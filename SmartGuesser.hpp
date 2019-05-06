#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using bullpgia::Guesser;
namespace bullpgia {
	class SmartGuesser :public Guesser {

	private:
		unsigned int length;
		std::vector<string> pastguess;
		string answer="";
		bool IfNoPermu;
		int permuCurr;
		int permoLen;
		int permuGuesses;
		int firstCounter;
		int moves;
		int bulls[10];

		int permotationLen();
		void swap(char &c1, char &c2);
		void permotationMaker(string s, int start, int end);


	public:
		void startNewGame(uint len) override;
		string guess() override;
		void learn(string ans) override;
	};
};