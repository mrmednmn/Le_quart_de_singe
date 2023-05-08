#ifndef __GAME__
#define __GAME__

#include "player.hpp"

class Game {
public:
	virtual void addPlayer(Player*) = 0;
	virtual void start() = 0;
	virtual      ~Game(){}
};


#endif //! __GAME__ INCLUDED
