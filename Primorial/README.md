En este ejemplo vemos como se puede calcular el primorial de un número.

El primorial de un número, denotado 'n#' es el producto de todos los primos menores o iguales a ese número:

$$n \\# = \prod_{i=1}^{\pi (n)} p_i$$

Por ejemplo: '5#' = 5 * 3 * 2 = 30
             '6#' = 5 * 3 * 2 = 30
             '1#' = 0

Para buscar los primos se usa un truco de ir saltando en pasos que van de dos, cuatro, dos, cuatro...
Esto es por la propiadad de los primos de ser todos de la forma k*6±1, sin embargo no todos estos son primos, hay que pasarlos por un filtro.
