#include <iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdio.h>
#include<locale.h>
using namespace std;
// ****** Disculpas, me enrrede con el codigo y no pude lograr que funcionara correctamente *******
// variables globales
int i;
int o=0;
string nombre[100];
string cedula[100];
string id[100];
string idr[100];
string nombres;
bool encontrado = false;
bool encontrado1 = false;
bool encontrado2 = false;
/****************/
// funciones y metodos
void ingreso();
void gotoxy();
void cuadro();
void registro();
void borrar();
void consultar();
void reporte();
/*********************/
HANDLE hConsoleHandle = GetStdHandle (STD_OUTPUT_HANDLE);
void gotoxy(int x ,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);

}

void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	
	for (i=x1; i<=x2;i++)
	{
		gotoxy(i,y1); printf("%c",205);   
		gotoxy(i,y2); printf("%c",205);   
	}

	for (i=y1; i<=y2;i++)
	{
		gotoxy(x1,i); printf("%c",186);  
		gotoxy(x2,i); printf("%c",186);   
	}

	
	gotoxy(x1,y1); printf("%c",201);   
	gotoxy(x1,y2); printf("%c",200);  
	gotoxy(x2,y1); printf("%c",187);  
	gotoxy(x2,y2); printf("%c",188);  

}

void ingreso()
{

	char opcion1, sigue;
	
	
		
		do{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(10,5,100,28);
		cuadro(33,1,80,3);
		SetConsoleTextAttribute (hConsoleHandle, 15);	
       gotoxy(40,02); cout << " Ingrese los Datos del inmigrante:	" <<endl;
     	
     	
 	   SetConsoleTextAttribute (hConsoleHandle, 15);
	   gotoxy(12,6); cout << "Ingrese el nombre del inmigrante: " ;
 	   cin >> nombre[i];
	
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,8);cout << " Ingrese la cedula del inmigrante: " ;
    	cin >> cedula[i];
		
	   SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,10);cout << "Coloque el Id del inmigrante: " ;
       cin >> id[i];
       
       SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,12);cout << "Registre al inmigrante como N: " ;
       cin >> idr[i];
		o++;
	   
	    do{
	       SetConsoleTextAttribute (hConsoleHandle, 15);
		gotoxy(12,20);cout<<"Desea Continuar agregando S/N";
	       sigue=getch();
	       
	    }while (toupper(sigue)!='S' && toupper(sigue)!='N');
    }while (tolower(sigue)=='s');
 
}

void registro()
{

		
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,5,100,28);
	cuadro(33,1,80,3);
    SetConsoleTextAttribute (hConsoleHandle, 15);	
    gotoxy(40,02); cout << " Registrar:	" <<endl;
      
    SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,6);cout << " Digite el Id para registrar al inmigrante:";
    cin >> nombres;
    for (int indice =0 ;(indice<o);indice++) 
    {                                         
	if (nombres==id[i])
	{ 
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,8);cout << " Registre al inmigrante como ingreso o salida:";
    cin >> idr[i];
	encontrado = true;
	} 
}
	if (encontrado==false){
	
	gotoxy(12,20);	cout<<"<La persona no existe, Pulse tecla para Abandonar> ";
	getch();
    }

}

void borrar()
{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,5,100,28);
	cuadro(33,1,80,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);	
    gotoxy(40,02); cout << " Borrar inmigrante:	" <<endl;
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,6);cout << "Digite el id para borrar el registro del inmigrante:";
    cin >> nombres;
    for (int indice =0 ;(indice<o);indice++)  
    {                                         
	 if (nombres==id[i])
	   { 
	   
        nombre[i]="";
        cedula[i]="";
        id[i]="";
        idr[i]="";
	    encontrado1 = true;
	    gotoxy(12,20);	cout<<"<Registro borrado, Pulse tecla para Abandonar> ";
	    getch();
	 } 
   }

   if (encontrado1==false){
    SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,20);	cout<<"<La persona no existe, Pulse tecla para Abandonar> ";
	getch();
   }   
}

void consultar()
{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,5,100,28);
	cuadro(33,1,80,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);	
    gotoxy(40,02); cout << " Consultar inmigrante:	" <<endl;
    
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,6);cout << "Digite el id para buscar al inmigrante:";
    cin >> nombres;
    for (int indice =0 ;(indice<o);indice++)  
   {                                         
	 if (nombres == id[i])
	   { 
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,8);cout << "Nombre:" << nombre[indice] << endl;
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,10);cout << "Cedula:" << cedula[indice] << endl;
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,12);cout << "ID:" << id[indice] << endl;
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,14);cout << "Registro:" << idr[indice] << endl;
	
	    encontrado2 = true;
	    gotoxy(12,20);	cout<<"<Pulse tecla para Abandonar> ";
	    getch();
	 } 
    }

    if (encontrado2==false){
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,20);	cout<<"<La persona no existe, Pulse tecla para Abandonar> ";
	getch();
    }
}

void reporte()
{
	system("cls");
	SetConsoleTextAttribute (hConsoleHandle, 10);
	cuadro(10,5,100,28);
	cuadro(33,1,80,3);
	SetConsoleTextAttribute (hConsoleHandle, 15);	
    gotoxy(40,02);cout << "Reporte:" << endl;

    for (int indice =0 ;(indice<o);indice++)
    {
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,6); cout << "Nombres: " << nombre[i];
	
	SetConsoleTextAttribute (hConsoleHandle, 15);
	gotoxy(12,10); cout << " cedulas: " <<cedula[i];
	
	
	
	gotoxy(12,20);	cout<<"<Pulse tecla para Abandonar> ";
	    getch();
   }
}

menu()
{
	char opc,conti;
	do	{
		system("cls");
		SetConsoleTextAttribute (hConsoleHandle, 10);
		cuadro(16,2,65,6); 
		cuadro(8,8,72,23);
		cuadro(8,24,72,26); 
		cuadro(15,20,27,22); 
		SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(28,4);printf(" Ingreso de inmigrantes ");
        SetConsoleTextAttribute (hConsoleHandle, 15);
	    gotoxy(15,10);printf("[1]  Ingresar viajero: ");
		gotoxy(15,12);printf("[2]  Registrar al inmigrante como ingreso o salida:");
		gotoxy(15,14);printf("[3]  Borrar Registros de inmigrantes:");
		gotoxy(15,16);printf("[4]  Consultar inmigrante");
		gotoxy(15,18);printf("[5]  Reporte de inmigrantes");
		gotoxy(16,21);printf("<[6] Salir>");
		
		SetConsoleTextAttribute(hConsoleHandle,14);
		gotoxy(15,25);printf("Su opcion es: ");
		opc=getch();

		switch(opc)
			{
			case '1': ingreso();break;
			case '2': registro(); break;
			case '3': borrar(); break;
			case '4': consultar(); break;
			case '5': reporte(); break;
			case '6':
				
			system("cls");
			gotoxy(20,10);printf("Estas seguro Que Deseas Salir del Sistema");
			SetConsoleTextAttribute (hConsoleHandle, 2);
			gotoxy(20,15);printf("Desea Continuar S/N");
			conti=getch();

			if (conti=='N' || conti=='n')
			menu();
			else if (conti=='S' || conti=='s')
			break; 
			}
		}while(opc!='6');
}



int main(int argc, char** argv) {
	menu();
	return 0;
}
