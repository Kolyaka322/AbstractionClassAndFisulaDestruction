#include <iostream>
#include <cmath>
#include <iomanip>

class Equation {
public:
    virtual ~Equation() = default;
    virtual void Roots() const = 0;
};

class LinearEquation : public Equation {
private:
    double a;
    double b;

public:
    LinearEquation(double a, double b) : a(a), b(b) {}

    void Roots() const override {
        std::cout << "Лінійне рівняння: " << a << "x + " << b << " = 0\n";
        if (std::abs(a) < 1e-12) {
            if (std::abs(b) < 1e-12) {
                std::cout << "Безліч розв'язків\n";
            }
            else {
                std::cout << "Коренів немає\n";
            }
        }
        else {
            double x = -b / a;
            std::cout << "x = " << x << "\n";
        }
    }
};

class QuadraticEquation : public Equation {
private:
    double a;
    double b;
    double c;

public:
    QuadraticEquation(double a, double b, double c) : a(a), b(b), c(c) {}

    void Roots() const override {
        std::cout << "Квадратне рівняння: " << a << "x^2 + " << b << "x + " << c << " = 0\n";
        if (std::abs(a) < 1e-12) {
            LinearEquation lin(b, c);
            lin.Roots();
            return;
        }

        double d = b * b - 4.0 * a * c;
        if (d < -1e-12) {
            std::cout << "Дійсних коренів немає\n";
        }
        else if (std::abs(d) <= 1e-12) {
            double x = -b / (2.0 * a);
            std::cout << "x1 = x2 = " << x << "\n";
        }
        else {
            double sqrtD = std::sqrt(d);
            double x1 = (-b - sqrtD) / (2.0 * a);
            double x2 = (-b + sqrtD) / (2.0 * a);
            std::cout << "x1 = " << x1 << ", x2 = " << x2 << "\n";
        }
    }
};

int main() {
    system("chcp 1251>null");
    Equation* eqs[] = {
        new LinearEquation(2.0, -6.0),
        new LinearEquation(0.0, 5.0),
        new QuadraticEquation(1.0, -5.0, 6.0),
        new QuadraticEquation(1.0, 2.0, 1.0),
        new QuadraticEquation(1.0, 1.0, 5.0)
    };

    for (const Equation* eq : eqs) {
        eq->Roots();
        std::cout << "-------------------------\n";
    }

    for (Equation* eq : eqs) {
        delete eq;
    }

    return 0;
}
