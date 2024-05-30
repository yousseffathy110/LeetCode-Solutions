#include <vector>
using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefixXor(n + 1, 0);
        for (int i = 0; i < n; ++i)
            prefixXor[i + 1] = prefixXor[i] ^ arr[i];
        int count = 0;
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i)
                if (prefixXor[i] == prefixXor[j + 1])
                    count += j - i;
        }
        return count;
    }
};
