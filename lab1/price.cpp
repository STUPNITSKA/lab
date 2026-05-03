#include "price.h"
#include <cstdio>
#include <windows.h>

void normalize(Price &p) {
  if (p.kopiyka >= 100) {
    p.hryvnia += p.kopiyka / 100;
    p.kopiyka = p.kopiyka % 100;
  }
  if (p.kopiyka < 0) {
    p.kopiyka = 0;
  }
}

void add(Price &a, Price b) {
  a.hryvnia += b.hryvnia;
  a.kopiyka += b.kopiyka;
  normalize(a);
}

void multiply(Price &p, int n) {
  p.hryvnia *= n;
  p.kopiyka *= n;
  normalize(p);
}

void round_price(Price &p) {
  int r = p.kopiyka % 10;
  if (r <= 4) {
    p.kopiyka -= r;
  } else {
    p.kopiyka += (10 - r);
  }
  normalize(p);
}

void print_price(Price p, const char *text)
{
  printf("%s: %d грн %02d коп.\n", text, p.hryvnia, p.kopiyka);
}


void print_result() {

  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  FILE *fp = nullptr;

  if (fopen_s(&fp, "input.txt", "r") != 0 )
  {
    printf("Помилка відкриття файлу\n");
    return;
  }

  Price total = {0, 0};

  int hrn, qty;
  short int kop;

  while (fscanf_s(fp, "%d %hd %d", &hrn, &kop, &qty) == 3) {

    Price line = {hrn, kop};

    multiply(line, qty);

    add(total, line);

  }

  fclose(fp);

  print_price(total, "Загальна сума");


  round_price(total);

  print_price(total, "До оплати (заокруглено)");

}