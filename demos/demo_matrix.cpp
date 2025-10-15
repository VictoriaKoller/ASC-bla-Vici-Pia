#include <iostream>

#include <vector.hpp>
#include <matrix.hpp>

namespace bla = ASC_bla;


int main()
{
  size_t n = 5;
  bla::Vector<double> x(n), y(n);
  bla::Matrix<double> A(n,n);
  bla::Matrix<double> B(n,n);

  for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
      A.set_value(i,j,i*j);
      B.set_value(i,j,-i*j+i);

    }
  }

  std::cout<<A;
  std::cout<<B;
  std::cout<<B.transpose();
  bla::Matrix<double> M = A*B;
  std::cout<<M;
  for (size_t i = 0; i < x.Size(); i++)
    {
      x(i) = i;
      y(i) = 10;
    }

  bla::Vector<double> z = x+y;
  
  std::cout << "x+y = " << z << std::endl;
  std::cout<<x <<std::endl;
  std::cout<< A*x;
}
