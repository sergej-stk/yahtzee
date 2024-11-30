//
// F.Matejka 2021
// conio Funktionen für repl.it
//

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

void cinit();
void cdeinit();
void cursoroff();
void cursoron();
void delay (unsigned long milliseconds);
void gotoxy (int x, int y);
void clrscr();
void draw_box(int x, int y, int w, int h);
void textcolor (int newcolor);
int kbhit();


// helper functions

/*
Zwei modes ausschalten 
ECHO echo mode
ICANON canonical mode - 
    In noncanonical mode input is available immediately (without the
    user having to type a line-delimiter character), no input
    processing is performed, and line editing is disabled.
*/
void changemode(int dir)
{
  static struct termios oldt, newt;

  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    // switch off: echo + canonical mode
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}

void cinit()
{
  setbuf(stdout, NULL); // avoid flushing by deactivation of buffering
  changemode(1);
  cursoroff();
  clrscr();
}

void cdeinit()
{
  // TODO: buffering is not reset yet
  changemode(0);
  cursoron();
}

// kbhit  https://cboard.cprogramming.com/c-programming/63166-kbhit-linux.html
int kbhit()
{
  struct timeval tv;
  fd_set rdfs;

  tv.tv_sec = 0;
  tv.tv_usec = 0;

  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);

  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &rdfs);

}

void cursoroff()
{
    printf("\e[?25l"); /* hide the cursor */
}

void cursoron()
{
    printf("\e[?25h"); /* show the cursor */      
}

void gotoxy (int x, int y)
{
  printf("\033[%d;%dH", y, x);
}

void delay (unsigned long milliseconds)
{
  usleep ((useconds_t)(milliseconds * 1000));
}

void clrscr()
{
  	// CSI n J - Erase in Display
	printf("\x1b[2J");
}



int screen_height()
{
  // TODO: keine Lösungsmöglichkeit gefunden
  return 0;
}

int screen_width()
{
  // TODO: keine Lösungsmöglichkeit gefunden
  return 0;
}

void draw_box(int x, int y, int w, int h)
{
  gotoxy(x,y);
  printf("\u250F"); // ┏
  for(int xx=x+1; xx<x+w; xx++) {
    printf("\u2501"); // ━
  }
  printf("\u2513"); // ┓
  gotoxy(x,y+h-1);
  printf("\u2517"); // ┗
  for(int xx=x+1; xx<x+w; xx++) {
    printf("\u2501"); // ━
  }
  printf("\u251B"); // ┛
  for(int yy=y+1;yy<y+h-1;yy++) {
    gotoxy(x,yy);
    printf("\u2503"); // ┃
    gotoxy(x+w,yy);
    printf("\u2503"); // ┃
  }

}


// Vordergrundfarbe setzen
// Farbcode: 0,..,255
// Siehe Tabelle: https://en.wikipedia.org/wiki/ANSI_escape_code#8-bit
void textcolor (int newcolor)
{
    printf ("\x1b[38;5;%dm", newcolor);
}
