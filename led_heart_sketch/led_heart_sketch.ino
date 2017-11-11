//  @autor = s.kulchanovskiy@gmail.com
//  @microcontroller = Atmega328p 

#include <OLED_I2C.h> //импорт библиотеки
OLED  myOLED(SDA, SCL, 8); //создаем экземпляр класса OLED с именем myOLED
extern uint8_t logo[];
extern uint8_t nelya[];
extern uint8_t message[];
extern uint8_t family[];

#define FLINE1_LED_PIN  2
#define LLINE1_LED_PIN  13

void display_logo(int pause){
    myOLED.clrScr();
    myOLED.drawBitmap(0, 0, logo, 128, 64);
    myOLED.update();
    delay(pause);
    for (int i=0; i<2; i++)
    {
      myOLED.invert(true);
      delay(500);
      myOLED.invert(false);
      delay(500);
    }
    delay(pause);
  }

void display_message(int pause){
    myOLED.clrScr();
    myOLED.drawBitmap(0, 0, nelya, 128, 64);
    myOLED.update();
    delay(500);
    myOLED.invert(true);
    delay(pause);
    myOLED.clrScr();
    myOLED.drawBitmap(0, 0, message, 128, 64);
    myOLED.update();
    delay(pause);
    myOLED.clrScr();
    myOLED.drawBitmap(0, 0, family, 128, 64);
    myOLED.update();
    delay(pause);
    myOLED.invert(false);
    delay(500);
  }

void led_on(){
    for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN; ++pin){
      digitalWrite(pin, HIGH);
    }
  }

void led_off(){
    for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN; ++pin){
      digitalWrite(pin, LOW);
    }
  }
  
void led_effect_1(int pause){
  for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN; ++pin){
      digitalWrite(pin, HIGH);
      delay(pause);
      digitalWrite(pin, LOW);
    }
    led_random();
  }

void led_effect_2(int pause){
  for (int pin = FLINE1_LED_PIN; pin <= 7; ++pin){
      digitalWrite(pin, HIGH);
      digitalWrite(pin+6, HIGH);
      delay(pause);
    }
    led_random();
  for (int pin = FLINE1_LED_PIN; pin <= 7; ++pin){
      digitalWrite(pin, LOW);
      digitalWrite(pin+6, LOW);
      delay(pause);
    }
   led_random();
  }

void led_effect_3(int pause){
  for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN; ++pin){
      digitalWrite(pin, HIGH);
      delay(pause);
    }
  led_random();
  for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN; ++pin){
      digitalWrite(pin, LOW);
      delay(pause);
    }
  led_random();     
  }

void led_effect_4(int pause){
  for (int pin = 7; pin >= FLINE1_LED_PIN; --pin){
      digitalWrite(pin, HIGH);
      digitalWrite(pin+6, HIGH);
      delay(pause);
    }
  led_random();
  for (int pin = 7; pin >= FLINE1_LED_PIN; --pin){
      digitalWrite(pin, LOW);
      digitalWrite(pin+6, LOW);
      delay(pause);
    }
  led_random();  
  }

void led_random(){
  int p = random(14, 18);
  if(digitalRead(p) == HIGH){
      digitalWrite(p,LOW);
    }else{
        digitalWrite(p,HIGH);
      }
  }

void setup() {
    randomSeed(analogRead(0));
    myOLED.begin(); //инициализируем дисплей
    myOLED.setBrightness(10); //настраиваем яркость дисплея
    for (int pin = FLINE1_LED_PIN; pin <= LLINE1_LED_PIN+4; ++pin){
        pinMode(pin, OUTPUT);
      }
  }

void loop() {
    led_off();
    led_random();
    for(int i = 1; i<=3; ++i){
        led_on();
        delay(500);
        led_off();
        delay(500);
      }
    led_random();   
    led_effect_1(50);
    led_random();
    display_logo(1000);
    led_random();
    for(int i=1; i<=3; ++i){
        led_effect_2(50);
    }
    led_random();    
    display_message(1000);
    led_random();
    led_effect_3(50);
    led_random();
    for(int i=1; i<=3; ++i){
        led_effect_4(50);
      }
    led_random();
  }
