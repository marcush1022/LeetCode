/*
Given an integer n, count the total number of digit 1 appearing in all non-negative 
integers less than or equal to n.

For example:
Given n = 13,
Return 6, because digit 1 occurred in the following numbers: 1, 10, 11, 12, 13.

对这个数字的每一位求存在1的数字的个数。从个位开始到最高位。

举个例子54215，比如现在求百位上的1，54215的百位上是2。可以看到xx100到xx199的百位上都是1，
这里xx从0到54，即100->199, 1100->1199...54100->54199, 这些数的百位都是1，因此百位上的1总数
是55*100。

如果n是54125,这时由于它的百位是1，先看xx100到xx199，其中xx是0到53，即54*100, 然后看54100到
54125，这是26个。所以百位上的1的总数是54*100 + 26.

如果n是54025，那么只需要看xx100到xx199中百位上的1，这里xx从0到53，总数为54*100

求其他位的1的个数的方法是一样的。

以算百位上1为例子:   假设百位上是0, 1, 和 >=2 三种情况: 
    case 1: n=3141092, a= 31410, b=92. 计算百位上1的个数应该为 3141 *100 次.
    case 2: n=3141192, a= 31411, b=92. 计算百位上1的个数应该为 3141 *100 + (92+1) 次. 
    case 3: n=3141592, a= 31415, b=92. 计算百位上1的个数应该为 (3141+1) *100 次. 

*/

class Solution {
public:
    int countDigitOne(int n) {
        long factor=1;
        long cdigit=0, highN=0, lowN=0;
        int count=0;
        while(n/factor>0)
        {
            cdigit=(n%(factor*10))/factor;
            highN=n/(factor*10);
            if(cdigit==1)
                count+=highN*factor+lowN+1;
            if(cdigit==0)
                count+=highN*factor;
            if(cdigit>1)
                count+=(highN+1)*factor;
            lowN=n%(factor*10);
            factor*=10;
        }
        return count;
    }
};
