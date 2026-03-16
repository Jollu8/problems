#include "sorts.hpp"

#include <filesystem>

#define MY_OPTIMIZE 1

namespace sorts {
    void insertionSort(std::vector<int>& arr, const std::function<bool(int, int)>& cmp) {
        for (int i = 0; i < arr.size(); i++){
            for(int j = i; j > 0 && cmp(arr[j] , arr[j - 1]); j--) {
                std::swap(arr[j], arr[j - 1]);
            }
        }
    }

    void selectionSort(std::vector<int>& arr, const std::function<bool(int, int)>& cmp) {
        for (int i = 0; i < arr.size(); i++) {
            int min = i;
            for(int j = i + 1; j <  arr.size(); j++) {
                if(cmp(arr[j], arr[min])) {
                    min = j;
                }
            }
            std::swap(arr[i], arr[min]);
        }
    }
}