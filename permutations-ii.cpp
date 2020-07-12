1.手写法
class Solution {
   vector<vector<int>> ans;

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        perm(nums,0,nums.size()-1);
        return ans;

    }
    
    void perm(vector<int> nums, int left, int right) {
        if(left==right)
        ans.push_back(nums);
        else{
            for(int i=left;i<=right;i++)
            {
                if(i!=left && nums[left] == nums[i]) continue;//  去重
                swap(nums[left],nums[i]);
                perm(nums,left+1,right);
            }
        }
    }
};

int main()
{
    Solution so;
    vector<int> ques = {1,1,2};
    vector<vector<int>> a;
    a = so.permuteUnique(ques);
    for(int i = 0; i<a.size();i++)
    {
        for(int j=0;j<a[0].size();j++)
        {
            cout << a[i][j] << " " ;
            
        }
    cout << endl;
    }
    
    system("pause");
    return 0;
}
2.库函数法--next_permutation()--全排列
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        result.push_back(nums);
        while(next_permutation(nums.begin(), nums.end())) {
            result.push_back(nums);
        }
        return result;
    }
};
