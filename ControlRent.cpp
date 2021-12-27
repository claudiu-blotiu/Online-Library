#include "ControlRent.h"

ControlRent::ControlRent()
{
	rent = new Rent * [100];

	load();
}

void ControlRent::add(Rent* a)
{
	rent[size] = a;
	size++;
}

void ControlRent::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << rent[i]->description() << endl;
	}
}

int ControlRent::position(int id)
{
	for (int i = 0; i < size; i++)
	{
		if (rent[i]->getId() == id)
		{
			return i;
		}
	}
	return -1;
}

void ControlRent::Delete(int id)
{
	int p = position(id);
	for (int i = p; i < size - 1; i++)
	{
		rent[i] = rent[i + 1];
	}
	size--;
}

int ControlRent::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return rent[size - 1]->getId() + 1;
}

void ControlRent::updateStudentId(int id, int newStudentId)
{
	int p = position(id);
	if (p != -1)
	{
		rent[p]->setStudentId(newStudentId);
	}
	else
	{
		cout << "Wrong Student Id" << endl;
	}
}

void ControlRent::updateBookId(int id, int newBookId)
{
	int p = position(id);
	if (p != -1)
	{
		rent[p]->setBookId(newBookId);
	}
	else
	{
		cout << "Wrong Book id" << endl;
	}
}

void ControlRent::updateStudentName(int id, string newStudentName)
{
	int p = position(id);
	if (p != -1)
	{
		rent[p]->setStudentName(newStudentName);
	}
	else
	{
		cout << "Wrong Student Name" << endl;
	}
}

void ControlRent::updateStudentAge(int id, int newStudentAge)
{
	int p = position(id);
	if (p != -1)
	{
		rent[p]->setStudentAge(newStudentAge);
	}
	else
	{
		cout << "Wrong Student Age" << endl;
	}
}

Rent** ControlRent::getRent(int studentId, int& nr)
{
	nr = 0;
	Rent** inchiriere = new Rent * [100];

	for (int i = 0; i < size; i++) {


		if (rent[i]->getStudentId() == studentId) {

			inchiriere[nr] = rent[i];

			nr++;
		}
	}
	return inchiriere;
}

Rent** ControlRent::getRent_Id(int rentId, int& nr)
{
	nr = 0;
	Rent** inchiriere = new Rent * [100];

	for (int i = 0; i < size; i++) {


		if (rent[i]->getId() == rentId) {

			inchiriere[nr] = rent[i];

			nr++;
		}
	}
	return inchiriere;
}

void ControlRent::load()
{
	ifstream read("Rent.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		int studentId;
		read >> studentId;
		int bookId;
		read >> bookId;
		string studentName;
		read >> studentName;
		int studentAge;
		read >> studentAge;

		if (id > 0) {

			Rent* g = new Rent(id, studentId, bookId, studentName, studentAge);
			this->add(g);
		}
	}

	read.close();
}

string ControlRent::toSave()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		text += rent[i]->toSave() + "\n";
	}
	text += rent[i]->toSave();
	return text;
}

void ControlRent::save()
{
	ofstream f("Rent.txt");

	f << this->toSave();

	f.close();
}
