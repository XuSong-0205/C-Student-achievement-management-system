#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<math.h>
#include<windows.h>


#define LEN sizeof(struct student)                    //�޲κ궨��

struct student                                        //����ѧ���Ľṹ������
{
	long num;
	char name[10];
	char sex[10];
	float score[3];
	float avg;
	struct student* next;
};


//����ȫ�ֱ���
double A;                                                                                //����ȫ�ֱ���,A-ѡ��˵�����
int B, N;                                                                                //����ȫ�ֱ���,B-�˵�ѡ���־,N-�ڵ���� 
struct student* h;                                                                       //����ṹ�����ͷָ��
char address_users[128] = "\0", address_AD[] = "D:\\address_AD.txt";                     //�����û���ַ�ַ�����


//��������
int Pos(int, int);                                    //��꺯��
int once(void);                                       //���洦��
int address(void);                                    //��ַ���
int welcome(void);                                    //�˵�����
int quit(void);                                       //�ӹ����˳�
int defaul(void);                                     //ѡ��������
int create(void);                                     //����
int create_1(void);
int create_2(void);
int create_3(void);
int print(void);                                      //���
int print_1(void);
int print_2(void);
int print_3(void);
int sort(void);                                       //����
int sort_1(void);
int sort_2(void);
int find(void);                                       //����
int find_1(void);
int find_2(void);
int insert(void);                                     //����
int insert_1(void);
int insert_2(void);
int delet(void);                                      //ɾ��
int delet_1(void);
int delet_2(void);
int revise(void);                                     //�޸�
int statistics(void);                                 //ͳ��
int write(void);                                      //����
int leave(void);                                      //�˳�
int Free(void);                                       //�ͷ��ڴ�
int choose(void);                                     //�˵�ѡ��

int Pos(int x, int y)                                 //���ù��λ��
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
	system("title ѧ���ɼ�����ϵͳ��������:*���Ȳ���");
	system("mode con cols=120 lines=30");
	system("color f0");
	return 0;
}


int address(void)                                     //��ַ��⹦��(�ļ����)
{
	FILE* fp;
	if (strlen(address_users) == 0)
		if ((fp = fopen(address_AD, "r")) == NULL)
		{
			Pos(38, 12);
			printf("����δ�����ļ������ַ�����Ƚ��е�ַ�������!");
			Pos(35, 14);
			printf("������Ĭ�ϵ�ַ���ļ��������򲿷ֹ��ܿ����޷�����ʹ�ã�\n\n\n\n\n\n");
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



int welcome(void)                                     //�˵�����
{
	int i, j;
	A = -1;                                           //ÿ�ν���˵����棬����ѡ����
	for (i = 0;i <= 20;i++)                           //��ӡ�˵�����
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
	printf("ѧ���ɼ�����ϵͳ");
	Pos(54, 9);
	printf("��ӭʹ��!");
	Pos(6, 20); 
	printf("1.����     2.���     3.����     4.����     5.����     6.ɾ��     7.�޸�     8.ͳ��      9.����      0.�˳�");
	Pos(46, 14);
	printf("��ѡ������ʹ�õĹ���(0-9):");
	if (scanf_s("%lf", &A) != 1)
		while (getchar() != '\n');
	system("cls");                                    //����
	return 0;
}


int quit(void)                                        //�˳��ӹ���
{
	Pos(54, 14);
	printf("�˳��ɹ�!\n");
	system("pause");
	return 0;
}


int defaul(void)                                      //ѡ��������
{
	Pos(48, 12);
	printf("�������,����������!\n");
	system("pause");
	return 0;
}



int create_1(void)                                    //1.1ѧ����Ϣ���루��������
{
	int n, t;
	struct student* head = NULL, * p1 = NULL, * p2 = NULL, * p = NULL;
	n = 0, head = NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	if (p1 == NULL)
	{
		Pos(48, 12);
		printf("�ڴ�����ʧ��,���˳���\n��");
		return 0;
	}
	Pos(38, 8);
	printf("�밴��˳������ѧ��������������Ϣ(ѧ�Ų���Ϊ��!):");
	Pos(41, 10);
	printf("ѧ�� ���� �Ա� ���ĳɼ� ��ѧ�ɼ� Ӣ��ɼ�");
	Pos(48, 12);
	printf("�����������ȷ��ʽ�˳�����!\n");
	Pos(50, 14);
	printf("����Ϣ֮�����ÿո����!\n\n\n\n\n\n\n");
	Pos(28, 22);
	printf("��ע�⣡������ԭ������Ϊ�գ�����ɹ��󣬻ᶪʧԭ�������������Ϣ����\n\n");
	system("pause");
	system("cls");
	printf("������ѧ����Ϣ:");
	t = scanf_s("%ld %s%s %f %f %f", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2]);
	if (t != 6)
		goto end_1;
	p1->next = NULL;                                    //��ʼ���ڵ�1
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
			printf("�ڴ�����ʧ��,���˳���\n");
			return 0;
		}
		printf("������ѧ����Ϣ:");
		t = scanf_s("%ld %s%s %f %f %f", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2]);
		if (t != 6)
			goto end_1;
		p1->next = NULL;
	}
    end_1:free(p1);
	if (t != 6)
		while (getchar() != '\n');
	N = n;
	printf("�������!\n");
	Free();
	h = head;
	system("pause");                                  //��ͣ
	return 0;
}


