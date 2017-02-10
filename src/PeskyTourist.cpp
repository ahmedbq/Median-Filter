//Ahmed B. Qureshi 700636758

#include <graphics.h>
#include <stdio.h>
using namespace std;

void loadImage (int imageNumber);
void sort (int passedIn[], int length);
void median (int a [], int length);


int main(){

int pic[200][225][9];

//Create windows
int firstWindow = initwindow (200,225, "Pictures");
int finalWindow = initwindow (200,225, "FinalPicture");
setcurrentwindow(firstWindow);

//Cycles through each picture to GET all pixels
for (int picNum=0; picNum<9; picNum++){
loadImage(picNum); //Uses loadImage Method
	for (int x = 0; x<200; x++){
		for (int y = 0; y<225; y++){
		pic[x][y][picNum]=getpixel(x,y);}}}

int redPixels[9];
int bluePixels[9];
int greenPixels[9];
int Pixels;

setcurrentwindow(finalWindow);

//Cycles through each picture to PUT all pixels
for (int a = 0; a < 200; a++){
	loadImage(picNum); //Uses loadImage Method
	for (int b = 0; b < 225; b++){
		for(int picNum = 0; picNum < 9; picNum++){
			Pixels = getpixel(a,b);
			//This collects the values

			bluePixels[picNum] = BLUE_VALUE(Pixels);
			redPixels[picNum] = RED_VALUE(Pixels);
			greenPixels[picNum] = GREEN_VALUE(Pixels);
			//This stores the values
			}

		sort(bluePixels, 9); //Uses bubble sorting method
		sort(redPixels, 9);
		sort(greenPixels, 9);
		//Median Function happens now
		median(bluePixels, 9);
		median(redPixels, 9);
		median(greenPixels, 9);

		putpixel(a,b,COLOR(redPixels[1],bluePixels[1],greenPixels[1])); //Puts the values into the final picture. CAN MAKE 1 INTO A 4. WHATS THE POINT OF MEDIAN METHOD

	}

}



} //last bracket for main function




//Bubble sorting method
void sort (int passedIn[], int length){
for (int k=0; k<length; k++){
	for (int p=k+1; p<length; p++){
		if (passedIn[k]>passedIn[p]){
			int temp1 = passedIn[k];
			int temp2 = passedIn[p];
			passedIn[p] = temp1;
			passedIn[k] = temp2;
			}
		}
	}
}

//loadImage Method
void loadImage(int imageNumber){
     char str[5];
     sprintf(str, "%i.jpg", imageNumber);
     readimagefile(str,0,0,200,225);}



//Calculates the median of the array

void median (int a [], int length){
	a[1] = a[5];
}
