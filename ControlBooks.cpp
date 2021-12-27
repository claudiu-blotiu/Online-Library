#include "ControlBooks.h"

ControlBooks::ControlBooks()
{
	book = new Books *[100];

	load();
}

void ControlBooks::add(Books* a)
{
	book[size] = a;
	size++;
}

void ControlBooks::show()
{
	for (int i = 0; i < size; i++)
	{
		cout << book[i]->description() << endl;
	}
}

int ControlBooks::position(string name)
{
	for (int i = 0; i < size; i++)
	{
		if (book[i]->getName() == name)
		{
			return i;
		}
	}
	return -1;
}

void ControlBooks::Delete(string name)
{
	int p = position(name);
	for (int i = p; i < size - 1; i++)
	{
		book[i] = book[i + 1];
	}
	size--;
}

int ControlBooks::nextId()
{
	if (size == 0)
	{
		return 1;
	}
	return book[size - 1]->getId() + 1;
}

void ControlBooks::updateName(string name, string newName)
{
	int p = position(name);
	if (p != -1)
	{
		book[p]->setName(newName);
	}
	else
	{
		cout << "Wrong Book name" << endl;
	}
}

void ControlBooks::updateType(string name, string newType)
{
	int p = position(name);
	if (p != -1)
	{
		book[p]->setType(newType);
	}
	else
	{
		cout << "Wrong Book type" << endl;
	}
}

void ControlBooks::updatePrice(string name, int newPrice)
{
	int p = position(name);
	if (p != -1)
	{
		book[p]->setPrice(newPrice);
	}
	else
	{
		cout << "Wrong Book price" << endl;
	}
}

void ControlBooks::showRomance()
{
	for (int i = 0; i < size; i++)
	{
		Romance* r = dynamic_cast<Romance*>(book[i]);

		if (r != NULL)
		{
			cout << r->description() << endl;
		}
	}
}

void ControlBooks::showNovel()
{
	for (int i = 0; i < size; i++)
	{
		Novel* n = dynamic_cast<Novel*>(book[i]);

		if (n != NULL)
		{
			cout << n->description() << endl;
		}
	}
}

void ControlBooks::showHorror()
{
	for (int i = 0; i < size; i++)
	{
		Horror* h = dynamic_cast<Horror*>(book[i]);

		if (h != NULL)
		{
			cout << h->description() << endl;
		}
	}
}

void ControlBooks::afisareCarti(int bookId)
{
	for (int i = 0; i < size; i++)
	{
		if (book[i]->getId() == bookId)
		{
			cout << book[i]->description() << endl;
		}
	}
}

void ControlBooks::load()
{
	ifstream read("Books.txt");

	while (!read.eof())
	{
		int id;
		read >> id;
		string name;
		read >> name;
		int price;
		read >> price;
		string type;
		read >> type;
		if (type == "Romance")
		{
			string author;
			read >> author;

			Books* a = new Romance(author, id, name, price);

			this->add(a);
		}
		if (type == "Novel")
		{
			bool popular;
			read >> popular;

			Books* b = new Novel(popular, id, name, price);

			this->add(b);
		}
		if (type == "Horror")
		{
			string ageRestrict;
			read >> ageRestrict;

			Books* c = new Horror(ageRestrict, id, name, price);

			this->add(c);
		}

	}
}

string ControlBooks::toSave()
{
	string text = "";
	int i = 0;
	for (i = 0; i < size - 1; i++)
	{
		text += book[i]->toSave() + "\n";
	}
	text += book[i]->toSave();
	return text;

}

void ControlBooks::save()
{
	ofstream f("Books.txt");

	f << this->toSave();

	f.close();
}