int create_2(void)                                    //1.2��ַ����
{
	FILE* fp;
	if ((fp = fopen(address_AD, "w")) == NULL)
	{
		Pos(46, 12);
		printf("�ļ���ʧ�ܣ����Ժ����ԣ�");
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
		printf("�����˳����룬��ַ������0��");
		Pos(44, 8);
		printf("��ע�⣡�˳��󣬵�ַ��Ϣ����������");
		Pos(22, 10);
		printf("�������ļ������ַ:(����˫б�ܸ�ʽ�������룡���� %s)", address_lizi);
		Pos(40, 11);
		scanf_s("%s", address_ad,128);
		if (address_ad[1] == 0)
		{
			system("cls");
			Pos(48, 12);
			printf("���ַ�Ϊ0�����˳����룡\n");
			system("pause");
			return 0;
		}
		Pos(36, 13);
		printf("�������ļ���:������ ѧ����Ϣ��");
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
		printf("�ļ������ַ���ļ���������ɣ������ַΪ:%s", address_users);
		Pos(28, 17);
		printf("����ȷ����ַ���ļ�����Ч����ȷ�������������ֹ��ܿ����޷�����ʹ�ã���\n");
		system("pause");
	}
	return 0;
}



int create_3(void)                                    //1.3����Ĭ�ϵ�ַ
{
	FILE* fp,*fp1;
	Pos(42, 12);
	printf("�������ļ������ַ���ļ�������ΪĬ�ϣ�");
	Pos(44, 14);
	printf("�����������е�ַ�������������");
	Pos(40, 16);
	printf("�ļ�Ĭ�ϴ����ַ���ļ���Ϊ D:\\ѧ����Ϣ.txt\n");
	system("pause");
	system("cls");
	if ((fp = fopen(address_AD, "w")) == NULL)
	{
		Pos(48, 12);
		printf("�ļ���ʧ�ܣ����Ժ����ԣ�");
		system("pause");
	}
	else
	{
		char mr[20] = "D:\\";
		strcat(mr, "\\ѧ����Ϣ.txt");
		fputs(mr, fp);
		fclose(fp);
		fp1 = fopen(mr, "w");
		fclose(fp1);
		strcpy(address_users, "D:\\ѧ����Ϣ.txt");
		Pos(48, 12);
		printf("����Ĭ�ϵ�ַ�ɹ���\n");
		system("pause");
	}
	return 0;
}



