#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#define N 20

//0��������غ���
void login();		            //ͼ��ݵ�¼����
void home_Page();	            //������

//1����ͼ�麯��
void add_book();		        //����ͼ��

//2ͼ�������ʾ����
void shuchu();		            //ͼ��ȫ�������ʾ

//3ͼ���ѯ��غ���
void search_book_meau();		//ͼ���ѯ�˵�
void search_by_num();	        //��Ų�ѯ
void search_by_name();	        //���Ʋ�ѯ
void search_by_author();	    //���߲�ѯ

//4ͼ��ɾ����غ���
void deletbook_meau();		    //ͼ��ɾ���˵�
void deletbook_by_num();	    //�����ɾ��
void deletbook_by_name();       // ������ɾ��

//5ͼ���޸���غ���
void xiugaibook_meau();		    //ͼ���޸Ĳ˵�
void xiugaibook_by_num();	    //��ͼ�����޸�
void xiugaibook_by_name();      //��ͼ�������޸�

//6ͼ��������
void sort_book();			    //ͼ������

//7�û���غ���
void users_meau();              //�û����˵�
void users_Create();            //�û�ע��
void users_Login();             //�û���¼
void users_zhizuorenyuan();     //��Ŀ������Ա
void users_retBook();           //�黹ͼ��
void users_broBook();           //�û�����
void main_Meau_Gaimi();		    //�޸ĵ�¼����ͼ�������

//8�˳�����
void main_quit();		        //�˳�����

//9�����������������ṹ��
void save();                //�����ļ�
void load();                //��ȡ�ļ�
int xianshi(int i);         //��ʾͼ����Ϣ
unsigned long suiji();      //�½�ͼ�����������ͼ��š����޷��ų�����
int M=0;                    //ʵ�ʵ�ͼ������
char c;                     //���������
int isLogin=0;              //�����ж��û��Ƿ��¼��0��ʾδ��¼
char guanli[10]="guanli";              //����Ա���룬����ʹ�õĹ���
char username[15]="jxnu",pwd1[100];	    //username[15]ԭʼ�˺ţ�����pwd1�޸�����ʱ�ıȽ�
char userName1[N],userPassword1[N];     //���ڽ���ͻ����Լ���¼����û��˺�����
void isGuanli();             //����Աʹ�ú���

struct booklibrary{
	unsigned long num;
	char id;		//ͼ����
	char bookName[N];	//����
	char author[N]; 	//����
	char isbn[N];		//ISBN��
	char chuBan[N];	//���浥λ
	char chuBanAge[N]; 	//����ʱ��
	char bookPrice[N];	//ͼ�鵥��
};
struct user{    //����û�������Ľṹ��
	char pwd[20];
}us;
struct booklibrary book[100];

