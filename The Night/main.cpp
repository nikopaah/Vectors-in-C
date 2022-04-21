#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>

#define ESC 27
#define SPACE 32

struct TStars{ // Variaveis "Mutáveis"

	int i;
  	int starX, starY; //coordenadas X e Y
  	int starC;   //cor do pixel
  	//int grandeza;     // 1 para big e 2 para pitico
};



void Triangulo(double X, double Y, int TamX, int TamY){
	int PontosTriangulo[8] = {
	//   X    Y 675
		X, Y,
		X-(TamX/18), Y+(TamY/11.25),
		X+(TamX/18), Y+(TamY/11.25),
		X, Y
	};
	
	setcolor(RGB(50,255,251));
	setfillstyle(3, RGB(255,255,255));
	fillpoly(4, PontosTriangulo);
}

void criaEstrela(TStars *Var, int qtd, int TamX, int TamY){
	int cont = 0;
	int i = 0;
	
	for(i = 0; i < qtd; i++){    	
	    cont++;
	    Var[cont-1].starX = rand()%TamX+1;
	    Var[cont-1].starY = rand()%TamY+1;
	    Var[cont-1].starC = RGB(rand()%256, rand()%256, rand()%256);
	}
}

int main(){
	
	int Tecla = 0, qtdEstrela = 0, Cor;
	int TamX = 0; //Largura
	int TamY = 0; //Altura
	int cont = 0;
	int pg = 1;
	int i =0;
	
	
	
	TStars *Var;
	Var = NULL;
	
    srand(time(NULL));
    //------
    
    printf("Digite a Largura da tela: ");
    scanf("%d", &TamX);
    
    //TamX = 900;
    
    TamY = (TamX * 75) / 100;
    qtdEstrela = (TamX * 8) / 100;
    
    
	double X = TamX/2, Y = TamY/2;
	double passoX = 3, passoY = 3;
	
	// Inicialização
    initwindow(TamX, TamY, "JOGNA2 – Entrega N1.E – Grupo Nekomancers", 200, 50);
    
    Var = (TStars *)malloc(sizeof(TStars) * qtdEstrela);
    criaEstrela(Var, qtdEstrela, TamX, TamY);
    
    while(Tecla != ESC){
    	
    	if(pg == 1) pg = 2; else pg = 1;
			
		setactivepage(pg); // Em construção
		cleardevice();
		setbkcolor(RGB(8,12,59));
    	
    	
    	cont = 0;
	    for(i = 0; i < qtdEstrela; i++){
	    	
	    	cont++;

		    putpixel(Var[cont-1].starX,Var[cont-1].starY-3, Var[cont-1].starC);
		    putpixel(Var[cont-1].starX,Var[cont-1].starY-2, Var[cont-1].starC);
		    
		    putpixel(Var[cont-1].starX-2,Var[cont-1].starY, Var[cont-1].starC);
		    putpixel(Var[cont-1].starX-3,Var[cont-1].starY, Var[cont-1].starC);
		    
		    putpixel(Var[cont-1].starX + 2,Var[cont-1].starY, Var[cont-1].starC);
		    putpixel(Var[cont-1].starX + 3,Var[cont-1].starY, Var[cont-1].starC);
		
		    putpixel(Var[cont-1].starX,Var[cont-1].starY+2, Var[cont-1].starC);
		    putpixel(Var[cont-1].starX,Var[cont-1].starY+3, Var[cont-1].starC);
		    
		    putpixel(Var[cont-1].starX+20,Var[cont-1].starY + Var[cont-1].starY+15, Var[cont-1].starC);
		}
		
		Triangulo(X, Y, TamX, TamY);
		
		//-------------------------------------------------------->
		setvisualpage(pg); // Visualização
		
		// Triangulo fora da Tela
		if(X < 0) X = TamX;
		if(X > TamX) X = 0;
		if(Y < 0) Y = TamY;
		if(Y > TamY) Y = 0;
		
		fflush(stdin);
		if(kbhit()){
			
			Tecla = getch();
			// printf("%d", Tecla);
		}
		
		//Movimentação Triangulo
		if(GetKeyState(VK_LEFT)&0x80)  X = X - passoX;
		if(GetKeyState(VK_RIGHT)&0x80) X = X + passoX;
		if(GetKeyState(VK_UP)&0x80)    Y = Y - passoY;
		if(GetKeyState(VK_DOWN)&0x80)  Y = Y + passoY;
			
		// Captura Tecla "V"
		if(GetKeyState(0x56)&0x80) {
			criaEstrela(Var, qtdEstrela, TamX, TamY);
		}
			
		// Captura Tecla "Espaço"
		if(GetKeyState(VK_SPACE)&0x80){
			X = (rand()%TamX+1)-(TamX/18);
			Y = (rand()%TamY+1)-(TamY/11.25);
		}  
			
	}
	
	free(Var);

    closegraph();    
    return 0;  
}
