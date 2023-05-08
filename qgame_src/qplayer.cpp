#include "../qgame_core/qplayer.hpp"

//Robot players handled by the game
//Player enter the next letter
char QPlayer::GuessNextLetter(const char* playersWord) {
	printInputBar(playersWord);
	char nextLetter;
	std::cin >> nextLetter;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');//IGNORE THE REMAINING values
	return std::toupper(nextLetter);
}

//Player enter the word in mind 
char* QPlayer::GetWordInMind(const char* playersWord) {
	printInputBar(playersWord);
	char* buffer = new char[DEFAULT_BUFFER_SIZE];
	std::cin >> buffer;
	// Remove the newline character from the end of the string
	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = '\0';
	}
	return buffer;
}

const char* QPlayer::getName() {
	return name.c_str();
}

bool QPlayer::IsRobot() {
	return name[0] == 'r' or name[0] == 'R';
}

//print the input bar contains the player name and the curr word formed by players.
void QPlayer::printInputBar(const char* playersWord) {
	std::string msg = name;
	msg += "(";
	msg.append(playersWord);
	msg += ")";
	msg += ">>";
	std::cout << msg;
}
