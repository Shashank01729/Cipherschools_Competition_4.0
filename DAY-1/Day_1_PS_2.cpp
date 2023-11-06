#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* prev;
};

void insert(Node* &head,Node* &tail,int d){
    Node* newNode=new Node();
    newNode->data=d;
    newNode->next=NULL;
    newNode->prev=tail;

    if(head==NULL){
        head=tail=newNode;
        return;
    }
    tail->next=newNode;
    tail=newNode;
}

Node* partition(Node* l,Node* h){
    int pivot=h->data;
    Node* n=l->prev;

    for(Node* j=l;j!=h;j=j->next){
        if(j->data<=pivot){
            if(n==NULL){
                n=l;
            } 
            else{
                n=n->next;
            }
            swap(n->data,j->data);
        }
    }

    if(n==NULL){
        n=l;
    } 
    else{
        n=n->next;
    }
    swap(n->data,h->data);
    return n;
}

void QS(Node* l, Node* h){
    if(h!=NULL && l!=h && l!=h->next){
        Node* pivot=partition(l,h);
        QS(l,pivot->prev);
        QS(pivot->next,h);
    }
}

void Sort_DLL(Node* &head, Node* &tail) {
    if(head==NULL || head==tail){
        return;
    }QS(head,tail);
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main(){
    int test_cases;
    cin >> test_cases;
    while(test_cases--){
        int n,data;
        Node* head=NULL;
        Node* tail=NULL;
        cin >> n;

        for(int i=0;i<n;i++){
            cin >> data;
            insert(head, tail, data);
        }
        Sort_DLL(head, tail);
        print(head);
    }
}
