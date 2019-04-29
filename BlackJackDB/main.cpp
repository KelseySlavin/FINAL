#include <iostream>
#include "BJdb.cpp"
#include <string>
#include <stdlib.h> //http://www.cplusplus.com/reference/cstdlib/srand/
#include <time.h> //http://www.cplusplus.com/reference/cstdlib/srand/

using namespace std;

int card1, card2, card3, card4;
int DealerCard1, DealerCard2, DealerCard3, DealerCard4;
int CardTotal;
int DealerCardTotal;
string HitStay;
void DealCards();
void DealAnotherCard();
void DealerCard();
void DealerAnotherCard();

void YouLose();
void YouWin();
void DealFourthCard();



int main()
{
	srand(time(NULL));
	cout << "WELCOME TO BLACKJACK!!" << endl;
	bool Should_Exit = false;
	while (!Should_Exit)
	{
		cout << "Press ENTER to get your first two cards" << endl;
		cin.get();
		DealCards();
		cout << "Card 1: " << card1 << endl;
		cout << "Card 2: " << card2 << endl;
		CardTotal = card1 + card2;
		cout << "Your total is: " << CardTotal << endl;
		if (CardTotal < 21)
		{
			cout << "Do you want to hit or stay?: ";
			string HitStay;
			getline(cin, HitStay);

			if (HitStay == "hit")
			{
				DealAnotherCard();
				cout << "Card 1: " << card1 << endl;
				cout << "Card 2:" << card2 << endl;
				cout << "Card 3: " << card3 << endl;
				CardTotal = CardTotal + card3;
				cout << "Your total is: " << CardTotal << endl;
				if (CardTotal > 21)
				{
					YouLose();
				}
				else if (CardTotal < 21)
				{
					cout << "Do you want to hit or stay?: ";
					cin >> HitStay;
					getline(cin, HitStay);

					if (HitStay == "hit")
					{
						DealFourthCard();
						cout << "Card 1: " << card1 << endl;
						cout << "Card 2:" << card2 << endl;
						cout << "Card 3: " << card3 << endl;
						cout << "Card 4: " << card4 << endl;
						CardTotal = CardTotal + card4;
						cout << "Your total is: " << CardTotal << endl;
					}
					else (HitStay = 'stay');
					{
						DealerCard();
						DealerCard();
						cout << "Dealer Card 1: " << DealerCard1 << endl;
						cout << "Dealer Card 2: " << DealerCard2 << endl;
						DealerCardTotal = DealerCard1 + DealerCard2;
						cout << "The dealers total is: " << DealerCardTotal << endl;
						if (DealerCardTotal < 21)
						{
							DealerAnotherCard();
							cout << "Dealer Card 3: " << DealerCard3 << endl;
							DealerCardTotal = DealerCardTotal + DealerCard3;
							cout << "The Dealers Total is: " << DealerCardTotal << endl;
						}
						else if (DealerCardTotal > 21)
						{
							cout << "Dealers BUST!" << endl;
							YouWin();
						}

					}
				}
				else if (HitStay == "stay")
				{
					DealerCard();
					cout << "Dealer Card 1: " << DealerCard1 << endl;
					cout << "Dealer Card 2: " << DealerCard2 << endl;
					DealerCardTotal = DealerCard1 + DealerCard2;
					cout << "The dealers total is: " << DealerCardTotal << endl;
					if (DealerCardTotal < 21)
					{
						DealerAnotherCard();
						cout << "Dealer hits again:"<< endl;
						cout<<"Dealer Card 3: " << DealerCard3 << endl;
						DealerCardTotal = DealerCardTotal + DealerCard3;
						cout << "The Dealers Total is: " << DealerCardTotal << endl;
					}
					else if (DealerCardTotal > 21)
					{
						cout << "Dealers BUST!" << endl;
						YouWin();
					}

				}

			}
			else if (CardTotal > 21)
			{
				YouLose();
				cout << "BUST! Thank you for playing";
				Should_Exit = true;
			}
			if (DealerCardTotal < CardTotal && CardTotal < 21)
			{
				YouWin();
				Should_Exit = true;
			}
			else if (CardTotal < DealerCardTotal && DealerCardTotal < 21)
			{
				YouLose();
				Should_Exit = true;
			}

			system("pause");

			return 0;
		}
	}
}

	void DealCards()
{
	card1 = rand() % 11+1;
	card2 = rand() % 11+1;
}

void DealAnotherCard()
{
	card3 = rand() % 11+1;
}

void DealFourthCard()
{
	card4 = rand() % 11+1;
}

void DealerCard()
{
	DealerCard1 = rand() % 11 + 1;
	DealerCard2 = rand() % 11 + 1;
}

void DealerAnotherCard()
{
	DealerCard3 = rand() % 11 + 1;
}

void YouLose()
{
	cout << "You Lose" << endl;
}


void YouWin()
{
	cout << "YOU WIN!" << endl;
}
