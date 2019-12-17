#include <iostream>
using namespace std;

#define INFINITY 65535
#define MaxNumSize 10
typedef int WeightType;
typedef char DataType;
typedef int Vertex;

bool Visited[MaxNumSize]={false};

typedef struct ENode{
    WeightType Weight;
    Vertex V1;
    Vertex V2;
}*Edge;

typedef struct GNode{
    int Nv;
    int Ne;
    WeightType G[MaxNumSize][MaxNumSize];
    DataType Data[MaxNumSize];
}*MGraph;

MGraph CreateGraph(int N);
MGraph BuildGraph();
void InsertEdge(MGraph Graph,Edge E);
void DFS(MGraph Graph,Vertex V);
void Visit(MGraph Graph,Vertex V);

int main() {
    MGraph Graph = BuildGraph();
    DFS(Graph,1);
    
    return 0;
}

MGraph BuildGraph(){
    int n;
    cout<<"请输入顶点个数 : ";
    cin>>n;
    MGraph Graph = CreateGraph(n);
    
    cout<<"请输入边数 : ";
    cin>>Graph->Ne;
    if(Graph->Ne){
        Edge E = new ENode;
        cout<<"Graph->Ne = "<<Graph->Ne<<endl;
        cout<<"请输入各边的顶点V1,V2和边权重Weight"<<endl;
        for(int i=0 ; i<Graph->Ne ; i++){
            cin>>E->V1>>E->V2>>E->Weight;
            InsertEdge(Graph,E);
        }
    }
    
    return Graph;
}

MGraph CreateGraph(int N){
    MGraph Graph = new GNode;
    Graph->Nv=N;
    Graph->Ne=0;
    
    for(int i=0;i<N;i++){
        cout<<"请输入点"<<i<<"的名字 : ";
        cin>>Graph->Data[i];
        for(int j=0;j<N;j++){
            Graph->G[i][j]=INFINITY;
            Graph->G[j][i]=INFINITY;
        }
    }
    
    return Graph;
}

void InsertEdge(MGraph Graph,Edge E){
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;
}

void DFS(MGraph Graph,Vertex V){
    Visit(Graph, V);
    Visited[V]=true;
    
    for(Vertex P = 0 ; P<Graph->Nv ; P++)
        if(Graph->G[V][P] != INFINITY&&!Visited[P])
            DFS(Graph,P);
}

void Visit(MGraph Graph,Vertex V){
    cout<<"Vertex "<<V<<"--"<<Graph->Data[V]<<" is Visited"<<endl;
}
