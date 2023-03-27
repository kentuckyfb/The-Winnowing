#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <random>
#include "CCard.h"
using namespace std;

struct SProfessor 
{
    string Name;
    vector<CCard *> InHand;
    int Prestige = 30;

public:
    SProfessor(string n) { 
        Name = n;
    }

};



CCard* splitString(string line) {
    int CardType;
    string firstname;
    string lastname;

    int power;
    int  resilience;

    

    string words[6];
    int index = 0;
    string word =  "";
    for (auto letter : line) {
        
        if (letter != ' ') {
            words[index] += letter;

        }
        else {
            index += 1;
            word = "";
        }
    }

    CardType = stoi(words[0]);
    firstname = words[1];
    lastname = words[2];
    power = stoi(words[3]);
    if (words[4] != "") {
        resilience = stoi(words[4]);
    }
    else {
        resilience = 0;
    }
   
    //TODO: add index 6 here
    CCard* cardPtr = new CCard(CardType, firstname, lastname, power, resilience);
    return cardPtr;
}

int Random(int max)
{
    return max; // int(float(rand()) / (RAND_MAX + 1) * float(range));
}

void GameOver(SProfessor player1, SProfessor player2, bool sacked) {
    if (sacked == true) {
        cout << player2.Name << " has no prestige and is sacked" << endl;
    }
    cout << "Game Over" << endl;
    cout << player1.Name << "'s prestige is " << player1.Prestige << endl;
    cout << player2.Name << "'s prestige is " << player2.Prestige << endl;
    cout << player1.Name << " win's" << endl;
}
void RoundsOver(SProfessor ProfessorPlagiaris, SProfessor ProfessorPifflePaper) {
    if (ProfessorPlagiaris.Prestige > ProfessorPifflePaper.Prestige) {
        GameOver(ProfessorPlagiaris, ProfessorPifflePaper, false);
    }
    else {
        GameOver(ProfessorPifflePaper, ProfessorPlagiaris, false);
    }

}


int main()
{

    SProfessor ProfessorPlagiaris = SProfessor("ProfessorPlagiaris");
    SProfessor ProfessorPifflePaper = SProfessor("ProfessorPifflePaper");

   fstream file;
   vector<CCard *> ProfessorPlagiaristDeck;
   vector<CCard *> ProfessorPifflePaperDeck;

   file.open("plagiarist.txt");
   string line;
   while(getline(file, line)) {
       //cout <<"line : "<< line << endl;
       //ProfessorPlagiaristDeck.push_back(splitString(line));
       splitString(line);
       ProfessorPlagiaristDeck.push_back(splitString(line));
       delete splitString(line);
   }
   file.close();
    
    
   //cout << endl;
   file.open("piffle-paper.txt");
   while (getline(file, line)) {
       //cout << line << endl;
       ProfessorPifflePaperDeck.push_back(splitString(line));
       delete splitString(line);
   }
   file.close();
   int CardIndex = 0;

  
   cout << "Welcome to U-Can’t. Let the winnowing begin..." << endl;

   cout << ProfessorPlagiaris.Name + " starts with " + ProfessorPlagiaristDeck[CardIndex]->GetFullname() << endl;
   ProfessorPlagiaris.InHand.push_back(ProfessorPlagiaristDeck[CardIndex]);
   cout << ProfessorPifflePaper.Name + " starts with " + ProfessorPifflePaperDeck[CardIndex]->GetFullname() << endl;
   ProfessorPifflePaper.InHand.push_back(ProfessorPifflePaperDeck[CardIndex]);
   CardIndex = 1;

   for (int i = 0; i < 30; i++) {
       int ran;
       cout << "Round " + to_string(i+1) << endl;

       //===========================================
       cout << ProfessorPlagiaris.Name + " draws " + ProfessorPlagiaristDeck[CardIndex]->GetFullname() << endl;
       ProfessorPlagiaris.InHand.push_back(ProfessorPlagiaristDeck[CardIndex]);
       ProfessorPifflePaper.Prestige = ProfessorPifflePaper.Prestige - ProfessorPlagiaris.InHand[i]->GetPower();
       cout << ProfessorPlagiaris.Name + " plays " + ProfessorPlagiaris.InHand[i]->GetFullname() << endl;
       cout << ProfessorPlagiaris.InHand[i]->GetFullname() << " attacks " << ProfessorPifflePaper.Name << ". " << ProfessorPifflePaper.Name << " prestige is now " << ProfessorPifflePaper.Prestige << endl;
       //===========================================

       //check
       if (ProfessorPlagiaris.Prestige <= 0) {
           GameOver(ProfessorPifflePaper, ProfessorPlagiaris, true);
           break;
       }
       else if (ProfessorPifflePaper.Prestige < 0) {
           GameOver(ProfessorPlagiaris, ProfessorPifflePaper, true);
           break;
       }
       //===========================================
       cout << ProfessorPifflePaper.Name + " draws " + ProfessorPifflePaperDeck[CardIndex]->GetFullname() << endl;
       ProfessorPifflePaper.InHand.push_back(ProfessorPifflePaperDeck[CardIndex]);
       //ran = Random(ProfessorPifflePaper.InHand.size());
       cout<< ProfessorPifflePaper.Name + " plays " + ProfessorPifflePaper.InHand[i]->GetFullname() << endl;
       ProfessorPlagiaris.Prestige = ProfessorPlagiaris.Prestige - ProfessorPlagiaris.InHand[i]->GetPower();
       cout << ProfessorPifflePaper.InHand[i]->GetFullname() << " attacks " << ProfessorPlagiaris.Name << ". " << ProfessorPlagiaris.Name << " prestige is now " << ProfessorPlagiaris.Prestige << endl;
       //===========================================


       //check
       if (ProfessorPlagiaris.Prestige <= 0) {
           GameOver(ProfessorPifflePaper, ProfessorPlagiaris, true);
           break;
       }
       else if (ProfessorPifflePaper.Prestige < 0) {
           GameOver(ProfessorPlagiaris, ProfessorPifflePaper, true);
           break;
       }

       if (i >= 30) {
           RoundsOver(ProfessorPlagiaris, ProfessorPifflePaper);
       }

       CardIndex += 1;
   }



}






