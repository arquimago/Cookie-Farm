#include <stdio.h>
#include <stdlib.h>

double calculateTime(double C,double F,double X,int n, double tempo){
	long double tempoAtual=0,tempoParaFarm=0,tempoComFarm=0;
	tempoAtual=X/(2+(n*F));
	tempoParaFarm=C/(2+(n*F));
	tempoComFarm=tempoParaFarm+X/(2+((1+n)*F));
	if(tempoComFarm>tempoAtual) {
		tempo=tempo+tempoAtual;	
		return tempo;
	}else{
		return calculateTime(C,F,X,(n+1),(tempo+tempoParaFarm));
	} 
}


int main(int argc,char** argv){
	int T=0,i=0;
	double C=0,F=0,X=0,tempo=0;
	FILE *arqOutput;
	FILE *arqInput;
	arqInput=fopen(argv[1],"r");
	arqOutput=fopen(argv[2],"w");
	if(arqInput==NULL||arqOutput==NULL){
		printf("Falha no acesso aos arquivos");
		exit(42);
	}
	fscanf(arqInput," %d",&T);
	
	for(i=1;i<(T+1);i++){
	
		fscanf(arqInput," %Lf %Lf %Lf",&C,&F,&X);
	
		tempo=calculateTime(C,F,X,0,0);
	
		fprintf(arqOutput,"Case #%d: %.7f\n",i,tempo);
	}
	return 0;	
}
