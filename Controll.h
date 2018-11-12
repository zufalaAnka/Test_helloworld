void controlBegin(){
    //iba zapnutie Ledky (obe sú na pine D3)
    pinMode(3,OUTPUT);
}
float potenciRead(){
    //na pine A0 je potenciometer, táto funkcia len načíta úroven a namapuje ju na percentá 0 až 100
int val=analogRead(0);
float percento = map((float)val, 0, 1023, 0.00, 100.00);
return percento;
}
void ledWrite(float percento){
    //len zapisanie PWM signalu na Led, hodnota do funkcie vstupuje ako percento.
float inPercento=percento*255/100;
analogWrite(3,inPercento);
}
void showLed(){
    //len vypisanie urovne nacitanej z A2 - fotorezistor v trubičke
    int val=analogRead(2);
    Serial.println(val);
}

void showLed2(int Pin,int minimal, int maximal){
    //vypisanie urovne nacitanej z A2 - fotorezistor v trubičke už ako percento 0 až 100, kde do funkcie vstupuje aj minimalna aj maximalna uroven.
    int val=analogRead(Pin);
    float percento = map((float)val, (float)minimal, (float)maximal, 0.00, 100.00);
    Serial.print(percento);
    }

int KalibraciaMin(){
    //minimalna uroven, ako maximum z nacitanych urovni
analogWrite(3,0);
int minimal=0;
for(int i=1;i<=10;i++){
  if (minimal<analogRead(1)){
    minimal=analogRead(1);
  }


}
return minimal;
}
int KalibraciaMax(){
    //minimalna uroven, ako minimum z nacitanych urovni
analogWrite(3,255);
delay(1000);//aby sme nemerali nabeh.
int maximal=1023;
for(int i=1;i<=10;i++){
  if (maximal>analogRead(1)){
    maximal=analogRead(1);
  }
}
return maximal;
}


