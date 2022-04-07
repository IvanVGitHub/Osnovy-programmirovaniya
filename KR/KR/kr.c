#include <stdio.h>
#include <time.h>


void Menu();  // ����������
void FirstTask();
void SecondTask();
void ThirdTask();
void FourthTask();
void FifthTask();
void WriteToArray();
void WriteToArray2D();
void GetRandomDouble();
void GetRandomInt2D();
void GetRandomInt();
void PrintArayDouble();
void PrintArayInt2D();
void PrintArayInt();
void KolvoElemKakLast();
void ZamenOtricNaNullDoMaxElem();
void NomerPervStrokiSPolojitElem();
void SrednArifmKotorieBolsheZadannoyVelichini();
void NomerMinVPervIVoVtoroyPolovineMassiva();
void PomenyatMestamiDveStroki();
void PreobrazovannayaStroka();

void FirstTask()
{
	int n;  // ���������� ���������� ������� �������
	double *a;  // ���������� �������

	printf("\n\n\n������� ������ ����������� �������: ");
	scanf("%i", &n);
	if (n < 2)
	{
		printf("�������� ������ �������!\n");
		FirstTask();
	}
	a = (int *)malloc(n * sizeof(double));

	WriteToArray(a, n);
	PrintArayDouble(a, n);
	KolvoElemKakLast(a, n);
	ZamenOtricNaNullDoMaxElem(a, n);

	free(a);  // ������������ ������
	Menu();
}

void SecondTask()
{
	int m, n;  // ���������� ������� �������
	int **aa;  // ���������� �������

	printf("\n\n\n������� ������ ���������� ������� (����� ������): ");
	scanf("%i%i", &m, &n);
	if (m < 2 || n < 2)
	{
		printf("�������� ������ �������!\n");
		SecondTask();
	}

	/* ��������� ������ ��� ��������� �� ������ */
	aa = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
	{
		/* ��������� ������ ��� �������� ����� */
		aa[i] = (int *)malloc(n * sizeof(int));
	}

	WriteToArray2D(aa, m, n);
	PrintArayInt2D(aa, m, n);
	NomerPervStrokiSPolojitElem(aa, m, n);
	SrednArifmKotorieBolsheZadannoyVelichini(aa, m, n);

	free(aa);
	Menu();
}

void ThirdTask()
{
	int *aaa;  // ���������� �������
	aaa = (int *)malloc(20 * sizeof(int));  // ��������� ������ ��� ��������� �� ������

	GetRandomInt(aaa, 20);
	PrintArayInt(aaa, 20);
	NomerMinVPervIVoVtoroyPolovineMassiva(aaa);

	free(aaa);
	Menu();
}

void FourthTask()
{
	int *aaaa;  // ���������� �������

	/* ��������� ������ ��� ��������� �� ������ */
	aaaa = (int **)malloc(6 * sizeof(int *));
	for (int i = 0; i < 6; i++)
	{
		/* ��������� ������ ��� �������� ����� */
		aaaa[i] = (int *)malloc(5 * sizeof(int));
	}

	printf("\n\n");
	WriteToArray2D(aaaa, 6, 5);
	PrintArayInt2D(aaaa, 6, 5);
	PomenyatMestamiDveStroki(aaaa, 6, 5);
	PrintArayInt2D(aaaa, 6, 5);

	free(aaaa);
	Menu();
}

void FifthTask()
{
	PreobrazovannayaStroka();

	Menu();
}

void WriteToArray(double *a, int n)
{
	printf("\n������� ������ ������������� ����������:\n1 - �������������\n2 - �������\n");
	int vibor = getche();  // ������ � ����������
	switch (vibor)
	{
	case '1':
		printf("\n");
		GetRandomDouble(a, n);
		break;
	case '2':
		printf("\n\n������� ��������\n");
		for (int i = 0; i < n; i++)  // � ����� ����������� ������
		{
			scanf("%lf", &a[i]);  // &a[i] - ����� i-�� �������� �������
		}
		break;
	default:
		printf("\n���������� ��� ���.\n");
		WriteToArray(a, n);
	}
}

