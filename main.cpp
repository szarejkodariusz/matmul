#include <iostream>
#include <time.h>

void matmul_1(const double *A, const double *B, double *C,
              const std::size_t A_rows, const std::size_t A_cols,
              const std::size_t B_rows, const std::size_t B_cols)
{
    if (A_cols != B_rows)
        return;

    for (std::size_t j = 0; j < A_rows; j++)
        for (std::size_t i = 0; i < B_cols; i++)
            for (std::size_t k = 0; k < A_cols; k++)
                C[i + B_cols * j] += A[k + A_cols * j] * B[i + B_cols * k];
}

void matmul_2(const double *A, const double *B, double *C,
              const std::size_t A_rows, const std::size_t A_cols,
              const std::size_t B_rows, const std::size_t B_cols)
{
    if (A_cols != B_rows)
        return;

    for (std::size_t k = 0; k < A_cols; k++)
        for (std::size_t j = 0; j < A_rows; j++)
            for (std::size_t i = 0; i < B_cols; i++)
                C[i + B_cols * j] += A[k + A_cols * j] * B[i + B_cols * k];
}

void matmul_3(const double *A, const double *B, double *C,
              const std::size_t A_rows, const std::size_t A_cols,
              const std::size_t B_rows, const std::size_t B_cols)
{
    if (A_cols != B_rows)
        return;

    for (std::size_t j = 0; j < A_rows; j++)
        for (std::size_t k = 0; k < 3; k++)
            for (std::size_t i = 0; i < B_cols; i++)
                C[i + B_cols * j] += A[k + A_cols * j] * B[i + B_cols * k];
}

int main(int argc, char const *argv[])
{
    std::size_t A_rows = 1 << 17, A_cols = 3;
    std::size_t B_rows = 3, B_cols = 2000;
    double *A = new double[A_rows * A_cols];
    double *B = new double[B_rows * B_cols];
    double *C = new double[A_rows * B_cols];

    printf("Matrix size: %f\n\n", static_cast<double>(A_rows) * static_cast<double>(B_cols) * sizeof(double) / (1 << 20));

    double time_1 = 0.0, time_2 = 0.0, time_3 = 0.0;

    clock_t start = clock();
    matmul_1(A, B, C, A_rows, A_cols, B_rows, B_cols);
    clock_t end = clock();
    time_1 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("matmul_1: %f s\n\n", time_1);

    start = clock();
    matmul_2(A, B, C, A_rows, A_cols, B_rows, B_cols);
    end = clock();
    time_2 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("matmul_2: %f s\n", time_2);
    printf("matmul_2 speedup: %3.2f %% \n\n", (1.0 - time_2 / time_1) * 100.0);

    start = clock();
    matmul_3(A, B, C, A_rows, A_cols, B_rows, B_cols);
    end = clock();
    time_3 = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    printf("matmul_3: %f s\n", time_3);
    printf("matmul_3 speedup: %3.2f %% \n\n", (1.0 - time_3 / time_1) * 100.0);

    delete[] A;
    delete[] B;
    delete[] C;
    return 0;
}
