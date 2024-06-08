class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int cumulativeSum = 0;
        unordered_map<int, int> sumIndexMap{{0, -1}};
        for (int index = 0; index < nums.size(); ++index) {
            cumulativeSum += nums[index];
            if (k) cumulativeSum %= k;
            auto it = sumIndexMap.find(cumulativeSum);
            if (it != sumIndexMap.cend()) {
                if (index - it->second > 1) return true;
            } else sumIndexMap[cumulativeSum] = index;
        }
        return false;
    }
};
