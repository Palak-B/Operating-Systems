#include <stdio.h>
#include <stdlib.h>


int *arrival_time;
int *burst_time;
int time;
int j;
int temp;
int temp2;

void sjf(int i)
{
	time+=burst_time[i];
	printf("%d",arrival_time[i]);
	printf("\t");
	printf("%d",burst_time[i]);
	burst_time[i]=0;
	printf("\n");
}
void main(){
	int limit;
	printf("Enter the number of process: ");
	scanf("%d",&limit);
	arrival_time = malloc(limit * sizeof(int));
	burst_time = malloc(limit * sizeof(int));
	int i;
	for (i=0;i<limit;i++){
		printf("Enter the arrival time for process %d: ",i+1);
		scanf("%d",&arrival_time[i]);
		printf("Enter the burst time for process %d: ",i+1);
		scanf("%d",&burst_time[i]);
	}
	for(i=0;i<limit;i++)
	{
		for(j=0;j<limit-i-1;j++)
		{
			if(burst_time[j]>burst_time[j+1])
			{
				temp=burst_time[j];
				temp2=arrival_time[j];
				burst_time[j]=burst_time[j+1];
				arrival_time[j]=arrival_time[j+1];
				burst_time[j+1]=temp;
				arrival_time[j+1]=temp2;
			}
		}
	}
	for(i=0;i<limit;i++)
	{
		printf("%d",arrival_time[i]);
		printf("\t");
		printf("%d",burst_time[i]);
		printf("\n");
	}
printf("\n");
printf("\n");

	i=0;
	int process=1;
	
	while(process)
	{
		if(time>=arrival_time[i] && burst_time[i])
		{
		sjf(i);
		i=0;
		continue;	
		}
		i=(i+1)%limit;
		process=0;
		for(j=0;j<limit;j++)
		{
			if(burst_time[j])
			{
				process=1;
				break;
			}
		}
	}

}

