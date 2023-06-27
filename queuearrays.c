 //queue using arrays
#include<stdio.h>
int queue[100],front=-1,rear=-1,max_size;
void enque(int val){
	if(rear==max_size-1){
		printf("Queue is full\n");
	}
	else if(front==-1 && rear==-1){
		front++;
		rear++;
		queue[rear]=val;
	}
	else{
		queue[++rear]=val;
	}
}
int deque(){
	if(front==-1 && rear==-1){
		return -1;
	}
	else if(front==rear){
		int de=queue[rear];
		rear=-1;
		front=-1;
		return de;
	}
	else{
		int de=queue[front++];
		return de;
	}
}
void display(){
	if(front==-1 && rear==-1){
		printf("queue is empty\n");
		return;
	}
	int i;
	for ( i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}
int main(){
    printf("Enter maximum size of queue:");
	scanf("%d",&max_size);
	int choice;
	while(1){
		printf("Enter\n1.Enque\n2.Deque\n3.Display\n Any other to display");
		scanf("%d",&choice);
		if(choice==1){
			//enque()
			int val;
			printf("Enter a value:");
			scanf("%d",&val);
			enque(val);
		}
		else if(choice==2){
			//deque()
			int res=deque();
			if (res==-1){
				printf("Queue is empty");
			}
			else{
				printf("%d is deleted \n",res);
			}
		}
		else if(choice==3){
			//display()
			display();
		}
		else{
			break;
		}
	}	
}
