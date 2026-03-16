// tests/cpp/test_insertion_sort.cpp

#include <gtest/gtest.h>

#include <vector>

#include "sorts.cpp"

class SortMock {
public:
    using Arr = std::vector<int>;
    using Comparator = std::function<bool(int, int)>;

    static Arr unsortedArray() {
        return {5, 2, 4, 6, 1, 3};
    }

    static Arr sortedArray() {
        return {1, 2, 3, 4, 5, 6};
    }

    static Comparator ascending() {
        return [](int a, int b) -> bool {
            return a < b;
        };
    }

    static Comparator descending() {
        return [](int a, int b) -> bool {
            return a > b;
        };
    }

    static Arr reverseSortedArray() {
        return {6, 5, 4, 3, 2, 1};
    }

    static void expectSortedAsc(const Arr& arr) {
        EXPECT_EQ(arr, sortedArray());
    }

    static void expectSortedDesc(const Arr& arr) {
        EXPECT_EQ(arr, reverseSortedArray());
    }
};


class TestSorts : public ::testing::Test {
protected:
    using Arr = std::vector<int>;
    using Comparator = std::function<bool(int, int)>;

    static Comparator ascending() {
        return [](int a, int b) -> bool {
            return a < b;
        };
    }

    static Comparator descending() {
        return [](int a, int b) -> bool {
            return a > b;
        };
    }

    static void expectEqual(const Arr& arr, const Arr& expected) {
        EXPECT_EQ(arr, expected);
    }
};

TEST_F(TestSorts, SelectionSort_IntAscending) {
    Arr arr{5, 2, 4, 6, 1, 3};

    sorts::selectionSort(arr, ascending());

    expectEqual(arr, {1, 2, 3, 4, 5, 6});
}

TEST_F(TestSorts, SelectionSort_IntDescending) {
    Arr arr{5, 2, 4, 6, 1, 3};

    sorts::selectionSort(arr, descending());

    expectEqual(arr, {6, 5, 4, 3, 2, 1});
}

TEST_F(TestSorts, InsertionSort_IntAscending) {
    Arr arr{5, 2, 4, 6, 1, 3};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {1, 2, 3, 4, 5, 6});
}

TEST_F(TestSorts, InsertionSort_AlreadySortedArray) {
    Arr arr{1, 2, 3, 4, 5};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {1, 2, 3, 4, 5});
}

TEST_F(TestSorts, InsertionSort_ReverseSortedArray) {
    Arr arr{5, 4, 3, 2, 1};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {1, 2, 3, 4, 5});
}

TEST_F(TestSorts, InsertionSort_Duplicates) {
    Arr arr{4, 2, 2, 8, 3, 3, 1};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {1, 2, 2, 3, 3, 4, 8});
}

TEST_F(TestSorts, InsertionSort_EmptyArray) {
    Arr arr{};

    sorts::insertionSort(arr, ascending());

    EXPECT_TRUE(arr.empty());
}

TEST_F(TestSorts, InsertionSort_SingleElementArray) {
    Arr arr{42};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {42});
}

TEST_F(TestSorts, InsertionSort_NegativeNumbers) {
    Arr arr{3, -1, 0, -5, 2};

    sorts::insertionSort(arr, ascending());

    expectEqual(arr, {-5, -1, 0, 2, 3});
}

TEST_F(TestSorts, InsertionSort_IntDescending) {
    Arr arr{5, 2, 4, 6, 1, 3};

    sorts::insertionSort(arr, descending());

    expectEqual(arr, {6, 5, 4, 3, 2, 1});
}