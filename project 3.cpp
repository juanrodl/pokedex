#include "Pokemon.cpp"
#include "Pokedex.cpp"
#include "TypeMap.cpp"
#include "loadpoke.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>
#include <random>

using namespace std;

void readTypes(vector<string>& res)
{
    ifstream file;
    file.open("noduplicates.txt");
    string temp;

    if (file.is_open())
    {
        while (getline(file, temp))
        {
            res.push_back(temp);
        }
    }
}

Pokemon generateRandomPokemon()
{
    Pokemon pokemon;
    string name, type, type2, region, line;
    vector<string> stats;
    vector<string> types;
    int hp, attack, defense, spAtk, spDef, speed, statTotal;
    int counter = 0;

    readTypes(types);

    vector<string> regions;
    regions.push_back("Kanto");
    regions.push_back("Johto");
    regions.push_back("Hoenn");
    regions.push_back("Sinnoh");
    regions.push_back("Onuva");
    regions.push_back("Kalos");
    regions.push_back("Alola");
    regions.push_back("Galar");

    ifstream namesFile("names.txt");
    vector<string> names;

    if (namesFile.is_open())
    {
        while (getline(namesFile, line))
        {
            names.push_back(line);
        }
        namesFile.close();
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(50, 350); // hp range
    uniform_int_distribution<> dis1(1, 200); // attack range
    uniform_int_distribution<> dis2(5, 200); // defense range
    uniform_int_distribution<> dis3(55, 200); // attack speed range
    uniform_int_distribution<> dis4(10, 100); // defense speed range
    uniform_int_distribution<> dis5(20, 200); // speed range
    uniform_int_distribution<> dis6(0,323); // type range
    uniform_int_distribution<> dis7(0,7); // region range
    uniform_int_distribution<> dis8(0, names.size() - 1); // name range

    hp = dis(gen);
    attack = dis1(gen);
    defense = dis2(gen);
    spAtk = dis3(gen);
    spDef = dis4(gen);
    speed = dis5(gen);
    type = types[dis6(gen)];
    type2 = types[dis6(gen)];
    region = regions[dis7(gen)];
    name = names[dis8(gen)];
    statTotal = (hp + attack + defense + spAtk + spDef + speed);

    while (type == type2)   //fix for same type
    {
        type2 = types[dis6(gen)];
    }

    stats.push_back(to_string(hp));
    stats.push_back(to_string(attack));
    stats.push_back(to_string(defense));
    stats.push_back(to_string(spAtk));
    stats.push_back(to_string(spDef));
    stats.push_back(to_string(speed));

    cout << endl;
    cout << "Pokemon's name: " << name << endl;
    cout << "Pokemon's HP: " << hp << endl;
    cout << "Pokemon's type: " << type << endl;
    //cout << "Pokemon's type 2: " << type2 << endl;
    cout << "Pokemon's region: " << region << endl;
    cout << "Pokemon's attack: " << attack << endl;
    cout << "Pokemon's defense: " << defense << endl;
    cout << "Pokemon's special attack: " << spAtk << endl;
    cout << "Pokemon's special defense: " << spDef << endl;
    cout << "Pokemon's speed: " << speed << endl;
    cout << "Stat total: " << statTotal << endl;

    // create pokemon object with stats here and return it
    return Pokemon(name, to_string(counter), type, to_string(statTotal), stats, region);
}

void insertRandomNToPokedex(Pokedex &graph, int n)
{
    Pokemon temp;

    for (int i = 0; i < n; i++)
    {
        temp = generateRandomPokemon();
        graph.Insert(temp);
    }

}

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

void printPokemonTypes(string& type)
{
    int option;

    cout << endl;
    cout << "1. Normal\n";
    cout << "2. Fire\n";
    cout << "3. Water\n";
    cout << "4. Electric\n";
    cout << "5. Grass\n";
    cout << "6. Ice\n";
    cout << "7. Fighting\n";
    cout << "8. Poison\n";
    cout << "9. Ground\n";
    cout << "10. Flying\n";
    cout << "11. Psychic\n";
    cout << "12. Bug\n";
    cout << "13. Rock\n";
    cout << "14. Ghost\n";
    cout << "15. Dark\n";
    cout << "16. Dragon\n";
    cout << "17. Steel\n";
    cout << "18. Fairy\n";
    cout << "0. None\n";
    cin >> option;

    if (option == 1)
        type = "NORMAL";
    else if (option == 2)
        type = "FIRE";
    else if (option == 3)
        type = "WATER";
    else if (option == 4)
        type = "ELECTRIC";
    else if (option == 5)
        type = "GRASS";
    else if (option == 6)
        type = "ICE";
    else if (option == 7)
        type = "FIGHTING";
    else if (option == 8)
        type = "POISON";
    else if (option == 9)
        type = "GROUND";
    else if (option == 10)
        type = "FLYING";
    else if (option == 11)
        type = "PSYCHIC";
    else if (option == 12)
        type = "BUG";
    else if (option == 13)
        type = "ROCK";
    else if (option == 14)
        type = "GHOST";
    else if (option == 15)
        type = "DARK";
    else if (option == 16)
        type = "DRAGON";
    else if (option == 17)
        type = "STEEL";
    else if (option == 18)
        type = "FAIRY";
    else if (option == 0)
        type = "";

}

void printPokemonVector(Pokemon& pokemon, Pokedex& graph, string name, vector<Pokemon>& temp)
{
    int option;

    temp = graph.SearchByName(name);

    if (temp.size() > 1) // if there is more than one pokemon with the same name, print vector of names
    {
        cout << "Choose one of the following Pokemons with the name \"" << name << "\"\n";
        for (int i = 0; i < temp.size(); i++)
        {
            cout << i << ": " << temp[i].GetName() << endl;
        }

        cin >> option;

        pokemon = temp[option];
    }
    else if (temp.size() == 1) // only one pokemon with this name
    {
        pokemon = temp[0];
    }
    else if (temp.empty()) // if no pokemon with given name are found
    {
        cout << "No Pokemon with name \"" << name << "\" found." << endl;
    }
}

void printMenu()
{
    map<int, vector<string>> pokedex;
    vector<string> temp;
    vector<Pokemon> tempPokemonVector;
    vector<int> dijkstra;
    int option, n, hp, attack, defense, spAtk, spDef, speed, statTotal, pokemonOption, result;
    int idCounter = 0;
    string pokemonName, pokemonType, pokemonForm;
    string pokemon1, pokemon2, croppedType, type1, type2;
    Pokemon atkPokemon, defPokemon, tempPokemon;
    Pokedex graph;
    TypeMap types;
    bool first = true;

    cout << "-----------------------------------\n";
    cout << "      Welcome to your Pokedex!     \n";
    cout << "-----------------------------------\n";

    while (true)
    {
        cout << endl;
        cout << "Poxedex Menu Options:\n\n";
        cout << "1. Unlock all existing Pokemon\n";
        cout << "2. Randomly generate new Pokemon\n";
        cout << "3. Create your own Pokemon\n";
        cout << "4. Battle two Pokemon\n";
        cout << "5. Display all Pokemon (BFS) (NOTE: Connect all Pokemon first)\n";
        cout << "6. Open Pokemon GPS (Dijkstra's) (NOTE: Connect all Pokemon first)\n";
        cout << "7. Connect all Pokemon\n";
        cout << "8. Exit\n";
        cin >> option;

        switch (option)
        {
            case (1):
                readCSV(graph);
                cout << "Successfully unlocked all Pokemon\n";
                cout << "There are now " << graph.numPokemon << " Pokemon in your Pokedex\n";
                break;
            case (2):
                cout << "How many Pokemon would you like to randomly generate?\n";
                cin >> n;
                insertRandomNToPokedex(graph, n);
                cout << endl;
                cout << "Successfully generated " << n << " random Pokemon and added them to your Pokedex.\n";
                break;
            case (3):
                cout << "Give your Pokemon a name: \n";
                cin >> pokemonName;
                cout << "Choose your Pokemon's type: \n";
                printPokemonTypes(type1);
                cout << "Choose your Pokemon's second type: (optional)\n";
                printPokemonTypes(type2);
                pokemonType = type1 + type2;
                cout << "Enter your Pokemon's region/variant: \n";
                cin >> pokemonForm;
                cout << "Enter your Pokemon's HP: \n";
                cin >> hp;
                cout << "Enter your Pokemon's attack: \n";
                cin >> attack;
                cout << "Enter your Pokemon's defense: \n";
                cin >> defense;
                cout << "Enter your Pokemon's special attack: \n";
                cin >> spAtk;
                cout << "Enter your Pokemon's special defense: \n";
                cin >> spDef;
                cout << "Enter your Pokemon's speed: \n";
                cin >> speed;
                temp.push_back(to_string(hp));
                temp.push_back(to_string(attack));
                temp.push_back(to_string(defense));
                temp.push_back(to_string(spAtk));
                temp.push_back(to_string(spDef));
                temp.push_back(to_string(speed));
                statTotal = hp + attack + defense + spAtk + spDef + speed;
                tempPokemon = Pokemon(pokemonName, to_string(idCounter), pokemonType, to_string(statTotal), temp, pokemonForm);
                graph.Insert(tempPokemon);
                idCounter++;
                cout << "Successfully added " << tempPokemon.GetName() << " to your Pokedex.\n";
                break;
            case (4):
                cout << "Enter attacking Pokemon:\n";
                cin >> pokemon1;
                cout << "Enter defending Pokemon:\n";
                cin >> pokemon2;

                if (graph.SearchValid(pokemon1) && graph.SearchValid(pokemon2))
                {
                    printPokemonVector(atkPokemon, graph, pokemon1, tempPokemonVector);
                    printPokemonVector(defPokemon, graph, pokemon2, tempPokemonVector);

                    // cout << "Attacking Pokemon's name: " << atkPokemon.GetName() << endl;
                    // cout << "Defending Pokemon's name: " << defPokemon.GetName() << endl;
                    // cout << endl;

                    result = Compare(atkPokemon, defPokemon, types);

                    if (result == 1) // attacker wins
                    {
                        cout << atkPokemon.GetName() << " wins!\n";
                    }
                    else if (result == -1) // defender wins
                    {
                        cout << defPokemon.GetName() << " wins!\n";
                    }
                    else // tie
                    {
                        cout << "It's a tie!\n";
                    }
                    croppedType = defPokemon.GetType().substr(0,3); // first three characters of type
                    graph.InsertEdge(atkPokemon, defPokemon, types.weights.at(croppedType));
                    cout << "You have connected " << atkPokemon.GetName() << " and " << defPokemon.GetName() << " in your Pokedex!\n";
                }
                else
                {
                    cout << "ERROR: Invalid Pokemon name. Returning to main menu.\n";
                }
                break;
            case (5):
                if (graph.numPokemon == 0)
                    cout << "Your Pokedex is empty! Please input some Pokemon into your Pokedex first.\n";
                else
                    graph.BFS(graph.hasher.at(1)); // uses first pokemon as source
                break;
            case (6):
                dijkstra = graph.Dijkstra(graph.hasher.at(1));

                for (int i = 1; i < dijkstra.size(); i++)
                {
                    if (dijkstra[i] == 0) // source pokemon
                        cout << graph.hasher.at(i).GetName() << " is " << dijkstra[i] << " units away. (Source Pokemon)" << endl;
                    else
                        cout << graph.hasher.at(i).GetName() << " is " << dijkstra[i] << " units away."<< endl;
                }
                break;
            case (7):
                if (graph.numPokemon == 0)
                {
                    cout << "Your Pokedex is empty! Please input some Pokemon into your Pokedex first.\n";
                }
                else
                {
                    cout << "This might take a while...\n";
                    graph.IncludeAll(types);
                    cout << "Successfully connected all Pokemon\n";
                }
                break;
            case (8):
                cout << "Goodbye!\n";
                exit(0);
                break;
        }
    }
}

int main()
{

    printMenu();

    return 0;
}