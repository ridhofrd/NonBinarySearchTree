#include "ADTNonBinaryTree.h"


void Create_withqueue(Isi_Tree X, int Jml_Node){
    if(Jml_Node != -1)
    {
        int Q[Jml_Node + 1];
        int pcur = 0;
        //printf("%c", X[pcur].info);
        //pcur = X[0].ps_fs;
        int nodeTerisi = 0;
        int sentinel = -1, jumlahAnak;
        char isiNode, terminator;
        int i = 0, o = 0;
        printf("Root: ");
        scanf("%c", &isiNode);
        X[i].info = isiNode;
        X[i].ps_nb = -1;
        X[i].ps_pr = -1;
        Q[i] = 0;
        nodeTerisi++;
        printf("JumlahAnak: ");
        scanf("%d", &jumlahAnak);
        scanf("%c", &terminator);
        int nodeinputAnak = 0;

            while(nodeinputAnak < jumlahAnak){
                printf("Anak ke-%d dari %c: ", nodeinputAnak + 1, X[Q[o]].info);
                scanf("%c", &isiNode);
                scanf("%c", &terminator);
                i++;
                if(nodeinputAnak == 0)
                    X[Q[o]].ps_fs = i;
                else
                    X[i - 1].ps_nb = i;
                nodeinputAnak++;
                nodeTerisi++;
                X[i].info = isiNode;
                X[i].ps_pr = Q[o];
                X[i].ps_fs = -1;
                X[i].ps_nb = -1;
                Q[i] = i;


            }

        o++;
        while(nodeTerisi < Jml_Node){
            nodeinputAnak = 0;
            printf("Jumlah node terisi: %d\n\n", nodeTerisi);
            printf("Parent %c\n", X[Q[o]].info);
            printf("JumlahAnak: ");
            scanf("%d", &jumlahAnak);
            scanf("%c", &terminator);

            while(nodeinputAnak < jumlahAnak){
                printf("Anak ke-%d dari %c: ", nodeinputAnak + 1, X[Q[o]].info);
                scanf("%c", &isiNode);
                scanf("%c", &terminator);
                i++;
                if(nodeinputAnak == 0)
                    X[Q[o]].ps_fs = i;
                else
                    X[i - 1].ps_nb = i;

                nodeinputAnak++;
                nodeTerisi++;
                X[i].info = isiNode;
                X[i].ps_pr = Q[o];
                X[i].ps_fs = -1;
                X[i].ps_nb = -1;
                Q[i] = i;


            }
            o++;
        }

    }
}
void Create_tree(Isi_Tree X, int Jml_Node){
    char isiVertex;
    char terminator;

    printf("Input tree dengan urutan pengisian secara level order: \n");
    int nodeTerisi  = 0, level = 0, parentTerisi = 0, parentOfNode = 0;
    printf("Masukkan nilai root(Level 0): ");
    scanf("%c", &isiVertex);
    X[nodeTerisi].info = isiVertex;
    X[nodeTerisi].ps_pr = -1;
    X[nodeTerisi].ps_nb = -1;
    int statusPengisianLevel = 1;

    while(nodeTerisi < Jml_Node){
        statusPengisianLevel = 1;
        int jumlahAnak;
        while(statusPengisianLevel == 1 && nodeTerisi <= Jml_Node){
            int anakTerisi  = 0;
            printf("Anak yang dimiliki oleh parent %c node %d level %d: ", X[parentTerisi].info, parentTerisi, level);
            scanf("%d", &jumlahAnak);
            if(nodeTerisi + jumlahAnak >= Jml_Node){
                statusPengisianLevel = 0;
                nodeTerisi += jumlahAnak;
                break;
            }
            scanf("%c", &terminator);
                while(anakTerisi < jumlahAnak){
                    char nilaiAnak;
                    if(anakTerisi == 0){
                        nodeTerisi++;
                        printf("Masukkan nilai anak ke-%d dari node %d: ", anakTerisi + 1, parentTerisi);
                        scanf("%c", &nilaiAnak);
                        scanf("%c", &terminator);
                        X[nodeTerisi].info = nilaiAnak;
                        X[nodeTerisi].ps_pr = parentTerisi;
                        X[nodeTerisi].ps_fs = -1;
                        X[parentTerisi].ps_fs = nodeTerisi;
                        anakTerisi++;
                    }
                    else{
                        nodeTerisi++;
                        printf("Masukkan nilai anak ke-%d dari node %d: ", anakTerisi + 1, parentTerisi);
                        scanf("%c", &nilaiAnak);
                        scanf("%c", &terminator);
                        X[nodeTerisi].info = nilaiAnak;
                        X[nodeTerisi].ps_pr = parentTerisi;
                        X[nodeTerisi - 1].ps_nb = nodeTerisi;
                        X[nodeTerisi].ps_fs = -1;
                        anakTerisi++;
                    }
                }
            X[nodeTerisi].ps_nb = -1;

            if(X[parentTerisi].ps_nb != -1)
                parentTerisi = X[parentTerisi].ps_nb;
            else{
                statusPengisianLevel = 0;
            }

            printf("Jumlah node terisi: %d\n", nodeTerisi + 1);

        }
        level++;
        if(level == 1){
            parentTerisi = X[parentOfNode].ps_fs;
            printf("test2\n");
        }
        else{
            if(X[parentOfNode].ps_nb != -1 && X[X[parentOfNode].ps_nb].ps_fs != -1 && level >= 3){
                parentOfNode = X[parentOfNode].ps_nb;
                parentTerisi = X[parentOfNode].ps_fs;
            }
            else{
                parentOfNode = X[parentOfNode].ps_fs;
                parentTerisi = X[parentOfNode].ps_fs;
            }
        }
    }

    printf("Node sudah terisi penuh!!!!\n");
    printf("Enter untuk lanjut\n");
    scanf("%c", &terminator);
}

