class Solution {
 public:
  bool judgeSquareSum(int c) {
    if (c < 0) return false;
    unsigned long l = 0;
    unsigned long r = static_cast<unsigned long>(sqrt(c));
    while (l <= r) {
      unsigned long sum = l * l + r * r;
      if (sum == c) return true;
      else if (sum < c) ++l;
      else --r;
    }
    return false;
  }
};
