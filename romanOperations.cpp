#include <iostream>

using namespace std;

int romanToInt(string s) 
{
    int ans = 0, l = s.length();
    
    for (int i = 0; i < l; i++)
    {
        if(s[i] == 77) ans += 1000;
        else if(s[i] == 68) ans += 500;
        else if(s[i] == 67) 
            if(s[i+1] == 77 || s[i+1] == 68)
                ans -= 100;
            else
                ans += 100;
        else if(s[i] == 76) ans += 50;
        else if(s[i] == 88) 
            if(s[i+1] == 67 || s[i+1] == 76)
                ans -= 10;
            else
                ans += 10;
        else if(s[i] == 86) ans += 5;
        else if(s[i] == 73) 
            if(s[i+1] == 86 || s[i+1] == 88)
                ans -= 1;
            else
                ans += 1;
    }
    return ans;
}

string intToRoman(int n)
{
    string str_romans[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

    string result = "";

    for (int i = 0; i < 13; ++i)
    {
        while(n - values[i] >= 0)
        {
            result += str_romans[i];
            n -= values[i];
        }
    }
    return result;
}

string calculate(string s)
{
    int ans = 0, l = s.length(), last_operation = l;
    string p;

    for (int i = l-1; i != -1; i--)
    {
        if (s[i] == 43) {
            ans += romanToInt(s.substr(i,last_operation-i));
            last_operation = i;
        } else if (s[i] == 45){
            ans -= romanToInt(s.substr(i,last_operation-i));
            last_operation = i;
        }
        
    }

    ans += romanToInt(s.substr(0,last_operation));

    return intToRoman(ans);
}

int main()
{
    cout << calculate("III+IV");
}