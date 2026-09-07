struct PairHash {
    std::size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>{}(p.first) ^
               (std::hash<int>{}(p.second) << 1);
    }
};

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        std::vector<std::pair<int, int>> solutions; 

        if(s1.empty() && s2.empty() && s3.empty()) return true;
        if(s1.empty()) return s2 == s3;
        if(s2.empty()) return s1 == s3;

        for(char c : s3) {
            if(solutions.empty()) {
                // Seeding
                if(s1[0] == c) {
                    solutions.emplace_back(1, 0);
                }

                if(s2[0] == c) {
                    solutions.emplace_back(0, 1);
                }

                if(solutions.empty()) return false;
                continue;
            }

            std::vector<std::pair<int, int>> newSolutions;
            std::unordered_set<std::pair<int, int>, PairHash> addedNewSolutions;
            for(auto& [l1, l2] : solutions) {
                if(l1 < s1.size() && s1[l1] == c) {
                    std::pair<int, int> newSolution{l1 + 1, l2};
                    auto it = addedNewSolutions.find(std::pair<int, int>(newSolution));
                    if(it == addedNewSolutions.end()) {
                        newSolutions.push_back(newSolution);
                        addedNewSolutions.insert(newSolution);
                    }
                }

                if(l2 < s2.size() && s2[l2] == c) {
                    std::pair<int, int> newSolution{l1, l2 + 1};
                    auto it = addedNewSolutions.find(std::pair<int, int>(newSolution));
                    if(it == addedNewSolutions.end()) {
                        newSolutions.push_back(newSolution);
                        addedNewSolutions.insert(newSolution);
                    }
                }
            }

            solutions = newSolutions;
            if(solutions.empty()) return false;
        }

    
        for(auto& [l1, l2] : solutions) {
            if(l1 == s1.size() && l2 == s2.size()) return true;
        }
        return false;
    }
};