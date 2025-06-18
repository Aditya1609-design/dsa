#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    // constructor
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node* root){
    cout<<"enter the value of root node"<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    } 
    root=new node(data);

    cout<<"enter the left child of the root node"<<endl;
    root->left=buildtree(root->left);
    cout<<"enter the right child of the root node"<<endl;
    root->right=buildtree(root->right);

    return root;

}

void lavelordertraversel(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);


    while(!q.empty()){

        node* temp=q.front();
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

void preordertraversal(node* root){
    if(root==NULL){
       return;
    }
    cout<<root->data<<endl;
    preordertraversal(root->left);
    preordertraversal(root->right);
}

void postordertraversal(node* root){
    if(root==NULL){
        return;
    }

    postordertraversal(root->left);
    postordertraversal(root->right);
    cout<<root->data<<endl;

}

void inordertraversal(node* root){
    if(root==NULL){
        return ;
    }

    inordertraversal(root->left);
    cout<<root->data<<endl;
    inordertraversal(root->right);
}

void buildfromlot(node* &root){
    queue<node*> q;
    cout<<"enter the data for root"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();

        cout<<"enter the data of left node of"<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }

        cout<<"enter the data of right node of"<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
}

// morris traversal
vector<int> inorder(Node* root){
vector<int> ans;
Node* curr=root;

while(curr!=NULL){
    if(!curr->left){
        ans.push_back(curr->data);
        curr=curr->right;
    }
    else{
        Node Prev=curr->left;
        while(prev->right!=NULL && prev->right!=curr){
            prev=prev->right;
        }
        if(pre->right==NULL){
            prev->right=curr;
            curr=curr->left;
        }
        else{
            prev->right=NULL;
            ans.push_back(curr->data);
            curr=curr->right;
    }

        return ans;
        
}


int main(){

    node* root=NULL;
    // root=buildtree(root);

    // // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // cout<<"printing the elements in lot"<<endl;
    // lavelordertraversel(root);

    // cout<<"printing the elements in preordertraversal"<<endl;
    // preordertraversal(root);


    // cout<<"printing the elements in postordertraversal"<<endl;
    // postordertraversal(root);


    // cout<<"printing the elements in inordertraversal"<<endl;
    // inordertraversal(root);

    buildfromlot(root);
    lavelordertraversel(root);








    return 0;
}
