#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    int freq;
    Node* left;
    Node* right;
};

Node* createNode(int data,int freq){
    Node* newNode=new Node;
    newNode->data=data;
    newNode->freq=freq;
    newNode->left=newNode->right=NULL;
    return newNode;
}

Node* insert(Node* root,int data,int freq){
    if(root==NULL){
        return createNode(data,freq);
    }

    if(data<root->data){
        root->left=insert(root->left,data,freq);
    } 
    else if(data>root->data){
        root->right=insert(root->right,data,freq);
    }
    return root;
}

int OptimalCost(Node* root,vector<int>& keys,vector<int>& freq,int n){
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=freq[i];
    }

    for(int i=1;i<=n-1;i++){
        for(int j=0;j<=n-1;j++){
            if(i+j<=n-1){
                int k=i+j;
                int maxi=INT_MAX;
                for(int r=j;r<=k;r++){
                    int part1=0,part2=0;
                    if(r-1>=j){
                        part1=dp[j][r-1];
                    }
                    if(r+1<=k){
                        part2=dp[r+1][k];
                    }
                    maxi=min(maxi,part1+part2);
                    dp[j][k]+=dp[r][r];
                }
                dp[j][k]+=maxi;
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    int Test_cases;
    cin >> Test_cases;

    while(Test_cases--){
        int n,ele;
        cin >> n;
        Node* root=NULL;
        vector<int> key,freq;

        for(int i=0;i<n;i++){
            cin >> ele;
            key.push_back(ele);
        }

        for(int i=0;i<n;i++){
            cin >> ele;
            freq.push_back(ele);
        }

        for(int i=0;i<n;i++){
            root=insert(root,key[i],freq[i]);
        }
        cout << OptimalCost(root,key,freq,n) << endl;
    }  
}
