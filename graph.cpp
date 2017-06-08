#include<iostream>
#include<string>

using namespace std;

class Edge
{
public:
    const int start;
    const int end;
    const int weight;
    Edge(int _start,int _end,int _weight):start(_start),end(_end),weight(_weight){}
    ~Edge() {if(next!=NULL)delete next;}
    Edge * getNext(){return next;}
    void  setNext(Edge * _next){if(next!=NULL)delete next;next = _next;}
private:
    Edge * next;
};

class GraphNode
{
public:
    
    GraphNode(){}
    ~GraphNode(){if(firstEdge!=NULL)delete firstEdge;};
    void setName(string _name){name = _name;firstEdge = NULL;}
    void addEdge(Edge * edge);
    string getName(){return name;}
    Edge * getFirstEdge(){return firstEdge;}
private:
    string name;
    Edge * firstEdge;
    // Edge * lastEdge;
};
void GraphNode::addEdge(Edge * edge){
    if(edge != NULL){
        edge->setNext(firstEdge);
        firstEdge=edge;
    }
    // if(firstEdge == NULL){
    //     firstEdge = edge;
    //     // lastEdge = firstEdge;
    // }else{
    //     edge ->setNext(firstEdge);
    //     firstEdge = edge;
    //     // lastEdge = edge;
    // }
}

class Graph
{
public:
    Graph(int _size):size(_size){if(_size>0) nodes = new GraphNode[_size];};
    ~Graph(){if(nodes!=NULL)delete [] nodes;};
    GraphNode * getNode(int n){if(n<size) return nodes+n;else return NULL;}
    Edge * getNodeEdges(int n){if(n<size) return nodes[n].getFirstEdge();else return NULL;}
private:
    int size;
    GraphNode * nodes; 
};

int main(){
    int size,temp1,temp2;
    string c;
    cin >> size;
    Graph g(size);
    for (int i = 0; i < size; i++){
        cin >> c;
        g.getNode(i)->setName(c);
    }
    for (int i = 0; i < size; i++){
        for(cin >> temp1;temp1 != -1;cin >> temp1){
            cin >> temp2;
            g.getNode(i)->addEdge(new Edge(i,temp1,temp2));
        }
    }

    for (int i = 0; i < size; i++){
        cout << g.getNode(i)->getName() << "  ";
        for(Edge * p = g.getNodeEdges(i);p!=NULL;p=p->getNext()){
            cout << "(" << p->start << "," << p->end << ")" << p->weight << "  ";
        }
        cout << endl;
    }

    return 0;
}