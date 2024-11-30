#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#include "conio.h"

#define HAUPTMENÜ 1
#define SPIEL 2

//Menue
int Hauptmenü();
void Einstellungen();
void Anleitung();
void Credits();

//Spielmechanik
int Spiel();
void Auswertung(int möglich [14], int Wurf [5], int Zahlen [7]);
void Liste(int Zahlen [7], int Wurf[5], int möglich [7]);
void print(int Auswahl);//Gibt einen durch eine Konstante festgelegten Bildschirm aus
void Würfeln (int Wurf [5], int Punkte [14], int gesamt);
void printg(int Auswahl, int Punkte [14], int Wurf[5], int Würfelcodes [7] [7]);



// hat mich sehr gefreut, mit dir zu coden
// - Max 03.05. 2024

// falls du das jemals lesen solltest,
// schreib irgendwas dazu :D



int main()
{          
  
  while (true)
  {
    switch (Hauptmenü())        //Auswahl in der Hauptmenü Funktion
    {
      case 1 : Spiel();     
      break;
      
      case 2 : Einstellungen();
      break;

      case 3 : Anleitung();   
      break;

      case 4 : Credits();     
      break;

      case 5 : return 0;
      break;
    }

  }

} 



int Spiel ()
{
  if(1);    // zeigt die Spiel Funktion am rechten Rand an - Dauerschleife?- Sergej    
            // Nein, eine Bedingung ohne Körper, macht also genau gar nichts.  - Max

  int Wurf [5];
  int Auswahl;
  int möglich [14];
  int Punkte [14];
  int gesamt;
  char Würfelcodes [7] [7];

  for (int i = 0; i < 14; i++)
      Punkte [i] = 0;

  
      printf("\t\t                                                                                                              \n");
      printf("\t\t  _______________________________________________                                                             \n");
      printf("\t\t  |                     _   _                    |                                                            \n");
      printf("\t\t  |     | /    _    ° _/_ _/_   ___   |          |                                                            \n");
      printf("\t\t  |     |/   |/  \\  |  |   |   /___\\  |          |                                                          \n");
      printf("\t\t  |     | \\  |   |  |  |   |   \\___   |__        |                                                          \n");
      printf("\t\t  |    ====================================      |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (01)   1er           :     [ %2d ]  /  5    |                                                            \n", Punkte[0]);
      printf("\t\t  |  (02)   2er           :     [ %2d ]  /  10   |                                                            \n", Punkte[1]);
      printf("\t\t  |  (03)   3er           :     [ %2d ]  /  15   |                                                            \n", Punkte[2]);
      printf("\t\t  |  (04)   4er           :     [ %2d ]  /  20   |                                                            \n", Punkte[3]);
      printf("\t\t  |  (05)   5er           :     [ %2d ]  /  25   |                                                            \n", Punkte[4]);
      printf("\t\t  |  (06)   6er           :     [ %2d ]  /  30   |                                                            \n", Punkte[5]);
      printf("\t\t  |  (07)   Bonus         :     [ %2d ]  /  35   |                                                            \n", Punkte[6]);
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (08)   Drilling      :     [ %2d ]  /  18   |                                                            \n", Punkte[7]);
      printf("\t\t  |  (09)   Vierling      :     [ %2d ]  /  24   |                                                            \n", Punkte[8]);
      printf("\t\t  |  (10)   Fullhouse     :     [ %2d ]  /  28   |                                                            \n", Punkte[9]);
      printf("\t\t  |  (11)   kl. Straße    :     [ %2d ]  /  30   |                                                            \n", Punkte[10]);
      printf("\t\t  |  (12)   gr. Straße    :     [ %2d ]  /  40   |                                                            \n", Punkte[11]);
      printf("\t\t  |  (13)   Kniffel       :     [ %2d ]  /  50   |                                                            \n", Punkte[12]);
      printf("\t\t  |  (14)   Chance        :     [ %2d ]  /  30   |                                                            \n", Punkte[13]);
      printf("\t\t  |     _________________________________        |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |         Gesamt        :     [    ]  / 378   |                                                            \n");
      printf("\t\t  |______________________________________________|                                                            \n");


  
  for (int i = 1; i <= 12; i++)
  {
     
      //Auswahl();

      printf("\t\t                                                                                                             \n");
      printf("\t\t  _______________________________________________                                                            \n");
      printf("\t\t  |                     _   _                    |                                                            \n");
      printf("\t\t  |     | /    _    ° _/_ _/_   ___   |          |                                                            \n");
      printf("\t\t  |     |/   |/  \\  |  |   |   /___\\  |          |                                                          \n");
      printf("\t\t  |     | \\  |   |  |  |   |   \\___   |__        |         Drücke eine beliebige Taste um zu würfeln        \n");
      printf("\t\t  |    ====================================      |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (01)   1er           :     [ %2d ]  /  5    |                                                            \n", Punkte[0]);
      printf("\t\t  |  (02)   2er           :     [ %2d ]  /  10   |                                                            \n", Punkte[1]);
      printf("\t\t  |  (03)   3er           :     [ %2d ]  /  15   |                                                            \n", Punkte[2]);
      printf("\t\t  |  (04)   4er           :     [ %2d ]  /  20   |                                                            \n", Punkte[3]);
      printf("\t\t  |  (05)   5er           :     [ %2d ]  /  25   |                                                            \n", Punkte[4]);
      printf("\t\t  |  (06)   6er           :     [ %2d ]  /  30   |                                                            \n", Punkte[5]);
      printf("\t\t  |  (07)   Bonus         :     [ %2d ]  /  35   |                                                            \n", Punkte[6]);
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (08)   Drilling      :     [ %2d ]  /  18   |                                                            \n", Punkte[7]);
      printf("\t\t  |  (09)   Vierling      :     [ %2d ]  /  24   |                                                            \n", Punkte[8]);
      printf("\t\t  |  (10)   Fullhouse     :     [ %2d ]  /  28   |                                                            \n", Punkte[9]);
      printf("\t\t  |  (11)   kl. Straße    :     [ %2d ]  /  30   |                                                            \n", Punkte[10]);
      printf("\t\t  |  (12)   gr. Straße    :     [ %2d ]  /  40   |                                                            \n", Punkte[11]);
      printf("\t\t  |  (13)   Kniffel       :     [ %2d ]  /  50   |                                                            \n", Punkte[12]);
      printf("\t\t  |  (14)   Chance        :     [ %2d ]  /  30   |                                                            \n", Punkte[13]);
      printf("\t\t  |     _________________________________        |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |         Gesamt        :     [   ]  / 378   |                                                            \n");
      printf("\t\t  |______________________________________________|                                                            \n");

      Würfeln(Wurf, Punkte, gesamt);

      int Zahlen [7];

      Auswertung(möglich, Wurf, Zahlen);

      gotoxy(67, 20);
      printf("Wo möchtest du deine Punkte eintragen?                         ");
      gotoxy(107, 20);
      scanf("%d", &Auswahl);

      Punkte [Auswahl - 1] = möglich [Auswahl - 1];
      
      for (int i = 0, gesamt = 0; i < 14; i++)
      {
          gesamt += Punkte[i];
      }

  }

  sleep(10);
  
  return 0;
}




