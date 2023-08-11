#include <bits/stdc++.h>
using namespace std;

struct BOOK
{
    /* data */
    string product;
    int price;
    int SeqNum;
};

int k = 0;
void load(BOOK b1[])
{
    // string pro;
    // cout << "Enter product name:";
    // cin >> pro;
    // b1[k].product = pro;
    // int pri;
    // cout << "Enter price:";
    // cin >> pri;
    // b1[k].price = pri;
    // int SeqNum;
    // cout << "Enter SeqNum:";
    // cin >> SeqNum;
    // b1[k].SeqNum = SeqNum;
    // k++;
    b1[k].product="K7";
    b1[k].price=100;
    b1[k].SeqNum=1;
    k++;
    b1[k].product="K7";
    b1[k].price=90;
    b1[k].SeqNum=2;
    k++;
    b1[k].product="K7";
    b1[k].price=110;
    b1[k].SeqNum=3;
    k++;
    b1[k].product="K5";
    b1[k].price=80;
    b1[k].SeqNum=4;
    k++;
    b1[k].product="K7";
    b1[k].price=-10;
    b1[k].SeqNum=5;
    k++;
    b1[k].product="K7";
    b1[k].price=80;
    b1[k].SeqNum=6;
    k++;
    b1[k].product="K7";
    b1[k].price=95;
    b1[k].SeqNum=7;
    k++;
    b1[k].product="K7";
    b1[k].price=80;
    b1[k].SeqNum=8;
    k++;
}

static bool cmp(const pair<string, vector<int>> &a, const pair<string, vector<int>> &b)
{
    return a.second[0] > b.second[0];
}

int main()
{

    // b1.product = "H1";
    //cout << "Enter no. of products:";

    // int n;
    // cin >> n;
    BOOK b1[200];
    //int tmp = n;
    load(b1);
    // while (n--)
    // {
    //     load(b1);
    // }
    int count1=0,count2=0;
    vector<pair<string, vector<int>>> p1;

    map<string,vector<int>> mp;
    vector<int> zeroes(5,0);
    for (int i = 0; i < k-1; i++)
    {
        //pair<string, vector<int>> pp;
        // pp.first = b1[i].product;
        // pp.second.push_back(b1[i].price);
        // pp.second.push_back(b1[i].SeqNum);
        // p1.push_back(pp);
       
        string book1=b1[i].product;
        string book2=b1[i+1].product;

        zeroes[count1]=b1[i].price;
        count1++;
        cout<<book1;
        cout<<" || ";
        int non_zero=0;
        for(int i=0;i<5;i++)
        {
            if(zeroes[i]!=0) non_zero++;
        }
        sort(zeroes.begin(),zeroes.begin()+non_zero);
        for(int i=0;i<5;i++)
        {
            cout<<zeroes[i]<<" ";
        }
        cout<<" || ";
        cout<<endl;

        if(book1!=book2)
        {
            for(int q=0;q<5;q++) zeroes[q]=0;
            count1=0;
        }
        // string book1=b1[i].product;
        // int vec=b1[i].price;
        // mp[book1].push_back(vec);
    }
    // sort(p1.begin(), p1.end(), cmp);
    // for (int i = 0; i < tmp; i++)
    // {
    //     cout << p1[i].first << " " << p1[i].second[0] << " " << p1[i].second[1] << "\n";
    // }
}