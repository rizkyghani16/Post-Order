 #include <stdio.h>
 #include <stdlib.h>

  struct tnode {
        int angka;
        struct tnode *kiri, *kanan;
  };

  struct tnode *root = NULL;

  struct tnode * BuatNode(int angka) {
        struct tnode *NodeBaru;
        NodeBaru  = (struct tnode *) malloc(sizeof(struct tnode));
        NodeBaru->angka = angka;
        NodeBaru->kiri = NULL;
        NodeBaru->kanan = NULL;
        return (NodeBaru);
  }

  void insertion(struct tnode **node, int angka) {
        if (!*node) {
                *node = BuatNode(angka);
        } else if (angka < (*node)->angka) {
                insertion(&(*node)->kiri, angka);
        } else if (angka > (*node)->angka) {
                insertion(&(*node)->kanan, angka);
        }
  }

  void postOrder(struct tnode *node) {
        if (node) {
                postOrder(node->kiri);
                postOrder(node->kanan);
                printf("%d  ", node->angka);
        }
        return;
  }

  int main() {
        int angka, ch;
        while (1) {
                printf("\n1. Masukan Data");
                printf("\n2. Post-order");
                printf("\n3. Keluar");
                printf("\n\nMasukan pilihan anda : ");
                scanf("%d", &ch);
                switch (ch) {
                        case 1:
                                printf("Masukan angka anda : ");
                                scanf("%d", &angka);
                                insertion(&root, angka);
                                break;
                        case 2:
                                postOrder(root);
                                break;
                        case 3:
                                exit(0);
                        default:
                                printf("Pilihan anda salah\n");
                                break;
                }
        }
        return 0;
  }
