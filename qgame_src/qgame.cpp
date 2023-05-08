#include "../qgame_core/qgame.hpp"

/*
Return a random first char from the dict to
init the first char in the game word.
*/
char QGame::getRandomFirstChar(char defLetter) {
	std::fstream db;
	const char* dict = filemanager->getFileName();
	db.open(dict, std::ios::in);
	if (!db.is_open()) {
		printf("Failed to open Dict :%s\n", dict);
		return false;
	}
	std::string line;
	while (std::getline(db, line)) {
		const char* currLine = line.c_str();
		if (wordStatus[currLine] != EXCLUDED_WORD) {
			return currLine[0];
		}

	}
	db.close();
	return defLetter;
}

bool QGame::IsGameOver() {
	for (auto& rec : quarters) {
		if (rec.second >= 1.) return true;
	}
	return false;
}


void QGame::add_quarter(const char* playerName) {
	quarters[playerName] += .25;
}

void QGame::Log(const char* msg) {
	printf("%s", msg);
}

bool QGame::isMatchThePlayersWord(const char* msg) {
	const char* PlayersWrd = currPlayersWord.c_str();
	return strstr(msg, PlayersWrd) != NULL;
}

void QGame::resolvePlayerAction(int sender, int reciver, const char* msg) {
	const char* reciverName = players[reciver]->getName();
	const char* senderName = players[sender]->getName();

	if (!isMatchThePlayersWord(msg)) {
		quarters[reciverName] += .25;
		printf("the word %s does not start by the expected letters, player %s takes a quarter monkey\n", msg, players[reciver]->getName());
		printScoreBar();
	}
	else if (wordStatus[msg] != EXCLUDED_WORD and filemanager->contains(msg)) { //check if the word in the dict	
		quarters[senderName] += .25;
		printf("the word %s exists, the player %s takes a quarter of a monkey\n", msg, players[sender]->getName());
		wordStatus[msg] = EXCLUDED_WORD;
		currRoundLoserIndex = sender;
		currPlayersWord.clear();
		printScoreBar();
	}
	else {
		quarters[reciverName] += .25;
		printf("the word %s does not exist, the player %s takes a quarter of a monkey\n", msg, players[reciver]->getName());
		printScoreBar();
	}
}

void QGame::resolvePlayerAction(int self) {
	const char* selfName = players[self]->getName();
	const char* currWord = currPlayersWord.c_str();

	if (wordStatus[currWord] != EXCLUDED_WORD and filemanager->contains(currWord)) { //check if the word in the dict	
		quarters[selfName] += .25;
		printf("The word %s exists, the player %s takes a quarter of a monkey\n", currWord, selfName);
		wordStatus[currWord] = EXCLUDED_WORD;
		currRoundLoserIndex = self;
		currPlayersWord.clear();
		printScoreBar();
	}
}

void QGame::Destroy() {
	for (auto& player : players) {
		delete player;
		player = nullptr;
	}
	delete filemanager;
	filemanager = nullptr;
}

void QGame::printScoreBar() {
	for (auto& rec : quarters) {
		printf("%s:%f;", rec.first, rec.second);
	}
	printf("\n");
}

void QGame::addPlayer(Player* player) {
	players.push_back(player);
	quarters[player->getName()] = .0;
}

//main loop
void QGame::start() {
	size_t PlayersCount = players.size();
	int currPlayerIndex = 0;
	while (!IsGameOver()) {

		if (currRoundLoserIndex != -1) {//update the last round looser index
			currPlayerIndex = currRoundLoserIndex;
			currRoundLoserIndex = -1;
		}
		//detect the player type
		bool isRobot = players[currPlayerIndex]->IsRobot();

		//get player response robot or human
		char response = isRobot ? (players[currPlayerIndex]->printInputBar(currPlayersWord.c_str()), getRandomFirstChar(ASK_PREV)) : players[currPlayerIndex]->GuessNextLetter(currPlayersWord.c_str());
		// calc the prev player index
		unsigned int prevPlayerIndex = ((currPlayerIndex - 1) >= 0) ? (currPlayerIndex - 1) : int(players.size() - 1);

		if (response == ASK_PREV) {
			//get the prev player type
			isRobot = players[prevPlayerIndex]->IsRobot();
			//get player word in mind human or robot	
			const char* WordInMindBuffer = isRobot ? filemanager->complete(currPlayersWord.c_str()) : players[prevPlayerIndex]->GetWordInMind(currPlayersWord.c_str());
			const char* prevPlayerWordInMind = WordInMindBuffer;
			printf("%s, entered the word >%s\n", players[prevPlayerIndex]->getName(), prevPlayerWordInMind);
			resolvePlayerAction(currPlayerIndex, prevPlayerIndex, prevPlayerWordInMind);
			//free the WordInMindBuffer
			delete[]WordInMindBuffer;
			WordInMindBuffer = nullptr;
		}
		else if (response == GIVE_UP) { // a player say ! 
			const char* currPlayerName = players[currPlayerIndex]->getName();
			quarters[currPlayerName] += .25;
			printf("player %s relinquishes the round and takes a quarter monkey\n", currPlayerName);
			printScoreBar();
		}
		else {
			currPlayersWord.push_back(response);//update the curr word
			if (isRobot) {//print the response if the player is robot to display it 
				printf("%c\n", response);
			}
			resolvePlayerAction(currPlayerIndex); //proccess 1 player input char
		}
		currPlayerIndex = (currPlayerIndex + 1) % PlayersCount; // update the current player index
	}
	Log("\nGame Over!\n");
}


QGame::~QGame() {
	Destroy();
}