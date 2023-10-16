#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup()
{
  Serial.begin(115200);
  mlx.begin();
  Serial.print("\n\nEmissivity = ");
  Serial.println(mlx.readEmissivity());
  mlx.writeEmissivity(0.972);
  Serial.println("================================================");
  Serial.println("SuhuAmbient\tSuhuObject");
}

void loop()
{
  Serial.print(mlx.readAmbientTempC());
  Serial.print("\t");
  Serial.println(mlx.readObjectTempC());
  delay(1000);
}