void Einstellungen()
{

}

void Anleitung()
{

}

void Credits()
{
  system("clear");
  gotoxy(50, 10);

  textcolor(7);

  
  gotoxy(50, 10);     printf("======================================================");
  gotoxy(50, 11);     printf("||    ---------------  Kniffel  ---------------     ||");
  gotoxy(50, 12);     printf("||==================================================||");
  gotoxy(50, 13);     printf("||                                                  ||");
  gotoxy(50, 14);     printf("||    Dieses Spiel wurde erstellt von :             ||");
  gotoxy(50, 15);     printf("||                                                  ||");
  gotoxy(50, 16);     printf("||         Maximilian Schnell-Birgmann              ||");
  gotoxy(50, 17);     printf("||         Sergej Steinsiek                         ||");
  gotoxy(50, 18);     printf("||                                                  ||");
  gotoxy(50, 19);     printf("||                                                  ||");
  gotoxy(50, 10);     printf("||    Vom           23. 12. 2021                    ||");
  gotoxy(50, 11);     printf("||    Bis zum       27. 03. 2024                    ||");
  gotoxy(50, 12);     printf("||                                                  ||");
  gotoxy(50, 13);     printf("||==================================================||");
  gotoxy(50, 14);     printf("||     ---------------  Kniffel  ---------------    ||");
  gotoxy(50, 15);     printf("======================================================");


  //delay(10000);
  sleep(10);
  
  system("clear");
}