/*----------------��������----------------*/
void main(){    //������
    login();
    //home_Page();
}
void login(){	//��¼����
	int i=0,k=0,j;
	FILE *fp;
	if((fp=fopen("ͼ�������.txt","r"))==NULL){
		strcpy(us.pwd,"123456"); }      //����ļ��򿪴����ʼ����
	fscanf(fp,"%s",&us.pwd);
	char username1[15];                 //������ԭʼ������Ƚϵı���
	//system("color 8f");		   //ϵͳ������color��ʾ��ɫ,8��ɫ��f������ɫ
	printf("\n\n");
	printf("\t ϵͳĬ���û�����jxnu,���룺123456\n");
	printf("\t��������������������������������������������������������������\n");
	printf("\t��**********************************************************��\n");
	printf("\t��***����������������������������������������������������***��\n");
	printf("\t��***��************************************************��***��\n");
	printf("\t��***��***                                         ****��***��\n");
	printf("\t��***��***         ��ӭʹ��ͼ�������Ϣϵͳ        ****��***��\n");
	printf("\t��***��***                                         ****��***��\n");
	printf("\t��***��***                                         ****��***��\n");
	printf("\t��***��***               18���ƿ��İ�              ****��***��\n");
	printf("\t��***��***                                         ****��***��\n");
	printf("\t��***��***                2020��10��               ****��***��\n");
	printf("\t��***��***                                         ****��***��\n");
	printf("\t��***��************************************************��***��\n");
	printf("\t��***����������������������������������������������������***��\n");
	printf("\t��**********************************************************��\n");
	printf("\t��������������������������������������������������������������\n");
	for(i=0;i<3;i++){
	printf("\n\t�������û���:");
	gets(username1);
	printf("\t���������ͼ�������:");
	for(j=0;j<100;j++){
		pwd1[j]=getch();
		if(pwd1[j]=='\r')   //�س�������������
            break;
		printf("*");
    }
	pwd1[j]='\0';
	if((strcmp(username,username1)==0)&&(strcmp(us.pwd,pwd1)==0)){
		printf("\n\t���Ѿ��ɹ���¼");
		k=1;
		for(i=0;i<20;i++){printf(".");Sleep(100);	}
        system("cls");//����
        home_Page();			//��ת��������
        break;
	}
    else{
        if(2-i>0)
            printf("\n\t�û�����������Ч������ϧ���ʣ%d�λ��ᣬ��������:\n",2-i);
        if(2-i==0)
            printf("\n\t�ܱ�Ǹ�û�����������Ȼ���󣬵�¼���������꣬��ӭ�´�����~");
    }
    continue;
    }
	if(k==0)
	printf("\n\t�����������3�Σ������˳�����......\n");
	Sleep(2000);			//������ͣ��������λ���룩��������ͣ2000����
	return;         //�������δ�����ת�˳�����
}
void home_Page() {	//����������
	int cmd;
	time_t T;  //��ȡϵͳʱ��
	struct tm * timenow;
	time ( &T );
	timenow = localtime ( &T );
    while(1){
		printf("\n\n");
		printf("\t ��ǰϵͳʱ����: %s",asctime (timenow) );
		printf("\t������������������������������������������������������������������\n");
		printf("\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
		printf("\t�� �U           �� ӭ ʹ �� ͼ �� �� �� �� Ϣ ϵ ͳ          �U ��\n");
		printf("\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *         1.¼��ͼ����Ϣ   *      2.���ͼ����Ϣ          *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *         3.ͼ����Ϣ��ѯ   *      4.ͼ����Ϣɾ��          *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *         5.ͼ����Ϣ�޸�   *      6.ͼ����Ϣ����          *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *         7.�û����ϵͳ   *      8.�˳���Ϣϵͳ          *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t������������������������������������������������������������������\n");
		printf("\t��ѡ���� 1 - 8 :");
        scanf("%d",&cmd);
		getchar();
		system("cls");
        switch(cmd){
           	case 1:add_book();break;
			case 2:shuchu();break;
			case 3:search_book_meau();break;
			case 4:deletbook_meau();break;
			case 5:xiugaibook_meau();break;
			case 6:sort_book1();break;
			case 7:users_meau();break;
			case 8:main_quit();break;
			default:printf("\n �Ƿ�����!\n");}
			system("pause");//������Ļ�����������
			system("cls");
        }
}

/*----------------ģ��1:����ͼ��----------------*/
void add_book(){//���ͼ��
	load();
	int m,i,j;
	printf(" �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T \n");
    printf(" ********** ¼��ͼ����Ϣ **********    \n");
    printf(" �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T  \n");
	for(i=0;i<4;i++){          //��������4�β��ܳ���ͼ���ڴ淶Χ�ͻ��˳�����
        printf("��������Ҫ��ӵ�ͼ��������");
        scanf("%d",&j);
        if(j<100-M){//Mʵ��ͼ������
            m=j;
            break;
        }
        printf("\t��ϵͳֻ�ܴ�� 100 �����ڵ�ͼ����Ϣ,ʣ��%d ���ռ�,����������\n",100-M);

    }
	if(i==4){
        printf("�����ͼ������������Χ\n");
        exit(0);
    }
	M=M+m;
	for(i=0;i<m;i++){
		printf("�����%d ��ͼ������: ",i+1);
		scanf("%s",book[M+i-m].bookName);
		printf("�����%d ��ͼ������:",i+1);
		scanf("%s",book[M+i-m].author);
		printf("�����%d ��ͼ��ISBN��:",i+1);
		scanf("%s",book[M+i-m].isbn);
		printf("�����%d �����浥λ:",i+1);
		scanf("%s",book[M+i-m].chuBan);
		printf("�����%d ������ʱ��:",i+1);
		scanf("%s",book[M+i-m].chuBanAge);
		printf("�����%d ��ͼ�鵥��:",i+1);
		scanf("%s",book[M+i-m].bookPrice);
		book[M+i-m].num=suiji();
		printf("��ͼ��ı�ű�ϵͳ��Ϊ:%lu\n",book[M+i-m].num);
    }
	save();//�����ļ�
}

/*----------------ģ��2:��ʾ����ͼ��----------------*/
void shuchu()//��ʾ����ͼ����Ϣ
{
	load();
	int i;//ѭ������
	printf(" ����ͼ�������Ϣ\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("����  ͼ���  ͼ������ ͼ������ ͼ��ISBN     ���浥λ       ����ʱ�� ͼ�鵥��\n");
	for(i=0;i<M;i++){
        printf("%2d ",i+1);
        printf("  %-9lu%-10s%-8s%-10s%-20s%-9s%-7s\n",book[i].num,book[i].bookName,book[i].author,
        book[i].isbn,book[i].chuBan,book[i].chuBanAge,book[i].bookPrice);
	}
}

/*----------------ģ��3:ͼ������----------------*/
void search_book_meau()//��ѯ�˵�
{
        int num,i;
		printf("\t������������������������������������������������������������������\n");
		printf("\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
		printf("\t�� �U             �� ӭ �� �� ͼ �� �� Ϣ �� ѯ ģ ��         �U ��\n");
		printf("\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *       1.��ͼ���Ų�ѯ   *      2.��ͼ�����Ʋ�ѯ        *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� *       3.��ͼ�����߲�ѯ   *      4.�������˵�����        *  ��\n");
		printf("\t�� *                          *                              *  ��\n");
		printf("\t�� ***********************************************************  ��\n");
		printf("\t������������������������������������������������������������������\n");
		printf("\t��ѡ���� 1 - 4 :");
		fflush(stdin);
		scanf("%d",&num);
		switch(num){
			case 1:search_by_num();break;
			case 2:search_by_name();break;
			case 3:search_by_author();break;
			case 4:{
			    system("cls");
                home_Page();
                break;
            }
			default:
			    printf("\n\t�Ƿ�����!\n");
			    printf("\t��ѯ�˵�������");
			    for(i=0;i<20;i++){printf(".");Sleep(100);	}
			    //system("pause");
			    system("cls");
                search_book_meau();
		}
}
void search_by_num()//��ͼ���Ų�ѯ
{
	load();
	int i,j=0,k;
	unsigned long n;
	printf("������Ҫ���ҵ�ͼ����:");
	scanf("%lu",&n);
    printf("��ѯ��");
    for(k=0;k<15;k++){printf(".");Sleep(100);}
	for(i=0;i<M;i++)
        if(n==book[i].num){
            xianshi(i);
            j++;
        }
	if(j==0)
        printf("��ѯ�ĸ�ͼ���Ų�����");
	printf("\n�����������\n");
	c=getch();
	system("cls");
	search_book_meau();
}
void search_by_name()//��ͼ�����Ʋ�ѯ
{
	int i,j=0,k;
	char c1[10];//*
	load();
	printf("������Ҫ���ҵ�ͼ������:");
	getchar();
	gets(c1);
    printf("��ѯ��");
    for(k=0;k<15;k++){printf(".");Sleep(100);}
	for(i=0;i<M;i++)
        if(strcmp(c1,book[i].bookName)==0){
            xianshi(i);
            j++;
    }
	if(j==0)
        printf(" û�в��ҵ���ͼ�����Ƶ���Ϣ!!!");
	printf("\n�����������\n");    //���������þ͵���system(pause)
	c=getch();                     //���������þ͵���system(pause),getch����ĳ���ַ�ʱ�������Զ���ȡ�����谴�س�
	system("cls");
	search_book_meau();
}
void search_by_author()//��ͼ�����߲�ѯ
{
	int i,j=0,k;
	char c1[10];
	load();
	printf("������Ҫ���ҵ�ͼ������:");
	getchar();
	gets(c1);
    printf("��ѯ��");
    for(k=0;k<15;k++){printf(".");Sleep(100);}
	for(i=0;i<M;i++)
        if(strcmp(c1,book[i].author)==0){
            xianshi(i);
            j++;
        }
	if(j==0)
        printf(" û�в��ҵ���ͼ�����ߵ���Ϣ!!!");
	printf("\n�����������\n");
	c=getch();
	system("cls");
	search_book_meau();
}

/*-----------------ģ��4:ͼ��ɾ��----------------*/
void deletbook_meau(){		//ɾ�����˵�
	int num,i;
    printf("\t������������������������������������������������������������������\n");
    printf("\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
    printf("\t�� �U             �� ӭ �� �� ͼ �� �� Ϣ ɾ �� ģ ��         �U ��\n");
    printf("\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       1.��ͼ����ɾ��   *      2.��ͼ������ɾ��        *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                     3.�������˵�����                    *  ��\n");
    printf("\t������������������������������������������������������������������\n");
    printf("\t���������ѡ��1-3:");
    fflush(stdin);
    scanf("%d",&num);
    switch(num){

        case 1:deletbook_by_num();break;
        case 2:deletbook_by_name();break;
        case 3:{system("cls");home_Page();break;}
        default:
            printf("\n\t�Ƿ�����!\n");
            printf("\tɾ���˵�������");
            for(i=0;i<20;i++){printf(".");Sleep(100);	}
            //system("pause");
            system("cls");
            deletbook_meau();
}
}
void deletbook_by_num(){	//���ݱ��ɾ��
	load();
	isGuanli();
	int i,j=0,k;
	char c1;//�Ƿ�ɾ������
	unsigned long n;
	printf("������Ҫɾ����ͼ����:");
	scanf("%lu",&n);
	for(i=0;i<M;i++)
        if(n==book[i].num){
        xianshi(i);
        k=i;//��¼�±�
        j++;	break;	}
	if(j==0){
        printf("��ͼ���Ų�����");
        k=-1;
        printf("\n�����������\n");
        c=getch();
        system("cls");
        deletbook_meau();
	}
	printf("ȷ��ɾ��?�� ���� y �� Y�����ǰ������\n");
	getchar();
	scanf("%c",&c1);
	if(c1=='y'||c1=='Y'){
        for(i=k;i<M-1;i++)
        book[i]=book[i+1];
        M=M-1;
        save();
        printf("ɾ���ɹ�\n");
    }
	printf("�����������\n");
	c=getch();
	system("cls");
	deletbook_meau();
}
void deletbook_by_name(){	//����ͼ������ɾ��
	load();
	isGuanli();
	int i,j=0,k;
	char c1;//�Ƿ�ɾ������
	char bookName1[N];	//����    //*
	printf("������Ҫɾ����ͼ������:");
	scanf("%s",bookName1);
	for(i=0;i<M;i++)
        if(strcmp(bookName1,book[i].bookName)==0){
            xianshi(i);
            k=i;
            j++;
            break;
        }
	if(j==0){
        printf("��ͼ�����Ʋ�����\n");
        k=-1;
        printf("�����������\n");
        c=getch();
        system("cls");
        deletbook_meau();
	}
	printf("ȷ��ɾ��?�� ���� y �� Y�����ǰ������\n");
	getchar();
	scanf("%c",&c1);
	if(c1=='y'||c1=='Y'){
        for(i=k;i<M-1;i++)
            book[i]=book[i+1];
        M=M-1;
        save();
        printf("ɾ���ɹ�\n");
    }
	printf("�����������\n");
	c=getch();
	system("cls");
	deletbook_meau();
}


/*-----------------ģ��5:ͼ����Ϣ�޸�----------------*/
void xiugaibook_meau(){	//�޸Ĳ˵�
	int num,i;
    printf("\t������������������������������������������������������������������\n");
    printf("\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
    printf("\t�� �U             �� ӭ �� �� ͼ �� �� Ϣ �� �� ģ ��        �U ��\n");
    printf("\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       1.��ͼ�����޸�   *      2.��ͼ�������޸�        *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                     3.�������˵�����                    *  ��\n");
    printf("\t������������������������������������������������������������������\n");
    printf("\t���������ѡ��1-3:");
    fflush(stdin);
    scanf("%d",&num);
    switch(num){
        case 1:xiugaibook_by_num();break;
        case 2:xiugaibook_by_name();break;
        case 3:{
            system("cls");
            home_Page();
            break;}
        default:
            printf("\n\t�Ƿ�����!\n");
            printf("\t�޸Ĳ˵�������");
            for(i=0;i<20;i++){printf(".");Sleep(100);	}
            //system("pause");
            system("cls");
            xiugaibook_meau();
    }
}
void xiugaibook_by_num(){	//���ݱ���޸�
	load();
	isGuanli();
	int i,j=0,k;//k���ҵ���ѱ�Ÿ�K
	char c2; //�Ƿ��޸�
	unsigned long n;
	printf("������Ҫ�޸ĵ�ͼ����:");
	scanf("%lu",&n);
	for(i=0;i<M;i++)
	if(n==book[i].num){
        xianshi(i);
        k=i;
        j++;
        break;
    }
	if(j==0){
        printf("��ͼ���Ų�����\n");
        k=-1;
        printf("\n�����������\n");
        c=getch();
        system("cls");
        xiugaibook_meau();
    }
	i=k;
	printf("�����µ�ͼ������: ");
	scanf("%s",book[i].bookName);
	printf("�����µ�ͼ������:");
	scanf("%s",book[i].author);
	printf("�����µ�ͼ��ISBN��:");
	scanf("%s",book[i].isbn);
	printf("�����µĳ��浥λ:");
	scanf("%s",book[i].chuBan);
	printf("�����µĳ���ʱ��:");
	scanf("%s",book[i].chuBanAge);
	printf("�����µ�ͼ�鵥��:");
	scanf("%s",book[i].bookPrice);
	printf("ȷ���޸�?�� ���� y �� Y�����ǰ������\n");
	getchar();
	scanf("%c",&c2);
	if(c2=='y'||c2=='Y'){
        save();
        printf("�޸ĳɹ���\n");
        printf("\n�����������\n");
        c=getch();system("cls");	xiugaibook_meau();
	}
	else{
        printf("\n�����������\n");
        c=getch();system("cls");	xiugaibook_meau();
	}
}
void xiugaibook_by_name(){	//����ͼ�������޸�
	isGuanli();
	load();
	int i,j=0,k;//k���ҵ���ѱ�Ÿ�K
	char c2;//�Ƿ��޸�
	char bookName1[20];	//����
	printf("������Ҫ�޸ĵ�ͼ������:");
	scanf("%s",bookName1);
	for(i=0;i<M;i++)
	if(strcmp(bookName1,book[i].bookName)==0){
        xianshi(i);
        k=i;
        j++;
        break;
    }
	if(j==0){
        printf("��ͼ�����Ʋ�����\n");
        k=-1;
        printf("\n�����������\n");
        c=getch();
        system("cls");
        xiugaibook_meau();
    }
	i=k;
	printf("�����µ�ͼ������: ");
	scanf("%s",book[i].bookName);
	printf("�����µ�ͼ������:");
	scanf("%s",book[i].author);
	printf("�����µ�ͼ��ISBN��:");
	scanf("%s",book[i].isbn);
	printf("�����µĳ��浥λ:");
	scanf("%s",book[i].chuBan);
	printf("�����µĳ���ʱ��:");
	scanf("%s",book[i].chuBanAge);
	printf("�����µ�ͼ�鵥��:");
	scanf("%s",book[i].bookPrice);
	printf("ȷ���޸�?�� ���� y �� Y�����ǰ������\n");
	getchar();
	scanf("%c",&c2);
	if(c2=='y'||c2=='Y'){
		save();
		printf("\n�޸ĳɹ���");
		printf("\n�����������\n");
		c=getch();
		system("cls");
		xiugaibook_meau();
	}
	else{
		printf("\n�����������\n");
		c=getch();
		system("cls");
		xiugaibook_meau();
		}
}


/*----------------ģ��6:ͼ����������----------------*/
void sort_book(){//ͼ����Ϣ����
	load();
	int i,j,t=0;//t�����Ƿ�����ɹ�
	struct booklibrary temp;
	for(i=0;i<M-1;i++){
		for(j=0;j<M-i-1;j++){
			if(book[j].num>book[j+1].num){//������MAX����Ų
				temp=book[j];
				book[j]=book[j+1];
				book[j+1]=temp;	t=1;
            }
        }
    }
	printf("��ӭ����ͼ������ģ�飬��ϵͳ����ͼ������С��������\n");
	printf("---------------------------------------------------------\n");
	printf("��������");
	for(i=0;i<21;i++){
		printf(".");
		Sleep(100);		}
	if(t==1){
		printf("\n������ɣ��밴��������ز鿴��");
		save(); //����ɹ��󱣴��ļ�
	}
	else
        printf("\n����ʧ�ܣ���������Ϊ�Ѿ�������ˣ��밴��������أ�");
    c=getch();
    system("cls");
    home_Page();
}
void sort_book1(){//ͼ����Ϣ����
	load();
	int i=M,j,t=0;//t�����Ƿ�����ɹ�
	struct booklibrary temp;
	bool flag=1;
	while(flag&&i>1)
    {
        flag=0;
        for(j=0;j<i-1;j++)
            if(book[j].num>book[j+1].num){
				temp=book[j];
				book[j]=book[j+1];
				book[j+1]=temp;
                t=1;
                flag=1;
            }
            i--;
    }
	printf("��ӭ����ͼ������ģ�飬��ϵͳ����ͼ������С��������\n");
	printf("---------------------------------------------------------\n");
	printf("��������");
	for(i=0;i<21;i++){
		printf(".");
		Sleep(100);		}
	if(t==1){
		printf("\n������ɣ��밴��������ز鿴��");
		save(); //����ɹ��󱣴��ļ�
	}
	else
        printf("\n����ʧ�ܣ���������Ϊ�Ѿ�������ˣ��밴��������أ�");
    c=getch();
    system("cls");
    home_Page();
}

/*----------------ģ��7:�û����----------------*/
void users_meau()//�û���ز˵�
{
	int num,i;
    printf("\t������������������������������������������������������������������\n");
    printf("\t�� �X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[ ��\n");
    printf("\t�� �U             �� ӭ �� �� ͼ �� �� �� �� ��  ϵ  ͳ      �U ��\n");
    printf("\t�� �^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       1.ͼ����û�ע��   *      2.ͼ����û���¼        *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       3.ͼ����û�ע��   *      4.��Ŀ  ���� ��Ա       *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       5.��  ��  ��  ��   *      6.��  ��  ��  ��        *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� *       7.�޸�ͼ�������   *      8.�� �� �� �� ��        *  ��\n");
    printf("\t�� *                          *                              *  ��\n");
    printf("\t�� ***********************************************************  ��\n");
    printf("\t������������������������������������������������������������������\n");
    printf("\n\t��ѡ���� 1 - 8 :");
    fflush(stdin);
    scanf("%d",&num);
    switch(num){
        case 1:users_Create();break;
        case 2:users_Login();break;
        case 3:users_delite();break;
        case 4:users_zhizuorenyuan();break;
        case 5:users_broBook();break;
        case 6:users_retBook();break;
        case 7:main_Meau_Gaimi();break;
        case 8:system("cls");home_Page();break;
    default:
        printf("\n\t�Ƿ�����!\n");
        printf("\t�û���ز˵�������");
        for(i=0;i<20;i++){printf(".");Sleep(100);	}
        //system("pause");
        system("cls");
        users_meau();
		}
}
void users_Create()//�û�ע��
{
    int i;
	FILE *zhanghaoFp;//�ļ�ָ��
	char  zhanghao[N];
	char password[N],password1[N];
	if ((zhanghaoFp=fopen("�˺�����.txt","a"))==NULL)
	{
      printf("file open error!\n");
      exit(0);
    }
	while(1)
	{
        printf("\n\n������ע����˺�(��λ��)������(��λ��)");
	    printf("\n�������˺�:");
	    scanf("%s",zhanghao);
	    printf("����������:");
	    scanf("%s",password);
	    system("pause");
	    //system("cls");
        printf("�ٴ���������:");
        scanf("%s",password1);
	    if(strcmp(password,password1)==0)
	    {
	        printf("������");
            //system("cls");

	        fprintf(zhanghaoFp,"%s %s\n",zhanghao,password);
	        fclose(zhanghaoFp);
            for(i=0;i<20;i++){printf(".");Sleep(100);}//�ȴ�������ʾ�ɹ�***
	   		printf("�����ɹ�");
	        printf("\n�����û�ϵͳ,");
            system("pause");
            system("cls");
		    users_meau();}
        else
        {
            system("pause");
            //system("cls");
            printf("\n\n�����������벻һ��,����������");
            break;}
   }
}
void users_delite(){
    FILE *fp;
    FILE *fp1;
    int i=0,j;
    char zhuxiao[20];
    char zhanghao[20],mima[20];
    isGuanli();
    printf("��ע���˺�����:\n");
    fp=fopen("�˺�����.txt","r");
    fp1=fopen("temp.txt","w");
    printf("�˺�       ����\n");
    while(fscanf(fp,"%s %s",zhanghao,mima)!=EOF){
        printf("%s %s\n",zhanghao,mima);
    }
    printf("��������Ҫע�����˺�\n");
    fflush(stdin);
    gets(zhuxiao);
    //printf("%s",zhuxiao);
    rewind(fp);//ָ��ص��ļ�ͷ
    while(fscanf(fp,"%s %s",zhanghao,mima)!=EOF){
        if(strcmp(zhuxiao,zhanghao)==0)
            continue;
        fprintf(fp1,"%s %s\n",zhanghao,mima);
    }
    printf("�˺�%sע����",zhuxiao);
    for(i=0;i<20;i++){printf(".");Sleep(100);}
    printf("ע���ɹ�\n");
    fclose(fp);
    fclose(fp1);
    remove("�˺�����.txt");
    rename("temp.txt","�˺�����.txt");
    printf("\n�����û��˵�");
    system("pause");
    system("cls");
    users_meau();

}
void users_Login()//�û���¼
{
    int i=0,j=0;
	int aa=0;//��¼״̬
	char userNameCheck1[N],userPasswordCheck1[N];
	int cc;
	FILE *fp;
	if((fp=fopen("�˺�����.txt","r"))==NULL){
		printf("File open error!\n");
		exit(0);
	}
    printf("\n�������¼�˺ţ�");
	scanf("%s",userName1);
    printf("�������¼���룺");
    for(j=0;j<N+2;j++){
		userPassword1[j]=getch();
		if(userPassword1[j]=='\r')   //�س�������������
            break;
		printf("*");
    }
    userPassword1[j]='\0';
	while(1){
        while(!feof(fp)){//feof��ĩΪ0
            fscanf(fp,"%s%s",userNameCheck1,userPasswordCheck1);
            if((strcmp(userName1,userNameCheck1)==0)&&(strcmp(userPassword1,userPasswordCheck1)==0)){
                    printf("\n��¼��");
                	for(i=0;i<21;i++){
                        printf(".");
                        Sleep(100);		}
                printf("��¼�ɹ�!\n");
                isLogin=1;
                fclose(fp);
                printf("�������˵�,");
                system("pause");
                system("cls");
                home_Page();
                aa=1;
            }
        }
        if(aa==0){
            //system("cls");
            printf("\n����������������밴1��������(��ȥ�س�)��������һ��");
            printf("\n���������ѡ�� ��");
            scanf("%d",&cc);
            if(cc==1)
                users_Login();
            if(cc!=1){
                system("cls");
                users_meau();
            }
        }
	}
}
void users_zhizuorenyuan(){//��Ŀ������Ա
    load();
    FILE *users_fp;
    int i;
    char zhi_school[20]={'\0'},zhi_class[20]={'\0'},zhi_name[20]={'\0'},zhi_id[20]={'\0'};
    if((users_fp=fopen("������Ա��Ϣ.txt","r")==NULL)){
        system("pause");
        system ("cls");
        users_meau();
    }
    users_fp=fopen("������Ա��Ϣ.txt","r");
    system("cls");
    printf("\n\n������Ա����:\n");
    printf("   ѧ   У  \t�༶\t ����\t\tѧ��\n");
    while(fscanf(users_fp,"%s%s%s%s",zhi_school,zhi_class,zhi_name,zhi_id)!=EOF){
                printf("%-13s%-11s%-10s%-13s\n",zhi_school,zhi_class,zhi_name,zhi_id);
    }
    fclose(users_fp);
    system("pause");
    printf("����������һ��");
    for(i=0;i<20;i++){printf(".");Sleep(100);}
    system("cls");
    users_meau();
}
void users_broBook(){//�û����麯��
    FILE *fpb;
    int isBro=0,i,j,broTian;//broTian��ʾ���ǽ�������
    char bro_name[20];
    system("cls");
    shuchu();
    if((fpb=fopen("������Ϣ.txt","a")==NULL))
    {
        printf("�ļ���ʧ�ܣ�����������һ����");
        Sleep(2000);
        system("cls");
        users_meau();
    }
    fpb=fopen("������Ϣ.txt","a");
    printf("��������������:\n");
    scanf("%s",&bro_name);
    load();
    for(i=0;i<M;i++)
    {
        if(strcmp(bro_name,book[i].bookName)==0){
            isBro=1;break;
        }
    }
    if(isBro==0){
        printf("û�и��飬����������һ����");
        for(i=0;i<20;i++){printf(".");Sleep(100);	}
        system("cls");
        users_meau();
    }
    if(isBro==1){
        printf("�������������\n");
        scanf("%d",&broTian);
        fprintf(fpb,"%s\t%s\t%d��\n",userName1,bro_name,broTian);
        fflush(fpb);
        for(j=i;j<M-1;j++)
            book[j]=book[j+1];
        M=M-1;
        save();
        printf("����ɹ�\n\nʣ��ɽ�ͼ������\n");
        shuchu();
        system("pause");
        printf("����������һ��");
        for(i=0;i<20;i++){printf(".");Sleep(100);}
        system("cls");
        users_meau();
    }
    fclose(fpb);
}
void users_retBook(){
    int i=0;
    char c[30];
    load();
    printf("��������Ҫ�黹��ͼ��:\n");
    fflush(stdin);
    gets(c);
    printf("%s�黹��",c);
    for(i=0;i<20;i++){printf(".");Sleep(100);}
    printf("�黹�ɹ�\n");
    printf("������һ��");
    system("pause");
    system("cls");
    users_meau();
}



/*---------------ģ��8:�˳���������----------------*/
void main_quit(){	//�˳�����
	system("cls");
	printf("\n\n\t����������������������������������������������������������������\n");
	printf("\t�� ***********************************************************��\n");
	printf("\t�� *                       ллʹ�ñ�����                    *��\n");
	printf("\t�� ***********************************************************��\n");
	printf("\t����������������������������������������������������������������\n\n");
	isLogin=0;
	exit(0);
}

/*-------------��������----------------*/
void save(){	//�ļ�����
	FILE *fp;
	int i;
	if((fp=fopen("ͼ����Ϣ.txt","w"))==NULL){
        printf("�ļ��򿪴���\n");
        exit(0);
    }
	for(i=0;i<M;i++)
        fwrite(&book[i],sizeof(struct booklibrary),1,fp);
	fclose(fp);	}
void load(){//������Ϣ���뵽�ڴ�
    if(isLogin==0)
    {
        int x;
        printf("\n����û��¼����ѡ��1:ע���˺� 2:��¼�˺� ��������������˵�");
        //Sleep(2000);
        //exit(0);
        printf("\n������ѡ��: ");
        scanf("%d",&x);
        if(x==1){
            system("pause");
            system("cls");
            users_Create();
        }
        if(x==2){
            system("pause");
            system("cls");
            users_Login();
        }
        //system("cls");
        else{
            system("pause");
            system("cls");
            home_Page();
        }
    }
    if(isLogin==1)
    {
        FILE *fp;
        int i;
        if((fp=fopen("ͼ����Ϣ.txt","r"))==NULL){
            printf("�ļ��򿪴���!\n");
            exit(0);	}
        for(i=0;!feof(fp);i++)
        {
            fread(&book[i],sizeof(struct booklibrary),1,fp);
        }
        fclose(fp);
        M=i-1;
    }
}
unsigned long suiji(){//���������ͼ���
	unsigned long h;
	srand(time(NULL));
	h=rand()%1000+2020000;
	return h;	}
void main_Meau_Gaimi(){	//�޸��������
	int j;
	FILE *fp;
	isGuanli();
	if((fp=fopen("ͼ�������.txt","w"))==NULL){
		printf("�ļ��򿪴���");
		exit(0);
    }
	printf("\n����������ԭʼ����:\n");
	fflush(stdin); 		//�������
	for(j=0;j<100;j++){
		us.pwd[j]=getch();
		if(us.pwd[j]=='\r')
		break;
		printf("*");
    }
    us.pwd[j]='\0';
	if((strcmp(us.pwd,pwd1)==0)){
		printf("\n��������Ҫ�޸ĵ�����\n");
		for(j=0;j<100;j++){
            us.pwd[j]=getch();
            if(us.pwd[j]=='\r')
                break;
            printf("*");
        }
		us.pwd[j]='\0';
		fflush(stdin); 		//�������
		printf("\n���ٴ�ȷ���������\n");
		for(j=0;j<100;j++){
            pwd1[j]=getch();
            if(pwd1[j]=='\r')
                break;
            printf("*");
        }
		pwd1[j]='\0';
		if((strcmp(us.pwd,pwd1)==0)){
            fprintf(fp,"%s",&us.pwd);
            fclose(fp);
			printf("\n�����޸ĳɹ��������µ�¼��");
			fprintf(fp,"%s",&us.pwd);
			Sleep(2000);
			system("cls");
			login();
        }
		else {
			printf("\n�������벻���ϣ����η��񵽴˽�����");
			printf("\n�����������\n");
			c=getch();
			system("cls");
			home_Page();
		}
    }
	else{
		printf("\n�����������\n\n");
		printf("\n\n�����������\n");
		c=getch();
		system("cls");
		home_Page();
		}
}
int xianshi(int i){
	int j=0;
	printf("\n����Ҫ�������ͼ�������Ϣ\n");
	printf("--------------------------------------------------------------------------------\n");
	printf("����  ͼ���  ͼ������ ͼ������ ͼ��ISBN     ���浥λ       ����ʱ�� ͼ�鵥��\n");
	printf("%2d ",j+1);
	printf("  %-9lu%-10s%-8s%-10s%-20s%-9s%-7s\n",book[i].num,book[i].bookName,book[i].author,
        book[i].isbn,book[i].chuBan,book[i].chuBanAge,book[i].bookPrice);
	return 0;
}
void isGuanli(){
    int i=0;
    char guanli1[20];
    printf("�������·Ա����:\n");
    fflush(stdin);
    gets(guanli1);
    if(strcmp(guanli1,guanli)==0)
    {
        printf("����Ա������֤��");
        for(i=0;i<20;i++){printf(".");Sleep(100);}
        printf("\n����Ա������ȷ����ӭʹ��\n");
    }
    if(strcmp(guanli1,guanli)!=0)
    {
        printf("����Ա�������,���˵�������");
        for(i=0;i<20;i++){printf(".");Sleep(100);}
        system("cls");
        home_Page();
    }
}
