/*
 * ContasPoupancaInvestimento.h
 *
 *  Created on: 24 de Fev de 2014
 *      Author: escarvalho
 */

#ifndef CONTASPOUPANCAINVESTIMENTO_H_
#define CONTASPOUPANCAINVESTIMENTO_H_

#include "ContasInvestimento.h"
#include "ContasPoupanca.h"

namespace std {
// Heran�a m�ltipla, no caso, p�blica para ambas as classes m�es
class ContasPoupancaInvestimento: public std::ContasInvestimento, public std::ContasPoupanca {
private:
	float saldoGlobal;
public:
	ContasPoupancaInvestimento();
	virtual ~ContasPoupancaInvestimento();
	void sacar(float);
	float getSaldoGlobal() { return saldoGlobal; };
	void depositar(float, int);
	void extrato();
};

} /* namespace std */
#endif /* CONTASPOUPANCAINVESTIMENTO_H_ */
