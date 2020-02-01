#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<windows.h>


#define LEN sizeof(struct student)                    //无参宏定义

struct student                                        //定义学生的结构体类型
{
	long num;
	char name[10];
	char sex[10];
	float score[3];
	float avg;
	struct student* next;
};


//定义全局变量
double A;                                                                                //定义全局变量,A-选择菜单功能
int B, N;                                                                                //定义全局变量,B-菜单选择标志,N-节点个数 
struct student* h;                                                                       //定义结构体变量头指针
char address_users[128] = "\0", address_AD[] = "D:\\address_AD.txt";                     //定义用户地址字符数组


//函数声明
int Pos(int, int);                                    //光标函数
int once(void);                                       //界面处理
int address(void);                                    //地址检测
int welcome(void);                                    //菜单界面
int quit(void);                                       //子功能退出
int defaul(void);                                     //选择错误界面
int create(void);                                     //输入
int create_1(void);
int create_2(void);
int create_3(void);
int print(void);                                      //输出
int print_1(void);
int print_2(void);
int print_3(void);
int sort(void);                                       //排序
int sort_1(void);
int sort_2(void);
int find(void);                                       //查找
int find_1(void);
int find_2(void);
int insert(void);                                     //插入
int insert_1(void);
int insert_2(void);
int delet(void);                                      //删除
int delet_1(void);
int delet_2(void);
int revise(void);                                     //修改
int statistics(void);                                 //统计
int write(void);                                      //保存
int leave(void);                                      //退出
int Free(void);                                       //释放内存
int choose(void);                                     //菜单选择

int Pos(int x, int y)                                 //设置光标位置
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
	return 0;
}


int once(void)
{
	system("title 学生成绩管理系统——作者:*咖啡不苦");
	system("mode con cols=120 lines=30");
	system("color f0");
	return 0;
}


int address(void)                                     //地址检测功能(文件检测)
{
	FILE* fp;
	if (strlen(address_users) == 0)
		if ((fp = fopen(address_AD, "r")) == NULL)
		{
			Pos(38, 12);
			printf("您还未设置文件储存地址，请先进行地址输入操作!");
			Pos(35, 14);
			printf("或设置默认地址和文件名！否则部分功能可能无法正常使用！\n\n\n\n\n\n");
			system("pause");
			system("cls");
		}
		else
		{
			fgets(address_users, 128, fp);
			fclose(fp);
		}
	return 0;
}



int welcome(void)                                     //菜单界面
{
	int i, j;
	A = -1;                                           //每次进入菜单界面，重新选择功能
	for (i = 0;i <= 20;i++)                           //打印菜单界面
	{
		Pos(48 + i, 5);
		printf("_");
		Pos(48 + i, 10);
		printf("_");
	}
	for (j = 0;j <= 4;j++)
	{
		Pos(48, 6 + j);
		printf("|");
		Pos(68, 6 + j);
		printf("|");
	}
	Pos(50, 7);
	printf("学生成绩管理系统");
	Pos(54, 9);
	printf("欢迎使用!");
	Pos(6, 20); 
	printf("1.输入     2.输出     3.排序     4.查找     5.插入     6.删除     7.修改     8.统计      9.保存      0.退出");
	Pos(46, 14);
	printf("请选择你想使用的功能(0-9):");
	if (scanf_s("%lf", &A) != 1)
		while (getchar() != '\n');
	system("cls");                                    //清屏
	return 0;
}


int quit(void)                                        //退出子功能
{
	Pos(54, 14);
	printf("退出成功!\n");
	system("pause");
	return 0;
}


int defaul(void)                                      //选择错误界面
{
	Pos(48, 12);
	printf("输入错误,请重新输入!\n");
	system("pause");
	return 0;
}



