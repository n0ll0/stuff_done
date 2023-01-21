#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    int64_t a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int64_t ans =0;
    for (int j=0; j<n; j++)
    {
        cout << a[j] <<"\n"<< a[j+1] << "\n";
        ans += a[j+1]-a[j];
    }
    
    cout<<ans;
    return 0;
}