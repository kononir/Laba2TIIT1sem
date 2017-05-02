//---------------------------------------------------------------------------

#include <vcl.h>
#include <conio.h>
#include <iostream.h>
#pragma hdrstop

struct Graph {int numberofvertex, numberofreb; int **mas; int *masnum; int *connection;} *graph;
void run_testcase(const char*);
Graph *load_graph(const char*);
void Check(int, Graph*);
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        run_testcase("graph1.txt");
}

getch();                        //getch ПОТОМ УБРАТЬ!!!!!!!!!!!!!!!!!!!!!!!
        return 0;
}

void run_testcase(const char *path){
        Graph *graph;
        graph=load_graph(path);
        show_graph(graph);
        Answer(graph);
        Delete_graphs(graph);
}

Graph *load_graph(const char *path)
{
FILE *f;
int answer=1, a, b;
if(f=fopen(path, "rb")){
        graph=new Graph;
        fscanf(f ,"%i", &graph->numberofvertex); //считывание кол-ва вершин
        fscanf(f ,"%i", &graph->numberofreb); //считывание кол-ва рёбер
        //cout<<numberofvertex<<endl<<numberofreb<<endl; //ВЫВОД КОЛ-ВА ВЕРШИН И РЁБЕР
        graph->mas=new int*[graph->numberofvertex+1];
        graph->masnum=new int[graph->numberofvertex+1];
        for(int i=1; i<graph->numberofvertex+1; i++){
                graph->mas[i]=new int[graph->numberofvertex];
                graph->masnum[i]=0; //заполняем массив кол-ва смежных данной вершине вершин нулями
        }
        while(answer>0){ //считывание рёбер(вершин)
                answer=fscanf(f ,"%i", &a);
                fscanf(f ,"%i", &b);
                if(answer>0){
                        graph->masnum[a]++;
                        graph->masnum[b]++;
                        graph->mas[a][graph->masnum[a]]=b;
                        graph->mas[b][graph->masnum[b]]=a;
                        //cout<<a<<" "<<b<<endl;
                }
        }
        fclose(f);
        //cout<<endl;
        //for(int i=1; i<graph->numberofvertex+1; i++){ //ВЫВОД ГРАФА
                //cout<<i<<"->";
                //for(int j=1; j<=graph->masnum[i]; j++) cout<<" "<<graph->mas[i][j];
                //cout<<endl;
        //}
}
else{
        printf("Error: Cannot open file '%s'.\n", path);
        getch();
        exit(1);
}
return graph;
}

void Check(int i, Graph *graph) //рекурсивная функция, которая записывает все вершины, которые связаны с вершиной 1 хотябы одним путём
{
int n;
        for(int j=0; j<graph->masnum[i]; j++){ //все смежные данной вершине вершины
                n=0;
                for(int k=1; k<=graph->connection[0]; k++){ //проверяются на существование номера такой вершины в массиве
                        if(graph->mas[i][j]!=graph->connection[k]){ //если не совпадает, то увеличивам переменную n на 1
                                n++;
                                continue;
                        }
                        break;
                }
                if(n==graph->connection[0]){ //если такой номер не найден, то записываем его в массив
                        graph->connection[0]++; //то увеличиваем кол-во элементов вершин, связаных с вершиной 1 хотябы одним путём
                        graph->connection[graph->connection[0]]=graph->mas[i][j]; //добавляем номер этой вершины в массив
                        Check(graph->mas[i][j], graph); //продолжаем поиск вершин (берём смежную данной вершине вершину)
                }
        }
}


//---------------------------------------------------------------------------
