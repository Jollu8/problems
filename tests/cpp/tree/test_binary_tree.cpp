#include "test_utils.h"

#include "tree/binary_tree.h"

#include <gtest/gtest.h>
#include <vector>


static utils::Node *buildList(const std::vector<int> &values) {
    utils::Node *head = nullptr;
    utils::Node *tail = nullptr;

    for (int value: values) {
        auto *node = new utils::Node(value);

        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

static std::vector<int> toVector(utils::Node *head) {
    std::vector<int> result;

    while (head != nullptr) {
        result.push_back(head->value);
        head = head->next;
    }

    return result;
}

static void deleteList(utils::Node *head) {
    while (head != nullptr) {
        utils::Node *next = head->next;
        delete head;
        head = next;
    }
}

static void deleteTree(utils::TreeNode *root) {
    if (root == nullptr) {
        return;
    }

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}


TEST(MaxDepthTest, EmptyTree) {
    utils::TreeNode *root = nullptr;

    EXPECT_EQ(tree::maxDepth(root), 0);
}

TEST(MaxDepthTest, OneNode) {
    auto *root = new utils::TreeNode{1, nullptr, nullptr};

    EXPECT_EQ(tree::maxDepth(root), 1);

    deleteTree(root);
}

TEST(MaxDepthTest, OnlyLeftBranch) {
    utils::TreeNode *root =
            new utils::TreeNode{
                1,
                new utils::TreeNode{
                    2,
                    new utils::TreeNode{3, nullptr, nullptr},
                    nullptr
                },
                nullptr
            };

    EXPECT_EQ(tree::maxDepth(root), 3);

    deleteTree(root);
}

TEST(MaxDepthTest, OnlyRightBranch) {
    utils::TreeNode *root =
            new utils::TreeNode{
                1,
                nullptr,
                new utils::TreeNode{
                    2,
                    nullptr,
                    new utils::TreeNode{3, nullptr, nullptr}
                }
            };

    EXPECT_EQ(tree::maxDepth(root), 3);

    deleteTree(root);
}

TEST(MaxDepthTest, BalancedTree) {
    utils::TreeNode *root =
            new utils::TreeNode{
                1,
                new utils::TreeNode{
                    2,
                    new utils::TreeNode{4, nullptr, nullptr},
                    new utils::TreeNode{5, nullptr, nullptr}
                },
                new utils::TreeNode{
                    3,
                    new utils::TreeNode{6, nullptr, nullptr},
                    new utils::TreeNode{7, nullptr, nullptr}
                }
            };

    EXPECT_EQ(tree::maxDepth(root), 3);

    deleteTree(root);
}

TEST(MaxDepthTest, UnbalancedTree) {
    utils::TreeNode *root =
            new utils::TreeNode{
                1,
                new utils::TreeNode{
                    2,
                    new utils::TreeNode{
                        4,
                        new utils::TreeNode{8, nullptr, nullptr},
                        nullptr
                    },
                    nullptr
                },
                new utils::TreeNode{3, nullptr, nullptr}
            };

    EXPECT_EQ(tree::maxDepth(root), 4);

    deleteTree(root);
}


TEST(ReverseListTest, EmptyList) {
    utils::Node *head = nullptr;

    utils::Node *reversed = tree::reverseList(head);

    EXPECT_EQ(reversed, nullptr);
}

TEST(ReverseListTest, OneElement) {
    utils::Node *head = buildList({10});

    utils::Node *reversed = tree::reverseList(head);

    EXPECT_EQ(toVector(reversed), std::vector<int>({10}));

    deleteList(reversed);
}

TEST(ReverseListTest, TwoElements) {
    utils::Node *head = buildList({1, 2});

    utils::Node *reversed = tree::reverseList(head);

    EXPECT_EQ(toVector(reversed), std::vector<int>({2, 1}));

    deleteList(reversed);
}

TEST(ReverseListTest, SeveralElements) {
    utils::Node *head = buildList({1, 2, 3, 4, 5});

    utils::Node *reversed = tree::reverseList(head);

    EXPECT_EQ(toVector(reversed), std::vector<int>({5, 4, 3, 2, 1}));

    deleteList(reversed);
}

TEST(ReverseListTest, NegativeValues) {
    utils::Node *head = buildList({-1, -2, 0, 3});

    utils::Node *reversed = tree::reverseList(head);

    EXPECT_EQ(toVector(reversed), std::vector<int>({3, 0, -2, -1}));

    deleteList(reversed);
}
