#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // ------------------------
    // Insert node using loop
    // Time Complexity: O(h)
    // ------------------------
    void insert(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* parent = nullptr;
        Node* current = root;
        while (current != nullptr) {
            parent = current;
            if (value < current->data)
                current = current->left;
            else if (value > current->data)
                current = current->right;
            else {
                // Value already exists, do not insert
                delete newNode;
                return;
            }
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    // ------------------------
    // Search using loop
    // Time Complexity: O(h)
    // ------------------------
    Node* search(int key) {
        Node* current = root;
        while (current != nullptr) {
            if (key == current->data)
                return current;
            else if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }
        return nullptr;
    }

    // ------------------------
    // Find minimum node starting from given node
    // Time Complexity: O(h)
    // ------------------------
    Node* findMin(Node* node) {
        while (node && node->left != nullptr)
            node = node->left;
        return node;
    }

    // ------------------------
    // Delete node using loop + recursion on right subtree only
    // Time Complexity: O(h)
    // ------------------------
    void deleteValue(int key) {
        Node* parent = nullptr;
        Node* current = root;

        // Find node to delete
        while (current != nullptr && current->data != key) {
            parent = current;
            if (key < current->data)
                current = current->left;
            else
                current = current->right;
        }

        if (current == nullptr)
            return; // Not found

        // Case 1: Node has no child or only one child
        if (current->left == nullptr || current->right == nullptr) {
            Node* child = (current->left) ? current->left : current->right;

            if (parent == nullptr)
                root = child; // Node to delete is root
            else if (parent->left == current)
                parent->left = child;
            else
                parent->right = child;

            delete current;
        }
        // Case 2: Node has two children
        else {
            // Find minimum in right subtree
            Node* successor = findMin(current->right);
            int val = successor->data;
            deleteValue(successor->data); // Delete successor
            current->data = val;
        }
    }

    // ------------------------
    // Inorder traversal O(n)
    // ------------------------
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorderTraversal() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    cout << "Inorder: "; bst.inorderTraversal();

    bst.deleteValue(20);
    bst.deleteValue(30);
    bst.deleteValue(50);

    cout << "After deletion, inorder: "; bst.inorderTraversal();

    return 0;
}
