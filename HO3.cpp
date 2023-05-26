#include <iostream>
#include <math.h>
using namespace std;

void calcular_regresion_cuadratica(float x[], float y[], float  n, float &a, float &b, float  &c) {
    float sum_x = 0.0, sum_y = 0.0, sum_x2 = 0.0, sum_x3 = 0.0, sum_x4 = 0.0, sum_xy = 0.0, sum_x2y = 0.0;

    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
        sum_xy += x[i] * y[i];
        sum_x2y += x[i] * x[i] * y[i];
    }

    cout <<"--- Listado de las Sumatorias ---"<<endl;
    cout <<"  sum_x: "<<sum_x<<endl;
    cout <<"  sum_y: "<<sum_y<<endl;
    cout <<" sum_x2: "<<sum_x2<<endl;
    cout <<"  sum_3: "<<sum_x3<<endl;
    cout <<" sum_x4: "<<sum_x4<<endl;
    cout <<" sum_xy: "<<sum_xy<<endl;
    cout <<"sum_x2y: "<<sum_x2y<<endl;
    cout <<"\t--- END ---\n"<<endl;

    float denom = ((sum_x2*sum_x2*sum_x2)+(sum_x*sum_x*sum_x4)+(n*sum_x3*sum_x3))-((n*sum_x2*sum_x4)+(sum_x*sum_x3*sum_x2)+(sum_x2*sum_x*sum_x3));

    a = (((sum_y*sum_x2*sum_x2)+(sum_x*sum_x*sum_x2y)+(n*sum_xy*sum_x3))-((n*sum_x2*sum_x2y)+(sum_x*sum_x3*sum_y)+(sum_x2*sum_x*sum_xy)))/denom;
    b = ((sum_x2 * sum_xy * sum_x2) + (sum_y * sum_x * sum_x4) + (n * sum_x3 * sum_x2y) - (n * sum_xy * sum_x4) - (sum_x2 * sum_x * sum_x2y) - (sum_y * sum_x3 * sum_x2))/denom;
    c = (((sum_x2*sum_x2*sum_x2y)+(sum_x*sum_xy*sum_x4)+(sum_y*sum_x3*sum_x3))-((sum_y*sum_x2*sum_x4)+(sum_xy*sum_x3*sum_x2)+(sum_x2y*sum_x*sum_x3)))/denom;
    
    cout <<"--- Valor de las Variable ---"<<endl;
    cout <<"Delta: "<<denom<<endl;
    cout <<"A: "<<a<<endl;
    cout <<"B: "<<b<<endl;
    cout <<"C: "<<c<<endl;
    cout <<"\t--- END ---\n"<<endl;
}


int main() {
    // DataSet Problem
    float x[] = {-3,-2,-1,0,1,2,3};
    float  y[] = {7.5,3,0.5,1,3,6,14};

    // DataSet Test = 0.96  length: 4  !source: no remember _-_
    //float x[] = {0,1,2,3};
    //float y[] = {1,3,2,0};

    // DataSet Test 2 = 0.972619    length: 13  !source: https://cs.franklin.edu/~sieberth/MATH160/bookFiles/Chapter3/333371_0307_317-323.pdf
    //float x[]= {15,20,25,30,35,40,45,50,55,60,65,70,75};
    //float y[]= {22.3,25.5,27.5,29.0,28.8,30.0,29.9,30.2,30.4,28.8,27.4,25.3,23.3};
    
    float SSE = 0, SST = 0, hat_y = 0, maybeR;

    // Remember change this for each case, is the length
    int n = 7;
    float a, b, c,input,result;

    calcular_regresion_cuadratica(x, y, n, a, b, c);

    // Sumatoria y hat
    for (int i = 0; i < n; i++)
    {
        hat_y += y[i];
    }

    hat_y = hat_y / n;

    float prom = hat_y;


    for (int i = 0; i < n; i++)
    {
        result = a * (x[i] * x[i]) + b * (x[i]) + c;

        SSE += pow(y[i] - a * pow(x[i],2) - b * x[i] - c,2);
        
        SST += pow((y[i] - hat_y),2);
    }

    // Calcule of R2
    maybeR = 1 - (SSE / SST);

    cout <<"\t--- Resultados ---"<<endl;
    cout << "La ecuacion de la regresion cuadratica es: Y = " << a << "X^2 + " << b << "X + " << c << endl;
    cout << "R2: " << maybeR <<endl;
    
    cout << "Ingrese valor de X: ";
    cin >> input;
    maybeR = a*(input*input)+b*(input)+c;
    cout << "El mejor valor de Y encontrado para el valor de X propuesto es: "<<result<<endl;
    
    cout <<"\t--- END ---\n"<<endl;
    
    system("pause");
}