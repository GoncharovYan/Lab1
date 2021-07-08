#pragma once
#include <string>
class Hero
{
	bool isAlive = true;
	int m_hp;
	int m_block;
	int m_skill = 0; //1-ArcherL 2-ArcherU 
	std::string m_name;
public:
	Hero(std::string name, int hp);
	virtual void Reset() = 0;
	
	int getHp() { return m_hp; }
	void setHp(int attack); //Affects the amount of health

	virtual void changeDef(int defence) = 0; //Affects the defensive skills of the hero
	virtual int Def(int attack, Hero& h) = 0;
	void setSkill(int numSkill) { m_skill = numSkill; }
	int getSkill() { return m_skill; }

	int getBlock() { return m_block; }
	void Block();
	virtual void Low(Hero& h) = 0;
	virtual void Medium(Hero& h) = 0;
	virtual void High(Hero& h) = 0;
	virtual void Ult(Hero& h) = 0;
	std::string getName() {
		return m_name;
	}

	void notAlive() { isAlive = false; }
	void notnotAlive() { isAlive = true; }
	bool Alive() { return isAlive; }
	virtual void getInfo() = 0;

};