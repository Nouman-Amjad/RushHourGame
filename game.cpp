//============================================================================
// Name        : Nouman_Amjad.cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>
#include<fstream>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
                                                                                                                                   
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
 }

 int hscores[10];		//array for storing highscores after reading the file
 string names[10];		//array for storing name of person who made highscores
 int treerandx[6]={0},treerandy[6]={0};	// array for random cooordinates of trees
 int manrandx[6]={0},manrandy[6]={0};		// array for random cooordinates of mans or passanger
 int pixels[20][20]={0};			// MAin array that store the values against any block or tree
 int xI = 120, yI =760 ;			
 int score=0;				// variable for storing score of the player
 bool displayflag = true;		
 string taxi_color;			//String for saving the taxi color  

void drawRedCar() {	//this function will draw RED car for player
	DrawCircle( (xI+5) , (yI+2) , 6.5 ,colors[BLACK] );
	DrawCircle( (xI + 37) , (yI+2) , 6.5 ,colors[BLACK] );
	DrawCircle((xI + 21) , (yI + 25),10,colors[BLACK]);
	DrawRectangle( (xI+5) , (yI+2) , 35 , 23 , colors[RED]); 
	glutPostRedisplay();
	}

void drawYellowCar() {		//this function will draw YELLOW car for player
	DrawCircle( (xI +5) , (yI+2) , 6.5 ,colors[BLACK] );
	DrawCircle( (xI + 37) , (yI+2) , 6.5 ,colors[BLACK] );
	DrawCircle((xI + 21) , (yI + 25),10,colors[BLACK]);
	DrawRectangle( (xI+3.5) , (yI+2), 35 , 23 , colors[GOLD]); 
	glutPostRedisplay();
	}
	
 int A=2;
 int bx[10]={0}, by[10]={0};
 int bcx=400,bcy=120;		// coordinates of Blue car moving automatically
 bool flag = true;		// bool for moment of car 1
