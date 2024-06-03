class Solution {
public:
  int appendCharacters(string s, string t) {
    int i = 0;
    for (const char c : s)
      if (c == t[i] && ++i == t.length()) return 0;
    return t.length() - i;
  }
};
