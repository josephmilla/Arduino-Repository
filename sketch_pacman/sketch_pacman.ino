/**
* Name: Pacman LCD Display
* Author: Joseph Milla
* Author URI: http://www.josephmilla.com
* Version: 1.0.0
* Tag: Arduino, Pacman
*/

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//CUSTOM CHARACTERS
byte pac1Def[8] = {
  0b00000,
  0b01110,
  0b11011,
  0b11111,
  0b11111,
  0b01110,
  0b00000,
  0b00000
};
byte pac2Def[8] = {
  0b00000,
  0b01110,
  0b10100,
  0b11000,
  0b11100,
  0b01110,
  0b00000,
  0b00000
};
byte pillDef[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b01100,
  0b01100,
  0b00000,
  0b00000,
  0b00000
};

byte p[8] = {31, 31, 29, 31, 31, 28, 28};
byte a[8] = {14, 27, 27, 31, 27, 27, 27};
byte c[8] = {14, 27, 24, 24, 24, 27, 14};
byte m[8] = {17, 27, 31, 31, 31, 27, 27};
byte n[8] = {17, 25, 29, 31, 31, 19, 17};

const byte pac1 = 0x0;
const byte pac2 = 0x1;
const byte pill = 0x2;
const int del = 250;

int x = 0;
int y = 1;
int posx = 0;
int posy = 1;

void setup() {
  lcd.createChar(0, pac1Def);
  lcd.createChar(1, pac2Def);
  lcd.createChar(2, pillDef);
  lcd.begin(16, 2);
  fill();
  
  lcd.createChar(3, p);
  lcd.createChar(4, a);
  lcd.createChar(5, c);
  lcd.createChar(6, m);
  lcd.createChar(7, n);
  
  lcd.setCursor(5, 0);
  lcd.print((char)3);
  lcd.print((char)4);
  lcd.print((char)5);
  lcd.print((char)6);
  lcd.print((char)4);
  lcd.print((char)7);
}

void fill()
{
 lcd.setCursor(0, 1);
 lcd.write(pill);
 for(int i = 0; i < 7; i++)
 {
   lcd.write(" ");
   lcd.write(pill);
 }
}

void animation()
{
  lcd.setCursor(posx,posy);
  lcd.write(" ");
  lcd.setCursor(x,y);
  lcd.write(pac1);
  delay(del);
  lcd.setCursor(x,y);
  lcd.write(pac2);
  
  delay(del);
  posx = x;
  posy = y;
}

void loop() 
{
  animation();
  x++;
  
  if(x > 15 && y == 0)
  {
    x = 0;
    y = 1;
  }
  else if(x > 15 && y == 1)
  {
    x = 0;
    y = 1;
    fill();
  }
}
