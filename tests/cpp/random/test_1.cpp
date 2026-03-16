//
// Created by Jollu Emil on 5/31/26.
//
#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <algorithm>
#include <cstdlib>
#include <numeric>
#include <set>
#include <vector>
#include "random/rand_1.h"
using namespace std;
using ::testing::ElementsAreArray;
using ::testing::UnorderedElementsAreArray;


class SamplerMock {
public:
};

static void assertSizeAndUniqueness(const vector<int> &sample, int k) {
    ASSERT_EQ(static_cast<int>(sample.size()), k);
    set<int> seen(sample.begin(), sample.end());
    ASSERT_EQ(static_cast<int>(seen.size()), k);
}

TEST(Rand_1_Test, BasicKnownN) {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 3;

    auto res = myrandom::sampleKnownN(S, k);

    assertSizeAndUniqueness(res, k);
    EXPECT_THAT(res, UnorderedElementsAreArray(res));
    for (int x: res) {
        EXPECT_NE(find(S.begin(), S.end(), x), S.end());
    }
}

TEST(Rand_1_Test, BasicUnknownN) {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 3;

    auto res = myrandom::sampleUnknownN(S, k);

    assertSizeAndUniqueness(res, k);
    for (int x: res) {
        EXPECT_NE(find(S.begin(), S.end(), x), S.end());
    }
}

TEST(Rand_1_Test, KEqualsN) {
    vector<int> S = {10, 20, 30, 40};
    int k = 4;

    auto res1 = myrandom::sampleKnownN(S, k);
    auto res2 = myrandom::sampleUnknownN(S, k);

    assertSizeAndUniqueness(res1, k);
    assertSizeAndUniqueness(res2, k);

    EXPECT_THAT(res1, UnorderedElementsAreArray(S));
    EXPECT_THAT(res2, UnorderedElementsAreArray(S));
}

TEST(Rand_1_Test, KEqualsOne) {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 1;

    auto res1 = myrandom::sampleKnownN(S, k);
    auto res2 = myrandom::sampleUnknownN(S, k);

    assertSizeAndUniqueness(res1, k);
    assertSizeAndUniqueness(res2, k);
}

TEST(Rand_1_Test, UniformityKnownN) {
    int n = 10;
    int k = 3;
    int trials = 100000;

    vector<int> S(n);
    iota(S.begin(), S.end(), 0);

    vector<int> count(n, 0);

    for (int t = 0; t < trials; t++) {
        auto res = myrandom::sampleKnownN(S, k);
        assertSizeAndUniqueness(res, k);
        for (int x: res) {
            count[x]++;
        }
    }

    double expected = (double) trials * k / n;
    double tolerance = expected * 0.08;

    for (int i = 0; i < n; i++) {
        EXPECT_NEAR(count[i], expected, tolerance);
    }
}

TEST(Rand_1_Test, UniformityUnknownN) {
    int n = 10;
    int k = 3;
    int trials = 100000;

    vector<int> S(n);
    iota(S.begin(), S.end(), 0);

    vector<int> count(n, 0);

    for (int t = 0; t < trials; t++) {
        auto res = myrandom::sampleUnknownN(S, k);
        assertSizeAndUniqueness(res, k);
        for (int x: res) {
            count[x]++;
        }
    }

    double expected = (double) trials * k / n;
    double tolerance = expected * 0.08;

    for (int i = 0; i < n; i++) {
        EXPECT_NEAR(count[i], expected, tolerance);
    }
}


TEST(Rand_1_Test, HasOneEntryPerDataItem) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    EXPECT_EQ(scheme.size(), n);
}

TEST(Rand_1_Test, EachItemHasThreeDifferentNodes) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    for (int item = 0; item < n; item++) {
        auto nodes = scheme[item];

        EXPECT_GE(nodes[0], 0);
        EXPECT_GE(nodes[1], 0);
        EXPECT_GE(nodes[2], 0);

        EXPECT_LT(nodes[0], n);
        EXPECT_LT(nodes[1], n);
        EXPECT_LT(nodes[2], n);

        set<int> uniqueNodes = {nodes[0], nodes[1], nodes[2]};
        EXPECT_EQ(uniqueNodes.size(), 3);
    }
}

TEST(Rand_1_Test, EachNodeStoresAtMostThreeItems) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    vector<int> nodeLoad(n, 0);

    for (auto nodes: scheme) {
        nodeLoad[nodes[0]]++;
        nodeLoad[nodes[1]]++;
        nodeLoad[nodes[2]]++;
    }

    for (int node = 0; node < n; node++) {
        EXPECT_LE(nodeLoad[node], 3);
    }
}

TEST(Rand_1_Test, UsesAllCapacity) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    vector<int> nodeLoad(n, 0);

    for (auto nodes: scheme) {
        nodeLoad[nodes[0]]++;
        nodeLoad[nodes[1]]++;
        nodeLoad[nodes[2]]++;
    }

    for (int node = 0; node < n; node++) {
        EXPECT_EQ(nodeLoad[node], 3);
    }
}

TEST(Rand_1_Test, NoTwoItemsHaveSameThreeNodes) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    set<array<int, 3> > triples;

    for (auto nodes: scheme) {
        sort(nodes.begin(), nodes.end());

        EXPECT_FALSE(triples.contains(nodes));
        triples.insert(nodes);
    }
}

TEST(Rand_1_Test, AnyThreeFailedNodesLoseAtMostOneItem) {
    int n = 1000;

    auto scheme = myrandom::buildReplicationScheme(n);

    map<array<int, 3>, int> tripleCount;

    for (auto nodes: scheme) {
        sort(nodes.begin(), nodes.end());
        tripleCount[nodes]++;
    }

    for (auto [triple, count]: tripleCount) {
        EXPECT_LE(count, 1);
    }
}
