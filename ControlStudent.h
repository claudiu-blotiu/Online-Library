#include"Student.h"
class ControlStudent
{
private:

	Student** student;

public:

	int size = 0;

	ControlStudent();

	void add(Student* a);

	void show();

	int position(int id);

	void Delete(int id);

	int nextId();

	void updateStudentName(int id, string newStudentName);

	void updateStudentAge(int id, int newStudentAge);

	void updatePassword(int id, string newPassword);

	Student* getUser(string, string);

	void load();

	string toSave();

	void save();

};

