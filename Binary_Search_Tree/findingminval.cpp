#include<iostream>
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

Node* minval(Node* root){
    Node* temp=root;

    while(temp!=NULL){
        temp=temp->left;
    }

    return temp;
}

Node* maxval(Node* root){
    Node* temp=root;

    while(temp!=NULL){
        temp=temp->right;
    }

    return temp;
}


int main(){

    Node* root=NULL;
    
    cout<<"enter the data"<<endl;
    takeinputdata(root);


    lavelordertraversel(root);

    ans1=minval(root);
    cout<<"min value will be"<<ans1<<endl;


    ans2=maxval(root);
    cout<<"max value will be"<<ans2<<endl;












    return 0;
}