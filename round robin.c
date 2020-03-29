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
