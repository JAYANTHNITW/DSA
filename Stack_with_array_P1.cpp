// Implementation of Stack using  Array


#include <iostream>
#include <string>
using namespace std;
 
struct Student  //Student structure
{
    string StudentName;
    string rollNo;
    string department;
};

class Stack{
    private:
        Student *S;  //pointer to the structure
        int topIndex;
        int size;
      
    public:
        Stack(int SIZE){
            S = new Student[SIZE];  //pointing the first memory location of student structure
            topIndex=-1;
            size = SIZE;
            
        }

        bool isEmpty(){    //to check whether stack is empty or not
            return (topIndex==-1);
        }

        bool isFull(){// to check whether stack is full or not
            return (topIndex>=size-1);
        }

         
        bool push(Student student){ // adding students to the stack using push function
            if(isFull()) return false;
            else{
                topIndex++;
                S[topIndex]=student;
                 
                return true;
            }
        }

        Student pop(){// returning and deleting the student from stack
            if(isEmpty()){
                cout<<"Stack is empty....";
                return {"","-1",""};
            }
            else{ Student temp  = S[topIndex--];
            return temp;
            }
        }

        Student top(){// returning the top student from the stack
            return S[topIndex];
        }

        void print(){ // printing the all the students in the stack
            if(isEmpty()){
                cout<<"Stack is empty....";
            }
            else{cout<<"All the students present in the stack:"<<endl;
                for (int i=0;i<=topIndex;i++){
                    cout<< "Name:"<< S[i].StudentName
                    << ", rollNo:"<< S[i].rollNo
                    << ", department:" <<S[i].department<<'\n'<<endl;
                }
            }
        }
};

// Menu based implementation of stack
int main(){
    int stacksize;
    cout<<"How many number of students data you want to include in stack: ";
    cin>>stacksize;
    Stack s(stacksize);
    Student student;
    int choice =0;

    while(choice !=7){
        cout<<"1. IsEmpty(), 2. IsFull(), 3. push(), 4. pop(), 5. top(), 6.print(), 7.exit()\n"<<endl;
        cout<<"Give number ranging from 1 to 7: ";
        cin>>choice;

        switch(choice){
            
            case 1: cout<<"Is Empty:"<<(s.isEmpty()?"Yes":"No")<<endl; //Checking whether stack is empty or not
                break;

            case 2: cout<<"Is Full:"<<(s.isFull()? "Yes":"No")<<endl;// checking wheter stack is full or not
                break;

            case 3: if(s.isFull()){// pushing the student to stack
                cout<<"Stack is full cannot push"<<endl;
                }
                else{
                    cin.ignore();
                    cout<<"Student Name: ";
                    getline(cin,student.StudentName);
                    cout<<"roll No: ";
                    getline(cin,student.rollNo);
                    cout<<"Department: ";
                    getline(cin,student.department);
                    s.push(student);
                    cout<< "Successfully pushed student: "<<student.StudentName<<"\n"<<endl;
                    break;
                }
                break;

            case 4: if(s.isEmpty()){  // popping the student from stack
                cout<<"Stack is empty, cannot pop..."<<endl;
                }
                else{
                    student = s.pop();
                    cout<<"Popped student name:" << student.StudentName<<
                    ", rollNo:"<< student.rollNo<<
                    ", department:"<< student.department<<endl;;
                }
                break;
            
            case 5: if(s.isEmpty()){            //To check the top student of the stack
                cout<<"Stack is empty, No students to show"<<endl;
                }
                else{
                    student = s.top();
                    cout<<"top-> student details:"<<student.StudentName<<
                    ", rollNo:"<< student.rollNo<<
                    ", department:"<< student.department<<endl;
                }
                break;
            
            case 6: // To print all the students of the stack
                    s.print();
                    break;
            
            case 7: cout<< "Exiting ...."<<endl;
                    break;

            default: cout<<"Enter the right choice, please try again!"<<endl;
            break;
        }
    }

    return 0;

}

