#include <iostream>
#include <vector>
#include <utility>

using namespace std;

//trasforma a frase em uma lista de palavras
vector <string> frase_vector(string fraseParam){

    vector <string> fraseVct;

    int spacei;
    string palavra;

    do{

        spacei = fraseParam.find(' ');
        palavra = fraseParam.substr(0, spacei);

        fraseVct.push_back(palavra);

        fraseParam = fraseParam.substr(spacei + 1);

    }while(spacei != -1);

    return fraseVct;
}

//conta quantas vezes um caractere aparece na frase
int contador(string fraseParam, char caracterParam) {

    int i, qtdCaracter = 0;

    if (fraseParam.find(caracterParam) == -1){
        qtdCaracter = 0;
    }

    else {

            while(i != -1) {

                i = fraseParam.find(caracterParam);

                fraseParam = fraseParam.substr(i + 1);

                qtdCaracter++;

                i = fraseParam.find(caracterParam);

            }
    }

    return qtdCaracter;
}

//conta a quantidade de palavras repetidas na frase
int contar_repetida(string fraseParam){

    int qtdRepetidas = 0, spacei = fraseParam.find(' ');

    vector <string> fraseLista = frase_vector(fraseParam);

    for(int i = 0; i < fraseLista.size(); i++){

        for(int j = 0; j < fraseLista.size(); j++){

            if(fraseLista[j] == fraseLista[i] && i != j){
                qtdRepetidas++;
                fraseLista.erase(fraseLista.begin() + j);
            }
        }

        return qtdRepetidas;
    }
}

//inverte a 1° e a 2° palavra da frase
string trocar(string fraseParam){

    vector <string> fraseLista = frase_vector(fraseParam);

    string beginWord = fraseLista[0];
    string endWord = fraseLista[fraseLista.size() - 1];
    string fraseModif = "";

    fraseLista[0] = endWord;
    fraseLista[fraseLista.size() - 1] = beginWord;

    //swap(fraseLista[0], fraseLista.size());

    for(string palavra:fraseLista){
        fraseModif += palavra + " ";
    }

    return fraseModif;
}



int main () {

    setlocale(LC_ALL, "portuguese");

    string frase;
    int qtdA = 0;

    cout << "Digite uma frase:" << endl;

    getline(cin, frase);

    while(frase.empty()){
        cout << "***Error***" << endl << endl << "Digite uma frase:" << endl;
        getline(cin, frase);
        cout << endl;
    }

    system("cls");

    cout <<  "A frase que você digitou é: " << frase << endl << endl;
    cout << "Sua frase tem " << frase.length() << " caracteres e " << contador(frase, ' ') + 1 << " palavra(s)." << endl;
    cout << "A letra 'a' aparece " << contador(frase, 'a') << " vez(es) na sua frase" << endl;
    cout << "Existe(m) " << contar_repetida(frase) << " palavra(s) repetida(s) na sua frase" << endl << endl;

    cout << "Sua frase com a primeira palavra e a última trocadas fica assim:" << endl << trocar(frase) << endl << endl;


return 0;
}
