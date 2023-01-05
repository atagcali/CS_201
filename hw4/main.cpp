
#include <iostream>
#include "AlgebraicExpression.h"

using namespace std;
// It converts an infix expression exp to its equivalent prefix form.
string infix2prefix(const string exp);
// It converts an infix expression exp to its equivalent postfix form.
string infix2postfix(const string exp);
// It converts a prefix expression exp to its equivalent infix form.
string prefix2infix(const string exp);
// It converts a prefix expression exp to its equivalent postfix form.
string prefix2postfix(const string exp);
// It converts a postfix expression exp to its equivalent infix form.
string postfix2infix(const string exp);
// It converts a postfix expression exp to its equivalent prefix form.
string postfix2prefix(const string exp);
//It evaluates an infix expression.
double evaluateInfix(const string exp);
//It evaluates a prefix expression.
double evaluatePrefix(const string exp);
//It evaluates a postfix expression.
double evaluatePostfix(const string exp);

double evaluateInfix(const string exp) {
    AlgebraicExpression a;
    return a.evaluateInfix(exp);
}

double evaluatePrefix(const string exp) {
    AlgebraicExpression a;
    return a.evaluatePrefix(exp);
}

double evaluatePostfix(const string exp) {
    AlgebraicExpression a;
    return a.evaluatePostfix(exp);
}

string infix2prefix(const string exp) {
    AlgebraicExpression a;
    return a.toprefix(exp);
}

string infix2postfix(const string exp) {
    AlgebraicExpression a;
    return a.topostfix(exp);
}

string prefix2infix(const string exp) {
    AlgebraicExpression a;
    return a.toinfix(exp);
}

string prefix2postfix(const string exp) {
    AlgebraicExpression a;
    return a.topostfix(exp);
}

string postfix2infix(const string exp) {
    AlgebraicExpression a;
    return a.toinfix(exp);
}

string postfix2prefix(const string exp) {
    AlgebraicExpression a;
    return a.toprefix(exp);
}



int main() {
    cout << infix2prefix("( 12 + 5 ) - 20 * 4") << endl;
    cout << infix2postfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << evaluateInfix("( 12 + 5 ) - 20 * 4") << endl;
    cout << prefix2infix("* + * 100 2 4 - 12 4") << endl;
    cout << prefix2postfix("* + * 100 2 4 - 12 4") << endl;
    cout << evaluatePrefix("* + * 100 2 4 - 12 4") << endl;
    cout << postfix2infix("100 12 2 - 8 * + 4 /") << endl;
    cout << postfix2prefix("100 12 2 - 8 * + 4 /") << endl;
    cout << evaluatePostfix("100 12 2 - 8 * + 4 /") << endl;
    return 0;
}