void WriteToArray2D(int **aa, int m, int n)
{
	printf("\n������� ������ ������������� ����������:\n1 - �������������\n2 - �������\n");
	int vibor = getche();  // ������ � ����������
	switch (vibor)
	{
	case '1':
		printf("\n");
		GetRandomInt2D(aa, m, n);
		break;
	case '2':
		printf("\n\n������� ��������\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%i", &aa[i][j]);
			printf("\n");
		}
		break;
	default:
		printf("\n���������� ��� ���.\n");
		WriteToArray2D(aa, m, n);
	}
}

void GetRandomDouble(double *a, int n)  // ���������� ������� ���������� ������������� ����������
{
	for (int i = 0; i < n; i++)  // � ����� ����������� ������
		a[i] = (rand() % 200 - 100) + ((float)(rand() % 100) * 0.01);  // ���������� ����� �������������/��������������� ���������� � ��������� (-100; 100)
}

void GetRandomInt2D(int **aa, int m, int n)  // ���������� ������� ���������� ������ ����������
{
	for (int i = 0; i < m; i++)  // � ����� ����������� ������
	{
		for (int j = 0; j < n; j++)
			aa[i][j] = rand() % 20 - 10;  // �������������� "����" ��������, �������� (-5; 5)// ���������� ����� ������������� ���������� � ��������� (-10; 10)
	}
}

void GetRandomInt(int *aaa, int n)  // ���������� ������� ���������� ������ ����������
{
	for (int i = 0; i < n; i++)
		aaa[i] = rand() % 35 - 15;  // ���������� ����� ������������� ���������� � ��������� (-15; 20)
}

void PrintArayDouble(double *a, int n)  // ����� �������
{
	printf("\n������:\n");
	for (int i = 0; i < n; i++)
		printf("%.2f ", a[i]);
}

void PrintArayInt2D(int **aa, int m, int n)  // ����� �������
{
	printf("\n������:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%i     ", aa[i][j]);
		printf("\n");
	}
}

void PrintArayInt(int *aaa, int n)
{
	printf("\n\n\n������:\n");
	for (int i = 0; i < n; i++)
		printf("%i ", aaa[i]);
}

void KolvoElemKakLast(double *a, int n)
{
	double last = a[n - 1];  // �������� ���������� �������� �������
	int counter = 0;  // ������� ���������� ��������� �������, ����������� �� �������� � ��������� ���������

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == last)
		{
			counter++;
		}
	}

	printf("\n\n���������� ��������� �������, ����������� �� �������� � ��������� ���������: %i", counter);
}

void ZamenOtricNaNullDoMaxElem(double *a, int n)
{
	int max = a[0];  // ���������� ����������, �������� ������������ �������
	int max_i = 0;  // ���������� ����������, �������� ������ ������������� ��������

	for (int i = 1; i < n; i++)  // ����� ������������� ��������
	{
		if (a[i] > max)
		{
			max = a[i];
			max_i = i;
		}
	}

	for (int i = 0; i < max_i; i++)  // ������ �� 0 ������������� ��������� �� �������������
	{
		if (a[i] < 0)
		{
			a[i] = 0;
		}
	}

	printf("\n\n�������� �� 0 ������������� �������� �������, ������������� �� ������������� ��������:");
	PrintArayDouble(a, n);
}

void NomerPervStrokiSPolojitElem(int **aa, int m, int n)
{
	int number;  // ���������� ����������, �������� ����� ������ �� �����, ���������� ���� �� ���� ������������� �������
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (aa[i][j] > 0)
			{
				number = i;
				i = m;  // ����� ����� �� �������� �����
				break;
			}
		}
	}
	printf("\n����� ������ ������, ���������� ���� �� ���� ������������� �������: %i", number);
}

void SrednArifmKotorieBolsheZadannoyVelichini(int **aa, int m, int n)
{
	int trigger;  // ���������� ����������, �������� �������� ��� ��������� ��������
	int counter = 0;  // ���������� ����������, �������� ���������� ��������� ��� �������� �������� ���������������
	double value = 0;  // ���������� ����������, �������� ����� ��������� ��� �������� �������� ���������������

	printf("\n\n������� ����� ����� �� ��������� �������������� � �������: ");
	scanf("%i", &trigger);

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (aa[i][j] > trigger)
			{
				value += aa[i][j];
				counter++;
			}
		}
	}

	value /= counter;
	printf("\n������� �������������� ���������, �������� ������� ������ �������� ��������: %.2lf", value);
}

