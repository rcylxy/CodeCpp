#include <iostream>
using namespace std;

int v[510], w[510], s[510], dp[6100];
//此时w[i]表示的是价值，v[i]表示的是重量
int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
  {
    cin >> v[i] >> w[i] >> s[i];
  }
  for (int i = 1; i <= n; ++i)
  {
    for (int j = m; j >= 1; --j)
    {
      for (int k = 0; k <= s[i] && j >= k * v[i]; ++k)
      {
        //这是01背包的变种，增加了从0个物品到有限个物品的第三层次的循环
        dp[j] = max(dp[j], dp[j - k * v[i]] + k * w[i]);
      }
    }
  }
  cout << dp[m];
  return 0;
}