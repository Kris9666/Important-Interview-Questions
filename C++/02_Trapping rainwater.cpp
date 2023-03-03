// Trapping Rainwater 
// Given non-negative integers representing an elevation map where the width of each bar is 1, Compute
// How much water it can trap after raining.
// Input = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output = 6


#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int rain_water(vector<int> a){
    stack<int> st;
    int n = a.size(), ans=0;
    for (int i=0; i<n; i++){
        while(!st.empty() && a[st.top()]<a[i]){
            int curr = st.top();
            st.pop();
            if(st.empty()){
                break;
            }
            int diff = i-st.top()-1;
            ans+=(min(a[st.top()],a[i]) - a[curr])*diff;
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> a = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a)<<endl;
    return 0;
}