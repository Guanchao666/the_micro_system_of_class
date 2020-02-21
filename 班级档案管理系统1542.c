#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 999 //�����������ݵ������ 

struct student { //����һ������ѧ����Ϣ�Ľṹ������
	char class_num[5];//���
	char no[12];//ѧ��
	char name[8];//����
	char sex[5];//�Ա�
	char age[5];//����

};
struct student stu[N];//����ȫ�ֱ���
typedef enum __bool { false = 0, true = 1 } bool;//����һ�������ͽṹ�壬�����жϲ���ֵ

void menu() { //�˵�����
	printf("   FFFFFFF       IIIIIIII     TTTTTTTTTT   \n");
	printf("   FF               II            TT       \n");
	printf("   FFFFFF           II            TT       \n");
	printf("   FF               II            TT       \n");
	printf("   FF            IIIIIIII         TT       \n");
	printf("   FF      * * * * * * * * * * * * * * * * \n");
	printf("          *                                *\n");
	printf("          *    a.���ļ��ж���ѧ��������Ϣ  *\n");
	printf("          *    b.�����ѧ���Ļ�����Ϣ      *\n");
	printf("          *    c.ѧ��������Ϣ�������ļ�    *\n");
	printf("          *    d.ѧ��������Ϣɾ��          *\n");
	printf("          *    e.ѧ��������Ϣ�޸�          *\n");
	printf("          *    f.ѧ��������Ϣ��ѯ          *\n");
	printf("          *    g.�޸ĵ�¼����              *\n");
	printf("          *    p.�����ĵ�                  *\n");
	printf("          *    h.�˳�ϵͳ                  *\n");
	printf("          *                                *\n");
	printf("          * * * * * * * * * * * * * * * * \n");
	printf("\n");
	printf("������ѡ��:(a ~ g)\n");
}


