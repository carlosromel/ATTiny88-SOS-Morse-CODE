/*
  SOS

  Turns an external LED (pin 3) on and Off, for SOS Morse Code.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  Created by Carlos Romle at 3/04/2023.

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/
*/

/**
 * 0) Usar a Arduino IDE 2.1.0
 * 1) Ajuste as permissões do disppositivo no Linux
      curl https://raw.githubusercontent.com/micronucleus/micronucleus/master/commandline/49-micronucleus.rules | sudo tee /etc/udev/rules.d/49-micronucleus.rules
 * 2) Configurar a Arduino IDE
 * 2.1) File | Preferences
        Inclua as URLs (abaixo) no campo: Additional boards manager
        http://digistump.com/package_digistump_index.json
        https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json
        http://drazzy.com/package_drazzy.com_index.json
   2.2) Tools | Board | Board manager
        Pesquie por ATTinycore
        Instale
   2.3) Tools | Board | ATtinyCore -> ATTiny88 (Micronucleus, MH-ET t88 w/16MHz CLOCK)
   2.4) Tools | Programmer -> USBtinyISP (ATtinyCore) FAST, for parts running >= 2MHz
 */

/*
 * Cálculo do tempo:
 * Emitir cinco códigos PARIS em um minuto.
 *
 * 60s / 5 vezes  = 12s (por código)
 * 12s / 5 letras = 2,4s (por letra)
 * 2,4s =  2400 millisegundos
 */
#define LED_EXTERNO 3
#define DIT         200
#define DAH         (DIT * 3)

// the setup function runs once when you press reset or power the board
// initialize digital pin LED_BUILTIN as an output.
void setup() {
  pinMode(LED_EXTERNO, OUTPUT);
}

void blink(int pin, int ms, int count) {
  for (int c = 0; c < count; ++c) {
    digitalWrite(LED_EXTERNO, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(ms);                        // wait for a second
    digitalWrite(LED_EXTERNO, LOW);   // turn the LED off by making the voltage LOW
    delay(ms);                        // wait for a second
  }
}

void slow(int pin, int count) { blink(pin, DIT, count); }
void fast(int pin, int count) { blink(pin, DAH, count); }

// the loop function runs over and over again forever
void loop() {
    delay(DAH);
    slow(LED_EXTERNO, 3);
    delay(DAH);
    fast(LED_EXTERNO, 3);
    delay(DAH);
    slow(LED_EXTERNO, 3);
    delay(DAH);
}
