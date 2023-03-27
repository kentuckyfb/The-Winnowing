#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#pragma once
class CCard
{
private:
	int CardType;
	string firstname;
	string lastname;

	int power;
	int  resilience;

public:
	CCard() {
		return;
	}
	//constructor for class 
	CCard(int num, string fs, string ls, int pPoints, int rPoints) {
		CardType = num;
		firstname = fs;
		lastname = ls;
		power = pPoints;
		resilience = rPoints;
	}

	//getters
	int GetCardType() {
		return CardType;
	}
	int GetPower() {
		return power;
	}

	int GetResilience() {
		return resilience;
	}

	string GetFirstname() {
		return firstname;

	}

	string GetLastname() {
		return lastname;
	}

	string GetFullname() {
		return GetFirstname() + " " + GetLastname();
	}

	//setters
	void SetCardType(int num) {
		CardType = num;
	}

	void SetFirstname(string fs) {
		firstname = fs;
	}

	void SetLastname(string ls) {
		lastname = ls;
	}

	void SetPower(int pPoints) {
		power = pPoints;
	}

	void SetResilience(int rPoints) {
		resilience = rPoints;
	}



};