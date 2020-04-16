/* Marcuzzi Giuseppe
    combattimento all'infinito
	idea di N2K nel giorno 08/02/2020
	
	Nel menu' principale scelta di combattimento all'infinito.

	dove il protagonoista parte con 1 punto abilitï¿½ in ogni statistica e scegli dove assegnare i 10 punti abilitï¿½

	dopo 9 mostri scontro contro boss.

	dopo aver sconfitto il boss ha il 100 % di drop di 6 punti abilitï¿½ (da assegnare subito).

	le statistiche dei mostri (normali) aumentano del 10 % (rispetto al mostro precedente mentre le statistiche del boss aumentano del 20 % rispetto il l'ultimo mostro


	statistiche:
	forza,
	costituzione,
	dstrezza,
	fortuna,


	danno= (danno base arma)+% della forza

	Vita= 1.5 * ogni punto assegnato alla costittuzione

	schiva= 5.5 * ogni punto assegnato alla destrezza

	fortuna= 6 % per ogni punto ablita' assegnato 
	 	50 % di droppare 1 punto abilita' (nei mostri normali) (accumulabili fino al Boss)
	 		if (fortuna > 100){
			fortuna-100
				rilancio il dado.
				if (numero che esce e' compreso tra 0 e fortuna-100){
					riceve 2 punti abilita' (in totale)
				}
			}
		 nei mostri normali numero che esce e' compreso tra 0 e 70 droppa un'arma comune se tra 71 e 101 arma rara
	 	nei Boss numero che esce tra 0 e 50 droppa comune tra 51 e 80 rara tra 81 e 95 epica tra 96 e 101 leggendaria
	
   15/02/2020
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>

using namespace std;

// variabili globali
char fermaCout;

// regole
void regoleDelPGInfinito();
void regoleDelCombattimentoInfinito();
void aCosaServonoLeStatistiche();
void regoleCombattimentoInfinito();

// statistiche
int statisticheCombattimentoInfinito [4]={1, 1, 1, 1};
void assegnazioneStatisticheInfinite(); // le statistiche del combattimento all' infinito

// funzioni varie
int lanciaDado(int);


// funzioni di combattimento
void combattimentoInfinito();

int main (int argc, char *argv[]){
	
	char cosaDecideDiFare='1';
	do {
		system("CLS");
		cout << "--> 1) Giocare = 1" << endl
		     << "--> 2) Regole = 2" << endl
		     << "--> 0) Esci dal programma = 0" << endl
		     << "quando hai scelto premi il numero corrispondente" << endl;
		cosaDecideDiFare=_getch();
		std::cout << endl;
		
		switch (cosaDecideDiFare){
			case '1':
				assegnazioneStatisticheInfinite();
				combattimentoInfinito();
				break;
				
			case '2':
				regoleCombattimentoInfinito();
				break;
				
			case '0':
				break;
				
			default:
				system("CLS");
				cout << "scelta non valida" << endl
				 	 << "Premi un tasto per continuare" << endl;
				fermaCout= _getch();
				break;
		}
	} while (cosaDecideDiFare!='0');
	
	
	return 0;	
}

void regoleDelPGInfinito(){
	system("CLS");
	cout << "Il tuo personaggio partira' con 1 punto abilita' in ogni statistica (forza, costituzione, destrezza e fortuna)." << endl
		 << "Avrai a disposizione 10 punti ablita' iniziali, di cui potrai usifruire come preferisci," << endl 
		 << "assegnandoli a piacere alle varie statistiche." << endl
		 << "In questa modalita' non si ha una vera e propria storia;" << endl
		 << "quindi cerca di divertiti e di arrivare il piu' lontano possibile" << endl
		 << "per riaprire il menu' premi un tasto qualunque" << endl;
	fermaCout=_getch();
}

void regoleDelCombattimentoInfinito(){
	system("CLS");
	cout << "Quando Okin (uno che conosco io (Creatore di questo gioco (Marcuzzi Giuseppe)) mi fa i combattimenti, potro' spiegarmi meglio, al mometo accontentati" << endl << endl
		 << "Partirai affrontando dei mostri;" << endl
		 << "Essi possono dopparti 1 o piu' punti abilta' e possono dropparti anche una spada di rarezza variabile." << endl
		 << "Dopo 9 mostri sconfitti dovrai sconfiggere 1 Boss." << endl
		 << "Logicamente i Boss saranno (tendenzialmente) abbastanza piu' forti rispetto ai mostri precedenti." << endl
		 << "Una volta che hai sconfito un Boss; esso ti droppera' 6 punti abilita' ed un'arma di rarezza variabile." << endl
		 << "Cosi' all'infinito. O almeno finche' non muori." << endl
		 << "per riaprire il menu' premi un tasto qualunque" << endl;
	fermaCout=_getch();
}

void aCosaServonoLeStatistiche(){
	char qualeStatisticaVuoleVedere=0;
	do {
		system("CLS");
		cout << "In questa modalita' hai solo 4 statistiche:" << endl
			 << "--> 1) Forza = 1" << endl
			 << "--> 2) Costituzione = 2" << endl
			 << "--> 3) Destrezza = 3" << endl
			 << "--> 4) Fortuna = 4" << endl
			 << "--> 0) Torna al menu' precedente = 0" << endl;
		qualeStatisticaVuoleVedere=_getch();
		switch (qualeStatisticaVuoleVedere){
			case '1':
				cout << endl << "La Forza, insieme al danno caratteristico dell'arma che userai," << endl
					 << "servira' per calcolare il danno che infliggerai ai mosti e ai Boss." << endl
					 << "per riaprire il menu' premi un tasto qualunque" << endl;
				fermaCout=_getch();
				break;
			
			case '2':
				cout << endl << "La Costituzione e' il parametro fondamentale per la vita del tuo PG;" << endl
					 << "piu' punti assegnerai a questa caratteristica," << endl
					 << "piu' lunga sara' la vita del tuo PG." << endl
					 << "per riaprire il menu' premi un tasto qualunque" << endl;
				fermaCout=_getch();
				break;
			
			case '3':
				cout << endl << "La Destrezza e' il parametro fondamentale per poter schivare i colpi del tuo avversario," << endl
					 << "la Destrezza ti permettera' anche di poter attaccare per primo all'inzio del turno." << endl
					 << "per riaprire il menu' premi un tasto qualunque" << endl;
				fermaCout=_getch();
				break;
			
			case '4':
				cout << endl << "La Fortuna e' un paramentro particolare;" << endl
					 << "infatti esso ti permettera' di poter droppare 1 punto abilta' aggiuntivo, dopo aver sconfitto un mostro," << endl
					 << "e ti permettera' di poter droppare anche un'arma e decide anche di quale rarita' sara' quest'ultima" << endl
					 << "per riaprire il menu' premi un tasto qualunque" << endl;
				fermaCout=_getch();
				break;
			
			case '0':
				break;
				
			default:
				system("CLS");
				cout << "scelta non valida" << endl
				 	 << "Premi un tasto per continuare" << endl;
				fermaCout= _getch();
				break;
		}
	} while (qualeStatisticaVuoleVedere!='0');
	
}

void regoleCombattimentoInfinito(){
	
	system("CLS");
	char sceltaRegolePgORegoleComabttimentoInfinito;
	do {
		system("CLS");
		cout << "--> 1) Regole per crare il PG (personaggio) = 1" << endl
		     << "--> 2) Regole per il combattimento = 2" << endl
		     << "--> 3) A cosa servono le statistiche = 3" << endl
		     << "--> 0) Torna al menu' precendente = 0" << endl
		     << "quando hai scelto premi il numero corrispondente" << endl;
		sceltaRegolePgORegoleComabttimentoInfinito=_getch();
		cout << endl;
		
		switch (sceltaRegolePgORegoleComabttimentoInfinito){
			case '1':
				regoleDelPGInfinito();
				break;
				
			case '2':
				regoleDelCombattimentoInfinito();
				break;
				
			case '3':
				aCosaServonoLeStatistiche();
				break;
				
			case '0':
				break;
				
			default:
				system("CLS");
				cout << "scelta non valida" << endl
				 	 << "Premi un tasto per continuare" << endl;
				fermaCout= _getch();
				break;
		}
	} while (sceltaRegolePgORegoleComabttimentoInfinito!='0');
	
}

void assegnazioneStatisticheInfinite(){
	// da fare urgentemente
	
	
	string nomePGInfinito;
	char sicurezzaNellaDecisioneDelNomeDelPGInfinito=1;
	do {
		cout << "Partiamo con il dare un nome al tuo PG" << endl
		 	 << "N.B. deve essere senza spazi." << endl
			 << "Quando hai finito di scrivere il nome premi invio" << endl;
		cin >> nomePGInfinito;
		cout << endl << "Bene dunque questo sara' il nome del tuo PG: " << nomePGInfinito << endl
			 << "sei sicuro di questo nome?" << endl
		 	 << "Si=1 No=0" << endl;
		sicurezzaNellaDecisioneDelNomeDelPGInfinito=_getch();
		cout << endl;
	} while (sicurezzaNellaDecisioneDelNomeDelPGInfinito!='1');
	
	
	int puntiAbilitaIniziali;
	char sicurezzaNellaDecisioneDeiPuntiInfinito=1;
	do {
		puntiAbilitaIniziali=10;
		system("CLS");
		cout << "Sei giunto all'assegnazione delle statistiche del PG (reletavamente a questa modalita')." << endl
			 << "Il tuo personaggio partira' con 1 punto abilita' in ogni statistica (forza, costituzione, destrezza e fortuna)." << endl
			 << "Avrai a disposizione 10 punti ablita' iniziali, di cui potrai usifruire come preferisci," << endl 
			 << "assegnandoli a piacere alle varie statistiche." << endl
			 << "L'ordine di assegnazione sara' il seguente:" << endl
			 << "Forza, Costituzione, Destrezza, Fortuna." << endl
			 << "Ora decidi attentamente come assegnare i vari punti" << endl
			 << "Quando hai deciso inserisci il valore corrispondente e poi premi invio" << endl << endl
			 << "Forza: ";
		cin>> statisticheCombattimentoInfinito[0];
		puntiAbilitaIniziali-=statisticheCombattimentoInfinito[0];
		statisticheCombattimentoInfinito[0]++;
		cout << "Costituzione: ";
		cin>> statisticheCombattimentoInfinito[1];
		puntiAbilitaIniziali-=statisticheCombattimentoInfinito[1];
		statisticheCombattimentoInfinito[1]++;
		cout << "Destrezza: ";
		cin>> statisticheCombattimentoInfinito[2];
		puntiAbilitaIniziali-=statisticheCombattimentoInfinito[2];
		statisticheCombattimentoInfinito[2]++;
		cout << "Fortuna: ";
		cin>> statisticheCombattimentoInfinito[3];
		puntiAbilitaIniziali-=statisticheCombattimentoInfinito[3];
		statisticheCombattimentoInfinito[3]++;
		
		if (puntiAbilitaIniziali!=0){
			cout << endl << "Hai cercato di inserire troppi punti oppure troppi pochi" << endl
				 << "premi un tasto qualunque per continuare" << endl;
			fermaCout=_getch();
		} else {
			cout << endl << "I punti nelle tue statistiche attuali sono:" << endl
				 << "Forza: " << statisticheCombattimentoInfinito[0] << endl
				 << "Costituzione: " << statisticheCombattimentoInfinito[1] << endl
				 << "Destrezza: " << statisticheCombattimentoInfinito[2] << endl
				 << "Fortuna: " << statisticheCombattimentoInfinito[3] << endl << endl
				 << "sei sicuro?" << endl
				 << "Si=1 No=0" << endl;
			sicurezzaNellaDecisioneDeiPuntiInfinito=_getch();
		}
	} while (puntiAbilitaIniziali!=0 || sicurezzaNellaDecisioneDeiPuntiInfinito!='1');
	
}

void combattimentoInfinito(){
	system("CLS");
	int sceltaDellInizioAvventura;
	bool inizioAvventura;
	do {
		cout << "Finalmente siamo giunti al combattimento infinito." << endl
			<< "sei pronto?" << endl
			<< "Si=1 No=0" << endl;
		sceltaDellInizioAvventura = _getch();
		switch (sceltaDellInizioAvventura) {
		case '1':
			inizioAvventura = true;
			cout << endl << "OK, Ottimo allora iniziamo." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();;
			break;

		case '0':
			inizioAvventura = true;
			cout << endl << "Pazienza." << endl
				<< "Ormai iniziamo." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
			break;

		default:
			system("CLS");
			cout << "Scelta non valida" << endl;
			break;
		}
	} while (inizioAvventura!=true);
	system("CLS");

	char sceltaNelCombattimento;
	// contatore mostri
	int contatoreDiMostriAffrontatiTotali=0;
	int contatoreDimostriPrimaDelBoss=0;
	// statistiche armi e vita base dei mostri e PG
	int arma=2;
	int dannoPG=arma+(statisticheCombattimentoInfinito[0]-((statisticheCombattimentoInfinito[0]*10)/100));
	int vitaPG=1.5*statisticheCombattimentoInfinito[1];
	int schivata=5.5*statisticheCombattimentoInfinito[2];
	int dannoMostro=1;
	int vitaMostro=4;
	do {

		





		if (vitaPG>0){
			cout << endl << endl << "Dopo questo intenso combattimento immagino tu abbia visogno di un po' di riposo." << endl
				 << "Prenditi tutto il tempo di cui hai bisogno." << endl
				 << "Quando sei pronto a riprendere premi un tasto qualunque" << endl;
			fermaCout= _getch();
		} else {
			cout << "GAME OVER, senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
				 << "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
		}
	} while (vitaPG<=0 && sceltaNelCombattimento!='E');
	
}





/*  *COMBATTIMENTO DI ESEMPIO*

system("CLS");
cout << "Ti alzi dal tavolo, e con un capogiro si svela ai tuoi occhi il vero aspetto della sala da pranzo." << endl
 	 << "I muri e il tavolo sono sporchi di sangue, e i piatti sul tavolo sono pieni di budella viola." << endl
	 << "Il cuoco, rivelatosi essere un mostro, ti attacca." << endl;
	do {
	cout << "--> 1) attacca" << endl
		 << "--> 2) schiva" << endl;
	sceltaNelCobattimento = _getch();
	switch (sceltaNelCobattimento) {
		case '1':
			// attacco del PG
			contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
			cout << endl << "(urlo di attacco)(tipo arrrrrrrgh)" << endl
				 << "(Immaginatelo)" << endl;
			risultatoDalLancioDelDado = lanciaDado(20);
			if (risultatoDalLancioDelDado >= 13) {
				vitaDelMiniBoss = vitaDelMiniBoss - dannoPG;
				cout << endl << "Hai colpito il mostro." << endl
					 << "Gli rimane " << vitaDelMiniBoss << " di vita." << endl
					 << "Premi un tasto per continuare" << endl;
				fermaCout = _getch();
				cout << endl;
			} else {
				cout << endl << "Hai provato ad attaccarlo ma con uno scatto e' riuscito a schivarti." << endl
					 << "E ora ti sta per attaccare." << endl
					 << "Premi un tasto per continuare" << endl;
				fermaCout = _getch();
				cout << endl;
			}

			// attacco del minBoss
			if (vitaDelMiniBoss > 0) {
				contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
				risultatoDalLancioDelDado = lanciaDado(20);
				if (risultatoDalLancioDelDado >= statistichePG[2]) {
					vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
					cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
						 << "ed in quel momento e' riuscito a colpirti." << endl
						 << "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
						 << "Premi un tasto per continuare" << endl;
				fermaCout = _getch();
				cout << endl;
				} else {
					cout << endl << "Ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
						 << "Premi un tasto per continuare" << endl;
					fermaCout = _getch();
					cout << endl;
				}
			}
			break;

		case '2':
			// attacco del minBoss
			contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
			risultatoDalLancioDelDado = lanciaDado(17);
			if (risultatoDalLancioDelDado >= statistichePG[2]) {
				vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
				cout << endl << "Provi a schivare il colpo" << endl
					 << "ma non ci riesci quindi ti colpisce." << endl
					 << "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
					 << "Premi un tasto per continuare" << endl;
				fermaCout = _getch();
				cout << endl;
			} else {
				cout << endl << "Ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
					 << "Premi un tasto per continuare" << endl;
				fermaCout = _getch();
				cout << endl;
			}

			// attacco del PG
			if (vitaTemporaneaDelPG > 0) {
				contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
				cout << endl << "(urlo di attacco)(tipo arrrrrrrgh)" << endl
				 	<< "(Immaginatelo)" << endl;
				risultatoDalLancioDelDado = lanciaDado(20);
				if (risultatoDalLancioDelDado >= 10) {
					vitaDelMiniBoss = vitaDelMiniBoss - (dannoPG + 5);
					cout << endl << "Hai colpito il mostro." << endl
						 << "Gli rimane " << vitaDelMiniBoss << " di vita." << endl
						 << "Premi un tasto per continuare" << endl;
					fermaCout = _getch();
					cout << endl;
				} else {
					cout << endl << "Hai provato ad attaccarlo ma con uno scatto e' riuscito a schivarti." << endl
						 << "E ora ti sta' per attaccare." << endl
						 << "Premi un tasto per continuare" << endl;
					fermaCout = _getch();
					cout << endl;

					// 2Â° attacco del minBoss
					if (vitaDelMiniBoss > 0) {
						contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
						risultatoDalLancioDelDado = lanciaDado(25);
						if (risultatoDalLancioDelDado >= statistichePG[2]) {
							vitaTemporaneaDelPG = vitaTemporaneaDelPG - 10;
							cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
								 << "ed in quel momento e' riuscito a colpirti." << endl
								 << "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
								 << "Premi un tasto per continuare" << endl;
							fermaCout = _getch();
							cout << endl;
						} else {
							cout << endl << "Ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
								 << "Premi un tasto per continuare" << endl;
							fermaCout = _getch();
							cout << endl;
						}
					}
				}
			}
		break;

		default:
			system("CLS");
			cout << "scelta non valida" << endl << endl;
			break;
	}
} while (vitaDelMiniBoss >= 0 && vitaTemporaneaDelPG >= 0);


*/
