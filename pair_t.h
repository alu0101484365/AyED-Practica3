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

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
  public:
    /**
     * @brief Constructor por defecto.
     */
    pair_t(void); 

    /**
     * @brief Constructor con valor e índice.
     * @param val Valor almacenado.
     * @param inx Índice asociado.
     */
    pair_t(T, int);

    /**
     * @brief Destructor.
     */
    ~pair_t(void);

    /**
     * @brief Obtiene el valor.
     * @return Valor almacenado.
     */
    T get_val(void) const;

    /**
     * @brief Obtiene el índice.
     * @return Índice almacenado.
     */
    int get_inx(void) const;

    /**
     * @brief Asigna valor e índice.
     * @param val Valor a asignar.
     * @param inx Índice a asignar.
     */
    void set(T, int);

    /**
     * @brief Lee el par desde un flujo.
     * @param is Flujo de entrada.
     * @return Flujo de entrada.
     */
    std::istream& read(std::istream& is = std::cin);

    /**
     * @brief Escribe el par en un flujo.
     * @param os Flujo de salida.
     * @return Flujo de salida.
     */
    std::ostream& write(std::ostream& os = std::cout) const;

  private:
    T val_;   // Valor almacenado
    int inx_; // Índice asociado
};


/**
 * @brief Constructor por defecto.
 */
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}


/**
 * @brief Constructor con parámetros.
 */
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}


/**
 * @brief Destructor.
 */
template<class T> pair_t<T>::~pair_t() {}


/**
 * @brief Asigna valor e índice.
 */
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}


/**
 * @brief Devuelve el índice.
 */
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}


/**
 * @brief Devuelve el valor.
 */
template<class T> T pair_t<T>::get_val() const {
  return val_;
}


/**
 * @brief Lee el par desde flujo.
 */
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}


/**
 * @brief Escribe el par en flujo.
 */
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}


/**
 * @brief Operador de salida.
 */
template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
