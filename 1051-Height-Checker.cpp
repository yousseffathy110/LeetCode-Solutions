#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
  int heightChecker(vector<int>& heights) {
    vector<int> sortedHeights = heights;
    sort(sortedHeights.begin(), sortedHeights.end());
    int ans = 0;
    for (int i = 0; i < heights.size(); ++i) 
        if (heights[i] != sortedHeights[i]) ++ans;
    return ans;
  }
};
