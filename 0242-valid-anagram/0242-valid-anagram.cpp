class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map< char , int> mpp ;
        unordered_map<char , int> mpq;
        if(s.size() != t.size()) return false;

        for(int i = 0 ; i<s.size() ; i++)
        {
          mpp[s[i]]+=1;
          mpq[t[i]]+=1;
                 }
                 for(auto it : mpp)
                 {
                    if(it.second != mpq[it.first]) return false;
                 }
                 return true ;
    }
};