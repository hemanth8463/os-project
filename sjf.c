#include<stdio.h> 
int main()
{

int i,j,n;

int time,remaining;

int flag=0,timequantum=10;

int waitingtime=0,turnaroundtime=0,arrivaltime[10],bursttime[10],rt[10];

printf("\n\nEnter the Total number of Process:\t "); scanf("%d",&n);
remaining=n; for(i=0;i<n;i++)
{

printf("enter Arrival Time and Burst Time for process process number %d :",i+1);



scanf("%d",&arrivaltime[i]);



scanf("%d",&bursttime[i]);



rt[i]=bursttime[i];

}

printf("Enter Time Quantum:%d\t",timequantum);



printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");



for(time=0,i=0;remaining!=0;)

{

if(rt[i]<=timequantum && rt[i]>0)

{

time+=rt[i];

rt[i]=0;



flag=1;

}

else if(rt[i]>0)

{

rt[i]-=timequantum;



time+=timequantum;

}

if(rt[i]==0 && flag==1)

{

remaining--;

printf("P[%d]\t|\t%d\t|\t%d\n",i+1,time-arrivaltime[i],time-arrivaltime[i]-bursttime[i]);



waitingtime+=time-arrivaltime[i]-bursttime[i];



turnaroundtime+=time-arrivaltime[i];



flag=0;

}

if(i==n-1) i=0;

else if(arrivaltime[i+1]<=time) i++;
else

i=0;

}

printf("\n Average Waiting Time= %f\n",waitingtime*1.0/n);



printf(" Averageg Turnaround Time = %f",turnaroundtime*1.0/n);



return 0;

}

