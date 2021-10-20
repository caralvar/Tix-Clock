const int MINUTES_BUTTON_PIN = 5;
const int HOURS_BUTTON_PIN = 6;
const int MODIFY_HOUR_PIN = 7;
const int NUMBER_OF_INPUT_PINS = 2;
int INPUT_PINS[] = {MINUTES_BUTTON_PIN,HOURS_BUTTON_PIN};
const int DATA_PIN = 2;
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};
const int SECONDS_PERIOD_IN_MS = 1000;
int hour = 0;
int minute = 0;
int second = 0;

void SetInputPins(int[], int);
void SetOutputPins(int[], int);
int GetTensFromNumber(int);
int GetUnitsFromNumber(int);
int GiveMeRandomNumber(int, int);
int AddOneBasedOnInput(int, int);

void setup() 
{
    SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);
    SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);
    Serial.begin(9600);
}

void loop() 
{
    if (digitalRead(MODIFY_HOUR_PIN))
    {
        hour = AddOneBasedOnInput(HOURS_BUTTON_PIN, hour);
        minute = AddOneBasedOnInput(MINUTES_BUTTON_PIN, minute);    
    } 
    Serial.print("Hora: ");
    Serial.println(hour);
    Serial.print("Minutos: ");
    Serial.println(minute);
    delay(SECONDS_PERIOD_IN_MS);      
}
  
void SetInputPins(int inputPins[], int numberOfInputPins)
{
    for (int i = 0; i < numberOfInputPins; i++)
    {
        pinMode(inputPins[i], INPUT);
    }
}

void SetOutputPins(int outputPins[], int numberOfPins)
{
    for (int i = 0; i < numberOfPins; i++)
    {
        pinMode(outputPins[i], OUTPUT);
    }
}

int AddOneBasedOnInput(int inputPin, int numberToUpdate)
{
    if (digitalRead(inputPin))
    {
        numberToUpdate++; 
    }
    return(numberToUpdate);
}

int GetTensFromNumber(int number)
{
    int tensNumber;
    tensNumber = number / 10;
    return tensNumber;
}

int GetUnitsFromNumber(int number)
{
    int unitsNumber;
    unitsNumber = number % 10;
    return unitsNumber;  
}

int GiveMeRandomNumber(int lowerLimit, int upperLimit)
{
    int randomNumber;
    randomNumber = random(lowerLimit, upperLimit + 1);
    return randomNumber;
}
