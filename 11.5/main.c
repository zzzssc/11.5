#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define ERROR NULL
typedef int ElementType;
typedef struct snode{
    int data;
    struct snode *next;
}*snodestr;
typedef snodestr stack;
stack creatstack() //建立堆栈
{
    stack s;
    s=malloc(sizeof(struct snode));
    s->next = NULL;
    return s;
}
bool isempty(stack s)//判断是否为空
{
    return (s->next = NULL);
}
bool push(stack s,int x)
{
    snodestr t;
    t=malloc(sizeof(struct snode));
    if(!t)
    {
        printf("申请结点失败！");
        exit(-1);
    }
    t->data = x;
    t->next = s->next; //用的头插法
    s->next = t;
    return true;
}
ElementType pop(stack s)
{
    snodestr f;
    ElementType i;
    if(isempty(s))
    {
        printf("栈已空");
        return ERROR;
    }
    else{
    
            f=s->next;
            i=f->data;
            s->next = f->next;
            free(f);
            return i;
        }

}

int main(int argc, const char * argv[]) {
    snodestr s;
    s = creatstack();
    for(int i=9;i>=0;i--)
    {
        push(s,i);
    }
    snodestr p;
    for(p = s->next;p!=NULL;p=p->next) //链式不能用加加
    {
        printf("%d ",p->data);
    }
    printf("\n");
    pop(s);
    pop(s);
    for(p=s->next;p!=NULL;p=p->next)
    {
        printf("%d ",p->data);
    }
    printf("\n");
    return 0;
}
