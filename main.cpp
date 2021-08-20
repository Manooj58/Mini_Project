#include <iostream>
#include <string>
#include "Arraystack.h"
#include <math.h>
using namespace std;

int prefixevaluation(string s)
{

    ArrayStack st;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] == ' ')
        {
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9')
        {

            int num = 0;
            int j = i;
            while (s[i] >= '0' && s[i] <= '9')
            {
                i--;
            }
            i++;
            for (int k = i; k <= j; k++)
            {
                num = num * 10 + int((s[k]) - '0');
            }

            st.push(num);
        }
        else
        {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }

    return st.top();
}

int main()
{
    string prefix;
    cout << "Insert Postfix Expression: ";
    getline(std::cin, prefix);
    int evaluated_prefix = prefixevaluation(prefix);
    cout << prefix << ": " << evaluated_prefix << endl;
}