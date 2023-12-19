# Cerințe Proiect "Gestionarea Vehiculelor"

## Tipul de Date Vehicul
Un vehicul este definit ca având o marcă, o suprafață de rulare și o putere, după cum urmează:
```
enum SuprafataRulare {
    terestra, acvatica, aeriana, spatiala
};

struct Vehicul {
    char *marca; // e.g., ”Renault”
    SuprafataRulare s; // 0,1,2 sau 3
    unsigned int putere; // ex: 100, 120, maxim 200
};
```

# Cerințe
## 1. Citirea Datelor Vehicul
Implementați o funcție care citește date de la tastatură pentru un vehicul.

## 2. Afișarea Datelor Vehicul
Implementați o funcție care afișează datele unui vehicul.

## 3. Setarea Mărcii Vehiculului
Implementați o funcție care permite setarea mărcii unui vehicul.

## 4. Setarea Puterii Vehiculului
Implementați o funcție care permite setarea puterii unui vehicul.

## 5. Setarea Suprafeței de Rulare
Implementați o funcție care permite setarea suprafeței de rulare pentru un vehicul.

## 6. Crearea și Citirea unui Vector de Vehicule
Creați un vector în care stocați n vehicule (n citit de la tastatură, vectorul alocat dinamic). Citiți date pentru vectorul de vehicule cu funcția de la pct 1.

## 7. Sortarea și Afișarea Vehiculelor după Marcă
Sortați vectorul în funcție de marcă. Afișați-l folosindu-vă de funcția de la pct 2.

## 8. Afișarea Vehiculelor Aeriane cu Putere < 100
Afișați toate vehiculele care rulează pe suprafață aeriană și care au puterea mai mică de 100 de cai putere.

## 9. Modificarea Puterii Vehiculelor Acvatice
Modificați toate puterile vehiculelor, care rulează pe suprafață acvatică, scăzând 20% din putere.

## 10. Crearea unui Vector Nou pentru Vehiculele Terestre
Creați un vector nou: vector_spatiu, care să conțină toate vehiculele ce rulează pe suprafață terestră din vectorul inițial. Ce funcție ar trebui implementată de voi? Vă puteți folosi de funcțiile implementate la 3, 4, 5?
