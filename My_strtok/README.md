En este ejemplo vemos una implementación propia copia de la función strtok de C con el agregado extra de que no "destruye" el string original usando un argumento extra para especificar la longitud de las cadenas encontradas.

Aclaración: sé que justamente esto no es tokenizar, pero bueh, no me voy a poner a debatir que es.


Se ve en el main el ejemplo de uso de my\_strtokplus, que sigue una forma común en el uso de strtok.

[Change #1] A diferencia de strtok, y se nota en comparación, no salta todos los tokens aledaneos de un tirón sinó que trata de leer y devuelve cadenas vacías.
Es un problema que se debería arreglar en el futuro.

Changes.
Change #1: ya se ha logrado la forma de tratar tokens aledaneos en un string, se logra un resultado muy idéntico a strtok.

