//
//  bag.h
//  midterm2
//
//  Created by Jae Won Hyun on 10/23/16.
//  Copyright © 2016 Jae Won Hyun. All rights reserved.
//

// edit file:
// add nodecount private variable to account for the number of nodes

#ifndef bag_h
#define bag_h

#include <cstdlib>
#include "midterm2.h"
using namespace std;
#include <string>

//#include "BagList.h"
class BagList
{  //Container class
public:
    BagList (); // default constructor 
    bool putANode (string);
    void getList ();
    Node* findNode (string);
    void  deleteNode (string);
private:
    Node* ListPointer;
    // add nodecount to account for the number of nodes in the list
    int nodecount = 0;
};


#endif /* bag_h */
