#ifndef __FILE_HALNDLER__
#define __FILE_HALNDLER__


class FileHandler {
public:
	virtual bool        contains(const char*) = 0;
	virtual char*       complete(const char*) = 0;
	virtual void        setFile(const char*) = 0;
	virtual const char* getFileName() = 0;
	virtual             ~FileHandler(){}
};

#endif
