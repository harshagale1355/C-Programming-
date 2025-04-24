#include<stdio.h>
#include<stdlib.h>
#include"Cdynamic.h"
void main(){
  int n,choice;
  NODE q;
  initQ(&q);
  do{
    printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.PEEK\n\t4.Display\n\t5.Exit");
    printf("\nEnter operation =  ");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      if(isfull(&q))
	printf("\n\n\n================OVERFLOW QUEUE===========================\n\n");
      else{
	printf("Enter the element to add: \n");
	scanf("%d",&n);
	enqueue(&q,n);
      }
      break;
    case 2:
      if(isempty(&q))
	printf("\n\n=====================UNDERFLOW QUEUE=======================\n\n");
      else
	printf("\n\nRemoved element is: %d\n",dequeue(&q));
      break;
    case 3:
      if(isempty(&q))
	printf("\n\n=====================UNDERFLOW QUEUE=======================\n\n");
      else
	printf("\n\nThe peek element is : %d\n",peek(&q));
      break;
    case 4:
      if(isempty(&q))
	printf("\n\n=====================UNDERFLOW QUEUE=======================\n\n");
      else
	display(&q);
      break;
    case 5:
      printf("\n\nExit\n");
      break;
    default:
      printf("\n\nNot available");
    }
  }while(choice!=5);
}                                                                                                                                                           
          