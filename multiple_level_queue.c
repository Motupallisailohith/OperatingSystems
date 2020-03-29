#include<stdio.h>
#include<conio.h>



    int i,n,j=0,k=0,l=0,x,position,q,q1=0,q2=0,q3=0;
	
	int burst_time1[30],burst_time2[30],burst_time3[30],process2[30];
	int at1[30], at2[30], at3[30];
	int bt[30] , priority[30],priority1[30],at[30],t[30],t1,Total=0,total,counter=0;
	int p,waiting_time1[30],turnaround_time1[30],sum=0,waiting_time2[30],turnaround_time2[30];
	float avg_waiting_time1=0.0,avg_turnaround_time1=0.0,avg_waiting_time3,avg_turnaround_time3,avg_waiting_time2,avg_turnaround_time2;
	
void round_robin()
{
	printf("time quantum for queue3 :: 4 \n\n");
	for(i=0;i<j;i++)
	{
		t[i]=burst_time3[i];
	}
	printf(" process number\tburst time\t turnaround time\t waiting time\n\n");
	x=j;
	for(i=0;total=0;x!=0)
	{
		if(t[i]>0 && t[i]<=4)
		{
		  printf("process%d of queue3 is running for %d units \n",i+1,t[i]);
		 total = total + t[i];
		 t[i]=0;
		 counter=1;
		  
		}
		else if(t[i]>0)
		{
			printf("process%d of queue 3 is running for 4 units\n",i+1);
			t[i]=t[i]-4;
			total=total+4;
		}
		if(t[i]==0 && counter ==1)
		{
			x--;
			printf("process%d\t%d\t%d\t%d \n",i+1,burst_time3[i],total-at3[i],total-at3[i]-burst_time3[i]);
			avg_waiting_time3=avg_waiting_time3+total-at3[i]-burst_time3[i]; 
            avg_turnaround_time3=avg_turnaround_time3+total-at3[i]; 
			counter = 0;
		}
		if(i==j-1)
		{
			i=0;
		}
		else if(at3[i+1]<=total)
		{
			i++;
		}
		else
		{
			i=0;
		}
		
	}
	avg_waiting_time3=avg_waiting_time3/j;
    avg_turnaround_time3=avg_turnaround_time3/j;
    printf("\nAverage Waiting Time:%f",avg_waiting_time3); 
    printf("\nAverage Turnaround Time:%f\n",avg_turnaround_time3);
}

void priority_scheduling()
{
	for(i=0;i<k;i++)
	{
		position = i;
		for(q=i+1;q<k;q++)
		{
			if(priority1[q]<priority1[position])
			{
				position = q;
			}
		}
		t1=priority1[i];
		priority1[i]=priority1[position];
		priority1[position]=t1;
		
		t1= burst_time2[i];
		burst_time2[i]=burst_time2[position];
		burst_time2[position]=t1;
		
		t1=process2[i];
		process2[i]=process2[position];
		process2[position]=t1;
		
	}
	
	waiting_time2[0]=0;
	
    for(i=1;i<k;i++)
    {
        waiting_time2[i]=0;
        for(q=0;q<i;q++)
        {
            waiting_time2[i]=waiting_time2[i]+burst_time2[j];
        }
        sum=sum+waiting_time2[i];
    }

	avg_waiting_time2=sum/k;
    sum=0;
	printf("\nProcess ID\t\tBurst Time\t Waiting Time\t Turnaround Time\n");

	for(i=0;i<k;i++)
	{
		turnaround_time2[i]=burst_time2[i]+waiting_time2[i];
        sum=sum+turnaround_time2[i];
        printf("\nProcess[%d]\t\t%d\t\t %d\t\t %d\n",process2[i],burst_time2[i],waiting_time2[i],turnaround_time2[i]);
	}
	
	avg_turnaround_time2=sum/k;
    printf("\nAverage Waiting Time:\t%f",avg_waiting_time2);
    printf("\nAverage Turnaround Time:\t%f\n",avg_turnaround_time2);
    
	for(i=0;i<k;i++)
	{
		while(burst_time2[i]!=0)
		{
			if(burst_time2[i]>10)
			{
				printf("process%d of queue2 is running for 10 units",i+1);
				burst_time2[i]=burst_time2[i]-10;
			}
			else if(burst_time2[i]<=10)
			{
				printf("process%d of queue2 is running for %d units",i+1,burst_time2[i]);
				burst_time2[i]=0;
			}
		}
	}
}

