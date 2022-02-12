int RAND_poll(void)
{
unsigned char buf[ENTROPY_NEEDED];
pid_t curr_pid;
uid_t curr_uid;
static int first=1;
int i;
long rnd = 0;
struct timespec ts;
unsigned seed;
if (first) {
first = 0;
rnd = random ();
if (rnd == 1804289383) {
clock_gettime (CLOCK_REALTIME, &ts);
curr_pid = getpid();
curr_uid = getuid();
seed = ts.tv_sec ^ ts.tv_nsec ^ curr_pid ^ curr_uid;
srandom (seed);
}
}
for (i = 0; i < sizeof(buf); i++) {
if (i % 4 == 0)
rnd = random();
buf[i] = rnd;
rnd >>= 8;
}
RAND_add(buf, sizeof(buf), ENTROPY_NEEDED);
memset(buf, 0, sizeof(buf));
return 1;
}
int RAND_poll(void)
{
u_int32_t rnd = 0, i;
unsigned char buf[ENTROPY_NEEDED];
for (i = 0; i < sizeof(buf); i++) {
if (i % 4 == 0)
rnd = arc4random();
buf[i] = rnd;
rnd >>= 8;
}
RAND_add(buf, sizeof(buf), ENTROPY_NEEDED);
memset(buf, 0, sizeof(buf));
return 1;
}
int RAND_poll(void)
{
unsigned long l;
pid_t curr_pid = getpid();
#if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
unsigned char tmpbuf[ENTROPY_NEEDED];
int n = 0;
#endif
#ifdef DEVRANDOM
static const char *randomfiles[] = { DEVRANDOM };
struct stat randomstats[sizeof(randomfiles)/sizeof(randomfiles[0])];
int fd;
unsigned int i;
#endif
#ifdef DEVRANDOM_EGD
static const char *egdsockets[] = { DEVRANDOM_EGD, NULL };
const char **egdsocket = NULL;
#endif
#ifdef DEVRANDOM
memset(randomstats,0,sizeof(randomstats));
for (i = 0; (i < sizeof(randomfiles)/sizeof(randomfiles[0])) &&
(n < ENTROPY_NEEDED); i++)
{
if ((fd = open(randomfiles[i], O_RDONLY
#ifdef O_NONBLOCK
|O_NONBLOCK
#endif
#ifdef O_BINARY
|O_BINARY
#endif
#ifdef O_NOCTTY
|O_NOCTTY
#endif
)) >= 0)
{
int usec = 10*1000;
int r;
unsigned int j;
struct stat *st=&randomstats[i];
if (fstat(fd,st) != 0) { close(fd); continue; }
for (j=0;j<i;j++)
{
if (randomstats[j].st_ino==st->st_ino &&
randomstats[j].st_dev==st->st_dev)
break;
}
if (j<i) { close(fd); continue; }
do
{
int try_read = 0;
#if defined(OPENSSL_SYS_BEOS_R5)
try_read = 1;
#elif defined(OPENSSL_SYS_LINUX)
struct pollfd pset;
pset.fd = fd;
pset.events = POLLIN;
pset.revents = 0;
if (poll(&pset, 1, usec / 1000) < 0)
usec = 0;
else
try_read = (pset.revents & POLLIN) != 0;
#else
fd_set fset;
struct timeval t;
t.tv_sec = 0;
t.tv_usec = usec;
if (FD_SETSIZE > 0 && (unsigned)fd >= FD_SETSIZE)
{
try_read = 1;
}
else
{
FD_ZERO(&fset);
FD_SET(fd, &fset);
if (select(fd+1,&fset,NULL,NULL,&t) >= 0)
{
usec = t.tv_usec;
if (FD_ISSET(fd, &fset))
try_read = 1;
}
else
usec = 0;
}
#endif
if (try_read)
{
r = read(fd,(unsigned char *)tmpbuf+n, ENTROPY_NEEDED-n);
if (r > 0)
n += r;
#if defined(OPENSSL_SYS_BEOS_R5)
if (r == 0)
snooze(t.tv_usec);
#endif
}
else
r = -1;
if (usec == 10*1000)
usec = 0;
}
while ((r > 0 ||
(errno == EINTR || errno == EAGAIN)) && usec != 0 && n < ENTROPY_NEEDED);
close(fd);
}
}
#endif
#ifdef DEVRANDOM_EGD
for (egdsocket = egdsockets; *egdsocket && n < ENTROPY_NEEDED; egdsocket++)
{
int r;
r = RAND_query_egd_bytes(*egdsocket, (unsigned char *)tmpbuf+n,
ENTROPY_NEEDED-n);
if (r > 0)
n += r;
}
#endif
#if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
if (n > 0)
{
RAND_add(tmpbuf,sizeof tmpbuf,(double)n);
OPENSSL_cleanse(tmpbuf,n);
}
#endif
l=curr_pid;
RAND_add(&l,sizeof(l),0.0);
l=getuid();
RAND_add(&l,sizeof(l),0.0);
l=time(NULL);
RAND_add(&l,sizeof(l),0.0);
#if defined(OPENSSL_SYS_BEOS)
{
system_info sysInfo;
get_system_info(&sysInfo);
RAND_add(&sysInfo,sizeof(sysInfo),0);
}
#endif
#if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
return 1;
#else
return 0;
#endif
}
int RAND_poll(void)
{
return 0;
}
