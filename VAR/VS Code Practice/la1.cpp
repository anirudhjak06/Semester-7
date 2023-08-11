#include<bits/stdc++.h>
using namespace std;

int copy(int[] cnt,int[] cnt1)
{

}

int main()
{
    vector<char> words={'Q','W','E','R','T','Y','A','W','E','S','O','M','E'};
    vector<string> buckets={"AWZ","AWESOME","INCREDIBLE"};

    int cnt[26]={};    
    vector<string> ans;
      for (auto ch : words) 
          ++cnt[ch - 'a'];
          
      for (auto w : words) {
        bool flag = true;
        int cnt1[26]={};
        for(int i=0;i<26;i++)
        {
            cnt1[i]=cnt[i];
        }
        for (auto ch : w){
          if (cnt1[ch - 'a']) {
            cnt1[ch-'a']--;
          }
          else{
              flag = false;
              break;
          }
        }
        if (flag){
            ans.push_back("yes");
            for(int i=0;i<26;i++)
            {
                cnt1[i]=cnt[i];
            }
        }
        else{
            ans.push_back("no");
        }
      }
      for(int i=0;i<ans.size();i++)
      {
        cout<<ans<<" ";
      }

}