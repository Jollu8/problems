//
// Created by Jollu Emil on 5/24/26.
//

#include <string>
#include <gtest/gtest.h>
#include "string/substr.h"


class TestSubstr : public ::testing::Test {
protected:


    static void expectEqual(const std::size_t n, const std::size_t ans) {
        EXPECT_EQ(n, ans);
    }
};


TEST_F(TestSubstr, Substr_find_first_index) {
    constexpr std::string substr = "test";
    constexpr std::string str = "Hellotest";
    expectEqual(string::substr(str, substr), 5);
}

TEST_F(TestSubstr, Substr_returned_npos) {
    constexpr std::string substr = "test";
    constexpr std::string str = "Helloest";
    expectEqual(string::substr(str, substr), -1);
}

