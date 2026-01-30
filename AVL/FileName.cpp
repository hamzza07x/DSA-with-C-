#include<iostream>
using namespace std;
struct Node {
	int data;
	Node* left;
	Node* right;
	int height;
	Node(int val) {
		this->data = val;
		this->left = nullptr;
		this->right = nullptr;
		this->height = 1;
	}
};
struct AVLTree{
	Node* root;
	AVLTree() {
		this->root = nullptr;
	}
	int getHeight(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		return node->height;
	}
	Node* rightRotation(Node* node) {
		Node* newRoot = node->left;
		Node* tempNode = newRoot->right;
		newRoot->right = node;
		node->left = tempNode;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
		return newRoot;
	}
	Node* leftRotstion(Node* node) {
		Node* newRoot = node->right;
		Node* tempNode = newRoot->left;
		newRoot->left = node;
		node->right = tempNode;
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
		return newRoot;
	}
	int getBalance(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		int balance = getHeight(node->left) - getHeight(node->right);
		return balance;
	}
	Node* insert(Node* node, int val) {
		Node* newNode = new Node(val);
		if (node == nullptr) {
			return newNode;
		}
		if (val < node->data) {
			node->left = insert(node->left, val);
		}
		else if (val > node->data) {
			node->right = insert(node->right, val);
		}
		else {
			return node;
		}
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		int balance = getBalance(node);
		if (balance > 1 && val < node->left->data) {
			return rightRotation(node);
		}
		if (balance < -1 && val > node->right->data) {
			return leftRotstion(node);
		}
		if (balance > 1 && val > node->left->data) {
			node->left = leftRotstion(node->left);
			return rightRotation(node);
		}
		if (balance < -1 && val < node->right->data) {
			node->right = rightRotation(node->right);
			return leftRotstion(node);
		}
		return node;
	}
	void preorderTraversal(Node* node) {
		if (node == nullptr) {
			return;
		}
		cout << node->data << " ";
		preorderTraversal(node->left);
		preorderTraversal(node->right);
	}
};
int main() {
	AVLTree tree;
	tree.root = tree.insert(tree.root, 10);
	tree.root = tree.insert(tree.root, 20);
	tree.root = tree.insert(tree.root, 30);
	tree.root = tree.insert(tree.root, 40);
	tree.root = tree.insert(tree.root, 50);
	tree.root = tree.insert(tree.root, 25);
	cout << "Preorder traversal: ";
	tree.preorderTraversal(tree.root);
	cout << tree.getHeight(tree.root);
	cout << endl;
	cin.get();
	return 0;
}