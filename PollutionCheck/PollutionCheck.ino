
/*This is used to record and give a graphical representation of the pressure inside the motor.
 *This project helps in the detection and control of air pollution in wide areas. 
 *The graph provides a detailed study of the amount of dust produced per unit time.
 *Hardware components used Arduino Uno, BMP 180 Sensor Mortor, Power supply.  
 *We assume that the room pressure always remains constant.
 */
#include <Wire.h>
#include <SFE_BMP180.h>

SFE_BMP180 bmp180;

void setup() {
  Serial.begin(9600);
  bool success = bmp180.begin();

  if (success) {
    Serial.println("BMP180 init success");
  }
}
void loop() {
  char status;
  double T, P;
  bool success = false;

  status = bmp180.startTemperature();
  
  if (status != 0) {
    delay(1000);
    status = bmp180.getTemperature(T);

    if (status != 0) {
      status = bmp180.startPressure(3);

      if (status != 0) {
        delay(status);
        status = bmp180.getPressure(P, T);
        
        if (status != 0) {
          Serial.print("Pressure: ");
          Serial.print(P);
          Serial.println(" hPa");
          Serial.print("  ");
        }
      }
    }
  }
}
