#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width,  in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Define buttons
#define UP_PIN 50 
#define DOWN_PIN 31 
#define OK_PIN 48 
#define LEFT_PIN 30 //47
#define RIGHT_PIN 47 //30

#define OK_LED  41
#define NOT_LED  43
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//component cofig.

int index_sel[2]={0, 0};

//number of components in the comp_lists
const int length_of_lists[5]={20,20,20,20,13};

const String temp14[13][4][2]= {
  {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

  {
  {"10101OG0OO000V", "110"},
  {"11010OG1OO001V", "111"},
  {"00010OG0OO101V", "011"},
  {"11101OG0OO011V", "111"}
},
{
  {"10101OG0OO000V", "110"},
  {"11010OG1OO001V", "111"},
  {"00010OG0OO101V", "011"},
  {"11101OG0OO011V", "111"}
},
{
  {"00O10OGO01O11V", "0110"},
  {"11O01OGO01O11V", "0110"},
  {"10O00OGO11O01V", "1001"},
  {"01O11OGO00O10V", "1001"}
},
{
  {"00O01OGO10O11V", "0001"},
  {"01O10OGO11O00V", "0010"},
  {"10O11OGO00O01V", "0100"},
  {"11O10OGO01O00V", "1000"}
},
{
  {"00O01OGO10O11V", "0001"},
  {"01O10OGO11O00V", "0010"},
  {"10O11OGO00O01V", "0100"},
  {"11O10OGO01O00V", "1000"}
},
{
  {"00O01OGO10O11V", "0111"},
  {"01O10OGO11O00V", "1110"},
  {"10O11OGO00O01V", "1101"},
  {"11O10OGO01O00V", "1110"}
},
{
  {"00O01OGO10O11V", "0111"},
  {"01O10OGO11O00V", "1110"},
  {"10O11OGO00O01V", "1101"},
  {"11O10OGO01O00V", "1110"}
},
{
  {"00O01OGO10O11V", "1110"},
  {"01O10OGO11O00V", "1101"},
  {"10O11OGO00O01V", "1011"},
  {"11O10OGO01O00V", "0111"}  
},
{
  {"00O01OGO10O11V", "1110"},
  {"01O10OGO11O00V", "1101"},
  {"10O11OGO00O01V", "1011"},
  {"11O10OGO01O00V", "0111"}  
},
{
  {"0O0O0OGO0O0O0V", "111111"},
  {"1O1O1OGO1O1O1V", "000000"},
  {"pass", "pass"},
  {"pass", "pass"}
},
{
  {"0O0O0OGO0O0O0V", "111111"},
  {"1O1O1OGO1O1O1V", "000000"},
  {"pass", "pass"},
  {"pass", "pass"}
},
{
  {"10101OG0OO000V", "110"},
  {"11010OG1OO001V", "111"},
  {"00010OG0OO101V", "011"},
  {"11101OG0OO011V", "111"}
}
};


const String temp12[2][4][2]= {
    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}
    }
    };

const String temp10[2][4][2]= {
    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}
    }
    };



const String temp8[2][4][2]= {
    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}
    }
    };

const String temp6[2][4][2]= {
    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}
    }
    };

const String temp4[2][4][2]= {
    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}},

    {
      {"00O00OGO00O00V","1111" },
    {"11O11OGO11O11V","0000"},
    {"01O01OGO01O01V","1111"},
    {"pass","pass"}
    }
    };

// const String temp2[2][4][2]= {
//     {
//       {"00O00OGO00O00V","1111" },
//     {"11O11OGO11O11V","0000"},
//     {"01O01OGO01O01V","1111"},
//     {"pass","pass"}},

//     {
//       {"00O00OGO00O00V","1111" },
//     {"11O11OGO11O11V","0000"},
//     {"01O01OGO01O01V","1111"},
//     {"pass","pass"}
//     }
//     };

// test status, passses, fails, total tests.
int status_of_test[3] = {0,0,0};

//pin arrays 
int pin4[4] = { 2, 4, A5, A3};
int pin6[6] = { 2, 4, 6, A7, A5, A3};
int pin8[8] = { 2, 4, 6, 8, A9, A7, A5, A3};
int pin10[10] = { 2, 4, 6, 8, 10, A11, A9, A7, A5, A3};
int pin12[12] = { 2, 4, 6, 8, 10, 12, A13, A11, A9, A7, A5, A3};
int pin14[14] = { 2, 4, 6, 8, 10, 12, 14, A15, A13, A11, A9, A7, A5, A3};

