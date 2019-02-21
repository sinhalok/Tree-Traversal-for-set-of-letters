#include <stdio.h>
#include <stdlib.h>
//ALOK SINHA
struct node
{
    int value;
    node* left;
    node* right;
};


struct node* root;

struct node* insert(struct node* r, int data);
void inOrder(struct node* r);
void preOrder(struct node* r);
void postOrder(struct node* r);

int main()
{
    system("color E");
    root = NULL;
    int j,n,  v;


    printf("\nHOW MANY DATA'S DO YOU WANT TO INSERT FOR TREE TRAVERSAL?\n");
    scanf("%d", &n);

  int i;
  char a[n];
  for(i=0;i<n;i++) {
    scanf(" %c",&a[i]);

  }

    for(int k=0; k<n; k++){
        v=a[k];
        root = insert(root, v);
    }

    printf("\nINORDER TRAVERSAL: ");
    inOrder(root);
    printf("\n");

    printf("PREORDER TRAVERSAL: ");
    preOrder(root);
    printf("\n");

    printf("POSTORDER TRAVERSAL: ");
    postOrder(root);
    printf("\n");


    return 0;
}

struct node* insert(struct node* r, int data)
{
    if(r==NULL)
    {
        r = (struct node*) malloc(sizeof(struct node));
        r->value = data;
        r->left = NULL;
        r->right = NULL;
    }
    else if(data < r->value){
        r->left = insert(r->left, data);
    }
    else {
        r->right = insert(r->right, data);
    }
    return r;

}

void inOrder(struct node* r)
{
    if(r!=NULL){
        inOrder(r->left);
        printf("%c ",(char)r->value);
        inOrder(r->right);
    }
}

void preOrder(struct node* r)
{
    if(r!=NULL){
        printf("%c ", (char)r->value);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node* r)
{
    if(r!=NULL){
        postOrder(r->left);
        postOrder(r->right);
        printf("%c ", (char)r->value);

    }
}
