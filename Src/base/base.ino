#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <iclist.h>

#define PWM1_Res 8
#define PWM1_Freq 1000

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  // put your setup code here, to run once:
  ledcSetup(0, PWM1_Freq, PWM1_Res);
  ledcSetup(1, PWM1_Freq, PWM1_Res);
  ledcSetup(2, PWM1_Freq, PWM1_Res);
  ledcSetup(3, PWM1_Freq, PWM1_Res);
  ledcSetup(5, PWM1_Freq, PWM1_Res);
  ledcSetup(6, PWM1_Freq, PWM1_Res);
  ledcSetup(7, PWM1_Freq, PWM1_Res);
  ledcSetup(8, PWM1_Freq, PWM1_Res);
  ledcSetup(9, PWM1_Freq, PWM1_Res);
  ledcSetup(10, PWM1_Freq, PWM1_Res);
  ledcSetup(11, PWM1_Freq, PWM1_Res);
  ledcSetup(12, PWM1_Freq, PWM1_Res);
  ledcSetup(13, PWM1_Freq, PWM1_Res);
  ledcSetup(14, PWM1_Freq, PWM1_Res);
  ledcSetup(15, PWM1_Freq, PWM1_Res);

  Serial.begin(115200);

  return;
}


void loop() {
  // put your main code here, to run repeatedly:
  return;
}

int pin4[4] = { 32, 33, 18, 19 };
int pin6[6] = { 32, 33, 25, 5, 18, 19 };
int pin8[8] = { 32, 33, 25, 26, 4, 5, 18, 19 };
int pin10[10] = { 32, 33, 25, 26, 27, 2, 4, 5, 18, 19 };
int pin12[12] = { 32, 33, 25, 26, 27, 14, 15, 2, 4, 5, 18, 19 };
int pin14[14] = { 32, 33, 25, 26, 27, 14, 12, 13, 15, 2, 4, 5, 18, 19 };


void pin_dic(int number, char mode, int ind) {
  if (mode == '1') {
    pinMode(number, OUTPUT);
    digitalWrite(number, HIGH);
  } else if (mode == '0') {
    pinMode(number, OUTPUT);
    digitalWrite(number, LOW);
  } else if (mode == 'V') {
    pinMode(number, OUTPUT);
    digitalWrite(number, HIGH);
  } else if (mode == 'G') {
    pinMode(number, OUTPUT);
    digitalWrite(number, LOW);
  } else if (mode == 'O') {
    pinMode(number, INPUT);
  } else if (mode == 'P') {
    //there are 16 channels, we will use 14 of them and attach to 14 pins if need individually
    ledcAttachPin(number, ind);  //ind is the pwm channel
    ledcWrite(ind, 127);         //50% 1000Hz PWM output
  }

  else if (mode == 'Q') {
    pinMode(number, INPUT);

  }

  else {
    pinMode(number, INPUT);  //default is high impedance input mode to stop floating
  }
}


void pinm(String dat, String outs) {  //get input pin confg and desired Outputs

  int leng = dat.length();   //number of pins
  int legD = outs.length();  //number of outputs
  int out_count = 0;

  if (leng == 4) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin4[i], dat[i], i);
      delay(10);
    }

    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin4[i]);
        out_count = out_count + 1;
      }
    }
  }

  else if (leng == 6) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin6[i], dat[i], i);
      delay(10);
    }

    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin6[i]);
        out_count = out_count + 1;
      }
    }
  } else if (leng == 8) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin8[i], dat[i], i);
      delay(10);
    }
    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin8[i]);
        out_count = out_count + 1;
      }
    }
  } else if (leng == 10) {

    for (int i = 0; i < leng; i++) {
      pin_dic(pin10[i], dat[i], i);
      delay(10);
    }

    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin8[i]);
        out_count = out_count + 1;
      }
    }
  } else if (leng == 12) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin12[i], dat[i], i);
      delay(10);
    }
    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin12[i]);
        out_count = out_count + 1;
      }
    }
  } else if (leng == 14) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin14[i], dat[i], i);
      delay(10);
    }

    int o[legD] = {};
    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin14[i]);
        out_count = out_count + 1;
      }
    }
  }
}

void out_put(int ar1[],int ar2[]) {

int flag=0;
 for (int i =0;i<ar1.length(),i++) {
   if (ar2[i] != ar1[i]){
     flag=1;
     }
  

 }
if(flag==0){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Test part");
    display.setCursor(1,0);
    display.println("TEst case pass")
    display.display();
    
    }    
else{
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Test part");
    display.setCursor(1,0);
    display.println("TEst case faild")
    display.display();  
}
}