void PrintTree (Isi_Tree P, int Maks_node){
    for(int i = 0; i < Maks_node; i++){
        printf("===Identitas Node Indeks Ke-%d===\n\n", i);
        printf("===          %c               ===\n", P[i].info);

        if(P[i].ps_pr == -1)
            printf("Adam\n");
        else
            printf("Parent: %c\n", P[P[i].ps_pr].info);

        if(P[i].ps_fs == -1)
            printf("Tidak Punya Anak\n");
        else
            printf("First Son: %c\n", P[P[i].ps_fs].info);

        if(P[i].ps_nb == -1)
            printf("Tidak ada Next Brother\n");
        else
            printf("Next Brother: %c\n", P[P[i].ps_nb].info);
        printf("=================================\n\n");
    }
}

void PreOrder (Isi_Tree P){
    int pcur;
    int resmi;
    pcur = 0;
    printf("%c", P[pcur].info);
    resmi = true;
    int traverseStatus = 1;

    while(traverseStatus == 1){
        if(P[pcur].ps_fs != -1 && resmi){
            pcur = P[pcur].ps_fs;
            printf("%c", P[pcur].info);
        }
        else if(P[pcur].ps_nb != -1){
            pcur = P[pcur].ps_nb;
            printf("%c", P[pcur].info);
            resmi = true;
        }
        else{
            pcur = P[pcur].ps_pr;
            resmi = false;
        }

        if(P[pcur].ps_pr == -1)
            traverseStatus = 0;
    }

}

