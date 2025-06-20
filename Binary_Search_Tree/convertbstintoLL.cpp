void convertintoDLL(Node* root, Node* &head){
  if(root==NULL){
    return NULL;
  }

  convertintoDLL(root->right,head);
  root-right=head;
  head->left=root;
  head=root;

  convertintoDLL(root->left,head);
  
}
  
