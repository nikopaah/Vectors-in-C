#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>

#define Max 180
#define ESC 27

struct Dados{ // Variaveis "Mutáveis"
	int i;
	double X, Y;
	double passoX, passoY;
	
	double X1, Y1;
	double X2, Y2;
	bool Controle;
};

int main()  {
	
	// Iniciação
    int valor, Tecla;
    int Larg, Altu;
    int baseCalc;
    Dados Var[20];
    srand(time(NULL));
    
    Larg = 0;
    Altu = 0;
    //------
    
    do {
    	printf("Digite a Largura da tela (que seja maior que %d): ", Max);
    	scanf("%d", &Larg);
    } while(Larg < Max);
    
    do {
    	printf("Digite a Altura da tela (que seja maior que %d e menor que %d): ", Larg-50, Larg);
    	scanf("%d", &Altu);
    } while(Altu < Larg-50 || Altu > Larg);
    
    if(Larg > Altu) baseCalc = Altu;
    else baseCalc = Larg;
    
    //------------------------------
    // Variavéis Fixas
    int Margem = Larg/20;
    int Raio = Altu/30;
    int pg = 1, Cor = 0, i=0; 
    
    int qtdePLua = 14;
    int PontosLua[28] = {
    	//  X          Y
        baseCalc/2.5, (baseCalc/45)+Margem,
        baseCalc/3,   (baseCalc/18)+Margem,
        baseCalc/3.2, (baseCalc/10)+Margem,
        baseCalc/3.3, (baseCalc/5)+Margem,
        baseCalc/2.8, (baseCalc/3.6)+Margem,
        baseCalc/2,   (baseCalc/3.3)+Margem, 
        baseCalc/1.8, (baseCalc/4.2)+Margem,
        baseCalc/1.7, (baseCalc/6.4)+Margem,

        baseCalc/1.9, (baseCalc/4.5)+Margem,
        baseCalc/2.1, (baseCalc/4)+Margem,
        baseCalc/2.3, (baseCalc/4.5)+Margem,
        baseCalc/2.8, (baseCalc/6.9)+Margem,
        baseCalc/2.7, (baseCalc/18)+Margem,
        baseCalc/2.5, (baseCalc/45)+Margem
    };
    //---------
    int qtdePCarro = 10;
	int PontosCarro[20] = {
	//   X    Y
		Altu/9,    Altu/1.09, //820
		Altu/6.92, Altu/1.13,
		Altu/5.62, Altu/1.13,
		Altu/4.09, Altu/1.22,
		Altu/2.25, Altu/1.24,
		
		Altu/2.36, Altu/1.16,
		Altu/2.14, Altu/1.13,
		Altu/1.95, Altu/1.13,
		Altu/1.95, Altu/1.09,
		Altu/9,    Altu/1.09
		};
	
	//------------------------------
    // Variavéis Struct
    Var[1].Y = Altu-Margem-Raio;
    Var[2].Y = Altu-Margem-Raio;
	Var[0].passoY = 1;
	Var[1].passoY = 0.05;
	Var[1].passoX = 0.05;
	
	Var[0].Controle = true;
	Var[1].Controle = true;
	
	Var[1].X = Larg/3;
	Var[2].X = Larg/3.8;
	Var[3].X = Larg/3;
	Var[4].X = Larg/3.8;
	
	Var[3].Y = Altu/1.7;
    Var[4].Y = Altu/1.9;
    Var[5].Y = Altu/1.6;
    Var[6].Y = Altu/1.7;
	
    //-------------------------------------------------------
    // Inicialização
    initwindow(Larg, Altu, "JOGNA2 – Entrega N1.D – Grupo Nekomancers", 200, 50);
    
    
	while(Tecla != ESC){
		
	if(pg == 1) pg = 2; else pg = 1;		
	setactivepage(pg); // Em construção
		
		setbkcolor(RGB(75,0,130));
    	cleardevice();
    
    	// Margem
    	setcolor(RGB(131,111,255));
    	rectangle(Margem, Margem , Larg-Margem, Altu-Margem);
    	
    	//--------------------
    	// Céu
    
    	for(Var[0].i = 0; Var[0].i < Larg/11.25; Var[0].i++){
    		Var[0].X = rand()%Larg+1;
    		Var[0].Y = rand()%Altu+1;
    		Cor = RGB(rand()%256, rand()%256, rand()%256);
    	
	    	putpixel(Var[0].X,Var[0].Y-3, Cor);
	    	putpixel(Var[0].X,Var[0].Y-2, Cor);
	    
	    	putpixel(Var[0].X-2,Var[0].Y, Cor);
	    	putpixel(Var[0].X-3,Var[0].Y, Cor);
	    
	    	putpixel(Var[0].X + 2,Var[0].Y, Cor);
	    	putpixel(Var[0].X + 3,Var[0].Y, Cor);
	    
	    	putpixel(Var[0].X,Var[0].Y+2, Cor);
	    	putpixel(Var[0].X,Var[0].Y+3, Cor);
		}
    
	    drawpoly(qtdePLua, PontosLua);
		
	    // CENÁRIO
		setfillstyle(1, RGB(0,0,0));
		// Parallax 01    
	    //  Início  Altura   Largura  Onde ele bate no chão
	    bar(Margem+1,(Larg/2)+Margem , Larg/8,Altu-Margem);
	    bar(Larg/8,Larg/3 , Larg/4,Altu-Margem);
	    bar(Larg/4,Larg/6 , Larg/3,Altu-Margem);
	    bar(Larg/3,Larg/4.5 , Larg/1.8,Altu-Margem);
	    bar(Larg/1.7,Larg/3 , Larg/1.3,Altu-Margem);
	    bar(Larg/1.3,Larg/9, Larg/1.2,Altu-Margem);
	    bar(Larg/1.3,Larg/6, Larg/1.12,Altu-Margem);
	    bar(Larg/1.11,Larg/2.25, Larg-Margem,Altu-Margem);
	    
	    // Parallax 02
	    setfillstyle(1, RGB(28,28,28));
	    bar(Larg/15,Larg/3, Larg/9,Altu-Margem);
	    bar(Larg/9,Larg/2.25, Larg/3,Altu-Margem);
	    bar(Larg/2.9,Larg/3.6, Larg/1.5,Altu-Margem);
	    bar(Larg/1.4,Larg/2, Larg/1.2,Altu-Margem);
	    bar(Larg/1.2,Larg/1.63, Larg-Margem,Altu-Margem);
	    
	    // Parallax 03
	    setfillstyle(1, RGB(54,54,54));
	    bar(Margem+1,Larg/1.63, Larg/9,Altu-Margem);
	    bar(Larg/9,Larg/2.5, Larg/3.6,Altu-Margem);
	    bar(Larg/3.6,Larg/4.5, Larg/3,Altu-Margem);
	    bar(Larg/2.8,Larg/1.8, Larg/2,Altu-Margem);
	    bar(Larg/2,Larg/2.5, Larg/1.5,Altu-Margem);
	    bar(Larg/1.5,Larg/4.5, Larg/1.3,Altu-Margem);
	    bar(Larg/1.3,Larg/1.5, Larg-Margem,Altu-Margem);
	    
	    // Janelas
	    setcolor(RGB(255,255,255));
	    rectangle(Larg/3.46,Larg/4.28 , Larg/3.33,Altu-Margem*8);
	    rectangle(Larg/3.21,Larg/4.28 , Larg/3.10,Altu-Margem*8);
	    rectangle(Larg/1.47,Larg/4.28, Larg/1.40,Altu-Margem*10);
    
	    for(Var[1].i = 0; Var[1].i < Larg/180; Var[1].i++){
	    	rectangle(Larg/15,Larg/1.57+(Raio*Var[1].i) , Larg/10, Larg/1.52+(Raio*Var[1].i));
	    	rectangle(Larg/1.83,Larg/2.43+(Raio*Var[1].i), Larg/1.76,Larg/2.3+(Raio*Var[1].i));
	    	rectangle(Larg/1.73,Larg/2.43+(Raio*Var[1].i), Larg/1.52,Larg/2.3+(Raio*Var[1].i));
		}
	    
	    //-------------------------------
			
		// Carro
		setcolor(RGB(131,111,255));
		setfillstyle(1, RGB(131,111,255));
		fillpoly(qtdePCarro, PontosCarro);
		
		setcolor(RGB(255,255,255));	
		circle(baseCalc/4.7, Var[1].Y, Raio);
		circle(baseCalc/2.4, Var[2].Y, Raio);
		
		setcolor(RGB(0,255,255));	
		line(Var[1].X, Var[3].Y, Altu/3, Altu/1.23);
		setcolor(RGB(128,0,0));
        line(Var[2].X, Var[4].Y, Altu/3, Altu/1.23);
        setcolor(RGB(240,230,140));	
        line(Var[3].X, Var[5].Y, Altu/3, Altu/1.23);
        setcolor(RGB(255,228,225));	
        line(Var[4].X, Var[6].Y, Altu/3, Altu/1.23);
        
        
        
		setfillstyle(1, RGB(0,255,255));
		fillellipse(Var[1].X, Var[3].Y, Raio, Raio);
		setfillstyle(1, RGB(128,0,0));
    	fillellipse(Var[2].X, Var[4].Y, Raio, Raio);
    	setfillstyle(1, RGB(240,230,140));
    	fillellipse(Var[3].X, Var[5].Y, Raio, Raio);
    	setfillstyle(1, RGB(255,228,225));
    	fillellipse(Var[4].X, Var[6].Y, Raio, Raio);
		
		
			
	setvisualpage(pg); // Visualização
		
		// CÁLCULOS
		if(Var[0].Controle){
			i=0;
			while(i < Larg/180){
				Var[1].Y = Var[1].Y + Var[0].passoY;
				Var[2].Y = Var[2].Y - Var[0].passoY;
				
				Var[1].X = Var[1].X - Var[1].passoX;
				Var[2].X = Var[2].X + Var[1].passoX;
				
				Var[3].X = Var[3].X - Var[1].passoX;
				Var[5].Y = Var[5].Y - Var[1].passoY;
				Var[4].X = Var[4].X + Var[1].passoX;
				Var[6].Y = Var[6].Y + Var[1].passoY;
				
				i++;
				Var[0].Controle = false;
			}
		}
		else if(!Var[0].Controle){
			i=0;
			while(i < Larg/180){
				Var[1].Y = Var[1].Y - Var[0].passoY;
				Var[2].Y = Var[2].Y + Var[0].passoY;
				
				Var[1].X = Var[1].X + Var[1].passoX;
				Var[2].X = Var[2].X - Var[1].passoX;
				
				Var[3].X = Var[3].X + Var[1].passoX;
				Var[5].Y = Var[5].Y + Var[1].passoY;
				Var[4].X = Var[4].X - Var[1].passoX;
				Var[6].Y = Var[6].Y - Var[1].passoY;
				
				i++;
				Var[0].Controle = true;
			}
		}
		
		
			
		if(kbhit()) //Meio que obrigatório estar aqui
		Tecla = getch();
		
		delay(200);
	}
  
      closegraph();    
      return 0;     
}
