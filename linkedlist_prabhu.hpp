/*
 * Name: Anuj Prabhu
 * Date: 30 November 2023
 * Description: linkedlist_prabhu.hpp file
 * Usage: .hpp file that contains templates methods and their forward declarations; this file contains all functionality regarding my doubly linked list
 */

//import statements go here
#include <iostream>
#include <stdlib.h>
#include <string>

//using statements go here
using namespace std;

//forward declarations and function prototypes go here
template<typename T>
class Node;
template<typename T>
class LinkedList;

template<typename T>
class Node {
	//private
	private:
		//member properties
		T data;
		Node<T>* next;
		Node<T>* previous;
		
		friend class LinkedList<T>;
	
	//public
	public:
		//default constructor
		Node();
		
		//overloaded constructors
		Node(T);
		Node(T, Node<T>*, Node<T>*);
		
		//member functions
		T getData();
		void setData(T);
		
		Node<T>* getNext();
		void setNext(Node<T>*);
		
		Node<T>* getPrevious();
		void setPrevious(Node<T>*);
};

//Node class default constructor
template<typename T>
Node<T>::Node() {
	this->data = nullptr;
	this->next = nullptr;
	this->previous = nullptr;
}

//Node class overloaded constructor that sets Node data
template<typename T>
Node<T>::Node(T data) {
	this->data = data;
	this->next = nullptr;
	this->previous = nullptr;
}

//Node class overloaded constructor that sets Node properties
template<typename T>
Node<T>::Node(T data, Node<T>* next, Node<T>* previous) {
	this->data = data;
	this->next = next;
	this->previous = previous;
}

//getter
template<typename T>
T Node<T>::getData() {
	return this->data;
}

//setter
template<typename T>
void Node<T>::setData(T data) {
	this->data = data;
}

//getter
template<typename T>
Node<T>* Node<T>::getNext() {
	return this->next;
}

//setter
template<typename T>
void Node<T>::setNext(Node<T>* next) {
	this->next = next;
}

//getter
template<typename T>
Node<T>* Node<T>::getPrevious() {
	return this->previous;
}

//setter
template<typename T>
void Node<T>::setPrevious(Node<T>* previous) {
	this->previous = previous;
}

//LinkedList class
template<typename T>
class LinkedList {
	//private
	private:
	//Node<T>* head;
	//Node<T>* tail;
	
	//public
	public:
		Node<T>* head;
        	Node<T>* tail;
		//default constructor
			LinkedList();
		
		//destructor
			~LinkedList();
		
		//member methods
			int Length();
			void AddToFront(T);
			void AddToEnd(T);
			void AddAtIndex(T, int);
			void AddBefore(Node<T>*, T);
			void AddAfter(Node<T>*, T);
			T RemoveFromFront();
			T RemoveFromEnd();
			void RemoveTheFirst(T);
			void RemoveAllOf(T data);
			T RemoveBefore(Node<T>*);
			T RemoveAfter(Node<T>*);
			bool ElementExists(T);
			Node<T>* Find(T);
			int IndexOf(T);
			T RetrieveFront();
			T RetrieveEnd();
			T Retrieve(int);
			void PrintList();
			void Empty();
};

//LinkedList class constructor
template<typename T>
LinkedList<T>::LinkedList() {//(?)
	this->head = nullptr;
	this->tail = nullptr;
}

//destructor
template<typename T>
LinkedList<T>::~LinkedList() {
	Node<T>* temp = head;
	
	while(temp != nullptr) {//loop through list
		head = head->next;
		delete temp;//delete each node
		temp = head;
	}
}

//method that returns LinkedList length
template<typename T>
int LinkedList<T>::Length() {
	int counter = 0;
	
	Node<T>* temp = head;
	while(temp != nullptr) {//changed from temp->next to temp
		counter++;
		temp = temp->next;
	}
	return counter;
}

//method that adds a node to the front of the list
template<typename T>
void LinkedList<T>::AddToFront(T data) {
	Node<T>* newNode = new Node(data);

	if(head == nullptr) {
		//cout << "addToFront head =  null" << endl;
		head = newNode;
		tail = newNode;
	}
	else {
		//cout << "addToFront list aldready in place" << endl;
		newNode->next = head;
		head->previous = newNode;
		head = newNode;
	}
}

