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

  long long total_kop = ((long long)p.hryvnia * 100 + p.kopiyka) * n;
  p.hryvnia = (int)(total_kop / 100);
  p.kopiyka = (short)(total_kop % 100);
}

void round_price(Price &p) {

  int units = p.kopiyka % 10;

  if (units <= 4) {
    p.kopiyka = (short)(p.kopiyka - units);
  } else {
    p.kopiyka = (short)(p.kopiyka + (10 - units));
  }

  normalize(p);
}

void print_price(Price p, const char *label) {
  if (label) {
    printf("%s: ", label);
  }
  printf("%d грн %02d коп.\n", p.hryvnia, (int)p.kopiyka);
}