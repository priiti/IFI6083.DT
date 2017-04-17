#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Kirjeldus sõlme (node) jaoks
// Viidav2ljade nimedeks on "jah" v6i "ei". Nende abil antakse ette, mis tegevus j2rgmiseks on
struct AnimalTree {
    char text[30];
    struct AnimalTree *yes, *no;
};

// Funktsioon tagastab "jah" v6i "ei" v22rtuse siis, kui kasutaja on neist kumbagi valinud
char yesOrNo() {
    char answer = ' ';
    while (answer != 'y' && answer != 'n') {
        scanf("%c", &answer);
        getchar();
    }
    return answer;
}

// Funktsioon puu juure moodustamiseks
// Sisendiks on juure sisse kirjutatav tekst, v2ljundiks juure aadress
// N2ide: struct Animaltree *juur;
//        ...
//        juur = pathNode("Kas ta on suur"?);
struct AnimalTree *pathNode(char words[30]) {
    struct AnimalTree *helper;
    helper = (struct AnimalTree *)malloc(sizeof(struct AnimalTree));
    strcpy(helper->text, words);
    helper->yes = NULL;
    helper->no = NULL;
    
    return helper;
}

// Lisame puusse uue elemendi
// Uus element lisatakse parameetriga "koht" (viit- muutuja) m22ratud elemendi ei- v2lja kylge
// Tekstiv2lja kirjutatakse s6nad (words) v22rtus
// N2ide: struct AnimalTree *node;
//        addAnswerNo(node, "Hiir");
void addAnswerNo(struct AnimalTree *location, char words[30]) {
    struct AnimalTree *helper;
    helper = (struct AnimalTree *)malloc(sizeof(struct AnimalTree));
    strcpy(helper->text, words);
    helper->yes = NULL;
    helper->no = NULL;
    location->no = helper;
}

// Lisame puusse uue elemendi
// Uus element lisatakse parameetriga "koht" (viit- muutuja) m22ratud elemendi jah- v2lja kylge
// Tekstiv2lja kirjutatakse s6nad (words) v22rtus
// N2ide: struct AnimalTree *node;
//        addAnswerYes(node, "Hiir");
void addAnswerYes(struct AnimalTree *location, char words[30]) {
    struct AnimalTree *helper;
    helper = (struct AnimalTree *)malloc(sizeof(struct AnimalTree));
    strcpy(helper->text, words);
    helper->yes = NULL;
    helper->no = NULL;
    location->yes = helper;
}

// Funktsioon tagastab viida, mis on parameetriks "koht" olevale "ei" s6lmele
// "Ei" pool oleva elemendi viit
// Funktsiooni sobib kasutada puus liikumiseks juurest leheni
// N2ide: if (answer == 'n')
//              helper = moveTowardsNo(helper);
struct AnimalTree *moveTowardsNo(struct AnimalTree *location) {
    return location->no;
}

// Funktsioon tagastab viida, mis on parameetriks "koht" olevale "jah" s6lmele
// "Ei" pool oleva elemendi viit
// Funktsiooni sobib kasutada puus liikumiseks juurest leheni
// N2ide: if (answer == 'y')
//              helper = moveTowardsNo(helper);
struct AnimalTree *moveTowardsYes(struct AnimalTree *location) {
    return location->yes;
}

// Funktsioon kontrollib, kas parameetrit "koht" ette antud s6lm on leht
// 1 kui on leht, 0 kui ei ole leht
// Puus liikumise kontrolliks
// N2ide: (kuni ei ole j6utud leheni) -> while (!isLeaf(otsija)) {...
int isLeaf(struct AnimalTree *location) {
    if (location->yes == NULL) {
        return 1;
    } else {
        return 0;
    }
}

// Funktsioon tagastab parameetri "location" nodes oleva teksti
// N2ide: loom = nodeData(otsija);
char *nodeText(struct AnimalTree *location) {
    return location->text;
}

void addText(struct AnimalTree *location, char *text) {
    strcpy(location->text, text);
}

int main() {
    struct AnimalTree *animals, *helper;
    char answer, playAgain;
    char newAnimal[30], question[30], oldAnimal[30];
    
    animals = pathNode("Kas ta on suur?");
    addAnswerNo(animals, "Hiir");
    addAnswerYes(animals, "Elevant");
    
    // Kysimuste esitamise ja puus liikumise tsykkel
    do {
        helper = animals;
        while (!isLeaf(helper)) {
            printf("%s [y / n] ", nodeText(helper));
            answer = yesOrNo();
            
            if (answer == 'y') {
                helper = moveTowardsYes(helper);
            } else {
                helper = moveTowardsNo(helper);
            }
        }
        
        // Abi on looma sisaldava elemendi juures
        printf("Kas see loom on %s [y / n]?", nodeText(helper));
        answer = yesOrNo();
        
        if (answer == 'n') {
            printf("Mis looma m6tlesid?");
            fgets(newAnimal, 30, stdin);
            printf("Mida tema kohta kysida saab?");
            fgets(question, 30, stdin);
            strcpy(oldAnimal, nodeText(helper));
            addAnswerNo(helper, oldAnimal);
            addAnswerYes(helper, newAnimal);
            addText(helper, question);
        } else {
            printf("Tubli! Arvasid 6igesti.");
        }
        printf("Kas soovid veel m2ngida?");
        playAgain = yesOrNo();
    } while (playAgain == 'y');
    
    return 0;
}