//method that adds a node of the given data to the end of the list
template<typename T>
void LinkedList<T>::AddToEnd(T data) {
	Node<T>* newNode = new Node(data);
	if(head == nullptr) {
		//cout << "list does not exist" << endl;
		head = newNode;
		tail = newNode;
	}
	else {
		tail->next = newNode;
		newNode->previous = tail;
		tail = newNode;
	}
}

//method that adds a node at a given index of the list
template<typename T>
void LinkedList<T>::AddAtIndex(T data, int index) {
	int length = Length();
	if(index < 0 || index > length) {
		throw std::out_of_range("Index out of bounds");
	}
	
	else if(index == 0) {
		AddToFront(data);
	}
	else if(index == length) {
		AddToEnd(data);
	}
	else {
		Node<T>* newNode = new Node(data);
		
		Node<T>* before = nullptr;
		Node<T>* current = head;
		
		int counter = 0;
		while(counter != index) {
			before = current;
			current = current->next;
			counter++;
		}
		newNode->next = current;//changed before->next to current
		before->next = newNode;
		newNode->previous = before;//changed current->previous to before
		current->previous = newNode; 
	}
}

//adds a node of given data before the given node
template<typename T>
void LinkedList<T>::AddBefore(Node<T>* node, T data) {
	if(node->previous == nullptr) {
		AddToFront(data);
	}
	else {
		Node<T>* newNode = new Node(data);
		
		newNode->next = node->previous->next;
		node->previous->next = newNode;
		newNode->previous = node->previous;
		node->previous = newNode;
	}
}

//adds a node of given data after the node passed in parameters
template<typename T>
void LinkedList<T>::AddAfter(Node<T>* node, T data) {
	if(node->next == nullptr) {
		AddToEnd(data);
	}
	else {
		Node<T>* newNode = new Node(data);
		
		node->next->previous = newNode;
		newNode->previous = node;
		newNode->next = node->next;
		node->next = newNode;	
	}
}

//remove a node from the front of the list
template<typename T>
T LinkedList<T>::RemoveFromFront() {
	if(head == nullptr) {
		cout << "RemoveFromFront(): list does not exist" << endl;
		throw std::runtime_error("RemoveFromFront(): list does not exist");
	
	}
	else if(head == tail){//only one element
                T content = head->getData();
                delete head;
                head = nullptr;
                tail = nullptr;
                return content;
        }
	else{
		Node<T>* temp = head;
		//cout << (temp == nullptr)<<endl;
		T contents = temp->getData();
		head = head->next;
		if(head != nullptr) {
			head->previous = nullptr;
		}
		//temp->next = nullptr;
		//temp->previous = nullptr; (dont uncomment this)
		
		delete temp;
		
		return contents;
	}
}

//removes a node from the end of this list
template<typename T>
T LinkedList<T>::RemoveFromEnd() {
	if(head == nullptr) {
		throw std::runtime_error("RemoveFromEnd(): list does not exist");
	}
	else if(head == tail){//only one element
		T content = head->getData();
		delete head;
		head = nullptr;
		tail = nullptr;
		return content;
	}else{
		Node<T>* temp = tail;
		T contents = temp->getData();
		
		tail = tail->previous;
		if(tail != nullptr) {
			tail->next = nullptr;
		}
		//temp->previous = nullptr;
		
		delete temp;
		
		return contents;
	}
}

//method removes the first occurence of the node containing the given data
template<typename T>
void LinkedList<T>::RemoveTheFirst(T data) {
	if(head == nullptr) {
		throw std::runtime_error("RemoveTheFirst(): list does not exist");
	}
	else {
		//Node<T>* before = nullptr;
		Node<T>* current = head;
				
		while(current != nullptr && current->getData() != data) {
			//before = current;
			current = current->next;
		}
		
		if(current->previous == nullptr) {
			RemoveFromFront();
		}
		else if(current->next == nullptr) {
			RemoveFromEnd();
		}
		else {
			current->previous->next = current->next;
			current->next->previous = current->previous;
			
			current->previous = nullptr;
			current->next = nullptr;
			
			delete current;
		}
	}
}

