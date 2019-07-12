
#include <iostream>
typedef long long ll;

const int MAX = 200005;
int ans[MAX]; int cnt;
using namespace  std;
struct Line
{

	Line() {};
	ll x;
	ll y;
	bool on_the_right(ll x1, ll y1) {
		//叉积看是否在p0_p1右侧
		return((-x * y1) - (y * (x1 - x))) > 0;
	}
	Line(int a, int b) :x(a), y(b) {};
	friend int bin_search(int lo, int hi);
}lin[MAX];

int bin_search(int lo, int hi, int tem_x, int tem_y) {
	//while二分法
	while (lo<=hi)
	{
		int mi = (lo + hi) >> 1;
		if (lin[mi].on_the_right(tem_x, tem_y))hi = mi - 1; else
		{
			lo = mi + 1;
		}

	}
	
	return lo - 1;
	
	if (hi - lo < 0)return lo-1;
	int mi = (lo + hi) >> 1;
	//return lin[mi].on_the_right(tem_x, tem_y) ? bin_search(mi + 1, hi, tem_x, tem_y) : bin_search(lo, mi, tem_x, tem_y);
	return lin[mi].on_the_right(tem_x, tem_y) ? bin_search(lo, mi - 1, tem_x, tem_y) : bin_search(mi + 1, hi, tem_x, tem_y);
}


int main()
{
	// init action
	int n, m; int tem_x, tem_y;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{

		cin >> tem_x >> tem_y;
		lin[i] = Line(tem_x, tem_y);
	}
	int m2 = m;
	// m action
	while (m--)
	{
		cin >> tem_x >> tem_y;
		cout<< bin_search(1, n, tem_x, tem_y)<<'\n';
	}
	/*for (int i = 0; i < m2; i++)
	{
		cout << ans[i] << endl;
	}*/


}

