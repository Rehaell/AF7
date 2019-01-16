/*
 * AF6.cpp
 *
 *  Created on: 24 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasPoupanca.h"
#include "ContasPoupancaInvestimento.h"

using namespace std;

int main() {
	cout << "***CONTA DE ESPECIAL***" << endl;
	ContasEspeciais contaA;
	contaA.depositar(700);
	contaA.sacar(500);
	contaA.extrato();

	cout << "***CONTA DE POUPANÇA***" << endl;
	ContasPoupanca contaB;
	contaB.depositar(2000);
	contaB.rendimentoMensal(0.2);
	contaB.extrato();
	contaB.sacar(200);
	contaB.extrato();

	cout << "***CONTA BANCÁRIA***" << endl;
	ContasBancarias contaC;
	contaC.depositar(1000);
	contaC.sacar(200);
	contaC.extrato();

	cout << "***CONTA DE INVESTIMENTO***" << endl;
	ContasInvestimento contaD;
	contaD.depositar(3000);
	contaD.sacar(4000);
	contaD.sacar(1000);
	contaD.extrato();

	cout << "***CONTA DE INVESTIMENTO E DE POUPANÇA***" << endl;
	ContasPoupancaInvestimento contaE;
	contaE.depositar(20000, 1);
	contaE.depositar(1000, 2);
	contaE.sacar(200);
	contaE.extrato();

	return 0;
}




