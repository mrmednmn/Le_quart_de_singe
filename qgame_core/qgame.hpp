#ifndef __QGAME__
#define __QGAME__

#include "../core_base/game.hpp"
#include "../core_base/fileHandler.hpp"
#include <vector>
#include <unordered_map>
#include <cstring>
#include <fstream>


#define ASK_PREV      '?'
#define GIVE_UP       '!'
#define EXCLUDED_WORD 3

class QGame : public Game {
	std::vector<Player*>players;
	std::unordered_map<const char*, double>quarters;
	std::unordered_map<std::string, int>wordStatus; // is a word not proceesed before
	int currRoundLoserIndex;
	FileHandler* filemanager;
	std::string currPlayersWord;

	char getRandomFirstChar(char);
	bool IsGameOver();
	void add_quarter(const char*);
	void Log(const char*);
	bool isMatchThePlayersWord(const char*);
	void resolvePlayerAction(int sender, int reciver, const char* msg);
	void resolvePlayerAction(int self);
	void printScoreBar();
	
	void Destroy();

public:
	QGame(FileHandler* filemanager) {
		this->filemanager = filemanager;
		currPlayersWord = std::string();
		currRoundLoserIndex = -1; //the last round looser
	}

	void addPlayer(Player*) override;
	void start()override;

	QGame(const QGame&) = delete;
	QGame operator = (const QGame&) = delete;
	~QGame();

};

#endif //! __QGAME__ INCLUDED
