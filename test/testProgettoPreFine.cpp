/* Marcuzzi Giuseppe
	Sessione di D&D
   24/03/2020

   29/01/2020 ho finalmente ricevuto la base della prima storia (i 2 portoni)
   24/02/2020 ho finalmente ricevuto il sistema di combattimenti
*/

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;

// variabili globali
bool godMod = false; // per attivare la godMod vado in regoleDelCombattimento e premo g (in minuscolo)
bool stampareLeClassiOLeRegole = false; // se e' false stampa la classe se e' true stampa la razza
char fermaCout;

// danno + vita del personaggio
int dannoPG = 0; // danno totale che il PG fa
int vitaPG = 0; // vita totale che il PG ha

// storia portoni
bool haAnalizzatoLAtlare = false;
float contatoreDelleAzioni = 0; // MOLTO IMPORTANTE PER UN FINALE SE AZIONI>30 LA DONNA MUORE E QUINDI TE PERDI
bool vuoleTornareAi2PortoniNelSaloneGrande = false;
// porta di destra e sinistra
bool chiaveDelCuoco = false;
bool chiaveArruginita = false;
// finali
bool personaggioMorto = false;
bool morteDellaDonnaCheUrla = false;
bool morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = false;
bool fineDellaStoriaDelGrandeSalone = false;

// statistiche e lancio dei dadi
int statistichePG[6] = { 0, 0, 0, 0, 0, 0 };
int lanciaDado(int);

// funzioni regole + creazione PG
void regoleDelPG();
void regoleDelCombattimento();
void regoleDelGioco();
char menuDellaClasseORazza(string);
char staisticheDaAumentare();
void creazionePG();

// storia portoni
int riduzioneDeiMostri(int, int);
void aperturaPorteDellaPortaDiSinistraNelSalonePrincipale();
void portaDiSinistraNelSalonePrincipale();
bool labirintoDelleTreStanzeNelPortoneDiDestra(bool);
bool portaDiDestraNelSalonePrincipale(bool);
void inizioStoria();


