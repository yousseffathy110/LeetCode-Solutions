#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (nums[0] >= n)
      return n;
    for (int i = 1; i < n; ++i) {
      int greaterOrEqualCount = n - i;
      if (nums[i - 1] < greaterOrEqualCount && nums[i] >= greaterOrEqualCount)
        return greaterOrEqualCount;
    }
    return -1;
  }
};
