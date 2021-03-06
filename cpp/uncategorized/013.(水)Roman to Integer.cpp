/***************************************************************************************/
Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
/***************************************************************************************/

class Solution {
public:
    	int romanToInt(string s) {
        	int sz=0;
		int p[200]={0};
		p['I']=1,p['V']=5,p['X']=10,p['L']=50,p['C']=100,p['D']=500,p['M']=1000;
		int sum=0;
		sz=s.length();
		for(int i=0;i<sz;i++)
		{
			if(p[s[i+1]]>p[s[i]])
				sum-=p[s[i]];
			else
				sum+=p[s[i]];
		}
		return sum;
    }
};
