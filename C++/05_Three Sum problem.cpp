// Three Sum Problem
// Two Pointer Technique
// Given an array and a value, find if there exists three numbers whose sum is equal to the given value.
// Input = n=6, target=24 and arr[12,3,7,1,6,9]
// Output = True


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;
    cin>>n;
    int target;
    cin>>target;
    vector<int> arr(n);
    for (auto &i:arr){
        cin>>i;
    }
    bool found = false;\
    sort(arr.begin(), arr.end());
    for (int i=0; i<n; i++){
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int current = arr[i]+arr[lo]+arr[hi];
            if (current==target){
                found=true;
            }
            if (current<target){
                lo++;
            }
            else {
                hi--;
            }
        }
    }
    if (found){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
    return 0;
}