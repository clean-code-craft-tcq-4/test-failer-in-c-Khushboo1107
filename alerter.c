#include <stdio.h>
#include <assert.h>
#include "alert.h"

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // Return 200 for ok
    // Return 500 for not-ok
    // stub always succeeds and returns 200
    if(celcius > Alert_Threshold) {
        return 500;
    } else {
        return 200;
    }
}
    
void alertInCelcius(float farenheit) {
   float celcius=(farenheit-32)*5/9);
     int returnCode = networkAlertStub(celcius)
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

int main() {
    alertInCelcius(303.6);
    alertInCelcius(400.5);
    alertInCelcius(500.4);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
