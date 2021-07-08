#pragma once
#include "Hero.h"
#include <iostream>
#include <string>
using namespace std;

class Knight : public Hero
{
	int high_attack = 50;
	int m_shield = 40;
public:
	Knight(string name)
		: Hero(name, 200)
	{}
	void Reset();
	int Def(int attack, Hero& h) override;

	void changeDef(int defence) override;
	void Low(Hero& h) override;
	void Medium(Hero& h) override;
	void High(Hero& h) override;
	void Ult(Hero& h) override;

	void getInfo() override;
	static void pickInfo();
};

class Archer : public Hero
{
	int medium_attack = 20;
	int m_dodge = 25;
public:
	Archer(string name)
		: Hero(name, 150)
	{}
	void Reset();
	int Def(int attack, Hero& h) override;
	void changeDef(int defence) override;
	void Low(Hero& h) override;
	void Medium(Hero& h);
	void High(Hero& h);
	void Ult(Hero& h);

	void getInfo() override;
	static void pickInfo();
};

class Wizard : public Hero
{
	int m_flash = 25;
	int damage = 20;
public:
	Wizard(string name)
		: Hero(name, 125)
	{}
	void Reset();
	int Def(int attack, Hero& h) override;
	void changeDef(int defence) override;
	void Low(Hero& h) override;
	void Medium(Hero& h);
	void High(Hero& h);
	void Ult(Hero& h);

	void getInfo() override;
	static void pickInfo();
};