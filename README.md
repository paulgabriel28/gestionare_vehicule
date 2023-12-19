# Descrierea Proiectului "Gestionarea Vehiculelor"

## Descriere Generală
Acest proiect este un sistem de gestionare a vehiculelor care permite utilizatorilor să stocheze și să manipuleze informații despre diferite tipuri de vehicule. Programul este scris în C++ și oferă funcționalități precum introducerea datelor vehiculului, afișarea informațiilor, sortarea și filtrarea bazată pe anumite criterii.

## Detalii Implementare
- **Structura Vehicul**: Reprezintă un vehicul și conține marca, tipul suprafeței de rulare (terestră, acvatică, aeriană, spațială) și puterea.
- **Funcții Principale**:
  - `citeste_vehicul()`: Permite citirea informațiilor unui vehicul de la utilizator.
  - `afisare_vehicul()`: Afișează informațiile unui vehicul.
  - `set_marca()`, `set_putere()`, `set_suprafata()`: Permite modificarea mărcii, puterii și suprafeței de rulare a unui vehicul.
  - `copiaza_vehicul()`: Copiază informațiile de la un vehicul la altul.
  - `suprafata_text()`: Returnează reprezentarea text a tipului suprafeței de rulare.

## Instrucțiuni de Utilizare
1. **Introducerea datelor**: La început, programul solicită numărul de vehicule, după care permite utilizatorului să introducă date pentru fiecare vehicul.
2. **Sortarea și Afișarea Vehiculelor**: După introducerea datelor, programul sortează vehiculele în funcție de marca lor și le afișează.
3. **Filtrare**: Utilizatorul poate vedea vehiculele care rulează pe suprafața aeriană și au putere mai mică de 100 de cai putere.
4. **Modificarea Puterii**: Programul permite modificarea puterii vehiculelor care rulează pe suprafața aeriană.
5. **Gestionarea Vehiculelor Terestre**: Programul creează un vector separat pentru vehiculele terestre și le afișează.
