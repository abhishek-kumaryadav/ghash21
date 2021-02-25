
#include <bits/stdc++.h>
#define forn(i, S) for (int i = 0; i < S; i++)
using namespace std;
struct street
{
    int id;
    int start;
    string name;
    int end;
    int dist;
    int count = 0;
};
struct graph_node
{
    vector<int> in;
    vector<int> out;
};
int main()
{
    std::ifstream in("f.txt");
    std::streambuf *cinbuf = std::cin.rdbuf(); //save old buf
    std::cin.rdbuf(in.rdbuf());                //reairect std::cin to in.txt!

    std::ofstream out("f3.txt");
    std::streambuf *coutbuf = std::cout.rdbuf(); //save old buf
    std::cout.rdbuf(out.rdbuf());
    int D, I, S, V, F;
    cin >> D >> I >> S >> V >> F;
    map<string, int> streetid;
    struct graph_node graph[I];
    struct street starray[S];
    vector<int> start_st(S, 0);
    forn(i, S)
    {
        cin >> starray[i].start >> starray[i].end;
        starray[i].id = i;
        string tempname;
        cin >> tempname;
        starray[i].name = tempname;
        streetid.insert({tempname, starray[i].id});
        graph[starray[i].start].out.push_back(starray[i].id);
        graph[starray[i].end].in.push_back(starray[i].id);
        cin >> starray[i].dist;
    }
    // vector<int> car_path[V];
    forn(i, V)
    {
        int p;
        cin >> p;
        forn(j, p)
        {

            string ts;
            cin >> ts;
            int tid = streetid[ts];
            // car_path[j]=tid;
            if (j < p - 1)
                starray[tid].count++;
            if (j == 0)
            {
                start_st[tid]++;
            }
        }
    }
    cout << I << "\n";
    forn(i, I)
    {
        // cout << i << "\n";
        int tn = 0;
        int maxx = -1, maxid = 0;
        int flag = 0;
        forn(j, graph[i].in.size())
        {
            int stid = graph[i].in[j];
            if (starray[stid].count != 0)
                tn++;
            if (maxx < start_st[stid])
            {
                maxx = start_st[stid];
                maxid = stid;
                flag = 1;
            }
        }
        cout << i << "\n";
        int ccount = tn;
        if (tn > 0)
        {
            cout << tn << "\n";

            if (flag == 1 && starray[maxid].count > 0)
            {
                cout << starray[maxid].name << " 1\n";
            }
            forn(j, graph[i].in.size())
            {
                int stid = graph[i].in[j];
                if (stid != maxid && starray[stid].count != 0)
                {
                    cout << starray[stid].name << " 1\n";
                    // ccount--;
                }
            }
        }
        else
        {
            int stid = graph[i].in[0];
            cout << "1\n"
                 << starray[stid].name << " 1\n";
        }
        // cout << "\n";
    }
    return 0;
}