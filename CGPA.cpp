#include <iostream>
using namespace std;

// Cgpa calculator

double cgpa_calc(double arr[], int n)
{
    double grade[n], sum = 0, cgpa;

    for (int i = 0; i < n; i++)
    {
        grade[i] = (arr[i] / 10);
    }

    for (int i = 0; i < n; i++)
    {
        sum += grade[i];
    }
    cout << "the sum is " << sum << endl;

    cgpa = sum / n;
    return cgpa;
}

int main()
{

    int n = 5;
    double marks[] = {80, 90, 80, 90, 70};
    double cgpa = cgpa_calc(marks, n);

    cout << "CGPA = ";
    printf("%.1f\n", cgpa);
    cout << "CGPA Percentage = ";
    printf("%.2f", cgpa * 9.5);

    return 0;
}