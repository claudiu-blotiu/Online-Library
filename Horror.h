#include"Novel.h"
class Horror:public Books
{
private:

	string ageRestrict = "";

public:

	Horror()
	{

	}
	Horror(string, int,string, int);

	void setAgeRestrict(string);
	string getAgeRestrict();

	string description();

	string toSave();




};

