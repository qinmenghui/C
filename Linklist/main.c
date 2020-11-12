#include <stdio.h>
#include <string.h>
#include <math.h>
struct link
{
    struct link *pre;
    char a;
    struct  link *next;
}LINK[10];
int main() {
    struct link *head,*p,*p1;
    struct link string[10];
    int i;
    printf("put in the string:\n");
    for(i=0;i<10;i++)
    {
        scanf("%c",&(string[i].a));
    }
    for(i=0;i<10;i++)
    {
        printf("%c",string[i].a);
    }
    head = string;
    p=string;
    ++p;
    head->pre=NULL;
    head->next=p;
    for(i=1;i<10;i++)
    {
        p1=p;
        p->pre=--p1;
        p->next=++p;
    }
    p1=head;
    for(i=0;i<10;i++)
    {
        printf("%c",(p1+i)->a);
    }
    return 0;
}
