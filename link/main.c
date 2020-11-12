
typedef struct Snode
{
    int data;
    Snode *next;
}Snode,*PSnode;
void BinaryAddOne(PSnode&L)
{						//链表表头到表尾依次为高位到低位
PSnode Temp, q, p, s;
q = L->next;      //遍历查找的头指针
p = L;
s = NULL;         //查找0位的标记指针
while (q)
{
if (q->data==0)
s = q;		//记录从最高位开始的最后一个0位的位置
q = q->next;
}

if (s)
{
s->data = 1;	//记录的位置变为1
s = s->next;
while (s)
{
s->data = 0;//其后边的1位全变为0
s = s->next;
}
}
else
{//Temp 为二进制位满1时新进位空间开辟指针 形如1 3 7 15等二进制表示的下一个高位
Temp = new Snode;
Temp->data = 1;			//采用头插法进行新进位的添加
Temp->next = p->next;
p->next = Temp;
Temp = Temp->next;
while (Temp)				//新进位后的所有1位全变为0
{
Temp->data = 0;
Temp = Temp->next;
}
}

}
