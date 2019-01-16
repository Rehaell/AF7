/*
 * ContasInvestimento.cpp
 *
 *  Created on: 24 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasInvestimento.h"

namespace std {

ContasInvestimento::ContasInvestimento() {
	float s;
	cout << "Qual é o valor do investimento?" << endl;
	cin >> s;
	this->setSaldo(s);
}

ContasInvestimento::~ContasInvestimento() {
	// TODO Auto-generated destructor stub
}

// Controla saque de conta de investimento
void ContasInvestimento::sacar(float s){
	float saldo = this->getSaldo() - s;

	if (saldo < 0) {
		if (this->getSaldo() <= 50000){
			if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
		} else if (this->getSaldo() <= 150000) {
			if (!((saldo/-1) <= 2000)) cout << "Limite estourado!!!" << endl;
			} else if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
	}

	this->setSaldo(saldo);
	this->atualizaExtrato(s, "saque");
}
} /* namespace std */
