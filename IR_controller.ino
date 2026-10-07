#include <IRremote.h>
#define IR_RECEIVE_PIN 12
#define LED_FIRST 11
#define LED_SECOND 10
#define LED_THIRD 9
#define ZERO 12
#define ONE 16
#define TWO 17
#define THREE 18

void setup()
{
    Serial.begin(115200);
    IrReceiver.begin(IR_RECEIVE_PIN);
    pinMode(LED_FIRST, OUTPUT);
    pinMode(LED_SECOND, OUTPUT);
    pinMode(LED_THIRD, OUTPUT);

}

void loop()
{
    if (IrReceiver.decode())
    {
        IrReceiver.resume();
 //Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    //Serial.println(IrReceiver.decodedIRData.command);
        int command = IrReceiver.decodedIRData.command;
        Serial.println(command);

        switch (command)
        {
            case ZERO:  
                digitalWrite(LED_FIRST, HIGH);
                digitalWrite(LED_SECOND, HIGH);
                digitalWrite(LED_THIRD, HIGH);
                break;

            case ONE:  
                digitalWrite(LED_FIRST, HIGH);
                digitalWrite(LED_SECOND, LOW);
                digitalWrite(LED_THIRD, LOW);
                break;

            case TWO:  
                digitalWrite(LED_FIRST, LOW);
                digitalWrite(LED_SECOND, HIGH);
                digitalWrite(LED_THIRD, LOW);
                break;

            case THREE:  
                digitalWrite(LED_FIRST, LOW);
                digitalWrite(LED_SECOND, LOW);
                digitalWrite(LED_THIRD, HIGH);
                break;

            default:
                break;
        }
    }
}
