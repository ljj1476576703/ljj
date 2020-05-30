#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct student)
		 struct student//定义学生信息结构体 
    {
    	int xuehao;
    	int banj;
    	char name[20];
    	char sex[5];
    	int yu;
    	int shu;
    	int ying;
    struct student*next;	
	}student[40]; 
	int t,i,n;
	struct student*head;
	struct student *p1,*p2;
	void zhu()
	{
		printf("-------------------------------------------------------\n");
	printf("           主菜单           \n");//主菜单 
	printf("           1.录入学生信息      \n");
	printf("           2.添加     \n");
	printf("           3.删除学生信息      \n");
	printf("           4.成绩排名   \n");
	printf("           5.查找学生信息   \n");
	printf("           6.导出学生信息    \n");
	printf("           输入7退出程序！       \n");
	printf("-------------------------------------------------------------\n");
	printf("请选择子菜单\n");
	scanf("%d",&t);
	}
void lu()//手动录入学生信息 
{
	for(i=0;i<n;i++)
    {
    	printf("请输入第%d个学生的学号：",i+1);
    	scanf("%d",&student[i].xuehao);
    	printf("请输入第%d个学生的班级：",i+1);
    	scanf("%d",&student[i].banj);
    	printf("请输入第%d个学生的姓名：",i+1);
    	scanf("%s",&student[i].name);
    	printf("请输入第%d个学生的性别：",i+1);
		scanf("%s",&student[i].sex);
		printf("请输入第%d个学生的语文成绩；",i+1);
    	scanf("%d",&student[i].yu);
    	printf("请输入第%d个学生的数学成绩：",i+1);
    	scanf("%d",&student[i].shu);
    	printf("请输入第%d个学生的英语成绩：",i+1);
    	scanf("%d",&student[i].ying);
    }
    printf("学生人数是：%d\n",n);
}
void ru()//从文件录入 
{
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	printf("学号：班级：姓名：性别：语文成绩：数学成绩：英语成绩：\n");
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d  %d  %s  %s   %d  %d  %d\n",&student[i].xuehao,&student[i].banj,&student[i].name,&student[i].sex,&student[i].yu,&student[i].shu,&student[i].ying);
		printf("%d  %d  %s  %s   %d  %d  %d\n",student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
	}
	printf("学生人数是：%d\n",n);
	fclose(fp);
}
struct student *creat()
	{
		int t;
		printf("请输入(输入0结束)：\n");
		printf("学号：班级：姓名：性别: 语文成绩：数学成绩：英语成绩；\n"); 
		t=0;
		p1=p2=(struct student*)malloc(LEN);
		printf("请输入学号:");
		scanf("%d",&p1->xuehao);
		printf("请输入班级:");
		scanf("%d",&p1->banj);
		printf("请输入姓名:");
		scanf("%s",&p1->name);
		printf("请输入性别:");
		scanf("%s",&p1->sex);
		printf("请输入语文成绩:");
		scanf("%d",&p1->yu);
		printf("请输入数学成绩:");
		scanf("%d",&p1->shu);
		printf("请输入英语成绩:");
		scanf("%d\n",&p1->ying);
		head=NULL;
		while(p1->xuehao==0)
		{
		t=t+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		printf("请输入学号:");
		scanf("%d",&p1->xuehao);
		printf("请输入班级:");
		scanf("%d",&p1->banj);
		printf("请输入姓名:");
		scanf("%s",&p1->name);
		printf("请输入性别:");
		scanf("%s",&p1->sex);
		printf("请输入语文成绩:");
		scanf("%d",&p1->yu);
		printf("请输入数学成绩:");
		scanf("%d",&p1->shu);
		printf("请输入英语成绩：");
		scanf("%d",&p1->ying);
		}
		p2->next=NULL;
		return(head);
		n=n+t;
		printf("添加后学生人数：%d",n);
	}
