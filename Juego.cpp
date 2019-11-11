#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <allegro.h>
#include "Juego.h"

using namespace std;

MIDI *musica1;
SAMPLE *musica;

void classic();
void puzzle();
void zen();
bool b=true;
bool verificar2=false,verificar3=false;
int verificar=0;
int temporal;


Juego::Juego(int **m,int score){
this->m=m;
this->score=score;
}

int ** Juego::getmat(){
return this->m;
}

void eliminar3(Juego *obj){
int **aux=new int*[6];
for(int i=0;i<6;i++)
    aux[i]=new int[6];
aux=obj->getmat();
 for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
        verificar=0;
        if(aux[i][j]!=0)
            temporal=aux[i][j];
        else
            temporal=-1;
        obj->MatrizSP(i,j,0,temporal);
        }
    }
}

void Juego::LEFT(int i){
int aux;
aux=this->m[i][0];
for(int j=0;j<5;j++)
    this->m[i][j]=this->m[i][j+1];
this->m[i][5]=aux;
}

void Juego::RIGHT(int i){
int aux;
aux=this->m[i][5];
for(int j=5;j>=0;j--)
    this->m[i][j]=this->m[i][j-1];
this->m[i][0]=aux;
}

void Juego::UP(int j){
int aux;
aux=this->m[0][j];
for(int i=0;i<5;i++)
    this->m[i][j]=this->m[i+1][j];
this->m[5][j]=aux;
}

void Juego::DOWN(int j){
int aux;
aux=this->m[5][j];
for(int i=5;i>0;i--)
    this->m[i][j]=this->m[i-1][j];
this->m[0][j]=aux;
}


void menu(){

if(install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT,NULL)!=0){
    allegro_message("Error",allegro_error);
}

set_volume(70,70);
musica=load_sample("IABB.wav");
play_sample(musica,300,150,1000,1);
install_mouse();
install_keyboard();
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT_WINDOWED,1138,640,0,0);

//define variables utilizadas en el programa
	BITMAP *buffer = create_bitmap(1138,640);
	BITMAP *fondo;
	BITMAP *fondo2;
	BITMAP *menu1;
	BITMAP *menu2;
	BITMAP *menu3;
	BITMAP *menu4;
	BITMAP *menu5;
	BITMAP *menu6;
	BITMAP *menu7;
	BITMAP *cursor;

	// inicializa las variables
	clear_to_color(buffer, 0x333333);
	fondo = load_bitmap("Dots 1.1.bmp",NULL);
	fondo2 = load_bitmap("Dots 1.2.bmp",NULL);
	menu1=load_bitmap("Menu 1.bmp",NULL);
	menu2=load_bitmap("Menu 1.1.bmp",NULL);
	menu3=load_bitmap("Menu 1.2.bmp",NULL);
	menu4=load_bitmap("Menu 1.3.bmp",NULL);
	menu5=load_bitmap("Menu 1.4.bmp",NULL);
	menu6=load_bitmap("Menu 1.5.bmp",NULL);
	menu7=load_bitmap("Menu 1.6.bmp",NULL);
	cursor = load_bitmap("cursor.bmp",NULL);


	 bool salida = false;

    // primer menu simple
	while ( !salida )
	{
        play_sample(musica,300,150,1000,1);

         // posicion del boton
         if ( mouse_x > 940 && mouse_x < 1080 &&mouse_y > 540 && mouse_y < 585)
         {
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);

            // se ha pulsado el boton del raton
            if ( mouse_b & 1 )
            {
              salida=true;
            }
         }else{
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
         }

         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla
	     blit(buffer, screen, 0, 0, 0, 0, 1138, 640);

          if ( key[KEY_ESC] )
          {
               salida = true;
          }
    } //FIn de primera pantalla
    usleep(180000);
    salida=false;
    while(!salida){

        if (mouse_x > 455 && mouse_x < 685 && mouse_y > 290 && mouse_y <355 ){
          blit(menu2, buffer, 0, 0, 0, 0, 1138, 640);
            // se ha pulsado el boton del raton
          if ( mouse_b & 1 ){
            usleep(180000);
             zen();//Si se cumple que mande a llamar al modo de juego
          }
        }else if(mouse_x > 455 && mouse_x < 685 && mouse_y > 55 && mouse_y <120 ){
            blit(menu5, buffer, 0, 0, 0, 0, 1138, 640);
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 ){
                usleep(180000);
                classic();
          }

        }else if(mouse_x > 20 && mouse_x < 130 && mouse_y > 20 && mouse_y <90){
        blit(menu7, buffer, 0, 0, 0, 0, 1138, 640);
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 ){
                salida=true; //Si se cumple que mande a llamar al modo de juego
            }
        }else if(mouse_x > 950 && mouse_x < 1112 && mouse_y > 20 && mouse_y <90){
        blit(menu6, buffer, 0, 0, 0, 0, 1138, 640);
            // se ha pulsado el boton del raton
            if ( mouse_b & 1 ){
                salida=true; //Si se cumple que mande a llamar al modo de juego
            }
        }else{
        if (mouse_x > 455 && mouse_x < 685 && mouse_y > 215 && mouse_y < 275){
               blit(menu3, buffer, 0, 0, 0, 0, 1138, 640);
                // se ha pulsado el boton del raton
                if ( mouse_b & 1 )
                {
                salida=true;
                }
        }else{
        if (mouse_x > 455 && mouse_x < 685 && mouse_y > 137 && mouse_y < 200){
                blit(menu4, buffer, 0, 0, 0, 0, 1138, 640);
                // se ha pulsado el boton del raton
                if ( mouse_b & 1 )
                {
                usleep(180000);
                puzzle();
                }
        }else{
               blit(menu1, buffer, 0, 0, 0, 0, 1138, 640);
            }
            }//segundo else
        }//primer else
        masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);
        blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
         if ( key[KEY_ESC] )
          {
               salida = true;
          }



    }
