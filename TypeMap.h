#pragma once
#include <string>
#include <unordered_map>
using namespace std;
struct TypeMap {
	unordered_map <string, vector<double>> types;
	unordered_map <string, int> weights;
	TypeMap();
};