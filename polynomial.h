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

#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  // fabs, pow

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
  public:
    /**
     * @brief Constructor que crea un polinomio de grado n.
     * @param n Tamaño del vector (grado + 1).
     */
    Polynomial(const int n = 0) : vector_t<double>(n) {};

    /**
     * @brief Constructor de copia.
     * @param pol Polinomio a copiar.
     */
    Polynomial(const Polynomial& pol)
        : vector_t<double>(pol) {};

    /**
     * @brief Destructor.
     */
    ~Polynomial() {};

    /**
     * @brief Escribe el polinomio.
     * @param os Flujo de salida.
     * @param eps Precisión para considerar coeficientes no nulos.
     */
    void Write(std::ostream& = std::cout, const double eps = EPS) const;
    
    /**
     * @brief Evalúa el polinomio en un valor x.
     * @param x Valor donde evaluar.
     * @return Resultado de la evaluación.
     */
    double Eval(const double) const;

    /**
     * @brief Compara si dos polinomios son iguales.
     * @param pol Polinomio a comparar.
     * @param eps Precisión de comparación.
     * @return true si son iguales, false en caso contrario.
     */
    bool IsEqual(const Polynomial&, const double = EPS) const;
};


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
  public:
    /**
     * @brief Constructor con tamaño.
     * @param n Tamaño del polinomio.
     */
    SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};

    /**
     * @brief Constructor desde polinomio denso.
     * @param pol Polinomio denso.
     */
    SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};

    /**
     * @brief Constructor de copia.
     * @param spol Polinomio disperso a copiar.
     */
    SparsePolynomial(const SparsePolynomial&);

    /**
     * @brief Destructor.
     */
    ~SparsePolynomial() {};

    /**
     * @brief Escribe el polinomio disperso.
     * @param os Flujo de salida.
     */
    void Write(std::ostream& = std::cout) const;
    
    /**
     * @brief Evalúa el polinomio en x.
     * @param x Valor donde evaluar.
     * @return Resultado de la evaluación.
     */
    double Eval(const double) const;

    /**
     * @brief Compara dos polinomios dispersos.
     * @param spol Polinomio a comparar.
     * @param eps Precisión.
     * @return true si son iguales.
     */
    bool IsEqual(const SparsePolynomial&, const double = EPS) const;

    /**
     * @brief Compara un polinomio disperso con uno denso.
     * @param pol Polinomio denso.
     * @param eps Precisión.
     * @return true si son iguales.
     */
    bool IsEqual(const Polynomial&, const double = EPS) const;
};


// E/S]
/**
 * @brief Escribe el polinomio en formato legible.
 */
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}


/**
 * @brief Operador de salida.
 */
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}


// Operaciones con polinomios

/**
 * @brief Evaluación de un polinomio representado por vector denso
 */ 
double Polynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_size(); ++i) {
    result += at(i) * pow(x, i);
  }
  return result;
}


/**
 * @brief Comparación si son iguales dos polinomios representados por vectores densos
 */
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int size1 = get_size();
  int size2 = pol.get_size();
  int maximo = (size1 > size2) ? size1 : size2;
  for (int i = 0; (i < maximo) && (differents == false); ++i) {
    double coef1 = (i < size1) ? at(i) : 0.0;
    double coef2 = (i < size2) ? pol.at(i) : 0.0;
    if (fabs(coef1 - coef2) > eps) {
      differents = true;
    }
  }
  return !differents;
}


/**
 * @brief Constructor de copia.
 */
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

// E/S
/**
 * @brief Escribe el polinomio disperso.
 */
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}


/**
 * @brief Operador de salida.
 */
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
/**
 * @brief Evalúa el polinomio disperso.
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  for (int i = 0; i < get_nz(); ++i) {
    result += at(i).get_val() * pow(x, at(i).get_inx());
  }
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores dispersos
/**
 * @brief Compara dos polinomios dispersos.
 */
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol
			       , const double eps) const {
  bool differents = false;
  int maximo = (get_n() > spol.get_n()) ? get_n() : spol.get_n();
  for (int i = 0; (i < maximo) && (differents == false); ++i) {
    double coef1 = 0.0;
    double coef2 = 0.0;
    for (int j = 0; j < get_nz(); ++j) {
      if (at(j).get_inx() == i) {
        coef1 = at(j).get_val();
      }
    }
    for (int j = 0; j < spol.get_nz(); ++j) {
      if (spol.at(j).get_inx() == i) {
        coef2 = spol.at(j).get_val();
      }
    }
    if (fabs(coef1 - coef2) > eps) {
      differents = true;
    }
  }
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
/**
 * @brief Compara polinomio disperso con denso.
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  int size1 = get_n();
  int size2 = pol.get_size();
  int maximo = (size1 > size2) ? size1 : size2;
  for (int i = 0; (i < maximo) && (differents == false); ++i) {
    double coef1 = 0.0;
    double coef2 = (i < size2) ? pol.at(i) : 0.0;
    for (int j = 0; j < get_nz(); ++j) {
      if (at(j).get_inx() == i) {
        coef1 = at(j).get_val();
      }
    }
    if (fabs(coef1 - coef2) > eps) {
      differents = true;
    }
  }
  return !differents;
}

#endif  // POLYNOMIAL_H_
