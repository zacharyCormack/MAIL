#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
	stringstream ins;
	// run as daemon
	if (!fork())
		return 0;
	// schedule email send
	time_t when;
	ins << argv[1];
	ins >> when;
	while (time(NULL) < when)
		sleep(1);
	ins << "mutt";
	for (int i = 2; i < argc; i++)
	{
		ins << ' ' << argv[i];
	}
	system(ins.str().c_str());
	return 0;
}
