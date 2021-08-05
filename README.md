# Trabajo Práctico N°4: Poker

### Consigna:
Vamos a programar un juego basado en una de lasformas del famoso juego de cartas póquer llamado“póquer tapado”. Para ello cuentan con una plantilla que posee algunas funcionalidades del juego ya programadas para facilitarles las decisiones de diseñodel juego. La idea es que solamente escriban lasfunciones que se detallan a continuación, sin modificarel resto de la plantilla:
- `mezclar_mazo:` debe modificar la instancia delmazo recibida para que las cartas no se encuentrenen el orden inicial. Para esto pueden usar la funciónindice_aleatorioque devuelve un índice del mazo alazar.
- `apostar:` debe mostrarle al usuario la mano ypreguntarle cuántas fichas desea apostar. Lafunción debe comprobar que la cantidad ingresadapor el usuario no supera la cantidad de fichas deljugador.
- `responder:` idem apostar(), pero ademáscomprueba que la cantidad ingresada sea igual osuperior a la del contrincante.
- `subir_apuesta:` similar a responder() pero no sevuelve a mostrar la mano y se tiene que mostrarcuántas fichas apostaron ambos jugadores hastaese momento.
- `comparar_cartas:` recibe 2 manos y devuelve trueen caso de que gane la primera mano y false sigana la segunda. El orden de los juegos para saber quien gana una mano está establecido en el reglamento. 
### Reglamento:
Cada mano consta de 5 cartas. Cada carta tiene unpalo y un “número” (algunas son letras: A,J,Q,K) alquellamamos valor. Los posibles juegos que podemosarmar son los siguientes, en orden:
- `Par:` si hay 2 cartas del mismo valor.
- `Tris:` si hay 3 cartas del mismo valor.
- `Escalera:` si los números de las 5 cartas sonconsecutivos.
- `Color:` si hay 5 cartas del mismo palo.
- `Poker:` si hay 4 cartas del mismo valor.
- `Escalera real:` si la mano es una escalera y ademástodas las cartas tienen el mismo palo.

  En los casos de los pares, tries y escaleras el desempate se produce por el valor de las cartas (en el caso de la escalera el valor de la carta más alta).El orden de los valores es: A ,2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K 
  
  Si hay empate también con los valores o si se empata en cualquiera de los otros juegos el desempate se hace por palo. 
  
  _`En orden:` Pica, Corazón, Diamante, Trébol._
  
  Notar que puede ser que ningún jugador posea un juego, en este caso se compara por carta alta. El jugador 2 siempre es el que reparte y por ende el jugador 1 es   siempre mano. 
  
  Si ninguno de los dos jugadores quiere apostar(ambos apuestan 0 fichas) entonces se devuelve el pozo y se vuelve a repartir.

  El juego termina cuando uno de los dos jugadores pierde todas las fichas. Si esto sucede durante la ronda de apuestas se permite que los jugadores estén en       deuda (cantidad de fichas negativa) con tal de que puedan terminar de jugar la mano. 
  ### Criterio de evaluación
  ---
  El trabajo práctico está aprobado si el juego presentado cumple con la consigna y el reglamento. Para llegar al 10, deberán implementar al menos 2 de las     siguientes funcionalidades:
  - Que el ás sea la carta más alta manteniendo elmismo orden. Es decir, en la escalera sigue viniendo antes del 2.
  - Que en la escalera el ás pueda estar al final. O seaque tengo 2 escaleras posibles con el ás: A,2,3,4,5y 10,J,Q,K,A.
  - Que el jugador uno no siempre sea mano.
