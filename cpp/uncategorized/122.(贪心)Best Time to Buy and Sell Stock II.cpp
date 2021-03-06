/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions 
as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must 
sell the stock before you buy again).

Note: 刚开始以为一天只能交易一次，没想到同一天你可以先卖出再买入。
这样就很容易了，贪心就行了，考虑 [1, 2, 3]，你可以 [-1, +2-2, +3]，跟 [-1, +3] 是一样的，
也就是说只要比前一天多，你就可以在前一天买入，接下去一天卖出，这样稳赚不赔
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro=0;
        for(int i=1; i<prices.size(); i++)
        {
            if(prices[i]>prices[i-1])
                maxPro+=prices[i]-prices[i-1];
        }
        return maxPro;
    }
};
