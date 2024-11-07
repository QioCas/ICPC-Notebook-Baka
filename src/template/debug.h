void debug_utils() {}

template<class T, class ...U> void debug_utils(T a, U... b) {
    cerr << a;
    if(sizeof...(b)) { cerr << ", "; debug_utils(b...);}
}

#define debug(...) { cerr << #__VA_ARGS__ << " = "; debug_utils(__VA_ARGS__); cerr << "\n"; }

template<class Tp1, class Tp2>
ostream& operator << (ostream& cout, pair<Tp1, Tp2> val) {
    return cout << val.first << " " << val.second << "\n";
}

template<class Data, class Tp = decltype(declval<Data>().begin())>
typename enable_if<!is_same<Data, string>::value, ostream&>::type
operator << (ostream& cout, Data val) {
    cout << "[";
    for(auto i = val.begin(); i != val.end(); ++i)
        cout << (i == val.begin() ? "" : " ") << *i;
    return cout << "]";
}

template<class Data, class = decltype(declval<Data>().top())> ostream& operator << (ostream& cout, Data val) {
    cout << "[";
    for(; val.size(); val.pop())
        cout << val.top() << (val.size() == 1 ? "" : " ");
    return cout << "]";
}

template<class Tp> ostream& operator << (ostream& cout, queue<Tp> val) {
    cout << "[";
    for(; val.size(); val.pop())
        cout << val.front() << (val.size() == 1 ? "" : " ");
    return cout << "]";
}
