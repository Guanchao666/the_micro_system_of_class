#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define N 999 //定义容纳数据的最大量 

struct student { //定义一个包含学生信息的结构体数组
	char class_num[5];//班号
	char no[12];//学号
	char name[8];//姓名
	char sex[5];//性别
	char age[5];//年龄

};
struct student stu[N];//定义全局变量
typedef enum __bool { false = 0, true = 1 } bool;//定义一个布尔型结构体，用于判断布尔值

void menu() { //菜单函数
	printf("   FFFFFFF       IIIIIIII     TTTTTTTTTT   \n");
	printf("   FF               II            TT       \n");
	printf("   FFFFFF           II            TT       \n");
	printf("   FF               II            TT       \n");
	printf("   FF            IIIIIIII         TT       \n");
	printf("   FF      * * * * * * * * * * * * * * * * \n");
	printf("          *                                *\n");
	printf("          *    a.从文件中读入学生基本信息  *\n");
	printf("          *    b.添加新学生的基本信息      *\n");
	printf("          *    c.学生基本信息保存至文件    *\n");
	printf("          *    d.学生基本信息删除          *\n");
	printf("          *    e.学生基本信息修改          *\n");
	printf("          *    f.学生基本信息查询          *\n");
	printf("          *    g.修改登录密码              *\n");
	printf("          *    p.帮助文档                  *\n");
	printf("          *    h.退出系统                  *\n");
	printf("          *                                *\n");
	printf("          * * * * * * * * * * * * * * * * \n");
	printf("\n");
	printf("请输入选项:(a ~ g)\n");
}


