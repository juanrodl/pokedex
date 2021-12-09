#pragma once
#include "loadpoke.h"
#include "Pokemon.h"

vector<string> stats1;

string readFileIntoString(const string& path) {
    auto ss = ostringstream{};
    ifstream input_file(path);
    if (!input_file.is_open()) {
        cerr << "Could not open the file - '"
            << path << "'" << endl;
        exit(0);
    }
    ss << input_file.rdbuf();
    return ss.str();
}

 void readCSV(Pokedex& graph) {
    int counter=0;
    string filename("poke100k.csv");
    string file_contents;
  
    char delimiter = ',';

    file_contents = readFileIntoString(filename);

    istringstream sstream(file_contents);
    std::vector<string> items;
    string record;
    //  getline(sstream, record);
    int count1 = 0;
    while (std::getline(sstream, record)) {
        istringstream line(record);
        while (std::getline(line, record, delimiter)) {
            items.push_back(record);
            count1++;
        }
        //serial[0]	ID[1] Name[2]	Type[3]	Type2[4] Form[5]	Total[6]	HP[7]	Attack[8]  Defense[9]	Sp.Atk[10]	Sp.Def[11]	Speed[12]	Base[13]	Combo type[14]

        
       
        string serial = items[0];
        string ID     = items[1];
        string Name   = items[2];
        string Type   = items[3];
        string Type2  = items[4];
        string form = items[5];
        string total = items[6];
        string hp      = items[7];
        string attack  = items[8];
        string defense = items[9];
        string spAtk   = items[10];
        string spDef   = items[11];
        string speed   = items[12];
        string Base = items[13];
        string Combo = items[14];

        stats1.push_back(hp);      //hp
        stats1.push_back(attack);  //attack
        stats1.push_back(defense); //defense
        stats1.push_back(spAtk);   //spAtk
        stats1.push_back(spDef);   // spDef
        stats1.push_back(speed);  // speed

        //addpoke( items[0], items[1], items[2], items[3], items[4], items[5], items[6], items[7], items[8], items[9], items[10], items[11], items[12]);
      
        //string

//       Pokemon   (string name, string id, string type, string statTotal, vector<string> stats, string variant); 
        Pokemon one1(Name , ID, Type, total, stats1, form);

        graph.Insert(one1);
        
        items.clear();
        count1 = 0;
        counter++;
        //cout << "\033[F";
        //cout << counter;
    }


  

}
