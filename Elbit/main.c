#define _CRT_SECURE_NO_WARNINGS

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
double min_val(double a, double b);


int main()
{


	double val1, val2, val3, delta = 0.001, revenue_2nd_price = 0.0, revenue_2nd_price_2_players = 0.0;
	double reserve[] = { 0,0.1,0.2,0.3,0.4,0.6,0.7,0.8,0.9 };
	double reserve_price = 0.5;

	for (val1 = 0.0; val1 <= 1.0; val1 += delta) {
		for (val2 = 0.0; val2 <= 1.0; val2 += delta) {
			if (val1 >= val2)revenue_2nd_price_2_players += val2;
			else revenue_2nd_price_2_players += val1;
			for (val3 = 0.0; val3 <= 1.0; val3 += delta) {
				
				if ((val1 >= val2) && (val1 >= val3)) 			revenue_2nd_price += min_val(val2, val3);
				else if((val2 >= val1) && (val2 >= val3))		revenue_2nd_price += min_val(val1, val3); 
				else if ((val3 >= val1) && (val3 >= val2))		revenue_2nd_price += min_val(val1,val2);
			}
		}
	}
	printf("%lf  3 players \n  ", (revenue_2nd_price * delta * delta * delta));
	printf("%lf  2 players ", (revenue_2nd_price * delta * delta));
}



	double min_val(double a, double b) {
		if (a > b) return a;
		return b;

}
	
 