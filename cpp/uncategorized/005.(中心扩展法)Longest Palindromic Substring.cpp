/***********************************************************************************************/
Given a string s, find the longest palindromic substring in s. You may assume that the maximum 
length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"

Note: 采用中心扩展法，每个字符都有可能是回文字符串的中点。依次求得各字符作为中心的回文字符串，取其中最长
的那个即可。

注意到回文字符串分为奇、偶两种类型对应“aba”和“aa”，所以每个字符都要求两次回文字符。
/***********************************************************************************************/

class Solution {
public:
	string getLongest(string str, int left, int right)
	{
		int len=str.length();
		while(left>=0 && right<len && str[left]==str[right])
		{
			left--;
			right++;
		}
		return str.substr(left+1, right-left-1);
	}
	
    string longestPalindrome(string s) {
		int len=s.length();
		if(len==0 || len==1)
			return s;
        string longest=s.substr(0, 1);
		string tmp;
		for(int i=0; i<len; i++)
		{
			tmp= getLongest(s, i, i);
			if(tmp.length()>longest.length())
				longest=tmp;
			tmp= getLongest(s, i, i+1);
			if(tmp.length()>longest.length())
				longest=tmp;
		}
		return longest;
    }
};


Update:
class Solution {
public:
    string getLongest(string str, int left, int right)
    {
        while(left>=0 && right<str.length() && str[left]==str[right])
        {
            left--;
            right++;
        }
        return str.substr(left+1, right-left-1);
    }
    
    string longestPalindrome(string s) {
        int len=s.length();
        string longest=s.substr(0,1);
        string tmpStr="";
        for(int i=0; i<len; i++)
        {
            tmpStr=getLongest(s, i, i);
            if(tmpStr.length()>longest.length())
                longest=tmpStr;
            tmpStr=getLongest(s, i, i+1);
            if(tmpStr.length()>longest.length())
                longest=tmpStr;
        }
        return longest;
    }
};
