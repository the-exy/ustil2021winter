#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student
{
	char name[20];
	char score[10];
	struct Student* next;
}S;
S*  creat()
{
	printf("                                                进行链表初始化：\n");
	S* head = (S*)malloc(sizeof(S));
	S* p = head;
	printf("输入两次信息：\n");
	for (int i = 0; i < 2; i++)
	{
		S* s = (S*)malloc(sizeof(S));
		printf("请输入姓名：\n");
		gets(s->name);
		printf("请输入成绩：\n");
		gets(s->score);
		p->next = s;
		p = p->next;
		s->next = NULL;
	}
	printf("初始化完成！进入主菜单");
	return head;
}
void bianli(S* head)
{
	S* p = head;
	int i = 1;
	while (p->next)
	{
		p = p->next;
		printf("第%d个学生的名字是:%s   成绩为：%s\n", i, p->name,p->score);
		i++;
	}
}
void charu(S* head)
{
	S* p1 = head->next;
	S* p = (S*)malloc(sizeof(S));
	printf("请输入学生姓名：\n");
	gets(p->name);
	printf("请输入学生成绩：\n");
	gets(p->score);
	head->next = p;
	p->next = NULL;
	if (p1->next)
		p->next = p1;
	printf("增加成功！返回主菜单\n");
}
void change(S* head)
{
	printf("请输入要修改成绩的学生序号：\n");
	int n,m=1;
	scanf_s("%d", &n);
	int c = getchar();
	S* p = head;
	while (head->next)
	{
		if (n == m)
		{
			printf("请输入要修改的成绩：\n");
			char a[10];
			gets(a);
		//	p->score= a;
			printf("修改成功！返回主菜单\n");
			break;
		}
		else
		{
			m++;
			p = p->next;
			
		}
	}
	if(n!=m)
	printf("没有找到该学生，返回主菜单。\n");
	
}
void shanchu(S* head)
{
	int n;
	printf("请输入要删除的第n号数据:、\n");
	scanf_s("%d", &n);
	int c=getchar();
	int m = 1;
	S* p1 = head;
	S* p2 = head->next;
	while (p1->next)
	{
		if (n == m)
		{
			p1->next = p2->next;
			free(p2);
			printf("删除成功！返回主菜单\n");
			break;
		}
		else
		{
			p1 = p2;
			p2 = p2->next;
			m++;
		}
	}
	if (n != m)
		printf("没有找到该学生！返回主菜单");
}
void Selection(S* head,int n)
 {
	 switch(n)
	 {
	 case 1:bianli(head); break;
	 case 2:charu(head); break;
	 case 3:shanchu(head); break;
	 case 4:change(head); break;
	 default:
		 printf("请输入有效选项！");
		 break;
	 }
 }
void List()
{
	printf("                                        菜单：\n");
	printf("1.遍历\n");
	printf("2.插入\n");
	printf("3.删除\n");
	printf("4.修改\n");
	printf("请输入要进行的选项：\n");
}
void menu()
{
	int n;
	S* head = creat();
	List();
	while (~scanf_s("%d", &n))
	{
		getchar();
		Selection(head,n);
	}
}
void main()
{
	menu();
}
