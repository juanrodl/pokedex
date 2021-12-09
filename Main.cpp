#include "Pokemon.h"
#include "TypeMap.h"
#include "Pokedex.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <random>

using namespace std;

int Compare(Pokemon attacker, Pokemon defender, const TypeMap& types)
{
	string defenderType = defender.GetType();
	string attackerType = attacker.GetType();
	string temp;
	temp.append(attackerType, 0, 3);
	attackerType = temp;
	double attackerTotal = stod(attacker.GetStatTotal());
	double modifier = 0.0;
	vector<double> typing = types.types.at(defenderType);
	//Hate this, but its the only way I can think of to get the modifier

	if (attackerType == "NOR") {
		modifier = typing.at(0);
	}
	else if (attackerType == "FIR") {
		modifier = typing.at(1);
	}
	else if (attackerType == "WAT") {
		modifier = typing.at(2);
	}
	else if (attackerType == "ELE") {
		modifier = typing.at(3);
	}
	else if (attackerType == "GRA") {
		modifier = typing.at(4);
	}
	else if (attackerType == "ICE") {
		modifier = typing.at(5);
	}
	else if (attackerType == "FIG") {
		modifier = typing.at(6);
	}
	else if (attackerType == "POI") {
		modifier = typing.at(7);
	}
	else if (attackerType == "GRO") {
		modifier = typing.at(8);
	}
	else if (attackerType == "FLY") {
		modifier = typing.at(9);
	}
	else if (attackerType == "PSY") {
		modifier = typing.at(10);
	}
	else if (attackerType == "BUG") {
		modifier = typing.at(11);
	}
	else if (attackerType == "ROC") {
		modifier = typing.at(12);
	}
	else if (attackerType == "GHO") {
		modifier = typing.at(13);
	}
	else if (attackerType == "DRA") {
		modifier = typing.at(14);
	}
	else if (attackerType == "DAR") {
		modifier = typing.at(15);
	}
	else if (attackerType == "STE") {
		modifier = typing.at(16);
	}
	else if (attackerType == "FAI") {
		modifier = typing.at(17);
	}

	attackerTotal *= modifier;

	if (modifier == 0.0) {
		string atkType = attacker.GetType();
		string defType = defender.GetType();
		string temp;
		temp.append(defType, 0, 3);
		defType = temp;
		double mod = 0;
		vector<double> type = types.types.at(atkType);

		if (defType == "NOR") {
			mod = type.at(0);
		}
		else if (defType == "FIR") {
			mod = type.at(1);
		}
		else if (defType == "WAT") {
			mod = type.at(2);
		}
		else if (defType == "ELE") {
			mod = type.at(3);
		}
		else if (defType == "GRA") {
			mod = type.at(4);
		}
		else if (defType == "ICE") {
			mod = type.at(5);
		}
		else if (defType == "FIG") {
			mod = type.at(6);
		}
		else if (defType == "POI") {
			mod = type.at(7);
		}
		else if (defType == "GRO") {
			mod = type.at(8);
		}
		else if (defType == "FLY") {
			mod = type.at(9);
		}
		else if (defType == "PSY") {
			mod = type.at(10);
		}
		else if (defType == "BUG") {
			mod = type.at(11);
		}
		else if (defType == "ROC") {
			mod = type.at(12);
		}
		else if (defType == "GHO") {
			mod = type.at(13);
		}
		else if (defType == "DRA") {
			mod = type.at(14);
		}
		else if (defType == "DAR") {
			mod = type.at(15);
		}
		else if (defType == "STE") {
			mod = type.at(16);
		}
		else if (defType == "FAI") {
			mod = type.at(17);
		}
		if (mod == 0) {
			return 0;
		}
	}

	if (attackerTotal > stod(defender.GetStatTotal())) {
		return 1; //return 1 if attacker is stronger
	}
	else if (attackerTotal < stod(defender.GetStatTotal())) {
		return -1; //return -1 if defender is stronger
	}
	else {
		return 0; //return 0 if equal
	}

}

