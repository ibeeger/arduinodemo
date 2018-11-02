void setup() {
  // put your setup code here, to run once:
//   pinMode(13,OUTPUT);
}



void loop() {
  
//  digitalWrite(13,HIGH);
//  delay(1000);
//  digitalWrite(13,LOW);
//  delay(1000);

  for(int i = 0; i<=255; i+=5){
      analogWrite(9,i);
      delay(10);
    };
   
   for(int i = 255; i>=0; i-=5){
      analogWrite(9,i);
      delay(10);
    };
}

 
