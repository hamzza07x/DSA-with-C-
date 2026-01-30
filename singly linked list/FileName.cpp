#include<iostream>
#include<string>
using namespace std;
class Hospital {
private:
	int ID;
	string name;
	int age;
	string disease;
public:
	Hospital() {
		this->age = 0;
		this->name = "";
		this->ID = 0;
		this->disease = "";
	}
	void input() {
		cout << "Enter patient details: " << endl;
		cout << "Enter Name: ";
		getline(cin, this->name);
		cout << "Enter age: ";
		cin >> this->age;
		cin.ignore();
		cout << "Enter ID: ";
		cin >> this->ID;
		cin.ignore();
		cout << "Enter disease: ";
		getline(cin, this->disease);

	}
	void display() {
		cout << "Patient details: " << endl;
		cout << "Name: " << this->name << endl;
		cout << "Age: " << this->age << endl;
		cout << "ID: " << this->ID << endl;
		cout << "Disease: " << this->disease << endl;
	}
	int getID() {
		return this->ID;
	}
};
class Node {
public:
	Hospital patient;
	Node* next;
	Node(Hospital h) {
		this->patient = h;
		this->next = nullptr;
	}
};
class List {
public:
	Node* head;
	List() {
		this->head = nullptr;
	}
	void insert(Hospital h) {
		Node* newnode = new Node(h);
		if (head == nullptr) {
			head = newnode;
		}
		else {
			Node* temp;
			temp = head;
			while (temp->next != nullptr) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
	void search(int id) {
		Node* temp;
		temp = head;
		while (temp != nullptr) {
			if (temp->patient.getID() == id) {
				cout << "Patient found" << endl;
				temp->patient.display();
				return;
			}
			temp = temp->next;
		}
		cout << "Patient not found" << endl;
	}
	void display() {
		if (head == nullptr) {
			cout << "Empty list" << endl;
		}
		Node* temp;
		temp = head;
		while (temp != nullptr) {
			temp->patient.display();
			temp = temp->next;
		}
	}
	void remove(int id) {
		if (head == nullptr) {
			cout << "Empty list" << endl;
			return;
		}
		if (head->patient.getID() == id) {
			Node* temp;
			temp = head;
			head = head->next;
			delete temp;
			cout << "pateient removed" << endl;
			return;
		}
		Node* temp;
		temp = head;
		Node* previous;
		previous = nullptr;
		while (temp != nullptr && temp->patient.getID() != id) {
			previous = temp;
			temp = temp->next;
		}
		if (temp == nullptr) {
			cout << "Patient not found" << endl;
			return;
		}
		previous->next = temp->next;
		delete temp;
		cout << "Patient removed" << endl;
	}
};
int main() {
	int menuChoice;
	Hospital patient;
	List list;
	int userChoice;
	cout << "Enter your choice(1,0): ";
	cin >> userChoice;
	cout << endl;
	while (userChoice) {
		cout << "1.Add patient" << endl;
		cout << "2.Remove patient" << endl;
		cout << "3.Search patient" << endl;
		cout << "4.Display patient" << endl;
		cout << "Enter: ";
		cin >> menuChoice;
		cin.ignore();
		if (menuChoice == 1) {
			patient.input();
			list.insert(patient);
		}
		else if (menuChoice == 2) {
			int id;
			cout << "Enter id to remove: ";
			cin >> id;
			cin.ignore();
			list.remove(id);
		}
		else if (menuChoice == 3) {
			int id;
			cout << "Enter patient id to search: ";
			cin >> id;
			cin.ignore();
			list.search(id);
		}
		else if (menuChoice == 4) {
			list.display();
		}
		cout << "Do you want to enter more: ";
		cin >> userChoice;
	}
	cin.get();
}