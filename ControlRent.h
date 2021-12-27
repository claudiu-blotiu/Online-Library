#include"Rent.h"
class ControlRent
{
private:

	Rent** rent;

public:

	int size = 0;

	ControlRent();

	void add(Rent* a);

	void show();

	int position(int id);

	void Delete(int id);

	int nextId();

	void updateStudentId(int id, int newStudentId);

	void updateBookId(int id, int newBookId);

	void updateStudentName(int id, string newStudentName);

	void updateStudentAge(int id, int newStudentAge);

	Rent** getRent(int, int&);

	Rent** getRent_Id(int, int&);

	void load();

	string toSave();

	void save();


};

