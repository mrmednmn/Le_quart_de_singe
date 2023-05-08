#include "qgame_core/qgame.hpp"
#include "qgame_core/qfileHandler.hpp"
#include "qgame_core/qplayer.hpp"

/*
Dveloper: Mohamed Naamane
Contact: mrnmnwork@gmail.com
*/

int main(int argc, char** argv) try{
	if (argc < 2) throw std::runtime_error("Enter at least 2 players.");
	QGame quarterGame(new QFileHandler("ods4.txt"));
	std::string currPlayerName{};
	for (int i = 1; i < argc; ++i) {
		currPlayerName.push_back(std::toupper(*argv[i]));
		currPlayerName+= std::to_string(i);
		quarterGame.addPlayer(new QPlayer(currPlayerName.c_str()));
		currPlayerName.clear();
	}
	quarterGame.start();
	return 0;
}
catch (std::exception& ex) {
	std::cerr << ex.what() << "\n";
}