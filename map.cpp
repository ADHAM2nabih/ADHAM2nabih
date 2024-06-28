#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
using namespace std;

void print(map<string,int>&m)
{
    cout<<"-----------------"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<"-----------------"<<endl;
}
void print(map<char,int,greater<char>>&m) /////////////////////////////////
{
    cout<<"-----------------"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<"-----------------"<<endl;
}
void print(map<string,int>&m, string s)
{
    cout<<s<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<"-----------------"<<endl;
}
void print(map<string,int,greater<string>>&m, string s)
{
    cout<<s<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<"-----------------"<<endl;
}
void print(map<int,char,greater<int>>&m)
{
    cout<<"-----------------"<<endl;
    for(auto x:m)
    {
        cout<<x.first<<" : "<<x.second<<endl;
    }
    cout<<"-----------------"<<endl;
}
void print(multimap<char,int>&m_m)
{
    cout<<"-----------------"<<endl;
    for(auto m : m_m)
    {
        cout<<m.first<<" : "<<m.second<<endl;
    }
}
int main()
{

    int siz;
    cin>>siz;

    map<string,int>m; //sorted by the key , support random access , unique

    for(int i=0; i<siz; i++)
    {
        cout<<"enter name : ";
        string s;
        cin>>s;
        cout<<"enter age : ";
        int num;
        cin>>num;
        m[s]=num;
    }
    auto iter = m.begin(); // faster way to insert
    iter = m.insert(iter, {"abas",18});
    iter = m.insert(iter, {"hany",42});
    m.insert(pair<string,int>("doma",27));
    m.insert(make_pair("somia",41));
    m.insert({"mohaned",33});
    m.emplace("jana",36);
    iter = m.emplace_hint(iter,"kamel",31);
    print(m);

    auto fnd = m.find("doma");
    if(fnd!=m.end() || m.count("doma"))
    {
        cout<<"doma found "<<endl;
    }
    else
    {
        cout<<"doma not found "<<endl;
    }

    //////////erasing elements
    m.erase("doma");
    print(m);
    m.erase(m.begin(),++m.find("hany"));
    print(m);

    /*
    abas : 18
    hany : 42
    jana : 36
    kamel : 31
    mohaned : 33
    somia : 41
    */

    auto low = m.lower_bound("a");
    auto high = ++m.upper_bound("k");
    m.erase(low,high);
    print(m,"after erasing from a to k : ");

    cout<<"map size is : " <<m.size()<<endl;

    m.clear();
    print(m);

    map<char,int,greater<char>>m2;   //// desc (char)
    auto i = m2.begin();
    i = m2.emplace_hint(i,'z',20);
    i = m2.emplace_hint(i,'b',21);
    i = m2.emplace_hint(i,'c',22);
    i = m2.emplace_hint(i,'d',23);
    i = m2.emplace_hint(i,'e',200);
    i = m2.emplace_hint(i,'f',25);
    i = m2.emplace_hint(i,'g',26);
    i = m2.emplace_hint(i,'h',27);
    print(m2);

    map<int,char,greater<int>>m3; //// desc (int)
    auto i1 = m3.begin();
    i1 = m3.emplace_hint(i1,20,'z');
    i1 = m3.emplace_hint(i1,21,'b');
    i1 = m3.emplace_hint(i1,22,'c');
    i1 = m3.emplace_hint(i1,23,'d');
    i1 = m3.emplace_hint(i1,200,'e');
    i1 = m3.emplace_hint(i1,25,'f');
    i1 = m3.emplace_hint(i1,26,'g');
    i1 = m3.emplace_hint(i1,27,'h');
    print(m3);

    ///////////////////////// multimap ( non unique , same as map , random access not supported bec of duplicates )

    multimap<char,int>m_m;
    auto it = m_m.begin();
    it = m_m.emplace_hint(it,'a',10);
    it = m_m.emplace_hint(it,'a',10);
    it = m_m.emplace_hint(it,'a',15);
    it = m_m.emplace_hint(it,'b',20);
    it = m_m.emplace_hint(it,'c',40);
    it = m_m.emplace_hint(it,'z',100);
    print(m_m);

    cout<<"frequency of 'a' : "<<m_m.count('a')<<endl;

    /////////////////////////// unordered map ( not sorted , has same functions


    /////////////////////////  unordered multimap ( not sorted , enables dublicates )
}
