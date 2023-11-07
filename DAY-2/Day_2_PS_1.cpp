#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,S,Q;
    cin >> N >> S >> Q;
    vector<stack<int>> s(N);

    while(Q--){
        int P;
        cin >> P;

        if(P==1){
            int X,M;
            cin >> X >> M;
            if(M>=1 && M<= N){
                s[M-1].push(X);
                cout << "True" << endl;
            } 
            else{
                cout << "False" << endl;
            }
        } 
        else if(P==2){
            int M;
            cin >> M;
            if(M>=1 && M<=N && !s[M-1].empty()){
                int ele=s[M-1].top();
                s[M-1].pop();
                cout << ele << endl;
            } 
            else{
                cout << -1 << endl; 
            }
        }
    }
}
