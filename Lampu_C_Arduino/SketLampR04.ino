int nilai;
void setup() {
  // put your setup code here, to run once:
//Potensiometer ada di radio , rasistor nila diputar hambatannya berubah 5v 5v(1023)(512)(0-->0)GND = 0 
Serial.begin(9600);
}
//seberapa 
void loop() {
  // put your main code here, to run repeatedly:

  nilai = analogRead (A3);
  Serial.println(nilai);
delay(100);
}