void InOrder (Isi_Tree P){
    int pcur;
    int resmi;
    pcur = 0;
    resmi = true;
    int traverseStatus = 1;

    while(pcur != -1){
        if(P[pcur].ps_fs != -1 && resmi)
            pcur = P[pcur].ps_fs;
        else{
            if(resmi)
                printf("%c", P[pcur].info);

            if(pcur == P[P[pcur].ps_pr].ps_fs)
                printf("%c", P[P[pcur].ps_pr].info);

            if(P[pcur].ps_nb != -1){
                pcur = P[pcur].ps_nb;
                resmi = true;
            }
            else{
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }
}

void PostOrder (Isi_Tree P){
    int pcur;
    int resmi;
    pcur = 0;
    resmi = true;
    while(pcur != -1){
        if(P[pcur].ps_fs != -1 && resmi)
            pcur = P[pcur].ps_fs;
        else{
            printf("%c", P[pcur].info);
            if(P[pcur].ps_nb != -1){
                pcur = P[pcur].ps_nb;
                resmi = true;
            }
            else{
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }
}



void Level_orderWithoutQueue(Isi_Tree X){
    int nodeTerTraverse = 0, parentTerisi = 1, parentOfNode = 0;
    int statusTraverseLevel = 1;
    int level = 0;
    printf("%c", X[parentOfNode]);

    while(X[parentTerisi].ps_nb != -1 || X[parentTerisi].ps_fs != -1){
        statusTraverseLevel = 1;
        while(statusTraverseLevel == 1 && (X[parentTerisi].ps_nb != -1 || X[parentTerisi].ps_fs != -1)){
            printf("%c", X[parentTerisi].info);

            if(X[parentTerisi].ps_nb != -1)
                parentTerisi = X[parentTerisi].ps_nb;
            else{
                statusTraverseLevel = 0;
            }


        }
        level++;
            if(X[parentOfNode].ps_nb != -1 && X[X[parentOfNode].ps_nb].ps_fs != -1 && level >= 2){
                parentOfNode = X[parentOfNode].ps_nb;
                parentTerisi = X[parentOfNode].ps_fs;
                printf("%d", parentOfNode);
            }
            else{
                parentOfNode = X[parentOfNode].ps_fs;
                parentTerisi = X[parentOfNode].ps_fs;
            }

    }

}

void Level_order(Isi_Tree X, int jumlahNode){
    //karena malas membuat queue maka pakai array saja

    int Q[jumlahNode + 1];
    int pcur = 0;
    //printf("%c", X[pcur].info);
    //pcur = X[0].ps_fs;
    int i = 0;
    int o = 0, sentinel = -1;
    Q[i] = -1;
    while(sentinel != (i + 1)){
        printf("%c", X[pcur].info);

        if(X[pcur].ps_fs != -1){
            i++;
            Q[i] = X[pcur].ps_fs;
            pcur = X[pcur].ps_fs;

            while(X[pcur].ps_nb != -1){
                i++;
                Q[i]  = X[pcur].ps_nb;
                pcur = X[pcur].ps_nb;

            }
        }

        o++;
        pcur = Q[o];
        sentinel = o;
    }

}

void PrintTreeAddress (Isi_Tree P, int Maks_node){
    for(int i = 0; i < Maks_node; i++){
        printf("===Identitas Node Indeks Ke-%d===\n", i);
        printf("Parent: %d\n", P[i].ps_pr);
        printf("First Son: %d\n", P[i].ps_fs);
        printf("Next Brother: %d\n", P[i].ps_nb);
        printf("=================================\n\n");
    }
}

boolean Search (Isi_Tree P, infotype X){
    //dengan menggunakan preOrder sebagai metode traversing
    int pcur;
    int resmi;
    pcur = 0;
    if(P[pcur].info == X)
        return true;

    resmi = true;
    int traverseStatus = 1;

    while(traverseStatus == 1){
        if(P[pcur].ps_fs != -1 && resmi){
            pcur = P[pcur].ps_fs;
            if(P[pcur].info == X)
                return true;
        }
        else if(P[pcur].ps_nb != -1){
            pcur = P[pcur].ps_nb;
            if(P[pcur].info == X)
                return true;
            resmi = true;
        }
        else{
            pcur = P[pcur].ps_pr;
            resmi = false;
        }

        if(P[pcur].ps_pr == -1)
            traverseStatus = 0;
    }
    return false;
}

int nbElmt (Isi_Tree P){
    //menghitung jumlah vertex dengan traversing secara inOrder
    int pcur;
    int resmi;
    int count = 0;
    pcur = 0;
    resmi = true;
    int traverseStatus = 1;

    while(pcur != -1){
        if(P[pcur].ps_fs != -1 && resmi)
            pcur = P[pcur].ps_fs;
        else{
            if(resmi)
                count++;
            if(pcur == P[P[pcur].ps_pr].ps_fs)
                count++;
            if(P[pcur].ps_nb != -1){
                pcur = P[pcur].ps_nb;
                resmi = true;
            }
            else{
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }

    return count;
}

int nbDaun (Isi_Tree P){
    //menghitung jumlah daun(vertex tanpa anak) dengan menggunakan traversal postOrder
    int pcur;
    int resmi, count = 0;
    pcur = 0;
    resmi = true;
    while(pcur != -1){
        if(P[pcur].ps_fs != -1 && resmi)
        {
            pcur = P[pcur].ps_fs;
            if(P[pcur].ps_fs == -1)
                count++;
        }
        else{
            if(P[pcur].ps_nb != -1){
                pcur = P[pcur].ps_nb;
                resmi = true;
                if(P[pcur].ps_fs == -1)
                    count++;
            }
            else{
                pcur = P[pcur].ps_pr;
                resmi = false;
            }
        }
    }

    return count;
}
int Level (Isi_Tree P, infotype X, int jumlahNode){
    //menghitung level dari suatu vertex dengan levelOrder traversal
    int Q[jumlahNode + 1];
    int level[jumlahNode + 1];
    int pcur = 0;
    //printf("%c", X[pcur].info);
    //pcur = X[0].ps_fs;
    int i = 0;
    int o = 0, sentinel = -1;
    Q[i] = 0;
    level[i] = 0;

    while(sentinel != (i + 1)){
        //printf("%c", X[pcur].info);
        if(P[pcur].ps_fs != -1){
            i++;
            Q[i] = P[pcur].ps_fs;
            pcur = P[pcur].ps_fs;
            level[i] = level[Q[o]]  + 1;
            if(X == P[pcur].info)
                return level[i];
            while(P[pcur].ps_nb != -1){
                i++;
                level[i] = level[Q[o]]  + 1;
                if(X == P[pcur].info)
                    return level[i];
                Q[i]  = P[pcur].ps_nb;
                pcur = P[pcur].ps_nb;

            }


        }

        o++;
        pcur = Q[o];
        sentinel = o;
    }

    return -1;

}

int Depth (Isi_Tree P, int jumlahNode){
    //menghitung depth dengan levelOrder traversing
    //menghitung level dari suatu vertex dengan levelOrder traversal
    int Q[jumlahNode + 1];
    int level[jumlahNode + 1];
    int pcur = 0;
    //printf("%c", X[pcur].info);
    //pcur = X[0].ps_fs;
    int i = 0;
    int o = 0, sentinel = -1;
    Q[i] = 0;
    level[i] = 0;

    while(sentinel != (i + 1)){
        //printf("%c", X[pcur].info);
        if(P[pcur].ps_fs != -1){
            i++;
            Q[i] = P[pcur].ps_fs;
            pcur = P[pcur].ps_fs;
            level[i] = level[Q[o]]  + 1;
            while(P[pcur].ps_nb != -1){
                i++;
                level[i] = level[Q[o]]  + 1;
                Q[i]  = P[pcur].ps_nb;
                pcur = P[pcur].ps_nb;

            }


        }

        o++;
        pcur = Q[o];
        sentinel = o;
    }

    return level[i];
}
