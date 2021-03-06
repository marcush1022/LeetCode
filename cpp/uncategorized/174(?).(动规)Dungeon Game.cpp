/*
The demons had captured the princess (P) and imprisoned her in the bottom-right 
corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. 
Our valiant knight (K) was initially positioned in the top-left room and must 
fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at 
any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative 
integers) upon entering these rooms; other rooms are either empty (0's) or 
contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to 
move only rightward or downward in each step.


Write a function to determine the knight's minimum initial health so that he 
is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must 
be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN

Dungeon: 
[-2 -3 3] 
[-5 -10 1]
[10 30 -5]

MinHp: 
[7 5 2]
[6 11 5]
[1 1 6]

从右下角位置开始倒推，每个位置需要同时满足两个条件：（1）该位置HP为1(保证不死)，
（2）该位置的HP足够到达公主(使用动态规划)
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows=dungeon.size(), cols=dungeon[0].size();
        if(rows==0 || cols==0)
            return 0;
        vector<vector<int>> minHp(rows, vector<int>(cols, 0));
        int i, j;
        for(i=rows-1; i>=0; i--)
        {
            for(j=cols-1; j>=0; j--)
            {
                if(i==rows-1 && j==cols-1)
                    minHp[i][j]=max(1, 1-dungeon[i][j]);
                else if(i==rows-1)
                    minHp[i][j]=max(1, minHp[i][j+1]-dungeon[i][j]);
                else if(j==cols-1)
                    minHp[i][j]=max(1, minHp[i+1][j]-dungeon[i][j]);
                else
                    minHp[i][j]=max(1, min(minHp[i+1][j]-dungeon[i][j], minHp[i][j+1]-dungeon[i][j]));
            }
        }
        return minHp[0][0];
    }
};
