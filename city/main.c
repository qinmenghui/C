//软件192秦孟辉122122
//将若干城市的信息存入一个带头结点的单链表，结点中的城市信息包括城市名的位置坐标。
//要求：
//（1）给定一个城市名，返回其位置坐标
//（2）给定一个位置坐标P和一个距离D，返回所有与P的距离小于等于D的城市
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct Node{
    char name[10];
    int x;
    int y;
    struct Node *next;
}Node, *LinkList;
void Link(LinkList *link);
void input(LinkList link);
void print(LinkList link);
void searchByName(LinkList link,char *name);
void Location(LinkList link,int x,int y,int distance);
int main(){
    LinkList link;
    char name[20];
    int x,y,distance;
    Link(&link);
    input(link);
    print(link);
    printf("请输入您要查询的城市名：\n");
    scanf("%s",name);
    searchByName(link,name);
    printf("请输入该城市坐标和限定距离:\n");
    scanf("%d,%d,%d",&x,&y,&distance);
    Location(link,x,y,distance);
    free(Link);
    return 0;
}
void Link(LinkList *link){//初始化链表
    *link = (Node *)malloc(sizeof(Node));
    (*link)->next=NULL;
}
void print(LinkList link){//打印输出链表
    Node *p = link->next;
    while(p){
        printf("城市名:%s\tX坐标:%d\tY坐标：%d\n",p->name,p->x,p->y);
        p = p->next;
    }
}
void input(LinkList link) {//输入链表内数据
    Node *node;
    int time = 0;
    printf("请输入要输入的数据个数:\n");
    scanf("%d", &time);
    printf("请输入城市名及坐标:\n");
    for (int i = 0; i < time; i++) {
        node = (Node *) malloc(sizeof(Node));
        scanf("%s %d %d", node->name, &node->x, &node->y);
        link->next = node;
        link = node;
    }
    link->next = NULL;
}
//查找城市名
void searchByName(LinkList link,char *name){
    Node *node=link->next;
    while(node){
        if(strcmp(name,node->name)==0){
            printf("X坐标：%d\tY坐标：%d\n",node->x,node->y);
            break;
        }
        node = node->next;
    }
}
void Location(LinkList link,int x,int y,int distance){
    Node *node=link->next;
    while(node){
        if(sqrt(pow(x-node->x,2)+pow(y-node->y,2))<=distance){
            printf("城市:%s\n",node->name);
        }
        node=node->next;
    }
}