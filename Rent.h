#include"ControlBooks.h"
class Rent
{
private:

	int id = 1;
	int studentId = 1;
	int bookId = 1;
	string studentName = "";
	int studentAge = 1;

public:

	Rent()
	{

	}
	Rent(int, int, int, string, int);

	void setId(int);
	int getId();

	void setStudentId(int);
	int getStudentId();

	void setBookId(int);
	int getBookId();

	void setStudentName(string);
	string getStudentName();

	void setStudentAge(int);
	int getStudentAge();

	string description();

	string toSave();

};

