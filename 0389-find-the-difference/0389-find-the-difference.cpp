class Solution {
public:
    char findTheDifference(string s, string t) {
        int xor1=0;
        for(int i=0;i<s.size();i++){
            xor1^=s[i];
        }
        for(int i=0;i<t.size();i++){
            xor1^=t[i];
        }
        return xor1;
    }
};