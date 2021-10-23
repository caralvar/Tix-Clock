const int MINUTES_BUTTON_PIN = 5;
const int HOURS_BUTTON_PIN = 6;
const int NUMBER_OF_INPUT_PINS = 2;
int INPUT_PINS[] = {MINUTES_BUTTON_PIN,HOURS_BUTTON_PIN};
const int DATA_PIN = 2;
const int LATCH_PIN = 3;
const int CLOCK_PIN = 4;
const int NUMBER_OF_OUTPUT_PINS = 3;
int OUTPUT_PINS[] = {DATA_PIN, LATCH_PIN, CLOCK_PIN};
int hour = 0;
int minute = 0;
int second = 0;

void SetInputPins(int[], int);
void SetOutputPins(int[], int);
int GetTensFromNumber(int);
int GetUnitsFromNumber(int);
int GiveMeRandomNumber(int, int);
int AddOneBasedOnInput(int, int);
void UpdateClock();
  
void setup() 
{
    SetInputPins(INPUT_PINS, NUMBER_OF_INPUT_PINS);
    SetOutputPins(OUTPUT_PINS, NUMBER_OF_OUTPUT_PINS);
    Serial.begin(9600);
}

void loop() 
{

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
void UpdateClock() 
{
    second = second + 1;
    if(second == 60)
    {
        second = 0;
        minute = minute + 1; 
    }  
    if(minute == 60)
    {
        minute = 0;
        hour = hour + 1;  
    }  
    if (hour == 24)
    {
        hour = 0;  
    }
}
