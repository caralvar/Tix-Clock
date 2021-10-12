const int MINUTES_BUTTON_PIN = 5;
const int HOURS_BUTTON_PIN = 6;
const int NUMBER_OF_INPUT_PINS = 2;
int INPUT_PINS[] = {MINUTES_BUTTON_PIN,HOURS_BUTTON_PIN};
void SetInputPins(int[], int[]);

void setup() {
  // put your setup code here, to run once:
  SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);
}

void loop() {
  // put your main code here, to run repeatedly:

}
