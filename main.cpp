// modify the program so that the user values will be entered into the linked list in ascending order.
// For example, if A and C are entered into the list, a node containing B would be entered between them.
// If B was already entered into the list, the value A would be entered into the list prior to B.
// If A was already entered into the list, B would be entered following A in the list
#include <string>
#include <iostream>
#include "midterm2.h"
#include "bag.h"
using namespace std;


int main ()
{
    BagList A;  // call a bag
    string udata;
    bool cont = true;
    char sel;
    
    while (!cin.eof() && cont == true) {
        cout << "Enter your function: Add, Delete, Exit, Find, List: ";
        cin >> sel;
        
        if (!cin.eof()) {
            switch (sel) {
                case 'A': case 'a':
                {
                    cout << "Enter a character or control-z to end\n";
                    cin >> udata;
                    if (!cin.eof())
                        // from the bag of methods, call how to add a node;
                        cont = A.putANode(udata);
                    break;
                }
                case 'D': case 'd':
                {
                    cout << "Please Enter User Data value to delete: ";
                    cin >> udata;
                    if (!cin.eof())
                        A.deleteNode (udata);
                    break;
                }
                case 'E': case 'e':
                {
                    cont = false;
                    break;
                }
                case 'F': case 'f':
                {
                    cout << "Please Enter User Data value to find: ";
                    cin >> udata;
                    if (!cin.eof())
                    {
                        if (A.findNode(udata))
                        {
                            cout << "Node " << udata << " found" << endl;
                        }
                        else
                        {
                            cout << "Node " << udata << " not found" << endl;
                        }
                    }
                    break;
                }
                case 'L': case 'l':
                {
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
