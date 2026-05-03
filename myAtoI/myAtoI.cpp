#include <string>

using namespace std;



class Solution {
public:
    int myAtoi(string s) {
        
        //s = "21474836460"
        // intmax  2,147,483,647

        if(s.empty() || (s.length() == 1 && !isdigit(s[0]))) return 0;

        int sign = 1;
        uint64_t result_64 = 0;
        int result = 0;
        
        // We want to disregard leading whitespace
        // coppied from @dutch https://cplusplus.com/forum/beginner/251052/#msg1105531
        const char* WhiteSpace = " \t\v\r\n";
        size_t start = s.find_first_not_of(WhiteSpace);
        size_t end = s.find_last_not_of(WhiteSpace);
        string ts = start == end ? s : s.substr(start, end - start + 1);
        //

        // Checking for sign, if we find one then we remove it.
        // If the first char after leading whitespace is not a char then 
        //  any subsiquent non-digit chars should exit the loop.
        switch(ts[0]){
            case '+': 
                // cout << "+ ";
                sign = 1;
                ts.erase(0,1);
                break;
            case '-':
                // cout << "- ";
                sign = -1;
                ts.erase(0,1);
                break;
        }


        // Finding the first non-digit
        // If the first char is non-digit then we return 0.
        const char* Digits = "0123456789";
        int test = ts.find_first_not_of(Digits);
        if(test == 0) return 0;
        ts = ts.substr(0, test);

        // cout << "This is ts: " << ts << endl;
        // Checks for single digits
        if(ts.length() == 1) return (int)(ts[0]-'0')*sign;

        // Removes leading 0s
        test = ts.find_first_not_of("0");
        if(test < 0) return 0;
        ts = ts.substr(test, ts.length() - test);



        int len = ts.length();

        if(len>10) return sign < 0 ? sign*(INT_MAX)-1 : INT_MAX;

        for(int i = 0; i < len; i++){
            int digit = (int)ts[i]-'0';
            result_64 += digit * pow(10, len-i-1);
        }

        if(result_64 > INT_MAX){
            return sign < 0 ? sign*(INT_MAX)-1 : INT_MAX;
        } else {
            result = result_64;
        }

        return sign*result;
        // return !sign ? (int)result : (int)(result*sign);
    }
};