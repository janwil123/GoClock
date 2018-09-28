#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// D7 - Serial clock out (CLK oder SCLK)
// D6 - Serial data out (DIN)
// D5 - Data/Command select (DC oder D/C)
// D4 - LCD chip select (CE oder CS)
// D3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);

unsigned long t;
unsigned long secs = 1;

void setup()   {

  display.begin();

  // Kontrast setzen
  display.setContrast(60);
  display.clearDisplay();   // clears the screen and buffer
  display.setTextSize(3);
}


void loop() {
  t = millis();
  if (t > 1000*secs){
    //display.clearDisplay();
    set_text(11,0,String(secs-1),WHITE);
    set_text(11,0,String(secs),BLACK);
    secs = secs + 1;
  }
}

void set_text(int x,int y,String text,int color){
  
  display.setTextColor(color); // Textfarbe setzen, also Schwarz oder Weiss
  display.setCursor(x,y);      // Startpunkt-Position des Textes
  display.println(text);       // Textzeile ausgeben
  display.display();           // Display aktualisieren
}
