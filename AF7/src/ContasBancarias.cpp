/*
 * ContasBancarias.cpp
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasBancarias.h"

namespace std {

ContasBancarias::ContasBancarias() {
	cout << "Entre o n� da conta" << endl;
	cin >> numConta;
	cout << "Entre o nome do cliente:" << endl;
	cin >> cliente;
}

ContasBancarias::~ContasBancarias() {
	// TODO Auto-generated destructor stub
}

// Atualiza��o do saldo ap�s saques
void ContasBancarias::sacar(float v){
	saldo = saldo - v;

	if (saldo < 0) cout << "Seu saldo est� negativo: " << saldo << " �" << endl;
	else cout << "Seu saldo est� positivo: " << saldo << " �" << endl;

	atualizaExtrato(v, "saque");
}

// Atualiza��o de saldo e extrato ap�s dep�sitos
void ContasBancarias::depositar(float v) {
	saldo = saldo + v;
	atualizaExtrato(v, "dep�sito");
}

void ContasBancarias::atualizaExtrato(float v, string tipo) {
	time_t t = time(0);   // l� a data e hora atuais
	agora = localtime(&t);
	extratos e;
	e.ano = agora->tm_year;
	e.dia = agora->tm_mday;
	e.mes = agora->tm_mon;
	e.movimento = v;
	e.tipo = tipo;
}

void ContasBancarias::extrato() {
	cout << "EXTRATO" << endl;
		cout << "CLIENTE: " << cliente << endl;
		cout << "***********************************" << endl;
		for (it = movimentos.begin(); it != movimentos.end(); it++)
			cout << (*it).tipo << " " << (*it).dia << "-"
			<< (*it).mes << "-" << (*it).ano + 1900 << ":"
			<< (*it).movimento << " �" << endl;
		cout << "Saldo atual: " << saldo << " �" << endl;
		cout << "***********************************" << endl;
}
} /* namespace std */
