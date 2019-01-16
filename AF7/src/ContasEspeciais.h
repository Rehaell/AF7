/*
 * ContasEspeciais.h
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#ifndef CONTASESPECIAIS_H_
#define CONTASESPECIAIS_H_

#include "ContasBancarias.h"

namespace std {

class ContasEspeciais: public std::ContasBancarias {
private:
	float saldoMinimo;
public:
	ContasEspeciais();
	virtual ~ContasEspeciais();
	void sacar(float);
};

} /* namespace std */
#endif /* CONTASESPECIAIS_H_ */
