#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using bullpgia::Guesser;
namespace bullpgia {
	class SmartGuesser :public Guesser {

	private:
		unsigned int length;
		std::vector<string> pastguesses;
		string answer="";
		bool flag = true;
		int permutationFunc = 0;
		int mainLearnMove= 0;
		int bulls[10] = {0,0,0,0,0,0,0,0,0,0};
		int zeroToTen = 0;
		int permoLen=0;
		int moves = 0;

	public:
	
		int permotationLen();
		void swap(char &c1, char &c2);
		void permotationMaker(string s, int start, int end);


		void startNewGame(uint len) override;
		string guess() override;
		void learn(string ans) override;
	};
};
