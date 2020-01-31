#define LATCH_DIO 4 
#define CLK_DIO 7
#define DATA_DIO 8

const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0X82,0xF8,0X80,0X90};
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};

void setup() {
  // put your setup code here, to run once:
pinMode(LATCH_DIO,OUTPUT);
pinMode(CLK_DIO, OUTPUT);
pinMode(DATA_DIO, OUTPUT);
pinMode(13,OUTPUT);
  WriteNumberToSegment(0,1);
  WriteNumberToSegment(1,2);
  WriteNumberToSegment(2,3);
  WriteNumberToSegment(3,4);

}

void loop() {
  // put your main code here, to run repeatedly:
//  writeNumberTosegment(0,0);
//  writeNumberTosegment(1,1);
//  writeNumberTosegment(2,2);
//  writeNumberTosegment(3,3);

digitalWrite(13,HIGH);
delay(1000);
digitalWrite(13,LOW);
delay(1000);

}

void WriteNumberToSegment(byte Segment, byte Value)
{
  digitalWrite(LATCH_DIO,LOW);
  shiftOut(DATA_DIO, CLK_DIO,MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO,MSBFIRST, SEGMENT_SELECT[Segment]);
  digitalWrite(LATCH_DIO, HIGH);
}

