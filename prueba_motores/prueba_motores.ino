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

  esperarBoton(); //presionar boton para que los motores avancen
  motores(50, 50);
  delay(1000);

  esperarBoton(); //presionar boton para que los motores retrocedan
  motores(-50, -50);
  delay(1000);

  esperarBoton(); //presionar el boton para que los motores se detengan
  motores(0, 0);
  delay(100);

  esperarBoton(); //presionar el boton para que el motor izquierdo avance
  motores(50, 0)
  delay(1000);

  esperarBoton(); //presionar el boton para que el motor izquierdo retroceda
  motores(-50, 0)
  delay(1000);

  esperarBoton(); //presionar el boton para que el motor derecho avance
  motores(0, 50)
  delay(1000);

  esperarBoton(); //presionar el boton para que el motor derecho retroceda
  motores(0,-50)
  delay(1000);
}


void loop() {
}