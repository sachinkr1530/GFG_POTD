class Solution {
public:
    string longestString(vector<string>& words) {
        sort(words.begin(), words.end());
        unordered_set<string> st;
        string res = "";
        for (string& w : words) {
            if (w.length() == 1 || st.count(w.substr(0, w.length() - 1))) {
                st.insert(w);
                if (w.length() > res.length()) res = w;
            }
        }
        return res;
    }
};