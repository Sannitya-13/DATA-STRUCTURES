#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
	struct node *prev;
};
void insert(struct node**, int, int);
void delete(struct node**, int);
void traversal(struct node*);
struct node *search(struct node*, int);

int main(){
	int choice, want_continue, pos, data, key;
	struct node *head = NULL, *r;
	printf("Enter the choice 1.Insert 2.Delete 3.Traversal 4.Search\n");
	do{
		printf("Enter choice:");
		scanf("%d", &choice);
		switch(choice) {
			case 1:printf("Enter the Position and Data:");
				scanf("%d%d", &pos, &data);
				insert(&head, pos, data);
				break;
			case 2:printf("Enter the position to delete:");
				scanf("%d", &pos);
				delete(&head, pos);
				break;
			case 3:traversal(head);
				break;
			case 4:printf("Enter the key:");
				scanf("%d", &key);
				r = search(head, key);
				if(r == NULL)
					printf("Unsuccessful search\n");
				else
					printf("Successful search\n");
				break;
		}
		printf("Want to continue : Enter 1: ");
		scanf("%d",&want_continue);
	}while(want_continue == 1);
	return 0;
}
void insert(struct node **head, int pos, int data){
	struct node *temp, *p;
	int k = 1;
	temp = (struct node*)malloc(sizeof(struct node));
	temp -> data = data;
	p = *head;
	if(pos == 1){
		temp -> next = *head;
		temp -> prev = NULL;
		if(*head){
			(*head) -> prev = temp;
			}
		*head = temp;
		}
	else {
		while((k < pos - 1) && p -> next != NULL){
			p = p -> next;
			k++;
			}
		if(k != pos - 1){
			printf("Position doesn't exist\n");
			return;
			}
		temp -> next = p -> next;
		temp -> prev = p;
		if(p -> next)
			p -> next -> prev = temp;
		p -> next = temp;
		}
	}
void delete(struct node **head, int pos) {
	struct node *p, *q;
	int k = 1;
	p = *head;
	if(pos == 1){
		*head = (*head) -> next;
		if(*head) 
			(*head) -> prev = NULL;
		free(p);
	}
	else{
		while((k < pos) && (p -> next != NULL)){
			p = p -> next;
			k++;
		}
		if(k != pos){
			printf("Position doesn't exist\n");
			return;
		}
		q = p -> prev;
		q -> next = p -> next;
		if(p -> next) 
			p -> next -> prev = q;
		free(p);
	}
}
void traversal(struct node *head){
	struct node *p;
	int data;
	p = head;
	while(p != NULL){
		printf("%d\t", p -> data);
		p = p -> next;
		}
		printf("\n");
}
struct node *search(struct node *head, int key) {
	struct node *p;
	p = head;
	while(p != NULL){
		if(p -> data == key){
			return p;
			}
		p = p -> next;
	}
	return NULL;
}

