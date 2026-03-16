#include <iostream>

/// -> For test or code checking

#include <cassert>
#include <set>
#include <vector>
#include <iomanip>
#include <numeric>
#include <random>
using namespace std;

vector<int> sampleKnownN(const vector<int> &S, int k) {
    vector<int> res;

    if (k <= 0) return res;
    if (k > (int) S.size()) return res; // или throw invalid_argument

    res.assign(S.begin(), S.begin() + k);


    for (int i = k; i < (int) S.size(); i++) {
        int j = rand() % (i + 1); // случайное число от 0 до i

        if (j < k) {
            res[j] = S[i];
        }
    }

    return res;
}

vector<int> sampleUnknownN(const vector<int> &stream, int k) {
    return sampleKnownN(stream, k);
}

void assertSizeAndUniqueness(const vector<int> &sample, int k) {
    assert(static_cast<int>(sample.size()) == k);

    const set<int> seen(sample.begin(), sample.end());
    assert(seen.size()== k);
}

void testBasicKnownN() {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 3;

    auto res = sampleKnownN(S, k);

    assertSizeAndUniqueness(res, k);

    for (int x: res) {
        assert(find(S.begin(), S.end(), x) != S.end());
    }

    cout << "testBasicKnownN passed\n";
}

void testBasicUnknownN() {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 3;

    auto res = sampleUnknownN(S, k);

    assertSizeAndUniqueness(res, k);

    for (int x: res) {
        assert(find(S.begin(), S.end(), x) != S.end());
    }

    cout << "testBasicUnknownN passed\n";
}

void testKEqualsN() {
    vector<int> S = {10, 20, 30, 40};
    int k = 4;

    auto res1 = sampleKnownN(S, k);
    auto res2 = sampleUnknownN(S, k);

    assertSizeAndUniqueness(res1, k);
    assertSizeAndUniqueness(res2, k);

    cout << "testKEqualsN passed\n";
}

void testKEqualsOne() {
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 1;

    auto res1 = sampleKnownN(S, k);
    auto res2 = sampleUnknownN(S, k);

    assertSizeAndUniqueness(res1, k);
    assertSizeAndUniqueness(res2, k);

    cout << "testKEqualsOne passed\n";
}

// Статистический тест:
// каждый элемент должен попадать примерно с вероятностью k/n.
void testUniformityKnownN() {
    int n = 10;
    int k = 3;
    int trials = 100000;

    vector<int> S(n);
    iota(S.begin(), S.end(), 0);

    vector<int> count(n, 0);

    for (int t = 0; t < trials; t++) {
        auto res = sampleKnownN(S, k);

        assertSizeAndUniqueness(res, k);

        for (int x: res) {
            count[x]++;
        }
    }

    double expected = (double) trials * k / n;
    double tolerance = expected * 0.08; // 8%

    for (int i = 0; i < n; i++) {
        assert(abs(count[i] - expected) <= tolerance);
    }

    cout << "testUniformityKnownN passed\n";
}

void testUniformityUnknownN() {
    int n = 10;
    int k = 3;
    int trials = 100000;

    vector<int> S(n);
    iota(S.begin(), S.end(), 0);

    vector<int> count(n, 0);

    for (int t = 0; t < trials; t++) {
        auto res = sampleUnknownN(S, k);

        assertSizeAndUniqueness(res, k);

        for (int x: res) {
            count[x]++;
        }
    }

    double expected = (double) trials * k / n;
    double tolerance = expected * 0.08; // 8%

    for (int i = 0; i < n; i++) {
        assert(abs(count[i] - expected) <= tolerance);
    }

    cout << "testUniformityUnknownN passed\n";
}

int main() {
    testBasicKnownN();
    testBasicUnknownN();
    testKEqualsN();
    testKEqualsOne();
    testUniformityKnownN();
    testUniformityUnknownN();

    cout << "All tests passed\n";
}
