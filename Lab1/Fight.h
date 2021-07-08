#pragma once
#include "Hero.h"

class FightProcess
{
	Hero* pOne;
	Hero* pTwo;

	int round = 1;
	int game = 0;
	int wOne = 0;
	int wTwo = 0;
public:
	FightProcess(Hero& pOnem, Hero& pTwom)
		: pOne(&pOnem), pTwo(&pTwom)
	{
	}

	void GameStart();
	bool GameCheck();
	void RoundWin(Hero& p);
	void WinGame();

	int getGame() { return game; };
	int getRound() { return round++; };
};

void FightM(Hero& pOne, Hero& pTwo);