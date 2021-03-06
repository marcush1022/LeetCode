/*
Given an array of integers, find if the array contains any duplicates. Your function 
should return true if any value appears at least twice in the array, and it should 
return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len=nums.size();
        if(len==0)
            return false;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
        {
            if(!m[nums[i]])
                m[nums[i]]++;
            else
                return true;
        }
        return false;
    }
};
