#define CUSTOM_SETTINGS
#define INCLUDE_VOICE_RECOGNIZER_SHIELD
#define INCLUDE_TEXT_TO_SPEECH_SHIELD
#define INCLUDE_KEYBOARD_SHIELD
#define INCLUDE_SMS_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define INCLUDE_VIBRATION_SHIELD

#include <OneSheeld.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String msg;
int sent = 0;
int i = 0;
String phoneNum = ""; //write phone number here
int patternOne[6] = {1000, 2000, 1000, 2000, 1000, 2000};
int patternOneSize = 6;


void setup() {
  OneSheeld.begin();
  VoiceRecognition.start();
  lcd.begin(16, 2);
}


void loop() {
  //Blind to Deaf
  if (VoiceRecognition.isNewCommandReceived()) {
    String msg1 = VoiceRecognition.getLastCommand();

    //far contact if user said "sms" first
    if (msg1.substring(0, 3) == "sms") {
      String msg1f = msg1.substring(3);
      SMS.send (phoneNum, msg1f);
      TextToSpeech.say("sms sent");
      delay(4000);
    }
    //close contact
    else {
      if (msg1.length() > 16) {
        lcd.clear();
        lcd.setCursor(0, 0);
        for (int i = 0; i <= 16; i++) {
          lcd.print(msg1[i]);
        }
        lcd.setCursor(0, 1);
        for (int j = 16 ; j <= msg1.length() - 1 ; j++) {
          lcd.print(msg1[j]);
        }
      }
      else {
        lcd.clear();
        lcd.print(msg1);
      }

    }
  }
  //sms recieved
  SMS.setOnSmsReceive(GotSms);

  //Deaf to blind
  AsciiKeyboard.setOnButtonChange(&MsgBuild);


}

void GotSms(char * phoneNumber , char * messageBody)
{
  //for deaf
  Vibration.start(patternOneSize, patternOne);
  delay(6000);
  Vibration.stop();
  lcd.clear();
  lcd.print("you got an sms ");
  lcd.setCursor(0, 0);
  lcd.print(String(phoneNumber));
  delay(4000);
  String msg2 = String(messageBody);

  if (msg2.length() > 16) {

    lcd.clear();
    lcd.setCursor(0, 0);
    for (int i = 0; i <= 16; i++) {
      lcd.print(msg2[i]);
    }
    lcd.setCursor(0, 1);
    for (int j = 16 ; j <= msg2.length() - 1 ; j++) {
      lcd.print(msg2[j]);
    }
  }
  else {
    lcd.clear();
    lcd.print(msg2);
  }

  //for blind
  TextToSpeech.say("you got an sms from" + String(phoneNumber));
  delay(7000);
  TextToSpeech.say(messageBody);
  delay(300 * String(messageBody).length());
}

void MsgBuild (char pC)
{
  i++;
  if (sent < 2) {
    if (pC == 'S') {
      sent += 1;
      msg += pC;
    }
    else {
      sent = 0;
      msg += pC;
    }
  }
  else if (sent = 3) {
    i = i - 3;
    msg.remove(i);
    msg.toLowerCase();

    if (msg.substring(0, 3) == "sms") {
      String msgf = msg.substring(3);
      SMS.send (phoneNum, msgf);
      lcd.clear();
      lcd.print("sms sent");
      TextToSpeech.say("sms sent");
      delay(3000);
      sent = 0;
      msg = "";
      i = 0;
    }
    //close contact
    else {
      delay(2000);
      TextToSpeech.say(msg);

      if (msg.length() > 16) {
        lcd.clear();
        lcd.setCursor(0, 0);
        for (int i = 0; i <= 16; i++) {
          lcd.print(msg[i]);
        }
        lcd.setCursor(0, 1);
        for (int j = 16 ; j <= msg.length() - 1 ; j++) {
          lcd.print(msg[j]);
        }
      }
      else {
        lcd.clear();
        lcd.print(msg);
      }
      delay(300 * msg.length());
      sent = 0;
      msg = "";
      i = 0;
    }
  }
}