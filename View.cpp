#include "View.h"

View::View(Student* s)
{
	this->stud = s;

	listaCarti = new ControlBooks();

	listaStud = new ControlStudent;

	listaInchirieri = new ControlRent;
}

string View::meniu()
{
	string text = "";
	text += "---------------------------------------------------";
	text += "\nApasati tasta 1 pentru a afisa toate cartile";
	text += "\nApasati tasta 2 pentru a afisa toate cartiile inchiriate";
	text += "\nApasati tasta 3 pentru a te inchiria o carte";
	text += "\nApasati tasta 4 pentru a returna o carte";
	text += "\nApasati tasta 5 pentru a completa inchirierea";
	text += "\n-------------------------------------------------";

	return text;
}

void View::play()
{
	bool quit = false;
	int choise;

	while (quit == false)
	{
		cout << meniu() << endl;

		string x;
		cin >> x;

		choise = stoi(x);

		switch (choise)
		{
		case 1:viewBooks();
			break;
		case 2:viewRentedBooks();
			break;
		case 3:add();
			break;
		case 4:remove();
			break;
		case 5:save();
			break;
		}
	}
}

void View::viewBooks()
{
	cout << "--------CARTI ROMANTICE--------" << endl;
	this->listaCarti->showRomance();
	cout << "--------CARTI NOVEL--------" << endl;
	this->listaCarti->showNovel();
	cout << "--------CARTI HORRIR--------" << endl;
	this->listaCarti->showHorror();
}

void View::viewRentedBooks()
{
	int ct = 0;
	Rent** inchiriere = listaInchirieri->getRent(this->stud->getStudId(), ct);
	
	for (int i = 0; i < ct; i++)
	{
		listaCarti->afisareCarti(inchiriere[i]->getBookId());
	}
}

void View::add()
{
	cout << "Introduceti ID cartii dorite" << endl;

	int ct = 0;
	int bookID = 0;
	cin >> bookID;

	Rent* choise = new Rent(listaInchirieri->nextId(), stud->getStudId(), bookID, stud->getStudName(),stud->getStudAge());

	listaInchirieri->add(choise);
}

void View::remove()
{
	int rentID = 0;

	cout << "Introduceti ID inchirierii" << endl;

	cin >> rentID;

	int ct = 0;

	Rent** retur = listaInchirieri->getRent_Id(rentID, ct);

	for (int i = 0; i < ct; i++)
	{
		if (retur[i]->getStudentId() == stud->getStudId())
		{
			listaInchirieri->Delete(retur[i]->getId());
		}
	}
}

void View::save()
{
	listaInchirieri->save();
}