int main(int argc, char* argv[]) {
	srand(time(NULL));
	int esciDalProgramma = 1;
	char doveLUtenteVuoleAndarePartendoDalPrimoMenu = '1';
	godMod = false;
	do {
		system("CLS");
		cout << "Dungeons & Dragons (D&D) (in c++)" << endl
			<< "made by Giuseppe Marcuzzi" << endl << endl
			<< "Premi un tasto per continuare" << endl;
		fermaCout = _getch();
		cout << endl;
		cout << "--> 1) Giocare = 1" << endl
			<< "--> 2) Manuale = 2" << endl
			<< "--> 3) Test lancio dadi = 3" << endl
			<< "--> 4) Lingua" << endl
			<< "--> 5) Ringraziamenti = 5" << endl
			<< "--> 0) Esci dal programma = 0" << endl
			<< "quando hai scelto premi il numero corrispondente" << endl;
		doveLUtenteVuoleAndarePartendoDalPrimoMenu = _getch();
		std::cout << endl;

		switch (doveLUtenteVuoleAndarePartendoDalPrimoMenu) {
		case '1':
			creazionePG();
			inizioStoria();
			godMod = false;
			break;

		case '2':
			regoleDelGioco();
			break;

		case '3':
		{
			int quanteVolteLanciareIlDado = 1;
			do {
				cout << "per quante volte vuoi lanciare il dado?" << endl;
				std::cin >> quanteVolteLanciareIlDado;
			} while (quanteVolteLanciareIlDado <= 0);
			int facce;
			do {
				cout << "quante facce deve avere il dado?" << endl;
				std::cin >> facce;
				cout << endl;
			} while (facce <= 0);
			for (int i = 0; i < quanteVolteLanciareIlDado; i++) {
				std::cout << lanciaDado(facce) << " ";
			}
			cout << endl << "Premi un tasto per continuare" << endl;
			fermaCout = _getch();
		}
		break;



		case '5':
			system("CLS");
			cout << "Un grandissimo ringraziamento a:" << endl << endl
				<< "Arbjo Guza: Tutto quello che riguarda i combattimenti" << endl << endl
				<< "Paola Trevisiol: Controllo e correzione del testo" << endl
				<< "     (eventuali errori testuali/lessicali sono colpa di Marcuzzi Giuseppe)." << endl << endl
				<< "Nico/Okin: Storia base dei 2 portoni" << endl << endl
				<< "Per avermi supportato ma sopratutto sopportato per tutto il tempo in cui mi hanno aiutato." << endl
				<< "Premi un tasto per continuare" << endl;
			fermaCout = _getch();
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
	} while (doveLUtenteVuoleAndarePartendoDalPrimoMenu != '0');

	return 0;
}

int lanciaDado(int facce) {

	return rand() % facce + 1;
}

void regoleDelPG() {

	char sceltaDiCosaVuoleVedere = 0;
	int cosaVuoleVedereNelleRegoleDelPG = 1;
	while (cosaVuoleVedereNelleRegoleDelPG != 0) {
		cout << "--> 1) Classe = 1" << endl
			<< "--> 2) Razza = 2" << endl
			<< "--> 3) Statistiche e calcolo statistiche= 3" << endl
			<< "--> 0) Indietro = 0" << endl
			<< "quando hai scelto premi il numero corrispondente" << endl;
		fermaCout = _getch();
		cout << endl;

		switch (fermaCout) {

		case '1':
			// Classe
			system("CLS");
			std::cout << "Scegli una delle seguenti classi: "
				<< "N.B. Valuta attentamente quale classe scegliere," << endl
				<< "poiche' ogni classe ha una determinata arma." << endl
				<< "Essa, insieme alle tue statistiche, decidera' quanto danno infliggerai," << endl
				<< "le classi, insieme alle tue statistiche, decideranno anche quanta vita avra' il tuo PG" << endl << endl
				<< "Barbaro: Forte e non civilizzato. I barbari sono considerati guerrieri feroci." << endl
				<< "Ascia: 20 + statistica, Vita: 30 + statistica" << endl << endl
				<< "Guerriero: Coraggioso e deciso." << endl
				<< "I guerrieri sono abilissimi nell'uso delle armi e delle armature." << endl
				<< "Spada lunga: 18 + statistica, Vita: 32 + statistica" << endl << endl
				<< "Monaco: Maestro delle arti marziali." << endl
				<< "I monaci addestrano mente e corpo all'attacco e alla difesa." << endl
				<< "Pugni: 15 + statistica, Vita: 35 + statistica" << endl << endl
				<< "Paladino: Difensore del bene e della giustizia." << endl
				<< "I paladini sono cavalieri devoti a una divinita'." << endl
				<< "Martello: 18 + statistica, Vita: 32 + statistica" << endl << endl
				<< "Ranger: Esperto degli animali e della natura." << endl
				<< "I ranger inseguono e danno la caccia ai nemici." << endl
				<< "Spada corta: 15 + statistica, Vita: 35 + statistica" << endl << endl
				<< "Ladro: Assassino furtivo." << endl
				<< "I ladri sono criminali astuti e vedette abili." << endl
				<< "Pugnali: 15 + statistica, Vita: 35 + statistica" << endl << endl
				<< "Stregone: Nato con il dono della magia." << endl
				<< "Gli stregoni sono in grado di controllare energie antiche e insolite." << endl
				<< "Bastone magico: 12 + statistica, Vita 38 + statistica" << endl << endl
				<< "Mago: Ha dedicato tutta la vita allo studio della magia." << endl
				<< "Anni di studi consentono ai maghi di utilizzare poteri magici incredibili." << endl
				<< "Grimorio: 13 + statistica, Vita: 37 + statistica" << endl << endl
				<< "per riaprire il menu' premi un tasto qualunque" << endl;
			fermaCout = _getch();
			cout << endl;
			break;

		case '2':
			// Razze
			system("CLS");
			std::cout << "Dopo aver scelto una classe dovrai scegliere una razza tra le seguenti: " << endl
				<< "N.B. Valuta attentamente quale razza scegliere, poiche' essa ti portera' dei vantaggi e degli svantaggi rispetto alle statistiche del tuo personaggio." << endl << endl
				<< "Nani: Bassi, tozzi, resistenti e forti. Sono molto legati alla terra. I nani spesso vivono nelle montagne e nel sottosuolo." << endl
				<< "Modificatori delle statistiche: +2 Costituzione, +2 Saggezza, -2 Carisma." << endl << endl
				<< "Elfi: Alti, longevi, appaiono freddi e distaccati, ma sono molto legati alla natura." << endl
				<< "Gli elfi vivono in armonia con il mondo naturale che li circonda." << endl
				<< "Modificatori delle statistiche: +2 Destrezza, +2 Intelligenza, -2 Costituzione." << endl << endl
				<< "Gnomi: Misteriosi, bizzarri e alla ricerca di avventura. Gli gnomi sono la razza comune piu' piccola." << endl
				<< "Modificatori delle statistiche: +2 Costituzione, -2 Carisma, +2 Forza." << endl << endl
				<< "Mezzelfi: Solitari ma cordiali, sono longevi e posseggono movenze aggraziate." << endl
				<< "I mezzelfi non sono molto numerosi e hanno la tendenza a vagabondare, perche' non hanno una vera patria." << endl
				<< "Modificatori delle statistiche: +2 a un punteggio di caratteristica." << endl << endl
				<< "Mezzorchi: Independenti, forti e malvisti. I mezzorchi sono considerati mostri dalla gente comune, sono alti e muscolosi." << endl
				<< "Modificatori delle statistiche: +2 a un punteggio di caratteristica -2 Carisma." << endl << endl
				<< "Halfling: Ottimisti, allegri, curiosi e di bassa statura. In media sono alti poco meno di un metro, sono agili ma non hanno una grande forza." << endl
				<< "Modificatori delle statistiche: +2 Destrezza, +2 Carisma, ?2 Forza." << endl << endl
				<< "Umani: Capaci di adattarsi a tutte le situazioni, ambiziosi ed equilibrati. Gli umani sono la razza dominante, con grande varieta' di culture e caratteristiche fisiche." << endl
				<< "Modificatori delle statistiche: +2 a un punteggio di caratteristica." << endl
				<< "per riaprire il menu' premi un tasto qualunque" << endl;
			fermaCout = _getch();
			cout << endl;
			break;

		case '3':
			// Statistiche
			system("CLS");
			std::cout << "ogni PG ha delle statistiche:" << endl
				<< "Forza (For). La misura della forza fisica." << endl
				<< "E' importante per i personaggi che combattono corpo a corpo, come guerrieri, monaci e paladini." << endl << endl
				<< "Destrezza (Des). La misura dell'agilit?, dell'equilibrio e dei riflessi." << endl
				<< "E' importante per i ladri, per i personaggi che indossano armature leggere o medie e per chi attacca a distanza (con archi e fionde, ad esempio)." << endl << endl
				<< "Costituzione (Cos). La misura di salute e tempra." << endl
				<< "Aumenta i punti ferita del personaggio che, quando arrivano a zero, portano alla perdita di coscienza o al decesso." << endl << endl
				<< "Intelligenza (Int). La misura della conoscenza." << endl
				<< "E' Importante per i maghi e le classi che devono apprendere informazioni o avere capacit? logiche, come i paladini." << endl << endl
				<< "Saggezza (Sag). La misura del buonsenso." << endl
				<< "Contribuisce alla consapevolezza e alla forza di volont?. Importante per ranger" << endl << endl
				<< "Carisma (Car). La misura del fascino." << endl
				<< "Un alto punteggio in questa caratteristica rende il personaggio pi? gradevole, pi? bello e dalle migliori capacit? di comando." << endl
				<< "E' importante per paladini e stregoni." << endl << endl << endl;

			// Lancio dadi per le statistiche
			cout << "Calcolo delle statistiche del PG:" << endl
				<< "Il programma lancer? 4 dadi da sei facce e sommer? i valori risultanti;" << endl
				<< "le somme totali costituiranno i valori che verranno assegnati alle tue statistiche." << endl
				<< "Se hai dubbi sul metodo di calcolo dei valori," << endl
				<< "puoi fare un test nella sezione 'Test lancio dadi' del men? principale." << endl
				<< "per riaprire il menu' premi un tasto qualunque" << endl;
			fermaCout = _getch();
			cout << endl;
			break;

		case '0':
			cosaVuoleVedereNelleRegoleDelPG = 0;
			cout << endl;
			break;

		default:
			system("CLS");
			cout << "scelta non valida" << endl << endl;
			break;
		}
	}
}

void regoleDelCombattimento() {

	system("CLS");
	cout << "Il combattimento e' diviso a turni:" << endl
		<< "Avrai 2 scelte: attacca o schiva" << endl
		<< "Se scegli di attaccare, verra' lanciato un dado in base al quale si decidera' se hai colpito il tuo avversario;" << endl
		<< "se il tuo avversario non muore ti attacchera' nel medesimo modo." << endl
		<< "Se scegli di schivare, il tuo avversario attacchera' per primo," << endl
		<< "ma se riuscirai a colpirlo gli infliggerai un danno maggiore," << endl
		<< "anche se dopo ti attacchera' per una seconda volta." << endl
		<< "Per riaprire il menu' premi un tasto qualunque" << endl;
	fermaCout = _getch();
	if (fermaCout == 'g') {
		godMod = true;
	}
}

void regoleDelGioco() {

	int esciDalleRegoleDelGioco = 1;
	char sceltaSeRegolePgORegoleComabttimento;
	while (esciDalleRegoleDelGioco != 0) {
		system("CLS");
		cout << "--> 1) Regole per crare un PG (personaggio) = 1" << endl
			<< "--> 2) Regole per il combattimento = 2" << endl
			<< "--> 0) Torna al menu' precendente = 0" << endl
			<< "quando hai scelto premi il numero corrispondente" << endl;
		sceltaSeRegolePgORegoleComabttimento = _getch();
		cout << endl;

		switch (sceltaSeRegolePgORegoleComabttimento) {
		case '1':
			regoleDelPG();
			break;

		case '2':
			regoleDelCombattimento();
			break;

		case '0':
			esciDalleRegoleDelGioco = 0;
			break;

		default:
			system("CLS");
			std::cout << "scelta non valida" << endl << endl;
			break;
		}
	}
}

char menuDellaClasseORazza(string categoria) {

	string classi[8] = {
	"Barbaro",
	"Guerriero",
	"Monaco",
	"Paladino",
	"Ranger",
	"Ladro",
	"Stregone",
	"Mago" };

	string razze[7] = {
	"Nano",
	"Elfo",
	"Gnomo",
	"Mezzelfo",
	"Mezzorco",
	"Halfling",
	"Umano" };

	char voceDelMenu;

	if (stampareLeClassiOLeRegole == false) {
		for (int conta = 0; conta < 8; conta++) {
			cout << conta + 1 << ")-> " << classi[conta] << endl;
		}
	}
	else {
		for (int conta = 0; conta < 7; conta++) {
			cout << conta + 1 << ")-> " << razze[conta] << endl;
		}
	}

	cout << "Premi il numero della " << categoria << " scelta" << endl;
	char carattereLettoDaTastiera = _getch(); // scelta 
	if (carattereLettoDaTastiera == 'r') {
		cout << endl;
		regoleDelPG(); // funzione che stampa e basta
	}
	cout << endl;
	return carattereLettoDaTastiera;
}

char staisticheDaAumentare() {

	string statistiche[6] = {
		"Forza",
		"Destrezza",
		"Costituzione",
		"Intelligenza",
		"Saggezza",
		"Carisma" };

	char carattereLettoDaTastiera;

	for (int i = 0; i < 6; i++) {
		cout << i + 1 << ")--> " << statistiche[i] << endl;
	}

	cout << endl << "ora scelgi cosa aumentare." << endl
		<< "Per secegliere basta che premi il numro della statistica corrispondente" << endl;
	carattereLettoDaTastiera = _getch(); // scelta
	cout << endl;
	return carattereLettoDaTastiera;
}

void creazionePG() {

	// creazione nome
	string nomePG;
	char sicurezzaNellaDecisioneDelNomeDelPG = 1;
	do {
		cout << "Partiamo con il dare un nome al tuo PG" << endl
			<< "N.B. deve essere senza spazi." << endl
			<< "Quando hai finito di scrivere il nome premi invio" << endl;
		cin >> nomePG;
		cout << endl << "Bene dunque questo sara' il nome del tuo PG: ";
		cout << nomePG;
		cout << endl << "sei sicuro di questo nome?" << endl
			<< "Si=1 No=0" << endl;
		sicurezzaNellaDecisioneDelNomeDelPG = _getch();
		cout << endl;
	} while (sicurezzaNellaDecisioneDelNomeDelPG != '1');


	// scelta della classe
	bool haiSceltoUnaClasseORazzaNonValida;
	string classi[8] = {
		"Barbaro",
		"Guerriero",
		"Monaco",
		"Paladino",
		"Ranger",
		"Ladro",
		"Stregone",
		"Mago" };
	string classe = "classe";
	string classeScelta;
	char classeCheSceglie;
	char sicurezzaSceltaClasse = 0;

	/* Con if in cascata potrei far scrivere all' utente direttamente la classe
	   perche' switch-case prende solo valori interi
	   (if in cascata con controlli dei char)
	   ma probabilmente appesentirebbe molto il programma */
	do {
		stampareLeClassiOLeRegole = false;
		do {
			haiSceltoUnaClasseORazzaNonValida = false;
			cout << "Ora dobbiamo scegliere una classe fra le seguenti." << endl
				<< "se vuoi vedere i diversi modificatori di statistica di ogni razza" << endl
				<< "premi r (deve essere in minuscolo)" << endl
				<< "Classi:" << endl;
			classeCheSceglie = menuDellaClasseORazza(classe);
		} while (classeCheSceglie == 'r');

		if (classeCheSceglie >= '1' && classeCheSceglie <= '8') {
			classeScelta = classi[classeCheSceglie - 49];
		}
		else {
			system("CLS");
			haiSceltoUnaClasseORazzaNonValida = true;
			std::cout << "scelta non valida" << endl << endl;
		}

		if (haiSceltoUnaClasseORazzaNonValida == false) {
			cout << "Bene dunque tu sarai un " << classeScelta << endl
				<< "Sei sicuro?" << endl
				<< "Si=1 No=0" << endl;
			sicurezzaSceltaClasse = _getch();
			cout << endl;
		}
	} while (sicurezzaSceltaClasse != '1');
	stampareLeClassiOLeRegole = true;


	// scelta della razza
	string razze[7] = {
		"Nano",
		"Elfo",
		"Gnomo",
		"Mezzelfo",
		"Mezzorco",
		"Halfling",
		"Umano" };
	string razza = "razza";
	string razzaScelta;
	char razzaCheSceglie;
	char sicurezzaSceltaRazza = 0;

	/* Con if in cascata potrei far scrivere all' utente direttamente la razza
	   perche' switch-case prende solo valori interi
	   (if in cascata con controlli dei char)
	   ma probabilmente appesentirebbe molto il programma */
	do {

		do {
			haiSceltoUnaClasseORazzaNonValida = false;
			cout << "Ora dobbiamo scegliere una razza fra le seguenti." << endl
				<< "Le razze andranno a modificare le statistiche;" << endl
				<< "Valuta attentamente quale razza scegliere" << endl
				<< "se vuoi vedere i modificatori di statistica di ogni razza" << endl
				<< "premi r (deve essere in minuscolo)" << endl
				<< "Razze:" << endl;
			razzaCheSceglie = menuDellaClasseORazza(classe);
		} while (razzaCheSceglie == 'r');

		if (razzaCheSceglie >= '1' && razzaCheSceglie <= '7') {
			razzaScelta = razze[razzaCheSceglie - 49];
		}
		else {
			system("CLS");
			haiSceltoUnaClasseORazzaNonValida = true;
			std::cout << "scelta non valida" << endl << endl;
		}

		if (haiSceltoUnaClasseORazzaNonValida == false) {
			cout << "Bene dunque tu sarai un " << razzaScelta << endl
				<< "Sei sicuro?" << endl
				<< "Si=1 No=0" << endl;
			sicurezzaSceltaRazza = _getch();
			cout << endl;
		}
	} while (sicurezzaSceltaRazza != '1');


	// calcolo statistiche
	string forza = "Forza";
	string destrezza = "Destrezza";
	string costituzione = "Costituzione";
	string intelligenza = "Intelligenza";
	string saggezza = "Saggezza";
	string carisma = "Carisma";
	bool haiSceltoUnaStatisticaNonValida = false;
	int calcoloStatistiche[4] = { 0 };
	int sommaPerIlCalcoloDelleStatistiche = 0;
	char aumentoStatistiche;
	string statisticaCheSceglieDiAumentare;
	char condizioneDelCicloPerLAumentoStatistiche;
	system("CLS");
	cout << "Sei giunto nella parte piu' facile' della creazione di un PG;" << endl
		<< "Per capire come il programma calcoli le tue statistiche, puoi premere r ed accedere alla sezione 'Regole per creare un PG'" << endl
		<< "Se non ti fidi del generatore di numeri, puoi testarlo nel men? principale, ma solo al termine dell'attuale sessione di gioco." << endl
		<< "Bene dopo questo lungo discorso puoi vedere le tue statistiche." << endl
		<< "N.B. I tuoi valori andranno da un minimo di 10 in su, " << endl
		<< "ma ti avviso che le caratteristiche della razza del tuo personaggio potrebbero portarli al di sotto del 10." << endl << endl;

	for (int i = 0; i < 6; i++) {
		do {

			for (int i2 = 0; i2 < 4; i2++) {
				calcoloStatistiche[i2] = lanciaDado(6);
			}

			sommaPerIlCalcoloDelleStatistiche = calcoloStatistiche[0] + calcoloStatistiche[1] + calcoloStatistiche[2] + calcoloStatistiche[3];
			statistichePG[i] = sommaPerIlCalcoloDelleStatistiche;
			if (i == 2 && statistichePG[i] > 20) {
				statistichePG[i] = 20;
			}
		} while (statistichePG[i] < 10);
	}

	switch (razzaCheSceglie) {
	case '1':
		statistichePG[0] + 2;
		statistichePG[4] + 2;
		statistichePG[5] - 2;
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '2':
		statistichePG[1] + 2;
		statistichePG[0] - 2;
		statistichePG[3] + 2;
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '3':
		statistichePG[0] - 2;
		statistichePG[1] + 2;
		statistichePG[5] + 2;
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '4':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			cout << "visto che hai deciso di essere un Mezzelfo," << endl
				<< "puoi scegliere che statistica aumentare di 2 punti." << endl
				<< "queste sono le statistiche attuali." << endl
				<< "Statistiche:" << endl << endl;
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					cout << "Hai la costituzuione gia' al massimo, non puoi aumentarla ulteriormente." << endl
						<< "Premi un tasto per continuare." << endl;
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				std::cout << "scelta non valida" << endl << endl;
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				cout << "Hai scelto di potenziare " << statisticaCheSceglieDiAumentare << endl
					<< "sei sicuro?" << endl
					<< "Si=1 No=0" << endl;
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '5':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			cout << "visto che hai deciso di essere un Mezzorco," << endl
				<< "puoi scegliere che statistica aumentare di 2 punti." << endl
				<< "queste sono le statistiche attuali." << endl
				<< "Statistiche:" << endl << endl;
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					cout << "Hai la costituzuione gia' al massimo, non puoi aumentarla ulteriormente." << endl
						<< "Premi un tasto per continuare." << endl;
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				std::cout << "scelta non valida" << endl << endl;
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				cout << "Hai scelto di potenziare " << statisticaCheSceglieDiAumentare << endl
					<< "sei sicuro?" << endl
					<< "Si=1 No=0" << endl;
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');

		statistichePG[5] - 2;
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '6':
		statistichePG[0] - 2;
		statistichePG[1] + 2;
		statistichePG[5] + 2;
		cout << "Alla fine le tue statistiche sono:" << endl;
		break;

	case '7':
		do {
			haiSceltoUnaStatisticaNonValida = false;
			cout << "visto che hai deciso di essere un Umano," << endl
				<< "puoi scegliere che statistica aumentare di 2 punti." << endl
				<< "queste sono le statistiche attuali." << endl
				<< "Statistiche:" << endl << endl;
			aumentoStatistiche = staisticheDaAumentare();

			switch (aumentoStatistiche) {
			case '1':
				statistichePG[0] = statistichePG[0] + 2;
				statisticaCheSceglieDiAumentare = forza;
				break;

			case '2':
				statistichePG[1] = statistichePG[1] + 2;
				statisticaCheSceglieDiAumentare = destrezza;
				break;

			case '3':
				if (statistichePG[2] == 20) {
					haiSceltoUnaStatisticaNonValida = true;
					cout << "Hai la costituzuione gia' al massimo, non puoi aumentarla ulteriormente." << endl
						<< "Premi un tasto per continuare." << endl;
					fermaCout = _getch();
				}
				else {
					statisticaCheSceglieDiAumentare = costituzione;
					if (statistichePG[2] == 19) {
						statistichePG[2]++;
					}
					else {
						statistichePG[2] = statistichePG[2] + 2;
					}
				}
				break;

			case '4':
				statistichePG[3] = statistichePG[3] + 2;
				statisticaCheSceglieDiAumentare = intelligenza;
				break;

			case '5':
				statistichePG[4] = statistichePG[4] + 2;
				statisticaCheSceglieDiAumentare = saggezza;
				break;

			case '6':
				statistichePG[5] = statistichePG[5] + 2;
				statisticaCheSceglieDiAumentare = carisma;
				break;

			default:
				haiSceltoUnaStatisticaNonValida = true;
				system("CLS");
				std::cout << "scelta non valida" << endl << endl;
				break;
			}

			if (haiSceltoUnaStatisticaNonValida == false) {

				cout << "Hai scelto di potenziare " << statisticaCheSceglieDiAumentare << endl
					<< "sei sicuro?" << endl
					<< "Si=1 No=0" << endl;
				condizioneDelCicloPerLAumentoStatistiche = _getch();
			}
		} while (condizioneDelCicloPerLAumentoStatistiche != '1');
		cout << endl << "Alla fine le tue statistiche sono:" << endl;
		break;

	defoult:
		cout << "scelta non valida" << endl << endl;
		break;
	}

	if (godMod == true) {
		for (int i = 0; i < 6; i++) {
			statistichePG[i] = 100;
		}
	}

	cout << forza << ": " << statistichePG[0] << endl
		<< destrezza << ": " << statistichePG[1] << endl
		<< costituzione << ": " << statistichePG[2] << endl
		<< intelligenza << ": " << statistichePG[3] << endl
		<< saggezza << ": " << statistichePG[4] << endl
		<< carisma << ": " << statistichePG[5] << endl << endl << endl;


	// assegnazione delle armi + assegnazione della vita
	int dannoArmiBase[8] = { 20, 18, 15, 18, 15, 15, 12, 13 };
	int vitaBase[8] = { 30, 32, 35, 32, 35, 35, 38, 37 };
	switch (classeCheSceglie) {
	case '1':
		dannoPG = dannoArmiBase[0] + statistichePG[0];
		vitaPG = vitaBase[0] + statistichePG[2];
		break;

	case '2':
		dannoPG = dannoArmiBase[1] + statistichePG[0];
		vitaPG = vitaBase[1] + statistichePG[2];
		break;

	case '3':
		dannoPG = dannoArmiBase[2] + statistichePG[0];
		vitaPG = vitaBase[2] + statistichePG[2];
		break;

	case '4':
		dannoPG = dannoArmiBase[3] + statistichePG[0];
		vitaPG = vitaBase[3] + statistichePG[2];
		break;

	case '5':
		dannoPG = dannoArmiBase[4] + statistichePG[1];
		vitaPG = vitaBase[4] + statistichePG[2];
		break;

	case '6':
		dannoPG = dannoArmiBase[5] + statistichePG[1];
		vitaPG = vitaBase[5] + statistichePG[2];
		break;

	case '7':
		dannoPG = dannoArmiBase[6] + statistichePG[3];
		vitaPG = vitaBase[6] + statistichePG[2];
		break;

	case '8':
		dannoPG = dannoArmiBase[7] + statistichePG[3];
		vitaPG = vitaBase[7] + statistichePG[2];
		break;

	default:
		break;
	}
	/*  Barbaro: Ascia 20 danni + for / 30 + cos
		Guerriero: Spada lunga 18 + for / 32 + cos
		Monaco: Pugni 15 + for / 35 + cos
		Paladino: Martello 18 + for / 32 + cos
		Ranger: Spada corta 15 + dex / 35 + cos
		Ladro: Pugnali 15 + dex / 35 + cos
		Stregone: Bastone magico 12 + int / 38 + cos
		Mago: Grimorio 13 + int / 37 + cos
	*/


}

int riduzioneDeiMostri(int vitaDeiMostri, int quantitaDeiMostri) {

	// da vedere se fare
	// bisogna studiarsela bene
	if (vitaDeiMostri < 250) {
		quantitaDeiMostri = 5;
		if (vitaDeiMostri < 201) {
			quantitaDeiMostri = 4;
			if (vitaDeiMostri < 151) {
				quantitaDeiMostri = 3;
				if (vitaDeiMostri < 101) {
					quantitaDeiMostri = 2;
					if (vitaDeiMostri < 51) {
						quantitaDeiMostri = 1;
						if (vitaDeiMostri <= 0) {
							quantitaDeiMostri = 0;
						}
					}
				}
			}
		}
	}
	/*
	jndjcnjbvnsbnvbnsdv
	*/

	return quantitaDeiMostri;
}

void aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale() {

	// variabili genrali
	bool finisceDiEsplorareLePorte;
	char chePortaDecideDiScegliere = 0;

	// variabili della 1? porta a sinistra (il cuoco)
	char mangiareONonMangiareDalCuoco = 0;
	bool primaVoltaCheentraDalCuoco = true;
	int vitaDelMiniBoss = 100;

	// variabili 3? porta a destra (goblin + donna da salvare)
	int quantitaGoblin = 5;
	int vitaDeiGoblin = quantitaGoblin * 50;
	int valoreBaseDellaVitaDeiMostri = 250;

	// variabili di combattimento
	char sceltaNelCobattimento = 0;
	int risultatoDalLancioDelDado = 0;
	int vitaTemporaneaDelPG = vitaPG;


	do {
		vuoleTornareAi2PortoniNelSaloneGrande = false;
		finisceDiEsplorareLePorte = false;
		system("CLS");
		cout << "Devi decidere quale porta provare ad aprire." << endl
			<< "Puoi scegliere una delle seguenti porte" << endl
			<< "--> 1) 1^ porta a sinistra" << endl
			<< "--> 2) 2^ porta a sinistra" << endl
			<< "--> 3) 3^ porta a sinistra" << endl << endl

			<< "--> 4) 1^ porta a destra" << endl
			<< "--> 5) 2^ porta a destsra" << endl
			<< "--> 6) 3^ porta a destra" << endl << endl

			<< "--> 7) Torna indietro" << endl;
		chePortaDecideDiScegliere = _getch();
		switch (chePortaDecideDiScegliere) {
		case '1':
			if (primaVoltaCheentraDalCuoco == true) {
				primaVoltaCheentraDalCuoco = false;
				do {
					cout << endl << "Entri e vedi una sala da pranzo, con un tavolo imbandito di cibo appetitoso e un odore dolciastro che si spande per tutta la stanza." << endl
						<< "All'improvviso, spunta un anziano cuoco. 'Non pensavo di ricevere visite... Che fai qui?' chiede," << endl
						<< "per poi affermare, senza darti il tempo di rispondere: 'Beh, non importa, accomodati pure.' Ti fa un cenno con la mano, sedendosi a capotavola." << endl
						<< "Senza rendertene conto, ti trovi seduto al tavolo. 'Forza, mangia pure.', ti dice." << endl
						<< "--> 1) Mangi" << endl
						<< "--> 2) Non mangi" << endl;
					mangiareONonMangiareDalCuoco = _getch();
					switch (mangiareONonMangiareDalCuoco) {
					case '1':
						// finale 2
						finisceDiEsplorareLePorte = true;
						morteDellaDonnaCheUrla = true;
						fineDellaStoriaDelGrandeSalone = true;
						system("CLS");
						cout << "GAME OVER, senti le forze abbandonarti e subito ti ritrovi accasciato sul tavolo, morto." << endl
							<< "Finale 2 di 8" << endl
							<< "Premi un tasto qualunque per continuare" << endl;
						fermaCout = _getch();
						break;

					case '2':
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
								}
								else {
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
									}
									else {
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
								}
								else {
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
									}
									else {
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
											}
											else {
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
						system("CLS");
						if (vitaTemporaneaDelPG <= 0) {
							finisceDiEsplorareLePorte = true;
							morteDellaDonnaCheUrla = true;
							fineDellaStoriaDelGrandeSalone = true;
							cout << "GAME OVER, senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
								<< "Finale 3 di 8" << endl
								<< "Premi un tasto qualunque per continuare" << endl;
							fermaCout = _getch();
						}
						else {
							chiaveDelCuoco = true;
							cout << "Sei riuscito ad uccidere il cuoco." << endl
								<< "Cadi a terra stremato, ma cio' nonostante noti qualcosa di strano nelle tasche de cuoco," << endl
								<< "ti avvicini e noti che c'e' una chiave; nel dubbio decidi di prenderla." << endl
								<< "Premi un tasto qualunque per continuare" << endl;
							fermaCout = _getch();
						}
						break;

					default:
						system("CLS");
						cout << "scelta non valida" << endl << endl;
						break;
					}
				} while (mangiareONonMangiareDalCuoco != '1' && mangiareONonMangiareDalCuoco != '2');
			}
			else {
				system("CLS");
				cout << "Entri e vedi ancora il cuoco disteso, vicino al tavolo, morto." << endl
					<< "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
			}
			break;

		case '2':
			contatoreDelleAzioni++;
			system("CLS");
			cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
			break;

		case '3':
			contatoreDelleAzioni++;
			system("CLS");
			cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
			break;

		case '4':
			contatoreDelleAzioni++;
			system("CLS");
			cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
			break;

		case '5':
			contatoreDelleAzioni++;
			system("CLS");
			cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
				<< "Premi un tasto qualunque per continuare" << endl;
			fermaCout = _getch();
			break;

		case '6':
			if (chiaveArruginita == true || godMod == true) {
				if (contatoreDelleAzioni >= 30) {
					finisceDiEsplorareLePorte = true;
					morteDellaDonnaCheUrla = true;
					fineDellaStoriaDelGrandeSalone = true;
					system("CLS");
					cout << "GAME OVER, vedi la donna che dovevi salvare smenbrata." << endl
						<< "In quel momento la casa inizia a crollare e tu rimani bloccato al suo interno." << endl
						<< "Resisti per qualche girono, per poi morire di inedia." << endl// non sapevo come terminare
						<< "Finale 5 di 8" << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
				}
				else {
					if (morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == true) {
						finisceDiEsplorareLePorte = true;
						morteDellaDonnaCheUrla = true;
						fineDellaStoriaDelGrandeSalone = true;
						system("CLS");
						cout << "GAME OVER, vedi la donna che dovevi salvare smenbrata." << endl
							<< "In quel momento la casa inizia a crollare e tu rimani bloccato al suo interno." << endl
							<< "Resisti per qualche girono, per poi morire di inedia." << endl// non sapevo come terminare
							<< "Finale 1 di 8" << endl
							<< "Premi un tasto qualunque per continuare" << endl;
						fermaCout = _getch();
					}
					else {
						// combattimento
						vitaTemporaneaDelPG = vitaPG;
						system("CLS");
						cout << "Entri nella stanza." << endl // probabilmente da modificare
							<< "Vedi in fondo la donna da salvare circondata da 5 goblin." << endl
							<< "Essi, dopo averti visto, iniziano a caricare per attaccarti." << endl;
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
									vitaDeiGoblin = vitaDeiGoblin - dannoPG;
									quantitaGoblin = riduzioneDeiMostri(vitaDeiGoblin, quantitaGoblin);
									cout << endl << "Hai colpito 1 dei goblin." << endl
										<< "Gli rimangono " << vitaDeiGoblin << " di vita." << endl
										<< "Premi un tasto per continuare" << endl;
									fermaCout = _getch();
									cout << endl;
								}
								else {
									cout << endl << "Hai provato ad attaccarne 1 ma con uno scatto e' riuscito a schivarti." << endl
										<< "E ora ti stanno per attaccare." << endl
										<< "Premi un tasto per continuare" << endl;
									fermaCout = _getch();
									cout << endl;
								}

								// attacco dei goblin
								if (vitaDeiGoblin > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									for (int i = quantitaGoblin; i != 0; i--) {
										risultatoDalLancioDelDado = lanciaDado(20);
										if (risultatoDalLancioDelDado >= statistichePG[2]) {
											vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
											cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
												<< "ed in quel momento 1 goblin e' riuscito ad attaccarti." << endl
												<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
												<< "Premi un tasto per continuare" << endl;
											fermaCout = _getch();
											cout << endl;
										}
										else {
											cout << endl << "1 Goblin ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
												<< "Premi un tasto per continuare" << endl;
											fermaCout = _getch();
											cout << endl;
										}
										if (vitaTemporaneaDelPG <= 0) {
											i = 1;
											finisceDiEsplorareLePorte = true;
											morteDellaDonnaCheUrla = true;
											fineDellaStoriaDelGrandeSalone = true;
											system("CLS");
											cout << "GAME OVER, vedi la donna che viene attaccata dai goblin." << endl
												<< "Senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
												<< "Finale 6 di 8" << endl
												<< "Premi un tasto qualunque per continuare" << endl;
											fermaCout = _getch();
										}
									}
								}
								break;

							case '2':
								// attacco dei goblin
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								for (int i = quantitaGoblin; i != 0; i--) {
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= statistichePG[2]) {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
										cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
											<< "ed in quel momento 1 di loro e' riuscito ad attaccarti." << endl
											<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
										cout << endl;
									}
									else {
										cout << endl << "1 Goblin ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
										cout << endl;
									}
									if (vitaTemporaneaDelPG <= 0) {
										i = 1;
										finisceDiEsplorareLePorte = true;
										morteDellaDonnaCheUrla = true;
										fineDellaStoriaDelGrandeSalone = true;
										system("CLS");
										cout << "GAME OVER, vedi la donna che viene attaccata dai goblin." << endl
											<< "senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
											<< "Finale 6 di 8" << endl
											<< "Premi un tasto qualunque per continuare" << endl;
										fermaCout = _getch();
									}
								}

								// attacco del PG
								if (vitaTemporaneaDelPG > 0) {
									contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
									cout << endl << "(urlo di attacco)(tipo arrrrrrrgh)" << endl
										<< "(Immaginatelo)" << endl;
									risultatoDalLancioDelDado = lanciaDado(20);
									if (risultatoDalLancioDelDado >= 13) {
										vitaDeiGoblin = vitaDeiGoblin - (dannoPG + 5);
										quantitaGoblin = riduzioneDeiMostri(vitaDeiGoblin, quantitaGoblin);
										cout << endl << "Hai colpito 1 dei goblin." << endl
											<< "Gli rimangono " << vitaDeiGoblin << " di vita." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
										cout << endl;
									}
									else {
										cout << endl << "Hai provato ad attaccarne 1 ma con uno scatto e' riuscito a schivarti." << endl
											<< "E ora ti stanno per attaccare." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
										cout << endl;
									}

									// 2? attacco dei goblin
									if (vitaDeiGoblin > 0) {
										contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
										for (int i = quantitaGoblin; i != 0; i--) {
											risultatoDalLancioDelDado = lanciaDado(20);
											if (risultatoDalLancioDelDado >= statistichePG[2]) {
												vitaTemporaneaDelPG = vitaTemporaneaDelPG - 7;
												cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
													<< "ed in quel momento 1 di loro e' riuscito ad attaccarti." << endl
													<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
													<< "Premi un tasto per continuare" << endl;
												fermaCout = _getch();
												cout << endl;
											}
											else {
												cout << endl << "1 Goblin ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
													<< "Premi un tasto per continuare" << endl;
												fermaCout = _getch();
												cout << endl;
											}
											if (vitaTemporaneaDelPG <= 0) {
												i = 1;
												finisceDiEsplorareLePorte = true;
												morteDellaDonnaCheUrla = true;
												fineDellaStoriaDelGrandeSalone = true;
												system("CLS");
												cout << "GAME OVER, vedi la donna che viene attaccata dai goblin." << endl
													<< "senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
													<< "Finale 6 di 8" << endl
													<< "Premi un tasto qualunque per continuare" << endl;
												fermaCout = _getch();
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
						} while (vitaDeiGoblin > 0 && vitaTemporaneaDelPG > 0);
						if (vitaDeiGoblin <= 0 && vitaTemporaneaDelPG > 0) {
							finisceDiEsplorareLePorte = true;
							morteDellaDonnaCheUrla = true;
							fineDellaStoriaDelGrandeSalone = true;
							system("CLS");
							cout << "Hai vinto, salvi la donna." << endl
								<< "Insieme riuscite ad uscire dalla casa che sta crollando indenni." << endl
								<< "Lei si innamora di te e tu ricambi." << endl
								<< "Lasci la tua gilda per sposarla." << endl
								<< "La sua famiglia non ? molto d'accordo a causa del tuo passato, ma non ostacola l'unione." << endl
								<< "Tua suocera si trasferisce da voi e continua a mancarti di rispetto e maltrattarti." << endl
								<< "In un raptus di rabbia, la uccidi; tua moglie prova invano a fermarti." << endl
								<< "Terrorizzata, ti prega di non uccidere anche lei." << endl;
							do {
								cout << "--> 1) uccidila" << endl
									<< "--> 2) non ucciderla" << endl;
								fermaCout = _getch(); // uso fermaCout per non creare un' ulteriore variabile
							} while (fermaCout != '1' && fermaCout != '2');
							switch (fermaCout) {
							case '1':
								system("CLS");
								cout << "La uccidi e scappi." << endl
									<< "Provi a fare ritorno presso la tua gilda, ma ti accusano di essere un traditore e cercano di ucciderti." << endl
									<< "Riesci a fuggire e vivi il resto della tua vita come un vagabondo," << endl
									<< "tormentato dal rimorso per aver ucciso la donna che amavi." << endl
									<< "Finale 7 di 8" << endl
									<< "Premi un tasto qualunque per continuare" << endl;
								fermaCout = _getch();
								break;

							case '2':
								system("CLS");
								cout << "Non la uccidi." << endl
									<< "Continuate a vivere insieme, e dopo pochi mesi lei resta incinta di te." << endl
									<< "Lei per? ha ancora paura che tu possa farle del male, i rapporti sono tesi e litigate spesso." << endl
									<< "Decidi di abbandonarla a se stessa e per il resto della tua vita viaggerai per il mondo," << endl
									<< "rimpiangendo di aver lasciato lei e tuo figlio." << endl
									<< "Finale 8 di 8" << endl
									<< "Premi un tasto qualunque per continuare" << endl;
								fermaCout = _getch();
								break;

							default:
								system("CLS");
								cout << "scelta non valida" << endl << endl;
								break;
							}
						}
					}
				}
			}
			else {
				contatoreDelleAzioni++;
				system("CLS");
				cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
					<< "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
			}
			break;

		case '7':
			finisceDiEsplorareLePorte = true;
			break;

		default:
			cout << "scelta non valida" << endl << endl;
			break;
		}
	} while (finisceDiEsplorareLePorte != true);
}

void portaDiSinistraDelSalonePrincipale() {

	bool aperturaPortone1Volta = false;
	bool esceDallaPortaDiSinistraDelSalonePrincipale = false;
	bool ascoltaNellaPrimaScelta = false;
	bool esaminazioneDellePorte = false;
	bool morteDellaDonnaDopoAverSentitoLeUrla = false;
	char sceltaDellaPortaDiSinistraDelSalonePrincipale = '0';
	char decidereSeIndagareSeulleUrlaDellaDonna;
	bool indagareSulleUrlaDellaDonna = false;

	do {
		vuoleTornareAi2PortoniNelSaloneGrande = false;
		if (ascoltaNellaPrimaScelta == false && aperturaPortone1Volta == false) {
			system("CLS");
			aperturaPortone1Volta = true;
			cout << "Provi ad aprire il portone e a fatica ci riesci." << endl
				<< "Entri in un lungo corridoio." << endl
				<< "Il pavimento e' coperto da un tappeto rovinato, e noti tre porte alla tua destra e tre alla tua sinistra." << endl
				<< "Fai un respiro profondo, e senti un odore dolciastro che ti incuriosisce provenire da una delle porte." << endl
				<< "--> 1) Ascolta cosa ti succede intorno." << endl
				<< "--> 2) Indaga sull' odore dolciastro." << endl
				<< "--> 3) Prova ad aprire una delle porte." << endl
				<< "--> 4) Rifletti sulla vita." << endl // scelta quasi completamente inutile, ha una piccola sorpresa
				<< "--> 5) Torna indietro." << endl;
			sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
			switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
			case '1':
				contatoreDelleAzioni++;
				ascoltaNellaPrimaScelta = true;
				while (indagareSulleUrlaDellaDonna != true) {
					cout << endl << "Ascoltando con attenzione senti una donna piangere ed implorare di essere liberata," << endl
						<< "ma senti anche nella stessa direzione qualcuno ridacchiare." << endl
						<< "Vuoi indagare?" << endl
						<< "Si=1 No=0" << endl;
					decidereSeIndagareSeulleUrlaDellaDonna = _getch();
					switch (decidereSeIndagareSeulleUrlaDellaDonna) {
					case '1':
						contatoreDelleAzioni++;
						aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
						indagareSulleUrlaDellaDonna = true;
						break;
					case '0':
						indagareSulleUrlaDellaDonna = false;
						cout << endl;
						break;

					default:
						cout << "scelta non valida" << endl << endl;
						break;
					}
				}
				break;

			case '2':
				contatoreDelleAzioni++;
				cout << endl << "Inizi ad annusare l'aria cercando la fonte dell'odore, ma ben presto ti accorgi che si ? diffuso dappertutto." << endl
					<< "Decidi percio' di aprire una delle porte e indagare." << endl << endl;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
				break;

			case '3':
				contatoreDelleAzioni++;
				cout << endl << endl;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
				break;

			case '4':
				// finale 1
				morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
				cout << endl << "Ti siedi per terra, con la schiena appoggiata al muro." << endl
					<< "Dopo pochi minuti ti addormenti, e ti risvegli, intontito." << endl
					<< "Sembra siano passate delle ore, ma perlomeno ti senti piu' riposato." << endl;
				if (ascoltaNellaPrimaScelta == true) {
					morteDellaDonnaDopoAverSentitoLeUrla = true;
					cout << "Le urla della donna sono cessate, ma non te ne preoccupi." << endl;
				}
				cout << "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
				break;

			case '5':
				contatoreDelleAzioni++;
				vuoleTornareAi2PortoniNelSaloneGrande = true;
				break;
			default:
				system("CLS");
				cout << "scelta non valida" << endl << endl;
				break;
			}
		}
		else {
			system("CLS");
			if (ascoltaNellaPrimaScelta == false && morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == false) {
				cout << "--> 1) Ascolta cosa ti succede intorno." << endl
					<< "--> 2) Indaga sull' odore dolciastro." << endl
					<< "--> 3) Prova ad aprire una delle porte." << endl
					<< "--> 4) Rifletti sulla vita." << endl // scelta quasi completamente inutile ha una piccola sorpresa
					<< "--> 5) Torna indietro." << endl;
				sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
				switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
				case '1':
					contatoreDelleAzioni++;
					ascoltaNellaPrimaScelta = true;
					while (indagareSulleUrlaDellaDonna != true) {
						cout << endl << "Ascoltando con attenzione senti una donna piangere ed implorare di essere liberata," << endl
							<< "ma senti anche nella stessa drirezione qualcuno ridacchiare." << endl
							<< "Vuoi indagare?" << endl
							<< "Si=0 No=1" << endl;
						decidereSeIndagareSeulleUrlaDellaDonna = _getch();
						switch (decidereSeIndagareSeulleUrlaDellaDonna) {
						case '0':
							contatoreDelleAzioni++;
							aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
							indagareSulleUrlaDellaDonna = true;
							break;
						case '1':
							indagareSulleUrlaDellaDonna = true;
							cout << endl;
							break;

						default:
							cout << "scelta non valida" << endl << endl;
							break;
						}
					}
					break;

				case '2':
					contatoreDelleAzioni++;
					cout << endl << "Inizi ad annusare un po' dappertutto ma ben presto ti accorgi che l' odore e' ormai dappertutto," << endl
						<< "quindi decidi di provare ad aprire una porta per scoprire da dove proviene" << endl << endl;
					aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
					break;

				case '3':
					contatoreDelleAzioni++;
					cout << endl << endl;
					aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
					break;

				case '4':
					// finale 1
					morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
					cout << endl << "Ti siedi per terra, con la schiena appoggiata al muro." << endl
						<< "Dopo pochi minuti ti addormenti, e ti risvegli, intontito." << endl
						<< "Sembra siano passate delle ore, ma perlomeno ti senti piu' riposato." << endl;
					if (ascoltaNellaPrimaScelta == true) {
						morteDellaDonnaDopoAverSentitoLeUrla = true;
						cout << "Le urla della donna sono cessate, ma non te ne preoccupi." << endl;
					}
					cout << "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
					break;

				case '5':
					contatoreDelleAzioni++;
					vuoleTornareAi2PortoniNelSaloneGrande = true;
					break;
				default:
					system("CLS");
					cout << "scelta non valida" << endl << endl;
					break;
				}
			}
			else {
				system("CLS");
				if (morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita == false) {
					cout << endl
						<< "--> 1) Indaga sull' odore dolciastro." << endl
						<< "--> 2) Prova ad aprire una delle porte." << endl
						<< "--> 3) Rifletti sulla vita." << endl // scelta a sto punto quasi completamente inutile
						<< "--> 4) Torna indietro." << endl;
				}
				else {
					cout << "--> 1) Indaghi sull' odore dolciastro." << endl
						<< "--> 2) Prova ad aprire una delle porte." << endl
						<< "--> 3) Riposati." << endl // scelta a sto punto completamente inutile
						<< "--> 4) Torna indietro." << endl;
				}
			}

			sceltaDellaPortaDiSinistraDelSalonePrincipale = _getch();
			switch (sceltaDellaPortaDiSinistraDelSalonePrincipale) {
			case '1':
				contatoreDelleAzioni++;
				cout << endl << "Inizi ad annusare un po' dappertutto ma ben presto ti accorgi che l' odore e' ormai dappertutto," << endl
					<< "quindi decidi di provare ad aprire una porta per scoprire da dove proviene" << endl << endl;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
				break;

			case '2':
				contatoreDelleAzioni++;
				aperturaDiUnaDellePorteDellaPortaDiSinistraDelSalonePrincipale();
				break;

			case '3':
				// finale 1
				morteDellaDonnaCheUrlaDopoAverRiflettutoSullaVita = true;
				cout << endl << "Ti siedi per terra, con la schiena appoggiata al muro." << endl
					<< "Dopo pochi minuti ti addormenti, e ti risvegli, intontito." << endl
					<< "Sembra siano passate delle ore, ma perlomeno ti senti piu' riposato." << endl;
				if (ascoltaNellaPrimaScelta == true) {
					morteDellaDonnaDopoAverSentitoLeUrla = true;
					cout << "Le urla della donna sono cessate, ma non te ne preoccupi." << endl;
				}
				cout << "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
				break;

			case '4':
				contatoreDelleAzioni++;
				vuoleTornareAi2PortoniNelSaloneGrande = true;
				break;

			default:
				system("CLS");
				cout << "scelta non valida" << endl << endl;
				break;
			}
		}
	} while (morteDellaDonnaCheUrla != true && vuoleTornareAi2PortoniNelSaloneGrande != true);
}

