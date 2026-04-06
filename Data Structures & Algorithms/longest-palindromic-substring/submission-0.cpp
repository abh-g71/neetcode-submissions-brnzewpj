class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0;
        int l = 1;

        auto expand = [&](int left , int right){
            while(left >= 0 && right < n && s[left]==s[right]){
                if(right-left+1 > l){
                     start = left;
                    l = right-left+1;
                }
                left--;
                right++;
            }
        };
        for(int i = 0 ; i < n ; i++){
                expand(i,i);
                expand(i,i+1);
            }
        return s.substr(start,l);
    }
};
