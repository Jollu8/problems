//
// Created by Jollu Emil on 6/14/26.
//

#include "ds_1.h"

#include <numeric>

namespace ds {
    DirectAddressSet::DirectAddressSet(int n) {
        m_arr.resize(n + 1, INT_MAX);
    }

    void DirectAddressSet::insert(int x) {
        if (x < 1 or x > m_arr.size() - 1) {
            throw std::out_of_range("out of range");
        }
        m_arr[x] = x;
    }

    void DirectAddressSet::remove(int x) {
        if (x < 1 or x > m_arr.size() - 1) {
            throw std::out_of_range("out of range");
        }
        m_arr[x] = INT_MAX;
    }

    bool DirectAddressSet::contains(int x) const {
        if (x < 1 or x > m_arr.size() - 1) {
            throw std::out_of_range("out of range");
        }
        return m_arr[x] != INT_MAX;
    }
}