void Würfeln(int Wurf [5], int Punkte [14], int gesamt)
{
  srand ((unsigned) time (NULL));

  if (1);
  int test;


  int behalten [5];
  behalten [0] = 0;
  behalten [1] = 0;
  behalten [2] = 0;
  behalten [3] = 0;
  behalten [4] = 0;
  int behaltene = 5;

  int Würfelposition [5] [2];

  Würfelposition [0] [0] = 67;      Würfelposition [0] [1] = 6;
  Würfelposition [1] [0] = 82;      Würfelposition [1] [1] = 6;
  Würfelposition [2] [0] = 97;      Würfelposition [2] [1] = 6;
  Würfelposition [3] [0] = 74;      Würfelposition [3] [1] = 12;
  Würfelposition [4] [0] = 90;      Würfelposition [4] [1] = 12;


  char Würfelcodes [7] [7];

  /*
      ------Würfelcodes-------
      ========================


    Im Array Würfelcodes wird
    jedem Punkt am Würfel ein
    Platz zugeteilt, der entweder
    den Wert '*' hat oder leer ist.

    _________          _________
    | *   * |          | 0   1 |
    | * * * |          | 2 3 4 |
    |_*___*_|          |_5___6_|


    In jeder Zeile wird das Aussehen
    des Würfels bei einer bestimmten
    Zahl festgelegt :

    Würfelcodes [1] [3] = *;

    Erklärung:
    Falls eine 1 gewürfelt wird, 
    soll nur an Position 3 ein
    Punkt angezeigt werden.
  */

  Würfelcodes [0] [0] = ' ';       Würfelcodes [1] [0] = ' ';       Würfelcodes [2] [0] = '*';       Würfelcodes [3] [0] = ' ';
  Würfelcodes [0] [1] = ' ';       Würfelcodes [1] [1] = ' ';       Würfelcodes [2] [1] = ' ';       Würfelcodes [3] [1] = '*';
  Würfelcodes [0] [2] = ' ';       Würfelcodes [1] [2] = ' ';       Würfelcodes [2] [2] = ' ';       Würfelcodes [3] [2] = ' ';
  Würfelcodes [0] [3] = ' ';       Würfelcodes [1] [3] = '*';       Würfelcodes [2] [3] = ' ';       Würfelcodes [3] [3] = '*';
  Würfelcodes [0] [4] = ' ';       Würfelcodes [1] [4] = ' ';       Würfelcodes [2] [4] = ' ';       Würfelcodes [3] [4] = ' ';
  Würfelcodes [0] [5] = ' ';       Würfelcodes [1] [5] = ' ';       Würfelcodes [2] [5] = ' ';       Würfelcodes [3] [5] = '*';
  Würfelcodes [0] [6] = ' ';       Würfelcodes [1] [6] = ' ';       Würfelcodes [2] [6] = '*';       Würfelcodes [3] [6] = ' ';


  Würfelcodes [4] [0] = '*';       Würfelcodes [5] [0] = '*';       Würfelcodes [6] [0] = '*';
  Würfelcodes [4] [1] = '*';       Würfelcodes [5] [1] = '*';       Würfelcodes [6] [1] = '*';
  Würfelcodes [4] [2] = ' ';       Würfelcodes [5] [2] = ' ';       Würfelcodes [6] [2] = '*';
  Würfelcodes [4] [3] = ' ';       Würfelcodes [5] [3] = '*';       Würfelcodes [6] [3] = ' ';
  Würfelcodes [4] [4] = ' ';       Würfelcodes [5] [4] = ' ';       Würfelcodes [6] [4] = '*';
  Würfelcodes [4] [5] = '*';       Würfelcodes [5] [5] = '*';       Würfelcodes [6] [5] = '*';
  Würfelcodes [4] [6] = '*';       Würfelcodes [5] [6] = '*';       Würfelcodes [6] [6] = '*';

  for (int i = 0; i < 5; i++)
  {
    Wurf [i] = 0;
  }

      system("clear");

      printf("\t\t                                                                                                              \n");
      printf("\t\t  _______________________________________________                                                             \n");
      printf("\t\t  |                     _   _                    |                                                            \n");
      printf("\t\t  |     | /    _    ° _/_ _/_   ___   |          |                                                            \n");
      printf("\t\t  |     |/   |/  \\  |  |   |   /___\\  |          |    Gib ein beliebiges Zeichen ein, um zu würfeln :       \n");
      printf("\t\t  |     | \\  |   |  |  |   |   \\___   |__        |                                                          \n");
      printf("\t\t  |    ====================================      |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (01)   1er           :     [ %2d ]  /  5     |                                                            \n", Punkte[0]);
      printf("\t\t  |  (02)   2er           :     [ %2d ]  /  10    |                                                            \n", Punkte[1]);
      printf("\t\t  |  (03)   3er           :     [ %2d ]  /  15    |                                                            \n", Punkte[2]);
      printf("\t\t  |  (04)   4er           :     [ %2d ]  /  25    |                                                            \n", Punkte[3]);
      printf("\t\t  |  (05)   5er           :     [ %2d ]  /  30    |                                                            \n", Punkte[4]);
      printf("\t\t  |  (06)   6er           :     [ %2d ]  /  35    |                                                            \n", Punkte[5]);
      printf("\t\t  |  (07)   Bonus         :     [ %2d ]  /  35    |                                                            \n", Punkte[6]);
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |  (08)   Drilling      :     [ %2d ]  /  18    |                                                            \n", Punkte[7]);
      printf("\t\t  |  (09)   Vierling      :     [ %2d ]  /  24    |                                                            \n", Punkte[8]);
      printf("\t\t  |  (10)   Fullhouse     :     [ %2d ]  /  28    |                                                            \n", Punkte[9]);
      printf("\t\t  |  (11)   kl. Straße    :     [ %2d ]  /  30    |                                                            \n", Punkte[10]);
      printf("\t\t  |  (12)   gr. Straße    :     [ %2d ]  /  40    |                                                            \n", Punkte[11]);
      printf("\t\t  |  (13)   Kniffel       :     [ %2d ]  /  50    |                                                            \n", Punkte[12]);
      printf("\t\t  |  (14)   Chance        :     [ %2d ]  /  30    |                                                            \n", Punkte[13]);
      printf("\t\t  |     _________________________________        |                                                            \n");
      printf("\t\t  |                                              |                                                            \n");
      printf("\t\t  |         Gesamt        :     [   ]  / 378     |                                                            \n");
      printf("\t\t  |______________________________________________|                                                            \n");


      
      cursoron();
      gotoxy(111, 5);
      scanf("%d", &test);


    for (int j = 0; j < 3; j++)
    {

      
      for (int h = 0; h < 5; h++)
      {
        if (behalten [h] != 1)
        {
          Wurf [h] = (rand() % 6) + 1;

          gotoxy(Würfelposition[h] [0], Würfelposition [h] [1]);
          printf("_________");
          gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 1);
          printf("| %c   %c |", Würfelcodes[Wurf[h]] [0], Würfelcodes[Wurf[h]] [1]);
          gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 2);
          printf("| %c %c %c |", Würfelcodes[Wurf[h]] [2], Würfelcodes[Wurf[h]] [3], Würfelcodes[Wurf[h]] [4]);
          gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 3);
          printf("|_%c___%c_|", Würfelcodes[Wurf[h]] [5], Würfelcodes[Wurf[h]] [6]);
          textcolor(7);

          delay(100);
        }
      }


      if (j < 2)
      {
          for (int h = 0; h < 6; h++)
          {

              gotoxy(70, 20);
              printf("Würfel %d behalten (1 = ja, 2 = nein) ? :  \b", h + 1);
              scanf("%d", &behalten[h]);
            

              if (behalten [h] == 1)
              {
                textcolor(4);
                behaltene--;
              }

              else
              {
                Wurf[h] = 0;
              }
              
              if ( h < 5)
              {
              gotoxy(Würfelposition[h] [0], Würfelposition [h] [1]);
              printf("_________");
              gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 1);
              printf("| %c   %c |", Würfelcodes[Wurf[h]] [0], Würfelcodes[Wurf[h]] [1]);
              gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 2);
              printf("| %c %c %c |", Würfelcodes[Wurf[h]] [2], Würfelcodes[Wurf[h]] [3], Würfelcodes[Wurf[h]] [4]);
              gotoxy(Würfelposition[h] [0], Würfelposition [h] [1] + 3);
              printf("|_%c___%c_|", Würfelcodes[Wurf[h]] [5], Würfelcodes[Wurf[h]] [6]);
              }
              textcolor(7);
              
            }
            
          int g;
          for (int i = 0, g = 0; i < 5; i++)
          {
            if (behalten [i] == 1)
            {
              g++;
            }
          }

      }
      
    }

}



