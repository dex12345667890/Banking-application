# Console Bank Systeem (C++)

## Overzicht

Dit project is een console-gebaseerd banksysteem geschreven in C++.

De applicatie laat gebruikers bankaccounts aanmaken, inloggen, geld storten en opnemen, saldo bekijken en transacties opslaan met behulp van bestanden.

Dit project is gemaakt om mijn kennis te verbeteren van:

- Objectgeoriënteerd Programmeren (OOP)
- Bestandsverwerking
- STL containers
- Inputvalidatie
- Programmastructuur in C++

---

# Functionaliteiten

## Account Systeem

- Accounts aanmaken
- Inloggen met ID en wachtwoord
- Uitloggen

## Bank Functionaliteiten

- Geld storten
- Geld opnemen
- Saldo bekijken
- Transactiegeschiedenis met datum en tijd

## Bestandsopslag

- Accounts worden opgeslagen in bestanden
- Transacties worden opgeslagen in bestanden
- Data wordt automatisch geladen bij het opnieuw starten van het programma

## Inputvalidatie

- Detectie van ongeldige invoer
- Voorkomt negatieve saldo’s
- Voorkomt ongeldige stortingen en opnames

---

# Gebruikte Technologieën

- C++
- STL (`std::vector`)
- Bestandsverwerking (`fstream`)
- Objectgeoriënteerd Programmeren (OOP)
- Console interface

---

# Objectgeoriënteerd Programmeren

Dit project gebruikt meerdere klassen.

## Bank

De Bank-klasse beheert alle accounts en verzorgt de bestandsopslag.

## Account

De Account-klasse vertegenwoordigt een bankaccount en beheert:

- Saldo
- Stortingen
- Opnames
- Transacties
- Wachtwoorden

## Transaction

De Transaction-klasse slaat informatie op over transacties:

- Type transactie
- Bedrag
- Datum en tijd

---

# Projectstructuur

```text
include/
│
├── Account.h
├── Bank.h
└── Transaction.h

src/
│
├── Account.cpp
├── Bank.cpp
├── Transaction.cpp
└── main.cpp
```

---

# Dataopslag

## Accounts

Accounts worden opgeslagen in:

```text
data/accounts.txt
```

## Transacties

Transacties worden opgeslagen in:

```text
data/transactions.txt
```

Hierdoor blijft de data behouden nadat het programma wordt afgesloten.

---

# Gebruik van STL

Het project gebruikt:

```cpp
std::vector
```

voor het opslaan van:

- Accounts
- Transacties

Dit voorkomt het gebruik van vaste arrays en maakt dynamische opslag mogelijk.

---

# Geheugenbeheer

Het programma gebruikt voornamelijk STL containers zoals `std::vector` om geheugen automatisch te beheren.

Dit helpt bij het voorkomen van:

- Memory leaks
- Problemen met handmatige geheugenallocatie

Pointers worden veilig gebruikt voor het afhandelen van ingelogde accounts.

---

# Voorbeeldmenu

```text
===== BANK =====
1. Account aanmaken
2. Inloggen
3. Accounts tonen
4. Afsluiten
```

Na het inloggen:

```text
===== ACCOUNT MENU =====
1. Geld storten
2. Geld opnemen
3. Saldo bekijken
4. Transacties bekijken
5. Uitloggen
```

---

# Voorbeeld van een Transactie

```text
Deposit | €50.00
Mon May 27 12:30:15 2026
```

---

# Leerdoelen

## 1. Objectgeoriënteerd Programmeren

- Klassen gebruiken
- Encapsulation toepassen
- Constructors gebruiken
- Methoden implementeren
- Werken met meerdere source- en headerbestanden

## 2. Bestandsverwerking

- Lezen van bestanden
- Schrijven naar bestanden
- Permanente opslag van gegevens

## 3. STL en Geheugenbeheer

- Gebruik van `std::vector`
- Dynamische opslag
- Begrijpen hoe geheugenbeheer werkt in C++

---

# Compileren

Met MinGW / g++:

```bash
g++ src/*.cpp -Iinclude -o bankapp
```

Programma starten:

```bash
./bankapp
```

---

# Mogelijke Toekomstige Verbeteringen

- Geld overmaken tussen accounts
- Admin systeem
- Betere wachtwoordbeveiliging
- Opslag in CSV of JSON
- Verbeterde console interface
- Zoekfunctionaliteit