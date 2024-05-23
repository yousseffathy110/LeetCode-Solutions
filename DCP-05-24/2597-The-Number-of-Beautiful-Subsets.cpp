class Solution {
 public:
  int beautifulSubsets(vector<int>& nums, int k) {
    constexpr int kMaxNum = 1000;
    vector<int> count(kMaxNum + 1);
    unordered_map<int, set<int>> modToSubset;

    for (const int num : nums) {
      ++count[num];
      modToSubset[num % k].insert(num);
    }

    int prevNum = -k;
    int skipCount = 0;
    int pickCount = 0;

    for (const auto& [_, subset] : modToSubset) {
      for (const int num : subset) {
        const int nonEmptyCount = pow(2, count[num]) - 1;
        const int tempSkipCount = skipCount;
        skipCount += pickCount;
        pickCount = nonEmptyCount * (1 + tempSkipCount + (num - prevNum == k ? 0 : pickCount));
        prevNum = num;
      }
    }

    return skipCount + pickCount;
  }
};
