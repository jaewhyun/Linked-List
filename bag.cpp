//
//  bag.cpp
//  midterm2
//
//  Created by Jae Won Hyun on 10/23/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//
// edit history:
// add method to accounted for the number of nodes in order to decide whereand how to put in a new node
// add method to see if there are no nodes, add a new node
// add method to see if there is one existing node; determine if the user input is bigger or smaller than the existing node data before inputing a new node to the right or the left.
// add method to see if there is more than one existing node; determine if the user input is smaller than the first node
// add method to evaluate if there is more than one existing node; determine if the user input is smaller than the first node
// add method to evaluate if there is more than one existing node and determine if the user input is bigger than the first node and go through the array until finding the right spot (bigger than the previous, smaller than the next)
// add method to see if reached the end of the list and to put the node into the very last of the list.

#include "bag.h"
#include <string>
#include <iostream>
#include <cstdio>
#include "midterm2.h"
using namespace std;

// points to a node in the list of nodes
BagList::BagList ()
{
    ListPointer = NULL;
}

// put in node
bool BagList::putANode (string udata)
{
    // have x equal to false
    bool x = false;

    // if there were no nodes!
    if(nodecount == 0)
    {
        // node pointer temp1
        Node* temp1;
        // declare node A
        Node A;

        // make new node and increase the number of nodes by 1
        temp1 = A.putNode (ListPointer, udata);
        if (temp1 != NULL)
        {
            ListPointer = temp1;
            nodecount++;
            x = true;
        }
        
        //cout << A.getNodeData();
    }
    // if there was one node
    else if(nodecount == 1)
    {
        // cout << "currently the number of nodes are: " << nodecount << "\n";
        
        // if user input is smaller than the first node
        if(udata < ListPointer -> getNodeData())
        {
            // node pointer temp1
            Node* temp1;
            // declare node A
            Node A;
            
            // make new node and increase the number of nodes by 1
            temp1 = A.putNode(ListPointer, udata);
            if(temp1 != NULL)
            {
                ListPointer = temp1;
                nodecount++;
                x = true;
            }
        }
        // if the user input is bigger than the first node
        else
        {
            // node pointer temp1
            Node* temp1;
            // declare node A
            Node A;
            
            // make another node to input into the right of the original
            temp1 = A.putNode(NULL, udata);
            
            // tie the two nodes together
            if(temp1 != NULL)
            {
                ListPointer->putNextPointer(temp1);
                nodecount++;
                x = true;
            }
        }
    }
    // if there is more than one node
    else
    {
        Node* iterator;
        iterator = ListPointer;
        
        //if it is smaller than the first node data
        if(udata < iterator->getNodeData())
        {
            // node pointer temp1
            Node* temp1;
            Node A;
            
            // make node to put into the left side of the first node
            temp1 = A.putNode(ListPointer, udata);
            if(temp1 != NULL)
            {
                ListPointer = temp1;
                nodecount++;
                x = true;
            }
        }
        // if the input is bigger than the first node data
        else
        {
            // while the user input is bigger than the second one in the list and onwards
            // and have not reached the end node, move iterator through the list
            while(udata > iterator->getNextPointer()->getNodeData()
                  && iterator->getNextPointer() != NULL)
            {
                // have iterator iterate through the list
                iterator = iterator->getNextPointer();
                
                // if you have reached the final node
                if(iterator -> getNextPointer() == NULL)
                {
                    // node pointer temp1
                    Node* temp1;
                    Node A;
                    
                    // intput another node to the right of the final node
                    temp1 = A.putNode(NULL, udata);
                    if(temp1 != NULL)
                    {
                        iterator->putNextPointer(temp1);
                        nodecount++;
                        x = true;
                    }
                }
            }
            
            // if iterator is smaller than the second one
            if(udata < iterator->getNextPointer()->getNodeData())
            {
                // node pointer temp1
                Node* temp1;
                Node A;
                
                // input another node to the right of the first node
                temp1 = A.putNode(iterator->getNextPointer(), udata);
                if(temp1 != NULL)
                {
                    iterator->putNextPointer(temp1);
                    nodecount++;
                    x = true;
                }
            }
            
        }
    }
    
    return x;
}

void BagList::getList()
{ // return value should be a string of concatenated variables
    Node* temp;
    for (temp = ListPointer; temp != NULL;
         temp = temp->getNextPointer())
        cout << " User Data " << temp->getNodeData () << endl;
}

Node* BagList::findNode (string udata)
{
    Node* temp;
    for (temp = ListPointer; temp != NULL && temp->getNodeData () != udata;
		       temp = temp->getNextPointer());
    return temp;
}

void BagList::deleteNode (string udata)
{  // suggested by Yelena Oulenova
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
