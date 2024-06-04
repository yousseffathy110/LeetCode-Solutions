#include <vector>
#include <string>
using namespace std;

class Solution {
public:
  int longestPalindrome(string s) {
    vector<int> count(128, 0);
    int ans = 0;
    bool hasOddCount = false;
    for (const char c : s) ++count[c];
    for (const int freq : count) {
      if (freq % 2 == 0) ans += freq;
      else { ans += freq - 1; hasOddCount = true; }
    }
    return ans + hasOddCount;
  }
};
