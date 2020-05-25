#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>

using namespace std;
class Solution {
public:
    int reverse(int x) {
        int flag=0;
        if(x<0){
            if(x<=-2147483648)return 0;
            x=-x;
        } else{
            flag=1;
        }


        string s=to_string(x);
        for(int i=0;i<s.size()/2;i++){
            int j=s.size()-i-1;
            char temp=s[j];
            s[j]=s[i];
            s[i]=temp;
        }
        try {
            x = stoi(s);
        }catch (std::invalid_argument&){
            return 0;
        }catch (std::out_of_range&){
            return 0;
        }

        if(flag==0)x=-x;

        return x;
    }
};