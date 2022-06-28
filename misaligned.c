#include <stdio.h>
#include <assert.h>
int getColorNumber(int i, int j){
return i*5+j;
}

char* formatRow(int colorNumber, const char* majorColorName, const char* minorColorName){
    static char rowBuffer[80];
    sprintf(rowBuffer, "%d | %s | %s\n", colorNumber, majorColorName, minorColorName);
}
int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf(formatRow(getColorNumber(i,j), majorColor[i], minorColor[i]));
        }
    }
    return i * j;
}

int main() {    
    int result = printColorMap();
    assert(result == 25);
    printf("All is well (maybe!)\n");
    return 0;
}