//Pin switch modes
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
  } 
  else {
    pinMode(number, INPUT);  //default is high impedance input mode to stop floating
  }
}
// function for testing the IC

String pinm_blue(String dat) {  //get input pin confg and desired Outputs
  int lengD=0;
  int leng = dat.length();   //number of pins
//Serial1.println("got the lengd "+ String(leng));

  for (int i =0; i <leng; i++){
    //Serial.println()
    if(dat[i] == 'O'){
      lengD=lengD+1;
    }
  }
  //Serial1.println("got the lengd "+ String(lengD));

  
  //int lengD = outs.length();  //number of outputs
  int out_count = 0;
  int o[lengD] = {};

  if (leng == 4) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin4[i], dat[i], i);
      delay(10);
    }

    
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

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin6[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 8) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin8[i], dat[i], i);
      delay(10);
    }

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin8[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 10) {

    for (int i = 0; i < leng; i++) {
      pin_dic(pin10[i], dat[i], i);
      delay(10);
    }

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin10[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 12) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin12[i], dat[i], i);
      delay(10);
    }
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

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin14[i]);
        out_count = out_count + 1;
      }
    }
}

//Serial1.println(String(o[0]));
String Blue_outs="";

for (int i=0; i< lengD; i++){
  Blue_outs = Blue_outs + String(o[i]);
}
//Serial1.println("Dont know.  -"+Blue_outs);
// check if working or not.
  return Blue_outs;
}


//_____________________________________________________________________________
int pinm(String dat, String outs) {  //get input pin confg and desired Outputs

  int leng = dat.length();   //number of pins
  int lengD = outs.length();  //number of outputs
  int out_count = 0;
  int o[lengD] = {};

  if (leng == 4) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin4[i], dat[i], i);
      delay(10);
    }

    
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

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin6[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 8) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin8[i], dat[i], i);
      delay(10);
    }

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin8[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 10) {

    for (int i = 0; i < leng; i++) {
      pin_dic(pin10[i], dat[i], i);
      delay(10);
    }

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin10[i]);
        out_count = out_count + 1;
      }
    }
  } 
  else if (leng == 12) {
    for (int i = 0; i < leng; i++) {
      pin_dic(pin12[i], dat[i], i);
      delay(10);
    }
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

    for (int i = 0; i < leng; i++) {
      if (dat[i] == 'O') {
        o[out_count] = digitalRead(pin14[i]);
        out_count = out_count + 1;
      }
    }
}

// check if working or not.
  return out_put(outs,o);
}

// check if we get desired outputs from pins
int out_put(String ar1,int ar2[]) {// check between what we expected and what we got
int flag=1;
 for (int i =0; i<ar1.length();i++) {
   //Serial.print((ar2[i]));
   if (ar2[i] != (ar1[i]-'0')){
     flag=0;
     }
 }
return flag;
}

//bjt one
int bjt_tests(String NoP){
  int flag =1;
  int ch_bj = 100;
  if (NoP == "NPN"){ //NPN
    
    digitalWrite(3,HIGH);

    delay(100);

    ch_bj= digitalRead(A0);
    if (ch_bj == 1){
      flag = 0;
    }

    digitalWrite(3,LOW);

    delay(100);

    ch_bj= digitalRead(A0);
    if (ch_bj == 0){
      flag = 0;
    }
    
  }
  else if (NoP == "PNP"){ //NPN
    
    digitalWrite(13,HIGH);

    delay(100);

    ch_bj= digitalRead(A1);
    if (ch_bj == 1){
      flag = 0;
    }

    digitalWrite(13,LOW);

    delay(100);

    ch_bj = digitalRead(A1);
    if (ch_bj == 0){
      flag = 0;
    }
    
  }
  return flag;

}


