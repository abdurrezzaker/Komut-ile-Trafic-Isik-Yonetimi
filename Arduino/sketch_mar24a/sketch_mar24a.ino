
int L_N_Green = 8;
int L_N_Yellow = 9;
int L_N_Red = 10;
int L_S_Red = 11;
int L_S_Yellow = 12;
int L_S_Green = 13;
int cState = 0;
String okunanDeger = "";

void setup() {
  pinMode(L_N_Red, OUTPUT);
  pinMode(L_N_Yellow, OUTPUT);
  pinMode(L_N_Green, OUTPUT);
  pinMode(L_S_Red, OUTPUT);
  pinMode(L_S_Yellow, OUTPUT);
  pinMode(L_S_Green, OUTPUT);
  Serial.begin(9600);
  //Serial.flush();
}

void loop() {

  constant_state();
  if (Serial.available()) {

    char okunanKarakter = Serial.read();
    if (okunanKarakter != '*') {
      Serial.print(okunanKarakter);
      okunanDeger += okunanKarakter;
    } else {
      Serial.println();
      Serial.println("Enter tusuna bastin.");
      Calistir();
    }
  }
}
void Calistir() {
  //if (Serial.available()) {

  //if (enterOku == '\n') {
  //String okunanDeger = Serial.readString();

  int temp = okunanDeger.indexOf(' ');
  String komut1 = okunanDeger.substring(0, temp);
  okunanDeger = okunanDeger.substring(temp + 1);

  temp = okunanDeger.indexOf(' ');
  String komut2 = okunanDeger.substring(0, temp);
  okunanDeger = okunanDeger.substring(temp + 1);

  temp = okunanDeger.indexOf(' ');
  String komut3 = okunanDeger.substring(0, temp);
  okunanDeger = okunanDeger.substring(temp + 1);

  temp = okunanDeger.indexOf(' ');
  String komut4 = okunanDeger.substring(0, temp);
  okunanDeger = okunanDeger.substring(temp + 1);

  String komutArray[] = { komut1, komut2, komut3, komut4 };

  if (komutArray[0] == "Green1" && komutArray[2] == "Green2") {
    int Green1Value = komutArray[1].toInt();
    int Green2Value = komutArray[3].toInt();
    if (cState == 0)
      north_road_green(Green1Value, Green2Value);
    else
      south_road_green(Green1Value, Green2Value);

  } else if (komutArray[0] == "Red1" && komutArray[2] == "Red2") {
    int Red1Value = komutArray[1].toInt();
    int Red2Value = komutArray[3].toInt();
    if (cState == 0)
      south_road_red(Red1Value, Red2Value);
    else
      +(Red1Value, Red2Value);
  }
  /*for (int i = 0; i < 4; i++) {
    Serial.print(komutArray[i]);
    Serial.print(" ");
  }*/
  //}
  //}
}
void constant_state() {
  if (cState == 0) {
    digitalWrite(L_N_Red, HIGH);
    digitalWrite(L_S_Green, HIGH);
  } else {
    digitalWrite(L_N_Green, HIGH);
    digitalWrite(L_S_Red, HIGH);
  }
}
void south_road_green(int green1Value, int green2Value) {
  delay(green2Value - 750);
  digitalWrite(L_N_Yellow, HIGH);
  digitalWrite(L_S_Yellow, HIGH);
  delay(750);
  digitalWrite(L_N_Green, LOW);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, HIGH);
  delay(750);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, LOW);
  digitalWrite(L_S_Green, HIGH);
  delay(green1Value);
  north_road_green(green1Value, green2Value);
  //cState = 0;
}
void north_road_green(int green1Value, int green2Value) {
  delay(green1Value - 750);
  digitalWrite(L_S_Yellow, HIGH);
  digitalWrite(L_N_Yellow, HIGH);
  delay(750);
  digitalWrite(L_S_Green, LOW);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, HIGH);
  delay(750);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, LOW);
  digitalWrite(L_N_Green, HIGH);*
  delay(green2Value);
  south_road_green(green1Value, green2Value);
  //cState = 1;
}
void south_road_red(int red1Value, int red2Value) {
  delay(red2Value - 750);
  digitalWrite(L_S_Yellow, HIGH);
  digitalWrite(L_N_Yellow, HIGH);
  delay(750);
  digitalWrite(L_S_Green, LOW);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, HIGH);
  delay(750);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, LOW);
  digitalWrite(L_N_Green, HIGH);
  delay(red1Value - 750);
  south_road_red(red1Value, red2Value);
}
void north_road_red(int red1Value, int red2Value) {

  delay(red1Value - 750);
  digitalWrite(L_S_Yellow, HIGH);
  digitalWrite(L_N_Yellow, HIGH);
  delay(750);
  digitalWrite(L_N_Green, LOW);
  digitalWrite(L_N_Yellow, LOW);
  digitalWrite(L_N_Red, HIGH);
  delay(750);
  digitalWrite(L_S_Yellow, LOW);
  digitalWrite(L_S_Red, LOW);
  digitalWrite(L_S_Green, HIGH);
  delay(red2Value - 750);
  south_road_red(red1Value, red2Value);
}