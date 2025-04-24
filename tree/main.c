#include"tree.h"

void main(){
NODE *root=NULL,*ans;
int choice,n;
do{
printf("\n:::::MENU:::::\n1.CREATE\n2.SEARCH\n3.PREODER\n4.INORDER\n5.POSTORDER\n6.EXIT\n");
printf("\nEnter your choice:");
scanf("%d",&choice);
switch(choice){
case 1:root=createbst(root);break;
case 2:printf("Enter a Key to search:");
       scanf("%d",&n);
       ans=search(root,n);
       if(ans==NULL)
       printf("\nKey %d not found!!\n",n);
       else
       printf("\nkey %d found in tree.\n",ans->info);
       printf("\n");break;
case 3:printf("\nPREORDER traversal is:");
       preorder(root);
       printf("\n");break;
case 4:printf("\nINORDER traversal is:");
       inorder(root);
       printf("\n");break;
case 5:printf("\nPOSTORDER traversal is:");
       postorder(root);
       printf("\n");break;
case 6:printf("Exiting the program.........");
}
}while(choice!=6);
}

