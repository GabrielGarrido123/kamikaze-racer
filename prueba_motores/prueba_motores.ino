#define boton 2
#define buzzer 10
#define led 13

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};

void setup() {
  Serial.begin(115200);
  peri_setup();
  driverM_setup();
  sensores_setup();

  motores(0, 0);
  delay(500);

  digitalWrite(led,HIGH);
  Serial.println("Presiona el boton para que ambos motores avancen.");
  esperarBoton(); //presionar boton para que los motores avancen
  motores(125, 125);
  delay(1000);

  Serial.println("Presiona el boton para que ambos motores retrocedan.");
  esperarBoton(); //presionar boton para que los motores retrocedan
  motores(-125, -125);
  delay(1000);

  Serial.println("Presiona el boton para que ambos motores se detengan.");
  esperarBoton(); //presionar el boton para que los motores se detengan
  motores(0, 0);
  delay(100);

  Serial.println("Presiona el boton para que el motor izquerdo avance.");
  esperarBoton(); //presionar el boton para que el motor izquierdo avance
  motores(125, 0);
  delay(1000);

  Serial.println("Presiona el boton para que el motor izquerdo retroceda.");
  esperarBoton(); //presionar el boton para que el motor izquierdo retroceda
  motores(-125, 0);
  delay(1000);

  Serial.println("Presiona el boton para que el motor derecho avance.");
  esperarBoton(); //presionar el boton para que el motor derecho avance
  motores(0, 125);
  delay(1000);

  Serial.println("Presiona el boton para que el motor derecho retroceda.");
  esperarBoton(); //presionar el boton para que el motor derecho retroceda
  motores(0,-125);
  delay(1000);

  Serial.println("Presiona el boton para que ambos motores se detengan y concluir el testeo de motores.");
  esperarBoton(); //presionar el boton para que los motores se detengan
  motores(0, 0);
  delay(100);

  bipBkn(1661.22,200,50);
  bipBkn(1244.51,200,50);
  bipBkn(830.609,200,50);
  bipBkn(932.328,200,50);
  digitalWrite(led,LOW);
}


void loop() {
}