#include <stdio.h>
#include <stdlib.h>

struct vetorMagico{
	int *v;
	int posicao;
	int tamanho;
};

struct vetorMagico * criarVetor(int t){
	struct vetorMagico *p;
	p = (struct vetorMagico *) malloc (sizeof(struct vetorMagico));
	if(p){
		p->v = (int *) malloc (t * sizeof(int));
		if(p->v){
			p->posicao = 0;
			p->tamanho = t;
			return p;		
		}
		return NULL;
	}
}

struct vetorMagico * liberarVetor(struct vetorMagico *p){
	free(p->v);
	free(p);
	return NULL;
}

int estaVazio(struct vetorMagico *p){
	if(p->posicao == 0){
		return 1;
	}
}

int estaCheio(struct vetorMagico *p){
	if(p->posicao != p->tamanho) return 0;
}

int inserirVetor(int n, struct vetorMagico *p){
	int * aux, i;
	if(!estaCheio(p)){
		p->v[p->posicao++] = n; 
		return 1;
	}
	aux = (int *) malloc (2 * p->tamanho * sizeof(int));
	if(aux){
	 for(i = 0; i < p-> tamanho; i++){
	 	aux[i] = p->v[i];
	 }
	 free(p->v);
	 p->v = aux;
	 p->v[p->posicao++] = n;
	 p->tamanho = p->tamanho * 2;
	 return 1;
	
	}	
}

int removerElemento(int n, struct vetorMagico *p){
	int i, j;
	for(i = 0; i < p->tamanho; i++){
		if(n == p->v[i]){
			for(j = i; j < p->posicao; j++){
				p->v[j] = p->v[j+1];
			}
			p->posicao--;
		}
	}
}

void mostrarVetor(struct vetorMagico *p){
	int i;
	for(i = 0; i < p->tamanho; i++){
		printf("\nP->V[%d]-> %d\n", i, p->v[i]);
	}
}

void menu(){
	printf("\n\n1 - INSERIR NO VETOR\n");
	printf("2 - REMOVER ELEMENTO DO VETOR\n");	
	printf("3 - MOSTRAR VETOR\n");
}


int main(){
	
	int num, i, op = 1;
	struct vetorMagico *vetor;
	vetor = criarVetor(5);
	if(vetor) printf("VETOR CRIADO COM SUCESSO!\n\n");
	
	while(op){
		menu();
		scanf("%d", &op);
		if(op == 1){
			system("cls");
			printf("DIGITE UM NUMERO PARA INSERIR NO VETOR: \n\n");
			scanf("%d", &num);
			inserirVetor(num, vetor);
		}
		if(op == 2){
			system("cls");
			printf("DIGITE UM NUMERO PARA REMOVER DO VETOR: \n\n");
			scanf("%d", &num);
			removerElemento(num, vetor);
		}
		if(op == 3){
			system("cls");
			mostrarVetor(vetor);
		}		
	}
	return 0;
}
