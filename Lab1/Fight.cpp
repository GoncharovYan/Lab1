#include "Fight.h"

#include <iostream>
#include <ctime>
using namespace std;

void FightProcess::GameStart() {
	game++;
	round = 1;
}

bool FightProcess::GameCheck() {
	if (wOne == 3 || wTwo == 3)
		return false;
	else
		return true;
}

void FightProcess::RoundWin(Hero& p) {
	cout << endl << p.getName() << " win!!!" << endl;
	if (&p == pOne)
		wOne++;
	else
		wTwo++;
}

void FightProcess::WinGame() {
	if (wOne > wTwo)
		cout << pOne->getName() << " THE WINNER!!!" << endl;
	else
		cout << pTwo->getName() << " THE WINNER!!!" << endl;
}


void FightM(Hero& pOne, Hero& pTwo)
{
	FightProcess fightProcess(pOne, pTwo);

	int first;
	Hero* p1 = &pOne;
	Hero* p2 = &pTwo;

	while (fightProcess.GameCheck())
	{
		fightProcess.GameStart();
		
		srand(time(NULL));
		first = rand() % 2;

		if (first == 0) {
			cout << pOne.getName() << " starts first" << endl;
		}
		else {
			cout << pTwo.getName() << " starts first" << endl;
			p1 = &pTwo;
			p2 = &pOne;
		}

		cout << "**********************GAME " << fightProcess.getGame() << "**********************" << endl;
		int skill;
		cout << "**********************FIGHT**********************" << endl;
		while (p1->Alive() && p2->Alive())
		{
			cout << "**********************ROUND" << fightProcess.getRound() << "*********************" << endl;
			p1->getInfo();
			p2->getInfo();

			cout << p1->getName() << " choose your ability (1 - Low, 2 - Medium, 3 - High, 0 - Block): ";
			cin >> skill;
			switch (skill)
			{
			case 0:
				p1->Block();
				break;
			case 1:
				p1->Low(*p2);
				break;
			case 2:
				p1->Medium(*p2);
				break;
			case 3:
				p1->High(*p2);
				break;
			default:
				break;
			}

			if (!p2->Alive())
				break;

			cout << p2->getName() << " choose your ability (1 - Low, 2 - Medium, 3 - High, 0 - Block): ";
			cin >> skill;
			switch (skill)
			{
			case 0:
				p2->Block();
				break;
			case 1:
				p2->Low(*p1);
				break;
			case 2:
				p2->Medium(*p1);
				break;
			case 3:
				p2->High(*p1);
				break;
			default:
				break;
			}
		}

		(!p1->Alive()) ? fightProcess.RoundWin(*p2) : fightProcess.RoundWin(*p1);

		p1->Reset();
		p2->Reset();
	}

	fightProcess.WinGame();
}
