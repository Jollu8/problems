//
// Created by Jollu Emil on 5/24/26.
//

#pragma once

#include <string>
#include <vector>

namespace string {
    std::size_t findMatch(const std::string &str, const std::string &substr);

    /**
     * Возвращает все слова из словаря, которые соответствуют заданной
     * последовательности цифр на стандартной телефонной клавиатуре.
     *
     * Соответствие клавиш:
     * 2 -> a, b, c
     * 3 -> d, e, f
     * 4 -> g, h, i
     * 5 -> j, k, l
     * 6 -> m, n, o
     * 7 -> p, q, r, s
     * 8 -> t, u, v
     * 9 -> w, x, y, z
     *
     * Слово соответствует последовательности, если:
     * - длина слова равна длине последовательности цифр;
     * - каждая буква слова находится на клавише соответствующей цифры.
     *
     * @param digits Строка из цифр от '2' до '9'.
     * @param dictionary Список слов для проверки.
     *
     * @return Все слова из dictionary, подходящие под digits.
     */
    std::vector<std::string> findWordsByPhoneDigits(const std::string &digits,
                                                    const std::vector<std::string> &dictionary);
}
