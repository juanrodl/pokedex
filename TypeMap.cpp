#include "TypeMap.h"
#include <fstream>
#include <sstream>

TypeMap::TypeMap()
{
	fstream file("poketype1_flat.csv");

	string lineFromFile;
	while (getline(file, lineFromFile)) {
		
		istringstream stream(lineFromFile);

		string defType;
		string atType;
		double mod;
		int startVertex;
		int endVertex;
		double weight;

		string tempMod;
		string tempStart;
		string tempEnd;
		string tempWeight;

		getline(stream, defType, ',');
		getline(stream, atType, ',');
		getline(stream, tempMod, ',');
		mod = stod(tempMod);
		getline(stream, tempStart, ',');
		startVertex = stoi(tempStart);
		getline(stream, tempEnd, ',');
		endVertex = stoi(tempEnd);
		getline(stream, tempWeight, ',');
		weight = stoi(tempWeight);

		if (types.find(defType) == types.end()) {
			vector<double> tempVector;
			tempVector.push_back(mod);
			pair<string, vector<double>> temp = make_pair(defType, tempVector);
			types.insert(temp);
		}
		else {
			types[defType].push_back(mod);
		}

		pair<string, int> temp = make_pair(atType, endVertex);
		weights.insert(temp);
	}
	
}
