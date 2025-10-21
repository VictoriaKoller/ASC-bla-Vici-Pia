#include <cassert>
namespace ASC_bla{

  template <typename T>
    class MatrixExpr{
     public:
      auto derived() const { return static_cast<const T&> (*this); }
      int row_size() const { return this->row_size(); }
      int column_size() const { return this->column_size(); }
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
    SumMatrixExpr (TA _a, TB _b) : A(_a), B(_b) { }
    auto operator() (int i, int j) const { 
        std::cout<<"used SumMatrixExpression!!";
        return A(i,j)+B(i,j); }
    //size_t size() const { return a.size(); }      
  };
   template <typename TA, typename TB>
  auto operator+ (const MatrixExpr<TA> & a, const MatrixExpr<TB> & b)
  {
    std::cout<<"used + in MatrixExpr!!";

    assert (a.column_size() == b.column_size());
    assert (a.row_size() == b.row_size());

    return SumMatrixExpr(a.derived(), b.derived());
  }

   template <typename T>
  std::ostream & operator<< (std::ostream & ost, const MatrixExpr<T> & m)
  {
     if (m.row_size() > 0 && m.column_size() >0){
    for (int i = 0; i < m.row_size(); i++){
      for(int j = 0; j<m.column_size();j++){
        ost << m(i,j) << ", " ;
      }
        ost<< std::endl;

    }
        }
      
    return ost;
  }


}