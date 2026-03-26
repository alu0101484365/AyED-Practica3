# AyED-Practica3
Polinomios con vectores dispersos
Objetivo
La práctica consiste en el desarrollo de las clases Polynomial y SparsePolynomial para poder trabajar con Polinomios. La primera de ellas será una clase relacionada con la clase vector_t que almacena polinomios en vectores densos. La segunda será una clase heredera de la clase sparse_vector_t que almacena polinomios en vectores dispersos, a la que habrá que incorporarle un constructor adecuado. La clase vector disperso almacenará sus elementos dentro de un vector de pares (vector_t<pair_t<double>>), en los que los pares tienen dos elementos: el índice del elemento no nulo, y su valor correspondiente. Se propondrá también el desarrollo de métodos para la evaluación de un polinomio en un valor x dado y para comparar si dos polinomios son iguales. Ambos métodos se realizarán tanto para trabajar con vectores densos como dispersos.

Todo el código nuevo a desarrollar ha de ceñirse a la Google C++ Style Guide.

Recursos
Se proporciona el siguiente material:

vector_t.h: la clase vector denso
pair_t.h: definición del tipo par
sparse_vector_t.h: definición de la clase vector disperso
polynomial.h: definición de las clases para polinomios
main_polynomial.cc: programa principal de prueba
data_polynomial.txt: fichero con los datos de prueba
FASE I. COMPRENSIÓN DEL MATERIAL PROPORCIONADO
Descargar los ficheros fuente
Compilarlos y ejecutarlos:

$ g++ -g main_polynomial.cc -o main_polynomial

$ ./main_polynomial < data_polynomial.txt

Examinar los ficheros de cabecera identificando los constructores, destructores, los métodos para acceder a los atributos, los métodos para lectura desde teclado y escritura a pantalla, e identificar los elementos privados y públicos, tanto atributos como métodos. Identificar la sintaxis de las plantillas. Establecer dónde se efectúa la sobrecarga de operadores, determinar qué operadores han sido sobrecargados.

Comprender la clase pair_t que implementa una pareja índice y valor para cualquier tipo (numérico) T
Comprender la definición de la clase vector disperso (sparse_vector_t)
Comprender la definición del nuevo tipo pair_vector_t como:
typedef pair_t<double> pair_double_t;

typedef vector_t<pair_double_t> pair_vector_t;

Comprender la definición de las nuevas clases Polynomial y SparsePolynomial herederas de vector_t<double> y sparse_vector_t respectivamente
FASE II. DESARROLLO DE UN CONSTRUCTOR PARA LA CLASE sparse_vector_t
Desarrollar el constructor de la clase sparse_vector_t tal y como se ha especificado durante las clases para una clase vector disperso implementado sobre un vector de pares de tipo double (pair_vector_t)

FASE III. DESARROLLO DE MÉTODOS PARA EVALUAR EN UN PUNTO UN POLINOMIO MEDIANTE VECTOR DENSO Y VECTOR DISPERSO
Desarrollar un método Eval en cada clase Polynomial y SparsePolynomial que efectúe la evaluación del polinomio representado por el vector invocante para un valor dado de x. Los métodos debe tener la siguiente cabecera:

double Eval(const double) const;

FASE IV. DESARROLLO DE MÉTODOS PARA DETECTAR SI DOS POLINOMIOS SON IGUALES MEDIANTE VECTOR DENSO Y VECTOR DISPERSO
Desarrollar métodos IsEqual en cada clase Polynomial y SparsePolynomial que compare si son iguales el vector invocante y otro vector que se pasa como parámetro.

Los métodos debe tener las siguiente cabeceras:

Para la clase Polynomial:
bool IsEqual(const Polynomial&, const double = EPS) const;

Para la clase SparsePolynomial:
bool IsEqual(const SparsePolynomial&, const double = EPS) const;

bool IsEqual(const Polynomial&, const double = EPS) const;

donde el argumento opcional tipo double será la precisión desedada al comparar la igualdad entre dos números reales.

Evaluación
El criterio de evaluación será el siguiente:

Concluir Fase I y II, y haber resuelto satisfactoriamente la modificación propuesta: 5
Concluir Fase I, II, y III, y haber resuelto satisfactoriamente la modificación propuesta: 7
Concluir Fase I, II, III, y IV, y haber resuelto satisfactoriamente la modificación propuesta: 10
Una vez presentada la modificación de la práctica (y no antes) deben ser enviados solo los ficheros .cc y .h a través del enlace de esta tarea al campus virtual.

Resultado esperado
Si se ejecuta la práctica con todas las fases desarrolladas, la salida esperada por pantalla para el fichero data_polynomial.txt sería:

p1= 10: [ 3.4 + 2.1 x + 5.6 x^5 + 8.9 x^8 + 9.1 x^9 ]
p2= 11: [ 3.4 + 2.1 x + 5.6 x^5 + 8.9 x^8 + 9.1 x^9 ]
p3= 10: [ 1.3 x + 3.5 x^3 + 4.6 x^4 + 5.7 x^5 + 8.1 x^8 + 9.2 x^9 ]

sp1= 10(5): [ 3.4 + 2.1 x + 5.6 x^5 + 8.9 x^8 + 9.1 x^9 ]
sp2= 11(5): [ 3.4 + 2.1 x + 5.6 x^5 + 8.9 x^8 + 9.1 x^9 ]
sp3= 10(6): [ 1.3 x + 3.5 x^3 + 4.6 x^4 + 5.7 x^5 + 8.1 x^8 + 9.2 x^9 ]

p1(1)= 29.1
p1(3.3)= 549717
p1(-5)= -1.43144e+07
p2(1)= 29.1
p2(3.3)= 549717
p2(-5)= -1.43144e+07
p3(1)= 32.4
p3(3.3)= 543811
p3(-5)= -1.48201e+07

sp1(1)= 29.1
sp1(3.3)= 549717
sp1(-5)= -1.43144e+07
sp2(1)= 29.1
sp2(3.3)= 549717
sp2(-5)= -1.43144e+07
sp3(1)= 32.4
sp3(3.3)= 543811
sp3(-5)= -1.48201e+07

p1 == p1? true
p2 == p2? true
p3 == p3? true
p1 == p2? true
p2 == p1? true
p1 == p3? false
p3 == p1? false
p2 == p3? false
p3 == p2? false

sp1 == sp1? true
sp2 == sp2? true
sp3 == sp3? true
sp1 == sp2? true
sp2 == sp1? true
sp1 == sp3? false
sp3 == sp1? false
sp2 == sp3? false
sp3 == sp2? false

sp1 == p1? true
sp2 == p2? true
sp3 == p3? true
sp1 == p2? true
sp2 == p1? true
sp1 == p3? false
sp3 == p1? false
sp2 == p3? false
sp3 == p2? false