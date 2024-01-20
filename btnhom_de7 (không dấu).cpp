#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream InFile("input.txt");
    ofstream OutFile("output.txt");
    if (!InFile) return cerr<<"Khong the mo file input",1;

    int n,m;
    InFile>>n>>m;
    int a[n][m];
    int a1[n*m],a2[n*m];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) InFile>>a[i][j];

    int mode;
    cout<<"Chon che do choi"<<endl;
    cout<<"\t1/So sanh ket qua , xuat o trung"<<endl<<"\t2/Robot khong duoc di qua vi tri da di"<<endl<<"Che do : ";cin>>mode;
    while (mode!=1 && mode!=2)
    {
        cout<<"Che do khong hop le, xin chon lai : ";cin>>mode;
    }
    int x1,y1,x2,y2,t1=1,t2=1,t3=0,t4=0;
    cout<<"Nhap vi tri robot cua nguoi choi thu 1 : ";cin>>x1>>y1;
    while ((x1>n-1 || x1<0) || (y1>m-1 || y1<0))
    {
        cout<<"Vi tri cua robot thu 1 khong hop le, xin nhap lai : ";cin>>x1>>y1;
    }
    cout<<"Nhap vi tri robot cua nguoi choi thu 2 : ";cin>>x2>>y2;
    while ((x2>n-1 || x2<0) || (y2>m-1 || y2<0))
    {
        cout<<"Vi tri cua robot thu 2 khong hop le, xin nhap lai : ";cin>>x2>>y2;
    }
    a1[0]=a[x1][y1],a2[0]=a[x2][y2];
    a[x1][y1]=-1,a[x2][y2]=-1;
    if (mode==1)
    {
        int b[n][m];
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++) b[i][j]=a[i][j];
        int max=0,i,j;
        while (max!=-1)
        {
            max=-1;
            if (x1>0 && a[x1-1][y1]>max)
            {
                max=a[x1-1][y1];
                i=x1-1;j=y1;
            }
            if (x1<n-1 && a[x1+1][y1]>max)
            {
                max=a[x1+1][y1];
                i=x1+1;j=y1;
            }
            if (y1>0 && a[x1][y1-1]>max)
            {
                max=a[x1][y1-1];
                i=x1;j=y1-1;
            }
            if (y1<m-1 && a[x1][y1+1]>max)
            {
                max=a[x1][y1+1];
                i=x1;j=y1+1;
            }
            if (max!=-1)
            {
                a1[t1]=a[i][j];
                t1++;
                t3+=a[i][j];
                a[i][j]=-1;
                x1=i;y1=j;
            }
        }
        max=0;
        while (max!=-1)
        {
            max=-1;
            if (x2>0 && b[x2-1][y2]>max)
            {
                max=b[x2-1][y2];
                i=x2-1;j=y2;
            }
            if (x2<n-1 && b[x2+1][y2]>max)
            {
                max=b[x2+1][y2];
                i=x2+1;j=y2;
            }
            if (y2>0 && b[x2][y2-1]>max)
            {
                max=b[x2][y2-1];
                i=x2;j=y2-1;
            }
            if (y2<m-1 && b[x2][y2+1]>max)
            {
                max=b[x2][y2+1];
                i=x2;j=y2+1;
            }
            if (max!=-1)
            {
                a2[t2]=b[i][j];
                t2++;
                t4+=b[i][j];
                b[i][j]=-1;
                x2=i;y2=j;
            }
        }

        cout<<"Che do 1: So sanh ket qua 2 robot, xuat ra cac vi tri di trung\n";
        OutFile<<"Che do 1: So sanh ket qua 2 robot, xuat ra cac vi tri di trung\n";
        cout<<"Robot cua nguoi choi thu 1 : \n\tDi qua "<<t1<<" o\n\tTong diem : "<<t3<<"\n\tQuang duong da di : ";
        OutFile<<"Robot cua nguoi choi thu1 : \n\tDi qua "<<t1<<" o\n\tTong diem : "<<t3<<"\n\tQuang duong da di : ";
        for (i=0;i<t1;i++)
        {
            cout<<a1[i]<<" ";
            OutFile<<a1[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        cout<<"Robot cua nguoi choi thu 2 : \n\tDi qua "<<t2<<" o\n\tTong diem : "<<t4<<"\n\tQuang duong da di: ";
        OutFile<<"Robot cua nguoi choi thu 2 : \n\tDi qua "<<t2<<" o\n\tTong diem : "<<t4<<"\n\tQuang duong da di: ";
        for (i=0;i<t2;i++)
        {
            cout<<a2[i]<<" ";
            OutFile<<a2[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        if (t1>t2)
        {
            cout<<"Nguoi choi thu 1 di nhieu o hon nguoi choi thu 2"<<endl;
            OutFile<<"Nguoi choi thu 1 di nhieu o hon nguoi choi thu 2"<<endl;
        }
        else
        {
            cout<<"Nguoi choi thu 2 di nhieu o hon nguoi choi thu 1"<<endl;
            OutFile<<"Nguoi choi thu 2 di nhieu o hon nguoi choi thu 1"<<endl;
        }
        if (t3>t4)
        {
            cout<<"Nguoi choi thu 1 co tong diem lon hon nguoi choi thu 2"<<endl;
            OutFile<<"Nguoi choi thu 1 co tong diem lon hon nguoi choi thu 2"<<endl;
        }
        else
        {
            cout<<"Nguoi choi thu 2 co tong diem lon hon nguoi choi thu 1"<<endl;
            OutFile<<"Nguoi choi thu 2 co tong diem lon hon nguoi choi thu 1"<<endl;
        }
        cout<<"Cac o 2 robot deu di qua la : ";
        OutFile<<"Cac o 2 robot deu di qua la : ";
        for (i=0;i<t1;i++)
            for (j=0;j<t2;j++)
                if (a1[i]==a2[j])
                {
                    cout<<a1[i]<<" ";
                    OutFile<<a1[i]<<" ";
                }
    }
    else
    if (mode==2)
    {
        int max1=0,max2=0,i,j;
        while (max1!=-1 && max2!=-1)
        {
            max1=-1;
            max2=-1;
            if (x1>0 && a[x1-1][y1]>max1)
            {
                max1=a[x1-1][y1];
                i=x1-1;j=y1;
            }
            if (x1<n-1 && a[x1+1][y1]>max1)
            {
                max1=a[x1+1][y1];
                i=x1+1;j=y1;
            }
            if (y1>0 && a[x1][y1-1]>max1)
            {
                max1=a[x1][y1-1];
                i=x1;j=y1-1;
            }
            if (y1<m-1 && a[x1][y1+1]>max1)
            {
                max1=a[x1][y1+1];
                i=x1;j=y1+1;
            }
            if (max1!=-1)
            {
                a1[t1]=a[i][j];
                t1++;
                t3+=a[i][j];
                a[i][j]=-1;
                x1=i;y1=j;
            }
            if (x2>0 && a[x2-1][y2]>max2)
            {
                max2=a[x2-1][y2];
                i=x2-1;j=y2;
            }
            if (x2<n-1 && a[x2+1][y2]>max2)
            {
                max2=a[x2+1][y2];
                i=x2+1;j=y2;
            }
            if (y2>0 && a[x2][y2-1]>max2)
            {
                max2=a[x2][y2-1];
                i=x2;j=y2-1;
            }
            if (y2<m-1 && a[x2][y2+1]>max2)
            {
                max2=a[x2][y2+1];
                i=x2;j=y2+1;
            }
            if (max2!=-1)
            {
                a2[t2]=a[i][j];
                t2++;
                t4+=a[i][j];
                a[i][j]=-1;
                x2=i;y2=j;
            }
        }

        cout<<"Che do 2: So sanh ket qua 2 robot, cac robot khong duoc di vao o da di\n";
        OutFile<<"Che do 2: So sanh ket qua 2 robot, cac robot khong duoc di vao o da di\n";
        cout<<"Robot cua nguoi choi thu 1 : \n\tDi qua "<<t1<<" o\n\tTong diem : "<<t3<<"\n\tQuang duong da di : ";
        OutFile<<"Robot cua nguoi choi thu 1 : \n\tDi qua "<<t1<<" o\n\tTong diem : "<<t3<<"\n\tQuang duong da di : ";
        for (i=0;i<t1;i++)
        {
            cout<<a1[i]<<" ";
            OutFile<<a1[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        cout<<"Robot cua nguoi choi thu 2 : \n\tDi qua "<<t2<<" o\n\tTong diem : "<<t4<<"\n\tQuang duong da di : ";
        OutFile<<"Robot cua nguoi choi thu 2 : \n\tDi qua "<<t2<<" o\n\tTong diem : "<<t4<<"\n\tQuang duong da di : ";
        for (i=0;i<t2;i++)
        {
            cout<<a2[i]<<" ";
            OutFile<<a2[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        if (t1>t2)
        {
            cout<<"Nguoi choi thu 1 di nhieu o hon nguoi choi thu 2"<<endl;
            OutFile<<"Nguoi choi thu 1 di nhieu o hon nguoi choi thu 2"<<endl;
        }
        else
        {
            cout<<"Nguoi choi thu 2 di nhieu o hon nguoi choi thu 1"<<endl;
            OutFile<<"Nguoi choi thu 2 di nhieu o hon nguoi choi thu 1"<<endl;
        }
        if (t3>t4)
        {
            cout<<"Nguoi choi thu 1 co tong diem lon hon nguoi choi thu 2"<<endl;
            OutFile<<"Nguoi choi thu 1 co tong diem lon hon nguoi choi thu 2"<<endl;
        }
        else
        {
            cout<<"Nguoi choi thu 2 co tong diem lon hon nguoi choi thu 1"<<endl;
            OutFile<<"Nguoi choi thu 2 co tong diem lon hon nguoi choi thu 1"<<endl;
        }
    }
    InFile.close();
    OutFile.close();
}