//check the List and select respective congigs, and check
void multi(int ind){
  status_of_test[0]=0;
  status_of_test[1]=0;
  status_of_test[2]= 0;

  int passes=0;
  int fails=0;

  if (index_sel[0]==4){

  for(int i =0; i< 4 ; i++){
    String confg = temp14[ind][i][0];
    String exp_out= temp14[ind][i][1];

    if (confg == "pass"){
      continue;
    }
    else{
      if (pinm(confg,exp_out) == 1){
        passes= passes+1;
      }
      else{
        fails = fails+1;
      }

    }
  }
  }

  else if (index_sel[0]==3){

  for(int i =0; i< 4 ; i++){
    // String confg = temp12[ind][i][0];
    // String exp_out= temp12[ind][i][1];
    String confg = temp10[ind][i][0];
    String exp_out= temp10[ind][i][1];

    if (confg == "pass"){
      continue;
    }
    else{
      if (pinm(confg,exp_out) == 1){
        passes= passes+1;
      }
      else{
        fails = fails+1;
      }

    }
  }
  }

  else if (index_sel[0]==2){

  for(int i =0; i< 4 ; i++){
    String confg = temp8[ind][i][0];
    String exp_out= temp8[ind][i][1];

    if (confg == "pass"){
      continue;
    }
    else{
      if (pinm(confg,exp_out) == 1){
        passes= passes+1;
      }
      else{
        fails = fails+1;
      }

    }
  }
  }

  else if (index_sel[0]==1){

  for(int i =0; i< 4 ; i++){
    String confg = temp6[ind][i][0];
    String exp_out= temp6[ind][i][1];

    if (confg == "pass"){
      continue;
    }
    else{
      if (pinm(confg,exp_out) == 1){
        passes= passes+1;
      }
      else{
        fails = fails+1;
      }

    }
  }
  }

  else if (index_sel[0]==0){

  for(int i =0; i< 4 ; i++){
    String confg = temp4[ind][i][0];
    String exp_out= temp4[ind][i][1];

    if (confg == "pass"){
      continue;
    }
    else{
      if (pinm(confg,exp_out) == 1){
        passes= passes+1;
      }
      else{
        fails = fails+1;
      }

    }
  }
  }

  status_of_test[0]=passes;
  status_of_test[1]=fails;
  status_of_test[2]= passes+fails;
}

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

String state = "home";  //This variable changes with interfaces --- used for identifying the interface
String tested_state = "not tested"; //If the tested component is ok or not ok. Default is "not tested"
String retest_mode = "off";

int mode_selected = 0;  //This vriable is for store the mode(pin selection/BJT/Bluetooth) --- for choosing operating mode
int bjt_selected = 0;   //NPN or PNP 
int return_home = 0;    //This variable is for selecting Retest or Home

int page = 0; //used for breaking the IC list to pages
int ic_sel = 0; //used for going up and down in a ic page
int ic_ind;
int pin_number = 0;
int max_pages;

String pin_4[20] = {"comp1", "comp2", "comp3", "comp4","comp5","comp6","comp7","comp8","comp9","comp10","comp11","comp12","comp13","comp14","comp15","comp16","comp17","comp18","comp19","comp20"};
String pin_6[20] = {"comp1", "comp2", "comp3", "comp4","comp5","comp6","comp7","comp8","comp9","comp10","comp11","comp12","comp13","comp14","comp15","comp16","comp17","comp18","comp19","comp20"};
String pin_8[20] = {"comp1", "comp2", "comp3", "comp4","comp5","comp6","comp7","comp8","comp9","comp10","comp11","comp12","comp13","comp14","comp15","comp16","comp17","comp18","comp19","comp20"};
// String pin_12[20] = {"comp1", "comp2", "comp3", "comp4","comp5","comp6","comp7","comp8","comp9","comp10","comp11","comp12","comp13","comp14","comp15","comp16","comp17","comp18","comp19","comp20"};
String pin_10[20] = {"comp1", "comp2", "comp3", "comp4","comp5","comp6","comp7","comp8","comp9","comp10","comp11","comp12","comp13","comp14","comp15","comp16","comp17","comp18","comp19","comp20"};
String pin_14[13] = {"SN74HC00N", "CD74HC4075", "CD54HC4075", "CD74HCT86", "SN74HC08","SN54HC08","SN74ALS32","SN54ALS32","SN54HCT00","SN74HCT00","74LCX05FT","SN74LS14N","CD54HC4075"};


// declare an SSD1306 display object connected to I2C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String message;

