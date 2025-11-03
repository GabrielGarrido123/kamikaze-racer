#define boton 2
#define buzzer 10
#define led 13

bool debug = true; //para evitar que se esten mandando los outputs en consola cambiar a false
int s[] = {0,0,0,0,0,0};
float kp = 0.39; //cte proporcional
float ki = 0.1; //cte integral
float kd = 0.01; //cte derivada

int v[] = {25,50,75,100,150};
int vel = v[0]; //por defecto usara 50 como velocidad base
int modo = 0;

void setup(){
  peri_setup();
  sensores_setup();
  driverM_setup();

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
int t = 0;
void loop(){
  int p = posRel();
  int correccion = PID(p, kp, ki, kd);


  motores(vel + correccion, vel - correccion);
  t+=1;
  delay(1);
  if (t>1000){
    motores(0,0);
    esperarBoton();
    
    t=0;
  }
}
