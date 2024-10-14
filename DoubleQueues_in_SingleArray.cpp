#include<iostream>
using namespace std;
#define MAXS 10


class DoubleQueue{
	private:
		int q[MAXS];
		int c1,c2,f1,f2,r1,r2;
	public:
		DoubleQueue(){
			c1=c2=0;
			f1=r1=-1;
			f2=r2=MAXS;
		}
				
		int count(bool f)
		{
			if(f) return c1;
			else return c2;
		}
		
		bool enqueue(bool f,int v)
		{	
			int x;
			x = count(f) + count(!f);
			if(x==MAXS) return false;
			
			if(f)
			{
				if(c1==0){f1=0;r1=0;
				}
				q[r1] = v;
				r1 = (r1+1)%MAXS;
				c1++;
				return true;
			}
			else{
				if(c2==0){f2=MAXS-1;r2=MAXS-1;
				}
				q[f2]=v;
				f2 = (f2-1)%MAXS;
				c2++;
				return true;
			}
		}
		
		int dequeue(bool f)
		{
			int x;
			x = count(f) + count(!f);
			if(x==0) return false;
			
			if(f)
			{
				int v;
				v = q[f1];
				f1 = (f1+1)%MAXS;
				c1--;
				return v;
			}
			else{
				int r;
				r = q[r2];
				r2 = (r2-1)%MAXS;
				c2--;
				return r;
			}
				
		}
		
		void print(bool f)
		{
			if(f)
			{
				for(int i=f1;i<r1;i++)
					cout<<q[i]<<endl;
			}
			else{
				for(int j=r2;j>r2-c2;j--)
					cout<<q[j]<<endl;
			}
		}
};

int main()
{
	DoubleQueue q;
	q.enqueue(true,2);
	q.enqueue(true,3);
	q.enqueue(true,7);
	q.enqueue(true,199);
	q.dequeue(true);
	q.dequeue(true);
	q.dequeue(true);
	q.print(true);
}
