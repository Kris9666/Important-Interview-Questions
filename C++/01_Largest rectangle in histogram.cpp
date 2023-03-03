// largest rectangle in a histogram 
// Given an array. Each element represents the height to the histogram's bar and the width of
// each bar is 1, find the area of largest rectangle in the histogram.
// Input = arr[2,1,5,6,2,3]
// Output = Height=5 & width=2 i.e. area  = 2*5 = 10

#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int get_max_area(vector<int> a){
    int ans = 0, i=0;
    stack<int> st;
    a.push_back(0);
    int n = a.size();
    while(i<n){
        while(!st.empty() && a[st.top()]>a[i]){
            int t=st.top();
            int h=a[t];
            st.pop();
            if (st.empty()){
                ans = max(ans,h*i);
            }
            else {
                int len = i-st.top()-1;
                ans = max(ans,h*len);
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}
int main(){
    // vector<int> a = {2,1,5,6,2,3};
    vector<int> a = {2,4};
    cout<<get_max_area(a);
    return 0;
}