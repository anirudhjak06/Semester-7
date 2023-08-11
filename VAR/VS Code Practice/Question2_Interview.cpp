//Question-2

//Time complexity - O(n*k) where,
//n would be size of words and k is average no of letters in a word

//Space complexity of O(N) where,
//N is the size of bucket_of_letters

#include<bits/stdc++.h>
using namespace std;

int main()
{
    //Un-comment for command line input 
    // int n;
    // cout<<"Enter no of letters in buckets: ";
    // cin>>n;
    // vector<char> bucket_of_letters;
    // cout<<"Enter the "<<n<<"letters in the bucket"<<endl;
    // for(int i=0;i<n;i++)
    // {
    //     char c;
    //     cin>>c;
    //     bucket_of_letters.push_back(c);
    // }
    // int n1;
    // cout<<"No of words: ";
    // cin>>n1;
    // vector<string> words;
    // for(int i=0;i<n1;i++)
    // {
    //     string str;
    //     cin>>str;
    //     words.push_back(str);
    // }

    //Inputs
    vector<char> bucket_of_letters={'Q','W','E','R','T','Y','A','W','E','S','O','M','E'};
    vector<string> words={"AWZ","AWESOME","INCREDIBLE"};

    //Logic
    //For frequency count of bucket_of_letters
    map<char,int> mp1;
    for(auto it:bucket_of_letters)
    {
        mp1[it-'A']++;
    }
    //For outputting answer for each and every word
    vector<string> res;

    for(int i=0;i<words.size();i++)
    {
        //Temporary string to store each word which is only present in the hashmap
        string word=words[i];
        bool flag=true;
        string str="";
        for(int j=0;j<word.size();j++)
        {
            //If the word is already present, then remove it from the map
            if(mp1.find(word[j]-'A')!=mp1.end())
            {
                str+=word[j];
                mp1[word[j]-'A']--;
                //Edge case when map can be empty
                if(mp1[word[j]-'A']==0) mp1.erase(word[j]-'A');
            }
            //If the word is not present, add the characters in the string to the map.
            //Considering the edge case of only adding elements when string is completely present in the word.
            else
            {
                flag=false;
                for(int k=0;k<str.size();k++) mp1[str[k]-'A']++;
                str="";
                break;
            }
        }
        //If the flag is true, then yes or else no
        if(flag) res.push_back("YES");
        else res.push_back("NO");
    }
    //Outputting all the results in a vector and returning it.
    cout<<"Output Result: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<endl;
    }

}