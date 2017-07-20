# Linked-List
BU MET CS341 Midterm #2

1.	 Please modify the program below so that the user values will be entered into the linked list in ascending order.  For example, if A and C are entered into the list, a node containing B would be entered between them. Or, if B was already entered into the list, the value A would be entered into the list prior to B.  Or if A was already entered into the list, B would be entered following A in the list.
// John Maslanka  BagMenuProg3-withContainer.cpp Baglist Demo  10/17/2010
// Note: This application contains a delete method to remove a Node from the 
//       linked list. This program tests the return value from the new operator.
// Edit: 09/30/2009 Create Bagmenu top-level access to BagList application.
// Edit: 10/17/2010 Complete rewrite of delete method to decouple it from the main. 
//		Also fixed bug which caused the end of the list to be lost when a   
//			memberin the middle was deleted. 
//          Also, suggestions from student Yelena Oulanova to do delete cleanly.
// Edit: 02/15/2012 Changed some method names to more closely 
//			reflect the actions of their procedures
// Edit: 02/20/2012 Changed User input from double to string type

#include <string>
#include <iostream>
using namespace std;

//#include "Node.h"
class Node {
public:
	Node () {}
	Node* putNode (Node*, string);
	string getNodeData ();
	Node* getNextPointer ();
	void putNextPointer (Node*);
private:
	string st;
	Node* nextPtr;
};

#include <cstdlib>

Node* Node::getNextPointer (){
	return nextPtr;
}
void Node::putNextPointer (Node* x){
	this->nextPtr = x;
}
Node* Node::putNode (Node* x, string s) {
	Node* temp = NULL;
	if (temp = new Node()) {
		temp->nextPtr = x;
		temp->st = s;
	}
	return temp;
}
string Node::getNodeData() {
	return st;
}

//#include "BagList.h"
class BagList {  //Container class
public:
	BagList ();
	bool putANode (string);
	void getList ();
	Node* findNode (string);
	void  deleteNode (string);
private:
	Node* ListPointer;
};


BagList::BagList () 
	{ListPointer = NULL;}
bool BagList::putANode (string udata) {
	bool x = false;
	Node* temp1;
	Node A;
	temp1 = A.putNode (ListPointer, udata);
	if (temp1 != NULL)
	{	ListPointer = temp1;
		x = true;
	}
	return x;
}
void BagList::getList() { // return value shoould be a string of concatenated variables
	Node* temp;
	for (temp = ListPointer; temp != NULL;
			temp = temp->getNextPointer()) 
		cout << " User Data " << temp->getNodeData () << endl;
}
Node* BagList::findNode (string udata){
	Node* temp;
	for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata; 
		       temp = temp->getNextPointer());
	return temp;
}
void BagList::deleteNode (string udata) {  // suggested by Yelena Oulenova
	Node* delPtr = findNode (udata); 
	if (delPtr != NULL) {
		if (ListPointer == delPtr)
			ListPointer = delPtr->getNextPointer();
		else { Node* previousPtr; 
			Node* temp = ListPointer; 
			for (previousPtr = NULL; temp != delPtr; 
				previousPtr = temp, temp = temp->getNextPointer());
			previousPtr->putNextPointer(delPtr->getNextPointer());
		}
		delete delPtr;
		delPtr = NULL; //clears previous reference retained in this variable
		cout << "Node deleted: " << udata << endl;
	}
	else
		cout << "Node not found: " << udata << endl;
}

int main () {
    BagList A;  // declare a Container object
    string udata;
	bool cont = true;
    char sel;
    while (!cin.eof() && cont == true) {
	cout << "Enter your function: Add, Delete, Exit, Find, List: ";
	cin >> sel;
	if (!cin.eof()) {
	    switch (sel) {		
		case 'A': case 'a': {
		    cout << "Enter a string of characters or control-z to end";
		    cin >> udata;
		    if (!cin.eof())
cont = A.putANode(udata);
		    break;
		}
		case 'D': case 'd': { 
			cout << "Please Enter User Data value to delete: ";
			cin >> udata;
			if (!cin.eof()) 
				A.deleteNode (udata);
			break;
			}
		case 'E': case 'e': {
			cont = false;
			break;
			}
		case 'F': case 'f': {
			cout << "Please Enter User Data value to find: ";
			cin >> udata;
			if (!cin.eof()) 
				if (A.findNode(udata))
cout << "Node " << udata << " found" << endl;
				else
cout << "Node " << udata << " not found" << endl; 
			break;
			}
		case 'L': case 'l': {
			cout << "List of nodes" << endl;
			A.getList();
			cout << endl;
			break;
			}
		default: {
			cout << "Invalid function entered." << endl;
			break;
			 }
		   }
	    }
	}
	return 0;
}