void drawBlueCar(){		// This  function is displaying Blue car on the screen that moves automatically
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx +5) , (bcy + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx + 37) , (bcy + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx + 21) , (bcy + 25),10,colors[BLACK]);
	DrawRectangle( (bcx +5) , (bcy + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}

void moveBlueCar() {	// this function show the range of moving car 
	
	if ( bcx > 320  && flag ) 
	{
		bcx -= 5;
		if(bcx < 325)
			flag = false;
	}
	else if (bcx < 400 && !flag) 
	{
		bcx += 5;
		if (bcx > 395 )
			flag = true;
	}
}
 int movecarspeed =5 ;
 int bcx2=440,bcy2=640;
 bool flag2 = true;

void drawBlueCar2(){		// This  function is displaying Blue car on the screen that moves automatically
	
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx2 +5) , (bcy2 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx2 + 37) , (bcy2 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx2 + 21) , (bcy2 + 25),10,colors[BLACK]);
	DrawRectangle( (bcx2 +5) , (bcy2 + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}
void moveBlueCar2() {		// this function show the range of moving car
	if ( bcy2 > 400  && flag2 ) 
	{
		bcy2 -= movecarspeed;
		if(bcy2 < 405)
			flag2 = false;
	}
	else if (bcy2 < 640 && !flag2) 
	{
		bcy2 += movecarspeed ;
		if (bcy2 > 635 )
			flag2 = true;
	}
}
 int bcx3=880 ,bcy3=120;
 bool flag3 = true;
void drawBluecar3(){		// This  function is displaying Blue car on the screen that moves automatically
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx3 +5) , (bcy3 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx3 + 37) , (bcy3 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx3 + 21) , (bcy3 + 25),10,colors[BLACK]);
	DrawRectangle( (bcx3 +5) , (bcy3 + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}

void moveBluecar3() {		// this function show the range of moving car
	
	if ( bcx3 > 840  && flag3 ) 
	{
		bcx3 -= movecarspeed ;
		if(bcx3 < 830)
			flag3 = false;
	}
	else if (bcx3 < 920 && !flag3) 
	{
		bcx3 += movecarspeed ;
		if (bcx3 > 910 )
			flag3 = true;
	}
}

 int bcx4=240 ,bcy4=40;
 bool flag4 = true;
void drawBluecar4(){		// This  function is displaying Blue car on the screen that moves automatically
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx4 +5) , (bcy4 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx4 + 37) , (bcy4 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx4 + 21) , (bcy4 + 25),10,colors[BLACK]);
	DrawRectangle( (bcx4 +5) , (bcy4 + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}

void moveBluecar4() {		// this function show the range of moving car
	
	if ( bcx4 > 120  && flag4 ) 
	{
		bcx4 -= movecarspeed ;
		if(bcx4 < 110)
			flag4 = false;
	}
	else if (bcx4 < 240 && !flag4) 
	{
		bcx4 += movecarspeed ;
		if (bcx4 > 230 )
			flag4 = true;
	}
}

 int bcx5=440 ,bcy5=720;
 bool flag5 = true;
void drawBluecar5(){		// This  function is displaying Blue car on the screen that moves automatically
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx5 +5) , (bcy5 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx5 + 37) , (bcy5 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx5 + 21) , (bcy5 + 25),10,colors[BLACK]);
	DrawRectangle( (bcx5 +5) , (bcy5 + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}

void moveBluecar5() {		// this function show the range of moving car
	
	if ( bcx5 > 320 && flag3 ) 
	{
		bcx5 -= movecarspeed ;
		if(bcx5 < 310)
			flag5 = false;
	}
	else if (bcx5 < 440 && !flag5) 
	{
		bcx5 += movecarspeed ;
		if (bcx5 > 430 )
			flag5 = true;
	}
}

 int bcx6=820 ,bcy6=520;
 bool flag6 = true;
void drawBluecar6(){		// This  function is displaying Blue car on the screen that moves automatically
	int a= ((xI-120)/40);
	int b= (yI/40);
	pixels[a][b] = 50;
	DrawCircle( (bcx6 +5) , (bcy6 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle( (bcx6 + 37) , (bcy6 + 2) , 6.5 ,colors[BLACK] );
	DrawCircle((bcx6 + 21) , (bcy6 + 25),10,colors[BLACK]);
	DrawRectangle( (bcx6 +5) , (bcy6 + 2) , 35 , 23 , colors[BLUE]); 
	glutPostRedisplay();
	}
 
void moveBluecar6() {		// this function show the range of moving car
	
	if ( bcx6 > 820  && flag6 ) 
	{
		bcx6 -= movecarspeed;
		if(bcx6 < 810)
			flag6 = false;
	}
	else if (bcx6 < 720 && !flag6) 
	{
		bcx6 += movecarspeed;
		if (bcx6 > 710 )
			flag6 = true;
	}
}

void box(int bx, int by){		// this is for creating box like obstacles
	int a= ((bx-120)/40);
	int b= (by/40);
	pixels[a][b]=30;		// this is saving it value in the array by it loction 
	DrawSquare( bx , by , 40 ,colors[CHOCOLATE]); 
	DrawRectangle( (bx + 5) , (by + 12), 30 , 15 , colors[DARK_GRAY]);
}

 int mx,my;

void man(int g){	// this function create passanger on board
	
	mx=120 + (40*(manrandx[g]-1));
	my= (40*(manrandy[g]-1)) + 6.5;
	pixels[manrandx[g]-1][manrandy[g]-1]=20;
	if(pixels[manrandx[g]-1][manrandy[g]-1] != 10  && pixels[manrandx[g]-1][manrandy[g]-1] != 30 ){ //check for other obstacles
	DrawTriangle( (mx + 7) ,(my - 7) , (mx+ 13), (my - 7) , (mx + 17) , (my + 13) , colors[BLACK] ); 
	DrawTriangle( (mx + 22), (my - 7) , (mx + 28), (my - 7) , (mx + 17) , (my + 13) , colors[BLACK] ); 
	DrawLine( (mx + 17) , (my + 5) ,  (mx + 17) , (my + 24), 5 , colors[BLACK] );	
	DrawLine( (mx + 5) , (my + 13) ,  (mx + 27) , (my + 13), 2 , colors[BLACK] );	
	DrawCircle((mx+17),(my + 25),7,colors[BLACK]);}
	
}


void tree(int n){ // this is for creating tree like obstacles
	int tx,ty;
	pixels[treerandx[n]-1][treerandy[n]-1] = 30;  // this is saving it value in the array by it loction
	tx=120 + (40*(treerandx[n]-1));
	ty=40* (treerandy[n]-1) +1;
	DrawLine( (tx + 20) , (ty - 2) , (tx + 20) , (ty + 10)  , 6 , colors[SADDLE_BROWN]);
	DrawRoundRect( (tx + 5) , (ty + 6) , 30 , 34 ,colors[GREEN],15);
}

void blockH(int blx,int blxEnd, int bly ){	//h show horizontal
	for(int a=blx, b=bly ; a < blxEnd; a++){		//a for straight line
	DrawSquare( (120 + (40*(a-1))) , (40 * (b-1)) , 41 ,colors[BLACK]);  
	pixels[a-1][b-1]= 10;		// this is saving it value in the array by it loction
	}
}

void blockV(int blx,int bly, int blyEnd ){	//h show vertical
	for(int a=blx, b=bly ; b < blyEnd; b++){		//a for straight line
	DrawSquare( (120 + (40*(a-1))) , (40 * (b-1)) , 41 ,colors[BLACK]);   // for blocks in 3rd row 
	pixels[a-1][b-1]= 10;		// this is saving it value in the array by it loction
	}
}

void xlines(int x){		// this function produces the line in x axis
	DrawLine( x , 0 ,  x , 800 , 1.5 , colors[BLACK]);
}

 int min1=0,sec1=0;
 int menuflag = 1;
 bool flags=true;

void displaytime(){		//this is function for displaying time on screen 
	while (flags) {
        
        sec1++;
        // if seconds reaches 60
        if (sec1 == 60) {
            min1++;
 
            if (min1 == 3) 
            {
            //menuflag=5;
            flags=false;
            }
            
            sec1 = 0;
		}
 	}
	DrawString( 10, 780, "Timer", colors[BLACK]);

	DrawString( 7, 730, Num2Str(min1) , colors[BLACK]);
	DrawString( 15, 730, " min|", colors[BLACK]);
	

	DrawString( 70, 730, Num2Str(sec1)  , colors[BLACK]);
	DrawString( 80, 730, " sec", colors[BLACK]);
	glutPostRedisplay();
	
}

void GameMenu(void){		//this is fnction for menu
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		DrawString( 350, 520, "RUSH HOUR GAME", colors[MISTY_ROSE]);
		DrawRoundRect(390,400,120,60,colors[WHITE],20);	
		DrawRoundRect(400,405,100,50,colors[DARK_GREEN],20);	
		DrawString( 410, 415, "START", colors[BLACK]);
		
		DrawRoundRect(370,290,170,60,colors[WHITE],20);	
		DrawRoundRect(380,295,150,50,colors[DARK_GREEN],20);	
		DrawString( 390, 305, "LeaderBoard", colors[BLACK]);
	

		glutSwapBuffers(); // do not modify this line..


}

 int passanger = 0;
 bool passflag;
 bool scoreflag = true;
 bool boxflag= false;
 int r,t;


/*
 * Main Canvas drawing function.
 * */
 
 
 int k=0,j=440;
 bool menu= true;
 bool pas_scoreflag = false;
 int speed_of_car;
 
void GameDisplay()/**/{	//this is main function that display everything on the game screen
	if(menuflag == 1){
		GameMenu();	//calling menu function
		
		}
	else if  (menuflag == 2){	// for selecting taxi_color
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		DrawString( 370, 520, "Select Taxi colour ", colors[MISTY_ROSE]);
		
		DrawRoundRect(240,400,120,60,colors[WHITE],20);	
		DrawRoundRect(250,405,100,50,colors[RED],20);	
		DrawString( 270, 415, "RED", colors[BLACK]);
		
		DrawRoundRect(540,400,170,60,colors[WHITE],20);	
		DrawRoundRect(550,405,150,50,colors[GOLD],20);
		DrawString( 572, 415, "YELLOW", colors[BLACK]);
		
		DrawRoundRect(360,330,180,60,colors[WHITE],20);	
		DrawRoundRect(365,335,170,50,colors[DARK_GREEN],20);	
		DrawString( 375, 345, "Random Color", colors[BLACK]);
	
	}
	else if(menuflag == 3){	// For leaderboard
		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
				0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		DrawString( 420, 520, "Leader Borad", colors[MISTY_ROSE]);
		DrawString( 370, 470, "Names", colors[MISTY_ROSE]);
		DrawString( 510, 470, "High Scores", colors[MISTY_ROSE]);
		
		
		DrawString( 370, 440, "Nouman" , colors[MISTY_ROSE]);
		DrawString( 510, 440, "87" , colors[MISTY_ROSE]);
		
		DrawString( 370, 410, "Ahamr", colors[MISTY_ROSE]);
		DrawString( 510, 410, "85", colors[MISTY_ROSE]);
		
		DrawString( 370, 380, "Talha", colors[MISTY_ROSE]);
		DrawString( 510, 380, "80", colors[MISTY_ROSE]);
		
		DrawString( 370, 350, "Umer", colors[MISTY_ROSE]);
		DrawString( 510, 350, "77", colors[MISTY_ROSE]);
		
		DrawRoundRect(420,110,120,60,colors[WHITE],20);	
		DrawRoundRect(430,115,100,50,colors[DARK_GREEN],20);	
		DrawString( 440, 125, "START", colors[BLACK]);
	
	
	
	}
	else if (menuflag == 4){   //for starting the game
		menu = false;
		
		glClearColor(1, 1, 1, 0 ); 
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		
		int a= ((xI-120)/40);
		int b= (yI/40);
		
		if(pixels[a][b]==30 && scoreflag && ( taxi_color == "RED"))	//check for score on tree and boxes for red car
		{
			score -= 2;
			scoreflag=false;
		}
		
		if(pixels[a][b]==30 && scoreflag && ( taxi_color == "YELLOW"))//check for score on tree and boxes for yellow car
		{
			score -= 4 ;
			scoreflag=false;
		}
		
		if(pixels[a][b]==20 && scoreflag)	//check for score on passsanger
		{
			score -= 5;
			scoreflag=false;
		}
		
		if(pixels[a][b]==50 && pas_scoreflag)
		{
			score += 1;
		}
		
		
		displaytime();
		if(1)	//obstacles
		{
			for(int k=0;k<6;k++)
			tree(k);	// for random generation of trees
			
			man(0); 
			man(1); //for random generation of passangers
			man(2); 
			man(3); 
			man(4); 
			
			//box on the board
			box(280,600);
			box(840,80);
			box(440,320);	//for random generation of boxes
			box(280,120);
			box(640,560);
		}
		
		//displaytime();
		 
		if(1){	// grid
		//drawing perpendicular lines
		for(int a=120;a<960;a=a+40)
			xlines(a);
		
		//drawing straight lines
		DrawLine( 120 , 0 , 920 , 0 , 1.5 , colors[BLACK]);
		DrawLine( 120 , 800 , 920 , 800 , 1.5 , colors[BLACK]);
		}
		
		//drawing buildings
		if(1)
		{	blockH(1,2,1);
			blockH(9,16,18);	// 9 start of x axis //16 end of x axis // 17 is constant y axis
			blockH(3,7,3);
			blockH(3,7,18);
			blockH(17,20,8);
			blockH(12,16,14);
			blockH(7,11,10);
			blockH(12,16,3);
			blockH(2,3,8);
			blockH(18,19,18);
			blockH(8,10,20);
			
			//GetRandInRange( 0 , 20 );
			blockV(3,3,9);	// 3 is constant x axis //7 is start of y axis // 17 is end of y axis
			blockV(3,14,19);
			blockV(9,0,6);
			blockV(10,0,6);
			blockV(17,4,8);
			blockV(11,9,16);
			blockV(18,9,14);
			blockV(2,10,11);
		}
		
		// displaying score
		DrawString( 2, 640, "Score=", colors[BLACK]); 
		DrawString( 70, 640, Num2Str(score) , colors[BLACK]); 
		
		drawBlueCar();
		drawBlueCar2();	//for random moving cars
		
		// this will increase the random cars on the board after pick and drop of every two passanger
		if(passanger >= 2)
		{
			drawBluecar3();
			movecarspeed +=2;
		}
		if(passanger >= 4)
		{
			drawBluecar4();
			movecarspeed +=2;
		}
		if(passanger >= 6)
		{
			drawBluecar5();
			movecarspeed +=2;
		}
		if(passanger >= 8)
		{
			drawBluecar6();
			movecarspeed +=2;
		}
		
		//this is for selection of car color
		if(taxi_color == "RED")
		{
		drawRedCar();
		speed_of_car = 20;
		}
		else if(taxi_color == "YELLOW")
		{
		drawYellowCar();
		speed_of_car = 40;
		}
		if(pixels[a][b]==20 && passflag )	// for creating the destination of passenger
		{			
			DrawSquare(xI, yI, 40, colors[WHITE]);
			DrawCircle((xI),(yI),10,colors[RED]);
			passflag = false;
		}
		if( pixels[a][b]==20 && boxflag)	
		DrawSquare((r-40), (t-40), 40, colors[BLACK]);
		
		if(boxflag)
		DrawSquare((r-40), (t-40), 40, colors[GREEN]);
		
		
	}
	else if (passanger == 10){	// this is for showing if you win the game or not
		
		glClearColor(0, 0,0, 0); 
		glClear (GL_COLOR_BUFFER_BIT); //Update the colors
		
		DrawString( 520, 655, "YOU WIN !", colors[BLACK]);
		DrawString( 440, 605, " Your Socre is ", colors[BLACK]);
		DrawString( 600, 605, Num2Str(score), colors[BLACK]);
	
	
	}
	glutSwapBuffers(); // do not modify this line..

}

void NonPrintableKeys(int key, int x, int y) {
	
	if (key == GLUT_KEY_LEFT ) 
	{
		bool flag= false; 
		int a= ((xI-120)/40);		// converting coordinates into the points for collosion checking
		int b= (yI/40);
		
		if(pixels[a-1][b]!=10)
		flag=true;
		
		if( xI >120 && flag )
		{cout<<xI<<endl;
		xI -= speed_of_car;
		}
		scoreflag=true;

	}
	else if (key == GLUT_KEY_RIGHT ) 
	{
		bool flag= false; 
		int a= ((xI-120)/40);	// converting coordinates into the points for collosion checking
		int b= (yI/40);
		
		if(pixels[a+1][b]!=10)
		flag=true;
		
		if(xI<880 && flag)
		{cout<<xI<<endl;
		xI += speed_of_car;
		}
		scoreflag=true;
	}
	else if (key == GLUT_KEY_UP) 
	{	
		bool flag= false; 
		int a= ((xI-120)/40);
		int b= (yI/40); 	// converting coordinates into the points for collosion checking
		
		if(pixels[a][b+1]!=10)
		flag=true;
		
		if(yI<760 && flag)
		{cout<<yI<<endl;
		yI += speed_of_car;
		}
		scoreflag=true;
	}

	else if (key == GLUT_KEY_DOWN) 
	{
		bool flag= false; 
		int a= ((xI-120)/40);
		int b= (yI/40);		// converting coordinates into the points for collosion checking
		
		if(pixels[a][b-1]!=10)
		flag=true;
		
		if(yI>30 && flag)
		{cout<<yI<<endl;
		yI -= speed_of_car;
		}
		scoreflag=true;
	}
	glutPostRedisplay();

}

void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}
	
	int a= ((x-120)/40);
	int b= (y/40);
	
	if(key == 32 && pixels[a][b]==20){	// if space is pressed then pick the passanger up 
		r=x;
		t=y;
		boxflag=true;	
		passflag=true;	
	cout<< "p pressed "<<endl; 
	}
	
}

void Timer(int m) {

	moveBlueCar();
	moveBlueCar2();
	// for incresing the number of cars
	if(passanger >= 2)
		{
		moveBluecar3();
		}
	if(passanger >= 4)
		{
		moveBluecar4();
		}
	if(passanger >= 6)
		{
		moveBluecar5();
		}
	if(passanger >= 8)
		{
		moveBluecar6();
		}
	glutTimerFunc(100, Timer, 0);
}
 
void MousePressedAndMoved(int x, int y) {
	
	cout << x << " " << y << endl;
	glutPostRedisplay();
	
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}
 
 bool flagmenu=true;
 
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
		{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;
		if(menuflag != 2 && menuflag != 3 && menu )	//checks for menu
			if(x> 390  && x<510 && y >300 && y <350)
				menuflag=2;
				
		if(menuflag != 2 && menu )
			if(x> 370  && x<540 && y >380 && y <430)
				menuflag=3;
				
		if(menuflag != 2 && menu )
			if(x> 420  && x<540 && y >520 && y <570)
				menuflag=2;
		
		if(x> 240  && x< 360 && y >300 && y <340 && menu)
		{
			menuflag=4;
			taxi_color="RED";
		}
		
		if(x> 540  && x< 710 && y >295 && y <340 && menu)
		{
			menuflag=4;
			taxi_color="YELLOW";
		}
		if(x> 360  && x< 540 && y >350 && y <390 && menu)
		{
			menuflag=4;
			int m;
			m = rand() % 2;
			if(m == 0)
				taxi_color="YELLOW";
			else if(m == 1)
				taxi_color="RED";
		}
		} 
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}

