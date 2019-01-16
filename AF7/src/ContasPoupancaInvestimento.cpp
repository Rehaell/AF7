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
// para evitar ambiguidade � utilizado o operador de resolu��o de �mbito
void ContasPoupancaInvestimento::sacar(float s){
	float saldo = this->ContasPoupanca::getSaldo() + this->ContasInvestimento::getSaldo() - s; // resolu��o de �mbito

	if (saldo < 0) {
		if ((this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo()) <= 50000){
			if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
		} else if ((this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo()) <= 150000) {
			if (!((saldo/-1) <= 2000)) cout << "Limite estourado!!!" << endl;
			} else if (!((saldo/-1) <= 1000)) cout << "Limite estourado!!!" << endl;
	}

// Diminui o saldo do investimento caso positivo ainda, sen�o, retira da poupan�a
	if (this->ContasInvestimento::getSaldo() > 0) {
		this->ContasInvestimento::setSaldo(this->ContasInvestimento::getSaldo() - s); // resolu��o de ambiguidade!!!
		this->ContasInvestimento::atualizaExtrato(s, "saque");
	}
	else if (this->ContasPoupanca::getSaldo() > 0) {
			this->ContasPoupanca::setSaldo(this->ContasPoupanca::getSaldo() - s); // resolu��o de ambiguidade!!!
			this->ContasPoupanca::atualizaExtrato(s, "saque");
		}
		else cout << "Est�s quebrado!!!" << endl;
}

// M�todo para controlar o dep�sito na conta: investimento ou poupan�a
void ContasPoupancaInvestimento::depositar(float v, int op)  {
	switch (op) {
		case 1: this->ContasInvestimento::depositar(v); break;
		case 2: this->ContasPoupanca::depositar(v); break;
	}

	saldoGlobal = this->ContasInvestimento::getSaldo() + this->ContasPoupanca::getSaldo();
}

// M�todo para imprimir o extrato do investimento e da poupan�a
void ContasPoupancaInvestimento::extrato() {
	cout << "***POUPANCA***" << endl;
	this->ContasPoupanca::extrato();
	cout << "***INVESTIMENTO***" << endl;
	this->ContasInvestimento::extrato();
	cout << "SALDO GLOBAL: " << saldoGlobal << endl;
}
} /* namespace std */