int create_1(void)                                    //1.1学生信息输入（建立链表）
{
	int n, t;
	struct student* head = NULL, * p1 = NULL, * p2 = NULL, * p = NULL;
	n = 0, head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	if (p1 == NULL)
	{
		Pos(48, 12);
		printf("内存申请失败,已退出！\n！");
		return 0;
	}
	Pos(38, 8);
	printf("请按照顺序输入学生的以下六项信息(学号不能为零!):");
	Pos(41, 10);
	printf("学号 姓名 性别 语文成绩 数学成绩 英语成绩");
	Pos(48, 12);
	printf("输入任意非正确格式退出输入!\n");
	Pos(50, 14);
	printf("各信息之间请用空格隔开!\n\n\n\n\n\n\n");
	Pos(28, 22);
	printf("（注意！！！若原有链表不为空，输入成功后，会丢失原有链表的所有信息！）\n\n");
	system("pause");
	system("cls");
	printf("请输入学生信息:");
	t = scanf_s("%ld %s%s %f %f %f", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2]);
	if (t != 6)
		goto end_1;
	p1->next = NULL;                                    //初始化节点1
	while (p1->num != 0)
	{
		++n;
		if (n == 1)
			head = p1;
		else
			p2->next = p1;
		p2 = p1;
		p1 = (struct student*)malloc(LEN);
		if (p1 == NULL)
		{
			system("cls");
			Pos(48, 12);
			printf("内存申请失败,已退出！\n");
			return 0;
		}
		printf("请输入学生信息:");
		t = scanf_s("%ld %s%s %f %f %f", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2]);
		if (t != 6)
			goto end_1;
		p1->next = NULL;
	}
    end_1:free(p1);
	if (t != 6)
		while (getchar() != '\n');
	N = n;
	printf("输入结束!\n");
	Free();
	h = head;
	system("pause");                                  //暂停
	return 0;
}


int create_2(void)                                    //1.2地址输入
{
	FILE* fp;
	if ((fp = fopen(address_AD, "w")) == NULL)
	{
		Pos(46, 12);
		printf("文件打开失败，请稍后重试！");
		system("pause");
	}
	else
	{
		char address_ad[128] = "\0", address_id[20] = "\0";
		char address_lizi[40] = "C:\\";
		strcat(address_lizi, "\\Users\\");
		strcat(address_lizi, "\\lx0621\\");
		strcat(address_lizi, "\\Desktop");
		Pos(46, 7);
		printf("若需退出输入，地址请输入0！");
		Pos(44, 8);
		printf("请注意！退出后，地址信息将被擦除！");
		Pos(22, 10);
		printf("请输入文件储存地址:(请以双斜杠格式进行输入！例如 %s)", address_lizi);
		Pos(40, 11);
		scanf_s("%s", address_ad,128);
		if (address_ad[1] == 0)
		{
			system("cls");
			Pos(48, 12);
			printf("首字符为0，已退出输入！\n");
			system("pause");
			return 0;
		}
		Pos(36, 13);
		printf("请输入文件名:（例如 学生信息）");
		Pos(40, 14);
		scanf_s("%s", address_id,20);
		strcat(address_ad, "\\");
		strcat(address_ad, "\\");
		strcat(address_ad, address_id);
		strcat(address_ad, ".txt");
		strcpy(address_users, address_ad);
		fputs(address_users, fp);
		fclose(fp);
		Pos(22, 16);
		printf("文件储存地址和文件名输入完成！储存地址为:%s", address_users);
		Pos(28, 17);
		printf("（请确保地址和文件名有效且正确，否则其他部分功能可能无法正常使用！）\n");
		system("pause");
	}
	return 0;
}



int create_3(void)                                    //1.3设置默认地址
{
	FILE* fp,*fp1;
	Pos(42, 12);
	printf("即将把文件储存地址和文件名设置为默认！");
	Pos(44, 14);
	printf("如需更改请进行地址储存输入操作！");
	Pos(40, 16);
	printf("文件默认储存地址和文件名为 D:\\学生信息.txt\n");
	system("pause");
	system("cls");
	if ((fp = fopen(address_AD, "w")) == NULL)
	{
		Pos(48, 12);
		printf("文件打开失败，请稍后重试！");
		system("pause");
	}
	else
	{
		char mr[20] = "D:\\";
		strcat(mr, "\\学生信息.txt");
		fputs(mr, fp);
		fclose(fp);
		fp1 = fopen(mr, "w");
		fclose(fp1);
		strcpy(address_users, "D:\\学生信息.txt");
		Pos(48, 12);
		printf("设置默认地址成功！\n");
		system("pause");
	}
	return 0;
}



