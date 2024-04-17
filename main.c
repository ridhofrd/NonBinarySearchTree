#include <stdio.h>
#include <stdlib.h>
#include "ADTNonBinaryTree.h"

int main()
{
    nbtree NonBinaryTree[jml_maks + 1];
    int jumlahNode, inputStatus = 0;
    while(inputStatus == 0){
        printf("Masukkan jumlah node(max 20): ");
        scanf("%d", &jumlahNode);
        if(jumlahNode > 20)
            printf("Jumlah node yang dimasukkan lebih dari 20\n");
        else if(jumlahNode == 0){
            jumlahNode = -1;
            break;
        }
        else
            break;
    }
    char terminator;
    scanf("%c", &terminator);
    Create_withqueue(NonBinaryTree, jumlahNode);
    PrintTree(NonBinaryTree, jumlahNode);
    printf("PreOrder traversing: \n");
    PreOrder(NonBinaryTree);
    printf("\nInOrder traversing: \n");
    InOrder(NonBinaryTree);
    printf("\nPostOrder traversing: \n");
    PostOrder(NonBinaryTree);
    printf("\nLevelOrder traversing: \n");
    Level_order(NonBinaryTree, jumlahNode);

    printf("\n\nApakah I ada dalam tree? %d", Search(NonBinaryTree, 'I'));
    printf("\nTotal Vertex Pada Tree: %d", nbElmt(NonBinaryTree));
    int statusI = Search(NonBinaryTree, 'I');
    printf("\nJumlah Daun(Vertex tanpa anak) Pada Tree: %d", nbDaun(NonBinaryTree));
    if(statusI == 1)
        printf("\nLevel dari I adalah %d", Level(NonBinaryTree, 'I', jumlahNode));
    else
        printf("\nVertex dengan nilai I tidak ditemukkan\n");

    printf("\nDepth dari Tree adalah %d\n", Depth(NonBinaryTree, jumlahNode));
    return 0;
}
