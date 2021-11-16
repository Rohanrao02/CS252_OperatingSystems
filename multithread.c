/*This program creates multithreads to calculate average,maximum
	and minimum for a given list of numbers*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
int i;

typedef struct datastruct
{
    int size;
    int * values;
}datastruct;

//Avg calculating thread
void *avg_thread(void *ptr)
{
	datastruct * copy;
    copy = (datastruct *) ptr;

	int count = copy->size;
	float average = 0;

	for(i=0 ;i<count ;i++)
		{
			average =average + copy->values[i];
		}
	average=average/count;
	printf("The average value is:%f\n",average);
}

//Minimum calculating thread
void *min_thread(void *ptr)
{
	datastruct * copy;
    copy = (datastruct *) ptr;

	int count = copy->size, min = copy->values[0];
	
	for(int i=1;i<count;i++)
		{
			if(min > copy->values[i])
			{
				min = copy->values[i];
			}
		}
	printf("The Minimum  value is:%d\n",min);

}

//Maximum calculating thread
void *max_thread(void *ptr)
{
	datastruct * copy;
    copy = (datastruct *) ptr;

	int count = copy->size, max = copy->values[0];

	for(int i=1;i<count;i++)
		{
			if(max < copy->values[i])
			{
				max = copy->values[i];
			}
		}
	printf("The Maximum  value is:%d\n",max);
	}


int main()
{
int count,i,arr[50],t1,t2,t3;
pthread_t thread1,thread2,thread3;

	printf("Enter the count of number:");
	scanf("%d",&count);
	printf("Enter the numbers:");
	for (i=0;i<count;i++)
	{
		scanf("%d",&arr[i]);
	}

	datastruct ds = {count, arr};
	
	t1=pthread_create(&thread1,NULL,(void *)avg_thread,(void *)&ds);
	//Checking the creation of the thread 1
	if(t1)
    	{
        	fprintf(stderr,"Error - pthread_create() return code: %d\n", t1);
     		exit(EXIT_FAILURE);
    	}
	t2=pthread_create(&thread2,NULL,(void *)min_thread,(void *)&ds);
	//Checking the creation of the thread 2
	if(t2)
    	{
        	fprintf(stderr,"Error - pthread_create() return code: %d\n", t2);
        	exit(EXIT_FAILURE);
    	}
	t3=pthread_create(&thread3,NULL,(void *)max_thread,(void *)&ds);
	//Checking the creation of the thread 3
	if(t3)
    	{
        	fprintf(stderr,"Error - pthread_create() return code: %d\n", t3);
        	exit(EXIT_FAILURE);
    	}	

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	pthread_join(thread3,NULL);
	
	printf("pthread_create() for Thread 1 returns: %d\n",t1);
	printf("pthread_create() for Thread 2 returns: %d\n",t2);
	printf("pthread_create() for Thread 3 returns: %d\n",t3);

	exit(EXIT_SUCCESS);
	
}