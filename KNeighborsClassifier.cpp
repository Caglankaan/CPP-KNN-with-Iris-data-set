#include "KNeighborsClassifier.h"
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h> 
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include <fstream>

KNeighborsClassifier::KNeighborsClassifier()
{
    
}
KNeighborsClassifier::~KNeighborsClassifier()
{
    
}

std::vector<std::string> KNeighborsClassifier::splitVector(const std::string &text, char sep)
{
    std::vector<std::string> tokens;
    std::size_t start=0, end =0;
    while((end = text.find(sep,start)) != std::string::npos){
        tokens.emplace_back(text.substr(start,end-start));
        start = end + 1;
   } 
    tokens.emplace_back(text.substr(start));    

    return tokens;
}

bool KNeighborsClassifier::comparison(KNeighborsClassifier::Point a, KNeighborsClassifier::Point b) 
{ 
    return (a.distance < b.distance); 
}

void KNeighborsClassifier::fillDataSet(int numberOfData, std::string fileName)
{
    std::fstream f;
    f.open(fileName,std::ios::in);
    if (f.is_open()){ 
        std::string tp;
        while(getline(f, tp)){
            KNeighborsClassifier::Point p;
            std::vector<std::string> whole_data = splitVector(tp,',');
            p.x = atof(whole_data[0].c_str());
            p.y = atof(whole_data[1].c_str());
            p.z = atof(whole_data[2].c_str());
            p.t = atof(whole_data[3].c_str()); 
            classSet.insert(whole_data[4]);
            p.className = whole_data[4]; 
            pointArr.emplace_back(p);
        }
        f.close(); 
   }
}


std::string KNeighborsClassifier::predict(KNeighborsClassifier::Point p, int k) 
{ 
    Point closest_node;
    double minDistance = 0.0;
    for (int i = 0; i < pointArr.size(); i++)
    {
        double currentDistance = sqrt((pointArr[i].x - p.x) * (pointArr[i].x - p.x) + 
                                    (pointArr[i].y - p.y) * (pointArr[i].y - p.y) +
                                    (pointArr[i].z - p.z) * (pointArr[i].z - p.z) +
                                    (pointArr[i].t - p.t) * (pointArr[i].t - p.t));
        pointArr[i].distance = currentDistance;
        if (i == 0 || currentDistance < minDistance)
        {
            closest_node = pointArr[i];
            minDistance = currentDistance;
        }
    } 
    sort(pointArr.begin(), pointArr.end(), comparison); 
    std::unordered_map<std::string, int> frequencyOfClasses;

    std::unordered_set<std::string>::iterator itr; 
    
    for (int i = 0; i < k; i++) 
    {
        std::unordered_set<std::string>::iterator itr; 
        for (itr = classSet.begin(); itr != classSet.end(); itr++)
        {
            if(*itr == pointArr[i].className)
            {
                frequencyOfClasses[*itr] ++;
            }
        }
    } 
    int maxFreq = 0;
    std::string maxFreqClass;
    for(auto freq: frequencyOfClasses)
    {
        if(freq.second > maxFreq)
        {
            maxFreq = freq.second;
            maxFreqClass = freq.first;
        }
    }
    return maxFreqClass;
    
} 