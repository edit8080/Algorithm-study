﻿/*
* 1. n>=4 부터 새로운 조각이 생성된다.
*    새롭게 생성되는 조각은 0~n-4 에서 나오는 경우의 수의 합과 같다.(ex) (n-4)|=|, (n-6)|==|, (n-8)|===| ...)
* 2. 기존 타일은 뒤에 3가지가 올 수 있다.(=,||)
* 3. 새롭게 생성되는 조각은 2가지가 가능하다. (1번에서 나오는 조각의 위, 아래에 선)
*
* 시간복잡도 = O(n^2) (n : 벽의 크기)
*/

#include <iostream>

using namespace std;

int main()
{
	int n;
	int tile[31] = { 0 };
	int ret = 0;

	cin >> n;

	tile[0] = 1;
	tile[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		// 새롭게 생성되는 조각 앞에 오는 것들 ex) (n-4)|=|, (n-6)|==|, (n-8)|===| ...
		for (int j = 4; j <= i; j += 2)
			ret += tile[i - j];

		// 기존 타일은 뒤에 3가지가 올 수 있음(=,||) , 새롭게 생성되는 조각은 2가지가 가능함 (위, 아래에 선)
		tile[i] = 3 * tile[i - 2] + 2 * ret;
		ret = 0;
	}

	cout << tile[n];
}