#define HIZ A7 //sensor QTR-1A izquierdo
#define HDE A0 //sensor QTR-1A derecho

//Definición de variables
int geo = 0; //Variable de estado que indica nuestro modo de geo
int geo1 = 0, geo2 = 0, geo3 = 0; //Guardan nuestra huella digital
int umbral = 990; //umbral que consideraremos como negro
bool girando = false; //comenzamos recto

void hitos() {
  int Hiz = analogRead(HIZ); //Leemos el estado de ambos sensores
  int Hde = analogRead(HDE);
  Serial.println(Hiz);
  if (Hiz < umbral) { //Si el estado está por debajo de nuestro umbral de negro
    Hiz = 1; //El hito izquierdo está activado
  } else { //Caso contrario
    Hiz = 0; //El hito izquierdo no está activado
  }
  if (Hde < umbral) { //Si el estado está por debajo de nuestro umbral de negro
    Hde = 1; //El hito derecho está activado
  } else { //Caso contrario
    Hde = 0; //El hito derecho no está activado
  }
  if (Hiz == 0 && Hde == 0) {
    geo = 0;
  }
  if (Hiz == 1 && Hde == 0) {
    geo = 1;
  }
  if (Hiz == 0 && Hde == 1) {
    geo = 2;
  }
  if (Hiz == 1 && Hde == 1) {
    geo = 3;
  }

  if (geo1 != geo) { //Comprobamos si existe cambio del último geo registrado y el geo actual
    if (geo == 0 && geo1 == 1 && geo2 == 0) { //¿Pasamos el hito izquierdo?
      girando = !girando;
      if (girando == true){
        //multiplGiro = 0.5;
        bipAsync(1400);
      }else{
        multiplGiro = 1.0;
        bipAsync(1700);
      }
      
    }
    if (geo == 0 && geo1 == 2 && geo2 == 0) { //¿Pasamos el hito derecho?
      //contadorDerecho += 1;
      bipAsync(600);
    }
    if (geo == 0 && ((geo1 == 3) || (geo2 == 3) || (geo3 == 3))) { //¿Pasamos un cruce?
      //funcionCruce(); //Realizo las acciones para hito de cruce
    }
    //Actualizo mi historial de los últimos 3 geos detectados 
    geo3 = geo2;
    geo2 = geo1;
    geo1 = geo;
  }

}
