#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector <int> flowerbed = {1,0,0,0,1};
  int n;
  const int maxlength = 2 * 10e4;
  int array[maxlength],pos = 0,num = 0;
  cin >> n;
  memset(array,-2,sizeof(array));
  for (int flower : flowerbed)
  {
    if (flower == 1)
    {
      pos ++;
    }
    else
    {
      array[pos] ++;
    }
  }
  for (int i = 0;i < flowerbed.size();i ++)
  {
    if (array[i] > 0)
    {
      if(array[i] % 2)
      {
        num += (array[i] + 1) / 2;
      }
      else
      {
        num += array[i] / 2;
      }
    }
  }
  cout << (num > n) ? true : false;
}
