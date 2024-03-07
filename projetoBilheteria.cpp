#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int TOTAL_FILEIRAS = 15;
const int POLTRONAS_POR_FILEIRA = 40;

char mapaOcupacao[TOTAL_FILEIRAS][POLTRONAS_POR_FILEIRA];

int lugaresOcupados = 0;
double valorBilheteria = 0.0;

void reservarPoltrona() {
    int fileira, poltrona;

    cout << "Informe a fileira (1 a " << TOTAL_FILEIRAS << "): ";
    cin >> fileira;

    if (fileira < 1 || fileira > TOTAL_FILEIRAS) {
        cout << "Fileira inválida. Tente novamente." << endl;
        return;
    }

    cout << "Informe a poltrona (1 a " << POLTRONAS_POR_FILEIRA << "): ";
    cin >> poltrona;

    if (poltrona < 1 || poltrona > POLTRONAS_POR_FILEIRA) {
        cout << "Poltrona inválida. Tente novamente." << endl;
        return;
    }

    if (mapaOcupacao[fileira - 1][poltrona - 1] == '.') {
        mapaOcupacao[fileira - 1][poltrona - 1] = '#';
        lugaresOcupados++;
        
        if (fileira >= 1 && fileira <= 5) {
            valorBilheteria += 50.00;
        } else if (fileira >= 6 && fileira <= 10) {
            valorBilheteria += 30.00;
        } else {
            valorBilheteria += 15.00;
        }

        cout << "Poltrona reservada com sucesso!" << endl;
    } else {
        cout << "Esta poltrona já está ocupada. Escolha outra." << endl;
    }
}

void exibirMapaOcupacao() {
    cout << "Mapa de Ocupação do Teatro:" << endl;
    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            cout << mapaOcupacao[i][j] << " ";
        }
        cout << endl;
    }
}

void exibirFaturamento() {
    cout << "Quantidade de lugares ocupados: " << lugaresOcupados << endl;
    cout << fixed << setprecision(2);
    cout << "Valor da bilheteria: R$ " << valorBilheteria << endl;
}

int main() {

	setlocale(LC_ALL, "");
	
    for (int i = 0; i < TOTAL_FILEIRAS; ++i) {
        for (int j = 0; j < POLTRONAS_POR_FILEIRA; ++j) {
            mapaOcupacao[i][j] = '.';
        }
    }

    int opcao;
    do {
        cout << "\nSelecione uma opção:\n"
             << "0. Finalizar\n"
             << "1. Reservar poltrona\n"
             << "2. Mapa de ocupação\n"
             << "3. Faturamento\n";
        cin >> opcao;

        switch (opcao) {
            case 1:
                reservarPoltrona();
                break;
            case 2:
                exibirMapaOcupacao();
                break;
            case 3:
                exibirFaturamento();
                break;
            case 0:
                cout << "Programa finalizado." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