void setup() 
{   
  //bluetooth Declare
  pinMode( 19, INPUT_PULLUP );
  Serial1.begin(9600);
  pinMode(OK_LED, OUTPUT);
  pinMode(NOT_LED, OUTPUT);
//_______________________BJT
  pinMode(3, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
//_________________________

    pinMode(UP_PIN, INPUT);
    pinMode(DOWN_PIN, INPUT);
    pinMode(OK_PIN, INPUT);
    pinMode(LEFT_PIN, INPUT);
    pinMode(RIGHT_PIN, INPUT);


    // initialize OLED display with address 0x3C for 128x64
    if (!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        while (true);
    }

    delay(2000);         // wait for initializing
    oled.clearDisplay(); // clear display
    oled.setTextSize(2);          // text size
    oled.setTextColor(WHITE);     // text color
    oled.setCursor(20, 20);        // position to display
    oled.println("Welcome!"); // text to display
    oled.setTextSize(1);          // text size
    oled.setCursor(85, 55);        // position to display
    oled.println("CodeRed"); // text to display
    oled.display();               // show on OLED
    oled.clearDisplay(); // clear display
    delay (2000);
}


void loop() 
{   
    int up_val = digitalRead(UP_PIN);
    int down_val = digitalRead(DOWN_PIN);
    int left_val = digitalRead(LEFT_PIN);
    int right_val = digitalRead(RIGHT_PIN);
    int ok_val = digitalRead(OK_PIN);
    // Serial.println(" OK:  " + String(ok_val));
    // Serial.println(" up:  " + String(up_val));
    // Serial.println(" down:  " + String(down_val));
    // Serial.println(" right:  " + String(right_val));
    // Serial.println(" left:  " + String(left_val));
    //delay(5000);
    // Serial.print(ok_val);
    // Serial.println("Down ");
    // Serial.print(down_val);
    // Serial.println("uUp ");
    // Serial.print(up_val);
    // Serial.println(" Right");String
    // Serial.print(right_val);
    // Serial.println(" left");
    // Serial.print(left_val);
    
    if (state =="NPN" || state == "PNP"){
     int bjt_tested_state= bjt_tests(state);
     state = "checked_bjt";
    
     Bjt_succ(bjt_tested_state);
     
    }

    if ( state == "checked_bjt"){
      int left_val= digitalRead(LEFT_PIN);
      int right_val= digitalRead(RIGHT_PIN);
      
      if (left_val == 1){
        state ="BJT";
        delay(100);
      }
      else if(right_val == 1){
        state ="home";
        tested_state = "not tested";
        state = "home";
        mode_selected = 0; 
        bjt_selected = 0;  
        return_home = 0;    
        page = 0; 
        ic_sel = 0; 
        pin_number = 0;
        retest_mode = "off";
        delay(100);
        bjt_selected=0;
      }

    }

    if ( state == "blue_checked"){
      int left_val= digitalRead(LEFT_PIN);
      int right_val= digitalRead(RIGHT_PIN);
      
      if (left_val == 1){
        state =" Bluetooth";
        delay(100);
      }
      else if(right_val == 1){
        state ="home";
        delay(100);
      }

    }


    if ( state == " Bluetooth" ){
      bluetoothMode();
      String capt="";
      while(Serial1.available())
        {//while there is data available on the serial monitor
        message+=char(Serial1.read());//store string from serial command
        }

      if(!Serial1.available())

      {
      if(message!="") //"O01VG01O,1010"
      {
        //if data is available
      Serial1.print("Got Message -> ");
      Serial1.println(message); //show the data

      String Config_blu= message;//00O00OGO00O00V
      //String Config_outs="1111";

      //int blue_state = pinm(Config_blu,Config_outs);
      capt = pinm_blue(Config_blu);
      Serial1.print("Got Message -> ");
      Serial1.println(capt); //show the data

     // Blue_succ(blue_state);
     Blue_succ(capt);

      state = "blue_checked";

      message=""; //clear the data
    }
  }
}



    if (state == "home"){
        displayMenu();
        selectMenu();
    }

    else if (state == " Pin Selection"){
        pinSelection();
        pinnumSelect();
        
    }
  
    else if (state == " BJT"){
        bjtModel();
        bjtSelect();
    }

    else if (state == "  4"){
        
        if (retest_mode == "on"){
            compOK();
            retest_mode = "off";
        }

        else if (tested_state == "tested"){
              homeorretest();
            }


        else{
            icPages(page, pin_4, 20);
            backFoward();
            int ok_val =digitalRead(OK_PIN);
            Serial.println(" OK:  " + String(ok_val));
            if (ok_val == 1){
              compOK();
              
            }
  
        }
    }


    else if (state == "  6"){
        if (retest_mode == "on"){
            compOK();
            retest_mode = "off";
        }

        else if (tested_state == "tested"){
              homeorretest();
            }


        else{
            icPages(page, pin_6, 20);
            backFoward();
            int ok_val =digitalRead(OK_PIN);
            Serial.println(" OK:  " + String(ok_val));
            if (ok_val == 1){
              compOK();
              
            }
  
        }
    }



    else if (state == "  8"){
        if (retest_mode == "on"){
            compOK();
            retest_mode = "off";
        }

        else if (tested_state == "tested"){
              homeorretest();
            }


        else{
            icPages(page, pin_8, 20);
            backFoward();
            int ok_val =digitalRead(OK_PIN);
            Serial.println(" OK:  " + String(ok_val));
            if (ok_val == 1){
              compOK();
              
            }
  
        }
    }





    else if (state == " 10"){
        if (retest_mode == "on"){
            compOK();
            retest_mode = "off";
        }

        else if (tested_state == "tested"){
              homeorretest();
            }


        else{
            icPages(page, pin_10, 20);
            backFoward();
            int ok_val =digitalRead(OK_PIN);
            Serial.println(" OK:  " + String(ok_val));
            if (ok_val == 1){
              compOK();
              
            }
  
        }
    }

    else if (state == " 14"){
        if (retest_mode == "on"){
            compOK();
            retest_mode = "off";
        }

        else if (tested_state == "tested"){
              homeorretest();
            }


        else{
            icPages(page, pin_14, 13);
            backFoward();
            int ok_val =digitalRead(OK_PIN);
            Serial.println(" OK:  " + String(ok_val));
            if (ok_val == 1){
              compOK();
              
            }
        }
      }
}


void Bjt_succ(int state){
  if (state == 1){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(10, 25);
    oled.println(" Check Passed!");
    oled.setCursor(0, 50);
    oled.println("< Retry");
    oled.setCursor(90, 50);
    oled.println("Home >");
    oled.display();
    digitalWrite(OK_LED, HIGH);
    delay(4000);
    digitalWrite(OK_LED, LOW);
  }
  else if( state == 0){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(10, 25);
    oled.println("Failed the Check!");
    oled.setCursor(0, 50);
    oled.println("< Retry");
    oled.setCursor(90, 50);
    oled.println("Home >");
    oled.display();
    digitalWrite(NOT_LED, HIGH);
    delay(4000);
    digitalWrite(NOT_LED, LOW);
  }
}


void Blue_succ(String cap){
  
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(10, 20);
    oled.println(" Output Values-");
    oled.setCursor(10, 30);
    oled.println(cap);
    oled.setCursor(0, 50);
    oled.println("< Resend");
    oled.setCursor(90, 50);
    oled.println("Home >");
    oled.display();
    delay(4000);
  // else if( state == 0){
  //   oled.clearDisplay();
  //   oled.setTextSize(1);
  //   oled.setTextColor(SSD1306_WHITE);
  //   oled.setCursor(10, 25);
  //   oled.println("Failed the Check!");
  //   oled.setCursor(0, 50);
  //   oled.println("< Resend");
  //   oled.setCursor(98, 50);
  //   oled.println("Home >");
  //   oled.display();
  //   delay(4000);
  // }
}

//this function is for homepage
void displayMenu()
{ 
    int up_val = digitalRead(UP_PIN);
    int down_val = digitalRead(DOWN_PIN);
    
    const char *modes[3] = {
      " Pin Selection",
      " BJT",
      " Bluetooth"
    };

    //Moving between modes
    if (up_val == 1){
      if (mode_selected == 0) {
        mode_selected  = 2;
      }
      else{
        mode_selected = mode_selected - 1;
      }
      delay(150);
    }

    else if (down_val == 1){
      if (mode_selected == 2) {
        mode_selected  = 0;
      }
      else{
        mode_selected = mode_selected + 1;
      }
      delay(150);
    }

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 10);
    oled.println("Select the Mode");
    oled.setCursor(0, 25);

    for (int i = 0; i < 3; i++) {
      if (i == mode_selected){
        oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        oled.println(modes[i]);
      }

      else{
        oled.setTextColor(SSD1306_WHITE);
        oled.println(modes[i]);
      }
    }

    oled.display();
}


