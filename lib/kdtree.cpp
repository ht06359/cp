template<int K>
struct kdtree {
  kdtree *l = nullptr, *r = nullptr;
  int xmin = 1000000009, xmax = 1000000009, ymin = 1000000009, ymax = 1000000009, siz = 0;
  kdtree<K>(vector<pair<int,int>>::iterator bgn, vector<pair<int,int>>::iterator nd, bool by_x = true) {
    for (auto p = bgn; p != nd; p++) {
      auto [x, y] = *p;
      xmin = min(xmin, x);xmax = max(xmax, x);
      ymin = min(ymin, y);ymax = max(ymax, y);
    }
    siz = int(nd-bgn);
    if (siz <= 1) return;
    auto cen = bgn + siz / 2;
    if (by_x) {
      nth_element(bgn, cen, nd, [](pair<int,int> a, pair<int,int> b) {
        return a.first < b.first;
      });
    } else {
      nth_element(bgn, cen, nd, [](pair<int,int> a, pair<int,int> b) {
        return a.second < b.second;
      });
    }
    l = new kdtree<K>(bgn, cen, !by_x);
    r = new kdtree<K>(cen, nd, !by_x);
  }
  int count(int x1, int x2, int y1, int y2) const {
    if (x2 < xmin || xmax < x1 || y2 < ymin || ymax < y1) return 0;
    if (x1 <= xmin && xmax <= x2 && y1 <= ymin && ymax <= y2) return siz;
    return l->count(x1, x2, y1, y2) + r -> count(x1, x2, y1, y2);
  }
};