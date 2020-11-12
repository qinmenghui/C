
//商品货架可以看作一个栈，栈顶商品的生产日期最早
//栈底商品的生产日期最近，上货时，需要倒货架，以
//保证生产日期较近的商品在较下的位置。用队列和栈
//作为周转，实现上述管理过程。

//受到栈用递归解决栈颠倒的问题的启发，决定用递归
//来给栈排序。

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 20

typedef struct commodity
{
    char NAME[MAX_SIZE];
    int Date[2];			//以年/月的形式记录日期
    struct commodity* next;
}Node;

Node* creatStack(void)		//创建栈
{
    Node* top;
    top = (Node*)malloc(sizeof(Node));
    if (top != NULL)
    {
        top->next = NULL;
        return top;
    }
    printf("Out of place.\n");
    return NULL;
}

//压入栈元素
void pushStack(Node* top, Node* inform)
{
    inform->next = top->next;
    top->next = inform;
}

//出栈
Node* popStack(Node* top)
{
    Node* newp;
    if (top->next != NULL)
    {
        newp = top->next;
        top->next = newp->next;
        return newp;
    }
    return NULL;
}

//获取栈顶元素的日期
int* GetTop(Node* top)
{
    if (top->next != NULL)
        return top->next->Date;
    else
        return NULL;
}

//录入信息
void importElem(Node* top)
{
    Node* temp = (Node*)malloc(sizeof(Node));
    printf("Please enter the information for the first item:\n");
    printf("NAME:");
    scanf("%s", temp->NAME);
    printf("DATE(y/m):");
    scanf("%d/%d", &temp->Date[0], &temp->Date[1]);
    pushStack(top, temp);
}

//重复录入信息
void repetitionImp(Node* top)
{
    int decide;
    printf("Whether to enter commodity information?(1/0):");
    scanf("%d", &decide);
    if (decide == 1)
    {
        importElem(top);
        repetitionImp(top);
    }
}

//递归排序
void SortStack(Node* top)
{
    Node* temp;
    Node* Max;
    int* topDate;
    temp = popStack(top);
    if (top->next == NULL)
        exit(0);
    if (top->next->next != NULL)	//空栈时未判定
        SortStack(top);				//将剩下的Stack进行递归
    topDate = GetTop(top);
    if (temp->Date[0] > topDate[0])	//先将年进行比较
    {
        Max = popStack(top);
        pushStack(top, temp);
        pushStack(top, Max);
    }else if (temp->Date[1] > topDate[1])
    {
        Max = popStack(top);
        pushStack(top, temp);
        pushStack(top, Max);
    }
    else
        pushStack(top, temp);
}

void printStack(Node* top)
{
    Node* temp = top->next;
    while (temp != NULL)
    {
        printf("NAME:%s\t", temp->NAME);
        printf("DATA:%d/%d\n", temp->Date[0], temp->Date[1]);
        temp = temp->next;
    }
}

//主函数
void main()
{
    Node* top;
    top = creatStack();
    if (top == NULL)
        exit(0);
    repetitionImp(top);
    printStack(top);
    SortStack(top);
    printStack(top);
}