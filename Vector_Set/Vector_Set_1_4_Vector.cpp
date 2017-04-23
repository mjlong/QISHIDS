class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp; //local array composed of candidates under check
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, result, temp);
        return result;
    }
    
    void dfs(vector<int>& candidates, int spt, int sum, int target, vector<vector<int>>& result, vector<int>& temp){
      //spt: starting point
      //sum: sum of the local array: temp
        if(sum == target) {
	    //temp is complete
            result.push_back(temp);
            return;
        }
        
        for(int i = spt; i < candidates.size(); i++){
            if(sum + candidates[i] > target) return;
	    //impossible to reach target since all candidates are non-negative
            if(candidates[i]==candidates[i-1]&&i>spt) continue; // check duplicate combination
            temp.push_back(candidates[i]);
            dfs(candidates, i+1, sum + candidates[i], target, result, temp);
            temp.pop_back(); //candidates[i] considered
        }
        return;
    }
};
