//definicion pines
#define boton 2
#define buzzer 10
#define pinIR 11

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int sensores[] = {0,0,0,0,0,0};

void leer(){
  digitalWrite(pinIR, HIGH); //"encendido" del IR
  sensores[0] = analogRead(A0);
  sensores[1] = analogRead(A1);
  sensores[2] = analogRead(A2);
  sensores[3] = analogRead(A3);
  sensores[4] = analogRead(A4);
  sensores[5] = analogRead(A5);
  digitalWrite(pinIR,LOW);//"apagado" del IR
}

int posRel(){
  leer();
  float sumaPonderada = -2.5*sensores[0]-1.5*sensores[1]-0.5*sensores[2]+0.5*sensores[3]+1.5*sensores[4]+2.5*sensores[5];
  float suma = sensores[0]+sensores[1]+sensores[2]+sensores[3]+sensores[4]+sensores[5];
  bool enLinea = false;

  if (suma > 1000){online = true};

  if (online){
    pos = 
  }


  int ponderacion[6] = {-3,-2,-1,1,2,3};
  int suma = 0;
  for (int i = 0; i < 6; i++){
    suma += sensores[i]*ponderacion[i];//esto claramente aun no da entre -255 y 255
  }
  
  int maxAct = 1023*3+1023*2+1023;
  
  int sumaMap = map(suma,-maxAct,maxAct,-255,255);//ahora si da la posicion pedida :D

  if (sumaMap == 0){
    return 0;
  }
  return sumaMap;
}

void setup()
{
  pinMode(11, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int p = posRel();
  Serial.println(p);
}
