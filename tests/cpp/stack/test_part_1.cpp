#include <gtest/gtest.h>
#include <string>

#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>

#include <numeric>

#include  "stack/part_1.h"


TEST(BracketTest, CorrectSimple) {
    int pos = -2;
    EXPECT_TRUE(mystack::checkBrackets("()", pos));
    EXPECT_EQ(pos, -1);
}

TEST(BracketTest, CorrectNested) {
    int pos = -2;
    EXPECT_TRUE(mystack::checkBrackets("((())())()", pos));
    EXPECT_EQ(pos, -1);
}

TEST(BracketTest, CorrectEmpty) {
    int pos = -2;
    EXPECT_TRUE(mystack::checkBrackets("", pos));
    EXPECT_EQ(pos, -1);
}

TEST(BracketTest, FirstCharIsWrongClosing) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets(")()(", pos));
    EXPECT_EQ(pos, 0);
}

TEST(BracketTest, ExtraClosingBracket) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets("())", pos));
    EXPECT_EQ(pos, 2);
}

TEST(BracketTest, OneUnclosedOpening) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets("(()", pos));
    EXPECT_EQ(pos, 0);
}

TEST(BracketTest, ManyUnclosedOpenings) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets("(((", pos));
    EXPECT_EQ(pos, 0);
}

TEST(BracketTest, ClosingWithoutOpeningLater) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets("()())", pos));
    EXPECT_EQ(pos, 4);
}

TEST(BracketTest, OnlyClosingBracket) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets(")", pos));
    EXPECT_EQ(pos, 0);
}

TEST(BracketTest, OnlyOpeningBracket) {
    int pos = -2;
    EXPECT_FALSE(mystack::checkBrackets("(", pos));
    EXPECT_EQ(pos, 0);
}

TEST(LongestBalancedSubsequenceTest, EmptyString) {
    EXPECT_EQ(mystack::longestBalancedSubsequence(""), 0);
    EXPECT_EQ(mystack::longestBalancedSubsequence("(((("), 0);
    EXPECT_EQ(mystack::longestBalancedSubsequence("))))"), 0);
    EXPECT_EQ(mystack::longestBalancedSubsequence("()"), 2);
    EXPECT_EQ(mystack::longestBalancedSubsequence("((())())()"), 10);
    EXPECT_EQ(mystack::longestBalancedSubsequence(")()("), 2);
    EXPECT_EQ(mystack::longestBalancedSubsequence("())"), 2);
    EXPECT_EQ(mystack::longestBalancedSubsequence("(()"), 2);
    EXPECT_EQ(mystack::longestBalancedSubsequence("())(()"), 4);
    EXPECT_EQ(mystack::longestBalancedSubsequence(")()(())()()))())))("), 12);
    EXPECT_EQ(mystack::longestBalancedSubsequence(")()()()("), 6);
    EXPECT_EQ(mystack::longestBalancedSubsequence("))((())())(("), 8);
}


TEST(MinStackTest, EmptyInitially) {
    mystack::MinStack s;

    EXPECT_TRUE(s.empty());
}

TEST(MinStackTest, FindMinOnEmptyThrows) {
    mystack::MinStack s;

    EXPECT_THROW(s.findMin(), std::runtime_error);
}

TEST(MinStackTest, PushOneElement) {
    mystack::MinStack s;

    s.push(10);

    EXPECT_FALSE(s.empty());
    EXPECT_EQ(s.findMin(), 10);
}

TEST(MinStackTest, PushIncreasingElements) {
    mystack::MinStack s;

    s.push(1);
    s.push(2);
    s.push(3);

    EXPECT_EQ(s.findMin(), 1);
}

TEST(MinStackTest, PushDecreasingElements) {
    mystack::MinStack s;

    s.push(3);
    s.push(2);
    s.push(1);

    EXPECT_EQ(s.findMin(), 1);
}

TEST(MinStackTest, MinChangesAfterPop) {
    mystack::MinStack s;

    s.push(5);
    s.push(3);
    s.push(7);

    EXPECT_EQ(s.findMin(), 3);

    s.pop();

    EXPECT_EQ(s.findMin(), 3);

    s.pop();

    EXPECT_EQ(s.findMin(), 5);
}

TEST(MinStackTest, DuplicateMinimums) {
    mystack::MinStack s;

    s.push(5);
    s.push(2);
    s.push(2);
    s.push(8);

    EXPECT_EQ(s.findMin(), 2);

    s.pop();
    EXPECT_EQ(s.findMin(), 2);

    s.pop();
    EXPECT_EQ(s.findMin(), 2);

    s.pop();
    EXPECT_EQ(s.findMin(), 5);
}

TEST(MinStackTest, NegativeNumbers) {
    mystack::MinStack s;

    s.push(0);
    s.push(-3);
    s.push(10);
    s.push(-5);

    EXPECT_EQ(s.findMin(), -5);

    s.pop();

    EXPECT_EQ(s.findMin(), -3);
}

TEST(MinStackTest, PopUntilEmpty) {
    mystack::MinStack s;

    s.push(1);
    s.push(2);

    s.pop();
    s.pop();

    EXPECT_TRUE(s.empty());
    EXPECT_THROW(s.findMin(), std::runtime_error);
}
