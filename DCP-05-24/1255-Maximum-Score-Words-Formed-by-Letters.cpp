class Solution {
 public:
  int maxScoreWords(vector<string>& words, vector<char>& letters,
                    vector<int>& score) {
    vector<int> letterCount(26);
    for (const char letter : letters)
      ++letterCount[letter - 'a'];
    return calculateMaxScore(words, 0, letterCount, score);
  }

 private:
  int calculateMaxScore(const vector<string>& words, int startIndex, vector<int>& letterCount,
                        const vector<int>& score) {
    int maxScore = 0;
    for (int i = startIndex; i < words.size(); ++i) {
      int wordScore = attemptUseWord(words, i, letterCount, score);
      if (wordScore > 0)
        maxScore = max(maxScore, wordScore + calculateMaxScore(words, i + 1, letterCount, score));
      revertWordUse(words, i, letterCount);
    }
    return maxScore;
  }

  int attemptUseWord(const vector<string>& words, int index, vector<int>& letterCount,
                     const vector<int>& score) {
    bool canUseWord = true;
    int totalScore = 0;
    for (const char letter : words[index]) {
      if (--letterCount[letter - 'a'] < 0)
        canUseWord = false;
      totalScore += score[letter - 'a'];
    }
    return canUseWord ? totalScore : -1;
  }

  void revertWordUse(const vector<string>& words, int index, vector<int>& letterCount) {
    for (const char letter : words[index])
      ++letterCount[letter - 'a'];
  }
};
