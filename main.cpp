#include "KNeighborsClassifier.h"

int main() 
{ 
    KNeighborsClassifier knn = KNeighborsClassifier();
    knn.fillDataSet(50,"iris.data");
    std::vector<KNeighborsClassifier::Point> pointArr;
    std::fstream f;
    f.open("test.data",std::ios::in);
    if (f.is_open()){ 
        std::string tp;
        while(getline(f, tp)){
            KNeighborsClassifier::Point p;
            std::vector<std::string> whole_data = knn.splitVector(tp,',');
            p.x = atof(whole_data[0].c_str());
            p.y = atof(whole_data[1].c_str());
            p.z = atof(whole_data[2].c_str());
            p.t = atof(whole_data[3].c_str());
            pointArr.emplace_back(p);
        }
        f.close(); 
   }

    for(auto newPoint: pointArr)
    {
        std::cout << "Point (" << newPoint.x << "," << newPoint.y << "," << newPoint.z <<","<<newPoint.t <<")" << " probably classname: " << knn.predict(newPoint,5) << "\n";
    }
    return 0; 
}   