void input() { //学生基本信息的录入
	int i;
	int n;
	printf("请输入添加学生数：");
	scanf("%d",&n);
	for(i=N-n; i<N; i++) {
		printf("请输入学生的基本信息:\n");
		printf("班号/Class:\n");
		scanf("%s",stu[i].class_num);
		printf("姓名/Name:\n");
		scanf("%s",stu[i].name);
		printf("性别/sex:\n");
		scanf("%s",stu[i].sex);
		printf("年龄/age:\n");
		scanf("%s",stu[i].age);
		printf("学号/Number:\n");
		scanf("%s",stu[i].no);

	}
	printf("\n");
	printf("请检查信息是否输入正确！别忘了按C保存哦！\n");
	printf("\n");
	for(i=N-n; i<N; i++) {
		printf("%s   %s   %s   %s   %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
	}
}


void save() { //学生信息保存
	FILE * fp;
	int i;
	fp= fopen("student.txt","w");
	if (fp == NULL) {
		printf("文件不存在!\n");
		exit(0);
	}
	for(i=0; i<N; i++) { //在此处判断姓名所占长度调整学生信息存入文件中的格式
		if(strlen(stu[i].name)==4) {
			fprintf(fp,"%s    %s   %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}
		if(strlen(stu[i].name)==6) {
			fprintf(fp,"%s  %s   %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);
		}
	}
	fclose(fp);
	printf("保存成功！\n");
}


void Delete() { //删除函数；
	FILE*fp;
	fp=fopen("student.txt","w");
	char number[10];
	int f;
	bool flag=false;
	printf("删除学生信息:\n");
	printf("请输入学号:\n");
	scanf("%s",number);
	int i;
	for (i =0; i<N; i++) {
		if (!strcmp(number,stu[i].no)) {
			for(f=i; f<N; f++) { //调用strcpy函数令数组中的下一位元素将上一位覆盖从而实现删除功能
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
		printf("该学生不存在!:\n");
		Delete();
	}
	for(i=0; i<N; i++) {
		fprintf(fp,"%s  %s  %s  %s  %s\n",stu[i].class_num,stu[i].name,stu[i].sex, stu[i].age,stu[i].no);

	}
	printf("删除成功！\n");
	fclose(fp);
}

void search() { //查找函数

	int f;
	FILE*fp;
	fp=fopen("student.txt","rb");
	for(f=0; f<N; f++) {
		fscanf(fp,"%s%s%s%s%s",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
	}
	bool flag=false;//定义一个bool类型进行判断,bool类型在开头中已用结构体定义
	int m;
	int i;
	printf("    1 按学号查询\n");
	printf("    2 按姓名查询\n");
	printf("    3 按班号查询\n");
	printf("    4 按年龄查询\n");
	printf("    5 按性别查询\n");
	printf("请输入选项：");
	printf("\n");
	scanf("%d",&m);
	switch(m) {
		case 1: {
			char num[10];//定义一个学号的数组
			printf("请输入学号:\n");
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
				printf("该学生不存在.\n");
			}
			break;
		}
		case 2:
			printf("请输入姓名:\n");
			char na[10];//定义一个姓名的数组
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
				printf("该学生不存在.\n");
			}
			break;
		case 5: {
			char ch[5];//定义一个性别的数组
			printf("请输入性别:\n");
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
				printf("该学生不存在.\n");
			}
			break;
		}
		case 4: {
			char num_age[5];//定义一个年龄的数组
			printf("请输入年龄:\n");
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
				printf("该学生不存在.\n");
			}
			break;
		}
		default:
			break;

		case 3: {
			char class_number[5];//定义一个班号的数组
			printf("请输入班号:\n");
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
				printf("该学生不存在.\n");
			}
			break;
		}
	}
}

void modi() { //信息修改函数
	FILE*fp;//定义修改密码文件的指针
	FILE*fp1;//定义学生信息文件的指针
	char a[7];
	char b[7];
	char c[10];
	char ch;
	int i=0;
	int f;
	bool temp=false;
	fp1=fopen("student.txt","r");
	for(f=0; f<N; f++) { //从文件中将信息读到结构体中
		fscanf(fp1,"%s%s%s%s%s",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
	}
	fclose(fp1);
	printf("请输入密码():\n");
	scanf("%s",b);
	if((fp=fopen("passwd.dat","r"))==NULL) {
		printf("打开文件失败！");
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
			printf("密码错误！请重新输入密码：\n");
			scanf("%s",b);
		}
	}
	printf("请输入需要修改信息学生的学号：\n");
	scanf("%s",c);
	for(f=0; f<N; f++) {
		if (!strcmp(c,stu[f].no)) {
			printf("%s   %s  %s  %s  %s\n",stu[f].class_num,stu[f].name,stu[f].sex,stu[f].age,stu[f].no);
			printf("\n");
			printf("请输入新的信息：\n");
			printf("班号:\n");
			scanf("%s",stu[f].class_num);
			printf("姓名:\n");
			scanf("%s",stu[f].name);
			printf("性别:\n");
			scanf("%s",stu[f].sex);
			printf("年龄:\n");
			scanf("%s",stu[f].age);
			printf("学号:\n");
			scanf("%s",stu[f].no);
			temp=true;
			break;
		}
	}
	if(!temp) {
		printf("该学生不存在！\n");
	}

}

void read() { //从文件中读取学生信息
	int i;
	FILE*fp;
	fp=fopen("student.txt","r");
	printf("班号 姓名 性别 年龄 学号\n");
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
	printf("读取成功！\n");
	fclose(fp);
}

int accesswd() { //密码验证函数
	FILE*fp;
	char c[7],b[7],a[6],d[6];
	int i=0,passwd;
	char ch;
	if ((fp=fopen("passwd.dat","r"))==NULL) {
		printf("您还未设定保护密码!  请设定保护密码(不超过6位)\n");
		scanf("%s",a);
		printf("请二次输入密码\n");
		scanf("%s",d);
		if (strcmp(a,d)) {
			printf("两次密码不对，请重新输入！\n");
			accesswd();//递归，使得程序可以重复验证密码
		} else {
			fp = fopen("passwd.dat","w");
			fprintf(fp,"%s",a);
			fclose(fp);
			return 0;
		}
	} else {
		printf("请输入登陆密码：\n");
		scanf("%s",b);
		ch=fgetc(fp);
		while (ch!=EOF&&i<6) {
			c[i] = ch;
			ch=fgetc(fp);
			i++;

		}
		c[6] = '\0';
		if (!strcmp(b,c)) { //判断字符串b和c是否相等，是返回值0，否返回值1
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
	printf("请输入原始密码\n");
	scanf("%s",b);
	fp=fopen("passwd.dat","r");
	ch=fgetc(fp);
	while (ch!=EOF&&i<6) {
		c[i] = ch;
		ch=fgetc(fp);
		i++;
	}
	c[6] = '\0';
	if (!strcmp(b,c)) { //判断字符串b和c是否相等，是则进入新密码修改，否则递归
		printf("请输入新密码！\n");
		scanf("%s",a);
	} else {
		printf("原始密码不对，请重新输入！\n");
		Turnpasswd();//递归，使得用户无需重新打开程序修改密码
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
	printf("1.初次使用程序时，程序会引导你设定密码，并在本目录生成passwd.dat文件用于存放您的密码数据。*\n");
	printf("2.本目录下的student.txt文件为储存学生信息的文件，可作为导入导出的文件使用。               *\n");
	printf("3.本目录下的passwd.dat，student.txt为软件所生存的文件，请勿删除，以免数据的丢失！         *\n");
	printf("4.录入学生信息并确认无误后，请按C保存，否则数据将会丢失！！                               *\n");
	printf("*******************************************************************************************\n");
}

int main(int argc, char* argv[]) {

	char a[7];
	char n;
	int code;

	while(1) {

		code=accesswd();//调用函数，判断是否设定密码等
		if(code!=0) {
			printf("密码错误！");
			printf("\n");
		} else
			break;

	}
	printf("**************欢迎进入班级档案管理系统！****************\n");
	printf("*******************410养猪场出品！**********************\n");
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
