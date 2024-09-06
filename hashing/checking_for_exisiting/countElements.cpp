#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

/*
find the longest prefix with mostly 2 distinct k
we use sliding window to get the longest subarray
*/
int countLongestPrefx(string s,int k){

    int left = 0,ans=0;
    unordered_map<char, int> counts;

    for (int right = 0; right < s.length(); right++){
        counts[s[right]]++;
        while(counts.size()>k){
            counts[s[left]]--;
            if( counts[s[left]] ==0){
                counts.erase(s[left]);
            }
            left++;
        }
        cout <<s[right]<< ": "<< right << " - " <<s[left] << ": " << left << " + "
             << " = " << right - left + 1 << endl;
        ans = max(ans, right - left + 1);
    }

    return ans;
}


int countElements(vector<int>& arr) {
        
        std::unordered_set<int>countArr;
        
        int count=0;
        
        for(int i: arr){
            if(countArr.find(i) == countArr.end()){
                cout<<i<<endl;
                countArr.insert(i);
            }
        }
        // for(auto it= countArr.begin(); it!= countArr.end(); ++it){
        //     cout<<*it<<endl;
        // }
        
        for(int i=0; i<arr.size(); i++){
            if(countArr.find(arr[i]+1) != countArr.end()){
                //cout<<arr[i]+1<<endl;
                count++;
            }
           
        }
        
       
        
        return count;
        
        
    }
/*
calc the prefix sum
get the difference between prefix sum [i] - k
check if the difference is in the map
if its then increase count
other wise add the current prefix to the map
*/
//exact sum equal to k
      int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int>counts;
        vector<int>prefixSum(nums.size() + 1, 0);
        
        for(int i=1; i<=nums.size(); i++){
            prefixSum[i] = nums[i-1] + prefixSum[i-1];
        }
        
        int ans=0;

        for(int i=0; i<prefixSum.size(); i++){
            int diff = prefixSum[i]-k;
            if(counts.find(diff) != counts.end()){
               ans ++;
            }
            else{
                counts[ prefixSum[i]]++;
                
            }
        }
            
         return ans;
   
    }

    int main(){
        string s = "ecebaaaakaa";

        //cout << countLongestPrefx(s,n 2)<<endl;
        vector<int> nums = { 1, 2,3 };
        int k = 3;
        cout << subarraySum(nums, k)<<endl;
        return 0;
    }
    