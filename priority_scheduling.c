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
