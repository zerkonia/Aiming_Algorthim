#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> 
#define g 9.807            
#define PI 3.142857143                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
float convertToRadians(float phy){
	return ((phy * PI) / 180);
}
float convertToDegrees(float phy){
	return ((phy * 180) / PI);
}
int main(int argc, char *argv[]) {
	
    long double Xf = 125.000000000;
	long double velocity = 70.000000000;
	long double phy_scope = 1.078391842;
    long double aim_angle = 0.000000000;
	long double nominator = 0.000000000;
	long double dominator = 0.000000000;
	long double Yf = 0.000000000;
	long double X_square = 0.000000000;
	long double Y_square = 0.000000000;
	long double velocity_square = 0.000000000;
	
	printf("Enter range:");
	scanf("%llf",&Xf);
	printf("\n");
	printf("Enter velocity:");
	scanf("%llf",&velocity);
	printf("\n");
	printf("Enter scope angle in radians:");
	scanf("%llf",&phy_scope);
	printf("\n");
	
	//phy_scope = convertToRadians(phy_scope);
	printf("%llf",phy_scope);
	printf("\n");
	Yf = Xf * tan(phy_scope);
	printf("%llf",Yf);
	X_square = Xf * Xf;
	Y_square = Yf * Yf;
	velocity_square = velocity * velocity;
	nominator = (g*(X_square) / (velocity_square)) + Yf;
	dominator = sqrt((X_square) + (Y_square));
	aim_angle = (asin(nominator / dominator));
	aim_angle = aim_angle + phy_scope;
	aim_angle = aim_angle/2;
	printf("aim angle = %.15llf",convertToDegrees(aim_angle));
	return 0;
}                                                                                                     
