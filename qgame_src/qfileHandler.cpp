#include "../qgame_core/qfileHandler.hpp"


bool QFileHandler::contains(const char* word) {
	std::fstream db;
	db.open(dict, std::ios::in);
	if (!db.is_open()) {
		printf("Failed to open Dict :%s\n", dict);
		return false;
	}
	std::string line;
	while (std::getline(db, line)) {
		const char* currLine = line.c_str();
		if (strcmp(currLine, word)==0) {
			return true;
		}

	}
	db.close();
	return false;
}


char* QFileHandler::complete(const char* word) {
	std::fstream db;
	db.open(dict, std::ios::in);
	if (!db.is_open()) {
		printf("Failed to open Dict :%s\n", dict);
		return nullptr;
	}
	std::string line;
	char* buffer = new char[DEFAULT_BUFFER_SIZE];
	while (std::getline(db, line)) {
		const char* currLine = line.c_str();
		if (line.find(word) == 0 && line.length() > strlen(word)) {
			break;
		}

	}
	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = '\0';
	}
	strcpy(buffer, line.c_str());
	db.close();
	return buffer;
}

void QFileHandler::setFile(const char* dict) {
	this->dict = dict;
}

const char* QFileHandler::getFileName() {
	return dict;
}