int create(void)                                      //1.���빦��
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(10, 20);
		printf("1.ѧ����Ϣ����             2.�ļ������ַ����             3.����Ĭ�ϵ�ַ���ļ���             4.�˳�");
		Pos(54, 8);
		printf("1.���빦��ѡ��:");
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


int print_1(void)                                     //2.1�ļ����������
{
	int n = 0;
	FILE* fp2;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	p1 = p2 = (struct student*)malloc(LEN);
	if (p1 == NULL)
	{
		Pos(48, 12);
		printf("�ڴ�����ʧ��,���˳���\n");
		return 0;
	}
	if ((fp2 = fopen(address_users, "r")) == NULL)    //�򿪲������ļ�
	{
		Pos(40, 12);
		printf("���ļ�ʧ��!���Ƚ��е�ַ����򱣴������\n");
		system("pause");
		return 0;                                                                                                                          //���ļ��򿪲��ɹ����˳�
	}
	fseek(fp2, 66, 0);
	fscanf_s(fp2, "%ld %s %s %f %f %f %f\n", &p1->num, p1->name,10, p1->sex,10, &p1->score[0], &p1->score[1], &p1->score[2], &p1->avg);    //�ļ���Ϣ�����ڵ��ӦԪ��
	printf("%ld %s %s %.2f %.2f %.2f %.2f\n", p1->num, p1->name, p1->sex, p1->score[0], p1->score[1], p1->score[2], p1->avg);              //����鿴�Ƿ���ȷ
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
				printf("�ڴ�����ʧ��,���˳���\n");
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
	printf("\n\n\n\n\n\n                                                �ļ���Ϣ�ѳɹ�д������!\n");
	N = n;
	h = head;
	system("pause");
	return 0;
}



int print_2(void)                                     //2.2�ļ����
{
	FILE* fp1;
	char ch;
	if ((fp1 = fopen(address_users, "r")) == NULL)    //�򿪲������ļ�
	{
		Pos(40, 12);
		printf("���ļ�ʧ��!���Ƚ��е�ַ����򱣴������\n");
		system("pause");
		return 0;                                                                        //���ļ��򿪲��ɹ����˳�
	}
	while ((ch = fgetc(fp1)) != EOF)                                                     //���ļ��������Ƿ��ļ�β
		fputc(ch, stdout);                                                               //�������׼�豸�ļ�����ʾ������ʾ
	fclose(fp1);
	printf("\n\n\n\n\n\n                                                  �ļ���Ϣ�Ѿ��ɹ���ȡ!\n");
	system("pause");
	return 0;
}



int print_3(void)                                     //2.3�������
{
	int i = 0;
	struct student* head=NULL, * p=NULL;
	head = h;
	p = head;
	if (p != NULL)
	{
		printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��         ƽ����");
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
		printf("\n\n\n\n\n\n                                                ������Ϣ�ѳɹ������\n");
	}
	else
	{
		Pos(56, 12);
		printf("��ѧ����Ϣ!");
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}



int print(void)                                       //2.�������
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(12, 20);
		printf("1.�ļ����������                2.�ļ����                3.�������                 4.�˳�");
		Pos(54, 8);
		printf("2.�������ѡ��:");
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



int sort_1(void)                                      //3.1ѧ������(��������,ѡ������)
{
	int n, nummin;
	struct student* head=NULL, * p=NULL, * pmin=NULL, * p1=NULL, * p2=NULL;
	n = N;
	p = (struct student*)malloc(LEN);
	p1 = head = h;
	if (p == NULL)
	{
		Pos(48, 12);
		printf("�ڴ�����ʧ��,���˳���\n");
		return 0;
	}
	Pos(46, 12);
	printf("����ѧ�Ŵ�С,��С�����������!\n");
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
		printf("�������!���������鿴��\n");
		free(p);
	}
	else
	{
		Pos(50, 14);
		printf("��ѧ����Ϣ!\n\n\n");
	}
	system("pause");
	return 0;
}


