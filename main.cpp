#include <iostream>
#include <vector>
#include <assert.h>  
#include <map>   
using namespace std;


class Solution {
public:

    int romanstringtoint(string &input, string substring){
        int sum = 0;
        map<string,int> calculator{{"CM",900},{"CD",400},{"XC",90},{"XL",40},{"IX",9},{"IV",4}};
        
        while(input.find(substring) != std::string::npos){
            input.erase(input.find(substring),string(substring).length());
            sum+=calculator[substring];
        }
        return sum;

    }

    int romanToInt(string s) {
        string romannum = s;
        int sum = 0;

        sum += romanstringtoint(romannum,"CM");
        sum += romanstringtoint(romannum,"CD");
        sum += romanstringtoint(romannum,"XC");
        sum += romanstringtoint(romannum,"XL");
        sum += romanstringtoint(romannum,"IX");
        sum += romanstringtoint(romannum,"IV");
    
        map<char,int> calculator{{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};

        for(auto it = romannum.begin(); it < romannum.end(); ++it){
            sum += calculator[(*it)];
           
        }

        return sum;
    }
    
};

int main(){

    
    assert(Solution().romanToInt("MCMXCIV")==1994);
    assert(Solution().romanToInt("III")==3);
    assert(Solution().romanToInt("IV")==4);
    assert(Solution().romanToInt("IX")==9);
    assert(Solution().romanToInt("LVIII")==58);
    assert(Solution().romanToInt("LVIII")==58);

    return 0;
}