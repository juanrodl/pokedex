#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Pokemon {
	string name;
	string id;
	string type;
	string variant;
	string statTotal;
	vector<string> stats;
	
public:
	int placeInGraph;
	//Backbone
	Pokemon(); //Default Constructor
	Pokemon(string name, string id, string type, string statTotal, vector<string> stats, string variant); //Constructor for all data
	Pokemon& operator=(const Pokemon& rhs); //Copy assignment operator
	bool operator==(const Pokemon& rhs);

	//Getters
	string GetName() const;
	string GetID() const;
	string GetType() const;
	string GetStatTotal() const;
	vector<string> GetStats() const;
	string GetVariant() const;

	void Print();
};