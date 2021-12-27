#include"Books.h"
class Romance:public Books
{
private:

	string author = "";

public:

	Romance()
	{

	}
	Romance(string, int,string, int);

	void setAuthor(string);
	string getAuthor();

	string description();

	string toSave();

};

