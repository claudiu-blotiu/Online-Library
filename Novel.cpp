#include "Novel.h"

Novel::Novel(bool popular,int id, string name, int price) :Books(id,name, "Novel", price)
{
	this->popular = popular;
}

void Novel::setPopular(bool popular)
{
	this->popular = popular;
}
bool Novel::getPopular()
{
	return this->popular;
}

string Novel::description()
{
	string text = Books::description();

	text += "Popular: " + to_string(this->popular) + "\n";

	return text;
}

string Novel::toSave()
{
	string text = "";

	text += to_string(this->getId()) + " ";
	text += this->getName() + " ";
	text += this->getType() + " ";
	text += to_string(this->popular) + " ";
	text += to_string(this->getPrice());

	return text;
}

