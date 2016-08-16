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
