#include"Horror.h"
class ControlBooks
{
private:

	Books** book;

public:

	int size = 0;

	ControlBooks();

	void add(Books* a);

	void show();

	int position(string name);

	void Delete(string name);

	int nextId();

	void updateName(string name, string newName);

	void updateType(string name, string newType);

	void updatePrice(string name, int newPrice);

	void showRomance();

	void showNovel();

	void showHorror();

	void afisareCarti(int);

	void load();

	string toSave();

	void save();



};

