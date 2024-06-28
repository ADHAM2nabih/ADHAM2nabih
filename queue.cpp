#include <iostream>
#include <queue>
using namespace std;

void add(queue<int>&q,int siz)
{
    for(int i=1; i<=siz; i++)
    {
        q.push(i);
    }
}
void add(priority_queue<int,vector<int>,greater<int>>&p_q2,int siz)
{
    for(int i=1; i<=siz; i++)
    {
        p_q2.push(i);
    }
}
void add(priority_queue<int>&q,int siz)
{
    for(int i=1; i<=siz; i++)
    {
        q.push(i);
    }
}
void print(queue<int>&q)
{
    cout<<"queue : ";
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
void print(priority_queue<int,vector<int>,greater<int>>&p_q2)
{
    cout<<"queue : ";
    while(!p_q2.empty())
    {
        cout<<p_q2.top()<<" ";
        p_q2.pop();
    }
    cout<<endl;
}
void print(priority_queue<int>&q)
{
    cout<<"priority queue : ";
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<endl;
}
void frnt(queue<int>&q)
{
    cout<<"back : "<<q.back()<<endl;
}
void bck(queue<int>&q)
{
    cout<<"front : "<<q.front()<<endl;
}
void siz(queue<int>&q)
{
    cout<<"size of queue : "<<q.size()<<endl;
}

int main()
{
    queue<int>q;
    add(q,10);
    print(q);

    add(q,100);
    frnt(q);
    bck(q);
    siz(q);
    print(q);

//////////////// priority queue (Binary Heap )
//// sorted (asc - dsc) - min or max O(1)

    priority_queue<int>p_q; // sorted dsc
    add(p_q,10);
    print(p_q);

    priority_queue<int,vector<int>,greater<int>>p_q2;
    add(p_q2,15);
    print(p_q2);




}
