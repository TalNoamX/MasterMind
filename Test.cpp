/**
 * A demo program for bull-pgia.
 *
 * @author Erel Segal-Halevi
 * @since  2019-04
 */

using namespace std;

#include <iostream>
#include "play.hpp"
#include "calculate.hpp"
#include "DummyChoosers.hpp"
#include "DummyGuessers.hpp"
#include "SmartGuesser.hpp"
#include "badkan.hpp"
#define COMMA ,

using namespace bullpgia;

int main() {


	badkan::TestCase testcase;
	int grade = 0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {


		// BASIC TESTS - DO NOT CHANGE
		ConstantChooser c1234{ "1234" }, c12345{ "12345" }, c9999{ "9999" };
		ConstantGuesser g1234{ "1234" }, g12345{ "12345" }, g9999{ "9999" };

		testcase.setname("Calculate bull and pgia")
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "1234"), "4,0")      // 4 bull, 0 pgia
			.CHECK_OUTPUT(calculateBullAndPgia("1234", "4321"), "0,4")      // 0 bull, 4 pgia
			
			;

		testcase.setname("Play with dummy choosers and guessers")
			.CHECK_EQUAL(play(c1234, g1234, 4, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c1234, g9999, 4, 100), 101)    // guesser loses by running out of turns 
			.CHECK_EQUAL(play(c1234, g12345, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c12345, g1234, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).
			;


		testcase.setname("Play with smart guesser");
		RandomChooser randy;
		SmartGuesser smarty;
		

		for (uint i = 0; i < 100; ++i) {
			testcase.CHECK_EQUAL(play(randy, smarty, 4, 100) <= 100, true);  // smarty should always win in at most 100 turns!
		}

		//our tests

		ConstantChooser c9876{ "9876" }, c13579{ "13579" }, c7777{ "7777" };
		ConstantGuesser g9876{ "9876" }, g13579{ "13579" }, g7777{ "7777" };
		ConstantChooser c2468{ "2468" }, cmod3{ "36912" }, c0000{ "0000" };
		ConstantGuesser g2468{ "2468" }, gmod3{ "36912" }, g0000{ "0000" };
		testcase.setname("Test case 1:")

			.CHECK_OUTPUT(calculateBullAndPgia("1919", "9191"), "0,4")    
			.CHECK_OUTPUT(calculateBullAndPgia("9876", "9876"), "4,0")   
			.CHECK_OUTPUT(calculateBullAndPgia("9876", "9867"), "2,2")
			.CHECK_OUTPUT(calculateBullAndPgia("111", "222"), "0,0")
			.CHECK_OUTPUT(calculateBullAndPgia("2366", "6600"), "0,2")
			.CHECK_OUTPUT(calculateBullAndPgia("898", "890"), "2,0")
			.CHECK_OUTPUT(calculateBullAndPgia("5124", "5241"), "1,3")

			.CHECK_EQUAL(play(c9876, g9876, 4, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(c9876, g7777, 4, 100), 101)    // guesser loses by running out of turns 
			.CHECK_EQUAL(play(c9876, g13579, 4, 100), 101)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c13579, g9876, 4, 100), 0)     // chooser loses technically by choosing an illegal number (too long).

			.CHECK_EQUAL(play(c9876, g7777, 4, 100), 101)
			.CHECK_EQUAL(play(c7777, g7777, 4, 100), 1)
			.CHECK_EQUAL(play(c7777, g9876, 4, 100), 101)
			.CHECK_EQUAL(play(c7777, gmod3, 4, 100), 101)     // guesser loses technically by choosing an illegal number (too long).

			.CHECK_EQUAL(play(cmod3, gmod3, 5, 100), 1)      // guesser wins in one turn.
			.CHECK_EQUAL(play(cmod3, g9999, 5, 100), 101)    // guesser loses by running by making a ilegel guess
			.CHECK_EQUAL(play(c0000, g0000, 4, 100), 1)   // guesser loses technically by making an illegal guess (too long).
			.CHECK_EQUAL(play(c0000, g2468, 4, 100), 101)     // chooser loses technically by choosing an illegal number (too long).
			;

		ConstantChooser c0{ "0" }, c00001{ "00001" }, c55555555{ "55555555" }, c12{ "12" }, c8008{ "8008" }, c1{ "1" }, c00002{ "00002" }, c00003{ "00003" };
		ConstantGuesser g0{ "0" }, g00001{ "00001" }, g55555555{ "55555555" }, g12{ "12" }, g8008{ "8008" }, g1{ "1" }, g00002{ "00002" }, g00003{ "00003" };

		testcase.setname("Test case 2:")
			.CHECK_OUTPUT(calculateBullAndPgia("1", "1"), "1,0")
			.CHECK_OUTPUT(calculateBullAndPgia("001", "100"), "1,2")
			.CHECK_OUTPUT(calculateBullAndPgia("11", "22"), "0,0")
			.CHECK_OUTPUT(calculateBullAndPgia("111", "112"), "2,0")
			.CHECK_OUTPUT(calculateBullAndPgia("0", "0"), "1,0")
			.CHECK_OUTPUT(calculateBullAndPgia("123456789", "123456789"), "9,0")
			.CHECK_OUTPUT(calculateBullAndPgia("123456789", "987654321"), "1,8")

			.CHECK_EQUAL(play(c0, g0, 1, 5), 1)
			.CHECK_EQUAL(play(c0, g1, 1, 10), 11)
			.CHECK_EQUAL(play(c12, g0, 2, 25), 26)
			.CHECK_EQUAL(play(c12, g12, 2, 1), 1)

			.CHECK_EQUAL(play(c00001, g00001, 5, 18), 1)
			.CHECK_EQUAL(play(c55555555, g55555555, 8, 65), 1)
			.CHECK_EQUAL(play(c8008, g8008, 4, 100), 1)
			.CHECK_EQUAL(play(c1, g8008, 1, 34), 35)

			.CHECK_EQUAL(play(c00001, g0, 5, 200), 201)
			.CHECK_EQUAL(play(c1, g55555555, 1, 3), 4)
			.CHECK_EQUAL(play(c0, g00001, 1, 100), 101)
			.CHECK_EQUAL(play(c00001, g00001, 5, 657), 1)

			.CHECK_EQUAL(play(c00001, g00003, 5, 356), 357)
			.CHECK_EQUAL(play(c00002, g00002, 5, 3), 1)
			.CHECK_EQUAL(play(c00003, g00002, 5, 123), 124)
			.CHECK_EQUAL(play(c00003, g00001, 5, 11), 12)
			;

		testcase.setname("Test case 3:")
			.CHECK_OUTPUT(calculateBullAndPgia("0000", "9876"), "0,0")
			.CHECK_OUTPUT(calculateBullAndPgia("9876", "1236"), "1,0")
			.CHECK_OUTPUT(calculateBullAndPgia("22222", "22222"), "5,0")
			.CHECK_OUTPUT(calculateBullAndPgia("9871", "9876"), "3,0")
			.CHECK_OUTPUT(calculateBullAndPgia("12345", "67891"), "0,1")
			.CHECK_OUTPUT(calculateBullAndPgia("10234", "70685"), "1,0")

			.CHECK_EQUAL(play(c0000, g12345, 5, 100), 0) //guesser choose illegle string
			.CHECK_EQUAL(play(c12345, g13579, 5, 100), 101) //guesser loose
			.CHECK_EQUAL(play(c9999, g2468, 4, 100), 101)
			.CHECK_EQUAL(play(c9876, g0000, 4, 100), 101)
			.CHECK_EQUAL(play(c13579, g12345, 5, 100), 101)
			.CHECK_EQUAL(play(c9999, g0000, 4, 100), 101)
			.CHECK_EQUAL(play(c0000, g9999, 4, 100), 101)

			.CHECK_EQUAL(play(cmod3, g2468, 4, 100), 0) //chooser chose a iligel string
			.CHECK_EQUAL(play(c0000, gmod3, 4, 100), 101) //guesser chose a illegel string
			.CHECK_EQUAL(play(cmod3, g13579, 4, 100), 0)
			.CHECK_EQUAL(play(c12345, gmod3, 5, 100), 101)
			;


		RandomChooser rand2;
		SmartGuesser smart2;
		testcase.setname("Test case 4: smart guesser");

	

		grade = testcase.grade();
	}
	else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: " << grade << endl;
	return 0;



}