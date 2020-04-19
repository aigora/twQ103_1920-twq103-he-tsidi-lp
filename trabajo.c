#include <stdio.h>
#include <string.h>
#include <windows.h>

//vale :,(

struct datosEvau {
	char nombre[50];
	char apellidos[50];
	float nota[7];
	int nMat;
	char correo[100];
};

int main(){

	struct datosEvau alumno[200];
	int opcion, opCarrera, matricula,valido=0, i, j=0, c1=0, c2=0;
	float mediaEvau, s=0.0, n=0.0;
	FILE*pfichero;
	char buscar[50];
	char encontrado[50];
	int r;

	printf("Bienvenido al Programa de Preinscripcion de la Politecnica\n");



	printf("Introduzca opcion:\n");
	printf("1 - Registrarse como nuevo usuario\n");
	printf("2 - Iniciar sesion\n");
	printf("3 - Ayuda\n");
	scanf("%d", &opcion);

	system("cls");// Limpiar pantalla

while(valido==0){ //Comprueba que introduces la opcion correcta
	
	switch (opcion){


		case 1:
		    valido=1;

		printf("Primero calcularemos su nota de corte\n \nLuego le diremos si es apto para cursar nuestras titulaciones\n \nPor ultimo le daremos paso a la pagina principal de registro e inicio de sesion de la facultad ");

		printf("\nA continuacion se le pediran las notas de Evau para calcular la nota de corte\n");


		//Numero de asignaturas
		
		printf("\nAntes de nada, de cuantas asignaturas se ha examinado en Evau? ");
		scanf("%f", &n);
		while(n<4 || n>7){
			printf("Por favor introduzca los datos correctamente: ");
			scanf("%f", &n);
		}


		printf("\nIntroduzca las notas en el orden que quiera:\n ");



		for(i=0; i<n; i++){ 		//Notas Introducidas

		printf("\nNota:");
		scanf("%f", &alumno[j].nota[i]);

			while(alumno[j].nota[i]<0 || alumno[j].nota[i]>10){
			printf("Datos erroneos, vuelva a introducir la nota");
			scanf("%f", &alumno[j].nota[i]);
			}
		}

		for(i=0; i<n; i++){   //Media Notas
		s += alumno[j].nota[i];
		}


	mediaEvau = s/n;
	system("cls");


	printf("\nTu media de Evau es: %.2f \n", mediaEvau);

   		if(mediaEvau > 6.23){								//Comprobacion de acceso por media de Evau
   			printf("\nEnhorabuena, tiene posibilidad de cursar algun grado en nuestra facultad!");
   		}else{
   			printf("\nLo sentimos, su nota es inferior a la nota de corte en todas nuestras titulaciones");
   			return 0;
   			}
   			printf("\nSeleccione la carrera en la que quiera matricularse:\n \n1 - Ingenieria Quimica\n \n2 - Ingenieria Mecanica\n \n3 - Ingenieria Electrica\n \n4 - Ingenieria Electronica\n \n5 - Diseño Insustrial\n \n6 - Doble grado de Ingenieria del Diseño Industrial e Ingenieria Mecanica\n \n7 - Doble grado de Ingenieria Electrica e Ingeniieria Electronica\n");
   			scanf("%d", &opCarrera);
			
			system("cls");// Limpiar pantalla

   			switch (opCarrera){

   				case 1: //Quimica

   					pfichero = fopen("IngenieriaQuimica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

   					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}
					
   					fclose(pfichero);

   					pfichero = fopen("IngenieriaQuimica.txt", "a");

					if(mediaEvau < 6.51){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

   					printf("Ha seleccionado Ingenieria Quimica\n");

					printf("\nIntroduzca sus datos:\n\n");

					printf("Introduce nombre:");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("Introduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);



					fprintf(pfichero, "%04d\t", alumno[j].nMat); //Numero Matricula en el fichero
					fprintf(pfichero, "%s.%s@alumnos.upm.es \n", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero

					printf("Su numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);




					fclose(pfichero);

				break;

				case 2: //Mecanica

					pfichero = fopen("IngenieriaMecanica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					if(mediaEvau < 7.89){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaMecanica.txt", "a");

					printf("Ha seleccionado Ingenieria Mecanica\n");

					printf("\nIntroduzca sus datos:\n");

					printf("\nIntroduce nombre:");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("\nIntroduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);


					fprintf(pfichero, "%04d\t", alumno[j].nMat);
					fprintf(pfichero, "%s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero
					
					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;

				case 3: //Electrica

					pfichero = fopen("IngenieriaElectrica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					if(mediaEvau < 6.23){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaElectrica.txt", "a");

					printf("Ha seleccionado Ingenieria Electrica\n");

					printf("\nIntroduzca sus datos:\n");

					printf("\nIntroduce nombre:\n");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("\nIntroduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);

					
					fprintf(pfichero, "%04d\t", alumno[j].nMat);
					fprintf(pfichero, "%s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero
					
					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;

				case 4: //Electronica

					pfichero = fopen("IngenieriaElectronica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					if(mediaEvau < 7.49){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaElectronica.txt", "a");

					printf("Ha seleccionado Ingenieria Electronica\n");

					printf("\nIntroduzca sus datos:\n");

					printf("\nIntroduce nombre:\n");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("\nIntroduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);


					
					fprintf(pfichero, "%04d\t", alumno[j].nMat);
					fprintf(pfichero, "%s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero
					
					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;

				case 5: //Diseño

					pfichero = fopen("IngenieriaDiseño.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					if(mediaEvau < 8.59){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaDiseño.txt", "a");

					printf("Ha seleccionado Ingenieria de Diseno industrial\n");

					printf("\nIntroduzca sus datos:\n");

					printf("\nIntroduce nombre:\n");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("\nIntroduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);

					
					fprintf(pfichero, "%04d\t", alumno[j].nMat);
					fprintf(pfichero, "%s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero
					
					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;

				case 6: //Doble diseño y mecanica

					pfichero = fopen("IngenieriaDobleDiseñoMecanica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					if(mediaEvau < 9.22){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaDobleDiseñoMecanica.txt", "a");

					printf("Ha seleccionado Doble Grado de Ingenieria Mecanica y Diseño Industrial\n");

					printf("\nIntroduzca sus datos:\n");

					printf("\nIntroduce nombre: ");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("\nIntroduce apellidos:\n");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);


					fprintf(pfichero, "%04d\t", alumno[j].nMat);

					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;

				case 7: //Doble Electrica y Electronica

   					pfichero = fopen("IngenieriaDobleElectricaElectronica.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

   					if(mediaEvau < 7.21){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					while(fscanf(pfichero, "%s %s %d %s", alumno[j].nombre, alumno[j].apellidos, &alumno[j].nMat, alumno[j].correo) != EOF){

						alumno[j].nMat++;

   					}

					fclose(pfichero);

					pfichero = fopen("IngenieriaDobleElectricaElectronica.txt", "a");

					printf("Ha seleccionado Doble Grado de Ingenieria Electrica y Electronica\n");

					printf("\nIntroduzca sus datos:\n\n");

					printf("Introduce nombre:\n");
					scanf("%s", alumno[j].nombre);
					fprintf(pfichero, "%s ", alumno[j].nombre);

					printf("Introduce apellidos:");
					scanf("%s", alumno[j].apellidos);
					fprintf(pfichero, "%s ", alumno[j].apellidos);


					fprintf(pfichero, "%04d\t", alumno[j].nMat);
					fprintf(pfichero, "%s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos); // Correo en el fichero
					
					printf("\nSu numero de matricula es: %04d\n", alumno[j].nMat);
					printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellidos);

					fclose(pfichero);
				break;
			   }

		break;

		case 2:
		    valido=1;

			pfichero = fopen("IngenieriaQuimica.txt", "r");

			printf("Iniciar sesion\n");
			printf("Introduzca su correo de la upm");
			scanf("%s", buscar);
			while(fscanf(pfichero, "%s", encontrado)!=EOF){
				if (strcmp(encontrado, buscar)==0){
					r=1;
						}
			}

		    if(r==1){
		    	printf("Usuario encontrado");
			}
			//printf("Introduce tu nombre y apellidos:\n"); // Aqui accede a ficheros de gente previamente registradas
			//scanf("%s %s", alumno[j].nombre, alumno[j].apellidos);

		    //fscanf(pfichero, "%s %s", alumno[j].nombre, alumno[j].apellidos);






		    fclose(pfichero);
			break;

		case 3:
		    valido=1;

			printf("\nContacte con la secretaria de la ETSIDI:\n910677450 / 910677451 \nO a traves de nuestro e-mail: \nsecretaria.etsidi@upm.es ");

			break;

		default:

			printf("Opcion incorrecta \nVuelva a escribir la opcion deseada\n");
			printf("Introduzca opcion:\n");
			printf("1 - Registrarse como nuevo usuario\n");
			printf("2 - Iniciar sesion\n");
			printf("3 - Ayuda\n");
			scanf("%d", &opcion);
			
			system("cls");// Limpiar pantalla
			
			break;
	}

	}


	}







