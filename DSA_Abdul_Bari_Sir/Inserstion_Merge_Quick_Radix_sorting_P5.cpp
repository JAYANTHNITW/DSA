#include<iostream>
#include<cstdlib> // for rand() function
#include<climits> // for Swap() function
#include<cmath> // for log10() function

using namespace std;


// Insertion Sort
void InsertionSort(int *A,int n)
{	
	int j,x;
	int max= INT_MIN;
	for(int i=1;i<n;i++)
	{
		j=i-1;
		x = A[i];
		
		while(j>-1 && A[j]>x)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
		
}

// Merging

void merge(int *A,int l, int mid, int h)
{
	int i,j,k;
	i=k=l;
	j=mid+1;
	
	int B[100];
	
	while(i<=mid && j<=h)
	{
		if(A[i]>A[j])
			B[k++] = A[j++];
		else B[k++] = A[i++];
		
	}
	
	for(;i<=mid;i++)
		B[k++] = A[i];
	
	for(;j<=h;j++)
		B[k++] = A[j];
	
	for(int i=l;i<=h;i++)
		A[i] = B[i];
}

// Iterative Merge Sort

void Iterative_MergeSort(int *A,int n)
{
	
	for(int p=2;p<=n;p=p*2)
	{
		for(int i=0;i+p-1<n;i++){
			int l=i;
			int h = i+p-1;
			int mid = (l+h)/2;
			merge(A,l,mid,h);
		}
		
	}	
	 
	merge(A,0,(n-1)/2,n);
	
}

// Quick Sort

int Partition(int *A,int l,int h) // A- Integer pointer array, l- lower index ,h- higher index or no.of elements
{
	int pivot = A[l];
	int i=l;
	int j=h;
	do{
		do{i++;} while(pivot>=A[i]);
		do{j--;}while(pivot<A[j]);
		
		if(i<j)
		swap(A[i],A[j]);
		
	}while(j>i);
	
 
	swap(A[l],A[j]);
		
	return j;
}

void QuickSort(int *A,int l, int h) // A- Integer pointer array, l- lower index ,h- higher index or no.of elements
{
	int j;
	
	if(l<h) {
	j = Partition(A,l,h);
	QuickSort(A,l,j);
	QuickSort(A,j+1,h);
  }

}


// Radix Sort

struct Node{
	int data;
	Node* next;
};

int find_max(int A[],int n)
{
	int max=INT_MIN;
	
	for(int i=0;i<n;i++)
		{
			if(A[i]>max)
			max = A[i];
		}
		
	return max;
}

void Insert(Node *&p, int value)
{	
	Node *nn = new Node;
	nn->data = value;
	nn->next = NULL;
	
	if(p==NULL)
	{	 
		p= nn;
	}
	
	else{
		Node *temp;
		temp = p;
		while(temp->next!=NULL)
		temp = temp->next;
		temp->next = nn;
	}
}

int Delete(Node *&p)
{
	int value;
	Node *temp;
	temp = p;
	value = temp->data;
	if(temp->next!=NULL)
		p = temp->next;
	else p = NULL;
	
	delete temp;
	return value;
}

void RadixSort(int *A,int n)
{
	int max_value,k=1;
	max_value = find_max(A,n);
	int np = int(log10(max_value)+1); // No.of passess
	Node **bins;
	
	bins = new Node*[10];
	
	for(int p=1;p<=np;p++)
	{	
		int m =0;
		
		for(int i=0;i<10;i++)
			bins[i] = NULL;
		
		for(int j=0;j<n;j++)
			Insert(bins[(A[j]/k)%10],A[j]);
			
		k = k*10;
		
		for(int l=0;l<10;l++)
		{
		
			while(bins[l]!=NULL)
			A[m++] = Delete(bins[l]);
		}
	}
}
int* randGen(int n)
{
	int *RandArr = new int[n];
	
	for(int i=0;i<n;i++)
		RandArr[i]= rand();
		
	return RandArr;
}

void print(int *arr,int n)
{	
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
}

int main()
{
	int n;
	int choice=0;
 	
	while(choice!=5)
	{	cout<<"How many elements you want to sort? : ";
		cin>>n;
		// intarr - the pointer to the integer array
	    int *intarr = randGen(n);
	
		cout<<"Given Unsorted Integer Array: ";
		print(intarr,n);
		cout<<endl;
	
		cout<<"Choose the Sorting Algorithm: \n 1. Insertion Sort \n 2. Merge Sort \n 3. Quick Sort \n 4. Radix Sort \n 5. Exit"<<endl;
		cout<<"Give Value ranging from 1-5: ";
		cin>>choice;
	
		switch(choice)
		{
			case 1: InsertionSort(intarr,n);
				cout<<"Sorted Array: ";
				print(intarr,n);
				cout<<endl;
			break;
			
			case 2: Iterative_MergeSort(intarr,n);
				cout<<"Sorted Array: ";
				print(intarr,n);
				cout<<endl;
			break;
			
			case 3: QuickSort(intarr,0,n);
				cout<<"Sorted Array: ";
				print(intarr,n);
				cout<<endl;
			break;
			
			case 4:  RadixSort(intarr,n);
				cout<<"Sorted Array: ";
				print(intarr,n);
				cout<<endl;
			break;
			
			case 5: cout<<"Exiting..."<<endl;	 
			break;
			
			default: cout<<"Try again with choice within range: 1-5";
			break;
		}
	}
}
