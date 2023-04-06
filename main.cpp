///////////////////Lab 05//////////////////
#include <iostream>
#include <chrono>
using namespace std;

////////implement stack using array////////////
#define MAX 1000
int stack_arr[MAX];
int top=-1;     //top=-1 indicates th stack is empty
void push(int data){
    if(top==MAX-1){
        cout<<"Stack overflow";
        return;
    }
    top++;
    stack_arr[top]=data;
}
int pop(){
    if(top==-1){
        cout<<"Stack underflow";
        exit(1);
    }
    top--;
    return stack_arr[top+1];
}
void display(){
    cout<<"[";
    for(int i=0;i<=top;i++){
        cout<<stack_arr[i]<<",";
    }
    cout<<"\b]\n";
}
///////////////implement stack using linked list/////////
struct node{
    int data;
    struct node *next;
};
struct node* head =NULL;
void Push(int data){
    struct node* tempNode=(struct node*)malloc(sizeof(struct node));
    tempNode->data=data;
    tempNode->next=head;
    head=tempNode;
}
int Pop(){
    if (head==NULL){cout << "Stack underflow";exit(1);}
    int data=head->data;
    head=head->next;
    return data;
}
void Display(){
    if(head==NULL){
        cout<<"Stack is empty"<<endl;
        exit(1);
    }
    node *tempNode=head;
    cout<<"[";
    cout<<head->data<<",";
    while(tempNode->next!=NULL){
        cout<<tempNode->data<<",";
        tempNode=tempNode->next;
    }
    cout<<"\b]\n";
}

int main() {
    //////////////////////////////////////////
    cout<<"Stacks implement using arrays"<<endl;
    auto begin1 =chrono::high_resolution_clock::now();
    push(8);
    push(10);
    push(5);
    push(11);
    push(15);
    push(23);
    push(6);
    push(18);
    push(20);
    push(17);
    display();
    //for(int i=0;i<5;i++){cout<<pop()<<endl;}
    for(int i=0;i<5;i++){pop();}
    display();
    push(4);
    push(30);
    push(3);
    push(1);
    display();
    auto end1 =chrono::high_resolution_clock::now();
    auto elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
    /////////////////////////////////////////////
    cout<<"Stack implement using LinkedList"<<endl;
    auto begin2 =chrono::high_resolution_clock::now();
    Push(8);
    Push(10);
    Push(5);
    Push(11);
    Push(15);
    Push(23);
    Push(6);
    Push(18);
    Push(20);
    Push(17);
    Display();
    //for(int i=0;i<5;i++){cout<<Pop()<<",";}
    for(int i=0;i<5;i++){Pop();}
    Display();
    Push(4);
    Push(30);
    Push(3);
    Push(1);
    Display();
    auto end2 =chrono::high_resolution_clock::now();
    elapsed =chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2);
    elapsed=elapsed*1000;
    printf("Time taken is: %.6f milliseconds.\n", elapsed.count() * 1e-9);
    return 0;
}
