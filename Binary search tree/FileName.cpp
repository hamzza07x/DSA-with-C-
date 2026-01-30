#include <iostream>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    Node(int val) {
        this->data = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BinarySearchTree {
    Node* root;

    BinarySearchTree() {
        this->root = nullptr;
    }

    // Destructor Helper
    void destroy(Node* node) {
        if (node == nullptr) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    // Destructor
    ~BinarySearchTree() {
        destroy(this->root);
    }

    // Public Insert Wrapper
    void insert(int val) {
        this->root = insert(val, this->root);
    }

    // Insert Helper
    Node* insert(int val, Node* node) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(val, node->left);
        }
        else if (val > node->data) {
            node->right = insert(val, node->right);
        }
        return node;
    }

    // Sum of All Nodes
    int sum(Node* node) {
        if (node == nullptr) return 0;
        return node->data + sum(node->left) + sum(node->right);
    }

    // Traversals
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void preOrderTraversal(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }

    void postOrderTraversal(Node* node) {
        if (node == nullptr) return;
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }

    // Public Traversal Wrappers
    void inOrder() {
        inOrderTraversal(root);
        cout << endl;
    }

    void preOrder() {
        preOrderTraversal(root);
        cout << endl;
    }

    void postOrder() {
        postOrderTraversal(root);
        cout << endl;
    }

    // Find Max
    Node* max(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Find Min
    Node* min(Node* node) {
        if (node == nullptr) return nullptr;
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Search
    Node* search(Node* node, int val) {
        if (node == nullptr || node->data == val) return node;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    // Inorder Predecessor
    Node* inPredecessor(Node* node) {
        if (node == nullptr) return nullptr;
        node = node->left;
        while (node != nullptr && node->right != nullptr) {
            node = node->right;
        }
        return node;
    }

    // Inorder Successor
    Node* inSuccessor(Node* node) {
        if (node == nullptr) return nullptr;
        node = node->right;
        while (node != nullptr && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    // Public Remove Wrapper
    void remove(int val) {
        this->root = remove(this->root, val);
    }

    // Remove Helper
    Node* remove(Node* node, int val) {
        if (node == nullptr) return node;

        if (val < node->data) {
            node->left = remove(node->left, val);
        }
        else if (val > node->data) {
            node->right = remove(node->right, val);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* toRemove = inPredecessor(node);
            node->data = toRemove->data;
            node->left = remove(node->left, toRemove->data);
        }
        return node;
    }

    // Validate BST Helper
    bool checkBinarySearchTree(Node* node, int min, int max) {
        if (node == nullptr) return true;
        if (node->data <= min || node->data >= max) return false;
        return checkBinarySearchTree(node->left, min, node->data) &&
            checkBinarySearchTree(node->right, node->data, max);
    }

    // Validate BST Public
    bool isBinarySearchTree(Node* node) {
        return checkBinarySearchTree(node, INT_MIN, INT_MAX);
    }
};

// =======================
// Sample Main Function
// =======================
int main() {
    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(5);
    bst.insert(15);
    bst.insert(3);
    bst.insert(7);
    bst.insert(12);
    bst.insert(18);

    cout << "In-order: ";
    bst.inOrder();

    cout << "Pre-order: ";
    bst.preOrder();

    cout << "Post-order: ";
    bst.postOrder();

    cout << "Sum of all nodes: " << bst.sum(bst.root) << endl;

    int searchVal = 7;
    Node* found = bst.search(bst.root, searchVal);
    if (found) cout << "Found: " << found->data << endl;
    else cout << searchVal << " not found." << endl;

    bst.remove(5);
    cout << "After removing 5, In-order: ";
    bst.inOrder();

    cout << "Is valid BST? " << (bst.isBinarySearchTree(bst.root) ? "Yes" : "No") << endl;
    cout << "Press Enter to exit....";
    cout << endl;
    cin.get();
    return 0;
}