bool labirintoDelleTreStanzeNelPortoneDiDestra(bool primaVoltaCheEntraNelLabirinto) {
	/*
	Ti titrovi in una stanza quadrata con tre porte una a destra una davanti e una a sinistra [Piccolo labirinto, dopo aver aperto la porta (una qualsiasi ci si ritrova in una stanza uguale per 3 volte alla terza se non si ? fatta la combinazione corretta (che ? dx -> dx -> avanti)) si ritorner? al salone principale]
	Ti ritrovi in una stanza circolare con un altare, sembrerebbe una chiesa ma al centro c'? un mostro enorme (boss)
	1? combinazione	((dx -> dx -> avanti)).
	2? combinazione	((avanti -> avanti -> sx)) */

	// quando esce dal ciclo deve ritornare che ? entrato nella stanza del boss
	char qualePortaSceglie = 0;
	int contatoreDiQuanteStanzeSceglieDuranteIlLavirinto = 0;
	int combinazione1 = 0;
	int combinazione2 = 0;
	bool entraNellaStanzaDelBoss = true;

	if (primaVoltaCheEntraNelLabirinto == true) {

		system("CLS");
		do {
			if (contatoreDiQuanteStanzeSceglieDuranteIlLavirinto != 3) {
				if (contatoreDiQuanteStanzeSceglieDuranteIlLavirinto != 2) {
					cout << endl << "Ti ritrovi in una stanza quadrata con Tre porte," << endl
						<< "una alla tua destra, una alla tua sinistra e una davanti a te." << endl
						<< "--> 1) Porta di sinistra" << endl
						<< "--> 2) Porta centrale" << endl
						<< "--> 3) Porta di destra" << endl;
					qualePortaSceglie = _getch();
					switch (qualePortaSceglie) {
					case '1':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						break;

					case '2':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione2++;
						break;

					case '3':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione1++;
						break;

					default:
						system("CLS");
						cout << "scelta non valida" << endl << endl;
						break;
					}
				}
				else {
					// terza scelta della porta
					cout << endl << "Ti ritrovi in una stanza quadrata con Tre porte," << endl
						<< "una alla tua destra, una alla tua sinistra e una davanti a te." << endl
						<< "--> 2) Porta centrale" << endl
						<< "--> 3) Porta di destra" << endl;
					qualePortaSceglie = _getch();
					switch (qualePortaSceglie) {
					case '1':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione2++;
						break;

					case '2':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						combinazione1++;
						break;

					case '3':
						contatoreDiQuanteStanzeSceglieDuranteIlLavirinto++;
						contatoreDelleAzioni++;
						break;

					default:
						system("CLS");
						cout << "scelta non valida" << endl << endl;
						break;
					}
				}
			}
			else {
				contatoreDiQuanteStanzeSceglieDuranteIlLavirinto = 0;
				combinazione1 = 0;
				combinazione2 = 0;
			}
		} while (combinazione1 != 3 && combinazione2 != 3);
	}

	return entraNellaStanzaDelBoss;
}

