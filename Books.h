#include <iostream>
#include<string>
#include<fstream>

using namespace std;

class Books
{
private:

	int id = 1;
	string name = "";
	int price = 1;
	string type = "";
	

public:

	Books()
	{

	}
	Books(int,string, string, int);

	void setId(int);
	int getId();

	void setName(string);
	string getName();

	void setType(string);
	string getType();

	void setPrice(int);
	int getPrice();

	virtual string description();

	virtual string toSave();



};

