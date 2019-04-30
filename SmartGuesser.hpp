#include "Guesser.hpp"
#include "calculate.hpp"
#include <vector>
using bullpgia::Guesser;
namespace bullpgia {
	class SmartGuesser :public Guesser {
	private:
		int length;
		vector<int> pastguesses;
		private char num = '0';

	public:
		string guess() override;
	};
}
