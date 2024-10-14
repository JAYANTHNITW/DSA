// Infix to postfix and evlaution using stack data structure
#include<iostream>
using namespace std;
#define MAXS 30
#include <cstring>
#include <cmath> 


class CharStack
{
    private:
        char *S; // character pointer
		char arr[MAXS];// array intalized with MAXS size of 30
        int topIndex;
        int size;

    public:
        CharStack(){
            topIndex = -1;
            S = arr; // intialization of pointer
            size = MAXS;
        }

        int count() {
            return (topIndex + 1);
        }

        bool isFull() {
            return (topIndex >= (size - 1));
        }

        bool isEmpty() {
            return (topIndex == -1);
        }

        bool push(char v) {
            if (isFull()) return false;
            else {
                topIndex++;
                S[topIndex] = v;
                return true;
            }
        }

        char top() {
            if (isEmpty()) {
                cout << "Error: Stack is empty" << endl;
                return -1;  // Or some error value
            }
            return S[topIndex];
        }

        char pop() {
            if (isEmpty()) {
                cout << "Error: Stack underflow" << endl;
                return -1;  // Or some error value
            }
            return S[topIndex--];
        }

        void print() {
            if (isEmpty()) {
                cout << "";
                return;
            }

            for (int i = 0; i <= topIndex; i++) {
                cout << S[i];
            }
        }
};


// Numeric stack for evaluation
class NumStack
{
    private:
        double *S;
		double arr[MAXS];
        int topIndex;
        int size;

    public:
        NumStack(){
            topIndex = -1;
            S = arr;
            size = MAXS;
        }

        int count() {
            return (topIndex + 1);
        }

        bool isFull() {
            return (topIndex >= (size - 1));
        }

        bool isEmpty() {
            return (topIndex == -1);
        }

        bool push(double v) {
            if (isFull()) return false;
            else {
                topIndex++;
                S[topIndex] = v;
                return true;
            }
        }

        double top() {
            if (isEmpty()) {
                cout << "Error: Stack is empty" << endl;
                return -1;  // Or some error value
            }
            return S[topIndex];
        }

        double pop() {
            if (isEmpty()) {
                cout << "Error: Stack underflow" << endl;
                return -1;  // Or some error value
            }
            return S[topIndex--];
        }

        void print() {
            if (isEmpty()) {
                cout << "";
                return;
            }

            for (int i = 0; i <= topIndex; i++) {
                cout << S[i];
            }
        }
};


bool isoperator(char c){
	return (c=='+'|| c=='-' || c=='^' || c=='/' || c=='*' ||c=='%');
}

int precedence(char op){
	if(op=='+'||op=='-') return 1;
	if(op=='*'||op=='/'||op=='%') return 2;
	if(op=='^') return 3;
    return 0;
}


//Infix to postfix implementation
void INFIXTOPOSTFIX(const char* infix, char* postfix) {
    CharStack s;
    int j = 0;
    
    cout << "Step\tToken\tStack\tPostfix\n";
    cout << "---------------------------------\n";
    
    for (int i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];
        
        // Checking for operands and adding them to postfix character array.
        if (isalpha(token)) {
            postfix[j++] = token;
        }
        // Checking open parathesis and pushing it into stack
        else if (token == '(') {
            s.push(token);
        }
        //checking closing paranthesis and popping operators until we get opening paranthesis.
        else if (token == ')') {
            while (!s.isEmpty() && s.top() != '(') {
                postfix[j++] = s.pop();
            }
            s.pop(); 
        }
        // checking for operator and popping all the operators of higher or equal precedence if assosiativity is Left to Right.
        else if (isoperator(token)) {
            while (!s.isEmpty() && precedence(s.top()) >= precedence(token)) {
                postfix[j++] = s.pop();
            }
            s.push(token);
        }
        // infix to postfix step by step table
        cout << i+1 << "\t" << token << "\t";
        s.print();
        cout << "\t";
        for (int k = 0; k < j; k++) {
            cout << postfix[k];
        }
        cout << endl;
    }

    while (!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    
    postfix[j] = '\0'; 

    cout << "---------------------------------\n";
    cout << "Final Postfix Expression: " << postfix << "\n";
}

double EVALUATEPOSTFIX(const char* postfix,double values[]){
	NumStack s; // object of numeric stack
	
	cout<<"Step\tToken\tStack\n";
	cout<<"---------------------"<<endl;
	

	for(int i=0;postfix[i]!='\0';i++){
		char token = postfix[i];
		
		if(isalpha(token)){
			s.push(values[token-'A']);
		}
		
        //checking for operators using isoperator function and calculation
		else if(isoperator(token)){
			double val2=s.pop();
			double val1=s.pop();
			double result=0.0;
			
			switch(token){
				case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': result = val1 / val2; break;
                case '%': result = fmod(val1,val2); break;
                case '^': result = pow(val1,val2); break;
            }
	
			s.push(result);	
        }
		cout<< i+1<< "\t" << token << "\t";
		s.print();
		cout <<"\n";
	}
	
	cout << "------------------------\n";
	return s.pop();
}

int main() {
	char infix[MAXS], postfix[MAXS]; // decleration of infix and postfix character arrays
	double values[26]; // decleration of double values so that we can handle floating values
	cout<<"USE ONLY CAPITAL ALPHABETS...\n";
	cout<<"-------------------------"<<endl;
	cout<<"Enter infix Expression: ";
	cin>>infix;
	cout<< "Enter values for operands (e.g A 10 B 23): \n";
	char operand;
	double value;

    // in values array the values of corresponding operands will be stored
	while(cin>>operand>>value){
		if(operand>='A'&& operand<='Z'){
			values[operand-'A']=value;
		}
		if(cin.get()=='\n') break;
	}
	
	INFIXTOPOSTFIX(infix,postfix);// calling infix to postfix function 
	
	double result = EVALUATEPOSTFIX(postfix,values); // callling evaluation 

	cout << "Postfix Expression: " << postfix << "\n";
    cout << "Evaluated Result: " << result << "\n";

    return 0;
}












