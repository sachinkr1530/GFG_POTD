class Solution {
  public:
    string smallestWindow(string &s, string &p) {
        // code here
        unordered_map<char, int> freq;
        for (char c : p) freq[c]++;
        
        int required = freq.size(), formed = 0;
        unordered_map<char, int> window;
        int left = 0, right = 0, minLen = INT_MAX, start = 0;
        
        while (right < s.size()) {
            char c = s[right];
            window[c]++;
            if (freq.count(c) && window[c] == freq[c]) formed++;
            
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char d = s[left];
                window[d]--;
                if (freq.count(d) && window[d] < freq[d]) formed--;
                left++;
            }
            right++;
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};

