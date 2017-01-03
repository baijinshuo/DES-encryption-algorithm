#include<stdio.h>
#include<stdlib.h>
void input(int m2[8],int k2[10]);
void IP(int m0[8]);
void IP1(int m0[8]);
void P10(int k0[10]);
void shift(int k0[10]);
void P8(int k0[8]);
void fK(int m0[8],int sk[4]);
void F(int r[4],int sk[8]);
void exchange(int r2[4]);
void swap(int array[8]);
void output();
void jiami();
void jiemi();
int m[8],k[10],sk1[8],sk2[8];
int s0[4][4]={{1,0,3,2},{3,2,1,0},{0,2,1,3},{3,1,3,2}};
int s1[4][4]={{0,1,2,3},{2,0,1,3},{3,0,1,0},{2,1,0,3}};
int main()
{
    int z;
    printf("请选择操作：1加密，2解密");
    scanf("%d",&z);
    if(z=1)
        jiami();
    else if(z=2)
        jiemi();
    else
    printf("输入错误"); 
    getchar();
    putchar(getchar());
    return 0;
}
void jiami()
{
    int j;
    input(m,k);
    P10(k);
    shift(k);
    for(j=0;j<8;j++)
        sk1[j]=k[j+2];
    P8(sk1);
    shift(k);
    shift(k);
    for(j=0;j<8;j++)
        sk2[j]=k[j+2];
    P8(sk2);
    IP(m);
    fK(m,sk1);
    swap(m);
    fK(m,sk2);
    IP1(m); 
    output();
}
void jiemi()
{
    int j;
    input(m,k);
    P10(k);
    shift(k);
    for(j=0;j<8;j++)
        sk1[j]=k[j+2];
    P8(sk1);
    shift(k);
    shift(k);
    for(j=0;j<8;j++)
        sk2[j]=k[j+2];
    P8(sk2);
    IP(m);
    fK(m,sk2);
    swap(m);
    fK(m,sk1);
    IP1(m); 
    output();
}
void input(int m2[8],int k2[10])
{
    int i;
    int m1,k1;
    printf("请输入8位明（密）文：（仅支持二进制输入）");
    scanf("%d",&m1);
    for(i=7;i>=0;i--)
    {
         m2[i]=m1%10;
         m1=m1/10;
    } 
    printf("请输入10位密钥：");
    scanf("%d",&k1);
    for(i=9;i>=0;i--)
    {
         k2[i]=k1%10;
         k1=k1/10;
    }
}       
void IP(int m0[8])
{
    int m1[8];
    int i;
    m1[0]=m0[1];
    m1[1]=m0[5];
    m1[2]=m0[2];
    m1[3]=m0[0];
    m1[4]=m0[3];
    m1[5]=m0[7];
    m1[6]=m0[4];
    m1[7]=m0[6];
    for(i=0;i<8;i++)
        m0[i]=m1[i];
}
void IP1(int m0[8])
{
    int m1[8];
    int i;
    m1[0]=m0[3];
    m1[1]=m0[0];
    m1[2]=m0[2];
    m1[3]=m0[4];
    m1[4]=m0[6];
    m1[5]=m0[1];
    m1[6]=m0[7];
    m1[7]=m0[5];
    for(i=0;i<8;i++)
        m0[i]=m1[i];
}
     
void P10(int k0[10])
{
    int k1[10];
    int i;
    k1[0]=k0[2];
    k1[1]=k0[4];
    k1[2]=k0[1];
    k1[3]=k0[6];
    k1[4]=k0[3];
    k1[5]=k0[9];
    k1[6]=k0[0];
    k1[7]=k0[8];
    k1[8]=k0[7];
    k1[9]=k0[5];
    for(i=0;i<10;i++)
        k0[i]=k1[i];
}
void shift(int k0[10])
{
     int temp,i;
     temp=k0[0];
     for(i=0;i<4;i++)
         k0[i]=k0[i+1];
     k0[4]=temp;
     temp=k0[5];
     for(i=5;i<9;i++)
         k0[i]=k0[i+1];
     k0[9]=temp;
}
void P8(int k0[8])
{
    int i;
    int k1[8];
    k1[0]=k0[3];
    k1[1]=k0[0];
    k1[2]=k0[4];
    k1[3]=k0[1];
    k1[4]=k0[5];
    k1[5]=k0[2];
    k1[6]=k0[7];
    k1[7]=k0[6];
    for(i=0;i<8;i++)
        k0[i]=k1[i];
}
void fK(int m0[8],int sk[8])
{
    int b[4],c[8];
    int i;
    for(i=0;i<4;i++)
        {b[i]=m0[i+4];//右半部分 
        c[i+4]=m0[i+4];}//右半部分 
    F(b,sk);
    for(i=0;i<4;i++)
    c[i]=b[i]^m0[i];
    for(i=0;i<8;i++)
        m0[i]=c[i];
}
void F(int r[4],int sk[8])
{
    int i;
    int r0[8],r1[4];
    int p,q,t,s;
    r0[0]=r[3]^sk[0];
    r0[1]=r[0]^sk[1];
    r0[2]=r[1]^sk[2];
    r0[3]=r[2]^sk[3];
    r0[4]=r[1]^sk[4];
    r0[5]=r[2]^sk[5];
    r0[6]=r[3]^sk[6];
    r0[7]=r[0]^sk[7];
    p=2*r0[0]+r0[3];
    q=2*r0[1]+r0[2];
    t=s0[p][q];
    p=2*r0[4]+r0[7];
    q=2*r0[5]+r0[6];
    s=s1[p][q];
    r1[0]=t/2;
    r1[1]=t%2;
    r1[2]=s/2;
    r1[3]=s%2;
    exchange(r1);
    for(i=0;i<4;i++)
        r[i]=r1[i];
}
void exchange(int r2[4])
{
    int i;
    int r3[4];
    r3[0]=r2[1];
    r3[1]=r2[3];
    r3[2]=r2[2];
    r3[3]=r2[0];
    for(i=0;i<4;i++)
        r2[i]=r3[i];
}
void swap(int array[8])
{
    int i;
    int array0[8];
    for(i=0;i<4;i++)
    {
        array0[i]=array[1+4];
        array0[i+4]=array[i];
    }
    for(i=0;i<8;i++)
        array[i]=array0[i];
}
void output()
{
    int i;
    printf("加密后密文为：");
    for(i=0;i<8;i++)
        printf("%d ",m[i]);
}













