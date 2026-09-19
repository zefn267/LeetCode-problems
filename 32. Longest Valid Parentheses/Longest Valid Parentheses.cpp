class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st ({-1});
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            }
            else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                }
                else {
                    result = max(result, i - st.top());
                }
            }
        }

        return result;
    }
};