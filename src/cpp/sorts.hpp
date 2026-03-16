#pragma once

#include <functional>
#include <vector>



void insertionSort(std::vector<int>& arr, const std::function<bool(int, int)>& cmp);
void selectionSort(std::vector<int>& arr, const std::function<bool(int, int)>& cmp);
