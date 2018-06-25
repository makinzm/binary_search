#include <stdio.h>

//グローバル変数
int n;
int k;
int A[100000];

//m個のりんごが入るりんごバックを合計k個配ると持って帰れるかどうかを返す
int p(int m){
 //ローカル変数
 int i;
 int l = 0;
 for(i = 0; i < n; i++){
   l = l + 1 + (A[i]-1)/m;
 }
 return k >= l;
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
   int m = (lb + ub) / 2;
   if (p(m)){
     ub = m;
   }
   else {
     lb = m;
   }
 }
 //標準出力へ整数nと改行コード\nを出力
 printf("%d\n", ub);
 return 0;
}
