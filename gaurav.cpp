#include<stdio.h>
 
int main()
{
    int at[20],bt[20],xt[20],ct[20],p[20],wt[20],tat[20],i=0,j=0,k=0,n,total=0,pos,temp,count=0;
    int at1[20],bt1[20],p1[20],m;
    int proc[20],arr[20],brr[20];
    float avg_wt,avg_tat;
    printf("Enter number of process for 1st Queue:");
    scanf("%d",&n);
    printf("Enter number of process for 2nd Queue:");
    scanf("%d",&m);
    
    printf("\nEnter Arrival Time for 1st Queue:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at[i]);
        p[i]=i+1;           //contains process number
    }
    printf("\nEnter Arrival Time for 2nd Queue:\n");
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&at1[i]);
        p1[i]=i+1;           //contains process number
    }
    for(i=0;i<n;i++)
    {
 
    printf("\nEnter Burst Time for 1st Queue:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
	
	printf("\nEnter Burst Time for 2nd Queue:\n");
    for(i=0;i<m;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt1[i]);
        p1[i]=i+1;           //contains process number
    }
i=0;
j=0;
k=0;
while(i<n && j<m){
	if(at[i]<at1[j]){
		arr[k]=at[i];
		brr[k]=bt[i];
		proc[k]=k;
		i++;
		k++;
	}
	else if(at[i]==at1[j]){
		arr[k]=at[i];
		brr[k]=bt[i];
		proc[k]=k;
		i++;
		k++;
	}
	else{
		arr[k]=at1[j];
		brr[k]=bt1[j];
		proc[k]=k;
		k++;
		j++;
	}
}

while (i < n){
       arr[k] = at[i];
       brr[k] = bt[i];
       proc[k]=k;
	   k++;
	   i++; 
   }
  
    while (j < m){
        arr[k] = at1[j];
        brr[k] = bt1[j];
        proc[k]=k;
		k++;
		j++; 
}
count=0;
for(i=0;i<n+m;i++){
	ct[i]=0;
}     
   for(i=0;i<n+m;i++)
    {
    	if(brr[i]>=2)
    	{
    		xt[i]=brr[i]-2;
    		count=count+2;
		}
		else{
			ct[i]=brr[i]+count;
			count=count+brr[i];
		}
	}

for(i=0;i<=n+m;i++)
	{
		if(ct[i]==0)
		{
			ct[i]=count+xt[i];
			count=ct[i];					
		}
}
	for(i=0;i<n+m;i++)
    {
        tat[i]=ct[i]-arr[i];     //calculate turnaround time
        total+=tat[i];
    }
    avg_tat=(float)total/n;     //average turnaround time
    total=0;
 
 
    //calculate waiting time
    for(i=0;i<n+m;i++)
    {
        wt[i]=tat[i]-brr[i];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time

 
    printf("\nProcess\t     Arrival Time	Burst Time	  Completition Time    \tTurnaround Time  Waiting Time");
    for(i=0;i<n+m;i++)
    {
        printf("\np%d\t\t  %d\t\t  %d\t\t	%d\t\t    %d\t\t\t%d",proc[i],arr[i],brr[i],ct[i],tat[i],wt[i]);
    }
 
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
}
