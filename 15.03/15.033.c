#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recete numarasi
int receteNumarasiCokAcil = 1;    // Cocuklar icin cok acil
int receteNumarasiAcil = 100;     // Cocuklar icin acil
int receteNumarasiNormal = 500;   // Cocuklar icin normal
int receteNumarasiCokAcilY = 1001;  // Yetiskinler icin cok acil
int receteNumarasiAcilY = 2001;     // Yetiskinler icin acil
int receteNumarasiNormalY = 3001;   // Yetiskinler icin normal

// Hasta yapisi
typedef struct Hasta {
    char isim[100];
    char soyisim[50];
    char tc[12];
    int yas;
    char cinsiyet[10]; // Cinsiyet "Erkek" veya "Kadýn" olacak
    char sikayet[100];
    int oncelik;  // 1 = Cok Acil, 2 = Acil, 3 = Normal
    int receteNo;
    struct Hasta *next;
} Hasta;

typedef struct Node {
    Hasta hasta;
    struct Node *next;
} Node;

Node *cocukHead = NULL; // Cocuk Acil icin ayri bir liste
Node *head = NULL; // Acil Servis icin ayri bir liste

// Yeni hasta ekleme
void hastaEkle() {
    Hasta yeniHasta;

    // Hasta ismini al
    printf("Hasta Adi: ");
    while (1) {
        fgets(yeniHasta.isim, sizeof(yeniHasta.isim), stdin);
        // Yeni satir karakterini temizle
        yeniHasta.isim[strcspn(yeniHasta.isim, "\n")] = 0; 
        // Ismin bos olmamasi gerekiyor
        if (strlen(yeniHasta.isim) > 0) {
            break;
        }
        printf("Gecersiz isim! Lutfen gecerli bir isim girin: ");
    }

    // Hasta soyadini al
    printf("Hasta Soyadi: ");
    while (1) {
        fgets(yeniHasta.soyisim, sizeof(yeniHasta.soyisim), stdin);
        // Yeni satir karakterini temizle
        yeniHasta.soyisim[strcspn(yeniHasta.soyisim, "\n")] = 0;
        // Soyadýn boþ olmamasý gerekiyor
        if (strlen(yeniHasta.soyisim) > 0) {
            break;
        }
        printf("Gecersiz soyisim! Lutfen gecerli bir soyisim girin: ");
    }

    // TC Kimlik No
    printf("TC Kimlik No: ");
    while (1) {
        scanf("%s", yeniHasta.tc);
        // TC kimlik numarasýnýn 11 haneli olmasý gerekiyor
        if (strlen(yeniHasta.tc) == 11) {
            break;
        }
        printf("Gecersiz TC Kimlik No! 11 haneli bir TC kimlik numarasi girin: ");
    }

    // Yas
    printf("Yas: ");
    while (1) {
        scanf("%d", &yeniHasta.yas);
        // Yasýn geçerli bir aralýkta olmasý gerekiyor
        if (yeniHasta.yas >= 0 && yeniHasta.yas <= 120) {
            break;
        }
        printf("Gecersiz yas! 0 ile 120 arasýnda bir yas girin: ");
    }

    // Cinsiyet
    printf("Cinsiyet (Erkek/Kadin): ");
    while (1) {
        scanf("%s", yeniHasta.cinsiyet);
        // Cinsiyetin "Erkek" veya "Kadýn" olmasý gerekiyor
        if (strcmp(yeniHasta.cinsiyet, "Erkek") == 0 || strcmp(yeniHasta.cinsiyet, "Kadýn") == 0) {
            break;
        }
        printf("Gecersiz cinsiyet! Lutfen 'Erkek' veya 'Kadýn' girin: ");
    }

    // Sikayet
    printf("Sikayet: ");
    getchar();  // Onceki \n'i temizleme
    fgets(yeniHasta.sikayet, sizeof(yeniHasta.sikayet), stdin);
    // Sikayetin bos olmamasý gerekiyor
    while (strlen(yeniHasta.sikayet) == 0) {
        printf("Sikayet bos olamaz! Lutfen bir sikayet girin: ");
        fgets(yeniHasta.sikayet, sizeof(yeniHasta.sikayet), stdin);
    }

    // Oncelik
    printf("Oncelik (1: Cok Acil, 2: Acil, 3: Normal): ");
    while (1) {
        scanf("%d", &yeniHasta.oncelik);
        // Oncelik 1, 2 veya 3 olmali
        if (yeniHasta.oncelik >= 1 && yeniHasta.oncelik <= 3) {
            break;
        }
        printf("Gecersiz oncelik! 1, 2 veya 3 girin: ");
    }

    // Recete numarasini ata
    if (yeniHasta.yas < 18) { // Cocuk hastalar icin
        if (yeniHasta.oncelik == 1) { // Cok Acil
            yeniHasta.receteNo = receteNumarasiCokAcil++;
        } else if (yeniHasta.oncelik == 2) { // Acil
            yeniHasta.receteNo = receteNumarasiAcil++;
        } else { // Normal
            yeniHasta.receteNo = receteNumarasiNormal++;
        }

        Node *yeniNode = (Node *)malloc(sizeof(Node));
        yeniNode->hasta = yeniHasta;
        yeniNode->next = NULL;

        // Cocuk hastalar icin oncelik kontrolu ve siralama
        if (cocukHead == NULL || yeniNode->hasta.oncelik < cocukHead->hasta.oncelik) {
            yeniNode->next = cocukHead;
            cocukHead = yeniNode;
        } else {
            Node *temp = cocukHead;
            while (temp->next != NULL && temp->next->hasta.oncelik <= yeniNode->hasta.oncelik) {
                temp = temp->next;
            }
            yeniNode->next = temp->next;
            temp->next = yeniNode;
        }

        printf("\nHasta basariyla eklendi (Cocuk Acil)! Recete No: %d, Oncelik: %s\n", yeniHasta.receteNo, 
               (yeniHasta.oncelik == 1) ? "Cok Acil" : (yeniHasta.oncelik == 2) ? "Acil" : "Normal");
    } else { // Yetiskin hastalar icin
        if (yeniHasta.oncelik == 1) { // Cok Acil
            yeniHasta.receteNo = receteNumarasiCokAcilY++;
        } else if (yeniHasta.oncelik == 2) { // Acil
            yeniHasta.receteNo = receteNumarasiAcilY++;
        } else { // Normal
            yeniHasta.receteNo = receteNumarasiNormalY++;
        }

        Node *yeniNode = (Node *)malloc(sizeof(Node));
        yeniNode->hasta = yeniHasta;
        yeniNode->next = NULL;

        // Yetiskin hastalar icin oncelik kontrolu ve siralama
        if (head == NULL || yeniNode->hasta.oncelik < head->hasta.oncelik) {
            yeniNode->next = head;
            head = yeniNode;
        } else {
            Node *temp = head;
            while (temp->next != NULL && temp->next->hasta.oncelik <= yeniNode->hasta.oncelik) {
                temp = temp->next;
            }
            yeniNode->next = temp->next;
            temp->next = yeniNode;
        }

        printf("\nHasta basariyla eklendi (Acil Servis)! Recete No: %d, Oncelik: %s\n", yeniHasta.receteNo, 
               (yeniHasta.oncelik == 1) ? "Cok Acil" : (yeniHasta.oncelik == 2) ? "Acil" : "Normal");
    }
}

