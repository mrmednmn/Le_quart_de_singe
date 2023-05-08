#ifndef __QFILE_HALNDLER__
#define __QFILE_HALNDLER__

#include "../core_base/fileHandler.hpp"
#include <fstream>
#include <cstring>


#ifndef DEFAULT_BUFFER_SIZE
#define DEFAULT_BUFFER_SIZE 1024
#endif

class QFileHandler  : public FileHandler{
	std::ifstream db;
	const char* dict;
public:
	QFileHandler(const QFileHandler&) = delete;
	QFileHandler operator=(const QFileHandler&) = delete;
	QFileHandler(const char*dict){
		this->dict = dict;
	}

	bool contains(const char*)override;
	char* complete(const char*)override;
	void setFile(const char*) override;
	const char* getFileName()override;
};



#endif //! __QFILE_HALNDLER__ INCLUDED
