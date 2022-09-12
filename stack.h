struct Node
{
   struct Node *lchild;
   int data;
   struct Node *rchild;
};


struct stack
{
    int size;
    int top=-1;
    struct Node **p;
};
void create_s(struct stack *s1,int size)
{
    s1->size=size;
    s1->p=new int[s1->size];
}

void push(struct stack *s1,int x)
{
    if(s1->top==s1->size-1)
    cout<<"stack overflow";
    else
    {
        s1->top++;
        s1->p[s1->top]=x;

    }
}
int pop(struct stack *s1)
{
    int x=-1;
    if(s1->top==-1)
    cout<<"Stack underflow";
    else
    x=s1->p[s1->top--];
    return x;
}
void display(struct stack *s1)
{
    for(int i=s1->top;i>=0;i--)
    {
        cout<<s1->p[i]<<" ";
    }
}
int peek(struct stack s1,int pos)
{
    int x=-1;
    if(s1.top-pos+1<0)
    cout<<"invalid position";
    else{
        x=s1.p[s1.top-pos+1];
    }
    return x;
}

int isempty(struct stack s1)
{
    if(s1.top==-1)
    return 1;
    else
    return 0;
}