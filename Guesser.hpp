#pragma once
#include <string>


using namespace std;

namespace bullpgia {

	class Guesser {

	protected:
		unsigned int length;
	

	public:
		virtual string guess()=0;

		virtual void startNewGame(uint len) {this->length = len;};

		virtual void learn(string ans) {};
	};
};