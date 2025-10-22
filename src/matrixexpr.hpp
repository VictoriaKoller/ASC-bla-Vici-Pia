#include <cassert>
namespace ASC_bla{

  template <typename T>
    class MatrixExpr{
     public:
      auto derived() const { return static_cast<const T&> (*this); }
      int rowww() const { return 5; }
      int columnnn() const { return 5; }
      int dist() const { return this->dist(); }

      auto operator() (int i, int j) const {
         return derived()(i, j); }

  };


   template <typename TA, typename TB>
  class SumMatrixExpr : public MatrixExpr<SumMatrixExpr<TA,TB>>
  {
    TA A;
    TB B;
  public:
    SumMatrixExpr (TA _a, TB _b) : A(_a), B(_b) {
     }
    auto operator() (int i, int j) const { 
        return A(i,j)+B(i,j); }
    int row_size() const { return  A.Rows(); }      
    int column_size() const { return  A.Columns(); }      

  };


    template <typename TA, typename TB>
  class MultiMatrixVecExpr : public VecExpr<MultiMatrixVecExpr<TA,TB>>
  {
    TA A;
    TB b;
  public:
    MultiMatrixVecExpr (TA _a, TB _b) : A(_a), b(_b) { 
    }
    auto operator() (int i) const { 
      double value = 0;
      for (int j = 0; j<b.size(); j++){
        value+= A(i,j)*b(j);
      }

        return value;}
    int size() const { return b.size(); }      
  };

      template <typename TA, typename TB>
  class MultiMatrixExpr : public MatrixExpr<MultiMatrixExpr<TA,TB>>
  {
    TA A;
    TB B;
  public:
    MultiMatrixExpr (TA _a, TB _b) : A(_a), B(_b) { 
    }
    auto operator() (int i, int j) const { 
      double value = 0;
      for (int k = 0; k< row_size(); k++){ 
        value+= A(i,k)*B(k, j);
      }

        return value;}
        int row_size() const { return  A.Rows(); }      
    int column_size() const { return  A.Columns(); }   
  };



   template <typename TA, typename TB>
  auto operator+ (const MatrixExpr<TA> & a, const MatrixExpr<TB> & b)
  {
    //assert (a.column_size() == b.column_size());
    //assert (a.row_size() == b.row_size());
    return SumMatrixExpr(a.derived(), b.derived());
  }

  template <typename TA, typename TB>
  auto operator* (const MatrixExpr<TA> & a, const VecExpr<TB> & b)
  {
    return MultiMatrixVecExpr(a.derived(), b.derived());
  }


   template <typename TA, typename TB>
  auto operator* (const MatrixExpr<TA> & a, const MatrixExpr<TB> & b)
  {
    return MultiMatrixExpr(a.derived(), b.derived());
  }



////////////////////////////////////find row/column problem here
   template <typename T>
  std::ostream & operator<< (std::ostream & ost, const MatrixExpr<T> & m)
  {
    std::cout << "operator-MatrixExpr\n";
  
     if (m.rowww() > 0 && m.columnnn() >0){
    for (int i = 0; i < m.rowww(); i++){
      for(int j = 0; j<m.columnnn();j++){
        ost << m(i,j) << ", " ;
      }
        ost<< std::endl;
    }
        }
      
    return ost;
  }


}