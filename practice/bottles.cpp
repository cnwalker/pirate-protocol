#include <iostream>
#include <string>
#include <math>

using namespace std;

int accept_numbers()
{
    int order, increment;
    double x_low, x_high;

    cin << order;
    double polynomial[order + 2];

    for(int i = 0; i < order; i++)
    {
        cin >> polynomial[i];
    }

    double volume = M_PI * integrate(polynomial, order, x_low);
    return 0;
}

double integrate(double *polynomial, int order, double x_low)
{
    double c = 0;
    for(int i = order + 1; i > 0; i--)
    {
        polynomial[i] = polynomial[i - 1]/i;
        c -= polynomial[i]*pow(x_low, i);
    }

    poly[0] = c;
    return 0;
}

int main()
{
    while(!cin.eof())
    {
        accept_numbers();
    }
    return 0;
}
