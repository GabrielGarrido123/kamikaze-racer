//definicion pines
#define pinIR 11


int pos = 0;
int lastPos = 0;
int v_s_max[] = {0,0,0,0,0,0};
int v_s_min[] = {1023,1023,1023,1023,1023,1023};

void sensores_setup()
{
  pinMode(pinIR, OUTPUT);
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
    s[i] = map(s[i],0,1023,1023,0); //asi lee linea blanca sobre fondo negro
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

void calibracion() {
  digitalWrite(pinIR, HIGH);

  int v_s[6];

  for (int j = 0; j < 100; j++) {
    delay(30);
    v_s[0] = analogRead(A6);
    v_s[1] = analogRead(A5);
    v_s[2] = analogRead(A4);
    v_s[3] = analogRead(A3);
    v_s[4] = analogRead(A2);
    v_s[5] = analogRead(A1);

    for (int i = 0; i < 6; i++) {

      Serial.print(v_s[i]);
      Serial.print("\t");
    }
    Serial.println();

    for (int i = 0; i < 6; i++) {
      if (v_s[i] < v_s_min[i]) {
        v_s_min[i] = v_s[i];
      }
    }


    for (int i = 0; i < 6; i++) {
      if (v_s[i] > v_s_max[i]) {
        v_s_max[i] = v_s[i];
      }
    }
  }

  bip();
  bip();

  Serial.println();
  Serial.println();

  Serial.print("Minimos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_min[i]);
    Serial.print("\t");
  }
  Serial.println();

  Serial.print("Maximos");
  Serial.print("\t");

  for (int i = 0; i < 6; i++) {
    Serial.print(v_s_max[i]);
    Serial.print("\t");
  }
  Serial.println();
  digitalWrite(pinIR, LOW);
}