void print(struct student *head)
{	
	printf("请检查：\n");
	struct student*p;
	printf("您添加的信息如下：\n");
	p=head;
	if(head!=NULL)
	do
	{
		printf("学号：%d 班级：%d 姓名：%s 性别：%s 语文成绩：%d 数学成绩：%d 英语成绩；%d\n",p->xuehao,p->banj,p->name[20],p->sex,p->yu,p->shu,p->ying);
		p=p->next;
	}while(p!=NULL);
} 
void shanchu()
{
	int num;
	printf("请输入一个序号：");
	scanf("%d",&num);
	p1 = head;
	while(p1->next) {
		p2 = p1->next;
		if(p2->xuehao==num){
			p1->next = p2->next;
			free(p2);
		}
		else p1 = p2;
	}
	p1 = head->next;
	while(p1){
		printf("%d ",p1->xuehao);
		printf("%d",p1->banj);
		printf("%s",p1->name);
		printf("%s",p1->sex);
		printf("%d",p1->yu);
		printf("%d",p1->shu);
		printf("%d",p1->ying);
		p1 = p1->next;
	}
}
void pai()//排序 
{
    int j,k;
	int sum[40];
	for(i=0;i<n;i++)
	{
		sum[i]=student[i].yu+student[i].shu+student[i].ying;
	}
    struct student temp;
    for(i=0;i<n-1;i++)
    {k=i;
    	for(j=i+1;j<n;j++)
    	if(sum[j]>sum[k])
    	k=j;
    	temp=student[k];student[k]=student[i];student[i]=temp; 
   }
   printf("从大到小排序后的信息：\n");
   printf("学号:    班级：   姓名：  性别：  语文成绩：  数学成绩：  英语成绩： 总分： \n"); 
	for(i=0;i<n;i++)
	{
		printf("%d   %d  %s  %s  %d  %d  %d   %d\n",student[i].xuehao,student[i].banj,student[i].name[5],student[i].sex[5],student[i].yu,student[i].shu,student[i].ying,sum[i]);
	}
}
void cha()//查询 
{
	int p,f;
	printf("请输入1或2查询！（1：学号或2：姓名）\n");
	scanf("%d",&p);
	f=0;
	if(p==1)//按学号查询 
	{
		int o;
 	int f=0;
	printf("请输入学号：\n");
	scanf("%d",&o);
	for(i=0;i<n;i++)
		if(student[i].xuehao==o)
		{
			f=f+1;
		printf("学号：%d 班级：%d 姓名：%s 性别：%s 语文成绩：%d 数学成绩：%d 英语成绩；%d\n",
		student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying); 
		break;
		}
	     if(f==0)
	     {
		 printf("查无此人！\n");
		 }
	}
	if(p==2)//按名字查询 
	{
	char o[20];
	printf("请输入姓名：\n");
	scanf("%s",&o);
	for(i=0;i<n;i++)
		if(strcmp(student[i].name,o)==0)
		{
			f=1;
		printf("学号：%d 班级：%d 姓名：%s 性别：%s 语文成绩：%d 数学成绩：%d 英语成绩；%d\n",
		student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
		}
	     if(f==0)
	     {
		 printf("查无此人！\n");
		 }
	}
}
void dao()//保存学生信息到文件 
{
	scanf("%d",&n);
	FILE *fp=NULL;
	fp=fopen("student.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d，%d，%s，%s，%d，%d，%d\n",student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
	}
	fclose(fp);
}
int main()
{
	void zhu();
    void lu();
	void ru();
	void cha();
	void shanchu();
	void pai();
	void dao();
	printf("首先请输入想要输入的学生信息的人数：\n");
	scanf("%d",&n);	
   while(1)
    {
    	zhu();
    	system("cls");
	if(t==7)
	{
		printf("感谢使用！");
	break;
	}
  switch(t)
	    {
		case 1: 
		printf("1：手动录入\n");
		printf("2：从文件读取\n");
		printf("请输入1或2选择你的操作(输入0退出菜单)\n");
		int r;
		scanf("%d",&r);
			if(r==1){lu();}
			if(r==2){ru();}
			break; 
		case 2:
			head=creat();
			print(head);
			break;
			case 3:
				shanchu();
				break;
		case 4:
		    pai();
		    break;
		case 5:
		    cha();
			break;  
		case 6 :
			dao(); 
			printf("导入完成！");
		    break;
		default:
			printf("输入错误！\n");
			break; 
	    }
    } 
	return 0;
}
