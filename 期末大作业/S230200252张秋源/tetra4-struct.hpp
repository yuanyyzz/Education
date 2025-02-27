#ifndef TETRA4_STRUCT_HPP
#define TETRA4_STRUCT_HPP
#include<Eigen/Dense>
#include<vector>
#include<array>
using namespace std;

/*
point in 3d space
*/
struct Point3D
{
    double x;
    double y;
    double z;
};

struct Point3DResult : public Point3D{
    double u;
    double v;
    double w;
    Point3DResult(Point3D, double, double, double);
};

/*
Remember that the node number must start with 0
So the hypermesh meshed result should be preprocessed
*/
struct Tetra4NoBK{
    array<int, 4> node; //The index number of 4 nodes (node number start with 0)
    int elementNumber; // The index number of the element
};

struct Tetra4Element : public Tetra4NoBK{
    Eigen::Matrix<double, 6, 12> bmat; //B matrix
    Eigen::Matrix<double, 12, 12> kmat; //K matrix
    Tetra4Element(Tetra4NoBK&, Eigen::Matrix<double, 6, 12>&, Eigen::Matrix<double, 12, 12>&);
};

struct Tetra4Result{
    array<int, 4> node;
    int elementNumber;
    array<double, 6> strainVec;
    array<double, 6> stressVec;
    double vonMises;
};

struct Material //Attribute of the material
{
    double modulusE;
    double poissonRatio;
};

struct DisplaceBound //Displacement restriction
{
    int p;
    double u;
    double v;
    double w;
};
#endif