#include<stdio.h>
#include<semaphore.h>
#include<stdlib.h>
#include<pthread.h>
# define buffer 10
int buff[100];
sem_t mutex,full,empty;
int data=0,counter=0;
pthread_t proc[buffer];
pthread_t cons[buffer];
void * producer()
{
	sem_wait(&empty);
	sem_wait(&mutex);
	buff[counter++]=rand()%10;
	printf("data produced is %d",buff[counter-1]);
	printf("\n");
	counter++;
	sem_post(&mutex);
	sem_post(&full);
}

void * consumer()
{
	if(counter==0)
	exit;
	sem_wait(&full);
	sem_wait(&mutex);
	printf("data consumed is %d",buff[--counter]);
	printf("\n");
	counter--;
	sem_post(&mutex);
	sem_post(&empty);
}

int main()
{
int cc,pc,bf;
	printf("Enter buffer size");
	scanf("%d",&bf);
	printf("number of consumers");
	scanf("%d",&cc);
	printf("number of producers");
	scanf("%d",&pc);
	sem_init(&mutex,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,bf);
	int excess=cc-pc;
	if(excess>0)
	cc=pc;
	for(int i=0;i<cc;i++)
	{
	pthread_create(&cons[i],NULL,consumer,NULL);
	}
	for(int i=0;i<pc;i++)
	{
	pthread_create(&proc[i],NULL,producer,NULL);
	}
	for(int i=0;i<cc;i++)
	{
	pthread_join(cons[i],NULL);
	}
	for(int i=0;i<pc;i++)
	{
	pthread_join(proc[i],NULL);
	}
if (excess>0)
		printf("%d consumers could get no item\n", excess);
else if(excess<0)
		excess*=-1;
		printf("%d items not consumed\n",excess);
return 0;
}
