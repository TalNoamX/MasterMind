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
	int h[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int k;
	bool flagP = false;

	for (int i = 0; i < lengh; i++) 
	{
		k = choos[i] - 48;
		h[k] = h[k] + 1;
	}

	for (int i = 0; i < lengh; i++)
	{
		k = guess[i] - 48;
		flagP = false;
		for (int j = 0; j < lengh; j++)
		{
			if (choos[j] == guess[i])
			{
				if (i == j)
				{
					if (h[k] > 0 && !flagP)
					{
						bull++;
						h[k] = h[k] - 1;
						break;
					}   
					else
					{
						if (pgia > 0)
						{
							bull++;
							pgia--;
							break;
						}
						else
						{
							bull++;
							break;
						}
					}
				}
				else
				{
					if (h[k] > 0 && !flagP)
					{
						pgia++;
						h[k] = h[k] - 1;
						flagP = true;
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
