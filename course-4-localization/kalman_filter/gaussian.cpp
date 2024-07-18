#include <iostream>
#include <math.h>


double gaussian_pdf(double mu, double sigma2, double x)
{
    //Use mu, sigma2 (sigma squared), and x to code the 1-dimensional Gaussian
    //Put your code here
    double prob = 1/(sqrt(2*M_PI*sigma2)) * exp(-0.5*(pow(x-mu, 2.0)/sigma2));
    return prob;
}

int main()
{
    std::cout << gaussian_pdf(10.0, 4.0, 8.0) << std::endl;
    return 0;
}