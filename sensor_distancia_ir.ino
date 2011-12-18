/**
 * Codigo de exemplo de utilizacao do Sensor de Distancia IR Sharp 2YY0a02
 * Acende ou apaga um led de acordo com a distancia entre o sensor e um objeto
 *
 * Adapatado de http://luckylarry.co.uk/arduino-projects/arduino-using-a-sharp-ir-sensor-for-distance-calculation/
 *
 * 17 de dezembro de 2011
 * @LennonJesus
 */

const int sensorPin = 1; // pino analogico onde esta ligado o sensor
const int ledPin = 13; // pino onde esta ligado o led

void setup() {
  pinMode(ledPin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
  
  float distance = 0;
  
  // Afim de melhorar a precisao, utilizei o loop a seguir para coletar a distancia 8 vezes e armazenar a soma dos resultados
  for (int idx = 0; idx < 8; idx++) {

    float volts = analogRead(sensorPin) * 0.0048828125;   // value from sensor * (5/1024) - if running 3.3.volts then change 5 to 3.3

    distance += 65 * pow(volts, -1.10);          // worked out from graph 65 = theretical distance / (1/Volts)S - luckylarry.co.uk    
    
  }

  distance = distance / 8;  
  
  Serial.println(distance);
  
  if (distance < 25) {
    digitalWrite(ledPin, HIGH); 
  } else {
     digitalWrite(ledPin, LOW);
  }
   
  // como o loop que coleta os dados da distancia e executado 8 vezes em intervalos de 100 milisegundos, 
  // com um delay adicional de 200 milisegundos, teremos a medicao completa sendo executada a cada 1 segundo.
  delay(200);
}
