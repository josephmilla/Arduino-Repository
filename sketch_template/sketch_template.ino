/**
* Name: Piezo Music Template
* Author: Joseph Milla
* Author URI: http://www.josephmilla.com
* Version: 1.0.0
* Tag: Arduino, Piezzo Speakers
*/

//SPEAKER (PWM pin)
int speakerPin = 11;
//LED (Use pin 13 for built-in LED)
int ledPin = 13;

//FREQUENCIES
#define cL 129
#define cLS 139
#define dL 146
#define dLS 156
#define eL 163
#define fL 173
#define fLS 185
#define gL 194
#define gLS 207
#define aL 219
#define aLS 228
#define bL 232

#define c 261
#define cS 277
#define d 294
#define dS 311
#define e 329
#define f 349
#define fS 370
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466

#define cH 523
#define cHS 554
#define dH 587
#define dHS 622
#define eH 659
#define fH 698
#define fHS 740
#define gH 784
#define gHS 830
#define aH 880
#define aHS 910
#define bH 933

void setup()
{
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
}

void beep (int speakerPin, int freqHz, long timeMs)
{
  digitalWrite(ledPin, HIGH);
  
  double timeDelay = (double)(1000000/freqHz);
  double timeLoop = (double)((timeMs*1000)/(timeDelay*2));
  
  for(int i = 0; i < timeLoop; i++)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(timeDelay);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(timeDelay);
  }
  
  digitalWrite(ledPin, LOW);
  delay(20);
}

void playTone()
{
  beep(speakerPin, a, 500); 
  delay(250);
}

void loop()
{
  playTone();
}