/*
 * our gateway main function
 * */
 
int main(int argc, char*argv[]) {
	
	srand((unsigned int)time(NULL));
	int width = 1020, height = 840; // i have set my window size to be 800 x 600
	
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour By Nouman Amjad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	
	for(int k=0;k<6;k++)   //generating random numbers and storing them in arrays
	{
		bool treeflag = true ;
		treerandx[k]=GetRandInRange( 1 , 20 );
		treerandy[k]=GetRandInRange( 1 , 20 );
		
		pixels[manrandx[k]-1][manrandy[k]-1] = 30;
		while(treeflag)
		{
			if(pixels[treerandx[k]-1][treerandy[k]-1] == 10 || pixels[manrandx[k]-1][manrandy[k]-1] == 40)
				{
				treerandx[k]=GetRandInRange( 1 , 20 );
				treerandy[k]=GetRandInRange( 1 , 20 );
				treeflag = true;
				}
			else
				treeflag = false;
		}
	}
	for(int k=0;k<6;k++)	//generating random numbers and storing them in arrays
	{
		bool manflag = true ;
		manrandx[k]=GetRandInRange( 1 , 20 );
		manrandy[k]=GetRandInRange( 1 , 20 );
		pixels[manrandx[k]-1][manrandy[k]-1] = 20;
		while(manflag)
		{
			if(pixels[manrandx[k]-1][manrandy[k]-1] == 10 || pixels[manrandx[k]-1][manrandy[k]-1] == 40 || 							pixels[manrandx[k]-1][manrandy[k]-1] == 30 )
				{
				manrandx[k]=GetRandInRange( 1 , 20 );
				manrandy[k]=GetRandInRange( 1 , 20 );
				manflag = true;
				}
			else
				manflag = false;
		}
	}
	
	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(100.0, Timer, 0);
	
	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */

