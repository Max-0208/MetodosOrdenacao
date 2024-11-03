#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMARR 50000
#define TAMARR1 TAMARR-200

void imprimirMenu(){
    printf("+-------------------------------------------------------------+\n");
    printf("|(1) Preencher o array com números aleatórios                 |\n");
    printf("|(2) Ordenar o array pelo método Bubble Sort                  |\n");
    printf("|(3) Ordenar o array pelo método Selection Sort               |\n");
    printf("|(4) Ordenar o array pelo método Insertion Sort               |\n");
    printf("|(5) Ordenar o array pelo método Heap Sort                    |\n");
    printf("|(6) Ordenar o array pelo método Quick Sort                   |\n");
    printf("|(7) Ordenar o array pelo método Merge Sort                   |\n");
    printf("|(8) Ordenar o array pelo método Shell Sort                   |\n");
    printf("|(9) Ordenar o array pelo método Bucket Sort                  |\n");
    printf("|(10) Ordenar o array pelo método Counting Sort               |\n");
    printf("|(11) Ordenar o array pelo método Radix Sort                  |\n");
    printf("|(12) Imprimir resultados dos métodos de ordenação executados |\n");
    printf("|(13) Imprimir o array                                        |\n");
    printf("|(0) Encerrar o programa                                      |\n");
    printf("+-------------------------------------------------------------+\n");
    printf("Digite sua opção: ");
}

void preencherArray(int arr[]){
    int i;
    for(i=0; i<TAMARR; i++){
        arr[i] = rand()%200000;
    }
}

void imprimirArray(int arr[]){
    int i;
    for(i=0; i<200; i++){
        printf("%7d", arr[i]);
    }
    printf("    ...");
    for(i=TAMARR1; i<TAMARR; i++){
        printf("%7d", arr[i]);
    }
}

double mostrarResultado(int arr[], double (*funcao)(int)){
    double sortTime;

    imprimirArray(arr);
    sortTime = funcao(arr);
    printf("\n\n");
    imprimirArray(arr);
    printf("\n\nTempo de execução da ordenação: %.3f segundos\n\n", sortTime);
    sleep(10);
    system("cls");
    return sortTime;
}

double bubbleSort(int arr[]){
    int i,j,trocaNum;
    double sortTime;
    clock_t start = clock();

    for(i=0; i<TAMARR; i++){

        for(j=0; j<TAMARR; j++){

            if(arr[j] > arr[j+1]){

                trocaNum = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = trocaNum;
            }
        }
    }

    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    sortTime = cpu_time_used;
    return sortTime;
}

double selectionSort(int arr[]){
    int i,j, min;
    double sortTime;
    clock_t start = clock();

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
	clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    sortTime = cpu_time_used;
    return sortTime;
}

double insertionSort(int arr[]){
	int i, j, aux;
	double sortTime;
	clock_t start = clock();
	
	for(i=0; i<TAMARR - 1; i++){
		if(arr[i] > arr[i+1]){
			aux = arr[i+1];
			arr[i+1] = arr[i]; arr[i] = aux;
			j = i -1;
			while(j >= 0){
				if(aux < arr[j]){
					arr[j+1] = arr[j]; arr[j] = aux;
				}else{
					break;
				}
				j= j-1;
			}
		} 
	}
	clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    sortTime = cpu_time_used;
    return sortTime;
}

double heapSort(int arr[]) {
    double sortTime;
    clock_t start = clock();
    
    int n = TAMARR;
    int i, j, pai, filho, t;
    
    for (i = 1; i < n; i++) {
        filho = i;
        while (filho > 0) {
            pai = (filho - 1) / 2;
            if (arr[pai] < arr[filho]) {
                t = arr[pai];
                arr[pai] = arr[filho];
                arr[filho] = t;
                filho = pai;
            }
            else break;
        }
    }
    
    for (i = n-1; i > 0; i--) {
        t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        pai = 0;
        filho = 1;
        
        while (filho < i) {
            if (filho + 1 < i && arr[filho + 1] > arr[filho])
                filho++;
            if (arr[filho] > arr[pai]) {
                t = arr[pai];
                arr[pai] = arr[filho];
                arr[filho] = t;
                pai = filho;
                filho = 2 * pai + 1;
            }
            else break;
        }
    }
    
    clock_t end = clock();
    sortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    return sortTime;
}

