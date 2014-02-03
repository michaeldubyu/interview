#include <stdio.h>
#include <string>
#include <iostream>

int main(){
    std::string s1 = "string";
    std::string s2 = "asdffuckgod";

    std::string *p1 = &s1;
    std::string *p2 = p1;
    
    p1 = &s2;

    std::cout << "value of s1 should be string, and it is " << *p2 << std::endl;


}
