#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream InFile("input.txt");
    ofstream OutFile("output.txt");
    if (!InFile) return cerr<<"Không thể mở file input",1;

    int n,m;
    InFile>>n>>m;
    int a[n][m];
    int a1[n*m],a2[n*m];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) InFile>>a[i][j];

    int mode;
    cout<<"Chọn chế độ chơi"<<endl;
    cout<<"\t1/So sánh kết quả , xuất ô trùng"<<endl<<"\t2/Robot không được đi qua vị trí đã đi"<<endl<<"Chế độ : ";cin>>mode;
    while (mode!=1 && mode!=2)
    {
        cout<<"Chế độ không hợp lệ, xin chọn lại : ";cin>>mode;
    }
    int x1,y1,x2,y2,t1=1,t2=1,t3=0,t4=0;
    cout<<"Nhập vị trí robot của người chơi thứ 1 : ";cin>>x1>>y1;
    while ((x1>n-1 || x1<0) || (y1>m-1 || y1<0))
    {
        cout<<"Vị trí của robot thứ 1 không hợp lệ , xin nhập lại : ";cin>>x1>>y1;
    }
    cout<<"Nhập vị trí robot của người chơi thứ 2 : ";cin>>x2>>y2;
    while ((x2>n-1 || x2<0) || (y2>m-1 || y2<0))
    {
        cout<<"Vị trí của robot thứ 2 không hợp lệ , xin nhập lại : ";cin>>x2>>y2;
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

        cout<<"Chế độ 1 : So sánh kết quả 2 robot , xuất ra các vị trí đi trùng\n";
        OutFile<<"Chế độ 1 : So sánh kết quả 2 robot , xuất ra các vị trí đi trùng\n";
        cout<<"Robot của người chơi thứ 1 : \n\tĐi qua "<<t1<<" ô\n\tTổng điểm : "<<t3<<"\n\tQuảng đường đã đi : ";
        OutFile<<"Robot của người chơi thứ 1 : \n\tĐi qua "<<t1<<" ô\n\tTổng điểm : "<<t3<<"\n\tQuảng đường đã đi : ";
        for (i=0;i<t1;i++)
        {
            cout<<a1[i]<<" ";
            OutFile<<a1[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        cout<<"Robot của người chơi thứ 2 : \n\tĐi qua "<<t2<<" ô\n\tTổng điểm : "<<t4<<"\n\tQuảng đường đã đi : ";
        OutFile<<"Robot của người chơi thứ 2 : \n\tĐi qua "<<t2<<" ô\n\tTổng điểm : "<<t4<<"\n\tQuảng đường đã đi : ";
        for (i=0;i<t2;i++)
        {
            cout<<a2[i]<<" ";
            OutFile<<a2[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        if (t1>t2)
        {
            cout<<"Người chơi thứ 1 đi nhiều ô hơn người chơi thứ 2"<<endl;
            OutFile<<"Người chơi thứ 1 đi nhiều ô hơn người chơi thứ 2"<<endl;
        }
        else
        {
            cout<<"Người chơi thứ 2 đi nhiều ô hơn người chơi thứ 1"<<endl;
            OutFile<<"Người chơi thứ 2 đi nhiều ô hơn người chơi thứ 1"<<endl;
        }
        if (t3>t4)
        {
            cout<<"Người chơi thứ 1 có tổng điểm lớn hơn người chơi thứ 2"<<endl;
            OutFile<<"Người chơi thứ 1 có tổng điểm lớn hơn người chơi thứ 2"<<endl;
        }
        else
        {
            cout<<"Người chơi thứ 2 có tổng điểm lớn hơn người chơi thứ 1"<<endl;
            OutFile<<"Người chơi thứ 2 có tổng điểm lớn hơn người chơi thứ 1"<<endl;
        }
        cout<<"Các ô 2 robot đều di qua là : ";
        OutFile<<"Các ô 2 robot đều di qua là : ";
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

        cout<<"Chế độ 2 : So sánh kết quả 2 robot , các robot không được đi vào ô đã đi\n";
        OutFile<<"Chế độ 2 : So sánh kết quả 2 robot , các robot không được đi vào ô đã đi\n";
        cout<<"Robot của người chơi thứ 1 : \n\tĐi qua "<<t1<<" ô\n\tTổng điểm : "<<t3<<"\n\tQuảng đường đã đi : ";
        OutFile<<"Robot của người chơi thứ 1 : \n\tĐi qua "<<t1<<" ô\n\tTổng điểm : "<<t3<<"\n\tQuảng đường đã đi : ";
        for (i=0;i<t1;i++)
        {
            cout<<a1[i]<<" ";
            OutFile<<a1[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        cout<<"Robot của người chơi thứ 2 : \n\tĐi qua "<<t2<<" ô\n\tTổng điểm : "<<t4<<"\n\tQuảng đường đã đi : ";
        OutFile<<"Robot của người chơi thứ 2 : \n\tĐi qua "<<t2<<" ô\n\tTổng điểm : "<<t4<<"\n\tQuảng đường đã đi : ";
        for (i=0;i<t2;i++)
        {
            cout<<a2[i]<<" ";
            OutFile<<a2[i]<<" ";
        }
        cout<<endl;
        OutFile<<endl;
        if (t1>t2)
        {
            cout<<"Người chơi thứ 1 đi nhiều ô hơn người chơi thứ 2"<<endl;
            OutFile<<"Người chơi thứ 1 đi nhiều ô hơn người chơi thứ 2"<<endl;
        }
        else
        {
            cout<<"Người chơi thứ 2 đi nhiều ô hơn người chơi thứ 1"<<endl;
            OutFile<<"Người chơi thứ 2 đi nhiều ô hơn người chơi thứ 1"<<endl;
        }
        if (t3>t4)
        {
            cout<<"Người chơi thứ 1 có tổng điểm lớn hơn người chơi thứ 2"<<endl;
            OutFile<<"Người chơi thứ 1 có tổng điểm lớn hơn người chơi thứ 2"<<endl;
        }
        else
        {
            cout<<"Người chơi thứ 2 có tổng điểm lớn hơn người chơi thứ 1"<<endl;
            OutFile<<"Người chơi thứ 2 có tổng điểm lớn hơn người chơi thứ 1"<<endl;
        }
    }
    InFile.close();
    OutFile.close();
}
