#include "Heroes.h"

using namespace std;

enum Attacks {
	ATTACK_LOW = 1,
	ATTACK_MEDIUM = 2,
	ATTACK_HIGH = 3
};


void Knight::Reset() {
	high_attack = 50;
	m_shield = 40;
	setHp(200);
	notnotAlive();
}

void Knight::changeDef(int defence)
{
	m_shield += defence;
}

int Knight::Def(int attack, Hero& h)
{
	if (getSkill() == 1) {
		setSkill(0);
		return attack;
	}
	float block = static_cast<float>(m_shield) / 100;
	float blockDamage = attack * block;
	return attack - static_cast<int>(blockDamage);
}

void Knight::Low(Hero& h)
{
	if (h.getBlock() == ATTACK_LOW) {
		h.Ult(*this);
		return;
	}

	h.setHp(h.getHp() - h.Def(25, *this));
	h.changeDef(-10);

	if (h.getHp() <= 0)
		h.notAlive();
}

void Knight::Medium(Hero& h)
{
	if (h.getBlock() == ATTACK_MEDIUM) {
		h.Ult(*this);
		return;
	}
	h.setHp(h.getHp()- h.Def(2000, *this));
	changeDef(10);
	if (m_shield > 70)
		m_shield = 70;

	if (h.getHp() <= 0)
		h.notAlive();
}

void Knight::High(Hero& h)
{

	if (h.getBlock() == ATTACK_HIGH) {
		h.Ult(*this);
		return;
	}
	h.setHp(h.getHp() - h.Def(high_attack, *this));
	changeDef(-10);
	high_attack -= 10;	

	if (high_attack < 20)
		high_attack = 20;

	if (m_shield < 20)
		m_shield = 20;

	if (h.getHp() <= 0)
		h.notAlive();
}

void Knight::Ult(Hero& h)
{
	h.setHp(h.getHp() - h.Def((h.getHp() / 2), *this));
	m_shield = 40;
	high_attack = 50;

	if (h.getHp() <= 0)
		h.notAlive();
}

void Knight::getInfo()
{
	cout << getName() << " - hp: " << getHp() << ", def: " << m_shield << ", H_a dmg: " << high_attack << endl;
}

void Knight::pickInfo() {
	cout << "\nThe knight has a shield, with which he 100% blocks part of the damage received \nLow attack - The knight hits the opponent's legs and decreases the defensive ability of the opponent by 10. Deals 25 damage. \nMedium Attack - Strikes with a shield, increasing its damage block by 10 (Maximum 70).Deals 20 damage. \nUpper attack - the most powerful blow - deals 50 damage, defense and the next upper attack will be 10 weaker(Up to 20). \nUlt - Deals damage equal to half of the opponent's current health level, restores defense and damage from the upper attacks to standard indicators\n" << endl;
}

//Archer

void Archer::Reset() {
	medium_attack = 20;
	m_dodge = 25;
	notnotAlive();
	setHp(150);
}

int Archer::Def(int attack, Hero& h)
{
	if (getSkill() == 1) { //1 - archer low, 100% hit
		setSkill(0);
		return attack;
	}
	if (getSkill() == 2) { //2 - archer ult, 100% miss
		setSkill(0);
		m_dodge = 20;
		return 0;
	}
	int chance = rand() % 100;
	if (chance > m_dodge)
		return attack;
	else
		return 0;
}

void Archer::changeDef(int defence)
{
	m_dodge += defence;
}

void Archer::Low(Hero& h)
{
	if (h.getBlock() == ATTACK_LOW) {
		h.Ult(*this);
		return;
	}

	h.setHp(h.getHp() - h.Def(20, *this));
	h.setSkill(1);

	if (h.getHp() <= 0)
		h.notAlive();
}

void Archer::Medium(Hero& h)
{
	if (h.getBlock() == ATTACK_MEDIUM) {
		h.Ult(*this);
		return;
	}

	int damage = medium_attack + m_dodge;
	h.setHp(h.getHp() - h.Def(damage, *this));
	if (h.getHp() <= 0)
		h.notAlive();
}

