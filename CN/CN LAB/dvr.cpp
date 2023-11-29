#include<iostream>
using namespace std;
 
int main()
{
    int graph[50][50];
    int i,j,k,t;
    int nn;
 
    cout<<"\n Enter Number of Nodes:";
    cin>>nn;
 
    /* Initialize graph*/
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            graph[i][j]=-1;
        }
    }
 
    /* Vertex names */
    char ch[7]={'A','B','C','D','E','F','G'};
 
    /* Get input */
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            if(i==j)
            {
                graph[i][j]=0;
            }
            if(graph[i][j]==-1)
            {
                cout<<"\n Enter Distance between "<<ch[i]<<" - "<<ch[j]<<" : ";
                cin>>t;
                graph[i][j]=graph[j][i]=t;
            }
        }
    }
 
    /* Initializing via */
    int via[50][50];
    for (i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            via[i][j]=-1;
        }
    }
 
    cout<<"\n After Initialization";
    /* Display table initialization */
    for (i=0;i<nn;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<graph[i][j]<<"\t"<<via[i][j];
        }
    }
 
    //sharing table
    int sh[50][50][50];
    for(i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            for (k=0;k<nn;k++)
            {
                /* Check if edge is present or not*/
                if((graph[i][j]>-1)&&(graph[j][k]>-1))
                {
                    sh[i][j][k]=graph[j][k]+graph[i][j];
                }
                else
                {
                    sh[i][j][k]=-1;
                }
            }
        }
    }
 
    /*displaying shared table */
    for(i=0;i<nn;i++)
    {
        cout<<"\n\n For "<<ch[i];
        for (j=0;j<nn;j++)
        {
            cout<<"\n From "<<ch[j];
            for(k=0;k<nn;k++)
            {
                cout<<"\n "<<ch[k]<<" "<<sh[i][j][k];
            }
        }
    }
     
    /* Updating */
    int final[50][50];
    for(i=0;i<nn;i++)
    {
        for(j=0;j<nn;j++)
        {
            /* Copy initial value from input graph*/
            final[i][j]=graph[i][j];
            via[i][j]=i;
             
            /*Update them*/
            /* Check condition a - b - c */
            for(k=0;k<nn;k++)
            {
                 
                if((final[i][j]>sh[i][k][j]) || (final[i][j] == -1))
                {
                    if(sh[i][k][j]>-1)
                    {
                        final[i][j]=sh[i][k][j];
                        via[i][j]=k;
                    }
                }
            }
            /* After considering three vertex if final not found 
                consider 4th
                a- b- c- d
            */
 
            if(final[i][j]==-1)
            {
                for(k=0;k<nn;k++)
                {
 
                    if((final[i][k]!=-1)&&(final[k][j]!=-1))
                    {
                        if((final[i][j]==-1) || ((final[i][j]!=-1) &&(final[i][j]>final[i][k]+final[k][j]))) 
                        {
                            if(final[i][k]+final[k][j]>-1)
                            {
                                final[i][j]=final[i][k]+final[k][j];
                                via[i][j]=k;
                            }
                        }
                    }
                     
                }
            }
        }
    }
 
    cout<<"\n After Update :";
    /* Display table Updation */
    for (i=0;i<nn;i++)
    {
        cout<<"\n"<<ch[i]<<" Table";
        cout<<"\nNode\tDist\tVia";
        for(j=0;j<nn;j++)
        {
            cout<<"\n"<<ch[j]<<"\t"<<final[i][j]<<"\t";
            if(i==via[i][j])
                cout<<"-";
            else
                cout<<ch[via[i][j]];
        }
    }

}



/*
OP :
 Enter Number of Nodes:4

 Enter Distance between A - B : 5

 Enter Distance between A - C : 5

 Enter Distance between A - D : 1

 Enter Distance between B - C : 3

 Enter Distance between B - D : 1

 Enter Distance between C - D : 3

 After Initialization
A Table
Node    Dist    Via
A       0       -1
B       5       -1
C       5       -1
D       1       -1
B Table
Node    Dist    Via
A       5       -1
B       0       -1
C       3       -1
D       1       -1
C Table
Node    Dist    Via
A       5       -1
B       3       -1
C       0       -1
D       3       -1
D Table
Node    Dist    Via
A       1       -1
B       1       -1
C       3       -1
D       0       -1

 For A
 From A
 A 0
 B 5
 C 5
 D 1
 From B
 A 10
 B 5
 C 8
 D 6
 From C
 A 10
 B 8
 C 5
 D 8
 From D
 A 2
 B 2
 C 4
 D 1

 For B
 From A
 A 5
 B 10
 C 10
 D 6
 From B
 A 5
 B 0
 C 3
 D 1
 From C
 A 8
 B 6
 C 3
 D 6
 From D
 A 2
 B 2
 C 4
 D 1

 For C
 From A
 A 5
 B 10
 C 10
 D 6
 From B
 A 8
 B 3
 C 6
 D 4
 From C
 A 5
 B 3
 C 0
 D 3
 From D
 A 4
 B 4
 C 6
 D 3

 For D
 From A
 A 1
 B 6
 C 6
 D 2
 From B
 A 6
 B 1
 C 4
 D 2
 From C
 A 8
 B 6
 C 3
 D 6
 From D
 A 1
 B 1
 C 3
 D 0
 After Update :
A Table
Node    Dist    Via
A       0       -
B       2       D
C       4       D
D       1       -
B Table
Node    Dist    Via
A       2       D
B       0       -
C       3       -
D       1       -
C Table
Node    Dist    Via
A       4       D
B       3       -
C       0       -
D       3       -
D Table
Node    Dist    Via
A       1       -
B       1       -
C       3       -
D       0       -
--------------------------------
/*
