//题目：建立一个带头结点的线性链表，用以存放输入的二进制数，链表中每个结点的data域存放一个二进制位，
// 并在此链表上实现对二进制数加1对运算。

//想法：创建一个带头结点的单向链表，存放二进制。
//首元结点存放二进制数的最高位
//从低位往高位找到第一个值位0的位，把该位改为1，该位后面的数全部为0
//若未找到值为0的位，则该二进制数全为1，此时用头插法插入一个值为1的结点，并将其后所有结点变成0
#include "stdio.h"
#include "stdlib.h"

typedef  struct LinkList{
    int data;
    struct LinkList * next;
}Link;
Link *InitList(Link * head);//单链表的创建函数
Link *ListPlus1(Link *head);//实现+1
void Display(Link *head );//单链表的输出函数
int main()
{
    Link *head = NULL;//创建一个头指针
    printf("请输入一个十位二进制数字\n");
    head = InitList(head);//调用链表创建函数
    Display(head);//输出函数
    ListPlus1(head);
    Display(head);
    return 0;
}
Link *InitList(Link * head){
    int i = 0;
    int num[10];
    int length =sizeof(num)/sizeof(int);
    for(int i =0;i<length;i++){
        scanf("%d",&num[i]);
    }
    Link * node = NULL;//创造一个头结点
    head = (Link*)malloc(sizeof(Link));//初始化结点，分配内存
    head ->next = NULL;
    head ->data = 1;
    //声明一个指向头结点的指针，方便需要时向链表中添加新创建的结点
    node = head;
    //创建新的结点并初始化
    for(i=0;i<length;i++)
    {
        Link * body =(Link*)malloc(sizeof(Link));
        body ->next =NULL;
        body ->data =num[i];

        node ->next = body;
        node = node ->next;
    }
    return head;
}
void Display(Link * head){
    Link * p = head->next;
    while(p){
        if(p->next == NULL){
            printf("%d\n",p->data);
        }
        else {
            printf("%d->",p->data);
        }
        p = p ->next;
    }
}
Link *ListPlus1(Link * head) {
    Link *p, *s, *r;
    p = head->next;
    r = NULL;
    while (p != NULL) {
        if (p->data == 0)r = p;
        p = p->next;
    }
    //存在等于0的结点
    if (r != NULL) {
        r->data = 1;
        r = r->next;
        while (r != NULL) {
            r->data = 0;
            r = r->next;
        }
    }
        //不存在等于0的结点，即链表全部为1
    else {
        s = (Link *) malloc(sizeof(Link));
        s->data = 1;
        s->next = head->next;
        head->next = s;
        p = s->next;
        while (p != NULL) {
            p->data = 0;
            p = p->next;
        }
    }
    return head;
}