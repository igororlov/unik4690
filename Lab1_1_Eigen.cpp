#include "Eigen/Eigen"
#include <iostream>

int main()
{
  Eigen::Vector3d t;
  t << 1.0, 0.0, 3.0;
  std::cout << "Vector t:\n" << t << std::endl;

  Eigen::Matrix3d A;
  A << 1.0, 0.0, 3.0,
       4.0, 5.0, 6.0,
       7.0, 8.0, 9.0;
  std::cout << "Matrix A:\n" << A << std::endl;

  Eigen::Matrix3d I = Eigen::Matrix3d::Identity();
  std::cout << "Matrix I:\n" << I << std::endl;

  Eigen::Matrix4d T;
  T.fill(0);
  T.block(0,0,3,3) = A;
  T.topRightCorner(3,1) = t;
  T(3,3) = 1.0;
  std::cout << "Matrix T:\n" << T << std::endl;

  std::cout << "Matrix A transposed:\n" << A.transpose() << std::endl;


}
