#include <iostream>

namespace ASC_bla
{
    template <typename T>
    class Matrix
  {
    int  row_size;
    int  column_size;
    T * data;
    public:
        Matrix (int row_size, int column_size) 
        : row_size(row_size), column_size(column_size), data(new T[row_size*column_size]) { 
          std::cout << "constructed matrix with row_size " << row_size << " and column_size " <<column_size <<std::endl;
          ; }
        void set_value(int i, int j, T value){
          data[i*column_size + j] = value;
        }

        Matrix<T> transpose(){
          Matrix<T> transposed(column_size,row_size);
          for(int i = 0; i< row_size; i++){
            for(int j=0; j<column_size; j++){
              transposed.set_value(j,i,data[i*column_size + j]);
            }
          }
          return transposed;
        }
        int Row_size() const { return row_size; }
        int Column_size() const{ return column_size;}
        T & operator()(int i, int j) { return data[i*column_size + j]; }
        const T & operator()(int i, int j) const { return data[i*column_size + j];}
  };

  template <typename T>
  Matrix<T> operator* (const Matrix<T> & A, const Matrix<T> & B)
  {
    Matrix<T> multiplied(A.Row_size(), B.Column_size());
    for (int i = 0; i < A.Row_size(); i++){
      for(int j = 0; j< B.Column_size(); j++){
        double element = 0;
        for(int k= 0; k<A.Column_size(); k++){
          element+= A(i,k)*B(k,j);
        }
        multiplied.set_value(i,j, element);
      }
    }
    return multiplied;
  }


   template <typename T>
  Vector<T> operator* (const Matrix<T> & A, const Vector<T> & b)
  {
    Vector<T> multiplied(A.Row_size());
    for(int i = 0; i<A.Row_size(); i++){
      T sum = 0;
      for(int k = 0; k<A.Column_size(); k++){
        sum += A(i,k)*b(k);
      }
      multiplied(i) = sum;
    }

    return multiplied;

  }



template <typename T>
  std::ostream & operator<< (std::ostream & ost, const Matrix<T> & m)
  {
    if (m.Row_size() > 0 && m.Column_size() >0){
    for (int i = 0; i < m.Row_size(); i++){
      for(int j = 0; j<m.Column_size();j++){
        ost << m(i,j) << ", " ;
      }
        ost<< std::endl;

    }
        }
      
    return ost;
  }
  
}