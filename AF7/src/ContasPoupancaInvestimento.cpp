/*
 * ContasPoupancaInvestimento.cpp
 *
 *  Created on: 24 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasPoupancaInvestimento.h"

namespace std {

ContasPoupancaInvestimento::ContasPoupancaInvestimento() {
	// TODO Auto-generated constructor stub

}

ContasPoupancaInvestimento::~ContasPoupancaInvestimento() {
	// TODO Auto-generated destructor stub
}

// Controla saque de conta de investimento
// para evitar ambiguidade é utilizado o operador de resolução de âmbito
void ContasPoupancaInvestimento::sacar(float s){
	float saldo = this->ContasPoupanca::getSaldo() + this->ContasInvestimento::getSaldo() - s; // resolução de âmbito

	if (saldo < 0) {
		if ((this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo()) <= 50000){
			if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
		} else if ((this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo()) <= 150000) {
			if (!((saldo/-1) <= 2000)) cout << "Limite estourado!!!" << endl;
			} else if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
	}

// Diminui o saldo do investimento caso positivo ainda, senão, retira da poupança
	if (this->ContasInvestimento::getSaldo() > 0) {
		this->ContasInvestimento::setSaldo(this->ContasInvestimento::getSaldo() - s); // resolução de ambiguidade!!!
		this->ContasInvestimento::atualizaExtrato(s, "saque");
	}
	else if (this->ContasPoupanca::getSaldo() > 0) {
			this->ContasPoupanca::setSaldo(this->ContasPoupanca::getSaldo() - s); // resolução de ambiguidade!!!
			this->ContasPoupanca::atualizaExtrato(s, "saque");
		}
		else cout << "Estás quebrado!!!" << endl;
}

// Método para controlar o depósito na conta: investimento ou poupança
void ContasPoupancaInvestimento::depositar(float v, int op)  {
	switch (op) {
		case 1: this->ContasInvestimento::depositar(v); break;
		case 2: this->ContasPoupanca::depositar(v); break;
	}

	saldoGlobal = this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo();
}

// Método para imprimir o extrato do investimento e da poupança
void ContasPoupancaInvestimento::extrato() {
	cout << "***POUPANCA***" << endl;
	this->ContasPoupanca::extrato();
	cout << "***INVESTIMENTO***" << endl;
	this->ContasInvestimento::extrato();
	cout << "SALDO GLOBAL: " << saldoGlobal << endl;
}
} /* namespace std */
