#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Maze
{
public:
    const int m;
    const int n;
    Maze(int _m,int _n):m(_m),n(_n){
        mazemap = new int*[m];
        for (int i = 0; i < m; i++)
        {
            mazemap[i]=new int[n];
        }

    }
    ~Maze() {
        for (int i = 0; i < m; i++)
        {
            delete [] mazemap[i];
        }
       delete [] mazemap;
    }
    bool isAvailable(int l,int c){
        return (l>=0&&l<m&&c>=0&&c<n)&&(mazemap[l][c]==0); //简单写法
    }
    friend istream& operator>>(istream& is,Maze &m);

 private:
    int ** mazemap;
};

istream& operator>>(istream& is,Maze &m){
    int t;
    for (int i = 0; i < m.m; i++)
    {
        for (int j = 0; j < m.n; j++)
        {
            is >> t;
            m.mazemap[i][j]=t;
        }
    }
    return is;   
}

class Point
{
public:
    int l;
    int c;
    Point(){}
    Point(int _l,int _c):l(_l),c(_c){}
    Point(const Point& p){l=p.l;c=p.c;}
    bool operator==(Point &p){
        return l==p.l&&c==p.c;
    }
    Point& operator=(const Point& p){
        l=p.l;
        c=p.c;
        return *this;
    }

};
bool operator<(const Point &p1,const Point &p2){
    if (p1.l+p1.c!=p2.l+p2.c){
        return p1.l+p1.c<p2.l+p2.c;
    }else{
        return p1.l<p2.l;
    }
}

const int step[8][2]={{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1},{-1,0}};

class MazeSolver
{
public:
    MazeSolver(Maze &_maze):maze(_maze){
        time = new int*[maze.m];
        for (int i = 0; i < maze.m; i++)
        {
            time[i] = new int[maze.n];
            for (int j = 0; j < maze.n; j++)
            {
                time[i][j]=1000000; // 一个足够大的数   
            }
        }
    }
    ~MazeSolver(){
        for (int i = 0; i < maze.m; i++)
        {
            delete [] time[i];
        }
       delete [] time;
    }
    queue<Point> solve(){
        queue<Point> result;
        Point p(1,1);
        ptocheck.push(p);
        time[0][0]=0;
        while(!ptocheck.empty()){
            check(ptocheck.front().l-1,ptocheck.front().c-1);
            ptocheck.pop();
        } 
        if(time[maze.m-1][maze.n-1]==1000000)return result;
        p = Point(maze.m,maze.n);
        result.push(p);
        while(p.l!=1||p.c!=1){
            p = fore[p];
            result.push(p);
        }
        return result;
    }
private:
    Maze &maze;
    int ** time; //之前用广度优先，设定的时间戳。懒得去了，就当做访问标记
    int now;
    queue<Point> ptocheck;
    map<Point,Point> fore;
    bool isAvailable(int l,int c){
        return maze.isAvailable(l,c)&&time[l][c]>now+1;
    }
    void check(int l,int c){
        now = time[l][c];
        int nl,nc;
        for (int i = 0; i < 8; i++)
        {
            nl = l+step[i][0];
            nc = c+step[i][1];
            if(isAvailable(nl,nc)){
                time[nl][nc]=now+1;
                fore[Point(nl+1,nc+1)]=Point(l+1,c+1);
                ptocheck.push(Point(nl+1,nc+1));
            }
        }
    }
};
int main(){
    int m,n;
    cin >> m >> n;
    Maze maze(m,n);
    cin >> maze;
    MazeSolver ms(maze);
    queue<Point> solution = ms.solve();
    if(solution.empty()){
        cout << "不存在路径!" ;
    }
    while(!solution.empty()){
        cout << '(' << solution.front().l << ',' << solution.front().c << ") ";
        solution.pop();
    }
    cout << endl;
    return 0;
}