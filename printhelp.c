/*PrintHelp, ayuda en la impresión a doble cara y de múltiples paginas por cara
    Copyright (C) 2014 Ismael Rodríguez Hernández

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.*/


/**Uso: printhelp [numeroPaginas] [paginasPorCara (1 por omision)]*/
#include <stdio.h>
void main(int argc, char **argv){

	int pagsTotales, pagsPorCara, caras, aux, numeroCara, pag, inicioCara;
	if(argc<2){

		fprintf(stderr,"Uso: %s [Nºpáginas totales] [Páginas por cara (Por defecto,1)]\n",argv[0]);
		exit(1);
	}


	pagsTotales = atoi(argv[1]); //Páginas totales a imprimir
	if(argc>=3) pagsPorCara = atoi(argv[2]); //Páginas por cara
	else pagsPorCara = 1; //Por defecto, pagsPorCara = 1;
	

	if(pagsTotales < pagsPorCara){
		fprintf(stderr,"Error: Total de páginas debe ser mayor o igual que páginas por cara\n");
		exit(1);
	}
	
	//caras = nº de caras necesarias para imprimir
	caras = pagsTotales/pagsPorCara;
	if(pagsTotales%pagsPorCara>0) caras++;
	
	//Número de caras pares (numeroPares): (caras+1)/2
	int numeroPares = (caras+1)/2;
	//Número de caras impares (numeroImpares): caras/2
	int numeroImpares = caras/2;


	printf("Folios: %d - Caras impares: %d - Caras pares: %d\n",(numeroPares+numeroImpares+1)/2,numeroPares,numeroImpares);
	printf("CARAS IMPARES: ");
	
	/**
	CARAS PARES (impares reales)

	Número de cara (numeroCara): 2n, n en Naturales: 0,2,4,6,8... Corresponden a las caras 1,3,5,7,9... reales
	Comienzo de cara (inicioCara): numeroCara*pagsPorCara + 1. En qué página empieza la cara 'numeroCara'
	Final de cara: inicioCara + pagsPorCara;
	*/

	for(aux = 0; aux < numeroPares;aux++){
		//Escribo cada una de las paginas de las caras pares
		numeroCara = 2*aux;
		inicioCara = (numeroCara)*pagsPorCara+1;

		for(pag = inicioCara; (pag<inicioCara + pagsPorCara && pag<=pagsTotales);pag++){
			/*Solo coma si no es el primero*/
			if(pag != 1) 
				printf(",%d",pag);
			else
				printf("%d",pag);
		}

	}

	printf("\nCARAS PARES: ");
	/**
	CARAS IMPARES (Pares reales)

	Número de cara (numeroCara): 2n+1, n en Naturales: 1,3,5,7,9... Corresponden a las caras 2,4,6,8... reales
	Comienzo de cara (inicioCara): numeroCara*pagsPorCara + 1. En qué página empieza la cara 'numeroCara'
	Final de cara: inicioCara + pagsPorCara;
	*/
	
	for(aux=0;aux<numeroImpares;aux++){
		numeroCara = 2*aux + 1;
		inicioCara = (numeroCara)*pagsPorCara+1;
		for(pag = inicioCara; (pag<inicioCara + pagsPorCara && pag<=pagsTotales);pag++){
			
			/*Solo coma si no es el primero*/
			if(pag != pagsPorCara+1) 
				printf(",%d",pag);
			else
				printf("%d",pag);
		}
	}


	printf("\n");



}