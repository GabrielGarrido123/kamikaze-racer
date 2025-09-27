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
  s[0] = analogRead(A0);
  s[1] = analogRead(A1);
  s[2] = analogRead(A2);
  s[3] = analogRead(A3);
  s[4] = analogRead(A4);
  s[5] = analogRead(A5);
  digitalWrite(pinIR,LOW);//"apagado" del IR
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
