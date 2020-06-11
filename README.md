# TC1030 Proyecto "Brazo de 4 ejes".

Brazo que guarda cajas por colores, siendo el algoritmo de los movimientos del robot modificados por el usuario. Proyecto que simula el movimiento de un brazo robotico de 4 ejes, tiene la opcion de guardar posiciones para guardar hasta 3 tipos de cajas que se encuentran en diferentes espacios tridimencionales por cada tipo de caja. Este robot tambien puede ser manupulado manualmente con comandos de la consola.

Se usan los conceptor de programación orientado a objetos, para instanciar elementos del brazo que lo hacen funcionar de manera mecánica, algoritmica y objetiva.

# Funcionalidad (opciones que se pueden realizar).

       Menu:
Incrementa 1 grado servomotor 1 (base).

Decrementa 1 grado servomotor 1 (base).

Incrementa 1 grado servomotor 2 (articulacion 1).

Decrementa 1 grado servomotor 2 (articulacion 1).

Incrementa 1 grado servomotor 3 (articulacion 2).

Decrementa 1 grado servomotor 3 (articulacion 2).

Incrementa 1 grado servomotor 4 (mano).

Decrementa 1 grado servomotor 4 (mano).

Cantidad de cajas verdes a guardar.
       
Cantidad de cajas Rojas a guardar.
       
Cantidad de cajas Amarillas a guardar.
       
Pre-guardar posicion 1 para servos 2 y 3.

Pre-guardar posiciones 2, 3 y 4 para servos 2 y 3.

Pre-guardar posiciones 5 y 6 para servos 2 y 3.

Pre-guardar posiciones 7 y 8 para servos 2 y 3.

Guardar posiciones pre-guardadas para los servos 2 y 3.

Asignacion de abertura limite de la mano del robot.
       
Asignacion de cerradura limite de la mano del robot.
       
Guardar cajas verdes en los contenedores.

Guardar cajas rojas en los contenedores.

Guardar cajas amarillas en los contenedores.

VOLVER A MOSTRAR EL MENU.

Salir del programa.

# Consideraciones

El programa correrá en Windows, ya que cuenta con la librería windows.h para usar la función Sleep().

Compilar con: "g++ brazo.cpp -o brazo.exe" y correr "brazo.exe"
