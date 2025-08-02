
class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> firstSeenIdx;
        int prefix = 0, maxLen = 0;

        for (int i = 0; i < arr.size(); ++i) {
            prefix += (arr[i] > k) ? 1 : -1;

            if (prefix > 0) {
                maxLen = i + 1;
            } else if (firstSeenIdx.count(prefix - 1)) {
                maxLen = max(maxLen, i - firstSeenIdx[prefix - 1]);
            }

            if (!firstSeenIdx.count(prefix)) {
                firstSeenIdx[prefix] = i;
            }
        }
        return maxLen;
    }
};