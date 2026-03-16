//
// Created by Jollu Emil on 5/31/26.
//
#include "random/rand_1.h"

namespace myrandom {
    std::vector<int> sampleKnownN(const std::vector<int> &S, int k) {
        std::vector<int> res;

        if (k <= 0) return res;
        if (k > (int) S.size()) return res;

        res.assign(S.begin(), S.begin() + k);

        for (int i = k; i < (int) S.size(); i++) {
            int j = rand() % (i + 1);
            if (j < k) {
                res[j] = S[i];
            }
        }

        return res;
    }

    std::vector<int> sampleUnknownN(const std::vector<int> &stream, int k) {
        return sampleKnownN(stream, k);
    }

    std::vector<std::array<int, 3> > buildReplicationScheme(int n) {
        std::vector<std::array<int, 3> > scheme;

        scheme.reserve(n);
        for (int i = 0; i < n; i++) {
            scheme.push_back({
                i,
                (i + 1) % n,
                (i + 2) % n
            });
        }

        return scheme;
    }
}
