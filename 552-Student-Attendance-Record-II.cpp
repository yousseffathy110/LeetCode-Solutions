class Solution {
 public:
  int checkRecord(int n) {
    constexpr int kMod = 1'000'000'007;
    vector<vector<long>> countSequences(2, vector<long>(3, 0));
    countSequences[0][0] = 1;
    for (int day = 0; day < n; ++day) {
      vector<vector<long>> newCountSequences(2, vector<long>(3, 0));
      for (int absentCount = 0; absentCount < 2; ++absentCount) {
        for (int lateCount = 0; lateCount < 3; ++lateCount) {
          newCountSequences[absentCount][0] = (newCountSequences[absentCount][0] + countSequences[absentCount][lateCount]) % kMod;
        }
      }
      for (int absentCount = 0; absentCount < 2; ++absentCount) {
        for (int lateCount = 1; lateCount < 3; ++lateCount) {
          newCountSequences[absentCount][lateCount] = (newCountSequences[absentCount][lateCount] + countSequences[absentCount][lateCount - 1]) % kMod;
        }
      }
      for (int lateCount = 0; lateCount < 3; ++lateCount) {
        newCountSequences[1][0] = (newCountSequences[1][0] + countSequences[0][lateCount]) % kMod;
      }
      countSequences = newCountSequences;
    }
    long result = 0;
    for (int absentCount = 0; absentCount < 2; ++absentCount) {
      for (int lateCount = 0; lateCount < 3; ++lateCount) {
        result = (result + countSequences[absentCount][lateCount]) % kMod;
      }
    }
    return result;
  }
};
