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

float farenheitToCelciusConverter(float farenheit) {
    return ((farenheit-32)*5/9);
}
    
void alertInCelcius(float farenheit, int (*Fn_Ptr_NetworkAlert)(float)) {
    float celcius = farenheitToCelciusConverter(farenheit);
    int returnCode = Fn_Ptr_NetworkAlert(celcius);
    if (returnCode != 200) {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 1;
    }
}

void testTempAlerter(float farenheit, int expectedFailCount) {
    int (*Fcn_Ptr_networkAlert)(float);
    Fcn_Ptr_networkAlert = &networkAlertStub;
    alertInCelcius(farenheit,Fcn_Ptr_networkAlert);
    assert(alertFailureCount == expectedFailCount);
}

int main() {
    testTempAlerter(303.6,0);
    testTempAlerter(400.5,1);
    testTempAlerter(500.4,2);
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