//this function is for select item for home menu
void selectMenu()
{
  int ok_val = digitalRead(OK_PIN);

  const char *modes[3] = {
    " Pin Selection",
    " BJT",
    " Bluetooth"
  };

  if (ok_val == 1){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(10, 25);
    oled.println("--"+String(modes[mode_selected])+" --");
    oled.display();
    state = modes[mode_selected]; //state changes to the mode
    delay(1000);
    mode_selected = 0;
  }
}

//this is for pin selection page
void pinSelection()
{ 
    int up_val = digitalRead(UP_PIN);
    int down_val = digitalRead(DOWN_PIN);

    const char *pin[5] = {
      "  4",
      "  6",
      "  8",
      " 10",
      " 14"
    };

    //Moving between modes
    if (up_val == 1){
      if (pin_number == 0) {
        pin_number  = 4;
        delay(100);
      }
      else{
        pin_number = pin_number - 1;
        delay(100);
      }
    }

    else if (down_val == 1){
      if (pin_number == 4) {
        pin_number  = 0;
        delay(100);
      }
      else{
        pin_number = pin_number + 1;
        delay(100);
      }
    }

    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 0);
    oled.println("Select the Number of Pins");
    oled.setCursor(0, 20);

    for (int i = 0; i < 5; i++) {
      if (i == pin_number){
        oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
        oled.println(pin[i]);
      }

      else{
        oled.setTextColor(SSD1306_WHITE);
        oled.println(pin[i]);
      }
      
    }
    oled.display();
}

