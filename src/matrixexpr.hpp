#include <cassert>
namespace ASC_bla{

  template <typename T>
    class MatrixExpr{
     public:
    auto derived() const { return static_cast<const T&> (*this); }
    int row_size() const { return derived().row_size(); }
    int column_size() const { return derived().column_size(); }
    int dist() const { return derived().dist(); }

    auto operator() (size_t i) const { return derived()(i); }

  };


   template <typename TA, typename TB>
  class SumMatrixExpr : public MatrixExpr<SumMatrixExpr<TA,TB>>
  {
    TA A;
    TB B;
  public:
    SumMatrixExpr (TA _a, TB _b) : A(_a), B(_b) { }
    auto operator() (size_t i, size_t j) const { 
        std::cout<<"used SumMatrixExpression!!";
        return A(i,j)+B(i,j); }
    //size_t size() const { return a.size(); }      
  };


}