//Question-1

//Approach - Using stack

// Input:  arr[] = {1, 6, 4, 10, 2, 5}
// Output:        {-1, 1, 1, 4, 1, 2}

//From the input test case and output test case, I understand that question asks to find previous smaller element.

//Time complexity - o(n) wheree,
//n is the size of the array

//Space complexity - O(n)

// C++ implementation of efficient algorithm to find
// smaller element on left side

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // //Un-comment for command line input
    // int n;
    // cout<<"The size of the array: ";
    // cin>>n;
    // cout<<"Enter the elements in the array: "<<endl;
    // vector<int> v;
    // for(int i=0;i<n;i++)
    // {
    //     int element;
    //     cin>>element;
    //     v.push_back(element);
    // }

    //Inputs
	vector<int> v= {1,6,4,10,2,5};
	int n =v.size();

    //Logic
    stack<int> st;
    vector<int> res;
	for (int i=0; i<n; i++)
	{
        //Just maintaining a montonic increasing stack with element less than or equal to next element
		while (!st.empty() && st.top() >= v[i])
        {
			st.pop();
        }
        //Edge case of stack being empty is -1;
        if (st.empty())
        {
			res.push_back(-1);
        }
		else 
        {
        	res.push_back(st.top());
        }
		// Push the elements into the stack one by one
		st.push(v[i]);
    }
    //Outputting all the results in a vector and returning it.
    cout<<"Output Result: "<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;
	return 0;
}
