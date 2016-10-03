class Solution {
public:
  string removeKdigits(string num, int k) {
    string res;
    for (char c: num) {
      while (k && res.size() && res.back() > c) {
        res.pop_back();
        k--;
      }
      if (res.size() || c != '0')
        res += c;
    }
    return k >= res.size() ? "0" : res.substr(0, res.size()-k);
  }
};
