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
            throw std::runtime_error("did not find the word in the text");
        }

        std::vector<std::string> tokens;
        std::stringstream check1(text);
        std::string intermediate;
        while (std::getline(check1, intermediate, ' ')) /* Tokenizing a string */ {
            tokens.push_back(intermediate);
        }

        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i].length() == word.length()) {
                check(tokens[i], word);
            }

            if (match) {
                match = false; // for case that we check a few words
                return tokens[i]; 
            }
        }

        throw std::runtime_error("did not find the word in the text");
    }

    void check(const std::string token, const std::string word) {
        for (int i = 0; i < token.length(); i++) {
            if (!confirm(token[i], word[i])) {
                return;
            }
        }

        match = true;
    }

    bool confirm(char l1, char l2) {
        if (l1 == l2 || l1 == l2 + 32 || l1 == l2 - 32) {
            return true;
        }

        if (l1 <= 90) { // change to lower case
            l1 += 32;
        }
        
        if (l2 <= 90) {
            l2 += 32;
        }

        if ((l1 == 'v' || l1 == 'w') && (l2 == 'v' || l2 == 'w')) {
            return true;
        } else if ((l1 == 'g' || l1 == 'j') && (l2 == 'g' || l2 == 'j')) {
            return true;
        } else if ((l1 == 's' || l1 == 'z') && (l2 == 's' || l2 == 'z')) {
            return true;
        } else if ((l1 == 'd' || l1 == 't') && (l2 == 'd' || l2 == 't')) {
            return true;
        } else if ((l1 == 'o' || l1 == 'u') && (l2 == 'o' || l2 == 'u')) {
            return true;
        } else if ((l1 == 'i' || l1 == 'y') && (l2 == 'i' || l2 == 'y')) {
            return true;
        } else if ((l1 == 'b' || l1 == 'f' || l1 == 'p') && (l2 == 'b' || l2 == 'f' || l2 == 'p')) {
            return true;
        } else if ((l1 == 'c' || l1 == 'k' || l1 == 'q') && (l2 == 'c' || l2 == 'k' || l2 == 'q')) {
            return true;
        }

        return false;
    }
};