int sort_2(void)                                      //3.2ƽ��������(��������,ѡ������)
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
		printf("�ڴ�����ʧ��,���˳���\n");
		return 0;
	}
	Pos(46, 12);
	printf("����ƽ����,�ӵ͵��߽�������!\n");
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
		printf("�������!������鿴��\n");
		free(p);
	}
	else
	{
		Pos(50, 14);
		printf("��ѧ����Ϣ!\n\n\n");
	}
	system("pause");
	return 0;
}




int sort(void)                                        //3.������
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(16, 20);
		printf("1.ѧ������                            2.ƽ��������                            3.�˳�");
		Pos(52, 8);
		printf("3.������ѡ��:");
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




int find_1(void)                                      //4.1ѧ�Ų��ң�������ң�
{
	int i = 0, j = 0, t=0;
	long num = 0;
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(48, 10);
	printf("����ѧ�Ž��в���!");
	Pos(42, 12);
	printf("����ѧ��'0'�ͷ���ȷ��ʽ�����˳�!\n");
	system("pause");
	system("cls");
	printf("������Ҫ����ѧ����ѧ��:");
	t = scanf("%ld", &num);
	if (num == 0 || t != 1)
		goto end_4_1;
	if (head == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("��ѧ����Ϣ!\n");
	}
	else
	{
		Pos(0, 14);
		printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��        ƽ����");
		do
		{
			p = head;
			while ((p != NULL) && (num != p->num))
				p = p->next;
			if (p != NULL)
			{
				Pos(40, i);
				printf("    �Ѳ��ҵ���ѧ����Ϣ!");
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
				printf("    δ�ҵ���ѧ��!\n");
				i++;
			}
			if (i == 10)
			{
				printf("\n��������������\n");
				system("pause");
				system("cls");
				i = 0;
				Pos(0, 14);
				printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��        ƽ����");
			}
			Pos(0, i);
			printf("������Ҫ����ѧ����ѧ��:");
			t = scanf_s("%ld", &num);
			printf("\n");
		} while (num != 0 || t != 1);
	end_4_1:printf("���ҽ���!\n");
	}
	if (t != 1)
		while (getchar() != '\n');
	system("pause");
	return 0;
}



int find_2(void)                                      //4.2�������ң�������ң�
{
	int i = 0, j = 0;
	char name_2[10];
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(46, 14);
	printf("�����������в���!");
	Pos(46, 16);
	printf("����'0'�����˳�\n");
	system("pause");
	system("cls");
	printf("������Ҫ����ѧ��������:");
	scanf_s("%s", name_2,10);
	if (name_2[0] == 48)
		goto end_4_2;
	if (head == NULL)
	{
		system("cls");
		Pos(48, 12);
		printf("��ѧ����Ϣ!\n");
	}
	else
	{
		Pos(0, 14);
		printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��        ƽ����");
		do
		{
			p = head;
			while ((p != NULL) && strcmp(name_2, p->name))
				p = p->next;
			if (p != NULL)
			{
				Pos(50, i);
				printf("    �Ѳ��ҵ���ѧ����Ϣ!");
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
				printf("    δ�ҵ���ѧ��!\n");
				i++;
			}
			if (i == 10)
			{
				printf("\n��������������\n");
				system("pause");
				system("cls");
				i = 0;
				Pos(0, 14);
				printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��        ƽ����");
			}
			Pos(0, i);
			printf("������Ҫ����ѧ����ѧ��:");
			scanf_s("%s", name_2,10);
			printf("\n");
		} while (name_2[0] != 48);
	end_4_2:printf("���ҽ���!\n");
	}
	system("pause");
	return 0;
}




int find(void)                                        //4.���ҹ���(�������)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.ѧ�Ų���                          2.��������                          3.�˳�");
		Pos(52, 8);
		printf("4.���ҹ���ѡ��:");
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




