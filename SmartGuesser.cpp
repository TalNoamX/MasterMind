#include "SmartGuesser.hpp"
using namespace std;
using bullpgia::SmartGuesser;


void bullpgia::SmartGuesser::startNewGame(uint len)
{
	this->length = len;
	for (int i = 0; i < length; i++)
	{
		this->answer = this->answer + "0";
	}
	this->bulls = new int(length);
	this->ArrCounter = 0;
	this->StrCounter = 0;
}

string bullpgia::SmartGuesser::guess()
{
	return answer;
}
void bullpgia::SmartGuesser::learn(string ans)
{
	if (StrCounter < 10)
	{
		int comma = ans.find(','); //location of ,
		string SstrBull = ans.substr(0, comma - 1);//the bull string of the answer
		int numOfBalls = stoi(SstrBull);
		for (int i = 0; i < numOfBalls; i++)
		{
			bulls[ArrCounter] = StrCounter;
			ArrCounter++;
		}
		
		StrCounter++;
		string c = to_string(StrCounter)
		for (int i = 0; i < this->length; i++)
		{
			this->answer = this->answer + c;
		}
	}
	else
	{
		
	}
}
