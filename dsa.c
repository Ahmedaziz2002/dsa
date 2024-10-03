#include<stdio.h>
int main(){
    /*The first basic data structure We will learn is array*/
    /*An array is a collection of elements of the same type*/
    /*xtics=fixed size,homogenous elements,random access*/
    int arr[5]={5,7,8,2,3};/*declaration and initialization of an array*/
    int i;
    for(i=0;i<=4;i++){
        printf("The element %d is %d\n",i,arr[i]);
    }
    printf("Now we will print element 1 %d",arr[0]);
    return 0;

}#include<stdio.h>
#include<stdlib.h>//all programs using malloc or realloc have to include the stdlib file
int main(){
    /*Here we will seee how to dynamically allocate memeory to an array using pointers*/

    int n; //number of elements
    printf("Enter the size of the array");//prompt user to specify the size
    scanf("%d",&n);

    int *arr=(int *)malloc(n* sizeof(int));//dynamically allocating memory using malloc


    if(arr==NULL){
        printf("Memory could not be alllocated!");//checking if the memory is null the program exits
        return 1;
    }
    for(int i=0;i<n;i++){//initialize and print the array
        arr[i]=i+1;//assign values
        printf("%d\n",arr[i]);
       
    }
    printf("Size of array is %d\n",sizeof(*arr));
    free(arr);//deallocates the memory using free 
    return 0;
}#include<stdio.h>
#include<stdlib.h>//all programs using malloc or realloc have to include the stdlib file
int main(){
    /*Here we will seee how to dynamically allocate memeory to an array using pointers*/

    int n; //number of elements
    printf("Enter the size of the array");//prompt user to specify the size
    scanf("%d",&n);

    int *arr=(int *)malloc(n* sizeof(int));//dynamically allocating memory using malloc

    n=10;
    arr=(int *)realloc(arr,n* sizeof(int));//reallocates the array size memory

    if(arr==NULL){
        printf("Memory could not be alllocated!");//checking if the memory is null the program exits
        return 1;
    }
    for(int i=0;i<n;i++){//initialize and print the array
        arr[i]=i+1;//assign values
        printf("%d\n",arr[i]);
       
    }
    printf("Size of array is %d\n",sizeof(arr));
    free(arr);//deallocates the memory using free 
    return 0;
}#include<stdio.h>
int main(){
    /*Linked lists are a fundamental data structure used to store collections of data dynamically.*/
    /*They do not require contiguous memory alloation,allowing for efficient insertion and deletion operations*/
    /*A linked list consists of nodes where each node consist of tow main components data and pointer*/
    /*3 types of linked list-Single ll-each node points to the next node(forward traversal)
    Double ll-each node contains pointer to both the next and previous node(backward and forward traversal)
    Circular linked list-Similar to single but the last node points to the first node*/
    /*Ops on ll are traversal,insertion and deletion*/
    /*Creating a linked list involves several steps,creating the structure for the node plus all their oprations and managing memory*/

    
}#include<stdio.h>
#include<stdlib.h>

struct Node{//creating the structure for the node
    int data;//data
    struct Node* next;//pointer to the next node
};
//Now we will create functions for linked list ops we start with insertion
void insertatbeginning(struct Node** head,int new_data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));//allocate memory
    newnode->data=new_data;//assign data to new node
    newnode->next=(*head);//Link the old list of the new node
    (*head)=newnode;//Move the head to point to the new node
}
void printlist(struct Node* node){
    while(node != NULL){
        printf("%d ->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;//initialize an empty list

    insertatbeginning(&head,1);
    insertatbeginning(&head,4);
    insertatbeginning(&head,8);

    printf("Linked list after insertion:\n");
    printlist(head);

    return 0;


}#include<stdio.h>
#include<stdlib.h>

struct Node{//DEfine the NOde structure
    int data;
    struct Node* next;
};

//create a function to insert node at the beginning

void insertAtBeginning(struct Node** head,int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    if(newnode==NULL){
        printf("Memory allocation failed!\n");
        return;
    }

    newnode->data=newdata;
    newnode->next=(*head);
    (*head)=newnode;
}//This function to insert a node at the beginning is correct
void deletenode(struct Node **head,int key){
    struct Node* temp=*head;
    struct Node* prev=NULL;
//if node itself holds the key to be deleted
    if(temp !=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    //search for the key to be deleted keeping track of the previous node
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    //if key is not present in linked list
    if(temp==NULL)return;
    //remove the node from the linked list
    prev->next=temp->next;
    free(temp);

}
void displaylist(struct Node* node){
    while(node!=NULL){
        printf("%d->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;

    insertAtBeginning(&head,6);
    insertAtBeginning(&head,8);
    insertAtBeginning(&head,10);

    printf("LInked list after insertion is:\n");
    displaylist(head);

    deletenode(&head,6);
    deletenode(&head,2);

    printf("Linked list after deletion is:\n");
    displaylist(head);

    return 0;
}#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void insertAtBeginning(struct Node ** head,int newdata){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));

    if(newnode==NULL){
        printf("Memory could not be allocated\n");
    }
    newnode->data=newdata;
    newnode->next=(*head);
    (*head)=newnode;
}
void deleteNode(struct Node ** head,int key){
    struct Node* temp=*head;
    struct Node* prev=NULL;

    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL){
        printf("Key not foound in the list\n");
        return;
    }
    prev->next=temp->next;
    free(temp);
    return;
}
void displayList(struct Node* node){
    while(node!=NULL){
        printf("%d->",node->data);
        node=node->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head=NULL;
    int n,data,key;

    printf("Enter the number of nodes:\n");
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        printf("Enter the data for the nodes",i+1);
        scanf("%d",&data);
        insertAtBeginning(&head,data);
    }
    printf("Original list:\n");
    displayList(head);

    printf("Enter the key to delete:\n");
    scanf("%d",&key);
    deleteNode(&head,key);

    printf("List after deletion:\n");
    displayList(head);

    while(head!=NULL){
        struct Node* temp=head;
        head=head->next;
        free(temp);
    }
    return 0;
}