int insert_1(void)                                    //5.1ѧ�Ų���(��������)
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
		printf("�ڴ�����ʧ��,���˳���\n");
		return 0;
	}
	Pos(48, 12);
	printf("����Ϣ֮�����ÿո����!\n");
	Pos(46, 14);
	printf("�밴��Ӧ��ʽ����,������˳�!\n");
	system("pause");
	system("cls");
	printf("���������ѧ����Ϣ:");
	t0 = scanf_s("%ld %s %s %f %f %f", &p0->num, p0->name,10, p0->sex,10, &p0->score[0], &p0->score[1], &p0->score[2]);
	printf("��������������Ǹ�ѧ��֮ǰ:");
	t = scanf_s("%ld", &num);
	if (t != 1 || t0 != 6)
		goto end_5_1;
	if (head == NULL)                                 //��ѧ����Ϣ,��Ϊ��һ��
	{
		head = p0;
		p0->next = NULL;
		printf("\n��ѧ����Ϣ,�ѳ�Ϊ��һ��!\n");
	}
	else
	{
		while ((p1 != NULL) && !(num == p1->num))     //����ѧ�Ŵ��ڵ�ǰѧ�ţ�����
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (head == p1)                               //��һ��С�ڲ���ѧ�ţ�����һ��
		{
			p0->next = head;
			head = p0;
		}
		else                                          //�ҵ������ڲ���֮ǰ
		{
			p2->next = p0;
			p0->next = p1;
		}
	}
	++n;
	printf("�ѳɹ�����ѧ����Ϣ��������鿴��\n\n\n");
	if (t != 1 || t0 != 6)
	{
	end_5_1:printf("\n\n�����ʽ�������˳�!\n");
		while (getchar() != '\n');
		free(stud);
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}


int insert_2(void)                                    //5.2��������(��������)
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
		printf("�ڴ�����ʧ��,���˳���\n");
		return 0;
	}
	Pos(48, 12);
	printf("����Ϣ֮�����ÿո����!\n");
	Pos(44, 14);
	printf("�밴��Ӧ��ʽ����,��������쳣�˳�!\n");
	system("pause");
	system("cls");
	printf("���������ѧ����Ϣ:");
	t0 = scanf_s("%ld %s %s %f %f %f", &p0->num, p0->name,10, p0->sex,10, &p0->score[0], &p0->score[1], &p0->score[2]);
	printf("��������������Ǹ�ѧ��֮ǰ:");
	t = scanf_s("%s", name_5_2,10);
	name_5_2[9] = '\0';
	if (t != 1 || t0 != 6)
		goto end_5_2;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
		printf("\n��ѧ����Ϣ,�ѳ�Ϊ��һ��!\n");
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
	printf("�ѳɹ�����ѧ����Ϣ��������鿴��\n\n\n");
	if (t != 1 || t0 != 6)
	{
	end_5_2:printf("�����ʽ�������˳�!\n");
		while (getchar() != '\n');
		free(stud);
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}




int insert(void)                                      //5.���빦��(��������)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.ѧ�Ų���                          2.��������                          3.�˳�");
		Pos(52, 8);
		printf("5.���빦��ѡ��:");
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



int delet_1(void)                                     //6.1��ѧ��ɾ��(����ɾ��)
{
	int n = 0, t;
	long num = 0;
	n = N;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	head = h;
	printf("��������Ҫɾ����ѧ��ѧ��:");
	t = scanf_s("%ld", &num);
	if (t != 1)
		goto end_6_1;
	if (head == NULL)
		printf("��ѧ����Ϣ!\n");
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
			printf("\n��ɾ��%ld�ŵ�ѧ����Ϣ��������鿴��\n", num);
			free(p1);
			--n;
		}
		else
			printf("\n�Ҳ�����ѧ��!\n");
	}
	N = n;
	h = head;
	if (t != 1)
	{
	end_6_1:while (getchar() != '\n');
		printf("\n\n�����ʽ�������˳���\n");
	}
	system("pause");
	return 0;
}


