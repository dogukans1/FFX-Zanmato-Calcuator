#include<iostream>
#include"GilMotivation.h" //calcuation of Yojimbo's pay
#include"ThirdCalcuation.h"

int main() {
	int yc; //this value is Yojimbo's Compatibility level, required for first calcuation
	int gil; //Gil paid to Yojimbo, duh
	int pay; //this value is determined by how much Gil you've paid to Yojimbo, required for fist calcuation
	int fc; //first calcuation
	int od; //determines whether Zanmato's overdrive bar is full, required for second calcuation.
	int sc; //second calcuation
	int zl; //determines enemy's Zanmato level, used for third calcuation.
	int tc; //third calcuation
	double a = 0; //final calcuation should you not hit guaranteed Zanmato
	std::cout << "Welcome to my Zanmato Hit Probablity Calcuator in C++! This version of Calcuator is made with assumption that you've picked \"To defeat the most powerful of enemies.\" option. For love of the God \n";
	std::cout << "\nFirst, what is Yojimbo's compatibility value (you need to either count or use a save editor to find out)? It's something between 0-255 = ";
	std::cin >> yc;
	while (yc <= -1 || 256 <= yc) //ensures only correct value is entered for YC
	{
		std::cout << "This is not a correct value, please write something between 0-255 = ";
		std::cin >> yc;
	}
	std::cout << "Okay, I need to know how much gil you've paid to him = ";
	std::cin >> gil;
	while (gil <= 0) //ditto
	{
		std::cout << "This is not a correct value, please write something between 1-999999999 = ";
		std::cin >> gil;
	}
	pay = gilMotivation(gil); //used to find Yojimbo's motivation from your pay
	fc = yc / 4 + pay; //first calcuation is (Yojimbo Compatibility / 4) + the motivation he gets from your payment 
	std::cout << "Nice, now we need to check whether Yojimbo's Overdrive bar is full. If it is, type 1. Else, type any number = ";
	std::cin >> od;
	if (od == 1)  // Game adds 20 to the second calcuation if Yojimbo's Overdrive meter is full, giving more chance for a Zanmato
	{
		sc = fc + 20;
	}
	else
	{
		sc = fc;
	}
	std::cout << "Great! We need to determine enemy's Zanmato Level. This is something you need to look up. If it's 1, 2 or 3 then type 1, else any number you want to = ";
	std::cin >> zl;
	tc = thirdCalcuation(zl, sc); //IF enemy Zanmato level is 1-3, you take 80% of second calcuation, if it's 4-6 then 40%. And that is third calcuation
	if (80 <= tc) // the final calcuation is third calcuation + a random number between 0-63. You need to hit 80 total, so even if you roll 0 at a tc value of 80 it's guaranteed Zanmato
	{
		std::cout << "Zanmato is guaranteed!";
	}
	else if (tc <= 16) // even if you roll max 63 at 16 or less, it's guaranteed NOT Zanmato.
	{
		std::cout << "No chance of Zanmato!";
	}
	else //Assume a tc of 79, we subtract this from 80 to find that we need to roll at least 1. Then we subtract 1 from 64 (0 is also possible roll, thus giving us 64 possible roll) to find how many numbers in 64 possible roll guarantees Zanmato. Then we find out 63 possible numbers (everything except 0), then divide it and multiple it by 100 to find percentage of a roll that will make the equation 80 or more.
	{
		a = 80 - tc;
		a = 64 - a;
		a = a / 64;
		a = a * 100;
		std::cout << "Chance of Zanmato is = " << a;
	}
	std::cout << std::endl;
	system("pause");
}