#include <iostream>
#include <set>
#include <unordered_set>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void line()
{
    cout<<"**************************************"<<endl;
}
void print(set<int>&s)
{
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<*i<< " " ;
    }
    cout<<endl;
}
void print(set<int,greater<int>>&s)
{
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<*i<< " " ;
    }
    cout<<endl;
}
void print(multiset<int>&s)
{
    for(auto i=s.begin(); i!=s.end(); i++)
    {
        cout<<*i<< " " ;
    }
    cout<<endl;
}
void print(unordered_multiset<int>&u)
{
    for(auto i=u.begin(); i!=u.end(); i++)
    {
        cout<<*i<< " " ;
    }
    cout<<endl;
}
void print(unordered_set<int>&u)
{
    for(auto i=u.begin(); i!=u.end(); i++)
    {
        cout<<*i<< " " ;
    }
    cout<<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//// sorted as a binary tree
//// 1- unique values     2- sorted    3- fast insertion , removal , read only and searching  ( log(n) )

    int siz;
    cin>>siz;
    set<int>s;

    //// adding and removing

    for(int i=1; i<=siz; i++)
    {
        s.insert(i);
    }
    print(s);

    for(int i=1; i<=siz; i++)
    {
        s.insert(s.begin(),i);
    }
    //// faster way to insert
    print(s);

    auto it = s.begin();
    for(int i=1; i<=siz+10; i++)
    {
        it = s.emplace_hint(it,i); /////emplace_hint
    }
    print(s);

    auto l = s.begin();
    s.erase(l); ////erasing by iterator
    print(s);

    cout<<"after erasing (5) ";
    s.erase(5); ////erasing element
    print(s);
    cout<<"size is : " << s.size()<<endl;

    auto o = s.find(15);
    cout<<*o<<endl; //// if 15 isn't in the set it return an iterator which is s.end()

    auto k  = s.lower_bound(4);//Returns an iterator to the first element not less than the given key
    auto x  = s.upper_bound(11);//Returns an iterator to the first element greater than the given key
    cout<<*k<<endl;
    cout<<*x<<endl;

    auto range = s.find(10);
    s.erase(range,s.end());
    cout<<"set after removing a range of elements : ";
    print(s);

    auto eq_range = s.equal_range(7);
    cout<<"the element is : "<<*eq_range.first<<endl;
    cout<<"the element that follows the the targeted element : "<<*eq_range.second<<endl;

    set<int, greater<int>>seto {1,5,2,3,4};
    cout<<"desc order of seto set : ";
    print(seto);

    line();

    //////////////////               multi set (ordered - non unique )

    multiset<int>mult{5,2,7,9,2,1,3,4,4,4,5};
    multiset<int>mult2{5,56,5,2,9,77,1,1,1,1,3};
    multiset<int>multall{};
    multiset<int>multinter{};
    print(mult);
    print(mult2);

    set_union(mult.begin(),mult.end(),mult2.begin(),mult2.end(),inserter(multall, multall.begin()));
    set_intersection(mult.begin(),mult.end(),mult2.begin(),mult2.end(),inserter(multinter, multinter.begin()));
    cout<<"union multiset is : ";
    print(multall);
    cout<<"intersection multiset is : ";
    print(multinter);

    cout<<"the frequency of the element : "<<mult.count(5)<<endl;

    line();
    ////////////////                unordered set ( using hash function )

    unordered_set<int>u_s {4,2,5,8,7,4,1,3,5,9,8,2,1};
    cout<<"unordered set : ";
    print(u_s);

    for(auto x : u_s)
    {
        cout<<"the element : "<<x<<" is in the bucket : "<<u_s.bucket(x)<<endl;
    }
    cout<<"buckets count : "<<u_s.bucket_count()<<endl;

    int xf = 50;
    if(u_s.find(xf) !=u_s.end())
    {
        cout<<xf<<" is found in the unordered set"<<endl;
    }
    else
    {
    cout<<xf<<" not found in the unordered set " <<endl;
    }

    u_s.erase(u_s.find(7),u_s.end());
    cout<<"unordered set after erasing from 7 to end : ";
    print(u_s);


    line();
    /////////////////                unordered multi set

    unordered_multiset<int>u_ms {5,1,2,6,52,1,4,7,4,5,3,2,5,8,100};
    cout<<"unordered multiset : ";
    print(u_ms);

    line();

}
