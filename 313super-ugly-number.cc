typedef pair<int, int> pii;
class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int len = primes.size();
    vector<int> ugly{1}, idx(len, 0);
    priority_queue<pii, vector<pii>, greater<pii>> minheap;
    for (int i = 0; i < len; i++)
      minheap.emplace(primes[i], i);
    pii tmp;
    n--;
    while (n) {
      tmp = minheap.top();
      minheap.pop();
      int val = tmp.first, pid = tmp.second;
      if (val != ugly.back()) {
        ugly.push_back(val);
        n--;
      }
      minheap.emplace(primes[pid] * ugly[++idx[pid]], pid);
    }
    return ugly.back();
  }
};

class Solution {
public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    int m = primes.size();
    vector<int> ugly(n, INT_MAX);
    vector<int> idx(m, 0);
    ugly[0] = 1;
    for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++) {
        if (primes[j] * ugly[idx[j]] == ugly[i-1])
          idx[j]++;
        ugly[i] = min(ugly[i], primes[j] * ugly[idx[j]]);
      }
    return ugly[n-1];
  }
};
