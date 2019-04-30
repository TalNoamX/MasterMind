#ifndef Guesser_hpp
#define Guesser_hpp
#pragma once
#include <string>

typedef	unsigned int uint;
using namespace std;

namespace bullpgia {

	class Guesser {

	protected:
		uint length;

	public:
		virtual string guess()=0;

		virtual void startNewGame(uint len) 
		{
			this->length = len;
		};

		virtual void learn(string ans) {};
	};
}

#endif