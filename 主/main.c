#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
#define LEN sizeof(struct student)
		 struct student//����ѧ����Ϣ�ṹ�� 
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
	printf("           ���˵�           \n");//���˵� 
	printf("           1.¼��ѧ����Ϣ      \n");
	printf("           2.���     \n");
	printf("           3.ɾ��ѧ����Ϣ      \n");
	printf("           4.�ɼ�����   \n");
	printf("           5.����ѧ����Ϣ   \n");
	printf("           6.����ѧ����Ϣ    \n");
	printf("           ����7�˳�����       \n");
	printf("-------------------------------------------------------------\n");
	printf("��ѡ���Ӳ˵�\n");
	scanf("%d",&t);
	}
void lu()//�ֶ�¼��ѧ����Ϣ 
{
	for(i=0;i<n;i++)
    {
    	printf("�������%d��ѧ����ѧ�ţ�",i+1);
    	scanf("%d",&student[i].xuehao);
    	printf("�������%d��ѧ���İ༶��",i+1);
    	scanf("%d",&student[i].banj);
    	printf("�������%d��ѧ����������",i+1);
    	scanf("%s",&student[i].name);
    	printf("�������%d��ѧ�����Ա�",i+1);
		scanf("%s",&student[i].sex);
		printf("�������%d��ѧ�������ĳɼ���",i+1);
    	scanf("%d",&student[i].yu);
    	printf("�������%d��ѧ������ѧ�ɼ���",i+1);
    	scanf("%d",&student[i].shu);
    	printf("�������%d��ѧ����Ӣ��ɼ���",i+1);
    	scanf("%d",&student[i].ying);
    }
    printf("ѧ�������ǣ�%d\n",n);
}
void ru()//���ļ�¼�� 
{
	FILE *fp=NULL;
	fp=fopen("student.txt","r");
	printf("ѧ�ţ��༶���������Ա����ĳɼ�����ѧ�ɼ���Ӣ��ɼ���\n");
	for(i=0;i<n;i++)
	{
		fscanf(fp,"%d  %d  %s  %s   %d  %d  %d\n",&student[i].xuehao,&student[i].banj,&student[i].name,&student[i].sex,&student[i].yu,&student[i].shu,&student[i].ying);
		printf("%d  %d  %s  %s   %d  %d  %d\n",student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
	}
	printf("ѧ�������ǣ�%d\n",n);
	fclose(fp);
}
struct student *creat()
	{
		int t;
		printf("������(����0����)��\n");
		printf("ѧ�ţ��༶���������Ա�: ���ĳɼ�����ѧ�ɼ���Ӣ��ɼ���\n"); 
		t=0;
		p1=p2=(struct student*)malloc(LEN);
		printf("������ѧ��:");
		scanf("%d",&p1->xuehao);
		printf("������༶:");
		scanf("%d",&p1->banj);
		printf("����������:");
		scanf("%s",&p1->name);
		printf("�������Ա�:");
		scanf("%s",&p1->sex);
		printf("���������ĳɼ�:");
		scanf("%d",&p1->yu);
		printf("��������ѧ�ɼ�:");
		scanf("%d",&p1->shu);
		printf("������Ӣ��ɼ�:");
		scanf("%d\n",&p1->ying);
		head=NULL;
		while(p1->xuehao==0)
		{
		t=t+1;
		if(n==1)head=p1;
		else p2->next=p1;
		p2=p1;
		p1=(struct student*)malloc(LEN);
		printf("������ѧ��:");
		scanf("%d",&p1->xuehao);
		printf("������༶:");
		scanf("%d",&p1->banj);
		printf("����������:");
		scanf("%s",&p1->name);
		printf("�������Ա�:");
		scanf("%s",&p1->sex);
		printf("���������ĳɼ�:");
		scanf("%d",&p1->yu);
		printf("��������ѧ�ɼ�:");
		scanf("%d",&p1->shu);
		printf("������Ӣ��ɼ���");
		scanf("%d",&p1->ying);
		}
		p2->next=NULL;
		return(head);
		n=n+t;
		printf("��Ӻ�ѧ��������%d",n);
	}
void print(struct student *head)
{	
	printf("���飺\n");
	struct student*p;
	printf("����ӵ���Ϣ���£�\n");
	p=head;
	if(head!=NULL)
	do
	{
		printf("ѧ�ţ�%d �༶��%d ������%s �Ա�%s ���ĳɼ���%d ��ѧ�ɼ���%d Ӣ��ɼ���%d\n",p->xuehao,p->banj,p->name[20],p->sex,p->yu,p->shu,p->ying);
		p=p->next;
	}while(p!=NULL);
} 
void shanchu()
{
	int num;
	printf("������һ����ţ�");
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
void pai()//���� 
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
   printf("�Ӵ�С��������Ϣ��\n");
   printf("ѧ��:    �༶��   ������  �Ա�  ���ĳɼ���  ��ѧ�ɼ���  Ӣ��ɼ��� �ܷ֣� \n"); 
	for(i=0;i<n;i++)
	{
		printf("%d   %d  %s  %s  %d  %d  %d   %d\n",student[i].xuehao,student[i].banj,student[i].name[5],student[i].sex[5],student[i].yu,student[i].shu,student[i].ying,sum[i]);
	}
}
void cha()//��ѯ 
{
	int p,f;
	printf("������1��2��ѯ����1��ѧ�Ż�2��������\n");
	scanf("%d",&p);
	f=0;
	if(p==1)//��ѧ�Ų�ѯ 
	{
		int o;
 	int f=0;
	printf("������ѧ�ţ�\n");
	scanf("%d",&o);
	for(i=0;i<n;i++)
		if(student[i].xuehao==o)
		{
			f=f+1;
		printf("ѧ�ţ�%d �༶��%d ������%s �Ա�%s ���ĳɼ���%d ��ѧ�ɼ���%d Ӣ��ɼ���%d\n",
		student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying); 
		break;
		}
	     if(f==0)
	     {
		 printf("���޴��ˣ�\n");
		 }
	}
	if(p==2)//�����ֲ�ѯ 
	{
	char o[20];
	printf("������������\n");
	scanf("%s",&o);
	for(i=0;i<n;i++)
		if(strcmp(student[i].name,o)==0)
		{
			f=1;
		printf("ѧ�ţ�%d �༶��%d ������%s �Ա�%s ���ĳɼ���%d ��ѧ�ɼ���%d Ӣ��ɼ���%d\n",
		student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
		}
	     if(f==0)
	     {
		 printf("���޴��ˣ�\n");
		 }
	}
}
void dao()//����ѧ����Ϣ���ļ� 
{
	scanf("%d",&n);
	FILE *fp=NULL;
	fp=fopen("student.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp,"%d��%d��%s��%s��%d��%d��%d\n",student[i].xuehao,student[i].banj,student[i].name,student[i].sex,student[i].yu,student[i].shu,student[i].ying);
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
	printf("������������Ҫ�����ѧ����Ϣ��������\n");
	scanf("%d",&n);	
   while(1)
    {
    	zhu();
    	system("cls");
	if(t==7)
	{
		printf("��лʹ�ã�");
	break;
	}
  switch(t)
	    {
		case 1: 
		printf("1���ֶ�¼��\n");
		printf("2�����ļ���ȡ\n");
		printf("������1��2ѡ����Ĳ���(����0�˳��˵�)\n");
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
			printf("������ɣ�");
		    break;
		default:
			printf("�������\n");
			break; 
	    }
    } 
	return 0;
}
