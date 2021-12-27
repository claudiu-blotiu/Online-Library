#include"ControlStudent.h"
class View
{
	Student* stud;
	ControlBooks* listaCarti;
	ControlStudent* listaStud;
	ControlRent* listaInchirieri;

public:

	View(Student* s);

	string meniu();

	void play();

	void viewBooks();

	void viewRentedBooks();

	void add();

	void remove();

	void save();


};