void fcfs()
{   
	waiting_time1[0] = 0; 
	 for(i=1;i<l;i++)
    {
        waiting_time1[i] = 0;
        for(p=0;p<l;p++)
        {
            waiting_time1[i]=waiting_time1[i]+burst_time1[p];
        }
    } 
    
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n"); 
	
	for(i=0;i<l;i++)
	{
		
        turnaround_time1[i]=burst_time1[i]+waiting_time1[i];
        avg_waiting_time1=avg_waiting_time1+waiting_time1[i];
        avg_turnaround_time1=avg_turnaround_time1+turnaround_time1[i];
        printf("\nProcess[%d]\t\t%d\t\t%d\t\t%d\n",i+1,burst_time1[i],waiting_time1[i],turnaround_time1[i]);
	}
	
	avg_waiting_time1=avg_waiting_time1/l;
    avg_turnaround_time1=avg_turnaround_time1/l;
    printf("\nAverage Waiting Time=%f",avg_waiting_time1);
    printf("\nAverage Turnaround Time=%f",avg_turnaround_time1);
    
	for(i=0;i<l;i++)
	{
		while(burst_time1[i]!=0)
		{
			if(burst_time1[i]>10)
			{
				printf("process%d of queue1 is running for 10 units\n",i+1);
				burst_time1[i]=burst_time1[i]-10;
			}
			else if(burst_time1[i]<=10)
			{
				printf("process%d of queue2 is running for %d units \n",i+1,burst_time1[i]);
				burst_time1[i]=0;
			}
		}
	}
}

void round_robin_whole()
{
	printf("time quantum for 3 queues is 10 \n");
	for(i=1;i<Total;i = i+10)
	{
		if(q1>10)
		{
			printf("queue1 is running for 10 seconds\n");
			q1=q1-10;
		}
		else if(q1<=10 && q1!=0)
		{
			printf("queue1 is running for %d units \n",q1);
			q1=0;
		}
		if(q2>10)
		{
			printf("queue2 is running for 10 seconds\n");
			q2=q2-10;
		}
		else if(q2<=10 && q2!=0)
		{
			printf("queue2 is running for %d units \n",q2);
			q2=0;
		}
		if(q3>10)
		{
			printf("queue3 is running for 10 seconds \n");
			q3=q3-10;
		}
		else if(q3<=10 && q3!=0)
		{
			printf("queue3 is running for %d seconds \n",q3);
			q3=0;
		}
	}
}
	
	
int main()
{
	
	printf("enter number of processes\n");
	scanf("%d",&n);
	for(i = 0 ; i < n;i++)
	{
		printf(" burst time and priority of all process %d \n",i+1);
		printf("enter burst time of process \n ");
		scanf("%d",&bt[i]);
		printf("enter priority of processe \n ");
		scanf("%d",&priority[i]);
		printf("enter arrival time of process \n");
		scanf("%d",&at[i]);
		Total = Total +bt[i];
	}
	for(i=0; i< n;i++)
	{
		if(priority[i]>=1 && priority[i]<=5)
		{
			printf("process%d belongs to queue1 \n",i+1);
			at1[j]=at[i];
			burst_time1[j]=bt[i];
			j++;
			q1=q1+bt[i];
		}
		else if(priority[i]>6 && priority[i]<= 10)
		{
			printf("process%d belongs to queue2 \n",i+1);
			at2[k]=at[i];
			burst_time2[k]=bt[i];
			priority1[k]=priority[i];
			process2[k]=k+1;
			k++;
			q2=q2+bt[i];
		}
		else if(priority[i]>11)
		{
			printf("process%d belongs to queue3 \n\n",i+1);
			at3[l]=at[i];
			burst_time3[l]=bt[i];
			l++;
			q3=q3+bt[i];
		}
		
	}
	round_robin_whole();
	round_robin();
	fcfs();
	priority_scheduling();
	return 0;
}
