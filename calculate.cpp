#include <iostream>
#include "calculate.hpp"
	
using namespace std;
using bullpgia::calculate;

string bullpgia::calculateBullAndPgia(string choos, string guess)
{
	int lengh = choos.size();
	string answer = "";
	int bull = 0;
	int pgia = 0;
	int h[9];
	int k;
	bool used = false;

	for (int i = 0; i < lengh; i++) 
	{
		k = choos[i] - 48;
		h[k]= h[k]+1;
	}

	for (int i = 0; i < lengh; i++)
	{
		k = guess[i] - 48;
		for (int j = 0; j < lengh; j++)
		{
			if (choos[j] == guess[i])
			{
				if (i == j)
				{
					if (used = false)
					{
						bull++;
						h[k] = h[k] - 1;
						break;
					}   
					else
					{
						bull++;
						pgia--;
						break;
					}
				}
				else
				{
					if (h[k] > 0)
					{
						pgia++;
						h[k] = h[k] - 1;
						used = true;
					}
				}
			}
		}
	}
	string b = to_string(bull);
	string p = to_string(pgia);
	answer = b + "," + p;
	return answer;
}
