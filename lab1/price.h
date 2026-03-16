#ifndef PRICE_H
#define PRICE_H

struct Price {
  int hryvnia;
  short int kopiyka;
};

void normalize(Price &p);

void add(Price &a, Price b);

void multiply(Price &p, int n);

void round_price(Price &p);

void print_price(Price p, const char *label = nullptr);

#endif
