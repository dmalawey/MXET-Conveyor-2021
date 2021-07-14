// DPM modified library for simple calls to sounds
// as of 2021.07

#include <CuteBuzzerSounds.h>
#define BUZZER_PIN D5 // THE (+) PIN OF THE BUZZER (formerly D4)
#define BUZZER_GND D3 // // GROUND PIN FOR BUZZER

void setupBZ(){
  pinMode(BUZZER_GND, OUTPUT); 
  digitalWrite(BUZZER_GND, LOW); // SET BUZ GND LOW
  cute.init(BUZZER_PIN);
}

void playAll(){       // this functi on is to be broken down later.
cute.play(S_MODE3);
cute.play(S_OHOOH2);
cute.play(S_HAPPY);
cute.play(S_SAD);
cute.play(S_FART2);
cute.play(S_OHOOH);
cute.play(S_SLEEPING);  // skip this one
cute.play(S_HAPPY_SHORT);
cute.play(S_FART1);
cute.play(S_BUTTON_PUSHED);
cute.play(S_HAPPY);
cute.play(S_CONNECTION);
cute.play(S_MODE1);
cute.play(S_SURPRISE);
cute.play(S_CUDDLY);  
cute.play(S_SUPER_HAPPY);
cute.play(S_CONFUSED);
cute.play(S_FART3);
cute.play(S_DISCONNECTION);
cute.play(S_MODE2);
}

// There are 18 possible sounds in the library.
// This case structure offers 9 sounds.
// ASCII characters 1 thru 9 are used so we can take commands directly
// from serial or MQTT characters

void bzChirp(int sound_select) {  // USE THIS FUNCTION FOR CALLING ON SOUNDS
  if (sound_select == 49){ // corresponds to ASCII 1
    cute.play(S_MODE3);
  }
  if (sound_select == 50){ // corresponds to ASCII 2
    cute.play(S_OHOOH2);
  }
  if (sound_select == 51){
    cute.play(S_HAPPY);
  }
  if (sound_select == 52){
    cute.play(S_SAD);
  }
  if (sound_select == 53){
    cute.play(S_FART2);
  }
  else if (sound_select == 54){
    cute.play(S_HAPPY);
  }
  else if (sound_select == 55){
    cute.play(S_HAPPY_SHORT);
  }
  else if (sound_select == 56){
    cute.play(S_FART1);
  }
  else if (sound_select == 57){
  cute.play(S_BUTTON_PUSHED);
  }
  else { 
  //do nothing
  }
}
