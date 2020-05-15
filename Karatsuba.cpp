#include<iostream>
#include<string>
using namespace std;

int pad(string &a, string &b)
{
	int len = max(a.size(), b.size());
	string x(len - a.size(), '0'), y(len - b.size(), '0');
	a = x + a, b = y + b;
	return len;
}

string add(string x, string y, int shiftSecond = 0, int sub = 0) {
	int carry = 0;
	if (shiftSecond) y = y + string(shiftSecond, '0');
	int n = pad(x, y);
	if (sub) {
		for (int i = 0; i < y.size(); i++){
			y[i] = (y[i] == '1' ? '0' : '1');
		}
		carry = 1;
	}
	string ans(n, '0');
	for (int i = n - 1; i >= 0; i--) {
		int r = carry ^ (x[i] - '0') ^ (y[i] - '0');
		int s = carry + (x[i] - '0') + (y[i] - '0');
		ans[i] = (r == 0 ? '0' : '1');
		carry = (s >= 2 ? 1 : 0);
	}
	if (!sub && carry) ans = '1' + ans;
	return ans;
}

string multiply(string x, string y) {
	int n = pad(x, y);
	if (n == 0) return "";
	if (n == 1) {
		return to_string((x[0] - '0') * (y[0] - '0'));
	}
	int mid = n - n/2;
	string xl = x.substr(0, mid),
	xr = x.substr(mid),
	yl = y.substr(0, mid),
	yr = y.substr(mid);

	string A = multiply(xl, yl), B = multiply(xr, yr), C = multiply(add(xl, xr), add(yl, yr));
	string ans(2*n, '0');
	ans = add(ans, B);
	ans = add(ans, A, 2 * (n - mid));
	C = add(C, add(A, B), 0, 1);
	ans = add(ans, C, n - mid);
	return ans;
}

int main() {
	string x, y;
	cout<<"Enter 1st binary number: "; cin>>x;
	cout<<"Enter 2nd binary number: "; cin>>y;
	string ans = multiply(x, y);
	ans.erase(0, ans.find_first_not_of('0'));
	cout<<"Binary multiplication using divide and conquer: "<< ans;
}