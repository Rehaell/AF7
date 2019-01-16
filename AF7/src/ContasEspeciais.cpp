/*
 * ContasEspeciais.cpp
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasEspeciais.h"

namespace std {

ContasEspeciais::ContasEspeciais() {
	cout << "Entre o limite mínimo de saldo:" << endl;
	cin >> saldoMinimo;
}

ContasEspeciais::~ContasEspeciais() {
	// TODO Auto-generated destructor stub
}

void ContasEspeciais::sacar(float v) {
	this->setSaldo(this->getSaldo() - v);

	if (this->getSaldo() < 0)
		if (abs(this->getSaldo()) < saldoMinimo) cout << "Estourou o seu limite mínimo de saldo!!!" << endl;

	this->atualizaExtrato(v, "saque");
}

} /* namespace std */
