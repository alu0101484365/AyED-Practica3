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

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {
  public:
    /**
     * @brief Constructor que crea un vector disperso de tamaño n.
     * @param n Tamaño del vector original.
     */
    sparse_vector_t(const int = 0);

    /**
     * @brief Constructor que convierte un vector denso en disperso.
     * @param v Vector denso de entrada.
     * @param eps Precisión para considerar un valor como no nulo.
     */
    sparse_vector_t(const vector_t<double>&, const double = EPS);

    /**
     * @brief Constructor de copia.
     * @param sv Vector disperso a copiar.
     */
    sparse_vector_t(const sparse_vector_t&);

    /**
     * @brief Operador de asignación.
     * @param sv Vector a asignar.
     * @return Referencia al vector actual.
     */
    sparse_vector_t& operator=(const sparse_vector_t&);

    /**
     * @brief Destructor.
     */
    ~sparse_vector_t();
    
    /**
     * @brief Devuelve el número de elementos no nulos.
     * @return Número de elementos no nulos.
     */
    int get_nz(void) const;

    /**
     * @brief Devuelve el tamaño del vector original.
     * @return Tamaño total.
     */
    int get_n(void) const;

    /**
     * @brief Acceso a un elemento del vector disperso.
     * @param i Índice dentro del vector disperso.
     * @return Referencia al par (valor, índice).
     */
    pair_double_t& at(const int);

    /**
     * @brief Operador de acceso.
     * @param i Índice dentro del vector disperso.
     * @return Referencia al par.
     */
    pair_double_t& operator[](const int);
    
    /**
     * @brief Acceso constante a un elemento.
     * @param i Índice.
     * @return Referencia constante al par.
     */
    const pair_double_t& at(const int) const;

    /**
     * @brief Operador de acceso constante.
     * @param i Índice.
     * @return Referencia constante al par.
     */
    const pair_double_t& operator[](const int) const;

    /**
     * @brief Escribe el vector disperso.
     * @param os Flujo de salida.
     */
    void write(std::ostream& = std::cout) const;

  private:
    pair_vector_t pv_;  // Vector de pares (índice, valor)
    int nz_;            // Número de elementos no nulos
    int n_;             // Tamaño del vector original

    // bool IsNotZero(const double, const double = EPS) const;
};


/**
 * @brief Comprueba si un valor es distinto de cero según una tolerancia.
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

/**
 * @brief Constructor con tamaño.
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

/**
 * @brief Constructor desde vector denso.
 */
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps)
    : pv_(), nz_(0), n_(0) {
  n_ = v.get_size();
  pv_.resize(v.get_size());
  for (int i = 0; i < v.get_size(); i++) {
    if (IsNotZero(v.at(i), eps)) {
      pv_.at(nz_) = pair_t<double>(v.at(i), i);
      nz_ += 1;
    }
  }
}

/**
 * @brief Constructor de copia.
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;
}

/**
 * @brief Operador de asignación.
 */
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;
  return *this;
}

/**
 * @brief Destructor.
 */
sparse_vector_t::~sparse_vector_t() {}

/**
 * @brief Devuelve número de elementos no nulos.
 */
inline int sparse_vector_t::get_nz() const {
  return nz_;
}

/**
 * @brief Devuelve tamaño total.
 */
inline int sparse_vector_t::get_n() const {
  return n_;
}

/**
 * @brief Acceso a elemento.
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Operador [].
 */
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

/**
 * @brief Acceso constante.
 */
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Operador [] constante.
 */
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

/**
 * @brief Escritura en flujo.
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
  os << "]" << std::endl;
}

/**
 * @brief Operador de salida.
 */
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
