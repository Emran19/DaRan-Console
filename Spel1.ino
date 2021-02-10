#include <Wire.h>

int Current_Digit=9;
int Current_Color=1
String messageLine1 = "Yes"

#define NUM_LEDS 256

void setup()
{
  Serial.begin(9600);
}

 int Check_Pixel_In_Digit(int Number, int i,int j){
 int result;
 if (Number ==0) result=Zero[i][j];
 if (Number ==1) result=One[i][j];
 if (Number ==2) result=Two[i][j];
 if (Number ==3) result=Three[i][j];
 if (Number ==4) result=Four[i][j];
 if (Number ==5) result=Five[i][j];
 if (Number ==6) result=Six[i][j];
 if (Number ==7) result=Seven[i][j];
 if (Number ==8) result=Eight[i][j];
 if (Number ==9) result=Nine[i][j];
 return result;

}

void loop()
{
  for (int i=0;i<8;i++)
  {
    for (int j=0;j<8;j++)
     {
      if (Check_Pixel_In_Digit(Current_Digit,i,j)==1) leds[(i)*8+j]=CHSV( 0 , 0, 255);
      if (Check_Pixel_In_Digit(Current_Digit,i,j)==2) leds[(i)*8+j]=Colors[Current_Color];
      if (Check_Pixel_In_Digit(Current_Digit,i,j)==0) leds[(i)*8+j]=CHSV( 0 , 0, 0);
      }
  }
  delay(500);
  Current_Digit=Current_Digit-1;

  if (Current_Digit==-1)
  {
    matrix.setCursor(1,0);
    matrix.setTextSize(1);
    matrix.print(messageLine1);
  }
}
