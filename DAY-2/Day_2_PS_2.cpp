#include<bits/stdc++.h>
using namespace std;

void Largest_Rectangle(vector<int>& v,int n){
    int ans=0;
    for(int i=0;i<n;i++){
        int h=v[i],b=1;
        for(int j=i+1;j<n;j++){
            if(v[j]>=h){
                b++;
            }
            else{
                break;
            }
        }

        for(int j=i-1;j>=0;j--){
            if(v[j]>=h){
                b++;
            } 
            else{
                break;
            } 
        }
        ans=max(ans,h*b);
    } 
    cout << ans << endl;
}

int main(){
    int test_cases,n;
    cin >> test_cases;
    while(test_cases--){
        vector<int> v;
        cin >> n;
        for(int i=0;i<n;i++){
            int ele;
            cin >> ele;
            v.push_back(ele);
        }
        Largest_Rectangle(v,n);
    }
}