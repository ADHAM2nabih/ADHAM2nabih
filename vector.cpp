#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void print2d(vector<vector<int>>& v)
{
    for(int i=0; i<v.size(); i++)
    {
        for(int j=0; j<v.size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void print4(vector<int>&v)
{
    for(auto i=v.begin(); i!=v.end(); i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int siz;
    cin>>siz;
    vector<int>v(siz);

    for(int i=1; i<=siz; i++)
    {
        v.push_back(i);
    }

    print(v);
    cout<<"capacity  :  "<<v.capacity()<<endl;
    v.push_back(8);
    print(v);
    cout<<"capacity  :  "<<v.capacity()<<endl;
    v.clear();
    ///////////adding and removing

    for(int i=1; i<=siz; i++)
    {
        v.push_back(i);
    } ///// if the size is already init a size of zeros is init before the push_back func
    // 0 0 0 0 1 2 3 4     if size = 4
    print(v);

    for(int i=0; i<siz; i++)
    {
        v.insert(v.begin()+i,i+1);  // adding at the begin of the vector
        v.insert(v.end()-1,i+1);    // adding at the end of the vector
    }
    ////  1 2 3 4 0 0 0 0 1 2 3 1 2 3 4 4
    //// diff between ( emplace and insert ) is insert make a copy before inserting the object to the vector
    print(v);

    for(int i=0; i<siz; i++)
    {
        v.emplace(v.begin()+i,i);
    }
    print(v);
    ////0 1 2 3 1 2 3 4 0 0 0 0 1 2 3 1 2 3 4 4

    for(int i=1; i<=siz; i++)
    {
        v.erase(v.end()-i);
        v.pop_back();    //earsing elements
    }
    print(v);
    ////0 1 2 3 1 2  4 0 0 0 1

    cout<<"size is : "<<v.size()<< " \n";
    cout<<"capacity is : "<<v.capacity()<<" \n";
    // capacity constructed by doubling the size of the vector if it full of objects
    // size = 5 , capacity = 5  {  1 2 3 4 5  }and u wanna add one more obj
    // then the capacity will be 10 and size = 6

    v.clear();

    for(int i=1; i<=siz; i++)
    {
        v.emplace_back(i);
    }
    print(v);

    cout<<"front : "<<v.front()<<"  back : "<<v.back()<<endl;

    v.reserve(80);          ////increase capacity as u want
    cout<<"size is : "<<v.size()<< " \n";
    cout<<"capacity is : "<<v.capacity()<<" \n";

    v.shrink_to_fit();
    cout<<"size after shrinking is : "<<v.size()<< " \n";
    cout<<"capacity after shrinking is : "<<v.capacity()<<" \n";
    v.reserve(40);
    cout<<"size after reserving  is : "<<v.size()<< " \n";
    cout<<"capacity after reserving is : "<<v.capacity()<<" \n";

    v.resize(2);
    cout<<"size after resize is : "<<v.size()<< " \n";
    cout<<"capacity after resize is : "<<v.capacity()<<" \n";

    ////// the diff here between shrink_to_fit and resize  ( shrink make the capacity equals the size ) but the resiz func make the size only fit the vector
    ////// if the size = 5 and capacity = 40  resize (size = 4  capacity = 40)  shrink (size= 4  capacity = 4)

    int* pos = v.data();
    cout << "The vector elements are: ";
    for (int i = 0; i < v.size(); ++i)
        cout << *pos++ << " ";

/////////////////////////////////////////////////////////////////////////////////////////////////////////

    vector<vector<int>> f (siz+2,vector<int>(siz+2,0));
    for(int i = 2; i<=siz; i++)
    {
        for(int j=1; j<=siz; j++)
        {
            f[i][j] = j;
        }
    }
    print2d(f);
//////// 2D VECTOR for avoiding out of bounds

}
