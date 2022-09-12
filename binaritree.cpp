#include<bits/stdc++.h>
#include "queue.h"
#include "stack.h"

using namespace std;




     struct Node *root=NULL;


    void Treecreate()
    {
        struct Node *p,*temp;
        struct Queue q;
        int x;
        create(&q,100);
        cout<<"enter a root number";
        scanf("%d",&x);
        root = (struct Node *)malloc (sizeof(struct Node));
        root->data=x;
        root->lchild=root->rchild=NULL;
        enqueue(&q,root);
        while(!isEmpty(q))
        {
            p=dequeue(&q);
            cout<<"enter left child of "<<p->data;
            scanf("%d",&x);
            if(x!=-1)
            {
                temp = (struct Node *)malloc (sizeof(struct Node)) ;
                temp->data=x;
                temp->lchild=temp->rchild=NULL;
                p->lchild=temp;
                enqueue(&q,temp);
            }

            cout<<"enter right child "<<p->data;
            scanf("%d",&x);
            if(x!=-1)
            {
                temp =  (struct Node *)malloc (sizeof(struct Node)) ;
                temp->data=x;
                temp->lchild=temp->rchild=NULL;
                p->rchild=temp;
                enqueue(&q,temp);
            }
        }


    }


 void Preorder(struct Node *p)
  {
   if(p)
  {
   printf("%d ",p->data);
   Preorder(p->lchild);
   Preorder(p->rchild);
  }
  }

void Inorder(struct Node *p)
{
if(p)
{
    Inorder(p->lchild);
     printf("%d ",p->data); 
     Inorder(p->rchild);
}
}
void Postorder(struct Node *p)
{
   if(p)
   {
       Postorder(p->lchild); 
       Postorder(p->rchild);
       printf("%d ",p->data);
   }
}



void Itr_preorder(struct Node *t )
{
    struct stack st;
    create_s(&st,100);
    while(t!=NULL||!isempty(st))
    {
        if(t!=NULL)
        {
            printf("%d",t->data);
            push(&st,t);
            t=t->lchild;
        }
        else
        {
            t=pop(&st);
            t=t->rchild;
        }
    }
}

void level_order(struct Node *t)
{
    struct Queue q1;
    create(&q1,100);
    printf("%d",t->data);
    enqueue(&q1,t);
    while(!isEmpty(q1))
    {
        t=dequeue(&q1);
        if(t->lchild)
        {
            printf("%d",t->lchild->data);
            enqueue(&q1,t->lchild);
        }
        if(t->rchild)
        {
            printf("%d",t->rchild->data);
            enqueue(&q1,t->rchild);
        }

    }

}

int count(struct Node *p)
{
    int x,y;
    if(p!=NULL)
    {
        x=count(p->lchild);
        y=count(p->rchild);

        return x+y+1;
    }
    return 0;
}

int main()
{
    Treecreate();
    printf("\nPost Order ");
    //Postorder(root);
    printf(" \n");
    //printf("%d",count(root));
    //level_order(root);
    Itr_preorder(root);



    return 0;
}

