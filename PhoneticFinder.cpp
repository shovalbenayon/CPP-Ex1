/**
 * 03-2020
 * @author Shoval Benayon
 */

#include <stdexcept>
#include <bits/stdc++.h>
#include "PhoneticFinder.hpp"

bool match = false;

namespace Phonetic {
    std::string find(const std::string text, const std::string word) {
        if (text == " " || word == " ") {
            throw std::runtime_error("Error! can not recieve empty word");
        }

        std::vector<std::string> tokens;
        std::stringstream check1(text);
        std::string current;
        
        while (std::getline(check1, current, ' ')) /* Tokenizing a string */ {
            tokens.push_back(current);
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() == word.length()) {
                check_word(tokens[i], word);
            }

            if (match) {
                match = false; // for case that we check a few words
                return tokens[i]; 
            }
        }

        throw std::runtime_error("did not find the word in the text");
    }

    void check_word(const std::string token, const std::string word) {
        for (int i = 0; i < token.length(); i++) {
            if (!check_char(token[i], word[i])) {
                return;
            }
        }

        match = true;
    }

    bool check_char(char first, char second) {
        if (first == second || first == second + 32 || first == second - 32) {
            return true;
        }

        if (first <= 90) { // change to lower case
            first += 32;
        }
        
        if (second <= 90) {
            second += 32;
        }

        if ((first == 'v' || first == 'w') && (second == 'v' || second == 'w')) {
            return true;
        } else if ((first == 'g' || first == 'j') && (second == 'g' || second == 'j')) {
            return true;
        } else if ((first == 's' || first == 'z') && (second == 's' || second == 'z')) {
            return true;
        } else if ((first == 'd' || first == 't') && (second == 'd' || second == 't')) {
            return true;
        } else if ((first == 'o' || first == 'u') && (second == 'o' || second == 'u')) {
            return true;
        } else if ((first == 'i' || first == 'y') && (second == 'i' || second == 'y')) {
            return true;
        } else if ((first == 'b' || first == 'f' || first == 'p') && (second == 'b' || second == 'f' || second == 'p')) {
            return true;
        } else if ((first == 'c' || first == 'k' || first == 'q') && (second == 'c' || second == 'k' || second == 'q')) {
            return true;
        }

        return false;
    }
};