#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node* buildBinaryTree(){
    int data;
    cin >> data;

    if(data==-1){
        return NULL;
    }

    Node* root=new Node(data);
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        int l,r;
        cin >> l;
        if(l!=-1){
            curr->left=new Node(l);
            q.push(curr->left);
        }
        cin >> r;
        if(r!=-1){
            curr->right=new Node(r);
            q.push(curr->right);
        }
    }
    return root;
}

int Burn_Tree(Node* root,int n,int time){
    if (root==NULL){
        return 0;
    }
    if(root->data==n){
        time=0;
        return 1;
    }

    int L_Time=Burn_Tree(root->left,n,time);
    if(L_Time>0){
        time=L_Time;
        time++;
        return L_Time+1;
    }

    int R_Time=Burn_Tree(root->right,n,time);
    if(R_Time>0){
        time=R_Time;
        time++;
        return R_Time+1;
    }
    return time;
}

int Calculate_Time(Node* root,int n){
    int time=0;
    Burn_Tree(root,n,time);
    return time;
}

int main() {
    Node* root=buildBinaryTree();
    int n;
    cin >> n;
    cout << Calculate_Time(root,n) << endl;
}
