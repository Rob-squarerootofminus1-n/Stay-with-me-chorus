#define C2  65
#define C3  131
#define GH2 104
#define GH3 208
#define AH2 116
#define AH3 233 
#define C4  262
#define DH3 155
#define DH4 311
#define AH4 466
#define C5  523
#define GH4 416
#define DH5 622 
#define AH5 932 
#define C6 1046
#define G4  392
#define G5 792
#define FH4 370
#define FH5 740
#define GH5 832
#define F4  344
#define F5 688
#define A4  440
#define A5 880
#define D4  288
#define D5  576
#define G3 198
#define E4 329
#define REST 0
#define B4 494
#define CH4 277


int piezo = 8; 
int led = 7; 

volatile int beatlength = 120; 
float beatseparationconstant = 0.3;





int chorus_stay_with_me[] = {
  F4,1, F4,16, F4,16, REST,-4, F4,16, F4,16, //tiiiiii-  titi-     titi-
  REST,-4, F4,8, G4,8, A4,2, REST,16, F4,8,
  A4,8, A4,8, G4,8, G4,16, G4,16, C5,8, C5,8, AH4,16, AH4,8, A4,16,
 A4,2, REST,16, 
 F4,8, A4,8, A4,8, G4,8, G4,8, AH4,8, A4,8, A4,8, A4,-8,REST, 32, F4,8, F4,4,REST,16, A4,8,REST,16, 
 D4,8, F4,8, A4,8, AH4,8, C5,8, F4,8, F4,4, D4,8, F4,8, A4,8, AH4,8, C5,8, F4,8, F4,4,D4,8, F4,8, A4,8, AH4,8, C5,8, F4,8, F4,4,REST,16, 
 F4,8, G4,8, A4,2,F4,4, A4,8, A4,8, G4,8, G4,8, AH4,16, AH4,8,A4,16,
   
};

int notes = sizeof(chorus_stay_with_me) / sizeof(chorus_stay_with_me[0]) / 2;

int wholenote = (60000 * 4) / beatlength;

int divider = 0, noteDuration = 0;

void setup() {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    divider = chorus_stay_with_me[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; 
    }

    tone(piezo, chorus_stay_with_me[thisNote], noteDuration*0.9);

    delay(noteDuration);
    
    
    noTone(piezo);
        

      


  }
}


void loop()
{
}
