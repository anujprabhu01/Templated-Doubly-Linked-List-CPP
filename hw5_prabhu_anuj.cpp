/*
 * Name: Anuj Prabhu
 * Date: 29 November 2023
 * Description: hw5_prabhu_anuj.hpp file
 * Usage: main file that thoroughly tests my doubly linked list
 */

#include <iostream>
#include <stdlib.h>
#include "linkedlist_prabhu.hpp"

using namespace std;

int main(int argc, char** argv) {
	LinkedList<int>* list = new LinkedList<int>();
	//cout <<list->RetrieveFront() << endl;
	//cout <<list->RetrieveEnd() << endl;
	list->AddToEnd(101);
	list->PrintList();
	list->AddToEnd(13);
	list->PrintList();
	list->AddToEnd(6);
	list->PrintList();
	list->RemoveFromEnd();
	list->PrintList();
	//cout << "1.The head is:" << list->head->getData()<< endl;
        //cout << "1.The tail is:" << list->tail->getData()<< endl;
	list->RemoveFromFront();
	list->PrintList();
	//cout << "2.The head is:" << list->head->getData()<< endl;
        //cout << "2.The tail is:" << list->tail->getData()<< endl;
	list->head->getData();	
	list->RemoveFromEnd();
	//cout << (list->head==nullptr)<< "-"<<(list->tail == nullptr)<<endl;
	//cout << "3.The head is:" << list->head->getData()<< endl;
	//cout << "3.The tail is:" << list->tail->getData()<< endl;
	//list->PrintList();
	//cout << "im here"<<endl;
	//list->RemoveFromFront();
	list->PrintList();

return 0;
}
