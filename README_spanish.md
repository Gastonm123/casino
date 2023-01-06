# Reglas de la ruleta

- En la ruleta hay 37 números, del 0 al 36.
- Dentro de las posibles apuestas, nos vamos a centrar en las llamadas apuestas simples (pares y nones; rojos y negros; mayores y menores). En la ruleta hay 18 números pares y 18 impares; 18 rojos y 18 negros; 18 mayores y 18 menores. No hace falta que te aclare cuáles son pares e impares. :-) Los menores van del 1 al 18 y los mayores del 19 al 36. Los rojos y negros los podés ver acá: http://es.wikipedia.org/wiki/Ruleta#mediaviewer/Archivo:Roulette_frz.png
- El 0 (cero) es un nro. especial que no es par, impar, rojo, negro, mayor ni menor. O sea, si sale el cero y vos apostaste a cualquiera de las apuestas simples: perdiste!
- Al acertar en una apuesta simple la banca paga el doble de la cantidad apostada.

Para la simulación vamos a suponer lo siguiente:
- La apuesta mínima de la mesa es 5.
- La apuesta máxima de la mesa es 4.000.

# Forma de apostar

Cada jugador tiene un papelito adonde va anotando sus apuestas. Cuando comienza, su libreta dice:

1 - 2 - 3 - 4

Para apostar suma los nros. de los extremos y apuesta (en este caso apuesta 1 + 4 = 5). Si gana, anota lo que ganó en el final de la línea (5), mientras que si pierde, tacha los dos nros. de los extremos (1 y 4). Para la siguiente apuesta vuelve a apostar la suma de los extremos. Ojo que lo que se anota es la ganancia y no lo que te paga la banca (ahí está tu apuesta más la ganancia). Entonces:

Si ganó le quedaría: 1 - 2 - 3 - 4 - 5 (la próxima apuesta sería 1 + 5 = 6)
Si perdió quedaría: 2 - 3 (la próxima apuesta sería 2 + 3 = 5)

Si en algún momento se queda sin nros. en la fila, vuelve al principio y anota 1 - 2 - 3 - 4. Y si en algún momento supera el máximo de la mesa, lo mismo. O sea que si la suma te da más de 4.000, hay que volver a poner 1 - 2 - 3 - 4 y apostar 5.  Lo mismo si en algún momento le queda un número menor al mínimo. Si llegara a quedarle un único número, esa es su apuesta (siempre y cuando no supere el máximo permitido).

# Simulacion

La idea es hacer un programa que simule a 6 personas jugando simultáneamente en la misma mesa, donde cada uno apuesta siempre a lo mismo (uno a rojo, otro a negro, otro a mayor, etc.). También hay que simular la ruleta usando el random de la PC (no es lo ideal, pero es lo más simple que tenemos). O sea, vos tendrías que simular la secuencia completa:
- El jugador A apuesta a rojo.
- El jugador B apuesta a negro.
- El jugador C apuesta a mayor.
- El jugador D apuesta a menor.
- El jugador E apuesta a par.
- El jugador F apuesta a impar.
- Gira la ruleta, sale un nro.
- Se paga a cada jugador según corresponda.
- Se vuelve al principio con las nuevas apuestas.
Hay que tener en cuenta que cada uno de los jugadores lleva un papelito individual y sus apuestas son independientes unas de otras (cuando gana rojo, pierde negro y por lo tanto la apuesta siguiente seguramente será distinta).

Se supone que estos 6 jugadores juegan en equipo, por lo tanto habría que hacer una simulación de 10.000 tiradas de ruleta y al final hacer un balance sumando ganancias y pérdidas de los 6, para ver si terminaron ganando, perdiendo o si salieron con la misma plata que entraron.

A los fines prácticos vamos a suponer que los jugadores tienen dinero infinito, o sea que nunca van a dejar de apostar porque se quedaron sin guita.

Estaria bueno mostrar la secuencia con la apuesta de cada jugador y el número que salió. Al terminar la simulacion se tiene que mostrar el balance final después de las 10.000 apuestas. Se puede elegir volcar los resultados en un archivo o en la pantalla.

El código debe estar documentado en inglés.
