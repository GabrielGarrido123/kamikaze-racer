#define boton 2
#define buzzer 10
#define led 13

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};

void setup(){
  Serial.begin(9600);
  peri_setup();
  sensores_setup();

  bip(); //avisa que termino de inicializarse
}

void loop()
{
  int p = posRel();
  if (debug){
    Serial.print(s[0]);
    Serial.print("\t");
    Serial.print(s[1]);
    Serial.print("\t");
    Serial.print(s[2]);
    Serial.print("\t");
    Serial.print(s[3]);
    Serial.print("\t");
    Serial.print(s[4]);
    Serial.print("\t");
    Serial.print(s[5]);
    Serial.print("\t");
    Serial.println(p);
  }
}
