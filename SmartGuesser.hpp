#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using bullpgia::Guesser;
namespace bullpgia {
	class SmartGuesser :public Guesser {

	private:
		vector<int> pastguesses;
		int* bulls;
		int StrCounter;
		int ArrCounter;


	public:
		void startNewGame(uint len) override;
		string guess() override;
		void learn(string ans) override;
	};
}
