#include <iostream>
#include <stdexcept>
#include "PhoneticFinder.hpp"
using namespace std;

int main() {
	string text = "Dond vorri be haffy";
	cout << Phonetic::find(text, "dont") << endl; // should print "Dond"
	cout << Phonetic::find(text, "worry") << endl; // should print "vorri"
	cout << Phonetic::find(text, "Be") << endl; // should print "be"
	cout << Phonetic::find(text, "happy") << endl; // should print "haffy"
	try {
		cout << Phonetic::find(text, "happ") << endl; // should throw an exception - "happ" is not a full word in the sentence
	} catch (exception &ex) {
	 	cout << "	caught exception : " << ex.what() << endl; // should print "Did not find the word 'happ' in the text"
	}
}