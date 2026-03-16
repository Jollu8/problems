//
// Created by Jollu Emil on 6/13/26.
//

#include "part_1.h"

#include <stack>
#include <vector>


namespace mystack {
    void MinStack::push(int x) {
        if (not m_st.empty()) {
            m_st.push(x);
            auto top = m_min.top();
            m_min.push(x > top ? top : x);
            return;
        }
        m_st.push(x);
        m_min.push(x);
    }

    void MinStack::pop() {
        if (m_st.empty()) {
            return;
        }
        m_st.pop();
        m_min.pop();
    }

    int MinStack::findMin() const {
        if (not empty()) {
            return m_min.top();
        }
        throw std::runtime_error("MinStack is empty");
    }

    bool MinStack::empty() const {
        return m_st.empty();
    }

    bool checkBrackets(const std::string &s, int &errorPos) {
        std::vector<char> st;

        for (std::size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push_back(s[i]);
            } else {
                if (st.empty()) {
                    errorPos = i;
                    return false;
                }
                st.pop_back();
            }
        }
        if (not st.empty()) {
            errorPos = 0;
            return false;
        }
        errorPos = -1;
        return true;
    }

    int longestBalancedSubsequence(const std::string &s) {
        std::vector<char> st;
        if (s.empty()) {
            return 0;
        }

        int cnt{};
        for (char c: s) {
            if (c == '(') {
                st.push_back(c);
            } else {
                if (st.empty()) {
                    continue;
                }
                st.pop_back();
                cnt += 2;
            }
        }
        return cnt;
    }
};
