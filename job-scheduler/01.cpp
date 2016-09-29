#include <bits/stdc++.h>

#define ull unsigned long long
#define ul unsigned long

using namespace std;

struct job {
	ull pid;
	ull timestamp;
	string origin;
	string instructions;
	unsigned int importance;
	ul duration; 
};

vector<string> split(string str, char delimiter) {
  vector<string> internal;
  stringstream ss(str); // Turn the string into a stream.
  string tok;
  
  while(getline(ss, tok, delimiter)) {
    internal.push_back(tok);
  }
  
  return internal;
}

bool operator<(const job& a, const job& b) {
	if(a.importance < b.importance) return true;
	if(a.timestamp > b.timestamp) return true;
	if(a.duration > b.duration) return true;
	return false;
}

template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top().pid << " ";
        std::cout << q.top().timestamp << " ";
        std::cout << q.top().origin << " ";
        std::cout << q.top().instructions << " ";
        std::cout << q.top().importance << " ";
        q.pop();
    }
    std::cout << '\n';
}


int main(int argc, char const *argv[]) {
	string line;
	vector<string> input;
	unsigned int numCPU;
	priority_queue<job> jobs;
	while(getline(cin, line)) {
		cout << line << endl;
		input = split(line, ' ');
		if(input[0] == "cpus") {
			numCPU = std::stoi(input[1]);
		}
		if(input[0] == "job") {
			job newJob;
			newJob.timestamp = std::stoi(input[1]);
			newJob.pid = std::stoi(input[2]);
			newJob.origin = input[3];
			newJob.instructions = std::stoi(input[4]);
			newJob.duration = std::stoi(input[5]);
			jobs.push(newJob);
		}
		if(input[0] == "assign") {

		}
		if(input[0] == "query") {

		}
	}

	return 0;
}