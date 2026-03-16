//
// Created by Jollu Emil on 5/24/26.
//
#include "string/substr.h"
#include <unordered_map>

namespace string {
    std::size_t findMatch(const std::string &str, const std::string &sub) {
        if (sub.empty()) return 0;
        if (str.size() < sub.size()) return std::string::npos;

        for (std::size_t i = 0; i <= str.size() - sub.size(); ++i) {
            std::size_t j = 0;
            for (; j < sub.size() && str[i + j] == sub[j]; ++j) {
            }
            if (j == sub.size()) {
                return i;
            }
        }
        return std::string::npos;
    }


    std::vector<std::string> findWordsByPhoneDigits(
        const std::string &digits,
        const std::vector<std::string> &dictionary
    ) {
        constexpr auto getChar = [](char c) {
            if (c >= 'a' && c <= 'c') return '2';
            if (c >= 'd' && c <= 'f') return '3';
            if (c >= 'g' && c <= 'i') return '4';
            if (c >= 'j' && c <= 'l') return '5';
            if (c >= 'm' && c <= 'o') return '6';
            if (c >= 'p' && c <= 's') return '7';
            if (c >= 't' && c <= 'v') return '8';
            if (c >= 'w' && c <= 'z') return '9';

            return '?';
        };

        std::vector<std::string> result;

        for (const auto &word: dictionary) {
            if (word.size() != digits.size()) {
                continue;
            }
            bool isWord = true;

            for (size_t i = 0; i < word.size(); ++i) {
                if (getChar(word[i]) != digits[i]) {
                    isWord = false;
                    break;
                }
            }

            if (isWord) {
                result.emplace_back(word);
            }
        }
        return result;
    }
}
