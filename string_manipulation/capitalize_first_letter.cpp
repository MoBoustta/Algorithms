//
// Created by moboustt on 9/29/20.
//

#include <iostream>
#include <string>
#include <sstream>
#include <numeric>
#include <vector>
#include <chrono>

void capitalizeFirstLetter(std::string& inputStr){
    std::istringstream iStringStream(inputStr);
    inputStr.clear();
    auto bindTwoStrings = [] (std::string lhs, std::string rhs) -> std::string {
        if (islower(lhs[0])) lhs[0] -= 32;
        if (islower(rhs[0])) rhs[0] -= 32;
        return lhs.empty() ? rhs : lhs + " " + rhs;
    };
    inputStr = std::accumulate(std::istream_iterator<std::string>(iStringStream), std::istream_iterator<std::string>(), inputStr, bindTwoStrings);
}

void capitalizeFirstLetter2(std::string& inputStr){

    std::istringstream iStringStream(inputStr);
    std::vector<std::string> v;

    auto comp = [](std::string str) {
        std::for_each(str.begin(), str.end(), tolower);
        toupper(str[0]);
        return str;
    };
    auto bindTwoStrings = [] (std::string& lhs, std::string& rhs) -> std::string {
        return lhs.empty() ? rhs : lhs + " " + rhs;
    };

    std::transform(std::istream_iterator<std::string>(iStringStream), std::istream_iterator<std::string>(), std::back_inserter(v), comp);
    inputStr.clear();
    inputStr  = std::accumulate(v.begin(), v.end(), inputStr, bindTwoStrings);
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    std::string str { "Trees are beautiful" };
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << '\n';

    start = std::chrono::high_resolution_clock::now();
    std::string str1 { "Trees are beautiful" };
    end = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << '\n';

    capitalizeFirstLetter2(str);
    capitalizeFirstLetter(str1);
    std::cout << str << std::endl;
}