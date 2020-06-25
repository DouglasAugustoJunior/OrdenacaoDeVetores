#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void header()
{ // Cabecalho
	printf("|------------------------------------------------------------------------|\n");
	printf("|                   ESTRUTURA DE DADOS - ORDENACAO DE VETORES            |\n");
	printf("|------------------------------------------------------------------------|\n");
	printf("| SOFTWARE COM A FINALIDADE DE ORDENACAO E ANALISE DE VETORES UTILIZANDO |\n");
	printf("|         METODOS E TECNICAS DE ORDENACAO RECURSIVAS E NAO RECURSIVAS    |\n");
	printf("|                                                                        |\n");
	printf("|                         Douglas Augusto Junior                         |\n");
	printf("|------------------------------------------------------------------------|\n");
	printf("|                                          by Team Brave Wolf Developers |\n");
	printf("|------------------------------------------------------------------------|\n");
}

void splash()
{ // Splash Screen
	int i, j, cont = 0;
	char frases[9][20] = {"Aguarde...", "Insercao Direta...", "Bubble Sort...", "Selecao Direta...", "Shake Sort..", "Quick Sort...", "Merge Sort...", "Heap Sort...", "Contadores..."};
	system("color 03"); // padrao de cores do terminal

	for (i = 0; i <= 79; i++)
	{
		system("cls"); // limpa tela
		header();
		printf("\n\nCarregando: %s \n\n", frases[cont]);
		printf("  %d%%\r", i);
		fflush(stdout);
		if (i % 12 == 0)
		{
			cont++;
		}
		for (j = 0; j < i; j++)
		{
			if (!j)
			{ // Da espaco na barra pra nao enconstar na borda da tela
				printf("  ");
			}
			printf("%c", 219); // desenha barra
			Sleep(1);		   // velocidade da barra
		}
	}
	system("cls"); // limpa tela
}

int tamanho()
{ // pega tamanho do vetor
	long long int tamanho = 0;
	int opcao;
	printf("\n| Informe o tamanho do vetor:\n");
	printf("| 10^1  -> (1)\n");
	printf("| 10^2  -> (2)\n");
	printf("| 10^4  -> (3)\n");
	printf("| 10^6  -> (4)\n");
	printf("| 10^8  -> (5)\n");
	printf("| 10^9  -> (6)\n");
	printf("| 10^10 -> (7)\n");
	printf("| Opcao: ");
	scanf("%d", &opcao);
	switch (opcao)
	{
	case 1:
		tamanho = 10;
		break;
	case 2:
		tamanho = 100;
		break;

	case 3:
		tamanho = 10000;
		break;

	case 4:
		tamanho = 1000000;
		break;

	case 5:
		tamanho = 100000000;
		break;

	case 6:
		tamanho = 1000000000;
		break;

	case 7:
		tamanho = 10000000000;
		break;

	default:
		printf("Digita uma opcao valida!");
	}
	return tamanho;
}

// Insercao Direta
void insercaoDireta(long long int tam, int vetor[])
{
	int aux, i, j, ciclos = 0;
	for (i = 1; i < tam; i++)
	{
		aux = vetor[i];
		j = i - 1;
		while ((j >= 0) && (aux < vetor[j]))
		{
			vetor[j + 1] = vetor[j]; // deslocando
			j--;					 // decrementando
		}
		vetor[j + 1] = aux; // inserindo
		ciclos++;
	}
	printf("Vetor organizado Insercao: ");
	for (i = 0; i < tam; i++)
	{ // exibe vetor
		printf(" %d,", vetor[i]);
	}
	printf("\nCiclos: %d", ciclos);
}

// Selecao direta
void selecaoDireta(long long int tam, int vetor[])
{
	int menor, posmenor, i, j, ciclos = 0;
	for (i = 0; i < tam; i++)
	{
		menor = vetor[i];
		posmenor = i;
		for (j = i + 1; j < tam; j++)
			if (vetor[j] < menor)
			{
				menor = vetor[j];
				posmenor = j;
			}
		vetor[posmenor] = vetor[i];
		vetor[i] = menor;
		ciclos++;
	}
	printf("Vetor organizado Selecao: ");
	for (i = 0; i < tam; i++)
	{ // exibe vetor
		printf(" %d,", vetor[i]);
	}
	printf("\nCiclos: %d", ciclos);
}

// Shake Sort
void shakeSort(long long int tam, int vetor[])
{
	int j, k, l, r, aux, i, ciclos = 0;
	l = 1;
	r = k = tam - 1;
	do
	{
		for (j = r; j >= l; j--)
			if (vetor[j - 1] > vetor[j])
			{
				aux = vetor[j - 1];
				vetor[j - 1] = vetor[j];
				vetor[j] = aux;
				k = j;
			}
		l = k + 1;
		for (j = l; j <= r; j++)
			if (vetor[j - 1] > vetor[j])
			{
				aux = vetor[j - 1];
				vetor[j - 1] = vetor[j];
				vetor[j] = aux;
				k = j;
			}
		r = k - 1;
		ciclos++;
	} while (l <= r);
	printf("Vetor organizado Shake: ");
	for (i = 0; i < tam; i++)
	{ // exibe vetor
		printf(" %d,", vetor[i]);
	}
	printf("\nCiclos: %d", ciclos);
}

