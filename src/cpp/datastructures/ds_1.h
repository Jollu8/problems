//
// Created by Jollu Emil on 6/14/26.
//

#ifndef PROBLEMS_CPP_DS_1_H
#define PROBLEMS_CPP_DS_1_H
#include <vector>


namespace ds {
    /**
    * Словарь целых чисел из диапазона [1, n] с операциями за O(1)
    * в худшем случае.
    *
    * Поддерживаемые операции:
    * - insert(x): добавить x в множество;
    * - remove(x): удалить x из множества;
    * - contains(x): проверить, есть ли x в множестве.
    *
    * Инициализация выполняется за O(n).
    *
    * Если x не входит в диапазон [1, n], операции должны выбрасывать
    * std::out_of_range.
    */
    class DirectAddressSet {
    public:
        explicit DirectAddressSet(int n);

        void insert(int x);

        void remove(int x);

        bool contains(int x) const;

    private:
        std::vector<int> m_arr;
    };
};


#endif //PROBLEMS_CPP_DS_1_H
