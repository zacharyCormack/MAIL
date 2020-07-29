#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	size_t when;
	int num_messages, wait_time;
	// get arguments
	cout << "When to start, in UTS seconds: ";
	cin >> when;
	cout << "Number of messages: ";
	cin >> num_messages;
	cout << "Time between messages, in microseconds: ";
	cin >> wait_time;
	// run remaing tasks as daemon
	if (fork()!=0) return 0;
	// set up argument string to integer conversion
	stringstream ins;
	// wait until after certain time to send emails
	while (time(NULL) < when) sleep(1);
	// send command line arguments to mutt
	ins << "mutt";
	for (int i = 1; i < argc; i++)
		ins << ' ' << argv[i];
	const char* command = ins.str().c_str();
	// send message repeatedly
	while (num_messages-->0)
	{
		system(command);
		usleep(wait_time);
	}
	return 0;
}
