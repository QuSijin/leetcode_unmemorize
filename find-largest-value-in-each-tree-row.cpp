//同二叉树的层序遍历，几乎一样的解法--广度遍历
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int len = q.size();
            int levelMax = INT_MIN;
            for(int i = 0; i < len; i++) {
                TreeNode* curNode = q.front();
                q.pop();
                levelMax = max(curNode->val, levelMax);
                if(curNode->left) q.push(curNode->left);
                if(curNode->right) q.push(curNode->right);
            }
            res.push_back(levelMax);
        }
        return res;
    }
};