//FIN DEL MENU *********************************************************************************

//Pantalla principal-------------------------------




    }


void classic(){

   Juego *obj;
    int **m;
    m=new int*[6];
    for(int i=0;i<6;i++)
        m[i]=new int[6];
    srand(time(NULL));
    obj=new Juego(m,0);
    obj->llenarmat(5);
    obj->P_JUEGO();
}



void Juego::P_JUEGO(){//Imprime tablero jeje
install_mouse();
install_keyboard();
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1138, 640, 0, 0);
	BITMAP *buffer = create_bitmap(1138, 640);
    BITMAP *fondo;
    BITMAP *fondo2;
    BITMAP *fondo1;
    BITMAP *circulo;
	BITMAP *bolis;
	BITMAP *bola;
	BITMAP *cursor;
	bool bola1=true,bola2=true;
    bool salida=true;
    bool elimi=false;
    bool salida2=true;
	// inicializa las variables
	clear_to_color(buffer, 0x333333);
	fondo2=load_bitmap("Tablero 3.bmp",NULL);
	fondo1=load_bitmap("Tablero 1.bmp",NULL);
	fondo = load_bitmap("Tablero 2.bmp",NULL);
	circulo = load_bitmap("explo.bmp",NULL);
	bolis=load_bitmap("bolitas4.bmp",NULL);
	cursor=load_bitmap("cursor.bmp",NULL);
     int **aux=new int*[6];
    for(int i=0;i<6;i++)
    aux[i]=new int[6];
	while(salida==true){
    textprintf(fondo,font,160,200,0xFFFFFF,"  %d  ",this->score);
    if(score>1000 &&score<2000&&bola1==true){
    llenarmat(6);
    bola1=false;
    }else if(score>2000&&bola2==true){
    llenarmat(7);
    bola2=false;
    }
	elimi=false;
	if ( mouse_x > 25 && mouse_x < 120 &&mouse_y > 555 && mouse_y < 630){
            if ( mouse_b & 1 ){
            salida=false;
              sleep(1);
              }//UP::::::::::::::::::::.
        }else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 52 && mouse_y < 102){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(5);
                }
        }
        //DOWN:::::::::::
        else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 545 && mouse_y < 595){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(5);
                }
        }//LEFT:::::::::::::::::::::::
        else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(0);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(1);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(2);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(3);
                }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(4);
            }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(5);
                }
        }//RIGHT:::::::::::::::::::::::::...
        else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(0);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(1);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(2);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(3);
                }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(4);
            }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(5);
                }
        }

        else{}

        if(elimi==true){
        do{

        b=true;
        aux=this->getmat();
        for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
        verificar=0;
        if(aux[i][j]!=0)
            temporal=aux[i][j];
        else
            temporal=-1;
        MatrizSP(i,j,0,temporal);

        }
    }

    for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
        else
            masked_blit(circulo,buffer,0,0,l,k,53,53); ////////////////////////EXPLOSION PERRO


    }
    }
         // posicion del boton
            textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
                textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    }
    if(score<1000){
         recorrer(5);

     for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else{}

    }
    }
         // posicion del boton
            textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
    }
     }
    else if(score>1000&&score<2000){
     recorrer(6);
          for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else{}
            //masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
            textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
    }
     }
    else if(score>2000){
          for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else{}


    }
    }
         // posicion del boton
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::

                textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);

    }
     recorrer(7);

    }

    }while(b==false);
    }
           if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else{}
            //masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
            textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
            textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    }
    destroy_bitmap(bolis);
    destroy_bitmap(buffer);
	destroy_bitmap(fondo);
    destroy_bitmap(fondo1);
    destroy_bitmap(fondo2);
	destroy_bitmap(cursor);

}


