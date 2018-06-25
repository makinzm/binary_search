#include <stdio.h>

//グローバル変数
int n;
int k;
int A[100000];

//各時間の仕事をk個に分割でき,それが仕事量m以下に抑えられるかどうかを返す
int p(int m){
  //ローカル変数
  int c = 0;
  int s = 0;
  int i;
  for(i = 0; i < n; i++){
      //k個に分割できているかどうかを場合分け
      if(c <= k - 1){
          //分割された仕事量がm以下かどうかを場合分け
          if(s + A[i] <= m){
              s = s + A[i];
          }
          else{
              //一時間分の仕事がm以下かどうかを場合分け
              if(A[i] <= m){
                  s = A[i];
                  c = c + 1;
              }
              else{
                  c = k;
              }
          }
      }
      else{
          c = k;
      }
  }
  return c  <= k - 1;
}

int main(){
//ローカル変数
int i, lb, ub;
//標準入力から整数を2つ読み込みnとkに代入
scanf("%d%d", &n, &k);
for(i = 0; i < n; i++){
  //標準状態から整数を一つ読み込みA[i]に代入
  scanf("%d", &A[i]);
}
//二分探索
lb = 0;
ub = 1000000000;
while(ub - lb > 1){
    int m = (lb + ub)/2;
    if(p(m)){
        ub = m;
    }
    else{
        lb = m;
    }
}
//標準出力へ整数nと改行コード\nを出力
printf("%d\n",ub);
return 0;
}
