//
//  midterm2.h
//  midterm2
//
//  Created by Jae Won Hyun on 10/23/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//
// edit history:
// fixed variable name from "st" to "data" to make the name less confusing

#ifndef midterm2_h
#define midterm2_h
#include <string>
using namespace std;

class Node
{
public:
    Node () {}
    Node* putNode (Node*, string);
    string getNodeData ();
    Node* getNextPointer ();
    void putNextPointer (Node*);
private:
    // fixed variable from st to data to make the name less confusing
    string data;
    Node* nextPtr;
};

#endif /* midterm2_h */
