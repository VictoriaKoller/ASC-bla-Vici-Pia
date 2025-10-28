#include <iostream>
#include <matrixexpr.hpp>
namespace ASC_bla
{
  enum ORDERING { ColMajor, RowMajor };


  template <typename T, ORDERING ORD> 
  class MatrixView: public MatrixExpr<MatrixView<T, ORD>>{
    protected:
      int row_size, column_size, dist;
      T * data;
      public:
        MatrixView()=default;
        MatrixView(int row_size, int column_size, int dist)
        : row_size(row_size), column_size(column_size), dist(dist), data(new T[row_size*column_size]){
          dist = 1;
          ;
        }
      template<typename TDIST2>
      MatrixView(const MatrixView<T, ORD>& m2)
      : data(m2.data()), row_size(m2.Rows()), column_size(m2.Cols()), dist(m2.Dist()) { }


        //matrix view
      template <typename TB>
      MatrixView& operator= (const MatrixExpr<TB> & m2)
      {
        assert (row_size == m2.row_size());
        assert (column_size == m2.column_size());

        for (size_t i = 0; i < row_size; i++){
            for(size_t j=0; j<column_size; j++){
            data[dist*i + j] = m2(i, j);
            }
        }
        return *this;
      }

      // T * data() const { return data; }
      int Cols() const { return column_size; }
      int Rows() const { return row_size; }

      auto Dist() const { return dist; }
      const T & operator()(int i, int j) const { return data[i*column_size + j];}

  };


    template <typename T>
    class Matrix :public MatrixView <T, ColMajor>
  {
    typedef MatrixView <T, ColMajor> BASE;
    using BASE::row_size;
    using BASE::column_size;
    using BASE::dist;
    using BASE::data;
    //int  row_size;
    //int  column_size;
    public:
        // Matrix (int row_size, int column_size) 
        // { 
        //   this->row_size = row_size;
        //   this->column_size = column_size;
        //   this->data = new T[row_size*column_size];
        //   //row_size(row_size), column_size(column_size), data(new T[row_size*column_size])
          
        //   std::cout << "constructed matrix with row_size " << row_size << " and column_size " <<column_size <<std::endl;
        //   ; }
        void set_value(int i, int j, T value){
          data[i*column_size + j] = value;
        }

        Matrix(int rows, int cols)
        : MatrixView<T, ColMajor>(rows, cols, 1){ }

        Matrix<T> transpose(){
          Matrix<T> transposed(column_size,row_size);
          for(int i = 0; i< row_size; i++){
            for(int j=0; j<column_size; j++){
              transposed.set_value(j,i,data[i*column_size + j]);
            }
          }
          return transposed;
        }
        int get_row_size() const { return row_size; }
        int get_column_size() const{ return column_size;}
        T & operator()(int i, int j) { return data[i*column_size + j]; }
        const T & operator()(int i, int j) const { return data[i*column_size + j];}

        using BASE::operator=;

  };

  // template <typename T>
  // Matrix<T> operator* (const Matrix<T> & A, const Matrix<T> & B)
  // {
  //   Matrix<T> multiplied(A.get_row_size(), B.get_column_size());
  //   for (int i = 0; i < A.get_row_size(); i++){
  //     for(int j = 0; j< B.get_column_size(); j++){
  //       double element = 0;
  //       for(int k= 0; k<A.get_column_size(); k++){
  //         element+= A(i,k)*B(k,j);
  //       }
  //       multiplied.set_value(i,j, element);
  //     }
  //   }
  //   return multiplied;
  // }


  //  template <typename T>
  // Vector<T> operator* (const Matrix<T> & A, const Vector<T> & b)
  // {
  //   Vector<T> multiplied(A.get_row_size());
  //   for(int i = 0; i<A.get_row_size(); i++){
  //     T sum = 0;
  //     for(int k = 0; k<A.get_column_size(); k++){
  //       sum += A(i,k)*b(k);
  //     }
  //     multiplied(i) = sum;
  //   }

  //   return multiplied;

  // }



template <typename T>
  std::ostream & operator<< (std::ostream & ost, const MatrixView<T, ColMajor > & m)
  {
    std::cout<<"operator<<in MatrixView\n";
    if (m.Rows() > 0 && m.Cols() >0){
    for (int i = 0; i < m.Rows(); i++){
      for(int j = 0; j<m.Cols();j++){
        ost << m(i,j) << ", " ;
      }
        ost<< std::endl;

    }
        }
      
    return ost;
  }







  
}