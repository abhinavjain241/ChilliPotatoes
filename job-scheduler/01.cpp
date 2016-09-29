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
        std::cout << q.top().timestamp << " ";
        std::cout << q.top().pid << " ";
        std::cout << q.top().origin << " ";
        std::cout << q.top().instructions << " ";
        std::cout << q.top().importance << " ";
        std::cout << q.top().duration << " ";
        std::cout << std::endl;
        q.pop();
    }
}

template<typename T> void printJobs(T& q, int num) {
    while(num--) {
    	std::cout << "job";
        std::cout << q.top().timestamp << " ";
        std::cout << q.top().pid << " ";
        std::cout << q.top().origin << " ";
        std::cout << q.top().instructions << " ";
        std::cout << q.top().importance << " ";
        std::cout << q.top().duration << " ";
        std::cout << std::endl;
        q.pop();
    }
}

inline bool isInteger(const std::string & s)
{
   if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;
   char * p ;
   strtol(s.c_str(), &p, 10) ;
   return (*p == 0) ;
}

int main(int argc, char const *argv[]) {
	string line;
	vector<string> input;
	unsigned int numCPU, freeCPU, assigned;
	priority_queue<job> jobs;
	while(getline(cin, line)) {
		cout << line << endl;
		input = split(line, ' ');
		if(input[0] == "cpus") {
			numCPU = atoi(input[1].c_str());
			freeCPU = numCPU;
		}
		if(input[0] == "job") {
			job newJob;
			newJob.timestamp = atoi(input[1].c_str());
			newJob.pid = atoi(input[2].c_str());
			newJob.origin = input[3];
			newJob.instructions = input[4];
			newJob.importance = atoi(input[5].c_str());
			newJob.duration = atoi(input[6].c_str());
			jobs.push(newJob);
		}
		if(input[0] == "assign") {
			ull timestamp = atoi(input[1].c_str());
			unsigned int k = atoi(input[2].c_str());
			assigned = std::min<unsigned long>(std::min(freeCPU, k), jobs.size());
			freeCPU = freeCPU - assigned;
			printJobs(jobs, assigned);
		}
		if(input[0] == "query") {
			if(isInteger(input[2]))
			assigned = std::min<unsigned long>(atoi(input[2].c_str()), jobs.size());
			printJobs(jobs, assigned);
		}
	}
	// print_queue(jobs);
	return 0;
}