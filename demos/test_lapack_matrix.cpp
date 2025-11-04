#include <chrono>
#include <iostream>

#include <lapack_interface.hpp>
namespace bla = ASC_bla;


int main()
{
    ASC_bla::MatrixView<double, ASC_bla::ORDERING::ColMajor> a;
    ASC_bla::MatrixView<double, ASC_bla::ORDERING::ColMajor> b;
    ASC_bla::MatrixView<double, ASC_bla::ORDERING::ColMajor> c;
int n = 5;
size_t flops = n*n*n;
size_t runs = size_t (1e9 / flops) + 1;

auto start = std::chrono::high_resolution_clock::now();
for(size_t i = 0; i < runs; i++){
multMatMatLapack(a,b,c);
}
auto end = std::chrono::high_resolution_clock::now();
double time = std::chrono::duration<double>(end-start).count();
        
std::cout << "n = " << n << ", time = " << time << " s, GFlops = " 
     << (flops*runs)/time*1e-9 << '\n';

}
