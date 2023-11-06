#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

void insert(Node* &head, int d){
    Node* newNode=new Node();
    newNode->data=d;
    newNode->next=NULL;
    
    if(head==NULL){
        head=newNode;
        return;
    }
    
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void Helper(vector<int>& v,int s,int e){
    while(s<e){
        swap(v[s],v[e]);
        s++;
        e--;
    }
}

void Reversing(Node* &head,int arr[],int n,int m){
    vector<int> v;
    Node* temp=head;
    
    while(temp!=NULL){
        v.push_back(temp->data);
        temp=temp->next;
    }

    int cnt=n,start=0;
    for(int i=0;i<m;i++){
        if(arr[i]<=cnt){
            Helper(v,start,start+arr[i]-1);
            cnt-=arr[i];
            start+=arr[i];
        }
    }

    temp=head;
    for(int i=0;i<n;i++){
        temp->data=v[i];
        temp=temp->next;
    }
}

void print(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp=temp->next;
    }
}

int main(){
    int n,data,m;
    Node* head=NULL;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> data;
        if(data>=1 && data<=105){
            insert(head,data);
        }
    }

    cin >> m;
    int arr[m];
    for(int i=0;i<m;i++){
        cin >> arr[i];
    }

    Reversing(head,arr,n,m);
    print(head);
}