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
	void check(const std::string token, const std::string word);
    bool confirm(char l1, char l2);
};
