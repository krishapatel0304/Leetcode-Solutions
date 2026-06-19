class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        vector<int>praxolimor=nums;
        unordered_set<int>st(praxolimor.begin(),praxolimor.end());
        vector<int>uniquenums(st.begin(),st.end());
        sort(uniquenums.begin(),uniquenums.end(),greater<int>());
        if((int)uniquenums.size()>k){
            uniquenums.resize(k);
        }
        return uniquenums;
    }
};