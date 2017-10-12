#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s,substring;
    cin>>s;
    auto length=s.size();
    for(decltype(length) i=1;i<=length*0.5;++i)
    {
        bool signal=true;
        if(length%i==0)
        {
            substring=s.substr(0,i);
            int times=length/i;
            for(int j=1;j<times;++j)
            if(substring!=s.substr(j*i,i))
                {
                    signal=false;
                    break;
                }
        }else continue;
        if(signal==true)
        {
            cout<<"The shortest substring is "<<substring<<endl;
            return 0;
        }
    }
    cout<<"Not exist!"<<endl;
}
