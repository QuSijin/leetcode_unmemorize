class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()) {
            int len = q.size();
            vector<int> level;
            for (int i = 0; i < len; i ++) {
                TreeNode* t = q.front();
                q.pop();
                level.push_back(t->val);
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
            res.push_back(level);
        }
        return res;
    }
};
// 1.先将根节点存入队列，计算此时队列数据长度，根据相应长度，输出第一行的vector
// 2.判断，若存在左右子树，则压入队列
// 3.再判断压入队列后，队列数据长度，根据相应长度，输出新一行的vector
// 4.以此类推：
