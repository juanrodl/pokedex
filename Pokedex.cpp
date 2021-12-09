#include "Pokedex.h"
#include <unordered_set>
#include <queue>
#include <random>

Pokedex::Pokedex()
{
	numPokemon = 0;

}

void Pokedex::Insert(Pokemon& newPoke)
{
	numPokemon++;
	newPoke.placeInGraph = numPokemon;
	vector<pair<Pokemon, int>> temp;
	pair <int, Pokemon> temp2 = make_pair(numPokemon, newPoke);
	hasher.insert(temp2);
	pair <int, vector<pair<Pokemon, int>>> tempPair = make_pair(numPokemon, temp);
	pokedex.insert(tempPair);
	
}

void Pokedex::InsertEdge(Pokemon& start, Pokemon& end, int weight)
{
	pair<Pokemon, int> newEdge = make_pair(end, weight);
	pokedex.at(start.placeInGraph).push_back(newEdge);
}

vector<pair<Pokemon, int>> Pokedex::GetAdjList(const Pokemon& p)
{
	return pokedex.at(p.placeInGraph);
}

int Pokedex::GetWeight(Pokemon& start, Pokemon& end)
{
	if (pokedex.count(start.placeInGraph) == 0) {
		return -1; //if start doesnt exist in graph
	}
	vector<pair<Pokemon, int>> adjList = pokedex.at(start.placeInGraph);

	for (unsigned int i = 0; i < adjList.size(); i++) {
		if (adjList.at(i).first == end) {
			return adjList.at(i).second;
		}
	}
	return -1; //if end doesnt exist in the graph
}

vector<Pokemon> Pokedex::SearchByName(string name)
{
	vector<Pokemon> sameNamePoke;
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		string tempName = (*it).second.GetName();
		if (tempName == name) {
			sameNamePoke.push_back((*it).second);
		}
	}
	return sameNamePoke;
}

vector<Pokemon> Pokedex::SearchByID(string ID)
{
	vector<Pokemon> sameIDPoke;
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		string tempID = (*it).second.GetID();
		if (tempID == ID) {
			sameIDPoke.push_back((*it).second);
		}
	}
	return sameIDPoke;
}

bool Pokedex::SearchValid(string name)
{
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		string tempName = (*it).second.GetName();
		if (tempName == name) {
			return true;
		}
	}
	return false;
}

void Pokedex::BFS(const Pokemon& src)
{
	unordered_set<int> visited;
	visited.insert(src.placeInGraph);
	queue<Pokemon> vertices;
	vertices.push(src);
	while (vertices.size() != 0) {
		Pokemon vertex = vertices.front();
		vertices.pop();
		vector<pair<Pokemon, int>> adj = pokedex.at(vertex.placeInGraph);
		for (int i = 0; i < adj.size(); i++) {
			if (visited.find(adj.at(i).first.placeInGraph) == visited.end()) {
				visited.insert(adj.at(i).first.placeInGraph);
				vertices.push(adj.at(i).first);
			}
		}
		vertex.Print();
	}
}

vector<int> Pokedex::Dijkstra(const Pokemon& src)
{
	unordered_set<int> S;
	S.insert(src.placeInGraph);
	unordered_set<int> VS;
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		if (VS.find((*it).first) == VS.end() && (*it).first != src.placeInGraph) {
			VS.insert((*it).first);
		}
	}
	vector<int> d(numPokemon + 1, INT_MAX);
	d.at(src.placeInGraph) = 0;
	vector<int> p(numPokemon + 1, -1);
	for (auto it = VS.begin(); it != VS.end(); it++) {
		int weight = 0;
		bool isEdge = false;
		for (int i = 0; i < pokedex.at(src.placeInGraph).size(); i++) {
			if (pokedex.at(src.placeInGraph).at(i).first.placeInGraph == *it) {
				weight = pokedex.at(src.placeInGraph).at(i).second;
				isEdge = true;
			}
		}
		if (isEdge) {
			d.at(*it) = weight;
		}
	}
	while (!VS.empty()) {
		int smallest = INT_MAX;
		for (auto it = VS.begin(); it != VS.end(); it++) {
			if (d.at(*it) < smallest) {
				smallest = *it;
			}
		}
		VS.erase(smallest);
		S.insert(smallest);
		for (int i = 0; i < pokedex.at(smallest).size(); i++) {
			Pokemon v = pokedex.at(smallest).at(i).first;
			if (d.at(smallest) + pokedex.at(smallest).at(i).second < d.at(v.placeInGraph)) {
				d.at(v.placeInGraph) = d.at(smallest) + pokedex.at(smallest).at(i).second;
				p.at(v.placeInGraph) = smallest;
			}
		}
	}
	return d;
}

void Pokedex::IncludeAll(const TypeMap& types)
{
	//The goal for this is to have a graph that includes every vertex
	//needed because we only draw edges upon comparison, not insertion
	//Not at all perfect, but enough for our 2 algorthims to function
	// 1. Connect 1 to all other pokemon

	unordered_set<int> alreadyEdge;
	alreadyEdge.insert(1);
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		if ((*it).first != 1 && alreadyEdge.find((*it).first) == alreadyEdge.end()) {
			InsertEdge(hasher.at(1), (*it).second, types.weights.at((*it).second.GetType().substr(0, 3)));
			alreadyEdge.insert((*it).first);
		}
	}

	random_device rd;
	mt19937 gen(rd());

	// 2. visit each other pokemon
	for (auto it = hasher.begin(); it != hasher.end(); it++) {
		if ((*it).first != 1) { //if we arent at 1
			uniform_int_distribution<> dis(1, numPokemon);
			int newEdge = dis(gen);
			while (newEdge == (*it).first) {//and we arent drawing to the same vertex
				uniform_int_distribution<> dis2(1, numPokemon);
				newEdge = dis2(gen);
			}
			// insert 1 edge from that pokemon to a random other pokemon, weight is 1/2 of what we'd normally use
			InsertEdge(hasher.at((*it).first), hasher.at(newEdge), types.weights.at((*it).second.GetType().substr(0, 3)) / 2);
		}
	}
}
