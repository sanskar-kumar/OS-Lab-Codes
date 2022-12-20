#include <bits/stdc++.h>
using namespace std;
void waiting_time(vector<vector<int>> &time, vector<int> &waiting)
{
    int n = time.size();
    waiting[0] = 0;
    for (int i = 1; i < n; i++)
    {
        int last_task = waiting[i - 1] + time[i - 1][0] + time[i - 1][1];
        if (last_task <= time[i][0])
            waiting[i] = 0;
        else
            waiting[i] = last_task - time[i][0];
    }
    // printing waiting time
    cout << "Waitng time are:- ";
    for (int i : waiting)
    {
        cout << i << " ";
    }
    cout << endl;
}
void turn_around_time(vector<vector<int>> &time, vector<int> &waiting, vector<int> &tat)
{
    int n = time.size();
    for (int i = 0; i < n; i++)
    {
        tat[i] = time[i][1] + waiting[i];
    }
    cout << "Turn around time are:- ";
    for (int i : tat)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    cout << "Enter number of processes" << endl;
    int n;
    cin >> n;
    vector<vector<int>> time(n, vector<int>(2));
    vector<int> waiting(n);
    vector<int> tat(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the arrival time and burst time for process " << i + 1 << " :- " << endl;
        cin >> time[i][0] >> time[i][1];
    }
    sort(time.begin(), time.end());

    waiting_time(time, waiting);
    turn_around_time(time, waiting, tat);

    int total_waiting_time = 0;
    int total_turn_around_time = 0;

    for (int i = 0; i < n; i++)
    {
        total_waiting_time += waiting[i];
        total_turn_around_time += tat[i];
    }

    cout << "The average waiting time is :- " << double(total_waiting_time) / double(n) << endl;
    cout << "The average turn around time time is :- " << double(total_turn_around_time) / double(n) << endl;
}