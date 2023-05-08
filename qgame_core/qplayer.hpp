#ifndef __QPLAYER__
#define __QPLAYER__

#include "../core_base/player.hpp"
#include <cstring>
#include <iostream>
#include <limits>

#ifndef DEFAULT_BUFFER_SIZE
#define DEFAULT_BUFFER_SIZE 1024
#endif

class QPlayer : public Player{
	std::string name;
public:
	
	QPlayer(const char* n) :name(n) {}
	QPlayer(const QPlayer&) = delete;
	QPlayer operator=(const QPlayer&) = delete;

	char        GuessNextLetter(const char*)override;
	char*       GetWordInMind(const char*)override;
    const char* getName() override;
	bool        IsRobot()override;
	void        printInputBar(const char*)override;

};

#endif // ! __QPLAYER__ INCLUDED
