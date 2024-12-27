#include <bits/stdc++.h>
#include "column.hpp"
#include "columnNum.hpp"

int NumColumn :: getSum(){
    int sum = 0;
    for(std::string data : data){
        sum += std::stoi(data);
    }
    return sum;
}

int NumColumn :: getMin(){
    int min = std::stoi(data[0]);
    for(std::string data : data){
        if(std::stoi(data) < min){
            min = std::stoi(data);
        }
    }
    return min;
}

int NumColumn :: getMax(){
    int max = std::stoi(data[0]);
    for(std::string data : data){
        if(std::stoi(data) > max){
            max = std::stoi(data);
        }
    }
    return max;
}