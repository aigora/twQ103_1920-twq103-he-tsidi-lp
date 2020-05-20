#include <stdio.h>
#include <string.h>
#include <windows.h>



//regresar al menu despues de cada una


struct datosEvau {

	char titulo[4];
	char nombre[50];
	char apellido[50];
	float nota[7];
	int nMat;
	char correo[100];
	char contr[100];

};

int cFichero(struct datosEvau alumno[]){

	int j = 0;
	FILE*pfichero;

	pfichero = fopen("Usuarios.txt", "r");

	while(feof(pfichero) == 0){
		fscanf(pfichero,"%s %s %s %d %s %s", alumno[j].titulo, alumno[j].nombre, alumno[j].apellido, &alumno[j].nMat, alumno[j].correo, alumno[j].contr);
		j++;
	}

	fclose(pfichero);

	return j;
}

void banner(){

  system("COLOR ");

printf("  ....  ...  ....  ..    . .       .  ....  ..    .  ...  ...      ..         ...        .       ...  \n");
printf("  .  .   .   .     . .   .  .     .   .     . .   .   .   .  .    .  .       .   .       .      .   . \n");
printf("  ..     .   ...   .  .  .   .   .    ..    .  .  .   .   .   .  .    .      .....       .      ..... \n");
printf("  .  .   .   .     .   . .    . .     .     .   . .   .   .  .    .  .       .   .       .      .   . \n");
printf("  ....  ...  ....  .    ..     .      ....  .    ..  ...  ...      ..        .   .       .....  .   . \n");


printf("            ///////   ///////   ///////    ///////   ///////      //////// 					      ");
printf("              //           /      //            /      //    //        / 						      ");
printf("              ////         /        //          /      //      //      / 						      ");
printf("              //           /          ///       /      //    //        / 						      ");
printf("              ///////      /     //////     ///////    //////       ///////                           \n");
printf("                              ___________________________                                             \n");
printf("                             |                           |                                            \n");
printf("                             |                           |                                            \n");
printf("                             |                           | 										      \n");
printf("                             |   ****    ****    ****    | 										      \n");
printf("                             |   *   *   *   *   *   *   |                                            \n");
printf("                             |   ****    ****    ****    |                                            \n");
printf("                             |   *       *       *       |                                            \n");
printf("                             |   *       *       *       |                                            \n");
printf("                             |                           |                                            \n");
printf("                             |                           |                                            \n");
printf("                             |                           |                                            \n");
printf("                        _____|___________________________|________                                    \n");
printf("                      |Programa de Preinscripcion a la Politecnica|                                   \n\n\n");

	getch(0);

	system("cls");
}

int registro(struct datosEvau alumno[], int j){

	printf("\nIntroduzca sus datos:\n");
	printf("\nIntroduce nombre:");
	scanf("%s", alumno[j].nombre);

	printf("\nIntroduce tu primer apellido:");
	scanf("%s", alumno[j].apellido);

	printf("\nSu numero de matricula es: %04d\n", j);
	printf("\nSu correo electronico de la Politecnica es: %s.%s@alumnos.upm.es", alumno[j].nombre, alumno[j].apellido);
	printf("\nAhora introduzca una clave de acceso: ");
	scanf("%s", alumno[j].contr);

	return j;
}

int iSesion(struct datosEvau alumno[], int j){
			
			int encontrado = 0, i;
			char intr[100], cintr[100];
			
			fflush(stdin);
			
			while(encontrado==0){
				
				fflush(stdin);
				printf("Introduzca su correo de la UPM: ");
				gets(intr);
			
				printf("Introduzca su contraseña: ");			
				gets(cintr);
				
				for(i=0; i<j; i++){
					
					if((strcmp(intr, alumno[i].correo)==0)&&(strcmp(cintr, alumno[i].contr)==0)){
							encontrado = 1;
							break;
					}	
				}	
				system("cls");			
			}
			printf("Bienvenido %s %s, grado %s\n\n", alumno[i].nombre, alumno[i].apellido, alumno[i].titulo);
	return encontrado;
}

void menu(){

	printf("Bienvenido al Programa de Preinscripcion de la Politecnica\n");

	printf("Introduzca opcion:\n");
	printf("1 - Registrarse como nuevo usuario\n");
	printf("2 - Iniciar sesion\n");
	printf("3 - Ayuda\n");
	printf("4 - Salir del programa\n");
}

void calendario(){

	int cal[5][7];
	int p=1, l, i;

	for(i=0; i<5; i++){
		for(l=0; l<7; l++){
			cal[i][l] = p++;
			if(cal[i][l] >= 31){
			p=1;
			}
		}
	}
	printf("Mes de Junio\n\n");
	for (i=0; i<5; i++){
		for(l=0; l<7; l++){
  			if(cal[i][l] > 9){
			  	printf("%d ", cal[i][l]);
			} else{
				printf("0%d ", cal[i][l]);
			}
	  }
	  printf("\n");
  }
}
void eventosCalendario(int dia){

	int i;
	for(i=1;i<=31;i++){
		if(((dia+1)%7)==0||(dia%7)==0){
			printf("No es dia lectivo");
			break;
		}else if((dia%5)==0||(dia%4)==0){
			printf("Examen final, asignatura por decidir.");
		break;
		}else {
			printf("No tiene nada programado para este dia.");
			break;
		}		
	} 
}

