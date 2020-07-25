/**
 * 03-2020
 * @author Shoval benayon
 */

#pragma once

#include <string>
#include <iostream>

namespace Phonetic {
	/**
	 * This method finds the word in the given text.
	 */
	std::string find(const std::string text, const std::string word);

	/*
	*Checks for 2 strings if there are equal
	*/
	void check_word(const std::string token, const std::string word);

	/*
	*Checks for 2 chars if there are equal
	*/
    bool check_char(char l1, char l2);
};
