class Solution {
public:
    bool valid(string s) {
        if (s.size() > 3 || s.empty())
            return false;

        if (s[0] == '0' && s.size() > 1)
            return false;

        int n = stoi(s);

        if (n > 255)
            return false;

        return true;
    }

    void f(vector<string>& res, string s, string str,
           int idx, int n, int dot) {

        if (dot == 3) {
            string last = s.substr(idx);

            if (valid(last)) {
                res.push_back(str + last);
            }
            return;
        }

        for (int i = 0; i < 3; i++) {

            if (idx + i >= s.size())
                break;

            string p = s.substr(idx, i + 1);

            if (!valid(p))
                continue;

            f(res, s, str + p + '.', idx + i + 1, n, dot + 1);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        f(res, s, "", 0, s.size(), 0);
        return res;
    }
    
};