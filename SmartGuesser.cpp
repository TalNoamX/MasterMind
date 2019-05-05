#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <string>
#include <sstream>
#include <iostream>

using std::string;
using namespace std;
using bullpgia::SmartGuesser;
using bullpgia::calculateBullAndPgia;


int bullpgia::SmartGuesser::permotationLen()
{
	int len = this->length;
	int leng = this->length;
	while (len > 2)
	{
		len --;
		leng = leng *len;
	}
	return leng;
}

void bullpgia::SmartGuesser::swap(char & c1, char & c2)
{
	char temp;
	temp = c1;
	c1 = c2;
	c2 = temp;
}

void bullpgia::SmartGuesser::permotationMaker(string str, int start, int end)
{
	int tempIndex;
	if (start == end)
	{
		if (permutationFunc < permoLen)
		{
			pastguesses.push_back(str);
			permutationFunc++;
		}
	}
	else
	{
		for (tempIndex = start; tempIndex < str.size(); tempIndex++)
		{
			swap(str[start], str[tempIndex]);
			permotationMaker(str, start + 1, end);
			swap(str[start], str[tempIndex]);
		}
	}

}


string bullpgia::SmartGuesser::guess()
{
	moves++;
	return answer;
}

void bullpgia::SmartGuesser::startNewGame(uint len)
{
	this->length = len;
	this->moves = 0;
	for (int i = 0; i < 10; i++) { bulls[i] = 0; }
	this->zeroToTen = 0;//0 to 10
	flag = true;//permu flag
	this->permutationFunc = 0; //pemuu function init
	this->mainLearnMove = 0;//learn iterations
	this->permoLen = permotationLen();
	pastguesses.clear();

	for (int i = 0; i < length; i++)
	{
		this->answer +=to_string(0);
	}
	moves++;
	
}

void bullpgia::SmartGuesser::learn(string ans)
{
	int numOfBalls = ans[0] - 48;
	if (zeroToTen < 9)
	{
		if (numOfBalls != 0) 
		{
		this->bulls[zeroToTen] = numOfBalls;
		}
		zeroToTen++;
		this->answer = "";
		//int bullNumber = std::stoi(SstrBull);
		for (int i = 0; i < length; i++)
		{
			this->answer = this->answer + to_string(zeroToTen);
		}
	}

	else if (zeroToTen == 9)
	{
		if (numOfBalls != 0) 
		{
			this->bulls[zeroToTen] = numOfBalls;
		}
		zeroToTen = 999;
	}

	else
	{
		if (flag) 
		{//create the vector
			this->answer = "";
			flag = false;
			for (int i = 0; i <=9; i++)
			{
				while (bulls[i] > 0)
				{
					this->answer = this->answer + to_string(i);
					bulls[i]--;
				}
			}
			permotationMaker(this->answer,0,this->length-1);
		}

		else
		{
			if (mainLearnMove < permoLen)
			{
				this->answer = pastguesses[mainLearnMove];
				mainLearnMove++;
				this->moves++;
			}
		}
	}
}
