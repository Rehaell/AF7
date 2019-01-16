/*
 * ContasPoupanca.cpp
 *
 *  Created on: 20 de Fev de 2014
 *      Author: escarvalho
 */

#include "ContasPoupanca.h"

namespace std {

// Construtor da poupan�a guarda o dia de cria��o como refer�ncia para juros
ContasPoupanca::ContasPoupanca() {
	time_t t = time(0);   // l� a data e hora atuais
	this->setAgora(localtime(&t));
	cout << "Qual o dia para rendimento?" << endl;
	cin >> diaJuros;
	float valorInicial;
	cout << "Qual o dep�sito da poupan�a?" << endl;
	cin >> valorInicial;
	this->setSaldo(valorInicial);
}

ContasPoupanca::~ContasPoupanca() {
	// TODO Auto-generated destructor stub
}

void ContasPoupanca::rendimentoMensal(float percentual) {
	time_t t = time(0);   // l� a data e hora atuais
	this->setAgora(localtime(&t));

	if (diaJuros >= this->getAgora()->tm_mday) this->setSaldo(this->getSaldo() * (1.0 + percentual));
	else cout << "Ainda n�o � o dia de seu rendimento..." << endl;

}

} /* namespace std */
