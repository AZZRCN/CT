//������������кܶ�+1��-1��Щ����������Ͳ�ַ�ʽ�뻭�����귽���й�ϵ
//���ڸ���˼άϰ�ߣ�����ο�һ�£�Ȼ������Լ����Լ��ķ�ʽдһ�� 
#include<bits/stdc++.h>
using namespace std;
const int N=1005;
typedef long long ll;
struct mat{
	int x1,y1,x2,y2;
}a[N];
int num[4*N],cnt;
int b[4*N][4*N];
int n;
int main(){
	cin>>n;
	for(int i=1;i<=n;++i){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y2,&a[i].x2,&a[i].y1);//����y1��y2�����˺��壬����Ϊ����x1<x2,y1<y2�������� 
		num[++cnt]=a[i].x1;
		num[++cnt]=a[i].y1;
		num[++cnt]=a[i].x2;
		num[++cnt]=a[i].y2;
	}
	sort(num+1,num+cnt+1);
	cnt=unique(num+1,num+cnt+1)-num-1;
	for(int i=1;i<=n;++i){
		int x1=lower_bound(num+1,num+cnt+1,a[i].x1)-num;
		int x2=lower_bound(num+1,num+cnt+1,a[i].x2)-num;
		int y1=lower_bound(num+1,num+cnt+1,a[i].y1)-num;
		int y2=lower_bound(num+1,num+cnt+1,a[i].y2)-num;
		--x2;//���������ת������Ŀ����������ϵ�ϵ����㣬������ϣ����ֱ�Ӽ����ڸ����ϣ����Ƶ�̺�Ǹ��⣩ 
		--y2;
		b[x2+1][y2+1]+=1;//��ά��� 
		b[x2+1][y1]-=1;
		b[x1][y1]+=1;
		b[x1][y2+1]-=1;
	}
	for(int i=1;i<=cnt;++i){//��ԭһ�� 
		for(int j=1;j<=cnt;++j){
			b[i][j]+=b[i][j-1];
		}
	}
	for(int i=1;i<=cnt;++i){//�ٻ�ԭһ�� 
		for(int j=1;j<=cnt;++j){
			b[i][j]+=b[i-1][j];
		}
	}
	long long ans=0;
	for(int i=1;i<=cnt;++i){
		for(int j=1;j<=cnt;++j){//����������ˣ��Ͱ�������ε�������뵽�����档 
			if(b[i][j]>0) ans+=((ll)num[i+1]-num[i])*((ll)num[j+1]-num[j]);
		}
	}
	cout<<ans;
	return 0;
}