void Auswertung(int möglich [14], int Wurf [5], int Zahlen [7])
{
  if(1);


  Zahlen [1] = 0;
  Zahlen [2] = 0;
  Zahlen [3] = 0;
  Zahlen [4] = 0;
  Zahlen [5] = 0;
  Zahlen [6] = 0;


  for (int i = 0; i < 14; i++)    //Zurücksetzten des Wurfes
  {
    möglich [i] = 0;
  }

  
  for (int i = 0; i < 5; i++)   //Auswerten des Wurfes
  {
    for (int j = 1; j <= 6; j++)
    {
      if (Wurf [i] == j)   Zahlen [j] ++;
    }
  }  


  for (int i = 0; i < 6; i++)     //1er, 2er, 3er, 4er, 5er, 6er
  {
    möglich [i] = Zahlen [i + 1] * (i + 1);
  }

  if ( möglich [0] + möglich [1] + möglich [2] + möglich [3] + möglich [4] + möglich [5] >= 63)
  {
    möglich [6] = 35;
  }


  for (int i = 0; i < 5; i++)    //Drilling
  {
    if (Zahlen [i +1] >= 3)
        möglich [7] = (i + 1) * 3;
  }

  for (int i = 0; i < 5; i++)    //Vierling
  {
    if (Zahlen [i] >= 4)
        möglich [8] = (i + 1) * 4;
  }

  for (int i = 0; i < 5; i++)     //Fullhouse, fehlerhaft 
  {
    if (Zahlen [i] == 3)
    {
      for (int j = 0; j < 5; j++)
      {
        if (Zahlen [j] == 2)
            möglich [9] = ((i + 1) * 3) + ((j + 1) * 2);
      }
    }
  }

  if ( Zahlen[1] > 0 && Zahlen[2] > 0 && Zahlen[3] > 0 && Zahlen[4] > 0)  möglich [10] = 30;     //kleine Straße
  if ( Zahlen[2] > 0 && Zahlen[3] > 0 && Zahlen[4] > 0 && Zahlen[5] > 0)  möglich [10] = 30;
  if ( Zahlen[3] > 0 && Zahlen[4] > 0 && Zahlen[5] > 0 && Zahlen[6] > 0)  möglich [10] = 30;

  if ( Zahlen[1] > 0 && Zahlen[2] > 0 && Zahlen[3] > 0 && Zahlen[4] > 0 && Zahlen [5] > 0)  möglich [11] = 40;     //große Straße
  if ( Zahlen[2] > 0 && Zahlen[3] > 0 && Zahlen[4] > 0 && Zahlen[5] > 0 && Zahlen [6] > 0)  möglich [11] = 40;


  for (int i = 0; i < 5; i++)    // Kniffel
  {
    if (Zahlen [i] >= 5)
        möglich [12] = 50;
  }

  möglich [13] = Wurf [0] + Wurf [1] + Wurf [2] + Wurf [3] + Wurf[4];    //Chance
  
}



