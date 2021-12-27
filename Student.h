#include"ControlRent.h"
class Student
{
private:

	int studId = 1;
	string studName = "";
	int studAge = 1;
	string password = "";

public:

	Student()
	{

	}
	Student(int, string, int,string);

	void setStudId(int);
	int getStudId();

	void setStudName(string);
	string getStudName();

	void setStudAge(int);
	int getStudAge();

	void setPassword(string);
	string getPassword();

	string description();

	string toSave();


};

