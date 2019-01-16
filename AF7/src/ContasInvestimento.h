/*
 * ContasInvestimento.h
 *
 *  Created on: 24 de Fev de 2014
 *      Author: escarvalho
 */

#ifndef CONTASINVESTIMENTO_H_
#define CONTASINVESTIMENTO_H_

#include "ContasEspeciais.h"

namespace std {

class ContasInvestimento: public std::ContasEspeciais {

public:
	ContasInvestimento();
	virtual ~ContasInvestimento();
	void sacar(float);
};

} /* namespace std */
#endif /* CONTASINVESTIMENTO_H_ */
