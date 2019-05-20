#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double getDelta(double a, double b, double c){
	return b*b - 4.0 * a * c;
}

void solve(double a, double b, double c){
	double delta = getDelta(a, b, c);

	if(delta == 0){
		printf("%f\n", -b/(2*a));
	}
	else if(delta > 0){
		printf("%f\n", (-b + sqrt(delta)) / (2*a));
		printf("%f\n", (-b - sqrt(delta)) / (2*a));
	}
	else {
		delta = -delta;

		double real = -b/(2*a);
		double im = sqrt(delta)/(2*a);

		printf("%f + j%f\n", real, im);
		printf("%f - j%f\n", real, im);
	}
}

void help(){
	printf(" === Second degree equation solver === \n");
	printf("Finds the roots of a second degree equation.\n");
	printf("The equation has the forme a*x^2 + b*x + c\n");
	printf("\n");
	printf("Usage:\n");
	printf("secSolver [options]\n");
	printf("secSolver a b c\n");
	printf("secSolver a b\n");
	printf("secSolver a\n");
	printf("\n");
	printf("Options:\n");
	printf("\t--help, -h: display help\n");
}

int main(int argc, char *argv[]) {
	if(argc == 1){
		help();
		return EXIT_FAILURE;
	}
	else if(strcmp(*(argv+1), "--help") == 0 || strcmp(*(argv+1), "-h") == 0){
		help();
		return EXIT_SUCCESS;
	}
	else {
		double a = 0;
		double b = 0;
		double c = 0;

		if(argc > 4){
			printf("Too many arguments found\n");
			printf("\n");
			help();
			return EXIT_FAILURE;
		}

		if(argc >= 2){
			char* pEnd;
  			a = strtod (*(argv+1), &pEnd);
			if(strcmp(*(argv+1), pEnd) == 0){
				printf("Value %s is not a valid float\n", pEnd);
				return EXIT_FAILURE;
			}

			if(argc >= 3){
				b = strtod (*(argv+2), &pEnd);
				if(strcmp(*(argv+2), pEnd) == 0){
					printf("Value %s is not a valid float\n", pEnd);
					return EXIT_FAILURE;
				}

				if(argc == 4){
					c = strtod (*(argv+3), &pEnd);
					if(strcmp(*(argv+3), pEnd) == 0){
						printf("Value %s is not a valid float\n", pEnd);
						return EXIT_FAILURE;
					}
				}
			}
		}

		solve(a, b, c);
	}

	return EXIT_SUCCESS;
}
