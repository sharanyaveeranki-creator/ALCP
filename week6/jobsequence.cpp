#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);

    cout << "Enter job id, deadline and profit:" << endl;

    for (auto &j : jobs)
        cin >> j.id >> j.deadline >> j.profit;

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;

    for (auto j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<char> slot(maxDeadline + 1, '-');
    int totalProfit = 0;

    for (auto j : jobs) {
        for (int d = j.deadline; d >= 1; d--) {
            if (slot[d] == '-') {
                slot[d] = j.id;
                totalProfit += j.profit;
                break;
            }
        }
    }

    cout << "Job sequence: ";

    for (int i = 1; i <= maxDeadline; i++)
        cout << slot[i] << " ";

    cout << endl;
    cout << "Maximum profit = " << totalProfit << endl;

    return 0;
}