double quickSort(int arr[]) {
    double sortTime;
    clock_t start = clock();
    
    int pilha[TAMARR];
    int topo = -1;
    int inicio = 0;
    int fim = TAMARR - 1;
    int i, j, temp, pivo, pi;
    
    pilha[++topo] = inicio;
    pilha[++topo] = fim;
    
    while (topo >= 0) {
        fim = pilha[topo--];
        inicio = pilha[topo--];
        
        pivo = arr[fim];
        i = (inicio - 1);
        
        for (j = inicio; j <= fim - 1; j++) {
            if (arr[j] <= pivo) {
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        temp = arr[i + 1];
        arr[i + 1] = arr[fim];
        arr[fim] = temp;
        pi = i + 1;
        
        if (pi - 1 > inicio) {
            pilha[++topo] = inicio;
            pilha[++topo] = pi - 1;
        }
        
        if (pi + 1 < fim) {
            pilha[++topo] = pi + 1;
            pilha[++topo] = fim;
        }
    }
    
    clock_t end = clock();
    sortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    return sortTime;
}

double mergeSort(int arr[]) {
    double sortTime;
    clock_t start = clock();
    
    int* temp = (int*)malloc(TAMARR * sizeof(int));
    int tam_bloco, inicio1, inicio2, fim1, fim2;
    int i, j, k;
    
    for (tam_bloco = 1; tam_bloco < TAMARR; tam_bloco *= 2) {
        for (inicio1 = 0; inicio1 < TAMARR - tam_bloco; inicio1 += 2 * tam_bloco) {
            inicio2 = inicio1 + tam_bloco;
            fim1 = inicio2 - 1;
            fim2 = (inicio2 + tam_bloco - 1 < TAMARR - 1)? inicio2 + tam_bloco - 1 : TAMARR - 1;
            
            i = inicio1;
            j = inicio2;
            k = inicio1;
            while (i <= fim1 && j <= fim2) {
                if (arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else
                    temp[k++] = arr[j++];
            }
            
            while (i <= fim1)
                temp[k++] = arr[i++];
            while (j <= fim2)
                temp[k++] = arr[j++];
            
            for (i = inicio1; i <= fim2; i++)
                arr[i] = temp[i];
        }
    }
    
    free(temp);
    
    clock_t end = clock();
    sortTime = ((double) (end - start)) / CLOCKS_PER_SEC;
    return sortTime;
}

//void mostrarTodosResultados(double bubble, double selection, double insertion, double heap, double quick, double merge, double shell, double bucket, double counting, double radix)

int main(){
    int arr[TAMARR];
    int opMenu;
    double bubbleTime = 0, selectionTime = 0, insertionTime = 0, heapTime = 0, quickTime = 0, mergeTime = 0, shellTime = 0, bucketTime = 0, countingTime = 0, radixTime = 0;

    setlocale(LC_ALL, "Portuguese");

    srand(time(NULL));
    preencherArray(arr);

    do{
        imprimirMenu();
        scanf("%d", &opMenu);

        switch (opMenu){
            case 1:
                preencherArray(arr);
                break;
            case 2:
                bubbleTime = mostrarResultado(arr, bubbleSort);
                break;
            case 3:
                selectionTime = mostrarResultado(arr, selectionSort);
                break;
            case 4:
                insertionTime = mostrarResultado(arr, insertionSort);
                break;
           	case 5:
    			heapTime = mostrarResultado(arr, heapSort);
    			break;
			case 6:
    			quickTime = mostrarResultado(arr, quickSort);
    			break;
			case 7:
    			mergeTime = mostrarResultado(arr, mergeSort);
    			break;
    		/*
            case 8:
                shellSort (arr);
                break;
            case 9:
                bucketSort (arr);
                break;
            case 10:
                countingSort (arr);
                break;
            case 11:
                radixSort (arr);
                break;
            */
            case 12:
                if (bubbleTime == 0){
                    bubbleTime = bubbleSort(arr);
                }
                if (selectionTime == 0){
                    selectionTime = selectionSort(arr);
                }
                if (insertionTime == 0){
                	insertionTime = insertionSort(arr);
				}
				if(heapTime == 0){
					heapTime = 	heapSort(arr);
				}
				if(quickTime == 0){
					quickTime = quickSort(arr);
				}
				if(mergeTime == 0){
					mergeTime = mergeSort(arr);
				}
                printf("+-------------------------------------------------------------+\n");
                printf("|                  Resultados das ordenações                  |\n");
                printf("|Bubble   : %.3f segundos                                    |\n", bubbleTime);
                printf("|Selection: %.3f segundos                                    |\n", selectionTime);
                printf("|Insertion: %.3f segundos                                    |\n", insertionTime);
                printf("|Heap     : %.3f segundos                                    |\n", heapTime);
                printf("|Quick    : %.3f segundos                                    |\n", quickTime);
                printf("|Merge    : %.3f segundos                                    |\n", mergeTime);
                printf("|Shell    : %.3f segundos                                    |\n", shellTime);
                printf("|Bucket   : %.3f segundos                                    |\n", bucketTime);
                printf("|Counting : %.3f segundos                                    |\n", countingTime);
                printf("|Radix    : %.3f segundos                                    |\n", radixTime);
                printf("+-------------------------------------------------------------+\n");
                break;
            case 13:
                imprimirArray(arr);
                break;
        }
    }while (opMenu != 0);

    return 0;
}
