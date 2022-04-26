
//порты дисплея
#define CLK 19
#define DIO 18
//библиотека дисплея
#include "GyverTM1637.h"
//подключаем дисплей
GyverTM1637 disp(CLK, DIO);
//результат для вывода на дисплей
int result_to_display;
//пины входов по порядку от младшего разряда к старшему
byte ordersInputs[] = {2,3,4,5,6,7,8,9};

void setup() {
  //для отладки
  Serial.begin(9600);
  //конфигурируем пины как входы
  for (int j = 0; j < sizeof(ordersInputs);j++)
  {
    pinMode(ordersInputs[j], INPUT);
  }
  //настраиваем  и очищаем дисплей
  disp.brightness(7);
  disp.clear();
}

void loop() {
  
  result_to_display = 0;

  //побитно формируем результат
  for (int i = 0; i < sizeof(ordersInputs);i++)
  {
    result_to_display|=digitalRead(ordersInputs[i])<<i; 
  }
  //выводим на дисплей

  //Serial.println(result_to_display);
  //Serial.println(result_to_display,BIN);
  
  disp.displayInt(result_to_display); 
  //вывод 100 fps                       
  delay(200);
  
}
