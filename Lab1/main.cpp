#include "Hero.h"
#include "Heroes.h"
#include "Fight.h"
#include <iostream>
using namespace std;

char confirm(string heroClass) {
	char deal = 'd';
	while (true) {
		cout << "Choose a hero: "<< heroClass <<"? <y/n>: ";
		cin >> deal;
		if (deal != 'y' && deal != 'n')
			cout << "Incorrect enter (y/n), repeat please" << endl;
		else
			return deal;
	}
}

Hero* HeroPick(string name)
{
	cout << name << ", choose your hero" << endl;
	cout << "Knight - 1 \nArcher - 2 \nWizard - 3 " << endl;
	int var;
	cin >> var;

	char deal = 'e';
	switch (var)
	{
	case 1:
		Knight::pickInfo();
		deal = confirm("knight");
		if (deal == 'y')
			return new Knight(name);
		else
			return HeroPick(name);
		break;
	
	case 2:
		Archer::pickInfo();
		deal = confirm("archer");
		if (deal == 'y')
			return new Archer(name);
		else
			return HeroPick(name);
		break;
	
	case 3:
		Wizard::pickInfo();
		deal = confirm("wizard");
		if (deal == 'y')
			return new Wizard(name);
		else
			return HeroPick(name);
		break;
	default:
		break;
	}
}

int main()
{
	string name;
	cout << "Player 1, enter your name: ";
	cin >> name;
	Hero* p1 = HeroPick(name);

	cout << "Player 2, enter your name: ";
	cin >> name;
	Hero* p2 = HeroPick(name);

	FightM(*p1, *p2);
	delete p1;
	delete p2;

	return 0;
}