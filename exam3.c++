#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Term
{
    double coef;
    int expon;
};

struct Polynomial
{
    vector<Term> terms;
};

Polynomial calculateDifference(const Polynomial &A, const Polynomial &B)
{
    Polynomial result;
    int i = 0, j = 0;

    while (i < A.terms.size() || j < B.terms.size())
    {
        Term term;

        if (i < A.terms.size() && (j >= B.terms.size() || A.terms[i].expon > B.terms[j].expon))
        {
            term.coef = A.terms[i].coef;
            term.expon = A.terms[i].expon;
            i++;
        }
        else if (j < B.terms.size() && (i >= A.terms.size() || B.terms[j].expon > A.terms[i].expon))
        {
            term.coef = -B.terms[j].coef; // Subtract B's term
            term.expon = B.terms[j].expon;
            j++;
        }
        else
        {
            term.coef = A.terms[i].coef - B.terms[j].coef;
            term.expon = A.terms[i].expon;
            i++;
            j++;
        }

        result.terms.push_back(term);
    }

    return result;
}

double evaluatePolynomial(const Polynomial &poly, double x)
{
    double result = 0.0;
    for (const Term &term : poly.terms)
    {
        result += term.coef * pow(x, term.expon);
    }
    return result;
}

double bisection(const Polynomial &poly, double a, double b, double TOL)
{
    if (a < b && evaluatePolynomial(poly, a) * evaluatePolynomial(poly, b) >= 0)
    {
        cout << "Error: " << endl;
        return 0.0;
    }

    double c;
    while ((b - a) > TOL)
    {
        c = (a + b) / 2;
        double fc = evaluatePolynomial(poly, c);
        if (fc == 0)
        {
            return c;
        }
        else if (evaluatePolynomial(poly, a) * fc > 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    }
    return c;
}

int main()
{
    Polynomial A, B;
    A.terms = {{1, 2}, {15, 0}, {-1, -1}};
    B.terms = {{10, 1}, {-1, -1}};
    
    Polynomial D = calculateDifference(A, B);
    double a = 5;
    double b = 100;
    double TOL = 0.1;

    double root = bisection(D, a, b, TOL);

    cout << "다항식 D의 해: " << root << endl;

    return 0;
}