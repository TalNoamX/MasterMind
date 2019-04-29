#include "Guesser.hpp"
#include <vector>
using bullpgia::Guesser;
namespace bullpgia {
	class SmartGuesser :public Guesser {
	private:
		int length;
		vector<int> pastguesses;

	public:
		string guess() override;
	};
}
