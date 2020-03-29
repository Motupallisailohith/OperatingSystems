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