// Bubble Sort - Bolha
void bubbleSort(long long int tam, int vetor[])
{
	int aux, troca, j, i, ciclos = 0;
	j = tam - 1;
	do
	{
		troca = 0;
		for (i = 0; i < j; i++)
		{
			if (vetor[i] > vetor[i + 1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
				troca = 1;
			}
		}
		ciclos++;
		j--;
	} while (troca);
	printf("Vetor organizado Bolha: ");
	for (i = 0; i < tam; i++)
	{ // exibe vetor
		printf(" %d,", vetor[i]);
	}
	printf("\nCiclos: %d", ciclos);
}

// Particao Quick Sort
int particao(int esq, int dir, int vetor[], long long int tam)
{
	int pivor, i, j; // v = pivor, i e j contadores
	pivor = vetor[dir];
	i = esq - 1;
	j = dir;
	do
	{
		do
		{
			i = i + 1; // esquerda
		} while ((vetor[i] < pivor) && (i < dir));

		do
		{
			j = j - 1; // direita
		} while ((vetor[j] > pivor) && (j > 0));

		tam = vetor[i];
		vetor[i] = vetor[j];
		vetor[j] = tam;
	} while (j > i);

	// colocando o pivo a[d] em seu lugar

	vetor[j] = vetor[i];
	vetor[i] = vetor[dir];
	vetor[dir] = tam;
	return (i);
}
// Quick Sort
void quickSort(int esq, int dir, int vetor[], long long int tam)
{
	int i;
	if (dir > esq)
	{
		i = particao(esq, dir, vetor, tam); //Chama m�todo externo
		quickSort(esq, i - 1, vetor, tam);
		quickSort(i + 1, dir, vetor, tam);
	}
}

// Intercala Merge Sort
void intercala(int esq, int meio, int dir, int vetor[])
{
	int i = 0, j, k, *w;
	w = (int *)malloc(sizeof(int));
	i = esq;
	j = meio;
	k = 0;
	while (i < meio && j < dir)
	{
		if (vetor[i] < vetor[j])
		{
			w[k++] = vetor[i++];
		}
		else
		{
			w[k++] = vetor[j++];
		}
		while (i < meio)
		{
			w[k++] = vetor[i++];
		}
		while (j < dir)
		{
			w[k++] = vetor[j++];
		}
		for (i = esq; i < dir; ++i)
		{
			//vetor[i] = w[i = esq];
		}
		free(w);
	}
}
// Merge Sort
void mergeSort(int esq, int dir, int vetor[])
{
	int meio;
	if (esq < dir - 1)
	{
		meio = (esq + dir) / 2;
		mergeSort(esq, meio, vetor);
		mergeSort(meio, dir, vetor);
		intercala(esq, meio, dir, vetor);
	}
}

// HeapSort
void heapSort(int vetor[])
{
	// implementar
}

int main(int argc, char *argv[])
{ // metodo Principal
	int opcao, i;
	long long int tam;
	srand(time(NULL));
	splash();
	header();
	tam = tamanho();
	int vetor[tam], vet1[tam], vet2[tam], vet3[tam], vet4[tam], vet5[tam], vet6[tam], vet7[tam + 1]; // declara vetores

	for (i = 0; i < tam; i++)
	{ // gera vetor aleatorio
		vetor[i] = rand() % tam;
	}
	printf("| Seu vetor: ");
	for (i = 0; i < tam; i++)
	{ // exibe vetor aleatorio
		printf(" %d,", vetor[i]);
	}
	for (i = 0; i < tam; i++)
	{ // preenche vetores
		vet1[i] = vetor[i];
		vet2[i] = vetor[i];
		vet3[i] = vetor[i];
		vet4[i] = vetor[i];
		vet5[i] = vetor[i];
		vet6[i] = vetor[i];
		vet7[i + 1] = vetor[i];
	}
	do
	{ // realiza a ordenacao com algum metodo
		opcao = 1;
		printf("\n|------------------------------------------------------------------------|\n");
		printf("| Qual metodo de ordenacao desejar utilizar ?\n");
		printf("| Insercao Direta  (1)\n");
		printf("| Bubble Sort      (2)\n");
		printf("| Selecao Direta   (3)\n");
		printf("| Shake Sort       (4)\n");
		printf("| Quick Sort       (5)\n");
		printf("| Merge Sort       (6)\n");
		printf("| Opcao: ");
		scanf("%d", &opcao);
		switch (opcao)
		{
		case 1:
			//Insercao Direta
			insercaoDireta(tam, vet1);
			break;

		case 2:
			//Bubble Sort
			bubbleSort(tam, vet2);
			break;

		case 3:
			//Selecao Direta
			selecaoDireta(tam, vet3);
			break;

		case 4:
			//Shake Sort
			shakeSort(tam, vet4);
			break;

		case 5:
			//Quick Sort
			quickSort(0, tam - 1, vet5, tam);
			printf("| Seu vetor Quick: ");
			for (i = 0; i < tam; i++)
			{ // exibe vetor
				printf(" %d,", vet5[i]);
			}
			break;

		case 6:
			//Merge Sort
			mergeSort(tam / 2, tam / 2, vet6);
			printf("| Seu vetor Merge: ");
			for (i = 0; i < tam; i++)
			{ // exibe vetor
				printf(" %d,", vet6[i]);
			}
			break;

		default:
			printf("Digita uma opcao valida!");
		}
		printf("\n|------------------------------------------------------------------------|\n");
		printf("| Deseja realizar mais alguma operacao ?\n");
		printf("| Sim    (1)\n");
		printf("| Nao    (2)\n");
		printf("| Opcao: ");
		scanf("%d", &opcao);
	} while (opcao == 1);
	return 0;
}
