void convertintoDLL(Node* root, Node* &head){
  if(root==NULL){
    return NULL;
  }

  convertintoDLL(root->right,head);
  root-right=head;
  if(head!=NULL){
    head->left=root;
  }
  head=root;

  convertintoDLL(root->left,head);
  
}
  
