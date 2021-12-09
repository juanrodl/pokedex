#include "Pokemon.h"
#include "TypeMap.h"
#include <unordered_map>
Pokemon::Pokemon()
{
	name = "";
	id = "";
	type = "";
	statTotal = "";
	for (int i = 0; i < 6; i++) {
		stats.push_back("");
	}
	variant = "";
	placeInGraph = -1;
}

Pokemon::Pokemon(string name, string id, string type, string statTotal, vector<string> stats, string variant)
{
	this->name = name;
	this->id = id;
	this->type = type;
	this->statTotal = statTotal;
	this->stats = stats;
	this->variant = variant;
	placeInGraph = -1;
}

Pokemon& Pokemon::operator=(const Pokemon& rhs)
{
	this->name = rhs.name;
	this->id = rhs.id;
	this->type = rhs.type;
	this->statTotal = rhs.statTotal;
	this->stats = rhs.stats;
	this->variant = rhs.variant;
	this->placeInGraph = rhs.placeInGraph;
	return *this;
}

bool Pokemon::operator==(const Pokemon& rhs)
{
	if (this->name == rhs.name && this->id == rhs.id && this->type == rhs.type && this->variant == rhs.variant && this->statTotal == rhs.statTotal && this->stats == rhs.stats && this->placeInGraph == rhs.placeInGraph) {
		return true;
	}
	else {
		return false;
	}
}

string Pokemon::GetName() const
{
	return this->name;
}

string Pokemon::GetID() const
{
	return this->id;
}

string Pokemon::GetType() const
{
	return this->type;
}

string Pokemon::GetStatTotal() const
{
	return this->statTotal;
}

vector<string> Pokemon::GetStats() const
{
	return this->stats;
}

string Pokemon::GetVariant() const
{
	return this->variant;
}

void Pokemon::Print()
{
	cout << "Name: " << name << endl;
	cout << "Type: " << type << endl;
	cout << "Region/variant: " << variant << endl;
	cout << "Stat Total: " << statTotal << endl;
	cout << endl;
}
