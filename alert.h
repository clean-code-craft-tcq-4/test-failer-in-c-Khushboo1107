float farenheitToCelciusConverter(float farenheit);
int networkAlertStub(float celcius);
void alertInCelcius(float farenheit, int (*Fn_Ptr_NetworkAlert)(float));
void testTempAlerter(float farenheit, int expectedFailCount);

#define Alert_Threshold 200
