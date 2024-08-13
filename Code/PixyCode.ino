#include <Pixy2.h>
#include <Servo.h>

// Crear un objeto Pixy2
Pixy2 pixy;

// Crear un objeto Servo
Servo miServo;

// Definir el pin al que está conectado el servo
const int pinServo = 8;

// Definir los pines del módulo BTN7960
const int R_EN = 5;
const int R_PWM = 6;
const int L_EN = 4;
const int L_PWM = 7;

// Configurar las firmas
const uint8_t RED_SIGNATURE = 1;  // Rojo
const uint8_t GREEN_SIGNATURE = 2; // Verde

void setup() {
  // Iniciar la comunicación serial a 9600 baudios
  Serial.begin(9600);
  
  // Adjuntar el servo al pin 8
  miServo.attach(pinServo);
  
  // Iniciar la Pixy2
  pixy.init();

  // Configurar pines del módulo BTN7960 como salidas
  pinMode(R_EN, OUTPUT);
  pinMode(R_PWM, OUTPUT);
  pinMode(L_EN, OUTPUT);
  pinMode(L_PWM, OUTPUT);
  
  // Inicializar el módulo BTN7960
  digitalWrite(R_EN, HIGH); // Habilitar módulo derecho
  digitalWrite(L_EN, HIGH); // Habilitar módulo izquierdo
  
  // Colocar el servo en la posición central y testearlo
  miServo.write(90);

  int8_t result = pixy.setLamp(1, 1);  // 1 enciende las luces superiores, 0 apaga el LED RGB
}

void MotorForward(int Velocity) {
  analogWrite(R_PWM, 0);
  analogWrite(L_PWM, Velocity);
}

void MotorBackward(int Velocity) {
  analogWrite(R_PWM, Velocity);
  analogWrite(L_PWM, 0);
}

void loop() {
  // Obtener bloques de la PixyCam
  pixy.ccc.getBlocks();
  
  // Verificar si se detectaron bloques
  if (pixy.ccc.numBlocks) {
    // Iterar a través de los bloques detectados
    for (int i = 0; i < pixy.ccc.numBlocks; i++) {
      // Imprimir la información del bloque detectado
      Serial.print("Block detected: ");
      Serial.print(pixy.ccc.blocks[i].m_signature);
      Serial.print(", X: ");
      Serial.print(pixy.ccc.blocks[i].m_x);
      Serial.print(", Y: ");
      Serial.println(pixy.ccc.blocks[i].m_y);
      
      // Mover el servo según la firma detectada y controlar el motor
      if (pixy.ccc.blocks[i].m_signature == RED_SIGNATURE) {
        // Mover el servo a la derecha (posición 170) y avanzar el vehículo
        miServo.write(170);
        delay(1000);
        MotorForward(150);  // Ajustar la velocidad según tus necesidades
        delay(1000);
        miServo.write(90); // Regresar el servo a la posición central
      } 
      else if (pixy.ccc.blocks[i].m_signature == GREEN_SIGNATURE) {
        // Mover el servo a la izquierda (posición 10) y avanzar el vehículo
        miServo.write(10);
        delay(1000);
        MotorForward(150);  // Ajustar la velocidad según tus necesidades
        delay(1000);
        miServo.write(90); // Regresar el servo a la posición central
      }
    }
  } else {
    // Si no se detecta ningún objeto, avanzar en línea recta
    MotorForward(150);
  }
  
  // Esperar un breve momento antes de la próxima lectura
  delay(100);
}