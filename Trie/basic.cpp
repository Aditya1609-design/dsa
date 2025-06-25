#include<iostream>
using namespace std;

class Trienode{
    public:
        char data;
        Trienode* children[26];
        bool isTerminal;

        // constructor
        Trienode(char data){
            this->data=data;
            for(int i=0;i<26;i++){
                children[i]=NULL;
            }
            isTerminal=false;
        }

};

class Trie{
    public:
    Trienode* root;

    // constructor
    Trie(){
        root= new Trienode('\0');
    }

    void insertUtil(Trienode* root, string word){
        // base case
        if(word.length()==0){
            root->isTerminal=true;
            return ;
        }

        int index=word[0]-'A';
        Trienode* child;

        if(root->children[index] != NULL){
            child=root->children[index];
        }
        else{
            child = new Trienode(word[0]);
            root->children[index]=child;

        }

        insertUtil(child,word.substr(1));

    }

    void insertword(string word){
        insertUtil(root,word);
    }

    bool searchUtil(Trienode* root,string word){
        if(word.length()==0){
            return root->isTerminal;
        }

        int index=word[0]-'A';
        Trienode* child;

        if(root->children[index] !=NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        return searchUtil(child,word.substr(1));
    }

    bool searchword(string word){
        return searchUtil(root,word);
    }


    bool deleteUtil(Trienode* root,string word){
        if(word.length()==0){
            root->isTerminal=false;

            for(int i=0;i<26;i++){
                if(root->children[i] !=NULL){
                    return false; //node cannot be deleted
                }
            }

            return true; //node can be deleted
        }

        int index=word[0]-'A';
        Trienode* child;

        if(root->children[index] !=  NULL){
            child=root->children[index];
        }
        else{
            return false;
        }

        bool shouldbedeleted=deleteUtil(child,word.substr(1));

        if(shouldbedeleted){
            delete child;
            root->children[index]=NULL;

            if(root->isTerminal==false){
                for(int i=0;i<26;i++){
                    if(root->children[i] !=NULL){
                        return false;
                    }
                }
                return true;
            }
        }
        return false;
    }

    void deleteaword(string word){
        deleteUtil(root,word);
    }

};


int main() {

    Trie* t=new Trie();

    t->insertword("TIRE");
    t->insertword("TIME");
    t->insertword("ADITYA");

    cout<<"present or not "<< t->searchword("TIRE")<<endl;
    cout<<"present or not "<< t->searchword("TIR")<<endl;


    t->deleteaword("TIME");
    cout<<"present or not "<< t->searchword("TIME")<<endl;



    return 0;
}