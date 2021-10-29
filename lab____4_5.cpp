// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>
using namespace std;
double P0(const int N)
{
    double P = 1;
    for (int K = N; K <= 19; K++)
        P *= (((1. * K - 1. * N) / (1. * K + 1. * N)) + 1);
    return P;
}
double P1(const int N, const int K)
{
    if (K > 19)
        return 1;
    else
        return (((1. * K - 1. * N) / (1. * K + 1. * N)) + 1) * P1(N, K + 1);
}
double P2(const int N, const int K)
{
    if (K < N)
        return 1;
    else
        return (((1. * K - 1. * N) / (1. * K + 1. * N)) + 1) * P2(N, K - 1);
}
double P3(const int N, const int K, double t)
{
    t = t * (((1. * K - 1. * N) / (1. * K + 1. * N)) + 1);
    if (K >= 19)
        return t;
    else
        return P3(N, K + 1, t);
}
double P4(const int N, const int K, double t)
{
    t = t * (((1. * K - 1. * N) / (1. * K + 1. * N)) + 1);
    if (K <= N)
        return t;
    else
        return P4(N, K - 1, t);
}
int main()
{
    int N;
    cout << "N = "; cin >> N;
    cout << "(iter) P0 = " << P0(N) << endl;
    cout << "(rec up ++) P1 = " << P1(N, N) << endl;
    cout << "(rec up --) P2 = " << P2(N, 19) << endl;
    cout << "(rec down ++) P3 = " << P3(N, N, 1) << endl;
    cout << "(rec down --) P4 = " << P4(N, 19, 1) << endl;

    return 0;
}
