#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMARR 50000
#define TAMARR1 TAMARR-100

void imprimeMenu (){
    printf("+-------------------------------------------------------------+\n");
    printf("|(01) Preencher o array com n�meros aleat�rios                |\n");
    printf("|(02) Ordenar o array pelo m�todo Bubble Sort                 |\n");
    printf("|(03) Ordenar o array pelo m�todo Insertion Sort              |\n");
    printf("|(04) Ordenar o array pelo m�todo Selection Sort              |\n");
    printf("|(05) Ordenar o array pelo m�todo Heap Sort                   |\n");
    printf("|(06) Ordenar o array pelo m�todo Quick Sort                  |\n");
    printf("|(07) Ordenar o array pelo m�todo Merge Sort                  |\n");
    printf("|(08) Ordenar o array pelo m�todo Shell Sort                  |\n");
    printf("|(09) Ordenar o array pelo m�todo ...                         |\n");
    printf("|(10) Ordenar o array pelo m�todo ...                         |\n");
    printf("|(11) Ordenar o array pelo m�todo ...                         |\n");
    printf("|(12) Imprimir resultados dos m�todos de ordena��o executados |\n");
    printf("|(13) Imprimir o array                                        |\n");
    printf("|(00) Encerrar o programa                                     |\n");
    printf("+-------------------------------------------------------------+\n");
}

void preencheArray (int arr[]){
    int i;
    for(i=0; i<TAMARR; i++){
        arr[i] = rand()%200000;
    }
}

void imprimeArray (int arr[]){
    int i;
    for(i=0; i<100; i++){
        printf("%7d", arr[i]);
    }
    printf("    ...");
    for(i=TAMARR1; i<TAMARR; i++){
        printf("%7d", arr[i]);
    }
}

void bubbleSort(int arr[]){
    int i,j,trocaNum;

    for(i=0; i<TAMARR; i++){

        for(j=0; j<TAMARR; j++){

            if(arr[j] > arr[j+1]){

                trocaNum = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = trocaNum;
            }
        }
    }
    printf("\nArray Ordenado\n");
}

void selectionSort(int arr[]){
    int i,j, min;

    for(i=0; i<TAMARR - 1; i++) {
    	min = 0;
    	for(j=i + 1; j<TAMARR; j++) {
    		if (arr[j] < arr[min]){
    			min = j;
			}
		}
		int temp = arr[min];
		arr[min] = arr[i];
		arr[i] = temp;
	}
	printf("\nArray Ordenado\n");
}

int main(){
    setlocale(LC_ALL, "Portuguese");

    imprimeMenu();

    int arr[TAMARR];

    srand(time(NULL));

    preencheArray(arr);
    imprimeArray(arr);

    // Captura o tempo antes da execu��o da fun��o
    clock_t start = clock();

    selectionSort(arr);
	imprimeArray(arr);

    // Captura o tempo ap�s a execu��o da fun��o
    clock_t end = clock();

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calcula o tempo em segundos

    printf("\nTempo de execu��o da ordena��o: %f segundos\n", cpu_time_used);
    printf("\n\n\n");

    return 0;
}
