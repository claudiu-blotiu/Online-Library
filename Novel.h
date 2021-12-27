#include"Romance.h"
class Novel:public Books
{
private:

	bool popular = true;

public:

	Novel()
	{

	}
	Novel(bool, int,string, int);

	void setPopular(bool);
	bool getPopular();

	string description();

	string toSave();









};

