#include <iostream>
#include <string>
#include <cstdio>
#include <stdexcept>

using namespace std;
/*我的非常naive的做法*/
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

/*官方给的解答，利用弹出和推入数字&&溢出前检查*/
/*
 * 假设result为正数，当result>INT_MAX/10时，在此之后再乘10必然溢出
 * 若result恰好等于INT_MAX/10，若pop大于7时也必将溢出
 * 负数同理*/
class Solution2 {
public:
    int reverse(int x) {
        int result=0;
        while(x!=0){
            int pop=x%10;
            x=x/10;
            if(result>INT_MAX/10||((result==INT_MAX/10)&&pop>7))return 0;
            if(result<INT_MIN/10||((result==INT_MIN/10)&&pop<-8))return 0;
            result=result*10+pop;
        }
        return result;
    }
};