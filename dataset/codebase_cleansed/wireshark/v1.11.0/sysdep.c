void get_ieee_node_identifier(uuid_node_t *node)
{
static inited = 0;
static uuid_node_t saved_node;
char seed[16];
FILE *fp;
if (!inited) {
fp = fopen("nodeid", "rb");
if (fp) {
fread(&saved_node, sizeof saved_node, 1, fp);
fclose(fp);
}
else {
get_random_info(seed);
seed[0] |= 0x01;
memcpy(&saved_node, seed, sizeof saved_node);
fp = fopen("nodeid", "wb");
if (fp) {
fwrite(&saved_node, sizeof saved_node, 1, fp);
fclose(fp);
}
}
inited = 1;
}
*node = saved_node;
}
void get_system_time(uuid_time_t *uuid_time)
{
ULARGE_INTEGER time;
GetSystemTimeAsFileTime((FILETIME *)&time);
time.QuadPart +=
(unsigned __int64) (1000*1000*10)
* (unsigned __int64) (60 * 60 * 24)
* (unsigned __int64) (17+30+31+365*18+5);
*uuid_time = time.QuadPart;
}
void get_random_info(char seed[16])
{
MD5_CTX c;
struct {
MEMORYSTATUS m;
SYSTEM_INFO s;
FILETIME t;
LARGE_INTEGER pc;
DWORD tc;
DWORD l;
char hostname[MAX_COMPUTERNAME_LENGTH + 1];
} r;
MD5Init(&c);
GlobalMemoryStatus(&r.m);
GetSystemInfo(&r.s);
GetSystemTimeAsFileTime(&r.t);
QueryPerformanceCounter(&r.pc);
r.tc = GetTickCount();
r.l = MAX_COMPUTERNAME_LENGTH + 1;
GetComputerNameA(r.hostname, &r.l);
MD5Update(&c, &r, sizeof r);
MD5Final(seed, &c);
}
void get_system_time(uuid_time_t *uuid_time)
{
struct timeval tp;
gettimeofday(&tp, (struct timezone *)0);
*uuid_time = ((unsigned64)tp.tv_sec * 10000000)
+ ((unsigned64)tp.tv_usec * 10)
+ I64(0x01B21DD213814000);
}
void get_random_info(char seed[16])
{
MD5_CTX c;
struct {
struct sysinfo s;
struct timeval t;
char hostname[257];
} r;
MD5Init(&c);
sysinfo(&r.s);
gettimeofday(&r.t, (struct timezone *)0);
gethostname(r.hostname, 256);
MD5Update(&c, &r, sizeof r);
MD5Final(seed, &c);
}