//method removes all occurences of nodes containing the given data
template<typename T>
void LinkedList<T>::RemoveAllOf(T data) {
	Node<T>* temp = head;
	
	while(temp != nullptr) {
		if(temp->getData() == data) {
			if(temp->previous == nullptr) {
				Node<T>* headToDelete = temp;
				
				head = temp->next;
				head->previous = nullptr;
				
				temp = temp->next;
				
				headToDelete->next = nullptr;
				delete headToDelete;
			}
			else if(temp->next == nullptr) {
				Node<T>* tailToDelete = temp;
				
				tail = temp->previous;
				tail->next = nullptr;
				
				temp = temp->next;
				
				tailToDelete->previous = nullptr;
				delete tailToDelete;
			}
			else {
				Node<T>* nodeToDelete = temp;
				
				temp->previous->next = temp->next;
				temp->next->previous = temp->previous;
				
				temp = temp->next;
				
				nodeToDelete->next = nullptr;
				nodeToDelete->previous = nullptr;
				
				delete nodeToDelete;
			}
		}
		else {
		temp = temp->next;
		}
	}
}

//removes the node before the given node
template<typename T>
T LinkedList<T>::RemoveBefore(Node<T>* node) {
	if(node->previous == nullptr) {
		throw std::runtime_error("RemoveBefore(): node->previous = nullptr");
	}
	else if(node->previous->previous == nullptr) {
		T contents = RemoveFromFront();
		
		return contents;
	}
	else {
		Node<T>* temp = node->previous;
		T contents = temp->getData();
		
		node->previous->previous->next = node->previous->next;
		node->previous = node->previous->previous;
		
		temp->previous = nullptr;
		temp->next = nullptr;
		delete temp;
		
		return contents;
	}
}

//removes the node that comes after the given node
template<typename T>
T LinkedList<T>::RemoveAfter(Node<T>* node) {
	if(node->next == nullptr) {
		throw std::runtime_error("RemoveAfter(): node->next = nullptr");
	}
	else if(node->next->next == nullptr) {
		T contents = RemoveFromEnd();
		
		return contents;
	}
	else {
		Node<T>* temp = node->next;
		T contents = temp->getData();
		
		node->next = node->next->next;
		node->next->next->previous = node->next->previous;
		
		temp->next = nullptr;
		temp->previous = nullptr;
		delete temp;
		
		return contents;
	}
}

//method returns true if the given element exists in the list
template<typename T>
bool LinkedList<T>::ElementExists(T data) {
	Node<T>* current = head;
	
	while(current != nullptr) {
		if (current->getData() == data) {
			return true;
		}
		current = current->next;
	}
	return false;
}

//method finds and returns the node containing the data passed as a parameter
template<typename T>
Node<T>* LinkedList<T>::Find(T data) {
	if(head == nullptr) {
		//throw std::runtime_error("Find(): list is empty");
		return nullptr;
	}
	else {
		Node<T>* current = head;
		
		while(current != nullptr) {
			if(current->getData() == data) {
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
}

//method that returns the index of the first instance of data in the list
template<typename T>
int LinkedList<T>::IndexOf(T data) {
	int counter = 0;
	Node<T>* current = head;

	while(current != nullptr) {
		if(current->getData() == data) {
			return counter;
		}
		current = current->next;
		counter++;
	}
	return -1;
}

//method that returns the first element of the list
template<typename T>
T LinkedList<T>::RetrieveFront() {
	if(head == nullptr) {
		throw std::runtime_error("RetrieveFront(): list does not exist");
	}
	else {
		return head->data;
	}
}

//method that returns the last element of the list
template<typename T>
T LinkedList<T>::RetrieveEnd() {
	if(head == nullptr || tail == nullptr) {
		throw std::runtime_error("RetrieveEnd(): head || tail does not exist");
	}
	else {
		return tail->data;
	}
}

//method that returns the data of the node at the given index
template<typename T>
T LinkedList<T>::Retrieve(int index) {
	int length = Length();
	if(index < 0 || index >= length) {
		throw std::out_of_range("Index out of bounds");
	}
	else {
		int counter = 0;
		Node<T>* current = head;
		
		while(counter != index) {
			current = current->next;
			counter++;
		}
		return current->data;
	}
}

//method that prints the entire doubly linked list
template<typename T>
void LinkedList<T>::PrintList() {
	Node<T>* current = head;
	
	while(current != nullptr) {
		cout << current->getData() << " ";
		current = current->next;
	}
	cout << endl;
}

//method that empties the linked list by destructing it
template<typename T>
void LinkedList<T>::Empty() {
	Node<T>* temp = head;
	
	while(temp != nullptr) {
		head = head->next;
		delete temp;
		temp = head;
	}
}