void Juego::imprimir(){
for(int i=0;i<6;i++){
    for(int j=0;j<6;j++){
        cout<<this->m[i][j];
        }cout<<endl;
    }
}





void Juego::llenarmat(int n){

for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
        this->m[i][j]=1+rand()%(n-1+1);

}

void Juego::MatrizSP(int i,int j,int p,int temporal){//Funcion que va a hacer que la matriz se llene de tal forma que no encuentre 3 conectados en ninguna posision
   verificar+=1;

if(i<=4&&p!=4){//ARRIBA
    if(temporal==m[i+1][j]){
        if(j<=4)
            if(temporal==m[i][j+1])
                verificar++;
    MatrizSP(i+1,j,3,temporal);
    }
}
if(verificar>=3){
m[i][j]=0;
}

if(j<=4&&p!=2){//DERECHA
    if(temporal==m[i][j+1])
    MatrizSP(i,j+1,1,temporal);
}
if(verificar>=3){
m[i][j]=0;
}

if(i>=1&&p!=3){//ABAJO
    if(temporal==m[i-1][j]){
    MatrizSP(i-1,j,4,temporal);
    }
}
if(verificar>=3){
m[i][j]=0;
}
if(j>=1&&p!=1){//IZQUIERDA
    if(temporal==m[i][j-1])
    MatrizSP(i,j-1,2,temporal);
}
if(verificar>=3){
b=false;
this->score+=verificar;
m[i][j]=0;
}

}

