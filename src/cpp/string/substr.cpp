//
// Created by Jollu Emil on 5/24/26.
//
#include "string/substr.h"
namespace string {
    std::size_t substr(const std::string& str, const std::string& sub) {
        if (sub.empty()) return 0;
        if (str.size() < sub.size()) return std::string::npos;

        for (std::size_t i = 0; i <= str.size() - sub.size(); ++i) {
            std::size_t j = 0;
            for (; j < sub.size() && str[i + j] == sub[j]; ++j) {}
            if (j == sub.size()) {
                return i;
            }
        }
        return std::string::npos;
    }
}
