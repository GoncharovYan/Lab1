#include "Hero.h"
#include <iostream>
#include <string>
using namespace std;

Hero::Hero(std::string name, int hp)
	: m_name(name), m_hp(hp)
{}

void Hero::setHp(int affect)
{
	m_hp = affect;
	if (m_hp < 0)
		m_hp = 0;
}

void Hero::Block()
{
	cout << "Select the hit you want to block (1-Low, 2-Medium, 3-High): ";
	cin >> m_block;
	cout << endl;
}