void Juego::recorrer(int n){
int b1=0;
for(int i=0;i<6;i++)
    for(int j=0;j<6;j++)
        if(this->m[i][j]==0)
            b1=1;

if(b1==0)
return;
else{
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++){
            switch(i){
                case 0:
                    if(this->m[i][j]==0)
                        this->m[i][j]=1+rand()%(n-1+1);
                    break;
                case 1:
                    if(this->m[i][j]==0){
                    this->m[i][j]=this->m[i-1][j];
                    this->m[i-1][j]=1+rand()%(n-1+1);
                    }
                break;
                case 2:
                    if(this->m[i][j]==0){
                    this->m[i][j]=this->m[i-1][j];
                    this->m[i-1][j]=this->m[i-2][j];
                    this->m[i-2][j]=1+rand()%(n-1+1);
                    }
                break;
                case 3:
                    if(this->m[i][j]==0){
                    this->m[i][j]=this->m[i-1][j];
                    this->m[i-1][j]=this->m[i-2][j];
                    this->m[i-2][j]=this->m[i-3][j];
                    this->m[i-3][j]=1+rand()%(n-1+1);
                    }
                break;
                case 4:
                    if(this->m[i][j]==0){
                    this->m[i][j]=this->m[i-1][j];
                    this->m[i-1][j]=this->m[i-2][j];
                    this->m[i-2][j]=this->m[i-3][j];
                    this->m[i-3][j]=this->m[i-4][j];
                    this->m[i-4][j]=1+rand()%(n-1+1);
                    }
                break;
                case 5:
                    if(this->m[i][j]==0){
                    this->m[i][j]=this->m[i-1][j];
                    this->m[i-1][j]=this->m[i-2][j];
                    this->m[i-2][j]=this->m[i-3][j];
                    this->m[i-3][j]=this->m[i-4][j];
                    this->m[i-4][j]=this->m[i-5][j];
                    this->m[i-5][j]=1+rand()%(n-1+1);
                    }
                break;
                }
            }
        }
        }

    void puzzle(){

    Juego *obj2;
    int **m;
    m=new int*[6];
    for(int i=0;i<6;i++)
        m[i]=new int[6];
    srand(time(NULL));
    obj2=new Juego(m,0);

    obj2->Puzzle_Juego();


    }


    void Juego::Puzzle_Juego(){
    install_mouse();
install_keyboard();
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1138, 640, 0, 0);
	BITMAP *buffer = create_bitmap(1138, 640);
    BITMAP *fondo;
    BITMAP *fondo2;
    BITMAP *fondo1;
    BITMAP *circulo;
	BITMAP *bolis;
	BITMAP *bola;
	BITMAP *cursor;
	bool bola1=true,bola2=true;
    bool salida=true;
    bool elimi=false;
    bool salida2=true;
	// inicializa las variables
	clear_to_color(buffer, 0x333333);
	fondo2=load_bitmap("Tablero alone2.bmp",NULL);
	//fondo1=load_bitmap("Tablero 1.bmp",NULL);
	fondo = load_bitmap("puzzle1.bmp",NULL);
	circulo = load_bitmap("explo.bmp",NULL);
	bolis=load_bitmap("bolitas4.bmp",NULL);
	cursor=load_bitmap("cursor.bmp",NULL);
    this->m[0][0]=1;
    this->m[0][1]=1;
    this->m[0][2]=1;
    this->m[0][3]=1;
    this->m[0][4]=2;
    this->m[0][5]=2;
    this->m[1][0]=2;
    this->m[1][1]=1;
    this->m[1][2]=1;
    this->m[1][3]=1;
    this->m[1][4]=1;
    this->m[1][5]=2;
    this->m[2][0]=2;
    this->m[2][1]=2;
    this->m[2][2]=2;
    this->m[2][3]=2;
    this->m[2][4]=1;
    this->m[2][5]=1;
    this->m[3][0]=1;
    this->m[3][1]=1;
    this->m[3][2]=2;
    this->m[3][3]=2;
    this->m[3][4]=2;
    this->m[3][5]=2;
    this->m[4][0]=1;
    this->m[4][1]=1;
    this->m[4][2]=2;
    this->m[4][3]=2;
    this->m[4][4]=1;
    this->m[4][5]=1;
    this->m[5][0]=1;
    this->m[5][1]=2;
    this->m[5][2]=2;
    this->m[5][3]=1;
    this->m[5][4]=1;
    this->m[5][5]=1;



    int m2[6][6]= {{1,1,2,2,1,1},{1,1,2,2,1,1},{2,2,1,1,2,2},{2,2,1,1,2,2},{1,1,2,2,1,1},{1,1,2,2,1,1}};

    bool hola=true;
    while(hola==true){



        blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else
            masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }

    masked_blit(fondo,buffer,0,0,100,100,300,300);

    if ( mouse_x > 25 && mouse_x < 120 &&mouse_y > 555 && mouse_y < 630){
            if ( mouse_b & 1 ){
            hola=false;
              sleep(1);
              }//UP::::::::::::::::::::.
        }else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 52 && mouse_y < 102){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(5);
                }
        }
        //DOWN:::::::::::
        else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 545 && mouse_y < 595){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(5);
                }
        }//LEFT:::::::::::::::::::::::
        else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(0);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(1);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(2);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(3);
                }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(4);
            }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(5);
                }
        }//RIGHT:::::::::::::::::::::::::...
        else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(0);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(1);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(2);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(3);
                }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(4);
            }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(5);
                }
        }

        else{}
        int h=0;
        for(int i=0;i<6;i++)
            for(int j=0;j<6;j++){
            if(this->m[i][j]==m2[i][j])
               h++;
            }
        if(h==36){
            hola=false;
            for(int i=0;i<200;i++)
            textprintf(buffer,font,160,200,0xFFFFFF,"     HAS GANADO    ",8);

        }

         // posicion del boton
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);
        blit(buffer, screen, 0, 0, 0, 0, 1138, 640);

    }


    }

    void zen(){
    Juego *obj3;
    int **m;
    m=new int*[6];
    for(int i=0;i<6;i++)
        m[i]=new int[6];
    srand(time(NULL));
    obj3=new Juego(m,0);
    obj3->llenarmat(5);
    obj3->zen_juego();

    }

    void Juego::zen_juego(){
    install_mouse();
install_keyboard();
set_color_depth(32);
set_gfx_mode(GFX_AUTODETECT_WINDOWED, 1138, 640, 0, 0);
	BITMAP *buffer = create_bitmap(1138, 640);
    BITMAP *fondo;
    BITMAP *fondo2;
    BITMAP *fondo1;
    BITMAP *circulo;
	BITMAP *bolis;
	BITMAP *bola;
	BITMAP *cursor;
	bool bola1=true,bola2=true;
    bool salida=true;
    bool elimi=false;
    bool salida2=true;
	// inicializa las variables
	clear_to_color(buffer, 0x333333);
	fondo2=load_bitmap("Tablero alone.bmp",NULL);
	fondo1=load_bitmap("Tablero alone2.bmp",NULL);
	fondo = load_bitmap("Tablero alone.bmp",NULL);
	circulo = load_bitmap("explo.bmp",NULL);
	bolis=load_bitmap("bolitas4.bmp",NULL);
	cursor=load_bitmap("cursor.bmp",NULL);
     int **aux=new int*[6];
    for(int i=0;i<6;i++)
    aux[i]=new int[6];
	while(salida==true){
    //textprintf(fondo,font,160,200,0xFFFFFF,"  %d  ",this->score);
    if(score>1000 &&score<2000&&bola1==true){
    llenarmat(6);
    bola1=false;
    }else if(score>2000&&bola2==true){
    llenarmat(7);
    bola2=false;
    }
	elimi=false;
	if ( mouse_x > 25 && mouse_x < 120 &&mouse_y > 555 && mouse_y < 630){
            if ( mouse_b & 1 ){
            salida=false;
              sleep(1);
              }//UP::::::::::::::::::::.
        }else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 52 && mouse_y < 102){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              UP(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 52 && mouse_y < 102){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                UP(5);
                }
        }
        //DOWN:::::::::::
        else if(mouse_x > 590 && mouse_x < 640 &&mouse_y > 545 && mouse_y < 595){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(0);
              }
        }else if(mouse_x > 652 && mouse_x < 702 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(1);
              }
        }else if(mouse_x > 713 && mouse_x < 763 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              DOWN(2);
              }
        }else if(mouse_x > 773 && mouse_x < 824 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(3);
                }
        }else if(mouse_x > 837 && mouse_x < 887 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(4);
            }
        }else if(mouse_x > 897 && mouse_x < 948 &&mouse_y > 545 && mouse_y < 595){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                DOWN(5);
                }
        }//LEFT:::::::::::::::::::::::
        else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(0);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(1);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              LEFT(2);
              }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(3);
                }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(4);
            }
        }else if(mouse_x > 505 && mouse_x < 555 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                LEFT(5);
                }
        }//RIGHT:::::::::::::::::::::::::...
        else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 139 && mouse_y < 185){
              if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(0);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 199 && mouse_y < 250){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(1);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 260 && mouse_y < 310){
            if ( mouse_b & 1 ){
              sleep(1);elimi=true;
              RIGHT(2);
              }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 325 && mouse_y < 375){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(3);
                }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 389 && mouse_y < 438){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(4);
            }
        }else if(mouse_x > 995 && mouse_x < 1045 &&mouse_y > 450 && mouse_y < 500){
            if ( mouse_b & 1 ){
                sleep(1);elimi=true;
                RIGHT(5);
                }
        }

        else{}

        if(elimi==true){
        do{

        b=true;
        aux=this->getmat();
        for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
        verificar=0;
        if(aux[i][j]!=0)
            temporal=aux[i][j];
        else
            temporal=-1;
        MatrizSP(i,j,0,temporal);

        }
    }

    for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
        else
            masked_blit(circulo,buffer,0,0,l,k,53,53); ////////////////////////EXPLOSION PERRO


    }
    }
         // posicion del boton
           // textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
               // textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    }
    if(score<1000){
         recorrer(5);

     for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else
            masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
           // textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
    }
     }
    else if(score>1000&&score<2000){
     recorrer(6);
          for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else
            masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
          //  textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
    }
     }
    else if(score>2000){
          for(int q=0;q<100;q++){
    if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else
            masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::

              //  textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);

    }
     recorrer(7);

    }

    }while(b==false);
    }
           if(score<1000)
            blit(fondo, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=1000 && score<2000)
            blit(fondo1, buffer, 0, 0, 0, 0, 1138, 640);
        else if(score>=2000)
            blit(fondo2, buffer, 0, 0, 0, 0, 1138, 640);


    for(int i=0,k=150;i<6;i++,k+=57){
        for(int j=0,l=600;j<6;j++,l+=57){
      //  blit(bolis,buffer,0,0,i*80,j*80,80,70);
        if(this->m[i][j]==1)
            masked_blit(bolis,buffer,0,0,l,k,53,53);
        else if(this->m[i][j]==2)
            masked_blit(bolis,buffer,55,0,l,k,53,53);
         else if(this->m[i][j]==3)
            masked_blit(bolis,buffer,110,0,l,k,53,53);
         else if(this->m[i][j]==4)
            masked_blit(bolis,buffer,164,0,l,k,53,53);
         else if(this->m[i][j]==5)
            masked_blit(bolis,buffer,220,0,l,k,53,53);
         else if(this->m[i][j]==6)
            masked_blit(bolis,buffer,275,0,l,k,53,53);
         else if(this->m[i][j]==7)
            masked_blit(bolis,buffer,330,0,l,k,53,53);
         else
            masked_blit(bolis,buffer,385,0,l,k,53,53);


    }
    }
         // posicion del boton
           // textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);
         // pinta el cursor
         masked_blit(cursor, buffer, 0, 0, mouse_x, mouse_y, 13,22);

         // se muestra todo por pantalla

       //   if ( key[KEY_ESC] )
         //      salida = false;

         //Para entrar a eliminar matriz//:::::::::::::::::::::::::::::::::


    blit(buffer, screen, 0, 0, 0, 0, 1138, 640);
           // textprintf(buffer,font,160,200,0xFFFFFF,"  %d  ",this->score);

    }
    destroy_bitmap(bolis);
    destroy_bitmap(buffer);
	destroy_bitmap(fondo);
    destroy_bitmap(fondo1);
    destroy_bitmap(fondo2);
	destroy_bitmap(cursor);

    }
