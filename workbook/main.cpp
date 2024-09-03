#include <iostream>
#include <clocale>
#include <stdio.h>
#include "task1.h"
#include "task2.h"



int main(){
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    task1();
    task2();
    return 0;
}

