#include "Romance.h"

Romance::Romance(string author,int id, string name, int price) :Books(id,name, "Romance", price)
{
	this->author = author;
}

void Romance::setAuthor(string author)
{
	this->author = author;
}
string Romance::getAuthor()
{
	return this->author;
}

string Romance::description()
{
	string text = Books::description();

	text += "Author: " + this->author + "\n";

	return text;
}

string Romance::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += this->getType() + " ";
	text += this->author + " ";
	text += to_string(this->getPrice());

	return text;
}


