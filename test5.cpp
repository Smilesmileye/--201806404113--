public class Test9{
	public void Package(int c,int n,int w[],int v[]){
		int[][] m =new int[n+1][c+1];
		int[] x=new int[n+1];
		for(int i=0;i<=n;i++){
			m[i][0]=0;
		}
		for(int i=0;i<=c;i++){
			m[0][i]=0;
		}
		for(int i=1;i<=c;i++){
			if(w[1]>i){
				m[1][i]=0;
			}else{
				m[1][i]=v[1];
			}
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j<=c;j++){
				if(w[i]>j){
					m[i][j]=m[i-1][j];
				}else{
					int a=m[i-1][j];
					int b=m[i-1][j-w[i]]+v[i];
					m[i][j]=a>b?a:b;
				}
			}
		}
		int cc =c;
		for(int k=1;k<=n;k++){
			if(m[k][cc]==m[k-1][cc]){
				x[k]=0;
			}else{
				x[k]=1;
				cc -=w[k];
			}
		}
		for(int i=1;i<=n;i++){
			System.out.print(x[i]+" ");
		}
	}
}
