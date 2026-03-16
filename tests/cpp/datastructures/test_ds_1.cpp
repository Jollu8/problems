//
// Created by Jollu Emil on 6/14/26.
//
#include "datastructures/ds_1.h"
#include "test_utils.h"

TEST(DirectAddressSetTest, InitiallyEmpty) {
    ds::DirectAddressSet set(5);

    EXPECT_FALSE(set.contains(1));
    EXPECT_FALSE(set.contains(2));
    EXPECT_FALSE(set.contains(3));
    EXPECT_FALSE(set.contains(4));
    EXPECT_FALSE(set.contains(5));
}

TEST(DirectAddressSetTest, InsertOneElement) {
    ds::DirectAddressSet set(5);

    set.insert(3);

    EXPECT_TRUE(set.contains(3));
    EXPECT_FALSE(set.contains(1));
    EXPECT_FALSE(set.contains(5));
}

TEST(DirectAddressSetTest, InsertSeveralElements) {
    ds::DirectAddressSet set(10);

    set.insert(2);
    set.insert(5);
    set.insert(10);

    EXPECT_TRUE(set.contains(2));
    EXPECT_TRUE(set.contains(5));
    EXPECT_TRUE(set.contains(10));
    EXPECT_FALSE(set.contains(1));
    EXPECT_FALSE(set.contains(9));
}

TEST(DirectAddressSetTest, RemoveElement) {
    ds::DirectAddressSet set(5);

    set.insert(4);
    EXPECT_TRUE(set.contains(4));

    set.remove(4);
    EXPECT_FALSE(set.contains(4));
}

TEST(DirectAddressSetTest, RemoveMissingElementDoesNotBreak) {
    ds::DirectAddressSet set(5);

    set.remove(3);

    EXPECT_FALSE(set.contains(3));
}

TEST(DirectAddressSetTest, InsertDuplicateElement) {
    ds::DirectAddressSet set(5);

    set.insert(2);
    set.insert(2);

    EXPECT_TRUE(set.contains(2));

    set.remove(2);
    EXPECT_FALSE(set.contains(2));
}

TEST(DirectAddressSetTest, BoundaryValues) {
    ds::DirectAddressSet set(5);

    set.insert(1);
    set.insert(5);

    EXPECT_TRUE(set.contains(1));
    EXPECT_TRUE(set.contains(5));
}

TEST(DirectAddressSetTest, ContainsOutOfRangeThrows) {
    ds::DirectAddressSet set(5);

    EXPECT_THROW(set.contains(0), std::out_of_range);
    EXPECT_THROW(set.contains(6), std::out_of_range);
}

TEST(DirectAddressSetTest, InsertOutOfRangeThrows) {
    ds::DirectAddressSet set(5);

    EXPECT_THROW(set.insert(0), std::out_of_range);
    EXPECT_THROW(set.insert(6), std::out_of_range);
}

TEST(DirectAddressSetTest, RemoveOutOfRangeThrows) {
    ds::DirectAddressSet set(5);

    EXPECT_THROW(set.remove(0), std::out_of_range);
    EXPECT_THROW(set.remove(6), std::out_of_range);
}
