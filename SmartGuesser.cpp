#include "SmartGuesser.hpp"
using namespace std;
using bullpgia::SmartGuesser;


string bullpgia::SmartGuesser::guess()
{
	return string();
}
void bullpgia::SmartGuesser::learn(string ans)
{
	std::int comma = ans.find(","); //location of ,
	std::string bull = ans.substr(0, comma - 1);//the bull string of the answer
	std::string pgia = ans.substr(comma + 1); //the pgia string;
	int bullcount = std::stoi(bull); //parsh the string bull to int
	int pgiacount = std::stoi(pgia);
	if (bullcount + pgiacount != ans.size())
	{
		for (int i = 0; i < ans.size(); i++)
		{
			ans[i] = this->num;
		}
	}
}
