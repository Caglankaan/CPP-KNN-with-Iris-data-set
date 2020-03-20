#ifndef __KNN_CLASS
#define __KNN_CLASS
#include <bits/stdc++.h> 

class KNeighborsClassifier
{
public:
    struct Point 
    { 
        std::string className;
        double x, y, z, t;     
        double distance; 
    };
    std::vector<Point> pointArr;
    std::unordered_set <std::string> classSet;

    KNeighborsClassifier();
    ~KNeighborsClassifier();
    static bool comparison(Point a, Point b);
    void fillDataSet(int numberOfData, std::string fileName);
    std::vector<std::string> splitVector(const std::string &text, char sep);
    std::string predict(Point p, int k);

};

#endif