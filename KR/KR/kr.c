#include <stdio.h>
#include <time.h>


void Menu();  // объявление
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
	int n;  // объявление переменной размера массива
	double *a;  // объявление массива

	printf("\n\n\nВведите размер одномерного массива: ");
	scanf("%i", &n);
	if (n < 2)
	{
		printf("Неверный размер массива!\n");
		FirstTask();
	}
	a = (int *)malloc(n * sizeof(double));

	WriteToArray(a, n);
	PrintArayDouble(a, n);
	KolvoElemKakLast(a, n);
	ZamenOtricNaNullDoMaxElem(a, n);

	free(a);  // освобождение памяти
	Menu();
}

void SecondTask()
{
	int m, n;  // объявление размера массива
	int **aa;  // объявление массива

	printf("\n\n\nВведите размер двумерного массива (через пробел): ");
	scanf("%i%i", &m, &n);
	if (m < 2 || n < 2)
	{
		printf("Неверный размер массива!\n");
		SecondTask();
	}

	/* Выделение памяти под указатели на строки */
	aa = (int **)malloc(m * sizeof(int *));
	for (int i = 0; i < m; i++)
	{
		/* Выделение памяти под хранение строк */
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
	int *aaa;  // объявление массива
	aaa = (int *)malloc(20 * sizeof(int));  // выделение памяти под указатели на строки

	GetRandomInt(aaa, 20);
	PrintArayInt(aaa, 20);
	NomerMinVPervIVoVtoroyPolovineMassiva(aaa);

	free(aaa);
	Menu();
}

void FourthTask()
{
	int *aaaa;  // объявление массива

	/* Выделение памяти под указатели на строки */
	aaaa = (int **)malloc(6 * sizeof(int *));
	for (int i = 0; i < 6; i++)
	{
		/* Выделение памяти под хранение строк */
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
	printf("\nЗполним массив вещественными значениями:\n1 - автоматически\n2 - вручную\n");
	int vibor = getche();  // чтение с клавиатуры
	switch (vibor)
	{
	case '1':
		printf("\n");
		GetRandomDouble(a, n);
		break;
	case '2':
		printf("\n\nВводите значения\n");
		for (int i = 0; i < n; i++)  // в цикле заполняется массив
		{
			scanf("%lf", &a[i]);  // &a[i] - адрес i-го элемента массива
		}
		break;
	default:
		printf("\nПопробуйте ещё раз.\n");
		WriteToArray(a, n);
	}
}

void WriteToArray2D(int **aa, int m, int n)
{
	printf("\nЗполним массив вещественными значениями:\n1 - автоматически\n2 - вручную\n");
	int vibor = getche();  // чтение с клавиатуры
	switch (vibor)
	{
	case '1':
		printf("\n");
		GetRandomInt2D(aa, m, n);
		break;
	case '2':
		printf("\n\nВводите значения\n");
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				scanf("%i", &aa[i][j]);
			printf("\n");
		}
		break;
	default:
		printf("\nПопробуйте ещё раз.\n");
		WriteToArray2D(aa, m, n);
	}
}

void GetRandomDouble(double *a, int n)  // заполнение массива случайными вещественными элементами
{
	for (int i = 0; i < n; i++)  // в цикле заполняется массив
		a[i] = (rand() % 200 - 100) + ((float)(rand() % 100) * 0.01);  // заполнение ячеек вещественными/действительными значениями в диапазоне (-100; 100)
}

void GetRandomInt2D(int **aa, int m, int n)  // заполнение массива случайными целыми элементами
{
	for (int i = 0; i < m; i++)  // в цикле заполняется массив
	{
		for (int j = 0; j < n; j++)
			aa[i][j] = rand() % 20 - 10;  // автоматический "ввод" элеметов, диапазон (-5; 5)// заполнение ячеек целочисенными значениями в диапазоне (-10; 10)
	}
}

void GetRandomInt(int *aaa, int n)  // заполнение массива случайными целыми элементами
{
	for (int i = 0; i < n; i++)
		aaa[i] = rand() % 35 - 15;  // заполнение ячеек целочисенными значениями в диапазоне (-15; 20)
}

void PrintArayDouble(double *a, int n)  // вывод массива
{
	printf("\nМассив:\n");
	for (int i = 0; i < n; i++)
		printf("%.2f ", a[i]);
}

void PrintArayInt2D(int **aa, int m, int n)  // вывод массива
{
	printf("\nМассив:\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%i     ", aa[i][j]);
		printf("\n");
	}
}

void PrintArayInt(int *aaa, int n)
{
	printf("\n\n\nМассив:\n");
	for (int i = 0; i < n; i++)
		printf("%i ", aaa[i]);
}

void KolvoElemKakLast(double *a, int n)
{
	double last = a[n - 1];  // значение последнего элемента массива
	int counter = 0;  // считаем количество элементов массива, совпадающих по значению с последним элементом

	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == last)
		{
			counter++;
		}
	}

	printf("\n\nКоличество элементов массива, совпадающих по значению с последним элементом: %i", counter);
}

