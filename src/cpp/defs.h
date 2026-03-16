//
// Created by Jollu Emil on 6/13/26.
//

#pragma once
namespace utils {
    class TreeNode {
    public:
        TreeNode(int v) : value(v) {
        }

        TreeNode(int value, TreeNode *left, TreeNode *right)
            : value(value),
              left(left),
              right(right) {
        }

        friend bool operator==(const TreeNode &lhs, const TreeNode &rhs) {
            return lhs.value == rhs.value
                   && lhs.left == rhs.left
                   && lhs.right == rhs.right;
        }

        friend bool operator!=(const TreeNode &lhs, const TreeNode &rhs) {
            return !(lhs == rhs);
        }


        int value{};
        TreeNode *left = nullptr;
        TreeNode *right = nullptr;
    };


    class Node {
    public:
        Node(const Node &node) {
            value = node.value;
            next = node.next;
            prev = node.prev;
        }

        Node(Node &&node) noexcept {
            value = node.value;
            next = node.next;
            prev = node.prev;
            node.next = nullptr;
            node.prev = nullptr;
        }

        explicit Node(const int value) {
            this->value = value;
            next = prev = nullptr;
        }


        int value{};
        Node *next = nullptr;
        Node *prev = nullptr;
    };
}
