class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xors = 0;
        for (int num : nums)
            xors ^= num;
        unsigned int lowbit = xors & -static_cast<unsigned int>(xors);
        vector<int> ans(2);
        for (int num : nums)
            if (num & lowbit)
                ans[0] ^= num;
            else
                ans[1] ^= num;
        return ans;
    }
};
