#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node* left;
    Node* right;
    
    // constructo
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;

    }

};

Node* insertintoBST(Node* root,int data){
    
    if(root==NULL){
        root=new Node(data);
        return root;
    }

    if(root->data > data){
        root->left=insertintoBST(root->left,data);
    }
    else{
        root->right=insertintoBST(root->right,data);
    }

    return root;
}

void takeinputdata(Node* &root){
    int data;
    cout<<"taking the input data"<<endl;
    cin>>data;

    while(data!=-1){
        root=insertintoBST(root,data);
        cin>>data;
    }


}

void lavelordertraversel(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){

        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }

}


int main(){

    Node* root=NULL;

    // taking input data to create BST
    takeinputdata(root);
    
    cout<<"printing the BST"<<endl;
    lavelordertraversel(root);



    return 0;
}