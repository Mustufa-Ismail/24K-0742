#include <iostream>
using namespace std;

class node {
	public:
	int key=0;
	int data=0;
	node* next=NULL;
	
	node(){
		key=0;
		data=0;
		next=nullptr;
		
		
	}
	
	node(int k,int d){
		key=k;
		data=d;
		next=nullptr;
	} 
	
};

class singlyLinkedList{
	public:
		node* head;
		
		singlyLinkedList(){
			head=nullptr;
			
		}
	
	
	singlyLinkedList(node* n)
	{
		head =n;
	}
	
	void printList() {
        node* current = head;
        while (current != nullptr) {
            cout << "Key: " << current->key << ", Data: " << current->data << endl;
            current = current->next;
        }
    }
    
    void append(int k, int d) {
        node* newNode = new node(k, d);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    void prepend(int k, int d) {
        node* newNode = new node(k, d);
        newNode->next = head;
        head = newNode;
    }
    
    void insertAfter(node* prevNode, int k, int d) {
        if (prevNode == nullptr) {
            cout << "The given previous node cannot be nullptr." << endl;
            return;
        }
        node* newNode = new node(k, d);
        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

	void deleteLast() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    
    void deleteNode(node* delNode) {
        if (head == nullptr || delNode == nullptr) {
            cout << "The list is empty or the node to delete is nullptr." << endl;
            return;
        }
        if (head == delNode) {
            head = head->next;
            delete delNode;
            return;
        }
        node* current = head;
        while (current->next != nullptr && current->next != delNode) {
            current = current->next;
        }
        if (current->next == nullptr) {
            cout << "Node to delete not found." << endl;
            return;
        }
        current->next = delNode->next;
        delete delNode;
    }
    
    void updateNode(int k, int newData) {
        node* current = head;
        while (current != nullptr) {
            if (current->key == k) {
                current->data = newData;
                return;
            }
            current = current->next;
        }
        cout << "Node with key " << k << " not found." << endl;
    }
};


    
int main() {
    
    node* first = new node(1, 10);
    node* second = new node(2, 20);
    node* third = new node(3, 30);

    
    first->next = second;
    second->next = third;
    third->next = nullptr;

    
    singlyLinkedList list(first);

    cout << "Original list:" << endl;
    list.printList();

    
  list.append(4, 40);
  list.prepend(0, 0);
  list.insertAfter(second, 5, 50);

    cout << "List after insertion:" << endl;
    list.printList();
    
    list.deleteLast();
    list.deleteNode(second);
    cout << "List after deleting "<< endl;
    list.printList();
    
    list.updateNode(3, 25);
    cout<<"list after updation" <<endl;
    list.printList();
    

    return 0;

	}