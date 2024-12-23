vector<array<ll, 3>> manhattanMST(vector<Point> ps) {
    vector<int> id(sz(ps));
    iota(all(id), 0);
    vector<array<ll, 3>> edges;
    for (int k = 0; k < 4; k++) {
            sort(all(id), [&](int i, int j) { return (ps[i] - ps[j]).x < (ps[j] - ps[i]).y; });
            map<int, int> sweep;
            for (int i : id) {
                for (auto it = sweep.lower_bound(-ps[i].y);
                    it != sweep.end(); sweep.erase(it++)) {
                    int j = it->second;
                    Point d = ps[i] - ps[j];
                    if (d.y > d.x) break;
                    edges.push_back({d.y + d.x, i, j});
                }
                sweep[-ps[i].y] = i;
            }
            for (Point &p : ps)
                if (k & 1)
                    p.x = -p.x;
                else
                    swap(p.x, p.y);
    }
    return edges;
}