// Acil Servisteki hastalarý listele
void acilServisListele() {
    Node *temp = head;
    if (temp == NULL) {
        printf("\nAcil Serviste hasta bulunmamaktadir.\n");
        return;
    }

    printf("\n--- Acil Servis Hastalari ---\n");
    while (temp != NULL) {
        printf("Isim: %s %s, TC: %s, Yas: %d, Cinsiyet: %s, Oncelik: %s, Recete No: %d\n", 
                temp->hasta.isim, temp->hasta.soyisim, temp->hasta.tc, temp->hasta.yas, 
                temp->hasta.cinsiyet, 
                (temp->hasta.oncelik == 1) ? "Cok Acil" : (temp->hasta.oncelik == 2) ? "Acil" : "Normal",
                temp->hasta.receteNo);
        temp = temp->next;
    }
}

// Cocuk Acil'deki hastalarý listele
void cocukAcilListele() {
    Node *temp = cocukHead;
    if (temp == NULL) {
        printf("\nCocuk Acil'de hasta bulunmamaktadir.\n");
        return;
    }

    printf("\n--- Cocuk Acil Hastalari ---\n");
    while (temp != NULL) {
        printf("Isim: %s %s, TC: %s, Yas: %d, Cinsiyet: %s, Oncelik: %s, Recete No: %d\n", 
                temp->hasta.isim, temp->hasta.soyisim, temp->hasta.tc, temp->hasta.yas, 
                temp->hasta.cinsiyet, 
                (temp->hasta.oncelik == 1) ? "Cok Acil" : (temp->hasta.oncelik == 2) ? "Acil" : "Normal",
                temp->hasta.receteNo);
        temp = temp->next;
    }
}

// Menu
void menu() {
    int secim;

    while (1) {
        printf("\n--- Acil Servis Sistemi ---\n");
        printf("1. Hasta Ekle\n");
        printf("2. Acil Servisteki Hastalari Listele\n");
        printf("3. Cocuk Acil'deki Hastalari Listele\n");
        printf("4. Cikis\n");
        printf("Secim: ");
        scanf("%d", &secim);
        getchar();  // Buffera kalan \n karakterini temizle

        switch (secim) {
            case 1:
                hastaEkle();
                break;
            case 2:
                acilServisListele();
                break;
            case 3:
                cocukAcilListele();
                break;
            case 4:
                printf("Cikis yapiliyor...\n");
                return;
            default:
                printf("Gecersiz secim!\n");
        }
    }
}

int main() {
    menu();
    return 0;
}

