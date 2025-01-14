/**
 * Description: Returns edges of Gomory-Hu tree (second element is weight). 
 	* Max flow between pair of vertices of undirected graph is given by min edge
	* weight along tree path. Uses the fact that for any $i,j,k,$
	* $\lambda_{ik}\ge \min(\lambda_{ij},\lambda_{jk}),$ 
	* where $\lambda_{ij}$ denotes the flow between $i$ and $j.$
 * Source: https://github.com/koosaga/DeobureoMinkyuParty/blob/master/teamnote.tex
 * Time: $O(N)$ calls to Dinic
 * Verification: https://codeforces.com/problemset/problem/343/E
 */

#include "Dinic.h"

struct GomoryHu {
	V<pair<pi,int>> ed; // add undirected edge
	void ae(int a, int b, int c) { ed.pb({{a,b},c}); }
	V<pair<pi,int>> init(int N) { 
		vpi ret(N); Dinic D; D.init(N);
		each(t,ed) D.ae(t.f.f,t.f.s,t.s,t.s);
		FOR(i,1,N) {
			D.reset(); ret[i].s = D.maxFlow(N,i,ret[i].f);
			FOR(j,i+1,N+1) if (ret[j].f == ret[i].f 
				&& D.lev[j] != -1) ret[j].f = i;
		}
		V<pair<pi,int>> res;
		FOR(i,1,N) res.pb({{i,ret[i].f},ret[i].s});
		return res;
	}
};