//this is for selectig number of pins
void pinnumSelect()
{
    int ok_val = digitalRead(OK_PIN);

    const char *pin[5] = {
      "  4",
      "  6",
      "  8",
      " 10",
      " 14"
    };

    if (ok_val == 1){
      state = pin[pin_number];
    }

    delay(150);
}

//this is for bjt interface
void bjtModel()
{
    int up_val = digitalRead(UP_PIN);
    int down_val = digitalRead(DOWN_PIN);

    const char *bjt[2] = {
        "NPN",
        "PNP"
    };

    if ((up_val == 1)||(down_val == 1)){
      if (bjt_selected == 0){
        bjt_selected = 1;
      }
      else if (bjt_selected == 1){
        bjt_selected = 0;
      }
      delay(150);
    }
  
    if (bjt_selected == 0){
      oled.clearDisplay();
      oled.setTextSize(1);
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(0, 10);
      oled.println("Select the BJT model");
      oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      oled.setCursor(10, 30);
      oled.println("PNP");
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(10, 45);
      oled.println("NPN");
      oled.display();
      delay(100);
    }

    else if (bjt_selected == 1){
      oled.clearDisplay();
      oled.setTextSize(1);
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(0, 10);
      oled.println("Select the BJT model");
      oled.setTextColor(SSD1306_WHITE);
      oled.setCursor(10, 30);
      oled.println("PNP");
      oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      oled.setCursor(10, 45);
      oled.println("NPN");
      oled.display();
      delay(100);
    }
}

//this is for select pnp/npn
void bjtSelect()
{
  int ok_val = digitalRead(OK_PIN);
  const char *bjt[2] = {
    "NPN",
    "PNP"
  };

  if (ok_val == 1){
    oled.clearDisplay();
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 10);
    oled.println(bjt[bjt_selected]);
    oled.display();
    state = bjt[bjt_selected]; //state changes to the mode
    delay(100);
    bjt_selected = 0;
  }
}

//this is for connecting a device
/*void connectDevice(String component){
    oled.setTextSize(1);
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(20, 0);
    oled.println("Connect the "+component);
    oled.setCursor(40, 0);
    oled.println("Then press OK");
    oled.display();
}*/