void ZamenOtricNaNullDoMaxElem(double *a, int n)
{
	int max = a[0];  // объявление переменной, хранящей максимальный элемент
	int max_i = 0;  // объявление переменной, хранящей индекс максимального элемента

	for (int i = 1; i < n; i++)  // поиск максимального элемента
	{
		if (a[i] > max)
		{
			max = a[i];
			max_i = i;
		}
	}

	for (int i = 0; i < max_i; i++)  // замена на 0 отрицательных элементов до максимального
	{
		if (a[i] < 0)
		{
			a[i] = 0;
		}
	}

	printf("\n\nЗаменили на 0 отрицательные элементы массива, расположенные до максимального элемента:");
	PrintArayDouble(a, n);
}

void NomerPervStrokiSPolojitElem(int **aa, int m, int n)
{
	int number;  // объявление переменной, хранящей номер первой из строк, содержащей хотя бы один положительный элемент
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (aa[i][j] > 0)
			{
				number = i;
				i = m;  // чтобы выйти из внешнего цикла
				break;
			}
		}
	}
	printf("\nНомер первой строки, содержащей хотя бы один положительный элемент: %i", number);
}

void SrednArifmKotorieBolsheZadannoyVelichini(int **aa, int m, int n)
{
	int trigger;  // объявление переменной, хранящей введённое для сравнения значение
	int counter = 0;  // объявление переменной, хранящей количество элементов для подсчёта среднего арифметического
	double value = 0;  // объявление переменной, хранящей сумму элементов для подсчёта среднего арифметического

	printf("\n\nЗадайте целое число из диапазона представленных в массиве: ");
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
	printf("\nСреднее арифметическое элементов, значение которых больше заданной величины: %.2lf", value);
}

void NomerMinVPervIVoVtoroyPolovineMassiva(int *aaa)
{
	int minFirstHalf_i, minSecondHalf_i;  // индексы минимальных элементов в первой и второй половинах массива
	int minFirstHalf, minSecondHalf;  // значения минимальных элементов в первой и второй половинах массива

	minFirstHalf_i = 0;
	minFirstHalf = aaa[0];
	printf("\n\nПервая половина массива:\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%i ", aaa[i]);
		if (aaa[i] < minFirstHalf)
		{
			minFirstHalf_i = i;
			minFirstHalf = aaa[i];
		}
	}
	printf("\nИндекс минимального элемента: %i, минимальный элемент: %i\n", minFirstHalf_i, minFirstHalf);

	minSecondHalf_i = 10;
	minSecondHalf = aaa[10];
	printf("\nВторая половина массива:\n");
	for (int i = 10; i < 20; i++)
	{
		printf("%i ", aaa[i]);
		if (aaa[i] < minSecondHalf)
		{
			minSecondHalf_i = i;
			minSecondHalf = aaa[i];
		}
	}
	printf("\nИндекс минимального элемента: %i, минимальный элемент: %i", minSecondHalf_i, minSecondHalf);
}

void PomenyatMestamiDveStroki(int **aaaa, int m, int n)
{
	int *cache_first, *cache_second;  // объявление массива для хранения строки
	int first, second;  // объявление переменных для хранения номеров строк массива

	cache_first = (int**)malloc(n * sizeof(int*));  // выделение памяти под указатели на строки
	cache_second = (int**)malloc(n * sizeof(int*));  // выделение памяти под указатели на строки

	printf("\n\nВведите номера 2-х строк, элементы которых нужно поменять местами (через пробел): ");
	scanf("%i%i", &first, &second);

	for (int i = 0; i < n; i++)  // сохраняем первую из заданных строк во временный массив
	{
		cache_first[i] = aaaa[first][i];
	}

	for (int i = 0; i < n; i++)  // сохраняем вторую из заданных строк во временный массив
	{
		cache_second[i] = aaaa[second][i];
	}

	for (int i = 0; i < n; i++)  // заменяем первую строку в главном массиве
	{
		aaaa[first][i] = cache_second[i];
	}

	for (int i = 0; i < n; i++)  // заменяем вторую строку в главном массиве
	{
		aaaa[second][i] = cache_first[i];
	}

	free(cache_first);
	free(cache_second);
}

void PreobrazovannayaStroka()
{
	char str[] = "чotНПВ! б#aWK8-щ$ЙLy2ъ ( Udg6L { ЛаqE0д 87кЖЯQ";  // строка для преобразования
	int n = sizeof(str) / sizeof(char);  // узнаём длину массива
	int i, j, kol = 0, sum = 0;

	printf("\n\n%s", str);

	for (i = 0; i < n; i++)
	{
		if ((str[i] >= 48) & (str[i] <= 57))  // элементы идентифицируем по соответствующему индексу в ASCII таблице
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
	printf("\n\n\n\nСделайте свой выбор:\nПервое    задание, нажмите 1\nВторое    задание, нажмите 2\nТретье    задание, нажмите 3\nЧетвёртое задание, нажмите 4\nПятое     задание, нажмите 5\n\nВыйти, нажмите 0\n");

	int vibor = getche();  // чтение с клавиатуры
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
		printf("\nПопробуйте ещё раз.\n");
		Menu();
	}
}

int main(void)
{
	setlocale(0, "");  // подключение русского языка
	srand(time(NULL));

	printf("Контрольная работа, вариант №30");
	Menu();
}