#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

int search(int in[],int s,int e,int val){
    for(int i=s;i<=e;i++)
        if(in[i]==val) return i;
    return -1;
}

struct node* build(int in[],int post[],int s,int e,int *p){
    if(s>e) return NULL;

    struct node* t=(struct node*)malloc(sizeof(struct node));
    t->data=post[*p];
    (*p)--;

    if(s==e) return t;

    int i=search(in,s,e,t->data);

    t->right=build(in,post,i+1,e,p);
    t->left=build(in,post,s,i-1,p);

    return t;
}

void preorder(struct node* t){
    if(t){
        printf("%d ",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}

int main(){
    int n;
    scanf("%d",&n);

    int in[n],post[n];
    for(int i=0;i<n;i++) scanf("%d",&in[i]);
    for(int i=0;i<n;i++) scanf("%d",&post[i]);

    int p=n-1;
    struct node* root=build(in,post,0,n-1,&p);

    preorder(root);
}