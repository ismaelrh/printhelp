printhelp - ismaro3 2014
=========
Utilidad que ayuda en la impresión a doble cara de varias páginas por cara. Permite un ahorro de tiempo considerable.
Especificando el número total de páginas a imprimir y el número de páginas por cara deseado,
indica que números de página tenemos que escribir en el diálogo de impresión para poder imprimir
a doble cara sin dolores de cabeza.
Informacíon: Folios totales, números de páginas a introducir para caras impares (1,3,5,7...) y para páginas pares (2,4,6,8...)

Ejemplo de funcionamiento:
Tenemos un documento de 20 páginas, y queremos imprimir a doble cara, 4 páginas por cara:

>$ printhelp 20 4
Folios: 3 - Caras impares: 3 - Caras pares: 2
CARAS IMPARES: 1,2,3,4,9,10,11,12,17,18,19,20
CARAS PARES: 5,6,7,8,13,14,15,16

En el diálogo de impresión de nuestra impresora, pegaremos la secuencia de Caras impares e imprimiremos.
Seguidamente, colocaremos los folios por la otra cara en la impresora e imprimiremos usando la secuencia de Caras
pares. Como resultado, tendremos el documento correctamente impreso por las dos caras.

