#include <iostream>
#include <cmath> // for mathematical operations
using namespace std;

// scientific calculator
// overall time complexity of the program is O(1)

// void showmenu()    // to display the options menu
// {
//     cout << "\n\t\t Scientific Calculator"<<endl;
//     cout << "\n\tMenu:";
//     cout << "\n\t\t1. Addition, ";
//     cout << "\n\t\t2. Subtraction";
//     cout << "\n\t\t3. Multiplication";
//     cout << "\n\t\t4. Division";
//     cout << "\n\t\t5. Sine(sin)";
//     cout << "\n\t\t6. Cosine(cos)";
//     cout << "\n\t\t7. Tangent(tan)";
//     cout << "\n\t\t8. Exponentiation";
//     cout << "\n\t\t9. Logarithm (base 10)";
//     cout << "\n\t\t10. Natural Logarithm (ln)";
//     cout << "\n\t\t11. Power";
//     cout << "\n\t\t12. Square Root";
//     cout << "\n\t\t0. Exit\n";

//     // time complexity : O(1)
// }

// we can also define it in a class and out side it

class oper // for calculations, defining all functions inside a clas
{

 // the overall complexity remains the same -> time complexity : O(1)
    
public:
    void showmenu() // to display the options menu
    {
        cout << "\n\t\t Scientific Calculator" << endl;
        cout << "\n\tMenu:";
        cout << "\n\t\t1. Addition, ";
        cout << "\n\t\t2. Subtraction";
        cout << "\n\t\t3. Multiplication";
        cout << "\n\t\t4. Division";
        cout << "\n\t\t5. Sine(sin)";
        cout << "\n\t\t6. Cosine(cos)";
        cout << "\n\t\t7. Tangent(tan)";
        cout << "\n\t\t8. Exponentiation";
        cout << "\n\t\t9. Logarithm (base 10)";
        cout << "\n\t\t10. Natural Logarithm (ln)";
        cout << "\n\t\t11. Power";
        cout << "\n\t\t12. Square Root";
        cout << "\n\t\t0. Exit\n";

        // time complexity : O(1)
    }

    double add(double a, double b)
    {
        return a + b;
    }
    double sub(double a, double b)
    {
        return a - b;
    }
    double multiply(double a, double b)
    {
        return a * b;
    }
    double divide(double a, double b)
    {
        if (b == 0)
        {
            cout << "Error! Division by 0, You Moron" << endl;
            return NAN;
        }
        return a / b;
    }
    double sine(double angle)
    {
        return sin(angle);
    }
    double cosine(double angle)
    {
        return cos(angle);
    }
    double tangent(double angle)
    {
        return tan(angle);
    }
    double expo(double base, double exponent)
    {
        return pow(base, exponent);
    }
    double logarithm(double value)
    {
        if (value <= 0)
        {
            cout << "Error!   Log of non-positive number, You Moron" << endl;
            return NAN;
        }
        return log10(value);
    }
    double naturalLog(double value)
    {
        if (value <= 0)
        {
            cout << "Error!   Log of non-positive number, You Moron" << endl;
            return NAN;
        }
        return log(value);
    }
    double power(double base, double exponent)
    {
        return pow(base, exponent);
    }
    double squareroot(double value)
    {
        if (value < 0)
        {
            cout << "Error! Square Root of negative number " << endl;
            return NAN;
        }
        return sqrt(value);
    }
};

int main()
{
    oper calc;
    int choice; // time complexity : O(1)
    double num1, num2;
    while (true)
    {
        // showmenu();
        calc.showmenu(); // define like this after defining in class
        cout << "Enter your choice [0-12] : ";
        cin >> choice;

        if (choice == 0)
        {
            break;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter two numnbers ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.add(num1, num2) << endl;
            break;

        case 2:
            cout << "Enter two numnbers ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.sub(num1, num2) << endl;
            break;

        case 3:
            cout << "Enter two numnbers ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.multiply(num1, num2) << endl;
            break;

        case 4:
            cout << "Enter two numnbers ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.divide(num1, num2) << endl;
            break;

        case 5:
            cout << "Enter angle [in radians]: ";
            cin >> num1;
            cout << "Result: " << calc.sine(num1) << endl;
            break;

        case 6:
            cout << "Enter angle [in radians]: ";
            cin >> num1;
            cout << "Result: " << calc.cosine(num1) << endl;
            break;

        case 7:
            cout << "Enter angle [in radians]: ";
            cin >> num1;
            cout << "Result: " << calc.tangent(num1) << endl;
            break;

        case 8:
            cout << "Enter two numnbers ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.expo(num1, num2) << endl;
            break;

        case 9:
            cout << "Enter a number ";
            cin >> num1;
            cout << "Result: " << calc.logarithm(num1) << endl;
            break;
        case 10:
            cout << "Enter a number ";
            cin >> num1;
            cout << "Result: " << calc.naturalLog(num1) << endl;
            break;

        case 11:
            cout << "Enter base and exponent ";
            cin >> num1 >> num2;
            cout << "Result: " << calc.power(num1, num2) << endl;
            break;

        case 12:
            cout << "Enter a number ";
            cin >> num1;
            cout << "Result: " << calc.squareroot(num1) << endl;
            break;

        default:
            cout << "Invalid choice, try again.\n";
            break;
        }
    }

    return 0;
}