void Archer::High(Hero& h)
{
	if (h.getBlock() == ATTACK_HIGH) {
		h.Ult(*this);
		return;
	}

	m_dodge += 10;
	h.setHp(h.getHp() - h.Def(30, *this));
	if (h.getHp() <= 0)
		h.notAlive();
}

void Archer::Ult(Hero& h)
{
	setSkill(2);
	medium_attack += 15;

	if (h.getHp() <= 0)
		h.notAlive();
}

void Archer::getInfo()
{
	cout << getName() << " - hp: " << getHp() << ", def: " << m_dodge << "%, M_a dmg: " << medium_attack << endl;
}

void Archer::pickInfo() {
	cout << "\nArcher can dodge 100% enemy attack with a chance \nLow attack - the archer sets up traps, removing all opportunities to defend against her next attack(The enemy can raise the indicator himself) . Deals 20 damage. \nMedium attack - Powerful shot, the higher the archer has a chance to dodge, the more damage. Deals 20 damage as standard. \nHigh Attack - Rain of arrows, behind which an archer is hiding, gives + 10% chance to dodge. Deals 30 damage. \nUlt - 100% dodge from the next attack, the damage it medium attack is increased by 15. After the next move, the chance to dodge drops to 20%.\n" << endl;
}

//Wizard

void Wizard::Reset() {
	m_flash = 25;
	damage = 20;
	setHp(125);
	notnotAlive();
}

int Wizard::Def(int attack, Hero& h)
{
	if (getSkill() == 1) {
		setSkill(0);
		return attack;
	}
	if (m_flash < 0)
		m_flash = 0;
	else if (m_flash > 75)
		m_flash = 75;
	int chance = rand() % 100;
	if (chance > m_flash)
		return attack;
	else {
		h.setHp(h.getHp() - (attack / 2));
		return 0;
	}

	return 0;
}

void Wizard::changeDef(int defence)
{
	m_flash += defence;

}
void Wizard::Low(Hero& h)
{
	if (h.getBlock() == ATTACK_LOW) {
		h.Ult(*this);
		return;
	}

	setHp(getHp() + 20);
	m_flash += 10;
	damage -= 5;
	if (damage < 5)
		damage = 5;
	if (h.getHp() <= 0)
		h.notAlive();
}

void Wizard::Medium(Hero& h)
{
	if (h.getBlock() == ATTACK_MEDIUM) {
		h.Ult(*this);
		return;
	}

	if (getHp() > 62)
		h.setHp(h.getHp() - h.Def((damage + 10), *this));
	else
		h.setHp(h.getHp() - h.Def((damage + 20), *this));

	if (h.getHp() <= 0)
		h.notAlive();
}

void Wizard::High(Hero& h)
{
	if (h.getBlock() == ATTACK_HIGH) {
		h.Ult(*this);
		return;
	}

	h.changeDef(-10);
	m_flash -= 10;
	h.setHp(h.getHp() - damage);

	if (h.getHp() <= 0)
		h.notAlive();
}

void Wizard::Ult(Hero& h)
{
	setHp(getHp() + (h.getHp() / 2));
	damage = 20;
	if (h.getHp() <= 0)
		h.notAlive();
}

void Wizard::getInfo()
{
	cout << getName() << " - hp: " << getHp() << ", def: " << m_flash << "%, Attack base dmg: " << damage << endl;
}

void Wizard::pickInfo() {
	cout << "The wizard has a chance to reflect incoming damage to the opponent. Have a base damage to all attack	\nLow Strike - The wizard restores 20 health to himself, increasing the chance to blind the enemy by 10 %, but reduces the damage from all his attacks by 5 (5 min).\nMedium hit - The wizard casts a spell that deals 20 damage if the wizard's health is above 50% and 30 if less.\nHigh Attack - The Wizard reduces the opponent's chance to defend by 10, while lowering his chance to blind him. Deals 20 damage, excluding enemy armor.\nUlt - Recovers health equal to half of the opponents's hp, restores damage from all his attacks to standard" << endl;
}
