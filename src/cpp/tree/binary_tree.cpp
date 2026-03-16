//
// Created by Jollu Emil on 6/13/26.
//

#include "binary_tree.h"

#include <algorithm>

namespace tree {
    int maxDepth(utils::TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return std::max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }


    utils::Node *reverseList(utils::Node *head) {
        // utils::Node* prev = nullptr;
        // while (head != nullptr) {
        //     std::swap(prev, head->next);
        //     std::swap(prev, head);
        // }
        // return prev;

        if (head == nullptr or head->next == nullptr) { return head; }
        auto *prev = reverseList(head->next);


        head->next->next = head;
        head->next = nullptr;
        return prev;
    }
}
