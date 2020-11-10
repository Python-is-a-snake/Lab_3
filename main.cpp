#include <iostream>
using namespace std;

double equation(double x){
    return x * x - 7 * x + 12;
}

double FindRoot(double (*f)(double), double a, double b, double eps){
    double c;
    while((b-a)/2>eps){
        c=(a+b)/2;
        if((f(a) * f(c)) > 0) a = c;
        else b = c;
    }
    return c;
}

int task_10(){
    double a, b, eps, x;
    cout << "Interval: " << endl;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;

    cout << "Enter epsilon: ";
    cin >> eps;

    x=FindRoot(equation, a, b, eps);
    cout << "x = " << x << endl;
    return 0;
}

//////////////////////   TASK 2   /////////////////////

double Func(double x)
{
    double f;
    f = sin(x) + cos(x);
    return f;
}

int task_19(){
    long int N = 10000;
    double S = 0, x, a, b, h;
    const double Pi = 3.14159;
    a = 0;
    b = Pi;
    //the segment [a, b] is divided into N parts
    h = (b - a)/N;
    x = a + h;
    while (x < b)
    {
        S = S + 4 * Func(x);
        x = x + h;
        //check if the value x is out of the half-interval [a, b]
        if (x >= b)
            break;

        S = S + 2*Func(x);
        x = x + h;
    }
    S = (h/3)*(S + Func(a) + Func(b));
    cout << S;
    return 0;
}

int main(){
        task_10();
        task_19();
    return 0;
}