int create(void)                                      //1.输入功能
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(10, 20);
		printf("1.学生信息输入             2.文件储存地址输入             3.设置默认地址和文件名             4.退出");
		Pos(54, 8);
		printf("1.输入功能选择:");
		if (scanf("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:create_1();             break;
			case 2:create_2();             break;
			case 3:create_3();             break;
			case 4:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}


int print_1(void)                                     //2.1文件输出至链表
{
	int n = 0;
	FILE* fp2;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	if (p1 == NULL)
	{
		Pos(48, 12);
		printf("内存申请失败,已退出！\n");
		return 0;
	}
	if ((fp2 = fopen(address_users, "r")) == NULL)    //打开并测试文件
	{
		Pos(40, 12);
		printf("打开文件失败!请先进行地址输入或保存操作！\n");
		system("pause");
		return 0;                                                                                                                          //若文件打开不成功，退出
	}
	fseek(fp2, 66, 0);
	fscanf_s(fp2, "%ld %s %s %f %f %f %f\n", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2], &p1->avg);    //文件信息读至节点对应元素
	printf("%ld %s %s %.2f %.2f %.2f %.2f\n", p1->num, p1->name, p1->sex, p1->score[0], p1->score[1], p1->score[2], p1->avg);              //输出查看是否正确
	p1->next = NULL;
	do
	{
		++n;
		if (n == 1)
			head = p1;
		else
		{
			p1 = (struct student*)malloc(LEN);
			if (p1 == NULL)
			{
				system("cls");
				Pos(48, 12);
				printf("内存申请失败,已退出！\n");
				return 0;
			}
			fscanf_s(fp2, "%ld %s %s %f %f %f %f\n", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2], &p1->avg);
			printf("%ld %s %s %.2f %.2f %.2f %.2f\n", p1->num, p1->name, p1->sex, p1->score[0], p1->score[1], p1->score[2], p1->avg);
			p1->next = NULL;
			p2->next = p1;
			p2 = p1;
		}
	} while (!feof(fp2));
	fclose(fp2);
	printf("\n\n\n\n\n\n                                                文件信息已成功写入链表!\n");
	N = n;
	h = head;
	system("pause");
	return 0;
}



int print_2(void)                                     //2.2文件输出
{
	FILE* fp1;
	char ch;
	if ((fp1 = fopen(address_users, "r")) == NULL)    //打开并测试文件
	{
		Pos(40, 12);
		printf("打开文件失败!请先进行地址输入或保存操作！\n");
		system("pause");
		return 0;                                                                        //若文件打开不成功，退出
	}
	while ((ch = fgetc(fp1)) != EOF)                                                     //读文件并测试是否文件尾
		fputc(ch, stdout);                                                               //输出到标准设备文件（显示器）显示
	fclose(fp1);
	printf("\n\n\n\n\n\n                                                  文件信息已经成功读取!\n");
	system("pause");
	return 0;
}



