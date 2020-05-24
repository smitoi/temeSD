#include <bits/stdc++.h>

/// https://www.infoarena.ro/problema/alibaba

using	namespace std;

stack<int>	s;
char		nr[10001];
int			n, k, r[10001];
ifstream	f("alibaba.in");
ofstream	g("alibaba.out");

int	main()
{
	f >> n >> k;
	f >> nr;
	
	for (int i = 0; i < n; i++)
	{
		if (s.empty())
			s.push(nr[i] - '0');
		else
		{
			while (!s.empty() && (nr[i] - '0') > s.top() && k)
			{
				s.pop();
				k--;
			}
			s.push(nr[i] - '0');
		}
	}
	
	while (k--)
		s.pop();
	
	k = 0;
	while (!s.empty())
	{
		r[k] = s.top();
		k++;
		s.pop();
	}
	
	for (int i = (k - 1); i >= 0; i--)
		g << r[i];
	
	return 0;
}