//this is for showing ics page by page
void icPages(int page, String pin_4[], int numIC)
{  
  int up_val = digitalRead(UP_PIN);
  int down_val = digitalRead(DOWN_PIN);

  int Start, End;
  //Serial.println(sizeof(pin_4));
  max_pages = ceil(numIC/6);
  //Serial.println("max pages: "+ String(max_pages));
  Start = page*6;
  //const int numIC = 20;

  if (numIC < Start+6){
    End = numIC;
  }
  else{
    End = Start+6;
  }

  oled.clearDisplay();         // clear display
  oled.setTextSize(1);         // text size
  oled.setCursor(0, 0);        // position to display

  for (int k=Start; k<End; k++){
    if (k == (Start + ic_sel)){
      ic_ind = k;
      oled.setTextColor(SSD1306_BLACK, SSD1306_WHITE);
      oled.println(pin_4[k]); 
    }
    else{
      oled.setTextColor(SSD1306_WHITE);
      oled.println(pin_4[k]);
    }
  }
  

  if (page != max_pages){
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(104, 50);
    oled.println(">");
  }

  if (page != 0){
    oled.setTextColor(SSD1306_WHITE);
    oled.setCursor(0, 50);
    oled.println("<");
  }

  oled.display();

  if (up_val==1){
    if (ic_sel == 0){
      if (page == max_pages){
        ic_sel = numIC - 6*(max_pages) -1;
        Serial.println("ic_sel: "+ String(ic_sel));
      }
      else{
        ic_sel = 5;
      }
    }
    else{
      ic_sel = ic_sel - 1;
    }
    delay(100);
  }

  if (down_val==1){

    if (page == max_pages){
        if (max_pages*6 + ic_sel +1 == numIC){
          ic_sel = 0;
        }
        else{
          ic_sel = ic_sel + 1;
        }
    }
    else if(ic_sel == 5)
    {
      ic_sel=0;   
    }
    
    else{
      ic_sel = ic_sel + 1;
    }
    delay(100);
  }
}

//back and forward pages
void backFoward()
{
  int right_val = digitalRead(RIGHT_PIN);
  int left_val = digitalRead(LEFT_PIN);

  if (right_val == 1){
    if (page != max_pages){
    page= page+1;
    ic_sel = 0;
    }
    delay(150);
  }

  if (left_val == 1){
    if (page != 0){
    page= page-1;
    ic_sel = 0;
    }    
    delay(150);
  }
}

//select the component and do testing
void compOK(){
  int ind = page*6 + ic_sel;
  index_sel[1] = ind;
  index_sel[0] = pin_number; //4,6,8,12,14

  oled.clearDisplay();         // clear display
  oled.setTextSize(1);         // text size
  oled.setCursor(20, 25);        // position to display
  oled.println("Testing.... ");
  oled.display();
  delay(100);

  multi(index_sel[1]);
  tested_state = "tested";
  if (tested_state == "tested"){
    if (status_of_test[1] != 0){
      oled.clearDisplay();        
      oled.setTextSize(1);         
      oled.setCursor(20,10);        
      oled.println("Out of " + String(status_of_test[2]));
      oled.setCursor(25,20);
      oled.println(" test cases");
      oled.setCursor(35,30);
      oled.println(String(status_of_test[0])+ " passed!!!");
      digitalWrite(NOT_LED, HIGH);
      delay(4000);
      digitalWrite(NOT_LED, LOW);
    }
    else{
      oled.clearDisplay();         // clear display
      oled.setTextSize(1);         // text size
      oled.setCursor(20, 15);
      oled.println("All test cases");
      oled.setCursor(35, 25);
      oled.println("passed!!!");
      digitalWrite(OK_LED, HIGH);
      delay(4000);
      digitalWrite(OK_LED, LOW);
    }
    
  }
  
}

void homeorretest()
{
  int right_val = digitalRead(RIGHT_PIN);
  int left_val = digitalRead(LEFT_PIN);

  oled.setTextSize(1);
  
  oled.setTextColor(SSD1306_WHITE);
  oled.setCursor(0,50);
  oled.println("< Retest");
  oled.setCursor(90,50);
  oled.println("Home >");
  
  oled.display();

  

      if (right_val == 1){
        state = "home";
        tested_state = "not tested";
        state = "home";
        mode_selected = 0; 
        bjt_selected = 0;  
        return_home = 0;    
        page = 0; 
        ic_sel = 0; 
        pin_number = 0;
        retest_mode = "off";
      }
      else if (left_val == 1){
        tested_state = "not tested";
        retest_mode = "on";
      }
}

void bluetoothMode(){
  oled.clearDisplay();         // clear display
  oled.setTextSize(1);         // text size
  oled.setCursor(10, 25);  
  oled.println("Connecting.....");
  oled.display();
  delay(1000);
  //Connect the Bluetooth
}