int print_3(void)                                     //2.3链表输出
{
	int i = 0;
	struct student* head=NULL, * p=NULL;
	head = h;
	p = head;
	if (p != NULL)
	{
		printf("学号        姓名        性别        语文        数学        英语         平均分");
		do
		{
			Pos(1, 2 + i);
			printf("%ld", p->num);
			Pos(12, 2 + i);
			printf("%s", p->name);
			Pos(25, 2 + i);
			printf("%s", p->sex);
			Pos(36, 2 + i);
			printf("%.2f", p->score[0]);
			Pos(48, 2 + i);
			printf("%.2f", p->score[1]);
			Pos(60, 2 + i);
			printf("%.2f", p->score[2]);
			Pos(73, 2 + i);
			printf("%.2f", (p->avg) = (p->score[0] + p->score[1] + p->score[2]) / 3);
			p = p->next;
			i++;
		} while (p != NULL);
		printf("\n\n\n\n\n\n                                                链表信息已成功输出！\n");
	}
	else
	{
		Pos(56, 12);
		printf("无学生信息!");
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}



int print(void)                                       //2.输出功能
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(12, 20);
		printf("1.文件输出至链表                2.文件输出                3.链表输出                 4.退出");
		Pos(54, 8);
		printf("2.输出功能选择:");
		if (scanf_s("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:print_1();              break;
			case 2:print_2();              break;
			case 3:print_3();              break;
			case 4:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}



int sort_1(void)                                      //3.1学号排序(链表排序,选择排序法)
{
	int n, nummin;
	struct student* head=NULL, * p=NULL, * pmin=NULL, * p1=NULL, * p2=NULL;
	n = N;
	p = (struct student*)malloc(LEN);
	p1 = head = h;
	if (p == NULL)
	{
		Pos(48, 12);
		printf("内存申请失败,已退出！\n");
		return 0;
	}
	Pos(46, 12);
	printf("按照学号大小,从小到大进行排序!\n");
	system("pause");
	system("cls");
	if (head != NULL)
	{
		while (p1->next != NULL)
		{
			nummin = p1->num;
			pmin = p1;
			p2 = p1->next;
			while (p2 != NULL)
			{
				if (nummin > p2->num)
				{
					nummin = p2->num;
					pmin = p2;
				}
				p2 = p2->next;
			}
			p->num = p1->num, strcpy(p->name, p1->name), strcpy(p->sex, p1->sex),
				p->score[0] = p1->score[0], p->score[1] = p1->score[1], p->score[2] = p1->score[2], p->avg = p1->avg;
			p1->num = pmin->num, strcpy(p1->name, pmin->name), strcpy(p1->sex, pmin->sex),
				p1->score[0] = pmin->score[0], p1->score[1] = pmin->score[1], p1->score[2] = pmin->score[2], p1->avg = pmin->avg;
			pmin->num = p->num, strcpy(pmin->name, p->name), strcpy(pmin->sex, p->sex),
				pmin->score[0] = p->score[0], pmin->score[1] = p->score[1], pmin->score[2] = p->score[2], pmin->avg = p->avg;
			p1 = p1->next;
		}

		Pos(48, 14);
		printf("排序完成!请进行输出查看！\n");
		free(p);
	}
	else
	{
		Pos(50, 14);
		printf("无学生信息!\n\n\n");
	}
	system("pause");
	return 0;
}


int sort_2(void)                                      //3.2平均分排序(链表排序,选择排序法)
{
	int n=0;
	float avgmin=0;
	struct student* head=NULL, * p=NULL, * pmin=NULL, * p1=NULL, * p2=NULL;
	n = N;
	p = (struct student*)malloc(LEN);
	p1 = head = h;
	if (p == NULL)
	{
		Pos(48, 12);
		printf("内存申请失败,已退出！\n");
		return 0;
	}
	Pos(46, 12);
	printf("按照平均分,从低到高进行排序!\n");
	system("pause");
	system("cls");
	if (head != NULL)
	{
		while (p1->next != NULL)
		{
			avgmin = p1->avg;
			pmin = p1;
			p2 = p1->next;
			while (p2 != NULL)
			{
				if (avgmin > p2->avg)
				{
					avgmin = p2->avg;
					pmin = p2;
				}
				p2 = p2->next;
			}
			p->num = p1->num, strcpy(p->name, p1->name), strcpy(p->sex, p1->sex),
				p->score[0] = p1->score[0], p->score[1] = p1->score[1], p->score[2] = p1->score[2], p->avg = p1->avg;
			p1->num = pmin->num, strcpy(p1->name, pmin->name), strcpy(p1->sex, pmin->sex), 
				p1->score[0] = pmin->score[0], p1->score[1] = pmin->score[1], p1->score[2] = pmin->score[2], p1->avg = pmin->avg;
			pmin->num = p->num, strcpy(pmin->name, p->name), strcpy(pmin->sex, p->sex),
				pmin->score[0] = p->score[0], pmin->score[1] = p->score[1], pmin->score[2] = p->score[2], pmin->avg = p->avg;
			p1 = p1->next;
		}
		Pos(48, 14);
		printf("排序完成!请输出查看！\n");
		free(p);
	}
	else
	{
		Pos(50, 14);
		printf("无学生信息!\n\n\n");
	}
	system("pause");
	return 0;
}




int sort(void)                                        //3.排序功能
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(16, 20);
		printf("1.学号排序                            2.平均分排序                            3.退出");
		Pos(52, 8);
		printf("3.排序功能选择:");
		if (scanf_s("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:sort_1();               break;
			case 2:sort_2();               break;
			case 3:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}




int find_1(void)                                      //4.1学号查找（链表查找）
{
	int i = 0, j = 0, t=0;
	long num = 0;
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(48, 10);
	printf("输入学号进行查找!");
	Pos(42, 12);
	printf("输入学号'0'和非正确格式都将退出!\n");
	system("pause");
	system("cls");
	printf("请输入要查找学生的学号:");
	t = scanf("%ld", &num);
	if (num == 0 || t != 1)
		goto end_4_1;
	if (head == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("无学生信息!\n");
	}
	else
	{
		Pos(0, 14);
		printf("学号        姓名        性别        语文        数学        英语        平均分");
		do
		{
			p = head;
			while ((p != NULL) && (num != p->num))
				p = p->next;
			if (p != NULL)
			{
				Pos(40, i);
				printf("    已查找到该学生信息!");
				Pos(1, 15 + i);
				printf("%ld", p->num);
				Pos(12, 15 + i);
				printf("%s", p->name);
				Pos(25, 15 + i);
				printf("%s", p->sex);
				Pos(36, 15 + i);
				printf("%.2f", p->score[0]);
				Pos(48, 15 + i);
				printf("%.2f", p->score[1]);
				Pos(60, 15 + i);
				printf("%.2f", p->score[2]);
				Pos(73, 15 + i);
				printf("%.2f", p->avg);
				i++;
			}
			else
			{
				Pos(40, i);
				printf("    未找到该学生!\n");
				i++;
			}
			if (i == 10)
			{
				printf("\n即将进行清屏！\n");
				system("pause");
				system("cls");
				i = 0;
				Pos(0, 14);
				printf("学号        姓名        性别        语文        数学        英语        平均分");
			}
			Pos(0, i);
			printf("请输入要查找学生的学号:");
			t = scanf_s("%ld", &num);
			printf("\n");
		} while (num != 0 || t != 1);
	end_4_1:printf("查找结束!\n");
	}
	if (t != 1)
		while (getchar() != '\n');
	system("pause");
	return 0;
}



int find_2(void)                                      //4.2姓名查找（链表查找）
{
	int i = 0, j = 0;
	char name_2[10];
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(46, 14);
	printf("输入姓名进行查找!");
	Pos(46, 16);
	printf("输入'0'即可退出\n");
	system("pause");
	system("cls");
	printf("请输入要查找学生的姓名:");
	scanf_s("%s", name_2,10);
	if (name_2[0] == 48)
		goto end_4_2;
	if (head == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("无学生信息!\n");
	}
	else
	{
		Pos(0, 14);
		printf("学号        姓名        性别        语文        数学        英语        平均分");
		do
		{
			p = head;
			while ((p != NULL) && strcmp(name_2, p->name))
				p = p->next;
			if (p != NULL)
			{
				Pos(50, i);
				printf("    已查找到该学生信息!");
				Pos(1, 15 + i);
				printf("%ld", p->num);
				Pos(12, 15 + i);
				printf("%s", p->name);
				Pos(25, 15 + i);
				printf("%s", p->sex);
				Pos(36, 15 + i);
				printf("%.2f", p->score[0]);
				Pos(48, 15 + i);
				printf("%.2f", p->score[1]);
				Pos(60, 15 + i);
				printf("%.2f", p->score[2]);
				Pos(73, 15 + i);
				printf("%.2f", p->avg);
				i++;
			}
			else
			{
				Pos(50, i);
				printf("    未找到该学生!\n");
				i++;
			}
			if (i == 10)
			{
				printf("\n即将进行清屏！\n");
				system("pause");
				system("cls");
				i = 0;
				Pos(0, 14);
				printf("学号        姓名        性别        语文        数学        英语        平均分");
			}
			Pos(0, i);
			printf("请输入要查找学生的学号:");
			scanf_s("%s", name_2,10);
			printf("\n");
		} while (name_2[0] != 48);
	end_4_2:printf("查找结束!\n");
	}
	system("pause");
	return 0;
}




int find(void)                                        //4.查找功能(链表查找)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.学号查找                          2.姓名查找                          3.退出");
		Pos(52, 8);
		printf("4.查找功能选择:");
		if (scanf_s("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:find_1();               break;
			case 2:find_2();               break;
			case 3:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}




int insert_1(void)                                    //5.1学号插入(插入链表)
{
	int n, t0, t;
	long num=0;
	n = N;
	struct student *stud=NULL, *head=NULL, *p0=NULL, *p1=NULL, *p2=NULL;
	head = h;
	stud = (struct student*)malloc(LEN);
	p1 = head, p0 = stud;
	if (p0 == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("内存申请失败,已退出！\n");
		return 0;
	}
	Pos(48, 12);
	printf("各信息之间请用空格隔开!\n");
	Pos(46, 14);
	printf("请按相应格式输入,否则会退出!\n");
	system("pause");
	system("cls");
	printf("请输入插入学生信息:");
	t0 = scanf_s("%ld %s %s %f %f %f", &p0->num, p0->name,10, p0->sex,10, &p0->score[0], &p0->score[1], &p0->score[2]);
	printf("请输入想插入在那个学号之前:");
	t = scanf_s("%ld", &num);
	if (t != 1 || t0 != 6)
		goto end_5_1;
	if (head == NULL)                                 //无学生信息,成为第一个
	{
		head = p0;
		p0->next = NULL;
		printf("\n无学生信息,已成为第一个!\n");
	}
	else
	{
		while ((p1 != NULL) && !(num == p1->num))     //插入学号大于当前学号，后移
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (head == p1)                               //第一个小于插入学号，做第一个
		{
			p0->next = head;
			head = p0;
		}
		else                                          //找到，插在插入之前
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	++n;
	printf("已成功插入学生信息，请输出查看！\n\n\n");
	if (t != 1 || t0 != 6)
	{
	end_5_1:printf("\n\n输入格式错误，已退出!\n");
		while (getchar() != '\n');
		free(stud);
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}


int insert_2(void)                                    //5.2姓名插入(插入链表)
{
	int n, t0, t;
	char name_5_2[10];
	n = N;
	struct student* stud=NULL, * head=NULL, * p0=NULL, * p1=NULL, * p2=NULL;
	head = h;
	stud = (struct student*)malloc(LEN);
	p1 = head, p0 = stud;
	if (p0 == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("内存申请失败,已退出！\n");
		return 0;
	}
	Pos(48, 12);
	printf("各信息之间请用空格隔开!\n");
	Pos(44, 14);
	printf("请按相应格式输入,否则可能异常退出!\n");
	system("pause");
	system("cls");
	printf("请输入插入学生信息:");
	t0 = scanf_s("%ld %s %s %f %f %f", &p0->num, p0->name,10, p0->sex,10, &p0->score[0], &p0->score[1], &p0->score[2]);
	printf("请输入想插入在那个学生之前:");
	t = scanf_s("%s", name_5_2,10);
	name_5_2[9] = '\0';
	if (t != 1 || t0 != 6)
		goto end_5_2;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
		printf("\n无学生信息,已成为第一个!\n");
	}
	else
	{
		while ((p1 != NULL) && (strcmp(name_5_2, p1->name) != 0))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (head == p1)
		{
			p0->next = head;
			head = p0;
		}
		else
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	++n;
	printf("已成功插入学生信息，请输出查看！\n\n\n");
	if (t != 1 || t0 != 6)
	{
	end_5_2:printf("输入格式错误，已退出!\n");
		while (getchar() != '\n');
		free(stud);
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}




int insert(void)                                      //5.插入功能(插入链表)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.学号插入                          2.姓名插入                          3.退出");
		Pos(52, 8);
		printf("5.插入功能选择:");
		if (scanf_s("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:insert_1();             break;
			case 2:insert_2();             break;
			case 3:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}



int delet_1(void)                                     //6.1按学号删除(链表删除)
{
	int n = 0, t;
	long num = 0;
	n = N;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	head = h;
	printf("请输入想要删除的学生学号:");
	t = scanf_s("%ld", &num);
	if (t != 1)
		goto end_6_1;
	if (head == NULL)
		printf("无学生信息!\n");
	else
	{
		p1 = head;
		while (num != p1->num && p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (num == p1->num)
		{
			if (p1 == head)
				head = p1->next;
			else
				p2->next = p1->next;
			printf("\n已删除%ld号的学生信息，请输出查看！\n", num);
			free(p1);
			--n;
		}
		else
			printf("\n找不到该学生!\n");
	}
	N = n;
	h = head;
	if (t != 1)
	{
	end_6_1:while (getchar() != '\n');
		printf("\n\n输入格式错误，已退出！\n");
	}
	system("pause");
	return 0;
}


int delet_2(void)                                     //6.2按姓名删除(链表删除)
{
	int n = 0;
	char name_6[10];
	n = N;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	head = h;
	printf("请输入想要删除的学生姓名:");
	scanf_s("%s", name_6,10);
	name_6[9] = '\0';
	if (head == NULL)
		printf("无学生信息!\n");
	else
	{
		p1 = head;
		while (strcmp(name_6, p1->name) != 0 && p1->next != NULL)
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (strcmp(name_6, p1->name) == 0)
		{
			if (p1 == head)
				head = p1->next;
			else
				p2->next = p1->next;
			printf("\n已删除%s的学生信息，请输出查看！\n", name_6);
			free(p1);
			--n;
		}
		else
			printf("\n找不到该学生!\n");
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}



int delet(void)                                       //6.删除功能(链表节点删除)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.按学号删除                          2.按姓名删除                          3.退出");
		Pos(54, 8);
		printf("6.删除功能选择:");
		if (scanf_s("%lf", &i) != 1)
			while (getchar() != '\n');
		system("cls");
		if (fabs(i - (int)i) < 1e-5)
		{
			switch ((int)i)
			{
			case 1:delet_1();              break;
			case 2:delet_2();              break;
			case 3:quit();j = 1;           break;
			default:defaul();
			}
		}
		else
			defaul();
		system("cls");
	} while (!j);
	return 0;
}



int revise(void)                                      //7.修改功能(链表节点修改)
{
	int n = 0, t = 0, t0 = 0, i = 0;
	long num = 0;
	n = N;
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(0, i);
	printf("请输入要修改学生的学号:");
	t = scanf_s("%ld", &num);
	if (num == 0)
		goto end_7_10;
	if (t != 1)
		goto end_7_1;
	if (head == NULL)
	{
		system("cls");
		Pos(56, 12);
		printf("无学生信息！\n");
	}
	else
	do
	{
		p = head;
		while ((p != NULL) && (num != p->num))
			p = p->next;
		if (p != NULL)
		{
			Pos(0, ++i);
			printf("请输入新的学生信息:");
			t0=scanf(" %ld %s %s %f %f %f", &p->num, p->name, p->sex, &p->score[0], &p->score[1], &p->score[2]);
			if (t0 != 6)
				goto end_7_1;
			Pos(50, i);
			printf("已成功修改！");
		}
		else
		{
			Pos(50, i);
			printf("找不到该学生！\n");
		}
		Pos(0, ++i);
		printf("请输入要修改学生的学号:");
		t = scanf_s("%ld", &num);
		if (num == 0)
			goto end_7_10;
		if (t != 1)
			goto end_7_1;
	} while (p==NULL||p->num != 0);
    if (t != 1)
	{
	    end_7_1:while (getchar() != '\n');
		printf("\n\n输入格式错误，已退出！\n");
	}
	if (num == 0)
	{
	    end_7_10:Pos(48, i + 6);
		printf("修改结束，已退出！\n");
	}
	system("pause");
	return 0;
}

int  statistics(void)                                 //8.统计功能
{
	int i = 0, j = 0, t=0;
	float avg_8 = 0;
	struct student* p=NULL;
	p = h;
	Pos(46, 12);
	printf("按超过某个平均分的成绩进行统计!");
	Pos(52, 14);
	printf("请输入一个平均分!\n");
	system("pause");
	system("cls");
	printf("请输入分数:");
	t = scanf_s("%f", &avg_8);
	if (t != 1)
		goto end_8;
	printf("\n");
	if (p != NULL)
	{
		printf("学号        姓名        性别        语文        数学        英语         平均分");
		do
		{
			if (((double)(p->avg) - avg_8) > 1e-5)
			{
				Pos(1, 3 + i);
				printf("%ld", p->num);
				Pos(12, 3 + i);
				printf("%s", p->name);
				Pos(24, 3 + i);
				printf("%s", p->sex);
				Pos(36, 3 + i);
				printf("%.2f", p->score[0]);
				Pos(48, 3 + i);
				printf("%.2f", p->score[1]);
				Pos(60, 3 + i);
				printf("%.2f", p->score[2]);
				Pos(73, 3 + i);
				printf("%.2f", p->avg);
				i++;
				j++;
			}
			p = p->next;
		} while (p != NULL);
		printf("\n");
		if (i == 0)
		{
			system("cls");
			Pos(48, 14);
			printf("无符合的学生信息!\n");
		}
		printf("\n\n\n共有%d人!\n", j);
	}
	else
	{
		Pos(48, 12);
		printf("无学生信息!\n");
		i = 1;
	}
	if (t != 1)
	{
	end_8:while (getchar() != '\n');
		printf("\n输入格式错误，已退出!\n");
	}
	system("pause");
	return 0;
}



int write(void)                                       //9.保存功能（链表信息储存为文件）
{
	int n = 0;
	FILE* fp1;
	struct student* str1=NULL;
	n = N;
	str1 = h;
	if (str1 == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("链表为空,已退出！\n");
		return 0;
	}
	if ((fp1 = fopen(address_users, "w")) == NULL)
	{
		Pos(42, 12);
		printf("保存失败!请先进行地址输入或稍后重试！\n");                          //文件打开失败
		system("pause");
	}
	else
	{
		if (str1 != NULL)
			fputs("学号      姓名      性别      语文      数学      英语      平均分", fp1);
		fputc('\n', fp1);
		while (n != 0)
		{
			fprintf_s(fp1, "%-10ld%-10s%-10s%-10.2f%-10.2f%-10.2f%-10.2f", str1->num, str1->name, str1->sex,
				str1->score[0], str1->score[1], str1->score[2], (str1->avg) = (str1->score[0] + str1->score[1] + str1->score[2]) / 3);
			fputc('\n', fp1);
			str1 = str1->next;
			n--;
		}
		fclose(fp1);
		Pos(54, 12);
		printf("已保存完成!\n");
		system("pause");
	}
	return 0;
}



int leave(void)                                       //0.退出功能
{
	Free();
	Pos(54, 14);
	printf("退出成功!");
	Pos(52, 16);
	printf("欢迎下次使用!\n");
	B = 1;
	system("pause");
	return 0;
}

int Free(void)                                        //释放内存函数
{
	struct student* p = NULL, * p0 = NULL;
	p = p0 = h;
	while (p != NULL)
	{
		p0 = p0->next;
		free(p);
		p = p0;
	}
	if (p != NULL)
	{
		Pos(49, 18);
		printf("(释放内存发生错误!)\n");
	}
	else
	{
		Pos(51, 18);
		printf("(释放内存成功!)\n");
	}
	return 0;
}

int choose(void)                                      //功能选择 
{
	B = 0;
	if (fabs(A-(int)A) < 1e-5)                        //判断输入是否为浮点数
	{
		switch ((int)A)
		{
		case 1:create();                    break;    //1.输入
		case 2:print();                     break;    //2.输出
		case 3:sort();                      break;    //3.排序
		case 4:find();                      break;    //4.查找
		case 5:insert();                    break;    //5.插入
		case 6:delet();                     break;    //6.删除
		case 7:revise();                    break;    //7.修改
		case 8:statistics();                break;    //8.统计
		case 9:write();                     break;    //9.保存
		case 0:leave();                     break;    //0.退出
		default:defaul();
		}
	}
	else
		defaul();
	system("cls");
	return 0;
}



int main(void)
{
	once();
	do
	{
		address();
		welcome();
		choose();
	} while (!B);
	return 0;
}





//来自于*咖啡不苦
//1.0版本完成于2019.08.02           20:41    615行
//1.1版本完成于2019.08.03           20:11    934行
//1.2版本完成于2019.08.04           18:51    1022行
//1.21修复BUG版本完成于2019.08.05   18:48    1026行        查找不到时异常退出问题
//1.22稳定版完成于2019.08.06        13:39    1060行
//1.23修剪版完成于2019.08.06        18:33    980行
//1.24修复版完成于2019.08.06        18:55    984行
//1.25修复版完成于2019.08.07        13:54    988行
//1.30修复版完成于2019.08.07        19:57    1021行        违规操作时异常退出问题
//1.40稳定版完成于2019.08.08        16:55    1024行
//1.50版本完成于2019.08.09          21:37    1020行        文件存放位置问题
//1.60版本完成于2019.08.11          12:38    1150行        文件储存位置用户可自定义
//1.61版本完成于2019.08.12          18:35    1155行        减少储存地址位置的文件打开次数
//1.70版本完成于2019.08.14          15:27    1108行        减少部分函数的使用次数
//1.71版本完成于2019.08.14          19:22    1150行        增加默认地址操作
//1.72版本完成于2019.08.14          20:10    1165行        增加地址输入时可退出
//1.80版本完成于2019.08.17          16:25    1212行        修复非正常输入的异常问题
//1.90版本完成于2019.08.23          16:38    1230行        增加退出时释放堆内存
//1.95版本完成于2019.09.03          23:00    1304行        增加修改功能和界面信息等
//1.96版本完成于2019.09.04          12:56    1305行        增加输入功能的原有链表的内存释放
//1.97版本完成于2019.09.07          17:17    1371行        修复所有警告信息