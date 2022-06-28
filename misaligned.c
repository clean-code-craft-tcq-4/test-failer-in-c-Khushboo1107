#include <stdio.h>
#include <assert.h>
struct colorMap
{
	int pairNumber;
	char *majorColor;
	char *minorColor;
}

const int numberofValues = 25;
struct colorMap colorMapCollection[25];
  const char* MajorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
  const char* MinorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

void getColorMap()
{
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			colorMapCollection[i*5+j].pairNumber =i*5+j;
			colorMapCollection[i*5+j].majorColor =(char *)MajorColor[i];
			colorMapCollection[i*5+j].minorColor =(char *)MinorColor[j];
		}
	}
}

void printColorMap()
{
	for(int i=0; i <numberofValues; i++)
	{
		printf("%d | %s | %s\n", colorMapCollection[i].pairNumber, colorMapCollection[i].majorColor, colorMapCollection[i].minorColor);
	}
}
void TestFunction()
{
	for(int i=0; i<26; i++)
	{
		assert(colorMapCollection[i].pairNumber == i+1);
		assert(colorMapCollection[i].majorColor == MajorColor[i]);
		assert(colorMapCollection[i].minorColor == MinorColor[i]);
	}
}

intMain()
{
	getColorMap();
	printColorMap();
	TestFunction();
	printf("All is well (maybe!)\n");
    return 0;
}
