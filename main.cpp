#include <iostream>
#include <typeinfo>
using namespace std;


struct INODE {
    int data;
    INODE *next;
};

class innerLinkedList {
private:
    INODE *head;
public:
    innerLinkedList(){
        head = NULL;
    }

    void push_back(int data){
        INODE *newNode = new INODE();
        newNode->data = data;
        newNode->next = NULL;
        if(head==NULL){
            head = newNode;
        } else {
            INODE *temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print(){
        INODE *temp = head;
        while (temp->next != NULL) {
            cout << temp->data << ",";
            temp = temp->next;
        }
        cout << temp->data;
    }
};



struct ONODE {
    innerLinkedList* nodee;
    ONODE *next;
};

class outerLinkedList {
private:
    ONODE *head;
public:
    outerLinkedList() {
        head = NULL;
    }

    void push_back(innerLinkedList* nodee) {
        ONODE *newNode = new ONODE();
        newNode->nodee = nodee;
        newNode->next = NULL;
        if (head == NULL) {
            head = newNode;
        } else {
            ONODE *temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print(){
        ONODE *temp = head;
        while (temp != NULL) {
            temp->nodee->print();
            cout << "  ";
            temp = temp->next;
        }

    }

};



int main() {

    innerLinkedList innerList1;
    innerLinkedList innerList2;
    innerLinkedList innerList3;
    innerLinkedList innerList4;

    innerList1.push_back(1);
    innerList1.push_back(2);

    innerList2.push_back(4);
    innerList2.push_back(7);
    innerList2.push_back(90);
    innerList2.push_back(54);

    innerList3.push_back(6);
    innerList3.push_back(1);
    innerList3.push_back(99);

    innerList4.push_back(9);
    innerList4.push_back(8);


    outerLinkedList outerList;

    outerList.push_back(&innerList1);
    outerList.push_back(&innerList2);
    outerList.push_back(&innerList3);
    outerList.push_back(&innerList4);

    outerList.print();

}
