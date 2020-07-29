#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	// run prgram as daemon
	if (!fork()) return 0;
	// set up argument string to integer conversion
	stringstream ins;
	// wait until after certain time to send emails
	time_t when;
	ins << argv[1];
	ins >> when;
	while (time(NULL) < when) sleep(1);
	int num_messages, wait_time;
	// number of times to send message
	ins << argv[2];
	ins >> num_messages;
	// time between messages in microsecs
	ins << argv[3];
	ins >> wait_time;
	// send remaining arguments to mutt
	ins << "mutt";
	for (int i = 4; i < argc; i++)
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
