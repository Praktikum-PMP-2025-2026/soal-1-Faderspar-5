/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 * Modul               : 5
 * Hari dan Tanggal    : Selasa, 12 May 2026
 * Nama (NIM)          : Fauzan Akmal Rabbani (13224025)
 * Nama File           : last.c
 * Deskripsi           : Soal no 1 dengan implementasi fungsi-fungsi traversal dan alokasi memori dinamis
 * */

 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>

 //Implementasi 3 fungsi traversal (Referensi : Geeks for Geeks)

 struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Create node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)) ;
    if (newNode != NULL) {
        newNode ->data = data;
        newNode -> left = NULL ;
        newNode -> right = NULL ;
    }return newNode;
}

//Build Tree kiri = 2i+1 kanan = 2i+2
struct Node* createTree(int *arr, int n, int i) {
    struct Node* root = NULL;
    if (i < n) {
        root = createNode(arr[i]);
        root->left = createTree(arr, n, 2 * i + 1);
        root->right = createTree(arr, n, 2 * i + 2);
    } return root; 
}

//Preorder 
void preorderTraversal(struct Node* root) {
    if (root == NULL) return;
    printf(" %d", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//Inorder
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf(" %d", root->data);
    inorderTraversal(root->right);
}

// Postorder
void postorderTraversal(struct Node* root) {
    if (root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf(" %d", root->data);
}

int main() {
    int n; 
    int i;
    if (scanf("%d", &n) != 1) {
        return 0 ;
    }
    int *t = (int*)malloc(n*sizeof(int)) ;
    for (i =0 ; i < n; i++ ) {
        scanf("%d", &t[i]) ;
    }
    struct Node* root = createTree(t, n, 0) ;

    printf ("PRE") ;
    preorderTraversal(root) ;
    printf("\n") ;
        
    printf("IN") ;
    inorderTraversal(root) ; 
    printf("\n");

    printf("POST") ;
    postorderTraversal(root) ;
    printf("\n") ;
        
    free(t) ;
    return 0;
}
