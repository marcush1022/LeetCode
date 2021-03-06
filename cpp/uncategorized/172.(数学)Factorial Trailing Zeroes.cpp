/*
Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

对n!做质因数分解n!=2x*3y*5z*...
显然0的个数等于2*5的个数即min(x,z)，并且min(x,z)=z (归纳法证明)

即：求不大于N的数中因子5、25、...的数量
公式: Z = N/5 + N /(5 * 5) + N/( 5 * 5 * 5).....直到N/(5的K次方)等于0
公式中N/5表示不大于N的数中能被5整除的数贡献一个5，N/(5 * 5)表示不大于N的数中能被25整除的数再共享
一个5
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n)
        {
            count+=n/5;
            n=n/5;
        }
        return count;
    }
};
