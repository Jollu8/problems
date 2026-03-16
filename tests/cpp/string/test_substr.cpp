//
// Created by Jollu Emil on 5/24/26.
//

#include <string>
#include <gtest/gtest.h>
#include "string/substr.h"

#include <algorithm>
#include <vector>

class TestSubstr : public ::testing::Test {
protected:
    static void expectEqual(const std::size_t n, const std::size_t ans) {
        EXPECT_EQ(n, ans);
    }

    static void expectSameWords(std::vector<std::string> actual,
                                std::vector<std::string> expected) {
        std::sort(actual.begin(), actual.end());
        std::sort(expected.begin(), expected.end());

        EXPECT_EQ(actual, expected);
    }
};

TEST_F(TestSubstr, ExampleFromTask) {
    std::vector<std::string> dictionary = {
        "any", "box", "boy", "cow", "cat", "dog"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("269", dictionary),
        {"any", "box", "boy", "cow"}
    );
}


TEST_F(TestSubstr, NoMatchingWords) {
    std::vector<std::string> dictionary = {
        "cat", "dog", "tree"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("999", dictionary),
        {}
    );
}

TEST_F(TestSubstr, DifferentLengthsAreIgnored) {
    std::vector<std::string> dictionary = {
        "a", "ad", "ae", "af", "bad"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("23", dictionary),
        {"ad", "ae", "af"}
    );
}

TEST_F(TestSubstr, SingleDigit) {
    std::vector<std::string> dictionary = {
        "a", "b", "c", "d", "x"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("2", dictionary),
        {"a", "b", "c"}
    );
}

TEST_F(TestSubstr, EmptyDigits) {
    std::vector<std::string> dictionary = {
        "", "a", "abc"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("", dictionary),
        {""}
    );
}

TEST_F(TestSubstr, EmptyDictionary) {
    std::vector<std::string> dictionary = {};

    expectSameWords(
        string::findWordsByPhoneDigits("269", dictionary),
        {}
    );
}

TEST_F(TestSubstr, DigitSevenHasFourLetters) {
    std::vector<std::string> dictionary = {
        "p", "q", "r", "s", "t"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("7", dictionary),
        {"p", "q", "r", "s"}
    );
}

TEST_F(TestSubstr, DigitNineHasFourLetters) {
    std::vector<std::string> dictionary = {
        "w", "x", "y", "z", "v"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("9", dictionary),
        {"w", "x", "y", "z"}
    );
}

TEST_F(TestSubstr, KeepsDuplicateWordsIfDictionaryHasDuplicates) {
    std::vector<std::string> dictionary = {
        "any", "any", "box", "cat"
    };

    expectSameWords(
        string::findWordsByPhoneDigits("269", dictionary),
        {"any", "any", "box"}
    );
}


TEST_F(TestSubstr, Substr_find_first_index) {
    constexpr std::string substr = "test";
    constexpr std::string str = "Hellotest";
    expectEqual(string::findMatch(str, substr), 5);
}

TEST_F(TestSubstr, Substr_returned_npos) {
    constexpr std::string substr = "test";
    constexpr std::string str = "Helloest";
    expectEqual(string::findMatch(str, substr), -1);
}
