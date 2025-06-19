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

Node* deleteanode(Node* root,int x){
    if(root==NULL){
        return root;
    }

    if(root->data==x){
        // for 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // for 1 child 
        if(root->left!=NULL && root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            nNode* temp=root->right;
            delete root;
            return temp;
        }

        // for 2 children
        if(root->left!=NULL && root->right!=NULL){
            int minvalue=minval(root->right)->data;
            root->data=minvalue;
            root->right=deleteanode(root->right,minvalue);
            return root;
        }

    }
    else if(root->data>x){
        root->left=deleteanode(root->left,x);
       
    }
    else{
        root->right=deleteanode(root->right,x);
       
    }

    return root;

}

Node* minval(Node* root){
    Node* temp=root;

    while(temp!=NULL){
        temp=temp->left;
    }

    return temp;
}


int main(){


    Node* root=NULL;
    

    cout<<"enter the input data"<<endl;
    takeinputdata(root);


    lavelordertraversel(root);


    root=deleteanode(root,val);






    return 0;
}