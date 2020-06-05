# TC1030 Proyecto "Brazo de 4 ejes".

Brazo que guarda cajas por colores, siendo el algoritmo de los movimientos del robot modificados por el usuario. Proyecto que simula el movimiento de un brazo robotico de 4 ejes, tiene la opcion de guardar posiciones para guardar hasta 3 tipos de cajas que se encuentran en diferentes espacios tridimencionales por cada tipo de caja Por ser un abance se entrega de forma simulada con la terminal de la computadora, posteriormente se entregará en un sketch de arduino (usando hardware) que será controlado de manera inhalambrica por medio de una interfaz gráfica manipulada desde un smarphone.

Se usan los conceptor de programación orientado a objetos, para instanciar elementos del brazo que lo hacen funcionar de manera mecánica, algoritmica y objetiva.

# Funcionalidad (opciones que se pueden realizar).

       Menu:
'a' Incrementa 1 grado servomotor 1 (base).

'b' Decrementa 1 grado servomotor 1 (base).

'c' Incrementa 1 grado servomotor 2 (articulacion 1).

'd' Decrementa 1 grado servomotor 2 (articulacion 1).

'e' Incrementa 1 grado servomotor 3 (articulacion 2).

'f' Decrementa 1 grado servomotor 3 (articulacion 2).

'g' Incrementa 1 grado servomotor 4 (mano).

'h' Decrementa 1 grado servomotor 4 (mano).

'(numero)'+',' Cantidad de cajas verdes.
       
'(numero)'+'=' Cantidad de cajas Rojas.
       
'(numero)'+'/' Cantidad de cajas Amarillas.
       
'i' Pre-guardar posicion 1 para servos 2 y 3.

'j' Pre-guardar posiciones 2, 3 y 4 para servos 2 y 3.

'k' Pre-guardar posiciones 5 y 6 para servos 2 y 3.

'l' Pre-guardar posiciones 7 y 8 para servos 2 y 3.

'm' Guardar posiciones pre-guardadas para los servos 2 y 3.

'(numero)'+'%' Asignacion de abertura limite de la mano del robot.
       
'(numero)'+'#' Asignacion de cerradura limite de la mano del robot.
       
'n' Guardar cajas verdes en los contenedores.

'o' Guardar cajas rojas en los contenedores.

'p' Guardar cajas amarillas en los contenedores.

's' VOLVER A MOSTRAR EL MENU.

'q' Salir del programa.

# Consideraciones

El programa correrá en Windows, ya que cuenta con la librería windows.h para usar la función Sleep().

Compilar con: "g++ brazo.cpp -o brazo.exe" y correr "brazo.exe"
