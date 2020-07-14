class Solution{
private:
    //计算两个单词之间的距离
    int wordDist(const string& w1, const string &w2){
        int cnt = 0;
        for (int i = 0; i < w1.size(); i++){
            if (w1[i] != w2[i]) cnt++;
        }
        return cnt;
    }
    //寻找当前单词的所有邻接单词
    vector<string> findAdj(string& target, vector<string>& wordList){
        vector<string> res;
        for (const auto& word : wordList){
            if(wordDist(target, word) == 1){
                res.push_back(word);
            }
        }
        return res;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList){
        //双向BFS,需要两个队列
        deque<string> de;
        deque<string> nde;
        //记录访问过的节点
        unordered_set<string> visited;

        //加入第一个节点
        de.push_back(beginWord);
        visited.insert(beginWord);

        int cnt = 0;
        while( ! de.empty () || ! nde.empty() ){
            if (de.empty()){
                swap(de, nde);
                cnt++;
            }
            //出队，获取当前word
            auto str = de.front();
            de.pop_front();
            //找到当前单词的所有临近词
            for (auto e : findAdj(str, wordList)){
                if ( e == endWord) return cnt + 2; //临近词就是结束
                if (visited.find(e) == visited.end() ){ //没有访问
                    visited.insert(e);
                    nde.push_back(e);
                }
            }
        }
        return 0;
        
    }
};
