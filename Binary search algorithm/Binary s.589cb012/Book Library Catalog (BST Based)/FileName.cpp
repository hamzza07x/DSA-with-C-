#include<iostream>
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
	void destroy(Node* node) {
		if (node == nullptr) {
			return;
		}
		destroy(node->right);
		destroy(node->left);
		delete node;
	}
	~BinarySearchTree() {
		destroy(this->root);
	}
	Node* insert(int val, Node* node) {
		if (node == nullptr) {
			Node* newNode = new Node(val);
			return newNode;
		}
		if (val == node->data) {
			return node;
		}
		if (val < node->data) {
			node->left = insert(val, node->left);
		}
		if (val > node->data) {
			node->right = insert(val, node->right);
		}
		return node;
	}
	int sum(Node* node) {
		if (node == nullptr) {
			return 0;
		}
		int sumOfNodes = node->data + sum(node->left) + sum(node->right);
		return sumOfNodes;
	}
	void inOrderTraversal(Node* node) {
		if (node == nullptr) {
			return;
		}
		inOrderTraversal(node->left);
		cout << node->data << " ";
		inOrderTraversal(node->right);
	}
	void preOrderTraversal(Node* node) {
		if (node == nullptr) {
			return;
		}
		cout << node->data << " ";
		preOrderTraversal(node->left);
		preOrderTraversal(node->right);
	}
	void postOrderTraversal(Node* node) {
		if (node == nullptr) {
			return;
		}
		postOrderTraversal(node->left);
		postOrderTraversal(node->right);
		cout << node->data << " ";
	}
	Node* max(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		while (node != nullptr && node->right != nullptr) {
			node = node->right;
		}
		return node;
	}
	Node* min(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		while (node != nullptr && node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node* search(Node* node, int val) {
		if (node == nullptr || node->data == val) {
			return node;
		}
		if (val < node->data) {
			Node* toSearch = search(node->left, val);
			return toSearch;
		}
		if (val > node->data) {
			Node* toSearch = search(node->right, val);
			return toSearch;
		}
		return nullptr;
	}
	Node* inPredecessor(Node* node) {
		if (node == nullptr) {
			return node;
		}
		node = node->left;
		while (node != nullptr && node->right != nullptr) {
			node = node->right;
		}
		return node;
	}
	Node* inSuccessor(Node* node) {
		if (node == nullptr) {
			return node;
		}
		node = node->right;
		while (node != nullptr && node->left != nullptr) {
			node = node->left;
		}
		return node;
	}
	Node* remove(Node* node, int val) {
		if (node == nullptr) {
			return node;
		}
		if (val < node->data) {
			node->left = remove(node->left, val);
		}
		else if (val > node->data) {
			node->right = remove(node->right, val);
		}
		else {
			if (node->left == nullptr) {
				Node* toRemove = node->right;
				delete node;
				return toRemove;
			}
			else if (node->right == nullptr) {
				Node* toRemove = node->left;
				delete node;
				return toRemove;
			}
			Node* toRemvoe = inPredecessor(node);
			node->data = toRemvoe->data;
			node->left = remove(node->left, toRemvoe->data);
		}
		return node;
	}
	bool checkBinarySearchTree(Node* node, int min, int max) {
		if (node == nullptr) {
			return true;
		}
		if (node->data <= min || node->data >= max) {
			return false;
		}
		if (checkBinarySearchTree(node->left, min, node->data) && checkBinarySearchTree(node->right, node->data, max)) {
			return true;
		}
		else {
			return false;
		}
	}
	bool isBinarySearchTree(Node* node) {
		bool isBST = checkBinarySearchTree(node, INT_MIN, INT_MAX);
		return isBST;
	}
};
int main() {
	BinarySearchTree Tree;
	Tree.root = Tree.insert(1001, Tree.root);
	Tree.root = Tree.insert(800, Tree.root);
	Tree.root = Tree.insert(1500, Tree.root);
	Tree.root = Tree.insert(400, Tree.root);
	Tree.root = Tree.insert(900, Tree.root);
	Tree.root = Tree.insert(1200, Tree.root);
	Tree.root = Tree.insert(2000, Tree.root);
	Tree.root = Tree.insert(1005, Tree.root);
	Tree.root = Tree.insert(1100, Tree.root);
	Tree.preOrderTraversal(Tree.root);
	cout << endl;
	Tree.postOrderTraversal(Tree.root);
	cout << endl;
	int sumOfIDs = Tree.sum(Tree.root);
	cout << "Sum of all IDs: " << sumOfIDs << endl;
	Tree.remove(Tree.root, 1200);
	Tree.preOrderTraversal(Tree.root);
	cout << endl;
	cout << "Inorder succesor: " << Tree.inSuccessor(Tree.root)->data << endl;
	if (Tree.isBinarySearchTree(Tree.root)) {
		cout << "IS VALID" << endl;
	}
	else {
		cout << "NOT VALID" << endl;
	}
	cin.get();
	return 0;
}