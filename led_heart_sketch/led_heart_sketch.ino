//  @autor = s.kulchanovskiy@gmail.com
//  @microcontroller = Atmega328p 

#include <OLED_I2C.h> //импорт библиотеки
OLED  myOLED(SDA, SCL, 8); //создаем экземпляр класса OLED с именем myOLED
extern uint8_t logo[];
extern uint8_t nelya[];
extern uint8_t message[];
extern uint8_t family[];

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

void setup() {
    myOLED.begin(); //инициализируем дисплей
    myOLED.setBrightness(10); //настраиваем яркость дисплея
  }

void loop() {
    display_logo(2000);
    display_message(2000);
  }
