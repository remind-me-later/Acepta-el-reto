# El misterioso caso de los múltiplos de 7

## [Enunciado](https://www.aceptaelreto.com/problem/statement.php?id=564)

## Explicación de la solución

Los números 2^k - 1 son de la forma 1111...1111 en binario, donde k es el número
de unos. Notamos que una cadena de unos en binario solo es divisible por 7 si el
número de unos es divisible entre 3 (¿Por qué?). Así lo único que tenemos que
hacer es comprobar cuántos números entre 1 y N son divisibles entre 3, o lo que
es lo mismo, dividir N entre 3.
