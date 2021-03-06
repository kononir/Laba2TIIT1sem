//---------------------------------------------------------------------------

#include <vcl.h>
#include <conio.h>
#include <iostream.h>
#pragma hdrstop

struct Graph {int numberofvertex, numberofreb; int **mas; int *masnum; int *connection; int *bridge; int *cutvertex;} *graph;
void run_testcase(char*, char*);
Graph *load_graph(char*);
void Check(int, Graph*);
void Delete_graphs(Graph*);
void Answer(Graph*);
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
        char name[6], number[2];
        for(int num=1; num<=16; num++){
                itoa(num, number, 10);
                strcpy(name, number);
                strcat(name, ".in");
                run_testcase(number, name);
        }
getch();                        //getch ����� ������!!!!!!!!!!!!!!!!!!!!!!!
        return 0;
}

void run_testcase(char *number, char *path)
{
        Graph *graph;
        graph=load_graph(path);
        //Answer(number, graph);
        Delete_graphs(graph);
}

Graph *load_graph(char *path)
{
FILE *f;
int answer=1, a, b;
        if(f=fopen(path, "rb")){
                graph=new Graph;
                fscanf(f ,"%i", &graph->numberofvertex); //���������� ���-�� ������
                fscanf(f ,"%i", &graph->numberofreb); //���������� ���-�� ����
                //cout<<graph->numberofvertex<<endl<<graph->numberofreb<<endl; //����� ���-�� ������ � Ш���
                graph->mas=new int*[graph->numberofvertex+1];
                graph->masnum=new int[graph->numberofvertex+1];
                for(int i=1; i<graph->numberofvertex+1; i++){
                        graph->mas[i]=new int[graph->numberofvertex];
                        graph->masnum[i]=0; //��������� ������ ���-�� ������� ������ ������� ������ ������
                }
                while(answer>0){ //���������� ����(������)
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
                cout<<endl;
                //for(int i=1; i<graph->numberofvertex+1; i++){ //����� �����
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
Answer(char *number, Graph *graph)
{
        int reb=1;
        char name[6];
        strcat(name, number);
        //f=fopen(name, "wb");
        graph->bridge=new int[graph->numberofreb];
        graph->bridge[0]=0;
        graph->cutvertex=new int[graph->numberofvertex-2+1];
        graph->cutvertex[0]=0;
        for(int i=1; i<graph->numberofvertex+1; i++){
                if(graph->masnum[i]==1){
                        graph->bridge[0]++;
                        graph->bridge[graph->bridge[0]]=reb;
                        reb++;
                        continue;
                }
                else{
                        
                }
        }
                        //fprintf()
                        //������� ��� �����
}
void Check(int i, int m, Graph *graph) //����������� �������, ������� ���������� ��� �������, ������� ������� � �������� 1 ������ ����� ����
{
int n;
        for(int j=0; j<graph->masnum[i]; j++){ //��� ������� ������ ������� �������
                n=0;
                for(int k=1; k<=graph->connection[0]; k++){ //����������� �� ������������� ������ ����� ������� � �������
                        if(graph->mas[i][j]!=graph->connection[k]){ //���� �� ���������, �� ���������� ���������� n �� 1
                                n++;
                                continue;
                        }
                        break;
                }
                if(n==graph->connection[0]){ //���� ����� ����� �� ������, �� ���������� ��� � ������
                        graph->connection[0]++; //�� ����������� ���-�� ��������� ������, �������� � �������� 1 ������ ����� ����
                        graph->connection[graph->connection[0]]=graph->mas[i][j]; //��������� ����� ���� ������� � ������
                        Check(graph->mas[i][j], m, graph); //���������� ����� ������ (���� ������� ������ ������� �������)
                }

        }
}

void Delete_graphs(Graph *graph) //�������� ����� � ��������������� ��������
{
        for(int i=1;i<graph->numberofvertex+1;i++) delete graph->mas[i];
        delete graph->mas;
        delete graph->connection;
        delete graph;
}
//---------------------------------------------------------------------------
