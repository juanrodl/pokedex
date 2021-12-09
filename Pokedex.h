#pragma once
#include "Pokemon.h"
#include "TypeMap.h"
#include <unordered_map>

using namespace std;

struct Pokedex {

	unordered_map<int, Pokemon> hasher;
	unordered_map<int, vector<pair<Pokemon, int>>> pokedex;
	int numPokemon;

	Pokedex();

	void Insert(Pokemon& newPoke);
	void InsertEdge(Pokemon& start, Pokemon& end, int weight);

	vector<pair<Pokemon, int>> GetAdjList(const Pokemon& p);
	int GetWeight(Pokemon& start, Pokemon& end);
	vector<Pokemon> SearchByName(string name);
	vector<Pokemon> SearchByID(string name);
	bool SearchValid(string name);

	void BFS(const Pokemon& src);
	vector<int> Dijkstra(const Pokemon& src);

	void IncludeAll(const TypeMap& types);
};