bool portaDiDestraDelSalonePrincipale(bool primaVoltaCheEntraDalBoss) {

	// variabili generali
	char vuoleAnalizzareLAltare = 0;
	bool stanzaDelBoss = false;
	bool personaggioMorto = false;

	// variabili di combattimento
	char sceltaNelCobattimento = 0;
	int risultatoDalLancioDelDado = 0;
	int vitaDelBoss = 200;
	int vitaTemporaneaDelPG = vitaPG;

	if (chiaveDelCuoco == true || godMod == true) {
		if (primaVoltaCheEntraDalBoss == true) {
			stanzaDelBoss = labirintoDelleTreStanzeNelPortoneDiDestra(primaVoltaCheEntraDalBoss);
			primaVoltaCheEntraDalBoss = false;
			// combattimento
			system("CLS");
			cout << "Esci da quello che sembra essere un labirinto." << endl
				<< "Subito ti trovi davanti un demone rosso con una grossa mannaia." << endl
				<< "Dopo qualche istante ti nota ed inizia subito a caricarti," << endl
				<< "devi decidere velocemnete cosa fare" << endl;
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
						vitaDelBoss = vitaDelBoss - dannoPG;
						cout << endl << "Hai colpito il Demone Rosso." << endl
							<< "Gli rimane " << vitaDelBoss << " di vita." << endl
							<< "Premi un tasto per continuare" << endl;
						fermaCout = _getch();
						cout << endl;
					}
					else {
						cout << endl << "Hai provato ad attaccarlo ma con uno scatto e' riuscito a schivarti." << endl
							<< "E ora ti sta per attaccare." << endl
							<< "Premi un tasto per continuare" << endl;
						fermaCout = _getch();
						cout << endl;
					}

					// attacco del Boss
					if (vitaDelBoss > 0) {
						contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
						risultatoDalLancioDelDado = lanciaDado(20);
						if (risultatoDalLancioDelDado >= statistichePG[2]) {
							if (vitaDelBoss > 50) {
								vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
								cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
									<< "ed in quel momento e' riuscito a colpirti." << endl
									<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
									<< "Premi un tasto per continuare" << endl;
								fermaCout = _getch();
							}
							else {
								vitaTemporaneaDelPG = vitaTemporaneaDelPG - 23;
								cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
									<< "ed in quel momento ti ha caricato provocandoti tanti danni." << endl
									<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
									<< "Premi un tasto per continuare" << endl;
								fermaCout = _getch();
							}
							cout << endl;
						}
						else {
							cout << endl << "Ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
								<< "Premi un tasto per continuare" << endl;
							fermaCout = _getch();
							cout << endl;
						}
					}
					break;

				case '2':
					// attacco del Boss
					contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
					risultatoDalLancioDelDado = lanciaDado(17);
					if (risultatoDalLancioDelDado >= statistichePG[2]) {
						vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
						cout << endl << "Provi a schivare il colpo" << endl
							<< "ma non ci riesci quindi ti colpisce." << endl
							<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
							<< "Premi un tasto per continuare" << endl;
						fermaCout = _getch();
						cout << endl;
					}
					else {
						cout << endl << "Ha provato ad attaccarti ma con uno scatto sei riuscito a schivarlo." << endl
							<< "Premi un tasto per continuare" << endl;
						fermaCout = _getch();
						cout << endl;
					}

					// attacco PG dopo la schivata
					if (vitaTemporaneaDelPG > 0) {
						contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
						cout << endl << "(urlo di attacco)(tipo arrrrrrrgh)" << endl
							<< "(Immaginatelo)" << endl;
						risultatoDalLancioDelDado = lanciaDado(20);
						if (risultatoDalLancioDelDado >= 10) {
							vitaDelBoss = vitaDelBoss - (dannoPG + 5);
							cout << endl << "Hai colpito il Demone Rosso." << endl
								<< "Gli rimane " << vitaDelBoss << " di vita." << endl
								<< "Premi un tasto per continuare" << endl;
							fermaCout = _getch();
							cout << endl;
						}
						else {
							cout << endl << "Hai provato ad attaccarlo ma con uno scatto e' riuscito a schivarti." << endl
								<< "E ora ti sta' per attaccare." << endl
								<< "Premi un tasto per continuare" << endl;
							fermaCout = _getch();
							cout << endl;

							// 2? attacco del Boss
							if (vitaDelBoss > 0) {
								contatoreDelleAzioni = contatoreDelleAzioni + 0.5;
								risultatoDalLancioDelDado = lanciaDado(25);
								if (risultatoDalLancioDelDado >= statistichePG[2]) {
									if (vitaDelBoss > 50) {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 15;
										cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
											<< "ed in quel momento e' riuscito a colpirti." << endl
											<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
									}
									else {
										vitaTemporaneaDelPG = vitaTemporaneaDelPG - 23;
										cout << endl << "Dopo aver attaccato sei rimasto immobile," << endl
											<< "ed in quel momento ti ha caricato provocandoti tanti danni." << endl
											<< "Ti rimane " << vitaTemporaneaDelPG << " di vita." << endl
											<< "Premi un tasto per continuare" << endl;
										fermaCout = _getch();
									}
									cout << endl;
								}
								else {
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
			} while (vitaTemporaneaDelPG >= 0 && vitaDelBoss > 0);
			system("CLS");
			if (vitaTemporaneaDelPG <= 0) {
				morteDellaDonnaCheUrla = true;
				fineDellaStoriaDelGrandeSalone = true;
				cout << "GAME OVER, senti le forze abbandonarti e subito ti ritrovi accasciato a terra, morto." << endl
					<< "Finale 4 di 8" << endl
					<< "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
			}
			else {
				system("CLS");
				do {
					cout << "Sei riuscito ad uccidere il Demone Rosso." << endl
						<< "Cadi a terra stremato, mentre davanti a te compare qualcosa di simile ad un altare." << endl
						<< "Vuoi avvicinarti per analizzarlo?" << endl
						<< "Si=1 No=0" << endl;
					vuoleAnalizzareLAltare = _getch();
				} while (vuoleAnalizzareLAltare != '1' && vuoleAnalizzareLAltare != '0');

				if (vuoleAnalizzareLAltare == '1') {
					haAnalizzatoLAtlare = true;
					chiaveArruginita = true;
					system("CLS");
					cout << "Ti avvicini in modo sospettoso." << endl
						<< "Una volta raggiunto lo osservi e ne noti la somiglianza con un altare di chiesa." << endl
						<< "Girandoci attorno, noti al centro, nel punto dove si posiziona solitamente il prete, una porticina" << endl
						<< "decidi di aprirla e dentro ci trovi una chiave arrugginita." << endl
						<< "All'inizio sei titubante all'idea di prenderla; poiche' non ti costa nulla, lo fai." << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
				}
				else {
					system("CLS");
					cout << "Te ne freghi, ti giri ed esci saltellando alla Heidi." << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
				}
			}
		}
		else {
			if (haAnalizzatoLAtlare == true) {
				system("CLS");
				cout << "Entri vedi il Demone Rosso morto e disteso li' per terra e l'altare con la porticina aperta." << endl
					<< "Non noti nulla di particolare quindi decidi di uscire saltellando alla Heidi." << endl
					<< "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
			}
			else {
				system("CLS");
				do {
					cout << "Vedi il Demone rosso morto e disteso li' perterra." << endl
						<< "C'e' ancora l'altare." << endl
						<< "Vuoi avvicinarti per analizzarlo?" << endl
						<< "Si=1 No=0" << endl;
					vuoleAnalizzareLAltare = _getch();
				} while (vuoleAnalizzareLAltare != '1' && vuoleAnalizzareLAltare != '0');

				if (vuoleAnalizzareLAltare == '1') {
					haAnalizzatoLAtlare = true;
					chiaveArruginita = true;
					system("CLS");
					cout << "Ti avvicini in modo sospettoso." << endl
						<< "Una volta raggiunto lo osservi e ne noti la somiglianza con un altare di chiesa." << endl
						<< "Girandoci attorno, noti al centro, nel punto dove solitamente si mette il prete, una porticina" << endl
						<< "decidi di aprirla e dentro ci trovi una chiave arrugginita." << endl
						<< "All'inizio sei titubante all'idea di prenderla; poiche' non ti costa nulla, lo fai." << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
				}
				else {
					system("CLS");
					cout << "Te ne freghi, ti giri ed esci saltellando alla Heidi." << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
				}
			}
		}
	}
	else {
		cout << endl << "Provi a spingere e a tirare ma non si apre quindi ci rinunci." << endl
			<< "Probablmente serve una chiave" << endl
			<< "Premi un tasto qualunque per continuare" << endl;
		fermaCout = _getch();
	}
	vuoleTornareAi2PortoniNelSaloneGrande = true;
	return primaVoltaCheEntraDalBoss;
}

void inizioStoria() {

	bool inizioAvventura = false; //effettivamente non serve a nulla e' solo per cercare di rendere le cose un po' piu' divertenti ed interessanti
	char sceltaDellInizioAvventura; // anche questa variebile e' totalmete inutile ma creata per lo stecco discorso della precedente
	while (inizioAvventura != true) {
		cout << "Finalmente siamo giunti all' effettivo inizio della avventura." << endl
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
	}
	system("CLS");

	// inizio della storia
	bool esaminazioneDellePorte = false;
	bool primaVoltaCheEntraNelPortoneDiDestra = true;
	char sceltaDellaPortaPrincipale = '0';
	do {
		if (esaminazioneDellePorte == false && vuoleTornareAi2PortoniNelSaloneGrande == false) {
			cout << "Sei un membro della gilda dei mercenari." << endl
				<< "Sei stato contattato da una famiglia nobiliare per investigare all'interno della magione di una loro ricca cugina, di cui non si hanno notizie da una settimana." << endl
				<< "Durante l'esplorazione della magione, ti imbatti in un ampio salone e decidi di entrarci." << endl
				<< "All'improvviso, alle tue spalle senti un forte tonfo. Ti volti e vedi la porta chiudersi." << endl
				<< "Decidi di continuare ad avanzare, e noti due grandi portoni in fondo alla stanza, uno a destra e uno a sinistra." << endl
				<< "--> 1) Avvicinati per esaminare le porte." << endl
				<< "--> 2) Prova ad entrare nel portone di sinistra." << endl
				<< "--> 3) Prova ad entrare nel portone di destra." << endl;
			sceltaDellaPortaPrincipale = _getch();
			switch (sceltaDellaPortaPrincipale) {
			case '1':
				contatoreDelleAzioni++;
				cout << endl << "Sono entrambi di un legno solido." << endl
					<< "Quello di destra sembra essere chiusa a chiave." << endl
					<< "Premi un tasto qualunque per continuare" << endl;
				fermaCout = _getch();
				esaminazioneDellePorte = true;
				break;

			case '2':
				contatoreDelleAzioni++;
				portaDiSinistraDelSalonePrincipale();
				break;

			case '3':
				contatoreDelleAzioni++;
				primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra);
				break;

			default:
				system("CLS");
				cout << "Scelta non valida" << endl;
				break;
			}
		}
		else {
			if (esaminazioneDellePorte == false) {
				system("CLS");
				cout << "--> 1) Avvicinati per esaminare le porte." << endl
					<< "--> 2) Prova ad entrare nel portone di sinistra." << endl
					<< "--> 3) Prova ad entrare nel portone di destra." << endl;
				sceltaDellaPortaPrincipale = _getch();
				switch (sceltaDellaPortaPrincipale) {
				case '1':
					contatoreDelleAzioni++;
					cout << endl << "Sono entrambi di un legno solido." << endl
						<< "Quello di destra sembra essere chiusa a chiave." << endl
						<< "Premi un tasto qualunque per continuare" << endl;
					fermaCout = _getch();
					esaminazioneDellePorte = true;
					break;

				case '2':
					contatoreDelleAzioni++;
					portaDiSinistraDelSalonePrincipale();
					break;

				case '3':
					contatoreDelleAzioni++;
					primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra);
					break;

				default:
					system("CLS");
					cout << "Scelta non valida" << endl;
					break;
				}
			}
			else {
				system("CLS");
				cout << "--> 1) Prova ad entrare nel portone di sinistra." << endl
					<< "--> 2) Prova ad entrare nel portone di destra." << endl;
				sceltaDellaPortaPrincipale = _getch();
				switch (sceltaDellaPortaPrincipale) {
				case '1':
					contatoreDelleAzioni++;
					portaDiSinistraDelSalonePrincipale();
					break;

				case '2':
					contatoreDelleAzioni++;
					primaVoltaCheEntraNelPortoneDiDestra = portaDiDestraDelSalonePrincipale(primaVoltaCheEntraNelPortoneDiDestra);
					break;

				default:
					system("CLS");
					cout << "Scelta non valida" << endl << endl;
					break;
				}
			}
		}
	} while (fineDellaStoriaDelGrandeSalone != true);
}
