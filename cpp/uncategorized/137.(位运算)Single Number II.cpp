/*
Given an array of integers, every element appears three times except for one,
which appears exactly once. Find that single one.

解法：位操作。不管非孤异元素重复多少次，这是通用做法。

对于右数第i位，如果孤异元素该位为0，则该位为1的元素总数为3的整数倍。

如果孤异元素该位为1，则该位为1的元素总数不为3的整数倍（也就是余1）。

换句话说，如果第i位为1的元素总数不为3的整数倍，则孤异数的第i位为1，否则为0.

（如果非孤异元素重复n次，则判断是否为n的整数倍）
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask=1, ret=0, count1=0;
        int len=nums.size();
        while(mask)
        {
            count1=0;
            for(int i=0; i<len; i++)
            {
                if(nums[i]&mask)
                    count1++;
            }
            if(count1%3==1)
                ret|=mask;
            mask<<=1;
        }
        return ret;
    }
};
