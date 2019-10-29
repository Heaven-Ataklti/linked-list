#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
struct node *prev;
};
struct node *head = NULL;
struct node *tail=NULL;

void insert(int data){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->data=data;
	temp->next=NULL;
	temp->prev=NULL;
	if(head==NULL){
		head=tail=temp;
	}
	else{
		tail->next=temp;
		tail->prev=tail;
		tail=temp;
	}
}

void delete(int data){
	if(head==NULL){
		printf("no data");
	}
	else{
		struct node *temp=head,*temp2;
		while(temp->data!=data){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next=temp->next;
		temp->next->prev=temp2;
	}
}

void display(){
	struct node *ptr=head;
	while(ptr!=NULL){
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}

int main(){
	int data,i;
	printf("insert 3 items\n");
	for(i=0;i<=2;i++){
		scanf("%d",&data);
		insert(data);
		printf("\n");
		display();
		printf("\n");
	}
	delete(3);
	printf("\n");
	display();

}