int delet_2(void)                                     //6.2������ɾ��(����ɾ��)
{
	int n = 0;
	char name_6[10];
	n = N;
	struct student* head=NULL, * p1=NULL, * p2=NULL;
	head = h;
	printf("��������Ҫɾ����ѧ������:");
	scanf_s("%s", name_6,10);
	name_6[9] = '\0';
	if (head == NULL)
		printf("��ѧ����Ϣ!\n");
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
			printf("\n��ɾ��%s��ѧ����Ϣ��������鿴��\n", name_6);
			free(p1);
			--n;
		}
		else
			printf("\n�Ҳ�����ѧ��!\n");
	}
	N = n;
	h = head;
	system("pause");
	return 0;
}



int delet(void)                                       //6.ɾ������(����ڵ�ɾ��)
{
	int j = 0;
	double i = 0;
	do
	{
		Pos(18, 20);
		printf("1.��ѧ��ɾ��                          2.������ɾ��                          3.�˳�");
		Pos(54, 8);
		printf("6.ɾ������ѡ��:");
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



int revise(void)                                      //7.�޸Ĺ���(����ڵ��޸�)
{
	int n = 0, t = 0, t0 = 0, i = 0;
	long num = 0;
	n = N;
	struct student* head=NULL, * p=NULL;
	head = h;
	Pos(0, i);
	printf("������Ҫ�޸�ѧ����ѧ��:");
	t = scanf_s("%ld", &num);
	if (num == 0)
		goto end_7_10;
	if (t != 1)
		goto end_7_1;
	if (head == NULL)
	{
		system("cls");
		Pos(56, 12);
		printf("��ѧ����Ϣ��\n");
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
			printf("�������µ�ѧ����Ϣ:");
			t0=scanf(" %ld %s %s %f %f %f", &p->num, p->name, p->sex, &p->score[0], &p->score[1], &p->score[2]);
			if (t0 != 6)
				goto end_7_1;
			Pos(50, i);
			printf("�ѳɹ��޸ģ�");
		}
		else
		{
			Pos(50, i);
			printf("�Ҳ�����ѧ����\n");
		}
		Pos(0, ++i);
		printf("������Ҫ�޸�ѧ����ѧ��:");
		t = scanf_s("%ld", &num);
		if (num == 0)
			goto end_7_10;
		if (t != 1)
			goto end_7_1;
	} while (p==NULL||p->num != 0);
    if (t != 1)
	{
	    end_7_1:while (getchar() != '\n');
		printf("\n\n�����ʽ�������˳���\n");
	}
	if (num == 0)
	{
	    end_7_10:Pos(48, i + 6);
		printf("�޸Ľ��������˳���\n");
	}
	system("pause");
	return 0;
}

int  statistics(void)                                 //8.ͳ�ƹ���
{
	int i = 0, j = 0, t=0;
	float avg_8 = 0;
	struct student* p=NULL;
	p = h;
	Pos(46, 12);
	printf("������ĳ��ƽ���ֵĳɼ�����ͳ��!");
	Pos(52, 14);
	printf("������һ��ƽ����!\n");
	system("pause");
	system("cls");
	printf("���������:");
	t = scanf_s("%f", &avg_8);
	if (t != 1)
		goto end_8;
	printf("\n");
	if (p != NULL)
	{
		printf("ѧ��        ����        �Ա�        ����        ��ѧ        Ӣ��         ƽ����");
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
			printf("�޷��ϵ�ѧ����Ϣ!\n");
		}
		printf("\n\n\n����%d��!\n", j);
	}
	else
	{
		Pos(48, 12);
		printf("��ѧ����Ϣ!\n");
		i = 1;
	}
	if (t != 1)
	{
	end_8:while (getchar() != '\n');
		printf("\n�����ʽ�������˳�!\n");
	}
	system("pause");
	return 0;
}



