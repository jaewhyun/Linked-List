//
//  midterm2.cpp
//  midterm2
//
//  Created by Jae Won Hyun on 10/23/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

#include <stdio.h>
#include "midterm2.h"

// return next pointer
Node* Node::getNextPointer ()
{
    return nextPtr;
}

// set next pointer
// have "this" pointer point to whatever nextPtr is pointing to and equal to x
void Node::putNextPointer (Node* x)
{
    this->nextPtr = x;
}

// make a new node
Node* Node::putNode (Node* x, string s)
{
    Node* temp = NULL;
    if ((temp = new Node()))
    {
        // (*temp).nextPtr = x;
        temp->nextPtr = x;
        // (*temp).st = s;
        temp->data = s;
    }
    return temp;
}

// return whatever is in the node
string Node::getNodeData()
{
    return data;
}
