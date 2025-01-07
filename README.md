### Pena Andrei-Alexandru
### C.R. 2.3A

<h1 align="center">Planificare proiect P.O.O. 2024-2025</h1>
<h1 align="center">Conturi bancare</h1>


Gestionarea conturilor se va face folosind un număr de cont `unic` și a unei parole, alocate fiecărui client. 

Tipuri de carduri disponibile: carduri de `credit` și `debit`.

- ##### Carduri de `debit`: suma este deja deținută de proprietarul contului.

- ##### Carduri de `credit`: la retrageri o să fie aplicat un comision de 2%, întreaga sumă va trebui achitată în maxim 6 luni (există o limită de 1.000.000 de lei).

 - ##### `Depozit` cu dobândă fixă: posibilitatea de a depune bani pentru obținerea unei dobânzi anuale de 5%. Depunerea se va face din contul de debit, iar returnarea dobânzii se va face, de asemenea, tot în contul de debit.

#### **Meniul principal:**
1.	Log-in în cont folosind numărul unic de cont
2.	Înregistrare client nou
3.	Administrator (afișare listă clienți, este necesară o parolă)
4.	Închidere program
   
#### **Meniu client:**
1.	Cont debit (interogare sold / depunere / retragere / închidere)
2.	Cont credit (interogare sumă datorată / retragere / depunere / meniu dată / închidere)
3.	Depozit cu dobândă fixă (depunere / meniu dată)
4.	Deschidere cont de tip **debit** (în cazul în care nu există)
5.	Deschidere cont de tip **credit** (în cazul în care nu există)
6.	Închidere cont
7.	Ieșire în meniul principal

#### **Informațiile fiecărui client:**
1.	Nume
2.	Prenume
3.	Număr cont
4.	Parolă
5.	Detalii cont debit (dacă există, ce sumă deține clientul)
6.	Detalii cont credit (dacă există, ce sumă datorează clientul)
7.	Detalii depozit cu dobândă fixă (dacă există, ce sumă a depus clientul)
   
Toate detaliile vor fi **salvate** într-un fișier .txt, astfel că toate detaliile (conturi, sume, etc.) vor fi salvate pentru folosirea ulterioară a programului.

Se folosesc 4 clase: cont, client, administrator și bancă. 
