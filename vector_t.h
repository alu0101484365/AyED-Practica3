/** 
 * AUTOR: Raúl Navarro Cobos
 * FECHA: 17/03/2026
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRACTICA: 3
 * ESTILO: Google C++ Style Guide
 * COMENTARIOS: 
 * COMPILACION: g++ -g main_polynomial.cc -o main_polynomial
 * EJECUCION: ./main_polynomial < data_polynomial.txt
 */

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {
  public:
    /**
     * @brief Constructor que crea un vector de tamaño n.
     * @param n Tamaño del vector.
     */
    vector_t(const int = 0);

    /**
     * @brief Constructor de copia.
     * @param v Vector a copiar.
     */
    vector_t(const vector_t&);

    /**
     * @brief Operador de asignación.
     * @param v Vector a asignar.
     * @return Referencia al vector actual.
     */
    vector_t<T>& operator=(const vector_t<T>&);

    /**
     * @brief Destructor.
     */
    ~vector_t();
    
    /**
     * @brief Obtiene el valor en una posición.
     * @param i Índice.
     * @return Valor almacenado.
     */
    T get_val(const int) const;

    /**
     * @brief Obtiene el tamaño del vector.
     * @return Tamaño del vector.
     */
    int get_size(void) const;
    
    /**
     * @brief Modifica el valor en una posición.
     * @param i Índice.
     * @param val Valor a asignar.
     */
    void set_val(const int, const T);
    
    /**
     * @brief Acceso a un elemento con referencia.
     * @param i Índice.
     * @return Referencia al elemento.
     */
    T& at(const int);

    /**
     * @brief Operador de acceso.
     * @param i Índice.
     * @return Referencia al elemento.
     */
    T& operator[](const int);
    
    /**
     * @brief Acceso constante a un elemento.
     * @param i Índice.
     * @return Referencia constante al elemento.
     */
    const T& at(const int) const;

    /**
     * @brief Operador de acceso constante.
     * @param i Índice.
     * @return Referencia constante al elemento.
     */
    const T& operator[](const int) const;

    /**
     * @brief Redimensiona el vector.
     * @param n Nuevo tamaño.
     */
    void resize(const int);
    
    /**
     * @brief Lee el vector desde un flujo.
     * @param is Flujo de entrada.
     */
    void read(std::istream& = std::cin);

    /**
     * @brief Escribe el vector en un flujo.
     * @param os Flujo de salida.
     */
    void write(std::ostream& = std::cout) const;

  private:
    T *v_;   ///< Puntero al array dinámico
    int sz_; ///< Tamaño del vector
    
    /**
     * @brief Reserva memoria para el vector.
     */
    void build(void);

    /**
     * @brief Libera la memoria del vector.
     */
    void destroy(void);
};


/**
 * @brief Constructor con tamaño.
 */
template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

/**
 * @brief Constructor de copia.
 */
template<class T> vector_t<T>::vector_t(const vector_t<T>& w)
    : v_(NULL), sz_(0) {
  *this = w;
}

/**
 * @brief Operador de asignación.
 */
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  return *this;
}

/**
 * @brief Destructor.
 */
template<class T> vector_t<T>::~vector_t() {
  destroy();
}

/**
 * @brief Reserva memoria.
 */
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/**
 * @brief Libera memoria.
 */
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

/**
 * @brief Redimensiona el vector.
 */
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

/**
 * @brief Devuelve valor en índice.
 */
template<class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Devuelve tamaño.
 */
template<class T> inline int vector_t<T>::get_size() const {
  return sz_;
}

/**
 * @brief Asigna valor.
 */
template<class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/**
 * @brief Acceso con referencia.
 */
template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Operador [].
 */
template<class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}

/**
 * @brief Acceso constante.
 */
template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief Operador [] constante.
 */
template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

/**
 * @brief Lectura desde flujo.
 */
template<class T> void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

/**
 * @brief Escritura en flujo.
 */
template<class T> void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}


/**
 * @brief Operador de entrada.
 */
template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) { 
  v.read(is); 
  return is; 
} 


/**
 * @brief Operador de salida.
 */
template<class T> std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) { 
  v.write(os); 
  return os; 
}

#endif  // VECTORT_H_
