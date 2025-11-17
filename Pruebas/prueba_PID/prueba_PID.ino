#define boton 2
#define buzzer 10
#define led 13

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};
float kp = 0.08; //cte proporcional
float ki = 0.0; //cte integral
float kd = 0.5; //cte derivada
float multiplGiro = 1.0;

int v[] = {25,50,75,100,150};
int vel = v[1]; //por defecto usara 50 como velocidad base
int modo = 1;
int contadorDerecho = 0;
void setup(){
  //Serial.begin(9600);
  peri_setup();
  sensores_setup();
  driverM_setup();

  esperarBoton();
  calibracion();

  int configurando = true;
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

        modo += 1;

        if (modo == 5){
          modo = 0;
        }

        bip();
      }
      tiempoPres = 0;
    }

    delay(100);
  }
  vel = v[modo];
}
//int t = 0;
void loop(){
  int p = posRel();
  int correccion = PID(p, kp, ki, kd);
  hitos();


  motores(vel*multiplGiro + correccion, vel*multiplGiro - correccion);

  if (contadorDerecho == 2){
    motores(0,0);
    esperarBoton();
  }

  delay(1);

}
