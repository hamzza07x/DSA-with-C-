//#include<iostream>
//using namespace std;
//struct node {
//	int data;
//	node* next;
//	node(int val) {
//		this->data = val;
//		this->next = nullptr;
//	}
//};
//
//void insertathead(node*& head, int val) {
//	node* newnode = new node(val);
//	newnode->next = head;
//	head = newnode;
//}
//void insertattail(node*& head, int val) {
//	
//	node* newnode = new node(val);
//	if (head == nullptr) {
//		head = newnode;
//		return;
//	}
//	node* temp = head;
//	while (temp->next != nullptr) {
//		temp = temp->next;
//	}
//	temp->next = newnode;
//}
//void display(node* head) {
//	node* temp = head;
//	while (temp != nullptr) {
//		cout << temp->data << " ";
//		temp = temp->next;
//	}
//	cout << endl;
//}
//
//bool search(node* head, int val) {
//	int pos = 0;
//	node* temp = head;
//	while (temp != nullptr) {
//		if (temp->data == val) {
//			//return true;
//			cout << val << " found at position : " << pos << endl;
//			return true;
//		}
//		pos++;
//		temp = temp->next;
//	}
//	cout << "No match" << endl;
//	return false;
//}
//int main() {
//	int userChoice;
//	int val;
//	node* head = nullptr;
//	cout << "Enter you choice(1,0): ";
//	cin >> userChoice;
//	cin.ignore();
//	while (userChoice == 1) {
//		cout << "Enter value: ";
//		cin >> val;
//		cin.ignore();
//		insertattail(head, val);
//		cout << "Do you want to enter more: ";
//		cin >> userChoice;
//		cin.ignore();
//	}
//	display(head);
//	cout << endl;
//	insertathead(head, 0);
//	display(head);
//	cout << endl;
//	cout<<search(head, 3);
//	cout<<search(head, 7);
//	cout << endl;
//	system("pause");
//	return 0;
//}
#include<iostream>
using namespace std;
class node {
public:
	int data;
	node* next;
	node(int val) {
		this->data = val;
		this->next = 0;
	}
};
class  List {
public:
	node* head;
	int length;
	List(){
		this->head = nullptr;
		this->length = 0;
	}
	void insert(int val) {
		node* newnode = new node(val);
		if (head == nullptr) {
			head = newnode;
			return;
		}
		else {
			node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
		this->length++;
	}
	void display() {
		node* temp;
		temp = head;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
	void search(int val) {
		node* temp;
		temp = head;
		while (temp != nullptr) {
			if (temp->data == val) {
				cout << "matched" << endl;
				return;
			}
			temp = temp->next;
		}
		cout << "No match" << endl;
	}
};
int main() {
	List list;
	int userChoice;
	int val;
	cout << "Enter your choice (1,0): ";
	cin >> userChoice;
	cin.ignore();
	while (userChoice == 1) {
		cout << "Enter val: ";
		cin >> val;
		cin.ignore();
		list.insert(val);
		cout << "Do you want to continue: ";
		cin >> userChoice;
		cin.ignore();
		if (userChoice == 0) {
			break;
		}
	}
	list.display();
	list.search(2);
	cout << list.length << endl;
	system("pause");
	return 0;
}