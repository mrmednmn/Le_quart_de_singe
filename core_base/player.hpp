#ifndef __PLAYER__
#define __PLAYER__

class Player {
public:
	virtual char        GuessNextLetter(const char*) = 0;
	virtual char*       GetWordInMind(const char*) = 0;
	virtual const char* getName() = 0;
	virtual bool        IsRobot() = 0;
	virtual void        printInputBar(const char*) = 0;
	virtual             ~Player(){}
};

#endif // ! __PLAYER__ INCLUDED
