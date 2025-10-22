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
       // std::cout<<"help me I'm MatrixExpression\n";
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
        return A(i,j)+B(i,j); }
    //size_t size() const { return a.size(); }      
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
    //size_t size() const { return a.size(); }      
  };

      template <typename TA, typename TB>
  class MultiMatrixExpr : public MatrixExpr<MultiMatrixExpr<TA,TB>>
  {
    TA A;
    TB B;
  public:
    MultiMatrixExpr (TA _a, TB _b) : A(_a), B(_b) { 
      std::cout<<"MultiMatrixExpr erstellt";
    }
    auto operator() (int i, int j) const { 
      double value = 0;
      for (int k = 0; k< 5; k++){ //////////////////////////////////////////rowsize Problem again
        value+= A(i,k)*B(k, j);
      }

        return value;}
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
    std::cout<<"used * in MatrixExpr with Vektor!!\n";
    return MultiMatrixVecExpr(a.derived(), b.derived());
  }


   template <typename TA, typename TB>
  auto operator* (const MatrixExpr<TA> & a, const MatrixExpr<TB> & b)
  {
    std::cout<<"used * in MatrixExpr with Matrix!!\n";
    return MultiMatrixExpr(a.derived(), b.derived());
  }



////////////////////////////////////find row/column problem here
   template <typename T>
  std::ostream & operator<< (std::ostream & ost, const MatrixExpr<T> & m)
  {
    std::cout << "operator-MatrixExpr\n";
    std::cout<< m(0,0);
   ////////////////////////sizes
     //if (m.row_size() > 0 && m.column_size() >0){
    for (int i = 0; i < 5; i++){
      for(int j = 0; j<5;j++){
        ost << m(i,j) << ", " ;
      }
        ost<< std::endl;
    }
     //   }
      
    return ost;
  }


}