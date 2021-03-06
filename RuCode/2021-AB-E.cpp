#include<bits/stdc++.h>
using namespace::std;

int gcd(int a, int b){
	while(b){
		a %= b;
		swap(a, b);
	}
	return a;
}

int mcm(int a, int b){
	return a * b / gcd(a, b);
}


int a, b, c;
long long L, R;

long long g(long long x){
	return (x + a - 1) / a + (x + b - 1) / b + (x + c - 1) / c;	
}

long long f(long long x){
	int M = mcm(a, mcm(b, c));
	int val = M - (M / a + M / b + M / c);
	long long ans = 0;
	for(int R = 0; R < M; R++){
		if(R > x) break;
		int extra = 0;
		extra += (R + a - 1) / a;
		extra += (R + b - 1) / b;
		extra += (R + c - 1) / c;
		long long maxK = (x - R) / M;
		if(val == 0){
			if(R >= extra) ans += maxK + 1;
		}
		else if(val > 0){
			long long minK = max(0, (extra - R + val - 1) / val);
			if(minK <= maxK) ans += maxK - minK + 1;
		}
		else if(R - extra >= 0){
			long long maxK2 = (R - extra) / val;
			maxK = min(maxK, maxK2);
			ans += maxK + 1;
		}
	}
	return ans;
}

int main(){
	scanf("%d %d %d", &a, &b, &c);
	scanf("%lld %lld", &L, &R);
	printf("%lld\n", f(R) - f(L - 1));
	return 0;
}
