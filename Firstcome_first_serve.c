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
