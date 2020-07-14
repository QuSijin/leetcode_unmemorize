class Solution {
public:
    //解法1：单向bfs
    int minMutation(string start, string end, vector<string>& bank) {
        //1:判读极端情况
        if(start.empty()||end.empty()||bank.empty())return -1;
        if(find(bank.begin(),bank.end(),end)==bank.end())return -1;//目标基因不在基因库中
        
        //2:bfs的初始化工作
        vector<int> visit(bank.size(),0);
        int step=0;
        queue<string> q;
        q.push(start);
        
        //3:进行bfs
        while(!q.empty()){
            step++;
            int n=q.size();//确定每次bfs的宽度
            for(int i=0;i<n;++i){
                string temp=q.front();//获得队头元素
                q.pop();
                for(int j=0;j<bank.size();++j){//遍历整个基因库,访问未标记的基因；找到某个字符变异的基因添加标记，并进入队列即可
                    if(visit[j]==0){
                        int diff=0;
                        for(int k=0;k<temp.size();++k){
                            if(temp[k]!=bank[j][k]) diff++;
                        }
                        if(diff==1){//找到某个字符编译的基因
                            if(bank[j]==end)    return step;//若该下标j代表的基因为目标基因，则直接返回步长
                            visit[j]=1;//标记下标为j的基因已访问
                            q.push(bank[j]);
                        }
                    }
                }
            }
        }
        return -1;
    }
};
// 出队，当前队列中所有的元素
// 如果当前的字符串变化正好是目标值就返回step的值
// 如果不是就将当前的一个字符进行替换，查看是否在基因库，是否先前访问过
// 判断1：当前的字符串是否被访问过，被访问过说明陷入了循环，不可能变成目标值。
// 判断2：当前的字符串是否在基因库，如果在，就记录这个新的字符串被访问过，并且把这个新字符串加入到队列中
// 把当前层所有的可能性放入到队列中，当前层全记录完后当前的step++
// 进入到下一层，同样的逻辑
