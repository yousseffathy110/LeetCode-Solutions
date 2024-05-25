class Solution {
 public:
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> wordSet{wordDict.begin(), wordDict.end()};
    unordered_map<string, vector<string>> memo;
    return wordBreakHelper(s, wordSet, memo);
  }

 private:
  vector<string> wordBreakHelper(const string& s,
                                 const unordered_set<string>& wordSet,
                                 unordered_map<string, vector<string>>& memo) {
    if (const auto it = memo.find(s); it != memo.cend())
      return it->second;

    vector<string> results;

    for (int len = 1; len < s.length(); ++len) {
      const string& prefix = s.substr(0, len);
      const string& suffix = s.substr(len);
      if (wordSet.count(prefix))
        for (const string& word : wordBreakHelper(suffix, wordSet, memo))
          results.push_back(prefix + \ \ + word);
    }

    if (wordSet.count(s))
      results.push_back(s);

    return memo[s] = results;
  }
};
