#include <iostream>
#include <queue>
using namespace std;

int bfs(int arr[],int siz,int target)
{
    int i=1;
    queue<int>q;
    q.push(arr[1]);
    while(!q.empty())
    {
      if(q.front()!=target)
      {
          q.pop();
          if(i*2>=siz)
          {
              return 0;
          }
          q.push(arr[i*2]);
          q.push(arr[(i*2)+1]);
          i++;
      }
      else
      {
        return 1;
      }
    }
    return 0;
}

int main()
{
    int siz,target;
    cin>>siz>>target;
    int arr[siz+1];
    for(int i=1;i<siz;i++){ cin>>arr[i]; }
    cout<<bfs(arr,siz,target);

}
