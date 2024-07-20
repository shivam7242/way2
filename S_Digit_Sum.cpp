#include<bits/stdc++.h>



bool fun(vector<int> &a)
{
  int n = a.size();
  map<int, int> freq;
  for (int i = 0; i < n; i++)
  {
    int ele = a[i];
    for (int j = 2; j * j <= ele; j++)
    {
      while (ele % j == 0)
      {
        freq[j]++;
        ele = ele / j;
      }
      if (ele != 1)
      {
        freq[ele]++;
      }
    }
  }
  
  for (auto it = freq.begin(); it != freq.end(); it++)
  {
    if (it->second % n != 0)
    {
      return false;
    }
  }
  return true;
}

//   time complexity =  n* sqrt(n) 

// isko n logn me bhi kar sakte using spf technique



//  map kar  unorder map pe iterate nhi kar sakta

bool fun(vector<int> &a)
{
  int n = a.size();
  map<int, int> freq;

  // aur isko map kar unorder ki jagah
  for (int i = 0; i < n; i++)
  {
    int ele = a[i];
    for (int j = 2; j * j <= ele; j++)
    {
      while (ele % j == 0)
      {
        freq[j]++;
        ele = ele / j;
      }
    }
    if (ele != 1)
    {
      freq[ele]++;
    }
    //  isko undar wale loop ke bahar kar de 
    // for loop ke bahar andar wale 
  }
  for (auto it = freq.begin(); it != freq.end(); it++)
  {
    if (it->second % n != 0)
    {
      return false;
    }
  }
  return true;
}
int main(){




printf("%d %d %d %d\n", b,a,ch,ptr);


}