int main() {
	Pokedex graph;

	random_device rd;
	mt19937 gen(rd());
	vector<string> stats;
	uniform_int_distribution<> dis(50, 350); // hp range
	uniform_int_distribution<> dis1(1, 200); // attack range
	uniform_int_distribution<> dis2(5, 200); // defense range
	uniform_int_distribution<> dis3(55, 200); // attack speed range
	uniform_int_distribution<> dis4(10, 100); // defense speed range
	uniform_int_distribution<> dis5(20, 200); // speed range
	uniform_int_distribution<> dis6(0, 323); // type range
	uniform_int_distribution<> dis7(0, 7); // region range

	int hp = dis(gen);
	int attack = dis1(gen);
	int defense = dis2(gen);
	int spAtk = dis3(gen);
	int spDef = dis4(gen);
	int speed = dis5(gen);
	int statTotal = (hp + attack + defense + spAtk + spDef + speed);
	stats.push_back(to_string(hp));
	stats.push_back(to_string(attack));
	stats.push_back(to_string(defense));
	stats.push_back(to_string(spAtk));
	stats.push_back(to_string(spDef));
	stats.push_back(to_string(speed));
	Pokemon one("one", "123", "NORMAL", to_string(statTotal), stats, "sinnoh");

	uniform_int_distribution<> Dis(50, 350); // hp range
	uniform_int_distribution<> Dis1(1, 200); // attack range
	uniform_int_distribution<> Dis2(5, 200); // defense range
	uniform_int_distribution<> Dis3(55, 200); // attack speed range
	uniform_int_distribution<> Dis4(10, 100); // defense speed range
	uniform_int_distribution<> Dis5(20, 200); // speed range
	uniform_int_distribution<> Dis6(0, 323); // type range
	uniform_int_distribution<> Dis7(0, 7); // region range

	vector<string> stats2;
	hp = Dis(gen);
	attack = Dis1(gen);
	defense = Dis2(gen);
	spAtk = Dis3(gen);
	spDef = Dis4(gen);
	speed = Dis5(gen);
	statTotal = (hp + attack + defense + spAtk + spDef + speed);
	stats2.push_back(to_string(hp));
	stats2.push_back(to_string(attack));
	stats2.push_back(to_string(defense));
	stats2.push_back(to_string(spAtk));
	stats2.push_back(to_string(spDef));
	stats2.push_back(to_string(speed));

	Pokemon Two("2", "321", "FIRE", to_string(statTotal), stats2, "eadeasd");

	graph.Insert(one);
	graph.Insert(Two);
	graph.InsertEdge(one, Two, 13);

	vector<pair<Pokemon, int>> adjList = graph.GetAdjList(one);
	for (int i = 0; i < adjList.size(); i++) {
		cout << adjList.at(i).first.GetName() << " " << adjList.at(i).second << endl;
	}
	cout << graph.GetWeight(one, Two) << endl;

	cout << graph.SearchByName("one").at(0).GetName() << endl;
	cout << graph.SearchByID("321").at(0).GetName() << endl;

	return 0;
}


int main2() {
    random_device rd;
    mt19937 gen(rd());
    vector<string> stats;
    uniform_int_distribution<> dis(50, 350); // hp range
    uniform_int_distribution<> dis1(1, 200); // attack range
    uniform_int_distribution<> dis2(5, 200); // defense range
    uniform_int_distribution<> dis3(55, 200); // attack speed range
    uniform_int_distribution<> dis4(10, 100); // defense speed range
    uniform_int_distribution<> dis5(20, 200); // speed range
    uniform_int_distribution<> dis6(0, 323); // type range
    uniform_int_distribution<> dis7(0, 7); // region range

    int hp = dis(gen);
    int attack = dis1(gen);
    int defense = dis2(gen);
    int spAtk = dis3(gen);
    int spDef = dis4(gen);
    int speed = dis5(gen);
    int statTotal = (hp + attack + defense + spAtk + spDef + speed);
    stats.push_back(to_string(hp));
    stats.push_back(to_string(attack));
    stats.push_back(to_string(defense));
    stats.push_back(to_string(spAtk));
    stats.push_back(to_string(spDef));
    stats.push_back(to_string(speed));
    Pokemon one("one", "123", "NORMAL", to_string(statTotal), stats, "sinnoh");

    uniform_int_distribution<> Dis(50, 350); // hp range
    uniform_int_distribution<> Dis1(1, 200); // attack range
    uniform_int_distribution<> Dis2(5, 200); // defense range
    uniform_int_distribution<> Dis3(55, 200); // attack speed range
    uniform_int_distribution<> Dis4(10, 100); // defense speed range
    uniform_int_distribution<> Dis5(20, 200); // speed range
    uniform_int_distribution<> Dis6(0, 323); // type range
    uniform_int_distribution<> Dis7(0, 7); // region range
    
    vector<string> stats2;
    hp = Dis(gen);
    attack = Dis1(gen);
    defense = Dis2(gen);
    spAtk = Dis3(gen);
    spDef = Dis4(gen);
    speed = Dis5(gen);
    statTotal = (hp + attack + defense + spAtk + spDef + speed);
    stats2.push_back(to_string(hp));
    stats2.push_back(to_string(attack));
    stats2.push_back(to_string(defense));
    stats2.push_back(to_string(spAtk));
    stats2.push_back(to_string(spDef));
    stats2.push_back(to_string(speed));

    Pokemon Two("2", "321", "FIRE", to_string(statTotal), stats2, "eadeasd");
    
    cout << "Pokemon 1:" << endl << one.GetName() << endl << one.GetStatTotal() << endl << one.GetType() << endl;
    cout << "Pokemon 2:" << endl << Two.GetName() << endl << Two.GetStatTotal() << endl << Two.GetType() << endl;

    TypeMap types;

    cout << "Comparison says that ";
    int comp = Compare(one, Two, types);
	if (comp == 1)
		cout << "pokemon 1 is stronger";
	else if (comp == -1)
		cout << "pokemon 2 is stronger";
	else if (comp == 0)
		cout << "both are =";
	else
		cout << "error";
	return 0;
}