/**
 * Student Queue Management System
 * 
 * This program implements a circular queue to manage student data.
 * It demonstrates the basic operations of a queue data structure.
 
 */

#include<iostream>
#include<string>
using namespace std;

// Define the structure for student information
struct Student {
    string StudentName;
    string RollNo;
    string department;
};

// Queue class implementation using circular array
class Queue {
private:
    Student* S;       // Dynamic array to store Student objects
    int frontIndex;   // Index of the front element
    int rearIndex;    // Index of the rear element
    int count;        // Current number of elements in the queue
    int size;         // Maximum capacity of the queue

public:  
    // Constructor: Initializes the queue with given size
    Queue(int SIZE) {
        S = new Student[SIZE];
        frontIndex = -1;
        rearIndex = -1;
        count = 0;
        size = SIZE;
    }

    // Returns the current number of elements in the queue
    bool countval() { return count; }

    // Checks if the queue is full
    bool isFull() { return count == size; }

    // Checks if the queue is empty
    bool isEmpty() { return count == 0; }
    
    // Returns the front element of the queue without removing it
    Student front() { return S[frontIndex]; }

    // Adds a new student to the rear of the queue
    bool enQueue(Student student) {
        if (isFull()) return false;
        if (isEmpty()) {
            frontIndex = rearIndex = 0;
        } else {
            rearIndex = (rearIndex + 1) % size;  // Circular increment
        }
        S[rearIndex] = student;
        count++;
        return true;
    }

    // Removes and returns the front student from the queue
    Student deQueue() {
        if (isEmpty()) return {"#####", "#####", "####"};  // Return dummy student if empty
        Student std = S[frontIndex];
        if (count == 1) {
            frontIndex = rearIndex = -1;  // Reset indices if last element
        } else {
            frontIndex = (frontIndex + 1) % size;  // Circular increment
        }
        count--;
        return std;
    }

    // Prints all students in the queue
    void print() {
        if (isEmpty()) {
            cout << "No Students are present in the Queue";
        } else {
            cout << "All the students in the Queue:" << endl;
            int index = frontIndex;
            for (int i = 0; i < count; i++) {
                cout << "Name: " << S[index].StudentName << endl;
                cout << "RollNo: " << S[index].RollNo << endl;
                cout << "department: " << S[index].department << endl;
                index = (index + 1) % size;  // Circular increment
            }
        }
    }
};

// Main function to demonstrate queue operations
int main() {
    int queuesize;
    cout << "Enter the maximum number of students in the queue: ";
    cin >> queuesize;
    
    Queue q(queuesize);  // Create queue object
    int choice = 0;
    Student student;

    // Main program loop
    while (choice != 8) {  // Note: Changed to 8 to match the menu options
        // Display menu
        cout << "\n1. Check if empty\n2. Check if full\n3. Enqueue\n4. Dequeue\n"
             << "5. Count\n6. Check front student\n7. Print all\n8. Exit\n"
             << "Enter your choice (1-8): ";
        cin >> choice;

        // Process user choice
        switch(choice) {
            case 1: 
                cout << "Queue is " << (q.isEmpty() ? "empty" : "not empty") << endl;
                break;
            case 2: 
                cout << "Queue is " << (q.isFull() ? "full" : "not full") << endl;
                break;
            case 3:  // Enqueue operation
                if (q.isFull()) {
                    cout << "Queue is full. Cannot enqueue." << endl;
                } else {
                    cin.ignore();
                    cout << "Enter Student Name: ";
                    getline(cin, student.StudentName);
                    cout << "Enter Roll No: ";
                    getline(cin, student.RollNo);
                    cout << "Enter Department: ";
                    getline(cin, student.department);
                    q.enQueue(student);
                    cout << "Successfully enqueued student: " << student.StudentName << endl;
                }
                break;
            case 4:  // Dequeue operation
                if (q.isEmpty()) {
                    cout << "Queue is empty. Cannot dequeue." << endl;
                } else {
                    Student s = q.deQueue();
                    cout << "Dequeued student:\nName: " << s.StudentName
                         << "\nRoll No: " << s.RollNo
                         << "\nDepartment: " << s.department << endl;
                }
                break;
            case 5: 
                cout << "Number of students in the queue: " << q.countval() << endl;
                break;
            case 6:  // View front student
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    Student front = q.front();
                    cout << "Front student:\nName: " << front.StudentName
                         << "\nRoll No: " << front.RollNo
                         << "\nDepartment: " << front.department << endl;
                }
                break;
            case 7: 
                q.print();
                break;
            case 8: 
                cout << "Exiting program..." << endl;
                break;
            default: 
                cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        }     
    }

    return 0;
}