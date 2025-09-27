//definicion pines
#define boton 2
#define buzzer 10
#define pinIR 11

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};
int pos = 0;
int lastPos = 0;

void setup()
{
  pinMode(pinIR, OUTPUT);
  Serial.begin(9600);
}

void leer(){
  digitalWrite(pinIR, HIGH); //"encendido" del IR
  s[5] = analogRead(A1); //el A1 es el de mas a la derecha
  s[4] = analogRead(A2);
  s[3] = analogRead(A3);
  s[2] = analogRead(A4);
  s[1] = analogRead(A5);
  s[0] = analogRead(A6); //el A6 es el de mas a la izquierda
  digitalWrite(pinIR,LOW);//"apagado" del IR

  for(int i = 0;i<6;i++){
    s[i] = map(s[i],0,1023,1023,0) //asi lee linea blanca sobre fondo negro
  } 

}

int posRel(){
  leer();
  float sumaPonderada = -2.5*s[0]-1.5*s[1]-0.5*s[2]+0.5*s[3]+1.5*s[4]+2.5*s[5];
  float suma = s[0]+s[1]+s[2]+s[3]+s[4]+s[5];
  bool enLinea = false;

  if (suma > 1000){
    enLinea = true;
    }

  if (enLinea){
    pos = int(100.0 * sumaPonderada / suma);
  } else { //trata de volver a la linea
    if (lastPos < 0) {
      pos = -255;
    } else if (lastPos >= 0) {
      pos = 255;
    }
  }
  lastPos = pos;
  return pos;
}

void loop()
{
  int p = posRel();
  if (debug){Serial.println(p);}
}