int write(void)                                       //9.���湦�ܣ�������Ϣ����Ϊ�ļ���
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
		printf("����Ϊ��,���˳���\n");
		return 0;
	}
	if ((fp1 = fopen(address_users, "w")) == NULL)
	{
		Pos(42, 12);
		printf("����ʧ��!���Ƚ��е�ַ������Ժ����ԣ�\n");                          //�ļ���ʧ��
		system("pause");
	}
	else
	{
		if (str1 != NULL)
			fputs("ѧ��      ����      �Ա�      ����      ��ѧ      Ӣ��      ƽ����", fp1);
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
		printf("�ѱ������!\n");
		system("pause");
	}
	return 0;
}



int leave(void)                                       //0.�˳�����
{
	Free();
	Pos(54, 14);
	printf("�˳��ɹ�!");
	Pos(52, 16);
	printf("��ӭ�´�ʹ��!\n");
	B = 1;
	system("pause");
	return 0;
}

int Free(void)                                        //�ͷ��ڴ溯��
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
		printf("(�ͷ��ڴ淢������!)\n");
	}
	else
	{
		Pos(51, 18);
		printf("(�ͷ��ڴ�ɹ�!)\n");
	}
	return 0;
}

int choose(void)                                      //����ѡ�� 
{
	B = 0;
	if (fabs(A-(int)A) < 1e-5)                        //�ж������Ƿ�Ϊ������
	{
		switch ((int)A)
		{
		case 1:create();                    break;    //1.����
		case 2:print();                     break;    //2.���
		case 3:sort();                      break;    //3.����
		case 4:find();                      break;    //4.����
		case 5:insert();                    break;    //5.����
		case 6:delet();                     break;    //6.ɾ��
		case 7:revise();                    break;    //7.�޸�
		case 8:statistics();                break;    //8.ͳ��
		case 9:write();                     break;    //9.����
		case 0:leave();                     break;    //0.�˳�
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





//������*���Ȳ���
//1.0�汾�����2019.08.02           20:41    615��
//1.1�汾�����2019.08.03           20:11    934��
//1.2�汾�����2019.08.04           18:51    1022��
//1.21�޸�BUG�汾�����2019.08.05   18:48    1026��        ���Ҳ���ʱ�쳣�˳�����
//1.22�ȶ��������2019.08.06        13:39    1060��
//1.23�޼��������2019.08.06        18:33    980��
//1.24�޸��������2019.08.06        18:55    984��
//1.25�޸��������2019.08.07        13:54    988��
//1.30�޸��������2019.08.07        19:57    1021��        Υ�����ʱ�쳣�˳�����
//1.40�ȶ��������2019.08.08        16:55    1024��
//1.50�汾�����2019.08.09          21:37    1020��        �ļ����λ������
//1.60�汾�����2019.08.11          12:38    1150��        �ļ�����λ���û����Զ���
//1.61�汾�����2019.08.12          18:35    1155��        ���ٴ����ַλ�õ��ļ��򿪴���
//1.70�汾�����2019.08.14          15:27    1108��        ���ٲ��ֺ�����ʹ�ô���
//1.71�汾�����2019.08.14          19:22    1150��        ����Ĭ�ϵ�ַ����
//1.72�汾�����2019.08.14          20:10    1165��        ���ӵ�ַ����ʱ���˳�
//1.80�汾�����2019.08.17          16:25    1212��        �޸�������������쳣����
//1.90�汾�����2019.08.23          16:38    1230��        �����˳�ʱ�ͷŶ��ڴ�
//1.95�汾�����2019.09.03          23:00    1304��        �����޸Ĺ��ܺͽ�����Ϣ��
//1.96�汾�����2019.09.04          12:56    1305��        �������빦�ܵ�ԭ��������ڴ��ͷ�
//1.97�汾�����2019.09.07          17:17    1371��        �޸����о�����Ϣ