#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

struct Stack {
    Node* top;
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    int pop() {
        if (isEmpty()) return -1;
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }
    int peek() {
        return isEmpty() ? -1 : top->data;
    }
};

struct Queue {
    Node* front;
    Node* rear;
    Queue() {
        front = rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enQueue(int x) {
        Node* newNode = new Node(x);
        if (rear == nullptr) {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    int deQueue() {
        if (isEmpty()) return -1;
        int val = front->data;
        Node* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return val;
    }
};

struct Graph {
    int** matrix;
    int vertices;

    Graph(int v) {
        vertices = v;
        matrix = new int* [v];
        for (int i = 0; i < v; i++) {
            matrix[i] = new int[v];
            for (int j = 0; j < v; j++) {
                matrix[i][j] = 0;
            }
        }
    }

    void addEdge(int u, int v) {
        matrix[u][v] = 1;
        matrix[v][u] = 1; // undirected
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void DFS(int start) {
        bool* visited = new bool[vertices] {false};
        Stack s;
        s.push(start);
        cout << "DFS Traversal:";
        while (!s.isEmpty()) {
            int current = s.pop();
            if (!visited[current]) {
                cout << " " << current;
                visited[current] = true;
                for (int i = vertices - 1; i >= 0; i--) {
                    if (matrix[current][i] == 1 && !visited[i]) {
                        s.push(i);
                    }
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    void BFS(int start) {
        bool* visited = new bool[vertices] {false};
        Queue q;
        q.enQueue(start);
        visited[start] = true;
        cout << "BFS Traversal:";
        while (!q.isEmpty()) {
            int current = q.deQueue();
            cout << " " << current;
            for (int i = 0; i < vertices; i++) {
                if (matrix[current][i] == 1 && !visited[i]) {
                    q.enQueue(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
        delete[] visited;
    }

    ~Graph() {
        for (int i = 0; i < vertices; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.display();
    g.DFS(0);
    g.BFS(0);
    cin.get();
    return 0;
}