int main(){

    char tq[3] = {"IQ"}, tm[3] = {"IM"}, tec[3] = {"IEC"}, ten[3] = {"IEN"}, td[3] = {"ID"}, tdm[3] = {"IDM"}, tee[3] = {"IEE"};
	struct datosEvau alumno[200];
	int opcion, opCarrera, matricula,valido=0, i, j=0, c1=0, c2=0, p;
	float mediaEvau, s=0.0, n=0.0;
	FILE*pfichero;
	char introducido[50];
	int encontrado=0;
	int r;

	j = cFichero(alumno);
	banner();	
	system("cls");

while(valido == 0){ 	
	
	system("cls");
	cFichero(alumno);
	
	do{

		menu();
		fflush(stdin);
		scanf("%d", &opcion);

		system("cls");

		break;

	}while(opcion != 4);

		if(opcion == 4){
			valido=1;
			printf("Seguro que quiere salir?\n\n");
			menu();
			fflush(stdin);
			scanf("%d", &opcion);

		if(opcion == 4){
			valido=1;
			printf("Hasta la proxima!");
			return 0;

		}
	}

	system("cls");// Limpiar pantalla
		
if(opcion == 1){
		   
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
			printf("Datos erroneos, vuelva a introducir la nota: ");
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
   			printf("\nOpcion:");
			scanf("%d", &opCarrera);

			system("cls");// Limpiar pantalla

   			switch (opCarrera){

   					pfichero = fopen("Usuarios.txt", "r");

   					if(pfichero == NULL){
						printf("No se encuentra el fichero");
						return 0;
					}

					fclose(pfichero);

   				case 1: //Quimica

					if(mediaEvau < 6.51){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

   					printf("Ha seleccionado Ingenieria Quimica\n");

					strcpy(alumno[j].titulo, tq);

					fflush(stdin);

					j = registro(alumno, j);

				break;

				case 2: //Mecanica

					if(mediaEvau < 7.89){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					printf("Ha seleccionado Ingenieria Mecanica\n");

					strcpy(alumno[j].titulo, tm);
					
					fflush(stdin);

					j = registro(alumno, j);

				break;

				case 3: //Electrica

					if(mediaEvau < 6.23){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					printf("Ha seleccionado Ingenieria de Electrica\n");

					strcpy(alumno[j].titulo, tec);
					
					fflush(stdin);

					j = registro(alumno, j);

				break;

				case 4: //Electronica

					if(mediaEvau < 7.49){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					printf("Ha seleccionado Ingenieria de Electronica\n");
					
					strcpy(alumno[j].titulo, ten);			
					
					fflush(stdin);

					j = registro(alumno, j);
		
				break;

				case 5: //Diseño
					if(mediaEvau < 8.59){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}
					printf("Ha seleccionado Ingenieria de Diseno Industrial\n");

					strcpy(alumno[j].titulo, td);
					
					fflush(stdin);

					j = registro(alumno, j);

				break;

				case 6: //Doble diseño y mecanica
					if(mediaEvau < 9.22){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					printf("Ha seleccionado Doble Grado de Ingenieria Mecanica y Diseño Industrial\n");

					strcpy(alumno[j].titulo, tdm);
					
					fflush(stdin);

					j = registro(alumno, j);
					
				break;

				case 7: //Doble Electrica y Electronica
   					if(mediaEvau < 7.21){
						printf("\nLo sentimos, su nota es menor de la requerida para esta carrera");
						break;
					}

					printf("Ha seleccionado Doble Grado de Ingenieria Electrica y Electronica\n");
					
					strcpy(alumno[j].titulo, tee);
					
					fflush(stdin);

					j = registro(alumno, j);
				
				break;

			   default:

			   	printf("Introduzca una de las opciones pedidas por favor");
			   	return 0;
			   }

			   	pfichero = fopen("Usuarios.txt", "a");

			    fprintf(pfichero, "%s ", alumno[j].titulo);
				fprintf(pfichero, "%s ", alumno[j].nombre);
				fprintf(pfichero, "%s ", alumno[j].apellido);
				fprintf(pfichero, "%04d ", j); //Numero Matricula en el fichero
				fprintf(pfichero, "%s.%s@alumnos.upm.es ", alumno[j].nombre, alumno[j].apellido); // Correo en el fichero
				fprintf(pfichero, "%s\n", alumno[j].contr);

				fclose(pfichero);
				
				valido = 0;
	}


		if(opcion == 2){

		    valido = 1;
			
			iSesion(alumno, j);
			
			fflush(stdin);
			
			calendario();	
			
			int dia=1;
			printf("Introduzca el dia que quiere consultar:\n");
			scanf("%d",&dia);
			
			while(dia<1 || dia>31){
				printf("El dia seleccionado no es valido, vuelva a introducirlo\n");
				scanf("%d",&dia);
			}
			
						
			eventosCalendario(dia);
			fflush(stdin);
			
			getch(0);
			system("cls");
			printf("\nHasta luego.");
			
			getch(0);
			
		}
		
		if(opcion == 3){
		    valido=1;
			printf("\nContacte con la secretaria de la ETSIDI:\n910677450 / 910677451 \nO a traves de nuestro e-mail: \nsecretaria.etsidi@upm.es ");
		}
}
}