int Hauptmenü()
{

  cursoroff();
  system("clear"); 

  print(HAUPTMENÜ);

  const char Spielstart [] = {"Spiel starten"};
  const char Einstellungen [] = {"Einstellungen"};
  const char Anleitung [] = {"Anleitung"};
  const char Credits [] = {"Credits"};
  const char Ende [] = {"Ende"};

  char Optionen [5] [20];
  strcpy(Optionen [0], Spielstart);
  strcpy(Optionen [1], Einstellungen);
  strcpy(Optionen [2], Anleitung);
  strcpy(Optionen [3], Credits);
  strcpy(Optionen [4], Ende);

  int Auswahl;

  gotoxy(32, 19);
  cursoron();

  scanf("%d", &Auswahl);

  cursoroff();

  gotoxy (32, 19);  
  
  

  delay (1000);

  return Auswahl;
}



void Voreinstellungen(char name[25])
{
  system("clear"); //system("cls"); -> Fehler (compiler:clang)

  printf("Gib dir einen Namen:\n");
  fgets(name, 25, stdin);
  name[strlen(name)-1]='\0';

  sleep(1);
}



void print(int Auswahl)
{

  switch (Auswahl)
  {
      
  case HAUPTMENÜ :

      system("clear");

      textcolor(4);

      printf("\t\t                       _   _                                                                                \n");
      printf("\t\t       | /    _    ° _/_ _/_   ___   |                                                                      \n");
      printf("\t\t       |/   |/  \\  |  |   |   /___\\  |                                                                    \n");
      printf("\t\t       | \\  |   |  |  |   |   \\___   |__                                                                  \n");
      printf("\t\t      ====================================                                                                  \n");
      printf("\t\t                                                                                                            \n");

      textcolor(15);

      printf("\t           Willkommen im Hauptmenue!                                                                                     \n");
      printf("\t           Was moechtest du tun?                                                                                         \n");
      printf("\t                                                                                                                         \n");
      printf("\t                                                                                                                         \n");

      printf("\t                                                                                                    \n");
      printf("\t           [1]     Spiel starten                                                                                                              \n");
      printf("\t           [2]     Einstellungen                                                                                         \n");
      printf("\t           [3]     Credits                                                                                               \n");
      printf("\t           [4]     Spielregeln                                                                                                         \n");
      printf("\t           [5]     Verlassen                                                                                                         \n");
      printf("\t                                                                                                                         \n");
      printf("\t                                                                                                                         \n");
      printf("\t           Deine Auswahl [   ]                                                                                           \n");

      break;


    }
}





/*Credits umschreiben*/
