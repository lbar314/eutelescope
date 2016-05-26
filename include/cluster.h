#ifndef cluster_h
#define cluster_h 1

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

class Cluster {
  public:
    Cluster();
    void set_values(int,std::vector<int>,std::vector<int>);
    Cluster mirrorX();
    Cluster mirrorY();
    Cluster rotate90();
    void NeighbourPixels(int x, int y, std::vector<int> xOriginal, std::vector<int> yOriginal, std::vector<int> &xNeighbour, std::vector<int> &yNeighbour);
    void FindReferenceClusters(std::vector<Cluster> &clusterVec, int sizeMax);
    std::map<int,int> SymmetryPairs(std::vector<Cluster> clusterVec, const char* type);
    std::vector< std::vector<int> > sameShape(std::vector<Cluster> clusterVec);
    int WhichClusterShape(Cluster cluster, std::vector<Cluster> clusterVec);
    std::vector<int> getX() {return x;}
    std::vector<int> getY() {return y;}
    int Size() {return size;}
    bool operator==(Cluster c2);
    void getCenterOfGravity(float &xCenter, float &yCenter);
    std::string getPattern() {return pattern;}
 protected:
    int size;
    std::vector<int> x;
    std::vector<int> y;
    std::string pattern; //1° byte: row-span, 2° byte: column-span , remaining bytes: pattern of pixels
};

#endif
