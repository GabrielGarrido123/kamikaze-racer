#define boton 2
#define buzzer 10
#define led 13

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};
bool configurando = true;
int vExtra = 0;

void setup(){
  Serial.begin(9600);
  peri_setup();
  sensores_setup();

  pinMode(led,OUTPUT);
  bip(); //avisa que termino de inicializarse
}

void loop()
{
  bip();
  //configurar velocidad
  int tiempoPres = 0;
  digitalWrite(led,HIGH);
  while (configurando == true){
    bool btnPres = digitalRead(boton);

    if (btnPres == true){
      tiempoPres += 100;

      if (tiempoPres >= 1000){
        bipBkn(2200,1000,100);
        configurando = false;
      }
    }else{
      if (tiempoPres > 0 && tiempoPres < 1000){
        //fue soltado luego de ser presionado por menos de 1 seg
        vExtra += 5;
        bip();
      }
      tiempoPres = 0;
    }

    delay(100);
  }
  configurando = true;
  digitalWrite(led,LOW);

  delay(1000);
  bipBkn(1500,500,500);
  bipBkn(1500,500,500);
  bipBkn(1500,500,500);
  bipBkn(2000,1000,0);
  
  digitalWrite(led,HIGH);
  //que va a hacer: avanza un rato, luego gira a la derecha, avanza otro poco, retrocede, gira a la izquierda (avanzando), y se detiene
  motores(25 + vExtra,25 + vExtra);
  delay(2500);
  motores(40 + int(vExtra/2) ,10 + int(vExtra/2));
  delay(800);
  motores(25 + vExtra,25 + vExtra);
  delay(1000);
  motores(-25 - vExtra,-25 - vExtra);
  delay(1000);
  motores(10 + int(vExtra/2) ,40 + int(vExtra/2));
  delay(1500);
  motores(0,0);

  digitalWrite(led,LOW);
  bip();
  
  delay(1000);

  esperarBoton();
  delay(2000);
}