void NomerMinVPervIVoVtoroyPolovineMassiva(int *aaa)
{
	int minFirstHalf_i, minSecondHalf_i;  // ������� ����������� ��������� � ������ � ������ ��������� �������
	int minFirstHalf, minSecondHalf;  // �������� ����������� ��������� � ������ � ������ ��������� �������

	minFirstHalf_i = 0;
	minFirstHalf = aaa[0];
	printf("\n\n������ �������� �������:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%i ", aaa[i]);
		if (aaa[i] < minFirstHalf)
		{
			minFirstHalf_i = i;
			minFirstHalf = aaa[i];
		}
	}
	printf("\n������ ������������ ��������: %i, ����������� �������: %i\n", minFirstHalf_i, minFirstHalf);

	minSecondHalf_i = 10;
	minSecondHalf = aaa[10];
	printf("\n������ �������� �������:\n");
	for (int i = 10; i < 20; i++)
	{
		printf("%i ", aaa[i]);
		if (aaa[i] < minSecondHalf)
		{
			minSecondHalf_i = i;
			minSecondHalf = aaa[i];
		}
	}
	printf("\n������ ������������ ��������: %i, ����������� �������: %i", minSecondHalf_i, minSecondHalf);
}

void PomenyatMestamiDveStroki(int **aaaa, int m, int n)
{
	int *cache_first, *cache_second;  // ���������� ������� ��� �������� ������
	int first, second;  // ���������� ���������� ��� �������� ������� ����� �������

	cache_first = (int**)malloc(n * sizeof(int*));  // ��������� ������ ��� ��������� �� ������
	cache_second = (int**)malloc(n * sizeof(int*));  // ��������� ������ ��� ��������� �� ������

	printf("\n\n������� ������ 2-� �����, �������� ������� ����� �������� ������� (����� ������): ");
	scanf("%i%i", &first, &second);

	for (int i = 0; i < n; i++)  // ��������� ������ �� �������� ����� �� ��������� ������
	{
		cache_first[i] = aaaa[first][i];
	}

	for (int i = 0; i < n; i++)  // ��������� ������ �� �������� ����� �� ��������� ������
	{
		cache_second[i] = aaaa[second][i];
	}

	for (int i = 0; i < n; i++)  // �������� ������ ������ � ������� �������
	{
		aaaa[first][i] = cache_second[i];
	}

	for (int i = 0; i < n; i++)  // �������� ������ ������ � ������� �������
	{
		aaaa[second][i] = cache_first[i];
	}

	free(cache_first);
	free(cache_second);
}

void PreobrazovannayaStroka()
{
	char str[] = "�ot���! �#aWK8-�$�Ly2� ( Udg6L { ��qE0� 87���Q";  // ������ ��� ��������������
	int n = sizeof(str) / sizeof(char);  // ����� ����� �������
	int i, j, kol = 0, sum = 0;

	printf("\n\n%s", str);

	for (i = 0; i < n; i++)
	{
		if ((str[i] >= 48) & (str[i] <= 57))  // �������� �������������� �� ���������������� ������� � ASCII �������
		{
			kol++;
			sum += str[i];

			for (j = i; j < n - 1; j++)
				str[j] = str[j + 1];

			n--;
			i--;
		}
		else if ((str[i] >= 65) & (str[i] <= 90))
			str[i] = str[i] + 32;
	}

	str[i] = '\0';
	printf("\n%s\n%d\n%d\n", str, kol, sum);
}

void Menu()
{
	printf("\n\n\n\n�������� ���� �����:\n������    �������, ������� 1\n������    �������, ������� 2\n������    �������, ������� 3\n�������� �������, ������� 4\n�����     �������, ������� 5\n\n�����, ������� 0\n");

	int vibor = getche();  // ������ � ����������
	switch (vibor)
	{
	case '1':
		FirstTask();
		break;
	case '2':
		SecondTask();
		break;
	case '3':
		ThirdTask();
		break;
	case '4':
		FourthTask();
		break;
	case '5':
		FifthTask();
		break;
	case '0':
		return 0;
		break;
	default:
		printf("\n���������� ��� ���.\n");
		Menu();
	}
}

int main(void)
{
	setlocale(0, "");  // ����������� �������� �����
	srand(time(NULL));

	printf("����������� ������, ������� �30");
	Menu();
}