#include "price.h"
#include <cstdio>
#include <cstdlib>
#include <windows.h>

int main() {

  SetConsoleOutputCP(65001);
  SetConsoleCP(65001);
  FILE *fp = nullptr;
  errno_t err = fopen_s(&fp, "input.txt", "r");

  if (err != 0 || fp == nullptr) {
    printf("Помилка: не вдалося відкрити файл input.txt\n");
    return 1;
  }

  Price total = {0, 0};

  int hrn, kop, qty;
  int item_num = 0;

  printf("%-5s %-20s %-3s %-16s %s\n", "№", "Ціна", "Кіл", "Сума за позиц.",
         "");
  printf("------------------------------------------------------------\n");

  while (fscanf_s(fp, "%d %d %d", &hrn, &kop, &qty) == 3) {
    item_num++;

    Price line_total = {hrn, (short)kop};
    multiply(line_total, qty);

    printf("%-5d %3d грн %02d коп.  x%d  →  ", item_num, hrn, kop, qty);
    print_price(line_total);

    add(total, line_total);
  }

  fclose(fp);

  if (item_num == 0) {
    printf("Файл порожній або дані мають неправильний формат.\n");
    return 1;
  }

  printf("------------------------------------------------------------\n");
  print_price(total, "Загальна сума");

  Price rounded = total;
  round_price(rounded);
  print_price(rounded, "До оплати (заокруглено)");

  return 0;
}