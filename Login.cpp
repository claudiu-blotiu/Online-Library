#include "Login.h"

Login::Login()
{
	this->listaStud = new ControlStudent();
}

string Login::meniu()
{
	string text = "";

	text += "-----------------------------------------";
	text += "\nApasati tasta 1 pentru a va Loga";
	text += "\nApasati tasta 2 pentru a va inregistra";
	text += "\n---------------------------------------";
	text += "\n";

	return text;
}

void Login::play()
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
		case 1:login();
			break;
		case 2:inregistrare();
			break;
		}
	}
}

void Login::login()
{
	string user = "";

	cout << "Introduceti numele" << endl;

	cin >> user;

	string parola = "";

	cout << "Introduceti parola" << endl;

	cin >> parola;

	Student* s = listaStud->getUser(user, parola);

	if (s->getStudName() == user)
	{
		View* view = new View(s);

		view->play();
	}
	else
	{
		cout << "Wrong username or password" << endl;
	}
}

void Login::inregistrare()
{
	
	string name;
	cout << "Introduceti Numele" << endl;
	cin >> name;

	int age = 1;
	cout << "Introduceti varsta dv" << endl;
	cin >> age;

	string parola;
	cout << "Introduceti parola dorita" << endl;
	cin >> parola;

	Student* s = new Student(listaStud->nextId(), name, age, parola);
	listaStud->add(s);

	listaStud->save();
}
