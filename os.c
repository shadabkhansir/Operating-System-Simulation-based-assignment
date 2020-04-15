#include<stdio.h>
#include<conio.h>
int main()
{
  printf("\t\t\tNon Pre-emtive Scheduling Approach\n\n\n\n");
  long int n,i=0,j=0;
  printf("Please Enter Number of Processes : ");
  scanf("%ld",&n );
  double priority[n],avg_waiting,avg_turnaround,Burst_Time[n],Arrival_Time[n],Waiting_Time[n],Turn_around_Time[n], process[n], temp, completionTime[n],min,sum=0,sum2=0,wait_final, turnaround_final, wait_avg, turnaround_avg;
  for(i=0;i<n;i++)
  {
    printf("\nPlease Enter Burst Time for Process [%d] : ", i+1 );
    scanf("%lf", &Burst_Time[i]);
    printf("Please Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%lf", &Arrival_Time[i] );
    process[i]=i+1;
  }

  printf("\n\n\t\t\t Your Entered Values are\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],Arrival_Time[i],Burst_Time[i]);
  }
    printf("\t\t\t---------------------------------------\n");


  printf("\n\n\t\t\tSorting Processes according to Arrival_Time\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(Arrival_Time[i]<Arrival_Time[j])
      {

        temp = Burst_Time[j];
        Burst_Time[j] = Burst_Time[i];
        Burst_Time [i] = temp;

	      temp = process[j];
        process[j] = process[i];
        process[i] = temp;

	      temp = Arrival_Time[j];
        Arrival_Time[j] = Arrival_Time[i];
        Arrival_Time[i] = temp;

      }
    }
  }
  printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |\n",process[i],Arrival_Time[i],Burst_Time[i]);
  }
    printf("\t\t\t---------------------------------------\n");


  long int k = 1;
  double b_time = 0;
  for(j=0;j<n;j++)
  {
    b_time = b_time + Burst_Time[j];
    min = Burst_Time[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= Arrival_Time[i])&&(Burst_Time[i]<min))
      {
        temp = Burst_Time[k];
        Burst_Time[k] = Burst_Time[i];
        Burst_Time[i] = temp;

        temp = Arrival_Time[k];
        Arrival_Time[k] = Arrival_Time[i];
        Arrival_Time[i] = temp;

        temp = process[k];
        process[k] = process[i];
        process[i] = temp;
      }
    }
    k++;
  }
  Waiting_Time[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += Burst_Time[i-1];
    Waiting_Time[i] = sum - Arrival_Time[i];
    wait_final += Waiting_Time[i];
  }
  wait_avg = wait_final/n;
  for(i=0;i<n;i++)
  {
    sum2 += Burst_Time[i];
    Turn_around_Time[i] = sum2 - Arrival_Time[i];
    turnaround_final += Turn_around_Time[i];
  }
  turnaround_avg=turnaround_final/n;
printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],Arrival_Time[i],Burst_Time[i],Waiting_Time[i],Turn_around_Time[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");




  completionTime[0] = Burst_Time[0];
  for(i=1;i<n;i++)
  {
    completionTime[i] = completionTime[i-1] + Burst_Time[i];
  }

  for(i=0;i<n;i++)
  {
    priority[i] = 1+Waiting_Time[i]/completionTime[i];
    printf("%lf\n",priority[i]);
  }


  printf("\n\n\t\t\t -------------- Final Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[0],Arrival_Time[0],Burst_Time[0],Waiting_Time[0],Turn_around_Time[0]);
  for(i=n-1;i>0;i--)
  {
    printf("\t\t\t|  P[%0.0lf]   |       %0.0lf      |     %0.0lf      |        %0.0lf       |         %0.0lf          |\n",process[i],Arrival_Time[i],Burst_Time[i],Waiting_Time[i],Turn_around_Time[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");

  printf("\n\n\n\t\t\tAverage Turn Around Time : %lf",turnaround_avg);
  printf("\n\t\t\tAverage Waiting Time     : %lf\n\n",wait_avg);

  getch();
  return 0;
}