void input() { //ѧ��������Ϣ��¼��
	int i;
	int n;
	printf("���������ѧ������");
	scanf("%d",&n);
	for(i=N-n; i<N; i++) {
		printf("������ѧ���Ļ�����Ϣ:\n");
		printf("���/Class:\n");
		scanf("%s",stu[i].class_num);
		printf("����/Name:\n");
		scanf("%s",stu[i].name);
		printf("�Ա�/sex:\n");
		scanf("%s",stu[i].sex);
		printf("����/age:\n");
		scanf("%s",stu[i].age);
		printf("ѧ��/Number:\n");
		scanf("%s",stu[i].no);

	}
	printf("\n");
	printf("������Ϣ�Ƿ�������ȷ�������˰�C����Ŷ��\n");
	printf("\n");
	for(i=N-n; i<N; i++) {
		printf("%s   %s   %s   %s   %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
	}
}


void save() { //ѧ����Ϣ����
	FILE * fp;
	int i;
	fp= fopen("student.txt","w");
	if (fp == NULL) {
		printf("�ļ�������!\n");
		exit(0);
	}
	for(i=0; i<N; i++) { //�ڴ˴��ж�������ռ���ȵ���ѧ����Ϣ�����ļ��еĸ�ʽ
		if(strlen(stu[i].name)==4) {
			fprintf(fp,"%s    %s   %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}
		if(strlen(stu[i].name)==6) {
			fprintf(fp,"%s  %s   %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}
	}
	fclose(fp);
	printf("����ɹ���\n");
}


void Delete() { //ɾ��������
	FILE*fp;
	fp=fopen("student.txt","w");
	char number[10];
	int f;
	bool flag=false;
	printf("ɾ��ѧ����Ϣ:\n");
	printf("������ѧ��:\n");
	scanf("%s",number);
	int i;
	for (i =0; i<N; i++) {
		if (!strcmp(number,stu[i].no)) {
			for(f=i; f<N; f++) { //����strcpy�����������е���һλԪ�ؽ���һλ���ǴӶ�ʵ��ɾ������
				strcpy(stu[f].name,stu[f+1].name);
				strcpy(stu[f].class_num,stu[f+1].class_num);
				strcpy(stu[f].no,stu[f+1].no);
				strcpy(stu[f].sex,stu[f+1].sex);
				strcpy(stu[f].age,stu[f+1].age);
			}
			flag=true;
		}
	}
	if(!flag) {
		printf("��ѧ��������!:\n");
		Delete();
	}
	for(i=0; i<N; i++) {
		fprintf(fp,"%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);

	}
	printf("ɾ���ɹ���\n");
	fclose(fp);
}

void search() { //���Һ���

	int f;
	FILE*fp;
	fp=fopen("student.txt","rb");
	for(f=0; f<N; f++) {
		fscanf(fp,"%s%s%s%s%s",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
	}
	bool flag=false;//����һ��bool���ͽ����ж�,bool�����ڿ�ͷ�����ýṹ�嶨��
	int m;
	int i;
	printf("    1 ��ѧ�Ų�ѯ\n");
	printf("    2 ��������ѯ\n");
	printf("    3 ����Ų�ѯ\n");
	printf("    4 �������ѯ\n");
	printf("    5 ���Ա��ѯ\n");
	printf("������ѡ�");
	printf("\n");
	scanf("%d",&m);
	switch(m) {
		case 1: {
			char num[10];//����һ��ѧ�ŵ�����
			printf("������ѧ��:\n");
			scanf("%s",num);
			for ( i=0; i<N; i++) {
				if (!strcmp(num,stu[i].no)) {
					if(strlen(stu[i].name)==4) {
						printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					if(strlen(stu[i].name)==6) {
						printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					flag=true;
				}

			}
			if(!flag) {
				printf("��ѧ��������.\n");
			}
			break;
		}
		case 2:
			printf("����������:\n");
			char na[10];//����һ������������
			scanf("%s",na);
			for ( i =0; i<N; i++) {
				if (!strcmp(na,stu[i].name)) {
					if(strlen(stu[i].name)==4) {
						printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					if(strlen(stu[i].name)==6) {
						printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					flag = true;
				}
			}
			if (!flag) {
				printf("��ѧ��������.\n");
			}
			break;
		case 5: {
			char ch[5];//����һ���Ա������
			printf("�������Ա�:\n");
			scanf("%s",ch);
			for(i=0; i<N; i++) {
				if (!strcmp(ch,stu[i].sex)) {
					if(strlen(stu[i].name)==4) {
						printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					if(strlen(stu[i].name)==6) {
						printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					flag = true;
				}
			}
			if (!flag) {
				printf("��ѧ��������.\n");
			}
			break;
		}
		case 4: {
			char num_age[5];//����һ�����������
			printf("����������:\n");
			scanf("%s",&num_age);
			for ( i =0; i<N; i++) {
				if (!strcmp(num_age,stu[i].age)) {
					if(strlen(stu[i].name)==4) {
						printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					if(strlen(stu[i].name)==6) {
						printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					flag = true;
				}
			}
			if (!flag) {
				printf("��ѧ��������.\n");
			}
			break;
		}
		default:
			break;

		case 3: {
			char class_number[5];//����һ����ŵ�����
			printf("��������:\n");
			scanf("%s",class_number);
			for(i=0; i<N; i++) {
				if (!strcmp(class_number,stu[i].class_num)) {
					if(strlen(stu[i].name)==4) {
						printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					if(strlen(stu[i].name)==6) {
						printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
					}
					flag = true;
				}
			}
			if (!flag) {
				printf("��ѧ��������.\n");
			}
			break;
		}
	}
}

void modi() { //��Ϣ�޸ĺ���
	FILE*fp;//�����޸������ļ���ָ��
	FILE*fp1;//����ѧ����Ϣ�ļ���ָ��
	char a[7];
	char b[7];
	char c[10];
	char ch;
	int i=0;
	int f;
	bool temp=false;
	fp1=fopen("student.txt","r");
	for(f=0; f<N; f++) { //���ļ��н���Ϣ�����ṹ����
		fscanf(fp1,"%s%s%s%s%s",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
	}
	fclose(fp1);
	printf("����������():\n");
	scanf("%s",b);
	if((fp=fopen("passwd.dat","r"))==NULL) {
		printf("���ļ�ʧ�ܣ�");
		exit(0);
	}
	ch=fgetc(fp);
	while(ch!=EOF&&i<6) {
		a[i] = ch;
		ch=fgetc(fp);
		i++;
	}
	a[6] = '\0';
	fclose(fp);
	while(1) {
		if (!strcmp(a,b)) {
			break;
		} else {
			printf("��������������������룺\n");
			scanf("%s",b);
		}
	}
	printf("��������Ҫ�޸���Ϣѧ����ѧ�ţ�\n");
	scanf("%s",c);
	for(f=0; f<N; f++) {
		if (!strcmp(c,stu[f].no)) {
			printf("%s   %s  %s  %s  %s\n",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
			printf("\n");
			printf("�������µ���Ϣ��\n");
			printf("���:\n");
			scanf("%s",stu[f].class_num);
			printf("����:\n");
			scanf("%s",stu[f].name);
			printf("�Ա�:\n");
			scanf("%s",stu[f].sex);
			printf("����:\n");
			scanf("%s",stu[f].age);
			printf("ѧ��:\n");
			scanf("%s",stu[f].no);
			temp=true;
			break;
		}
	}
	if(!temp) {
		printf("��ѧ�������ڣ�\n");
	}

}

void read() { //���ļ��ж�ȡѧ����Ϣ
	int i;
	FILE*fp;
	fp=fopen("student.txt","r");
	printf("��� ���� �Ա� ���� ѧ��\n");
	for(i=0; i<N; i++) {
		fscanf(fp,"%s%s%s%s%s",stu[i].class_num,stu[i].name,stu[i].sex,stu[i].age,stu[i].no);
		if(strlen(stu[i].name)==4) {
			printf("%s    %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}
		if(strlen(stu[i].name)==6) {
			printf("%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}

	}
	printf("\n");
	printf("��ȡ�ɹ���\n");
	fclose(fp);
}

int accesswd() { //������֤����
	FILE*fp;
	char c[7],b[7],a[6],d[6];
	int i=0,passwd;
	char ch;
	if ((fp=fopen("passwd.dat","r"))==NULL) {
		printf("����δ�趨��������!  ���趨��������(������6λ)\n");
		scanf("%s",a);
		printf("�������������\n");
		scanf("%s",d);
		if (strcmp(a,d)) {
			printf("�������벻�ԣ����������룡\n");
			accesswd();//�ݹ飬ʹ�ó�������ظ���֤����
		} else {
			fp = fopen("passwd.dat","w");
			fprintf(fp,"%s",a);
			fclose(fp);
			return 0;
		}
	} else {
		printf("�������½���룺\n");
		scanf("%s",b);
		ch=fgetc(fp);
		while (ch!=EOF&&i<6) {
			c[i] = ch;
			ch=fgetc(fp);
			i++;

		}
		c[6] = '\0';
		if (!strcmp(b,c)) { //�ж��ַ���b��c�Ƿ���ȣ��Ƿ���ֵ0���񷵻�ֵ1
			return 0;
		} else {
			accesswd();
		}
		fclose(fp);
	}
}

void Turnpasswd() {
	FILE*fp;
	char a[6],b[6],c[6],d[6];
	int i=0,passwd;
	char ch;
	printf("������ԭʼ����\n");
	scanf("%s",b);
	fp=fopen("passwd.dat","r");
	ch=fgetc(fp);
	while (ch!=EOF&&i<6) {
		c[i] = ch;
		ch=fgetc(fp);
		i++;
	}
	c[6] = '\0';
	if (!strcmp(b,c)) { //�ж��ַ���b��c�Ƿ���ȣ���������������޸ģ�����ݹ�
		printf("�����������룡\n");
		scanf("%s",a);
	} else {
		printf("ԭʼ���벻�ԣ����������룡\n");
		Turnpasswd();//�ݹ飬ʹ���û��������´򿪳����޸�����
	}
	fclose(fp);
	fp = fopen("passwd.dat","w");
	fprintf(fp,"%s",a);
	fclose(fp);
}

void help() {
	printf("*******************************************************************************************\n");
	printf("*                       FFFFFFF       IIIIIIII     TTTTTTTTTT                             *\n");
	printf("*                       FF               II            TT                                 *\n");
	printf("*                       FFFFFF           II            TT                                 *\n");
	printf("*                       FF               II            TT                                 *\n");
	printf("*                       FF               II            TT                                 *\n");
	printf("*                       FF            IIIIIIII         TT                                 *\n");
	printf("*** Warming!!!                                                                            *\n");
	printf("1.����ʹ�ó���ʱ��������������趨���룬���ڱ�Ŀ¼����passwd.dat�ļ����ڴ�������������ݡ�*\n");
	printf("2.��Ŀ¼�µ�student.txt�ļ�Ϊ����ѧ����Ϣ���ļ�������Ϊ���뵼�����ļ�ʹ�á�               *\n");
	printf("3.��Ŀ¼�µ�passwd.dat��student.txtΪ�����������ļ�������ɾ�����������ݵĶ�ʧ��         *\n");
	printf("4.¼��ѧ����Ϣ��ȷ��������밴C���棬�������ݽ��ᶪʧ����                               *\n");
	printf("*******************************************************************************************\n");
}

int main(int argc, char* argv[]) {

	char a[7];
	char n;
	int code;

	while(1) {

		code=accesswd();//���ú������ж��Ƿ��趨�����
		if(code!=0) {
			printf("�������");
			printf("\n");
		} else
			break;

	}
	printf("**************��ӭ����༶��������ϵͳ��****************\n");
	printf("*******************410������Ʒ��**********************\n");
	printf("\n\n");
	menu();
	while(scanf("%c",&n)!=EOF) {
		switch(n) {
			case 'a':
				read();
				menu();
				break;
			case 'b':
				input();
				menu();
				break;
			case 'c':
				save();
				menu();
				break;
			case 'd':
				Delete();
				menu();
				break;
			case 'e':
				modi();
				menu();
				break;
			case 'f':
				search();
				menu();
				break;
			case 'g':
				Turnpasswd();
				menu();
				break;
			case 'h':
				exit(0);
				menu();
				break;
			case'p':
				help();
				menu();
				break;
		}
	}
	return 0;
}

