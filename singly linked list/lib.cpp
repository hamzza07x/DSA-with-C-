#include<iostream>
#include<string>
using namespace std;
class Book {
private:
	int ID;
	string title;
	string borrowerName;
	string dueDate;
public:
	Book()  {
		this->ID = 0;
		this->title = "";
		this->borrowerName = "";
		this->dueDate = "";
	}
	void input() {
		cout << "Enter book details." << endl;
		cout << "Enter ID: ";
		cin >> this->ID;
		cin.ignore();
		cout << "Enter title: ";
		getline(cin, this->title);
		cout << "Enter Borrower name: ";
		getline(cin, this->borrowerName);
		cout << "Enter due date: ";
		getline(cin, this->dueDate);
	}
	void borrowBook() {

	}
	void returnBook() {

	}
	void display() {
		cout << "Book details." << endl;
		cout << "ID: " << this->ID << endl;
		cout << "Title: " << this->title << endl;
		cout << "Borrower name: " << this->borrowerName << endl;
		cout << "Due date: " << this->dueDate << endl;
	}
	int getID() {
		return this->ID;
	}
	~Book() {

	}
};
class Node {
public:
	Book book;
	Node* next;
	Node(Book b) {
		this->book = b;
		this->next = nullptr;
	}
};
class List {
public:
	Node* head;
	List() {
		this->head = nullptr;
	}
	void insert(Book b) {
		Node* newnode = new Node(b);
		if (this->head == nullptr) {
			head = newnode;
			cout << "Book borrowed" << endl;
			return;
		}
		else {
			Node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
			cout << "Book borrowed" << endl;
			return;
		}
	}
	void remove(int i) {
		if (this->head == nullptr) {
			cout << "Empty list" << endl;
			return;
		}
		if (this->head->book.getID() == i) {
			Node* temp;
			temp = head;
			delete temp;
			cout << "Book returned" << endl;
			return;
		}
		Node* temp;
		temp = head;
		Node* previous;
		previous = nullptr;
		while (temp != nullptr && temp->book.getID() != i) {
			previous = temp;
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "Book not found" << endl;
			return;
		}
		previous->next = temp->next;
		delete temp;
		cout << "Book removed" << endl;
	}
	void display() {
		if (this->head == nullptr) {
			cout << "Empty list" << endl;
			return;
		}
		Node* temp;
		temp = head;
		while (temp != nullptr) {
			temp->book.display();
			temp = temp->next;
		}
		cout << endl;
	}
	void search(int i) {
		if (this->head == nullptr) {
			cout << "Empty list" << endl;
			return;
		}
		Node* temp;
		temp = head;
		while (temp != nullptr) {
			if (temp->book.getID() == i) {
				cout << "Book found" << endl;
				temp->book.display();
				return;
			}
			temp = temp->next;
		}
		cout << "Book not found" << endl;
	}
};
int main() {
	int userChoice;
	int choice;
	List list;
	Book book;
	cout << "Enter: ";
	cin >> userChoice;
	cout << endl;
	while (userChoice) {
		cout << "1.Borrow" << endl;
		cout << "2.Return" << endl;
		cout << "3.Search" << endl;
		cout << "4.Display" << endl;
		cout << "Enter: ";
		cin >> choice;
		if (choice == 1) {
			book.input();
			list.insert(book);
		}
		else if (choice == 2) {
			int id;
			cout << "Enter id: ";
			cin >> id;
			list.remove(id);
		}
		else if (choice == 3) {
			int id;
			cout << "Enter book id: ";
			cin >> id;
			list.search(id);
		}
		else if (choice == 4) {
			list.display();
		}
		cout << "Do you want to enter more: ";
		cin >> userChoice;
	}
	cin.get();
	return 0;
}