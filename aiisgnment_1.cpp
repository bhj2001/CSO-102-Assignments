/***# bhj2001 #***/
//assignment 1
#include<stdio.h>
#include<algorithm>
using namespace std;


double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return (double)sum/(double)n;
}


double findMedian(int a[], int n)
{
    sort(a, a+n);
    if (n % 2 != 0)
       return (double)a[n/2];

    return (double)(a[(n-1)/2] + a[n/2])/2.0;
}

double findVar(int a[],int n)
{
	int m=findMean(a, n);
	int i,sum=0;
	for(i=0;i<n;i++)
	{
		sum+=(a[i]-m)*(a[i]-m);
	}
	return (double)sum/(double)n;
}
int main()
{
	while(1)
	{
	int n;
	printf("enter no. of integers :");
	//cout<<"enter no. of integers :";
	scanf("%d",&n);
	//cin>>n;
    int a[n],i,j;
    for(i=0;i<n;i++)
    {
    	printf("enter integer %d :",i+1);
    	scanf("%d",&a[i]);
    	//cout<<"enter integer "<<i+1<<" :";
    	//cin>>a[i];
	}
    n = sizeof(a)/sizeof(a[0]);
    printf("mean = %f \n",findMean(a, n));
    //cout << "Mean = " << findMean(a, n) << endl;
    printf("median = %f\n",findMedian(a, n));
    //cout << "Median = " << findMedian(a, n) << endl;
    //cout << "Mode = " << 3*findMedian(a, n)-2*findMean(a, n) << endl;
    int asd[100]={0},max=0;
    for(i=0;i<n;i++)
    {
    	asd[a[i]]++;
    	if(asd[a[i]]>max)
    		max=asd[a[i]];
    }
    printf("mode = ");
    for(i=0;i<100;i++)
    {
    	if(asd[i]==max)
    	{
    		for(j=1;j<=1;j++)
    		{
    			printf("%d ",i);
    		}
    	}
    }
    printf("\nvariance = %f\n",findVar(a, n));
    //cout << "Variance = "<<findVar(a, n)<<endl;
    printf("sd = %f\n",sqrt(findVar(a, n)));
    //cout << "Standard Deviation = " << sqrt(findVar(a, n)) << endl;
	}
    return 0;
}
