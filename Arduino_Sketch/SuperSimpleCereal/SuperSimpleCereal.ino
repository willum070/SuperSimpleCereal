/*
  Super Simple Cereal example sketch.
*/

int numCharRead = 0;
char incomingData[20];

void setup() {  
    //Setup the serial port
    Serial.begin(9600);
}

// Infinite loop to get user input:
void loop() {
    if (Serial.available() > 0) {
        // Read input and copy to buffer 'incomingData'.
        numCharRead = Serial.readBytes(incomingData, 19);

        // Send buffer
        processCommands(numCharRead);        
    }
}

int processCommands(int numCharRead ) {
    switch(incomingData[1]) {
        
        // Return the device ID string.
        case '?':
            Serial.print("[My_Arduino_1234567890]");
            break;
             
        case 'L':
            Serial.print("[Another command!!!]");
            break;      
            
        default:
            Serial.print("[!No matching command]");
    }
}
