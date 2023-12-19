#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

enum SuprafataRulare {
    terestra, acvatica, aeriana, spatiala
};

struct Vehicul {
    char *marca = NULL;
    SuprafataRulare s: 2;
    unsigned int putere: 8;
};


char* suprafata_text(Vehicul &veh)
{    
    char *ret = (char *)malloc(15 * sizeof(char));
    switch(veh.s) {
        case terestra: {
            strcpy(ret, "terestra");
            break;
        }
        case acvatica: {
            strcpy(ret, "acvatica");
            break;
        }
        case aeriana: {
            strcpy(ret, "aeriana");
            break;
        }
        case spatiala: {
            strcpy(ret, "spatiala");
            break;
        }
    }

    return ret;
}

void citeste_vehicul(Vehicul &veh) 
{
    if(veh.marca != NULL) {
        free(veh.marca);
        veh.marca = NULL;
    }

    cout<<"Marca vehicul: ";
    char temp[20];
    cin>>temp;
    veh.marca = (char *)malloc((strlen(temp) + 1) * sizeof(char));
    strcpy(veh.marca, temp);

    cout<<"SuprafataRulare: ";
    int suprafata;
    cin>>suprafata;
    veh.s = SuprafataRulare(suprafata);

    cout<<"Putere: ";
    unsigned int put;
    cin>>put;
    veh.putere = put;
    cout<<"\n\n";
}

void afisare_vehicul(Vehicul veh)
{
    cout<<"\nMarca vehicul: "<<veh.marca;
    char *suprafata = suprafata_text(veh);
    cout<<"\nSupratafaRulare: "<<suprafata;
    cout<<"\nPutere: "<<veh.putere;
    cout<<"\n";
}

void set_marca(Vehicul &veh, char *marca_noua)
{
    if(veh.marca != NULL) {
        free(veh.marca);
        veh.marca = NULL;
    }
    veh.marca = (char *)malloc((strlen(marca_noua) + 1) * sizeof(char));
    strcpy(veh.marca, marca_noua);
}

void set_putere(Vehicul &veh, unsigned int putere_noua)
{
    veh.putere = putere_noua;
}

void set_suprafata(Vehicul &veh, SuprafataRulare suprafata)
{
    veh.s = suprafata;
}

void copiaza_vehicul(Vehicul &new_veh, Vehicul &old_veh)
{
    if(new_veh.marca != NULL) {
        free(new_veh.marca);
        new_veh.marca = NULL;
    }

    new_veh.marca = (char *)malloc((strlen(old_veh.marca) + 1) * sizeof(char));
    strcpy(new_veh.marca, old_veh.marca);

    new_veh.putere = old_veh.putere;

    new_veh.s = old_veh.s;
}




int main()
{
    // Test cod:
    // Vehicul masina;
    // citeste_vehicul(masina);
    // afisare_vehicul(masina);
    // char bmw[] = "bmw";
    // set_marca(masina, bmw);
    // afisare_vehicul(masina);
    // unsigned int put = 150;
    // set_putere(masina, put);
    // afisare_vehicul(masina);
    // set_suprafata(masina, spatiala);
    // afisare_vehicul(masina);

    int nr_veh;
    cout<<"-------------------------------------------------------\n";
    cout<<"Numar vehicule: ";
    cin>>nr_veh;
    
    Vehicul *masini = NULL;
    masini = (Vehicul *)malloc(nr_veh * sizeof(Vehicul));
    
    for(int i = 0; i < nr_veh; i++) {
        cout<<"Citeset vehiculul de pe pozitia: "<<i<<"\n";
        citeste_vehicul(masini[i]);
    }
    

    cout<<"-------------------------------------------------------\n";
    cout<<"Masini sortate:\n";
    for(int i = 0; i < nr_veh; i++) {
        for(int j = 0; j < nr_veh; j++) {
            if(strcmp(masini[i].marca, masini[j].marca) < 0) {
                Vehicul temp_veh;
                copiaza_vehicul(temp_veh, masini[i]);
                copiaza_vehicul(masini[i], masini[j]);
                copiaza_vehicul(masini[j], temp_veh);
            }
        }
    }    

    for(int i = 0; i < nr_veh; i++) 
        afisare_vehicul(masini[i]);


    cout<<"-------------------------------------------------------\n";
    cout<<"Masini care ruleaza pe suprafata aeriana si care au putere mai mica de 100 de cai putere:\n";
    for(int i = 0; i < nr_veh; i++) {
        if(masini[i].s == aeriana && masini[i].putere < 100) {
            afisare_vehicul(masini[i]);
        }
    }

    cout<<"-------------------------------------------------------\n";
    cout<<"Modificam puterea vehiculelor (acvatica):\n";
    for(int i = 0; i < nr_veh; i++) {
        if(masini[i].s == aeriana) {
            masini[i].putere = masini[i].putere - (2/10 * masini[i].putere);
        }
    }

    for(int i = 0; i < nr_veh; i++) 
        afisare_vehicul(masini[i]);

    
    Vehicul *vector_terestru = NULL;
    vector_terestru = (Vehicul *)malloc(sizeof(Vehicul));
    unsigned int total_vector_terestru = 0;
    
    cout<<"-------------------------------------------------------\n";
    cout<<"\n\nVectorul cu vehicule terestre (vector_terestru)\n";
    for(int i = 0; i < nr_veh; i++) {
        if(masini[i].s == terestra) {
            set_marca(vector_terestru[total_vector_terestru], masini[i].marca);
            set_suprafata(vector_terestru[total_vector_terestru], masini[i].s);
            set_putere(vector_terestru[total_vector_terestru], masini[i].putere);
            total_vector_terestru++;
            vector_terestru = (Vehicul *)realloc(vector_terestru, (total_vector_terestru + 1) * sizeof(Vehicul));
        }
    }

    for(int i = 0; i < total_vector_terestru; i++) {
        afisare_vehicul(vector_terestru[i]);
    }

    free(masini);
    masini = NULL;
    free(vector_terestru);
    vector_terestru = NULL;
    return 0;

}