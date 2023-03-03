// Maximum Consecutive Ones 
// Given the array A of 0s and 1s, we may change upto K values from 0 to 1.
// Return the length of the longest (contigous) subarray that contains only 1s.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for (auto &i:a){
        cin>>i;
    }
    int zerocnt = 0;
    int i=0, ans=0;
    for (int j=0; j<n; j++){
        if (a[j]==0){
            zerocnt++;
        }
        while(zerocnt>k){
            if(a[i]==0){
                zerocnt--;
            }
            i++;
        }
        ans = max(ans,j-i+1);
    }
    cout<<ans<<endl;
    return 0;
}