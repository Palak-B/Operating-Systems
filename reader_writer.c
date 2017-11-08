#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
int readcount=0;
sem_t mutex,write_b;
pthread_t read[10];
pthread_t write[10];
void* reader()
{
	sem_wait(&mutex);
	readcount++;
	if(readcount==1) sem_wait(&write_b);
	sem_post(&mutex);
	printf("data read");
	sem_wait(&mutex);
	readcount--;
	if(readcount==0) sem_post(&write_b);
	sem_post(&mutex);	
}

void* writer()
{
	sem_wait(&mutex);
	printf("data write");
	sem_post(&mutex);
}

void main()
{
	sem_init(&mutex,0,1);
	sem_init(&write_b,0,1);
	printf("total");
	int n;
	scanf("%d",&n);
	printf("readers");
	int rc;
	scanf("%d",&rc);
	printf("writers");
	int wc;
	scanf("%d",&wc);
	for(int i=0;i<rc;i++)
	{
	pthread_create(&read[i],NULL,reader,NULL);
	}
	for(int i=0;i<rc;i++)
	{
	pthread_create(&write[i],NULL,writer,NULL);
	}
	for(int i=0;i<rc;i++)
	{
	pthread_join(read[i],NULL);
	}
	for(int i=0;i<rc;i++)
	{
	pthread_join(write[i],NULL);
	}
return;
}
	
