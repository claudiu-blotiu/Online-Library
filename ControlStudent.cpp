#include "ControlStudent.h"

ControlStudent::ControlStudent()
{
	student = new Student * [100];

	load();
}

void ControlStudent::add(Student* a)
{
	student[size] = a;
	size++;
}

void ControlStudent::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << student[i]->description() << endl;
	}
}

int ControlStudent::position(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (student[i]->getStudId() == id)
		{
			return i;
		}
	}
	return -1;
}

void ControlStudent::Delete(int id)
{
	int p = position(id);
	for (int i = p; i < size - 1; i++)
	{
		student[i] = student[i + 1];
	}
	size--;
}

int ControlStudent::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return student[size - 1]->getStudId() + 1;
}

void ControlStudent::updateStudentName(int id, string newStudentName)
{
	int p = position(id);
	if (p != -1)
	{
		student[p]->setStudName(newStudentName);
	}
	else
	{
		cout << "Wrong Student Name" << endl;
	}
}

void ControlStudent::updateStudentAge(int id, int newStudentAge)
{
	int p = position(id);
	if (p != -1)
	{
		student[p]->setStudAge(newStudentAge);
	}
	else
	{
		cout << "Wrong Student Age" << endl;
	}
}

void ControlStudent::updatePassword(int id, string newPassword)
{
	int p = position(id);
	if (p != -1)
	{
		student[p]->setPassword(newPassword);
	}
	else
	{
		cout << "Wrong Login Password" << endl;
	}
}

Student* ControlStudent::getUser(string name, string parola)
{
	for (int i = 0; i < size; i++)
	{
		if (student[i]->getStudName() == name && student[i]->getPassword() == parola)
		{
			return student[i];
		}
	}
}

void ControlStudent::load()
{
	ifstream read("Student.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string studentName;
		read >> studentName;
		int studentAge;
		read >> studentAge;
		string password;
		read >> password;

		if (id > 0) {

			Student* g = new Student(id, studentName, studentAge,password);
			this->add(g);
		}
	}
}

string ControlStudent::toSave()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		text += student[i]->toSave() + "\n";
	}
	text += student[i]->toSave();
	return text;
}

void ControlStudent::save()
{
	ofstream f("Student.txt");

	f << this->toSave();

	f.close();
}
