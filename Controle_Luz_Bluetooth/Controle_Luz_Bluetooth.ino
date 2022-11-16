#include <SoftwareSerial.h> //biblioteca do Bluetooth

SoftwareSerial bluetooth(10, 11); //RX,TX

#define lamp 7 //pino para controle da iluminação

int blue = 0; //variável para armazenar o dado enviado via Bluetooth
int ilum = 0; //variável para conversão de valores

void setup() {
  // put your setup code here, to run once:
  bluetooth.begin(9600); //inicializa a comunicação com o Bluetooth e define velocidade de comunicação
  pinMode(lamp, OUTPUT); //define o pino como saída

}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available()) { //confere se alguma informação foi recebida
    delay(10);
    blue = bluetooth.read(); //lê e guarda o dado recebido
    if (blue > 0) {
      ilum = map(blue, 0, 100, 0, 255); //converte o valor em percentual recebido para a escala PWM
      analogWrite(lamp, ilum); //saída proporcional ao valor recebido na entrada
    }
  }

}
