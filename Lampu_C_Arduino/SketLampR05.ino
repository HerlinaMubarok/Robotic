int nilai;
void setup() {
  // put your setup code here, to run once:
//Potensiometer ada di radio , rasistor nila diputar hambatannya berubah 5v 5v(255)(512)(0-->0)GND = 0 
Serial.begin(9600);
}
//seberapa 
void loop() {
  // put your main code here, to run repeatedly:

  nilai = analogRead (A3);
  Serial.println(nilai);
  analogWrite (5, nilai/4);
delay(100);
}
