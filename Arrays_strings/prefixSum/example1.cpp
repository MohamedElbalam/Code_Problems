#include <iostream>
#include <vector>
using namespace std;

/*
    Example 1: Given an integer array nums, an array queries where queries[i] = [x, y] and an integer limit, return a boolean array that represents the answer to each query. A query is true if the sum of the subarray from x to y is less than limit, or false otherwise.

    For example, given nums = [1, 6, 3, 2, 7, 2], queries = [[0, 3], [2, 5], [2, 4]], and limit = 13, the answer is [true, false, true]. For each query, the subarray sums are [12, 14, 12].

*/
//one way of doing it
// vector<bool> prefixSum(vector<int>sum,vector<vector<int>>quieries,int limit){
//     vector<bool> prefix;
//     vector<int> arrSum(sum.size() + 1, 0);
//     for (int i = 1; i < sum.size(); i++){
//         arrSum[i] = arrSum[i - 1] + sum[i-1];
//     }

//     for (int i = 0; i < quieries.size(); i++){
//         int startIndx = quieries[i][0];
//         int endIndx = quieries[i][1];
//         // cout <<"start: "<< startIndx << " ";

//         int sums = arrSum[endIndx] - arrSum[startIndx-1];
//         // cout << "this is sums: " << quieries[i][1]<< " ";
//         prefix.push_back(sums < limit);

//     }


//     return prefix;
// }

//better solution

vector<bool> prefixSum(vector<int>&nums,vector<vector<int>>&quieries,int limit){

    vector<bool>prefix;
    vector<int> sum={nums[0]};
    for (int i = 1; i < nums.size(); i++){
        //sum all elements up to i inclusive
        sum.push_back(sum.back() + nums[i]);

    }
    for(vector<int>& query: quieries){
        int startIndex = query[0];
        int endIndex = query[1];
        int querySum = sum[endIndex] - sum[startIndex - 1];
        prefix.push_back(querySum < limit);
    }

    return prefix;
}

/*
split the array so the sum of the left half is greater than the second half

*/
int waysToSplitArray(vector<int>& nums) {
      int curr=0,rightSum=0, j=0,counter=0;
        
        for(int i=0; i<nums.size(); i++){
            curr+=nums[i];
        
            while(i+j+1<nums.size()){
                rightSum += nums[i+j+1];
                j++;
            }
            j = 0;
            if(curr>rightSum){
                counter++;
            }
            curr = 0;
        }
        return counter;
}

vector<bool> SumPrefixed(vector<int>&nums,vector<vector<int>>&quieries,int limit){
    vector<int> sum = {nums[0]};
    vector<bool> ans;
    
    for (int i = 1; i < nums.size(); i++){
        sum.push_back(sum.back() + nums[i]);
    }
    for (int i = 0; i<nums.size();i++){
        int x = quieries[i][0];
        int y = quieries[i][1];
        int curr = sum[y] - sum[x] + nums[x];
        ans.push_back(curr < limit);
    }
    return ans;
}    
//====================================================
string reversed(string word){
        int i=0,j=word.length()-1;
        string result="";
        while(i<j){
              swap(word[i],word[j]);
        }
        return word;
    }

    string reverseWords(string s) {
        int first=0;
        string result="";
        string temp="";
        for(int last=0; last<s.length(); last++){
            temp += s[last];
            if(s[last]==' '){
               result += reversed(temp) + " ";
               temp ="";
            }
            if(last == s.length()){
                result += reversed(temp);
            }
        }
        return result;
    
    }

     string reverseIndex(string revWord){
        string result="";
        for(int i=revWord.length(); i>=0; i--){
            result += revWord[i];
        }
        return result;
    }
    string reversePrefix(string word, char ch) {
        
        string reverseWord="";
        string result="";
        int i;
        bool found=false;
        for(i=0; i<word.length(); i++){
            reverseWord += word[i];

            if(word[i] == ch){
                cout << reverseWord << endl;
                result = reverseIndex(reverseWord);
                cout << result << endl;
                found = true;
                break;
            }
        }

        if(found==true){
            while (i<word.length()){
                result += word[i+1];
                i++;
            }
        }
        return result;
    }

int main(){
    // vector<int> arr = {1, 6, 3, 2, 7, 2};
    // vector<vector<int>> quieries = {{1, 3}, {2, 5}, {2, 4}};

    // vector<bool> sums = SumPrefixed(arr,quieries , 13);

    // for(bool i: sums){
    //     cout << boolalpha << i<< " ";
    // }
    // cout << endl;
    // //===============================
    // vector<int> arrSplit = {2,3,1,0};
    // cout << waysToSplitArray(arrSplit)<<endl;
    // //===================
    // vector<int> arrOnes = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};

    string word = "abcdefd";
    cout<< "reversed: " << reversePrefix(word,'d')<<endl;
    return 0;
}