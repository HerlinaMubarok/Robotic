void setup() {
  // put your setup code here, to run once:
pinMode(5,OUTPUT);
pinMode(2,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    if (digitalRead (2) == 1){
      digitalWrite (5,HIGH);
      Serial.println("Tombol ditekan");
    }
    else {
      digitalWrite (5,LOW);
      Serial.println("Tombol tidak ditekan");
    }
    delay(500);
}
