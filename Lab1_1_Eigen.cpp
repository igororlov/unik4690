#include "Eigen/Eigen"
#include <iostream>

int main()
{
  // Page 1
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

  // Page 2
  t(1) = 2.0;
  std::cout << "Updated vector t:\n" << t << std::endl;

  A(0,1) = 2.0;
  std::cout << "Updated matrix A:\n" << A << std::endl;

  Eigen::RowVector3d row1 = A.row(1);
  std::cout << "A.row(1):\n" << row1 << std::endl;

  Eigen::Vector3d col1 = A.col(1);
  std::cout << "A.col(1):\n" << col1 << std::endl;

  Eigen::Matrix2d block = T.block(1,1,2,2);
  std::cout << "T.block(1,1,2,2):\n" << block << std::endl;

  block(0,0) = -1.0;
  std::cout << "Block after change:\n" << block << std::endl;
  std::cout << "T.block(1,1,2,2) after change:\n" << T.block(1,1,2,2) << std::endl;
  // Summary - Eigen copies value, not reference. Original matrix is not changed.

  // Page 3
  std::cout << "T.block(1,1,2,2) + Block:\n" << T.block(1,1,2,2) + block << std::endl;

  // TODO add more here
  // http://www.uio.no/studier/emner/matnat/its/UNIK4690/v17/lab/lab_1/lab_1_kamerageometri-med-eigen.pdf
}
