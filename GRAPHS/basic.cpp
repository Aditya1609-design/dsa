 #include<iostream>
 #include<unordered_map>
 #include<list>

 using namespace std;

class graph{

    public:
    unordered_map<int , list<int>> adj;

    void addedge(int u ,int v,bool direction){

        adj[u].push_back(v);

        if(direction==0){
            adj[v].push_back(u);
        }
    }


    void printgraph(){
        for(auto i:adj){
            cout<<i.first<<"--> ";
            for(auto j: i.second){
                cout<<j<<", ";
            }
        }
    }

};




// ******************** THIS IS THE IMPLEMENTATION USING VECTOR<VECTOR<INT>> ******************************

// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.
//     vector<int> ans[n];
//     for(int i=0;i<m;i++){
//         int u=edges[i][0];
//         int v=edges[i][1];


//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }


//     vector<vector<int>> adj(n);
//     for(int i=0;i<n;i++){
//         adj[i].push_back(i);

//         for(int j=0;j<ans[i].size();j++){
//             adj[i].push_back(ans[i][j]);
//         }
//     }

//     return adj;
    
// }


int main(){

    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;


    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>> u>> v;
        g.addedge(u,v,0);
    }


    g.printgraph();



    return 0;
}