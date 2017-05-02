//---------------------------------------------------------------------------

#include <vcl.h>
#include <conio.h>
#include <iostream.h>
#pragma hdrstop

struct Graph {int numberofvertex, numberofreb; int **mas; int *masnum; int *connection;} *graph;
void Check(int, Graph*);
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
FILE *f;
int answer=1, a, b;
if(f=fopen("1.in", "rb")){
        graph=new Graph;
        fscanf(f ,"%i", &graph->numberofvertex); //���������� ���-�� ������
        fscanf(f ,"%i", &graph->numberofreb); //���������� ���-�� ����
        //cout<<numberofvertex<<endl<<numberofreb<<endl; //����� ���-�� ������ � Ш���
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
else cout<<"ERROR!";
getch();                        //getch ����� ������!!!!!!!!!!!!!!!!!!!!!!!
        return 0;
}

void Check(int i, Graph *graph) //����������� �������, ������� ���������� ��� �������, ������� ������� � �������� 1 ������ ����� ����
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
                        Check(graph->mas[i][j], graph); //���������� ����� ������ (���� ������� ������ ������� �������)
                }
        }
}
//---------------------------------------------------------------------------