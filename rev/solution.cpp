#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define INF (int)(1e9+7)
#define PI acos(-1)
#define F first
#define S second
#define _QWORD unsigned long long

ll powf(ll a,ll b){
//    return powl(a,b) ;
    if(b == 0)return 1LL ;
    else if(b&1){
        return powf(a,b/2)*powf(a,b/2)*a ;
    }else{
        return powf(a,b/2)*powf(a,b/2) ;
    }
}

ll tick4(ll a,ll b){
    return a/b;
}

ll tick3(ll a,ll b){
    return a-b;
}
ll tick5(ll a,ll b){
    return powf(b,a) ;
    /// here i replaced powl with a fast exponensiation function powf
}
ll tick6(ll a,ll b){
    return a+b;
}
ll tick7(ll a,ll b){
    return a*b;
}

int  main()
{
freopen("out.out","w",stdout) ;
  ll v4 = 0 ; // [sp+0h] [bp-30h]@0
  ll v5 = 0 ; // [sp+8h] [bp-28h]@0
  ll v6 = 0 ; // [sp+10h] [bp-20h]@0
  ll v7 = 0 ; // [sp+18h] [bp-18h]@0
  ll v8 = 0 ; // [sp+20h] [bp-10h]@1
  ll i; // [sp+28h] [bp-8h]@1

  printf(
    "This is your ticket to travel to Canda !\n"
    "All what you have to do is to wait until the flag is displayed !\n"
    "Trust me !");
  v8 = 0LL;
  for ( i = 0LL; i <= 1193046; ++i )
  {
    v7 = tick4(i, 41LL);
    v6 = tick5(v7, 3LL);
    v5 = tick6(v6, v8);
    v4 = tick7(v5, i);
    v8 = v4%18364757930599072000LL ;
//    printf("iteration : %d\n",i);
  }
  printf("Thank you for your patience ! Here is the flag: hackfest{%u}\n", v8);
  return 0;
}

