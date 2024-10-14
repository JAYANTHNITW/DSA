#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

int hashcode(int x)
{
	return x%10;
}

int deletenode(Node *&p, int dv)
{
	Node *temp;
	
	if(p==NULL) return -1;
	
	else if(p->data==dv)
	{	
		temp = p;
		dv = temp->data;
		p = temp->next;
		delete temp;
		return dv;
	}
	else{
		temp = p;
		while(temp->next!=NULL)
		{
			if(temp->next->data!=dv)
				 temp = temp->next;
			else break;
		}
		
		dv = temp->next->data;
		temp->next = temp->next->next;
			
	 	return dv;
	}
}

Node* Search(Node *&p, int value)
{	Node *temp;

	if(p->data == value)
	{
		return p;
	}
	else {
		temp =p;
		 
		while(temp!=NULL)
			{
				if(temp->data==value)
					return temp;
				
				else temp = temp->next;
			}
		return NULL;
	}
	 
}

Node* Sorted_Insert(Node *&p,int value)
{
	Node *nn = new Node;
	nn->data = value;
	
	if(p==NULL)
	{
		nn->next = NULL;
		p=nn;
		return p;	
	}
	
	else{
		Node *temp;
		temp = p;
		
		 if(value<=temp->data)
		 {
		 	nn->next = temp;
		 	p=nn;
		 	return p;
		 }
		 
		 else{
		 	while(temp->next!=NULL)
		 	{
		 		if(temp->data<value && temp->next->data<value)
		 			temp = temp->next;

				else break;
			 }
		 	
		 	nn->next = temp->next;
		 	temp->next =nn;
		 	return nn;
		 }
		 
	}
	return NULL;
}

 
 
// Open Addressing:

const int TABLE_SIZE = 10;

int linear_probing(int key, int index)
{
    return (key % TABLE_SIZE + index) % TABLE_SIZE;
}

void Insert(int ht[], int key)
{
    int i = 0;
    
    while (i < TABLE_SIZE) {
        int index = linear_probing(key, i);
        if (ht[index] == -1) {
            ht[index] = key;
            return;
        }
        i++;
    }
    cout << "Hash table is full. Cannot insert " << key << endl;
}

bool search(int ht[], int key)
{   
    int i = 0;
    
    while (i < TABLE_SIZE) {
        int index = linear_probing(key, i);
        if (ht[index] == key)
            return true;
        if (ht[index] == -1)
            return false;
        i++;
    }
    
    return false;
}

void Delete(int ht[], int key)
{
    int i = 0;
    
    while (i < TABLE_SIZE) {
        int index = linear_probing(key, i);
        if (ht[index] == key) {
            ht[index] = -1;
            cout << "Key " << key << " deleted successfully." << endl;
            return;
        }
        if (ht[index] == -1) {
            cout << "Key " << key << " not found in the hash table." << endl;
            return;
        }
        i++;
    }
    
    cout << "Key " << key << " not found in the hash table." << endl;
}


int main()
{   
    Node* ht_chaining[TABLE_SIZE];
    int ht_open[TABLE_SIZE];
    
    for(int i = 0; i < TABLE_SIZE; i++) {
        ht_chaining[i] = NULL;
        ht_open[i] = -1; // Use -1 to represent empty slots in open addressing
    }

    int choice;
    while (true) 
	{
        cout << "\nSelect the hashing technique: \n 1. Separate Chaining \n 2. Open Addressing \n 3. Exit" << endl;
        cout << "Provide value 1, 2, or 3: ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting program." << endl;
            break;
        }

        switch(choice) {
            case 1: // Separate Chaining
            {
                int op;
                do {
                    cout << "\nSeparate Chaining Operations:" << endl;
                    cout << "1. Insert\n2. Search\n3. Delete\n4. Return to main menu" << endl;
                    cout << "Enter your choice (1-4): ";
                    cin >> op;

                    switch(op) {
                        case 1: {
                            int key;
                            cout << "Provide Key to Insert: ";
                            cin >> key;
                            Node *temp = Sorted_Insert(ht_chaining[hashcode(key)], key);
                            if(temp != NULL)
                                cout << "Successfully Inserted value: " << temp->data << endl;
                            else
                                cout << "Insert unsuccessful" << endl;
                            break;
                        }
                        case 2: {
                            int key;
                            cout << "Provide Key to Search: ";
                            cin >> key;
                            Node *temp = Search(ht_chaining[hashcode(key)], key);
                            if(temp != NULL)
                                cout << "Searched value: " << temp->data << " is present" << endl;
                            else
                                cout << "Search unsuccessful" << endl;
                            break;
                        }
                        case 3: {
                            int key;
                            cout << "Provide Key to delete: ";
                            cin >> key;
                            int v = deletenode(ht_chaining[hashcode(key)], key);
                            if(v != -1)
                                cout << "Deleted key: " << v << endl;
                            else
                                cout << "Delete unsuccessful" << endl;
                            break;
                        }
                        
                         
                        case 4:
                            cout << "Returning to main menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (op != 4);
                break;
            }
            case 2: // Open Addressing
            {
                int op;
                do {
                    cout << "\nOpen Addressing Operations:" << endl;
                    cout << "1. Insert\n2. Search\n3. Delete\n4. Return to main menu" << endl;
                    cout << "Enter your choice (1-4): ";
                    cin >> op;

                    switch(op) {
                        case 1: {
                            int key;
                            cout << "Enter key to insert: ";
                            cin >> key;
                            Insert(ht_open, key);
                            break;
                        }
                        case 2: {
                            int key;
                            cout << "Enter key to search: ";
                            cin >> key;
                            if (search(ht_open, key))
                                cout << "Key " << key << " found in the hash table." << endl;
                            else
                                cout << "Key " << key << " not found in the hash table." << endl;
                            break;
                        }
                        case 3: {
                            int key;
                            cout << "Enter key to delete: ";
                            cin >> key;
                            Delete(ht_open, key);
                            break;
                        }
                        
                        case 4:
                            cout << "Returning to main menu" << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (op != 4);
                break;
            }
            default:
                cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
        }
    }
    return 0;
}
