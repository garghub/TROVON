int RAND_poll(void)
{
short int code;
gid_t curr_gid;
pid_t curr_pid;
uid_t curr_uid;
int i, k;
struct timespec ts;
unsigned char v;
# ifdef OPENSSL_SYS_VOS_HPPA
long duration;
extern void s$sleep(long *_duration, short int *_code);
# else
# ifdef OPENSSL_SYS_VOS_IA32
long long duration;
extern void s$sleep2(long long *_duration, short int *_code);
# else
# error "Unsupported Platform."
# endif
# endif
curr_gid = getgid();
RAND_add(&curr_gid, sizeof curr_gid, 1);
curr_gid = 0;
curr_pid = getpid();
RAND_add(&curr_pid, sizeof curr_pid, 1);
curr_pid = 0;
curr_uid = getuid();
RAND_add(&curr_uid, sizeof curr_uid, 1);
curr_uid = 0;
for (i = 0; i < (ENTROPY_NEEDED * 4); i++) {
for (k = 0; k < 99; k++)
ts.tv_nsec = random();
# ifdef OPENSSL_SYS_VOS_HPPA
duration = 1;
s$sleep(&duration, &code);
# else
# ifdef OPENSSL_SYS_VOS_IA32
duration = 1;
s$sleep2(&duration, &code);
# endif
# endif
clock_gettime(CLOCK_REALTIME, &ts);
v = (unsigned char)(ts.tv_nsec % 256);
RAND_add(&v, sizeof v, 1);
v = 0;
}
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
# if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
unsigned char tmpbuf[ENTROPY_NEEDED];
int n = 0;
# endif
# ifdef DEVRANDOM
static const char *randomfiles[] = { DEVRANDOM };
struct stat randomstats[sizeof(randomfiles) / sizeof(randomfiles[0])];
int fd;
unsigned int i;
# endif
# ifdef DEVRANDOM_EGD
static const char *egdsockets[] = { DEVRANDOM_EGD, NULL };
const char **egdsocket = NULL;
# endif
# ifdef DEVRANDOM
memset(randomstats, 0, sizeof(randomstats));
for (i = 0; (i < sizeof(randomfiles) / sizeof(randomfiles[0])) &&
(n < ENTROPY_NEEDED); i++) {
if ((fd = open(randomfiles[i], O_RDONLY
# ifdef O_NONBLOCK
| O_NONBLOCK
# endif
# ifdef O_BINARY
| O_BINARY
# endif
# ifdef O_NOCTTY
| O_NOCTTY
# endif
)) >= 0) {
int usec = 10 * 1000;
int r;
unsigned int j;
struct stat *st = &randomstats[i];
if (fstat(fd, st) != 0) {
close(fd);
continue;
}
for (j = 0; j < i; j++) {
if (randomstats[j].st_ino == st->st_ino &&
randomstats[j].st_dev == st->st_dev)
break;
}
if (j < i) {
close(fd);
continue;
}
do {
int try_read = 0;
# if defined(OPENSSL_SYS_BEOS_R5)
try_read = 1;
# elif defined(OPENSSL_SYS_LINUX)
struct pollfd pset;
pset.fd = fd;
pset.events = POLLIN;
pset.revents = 0;
if (poll(&pset, 1, usec / 1000) < 0)
usec = 0;
else
try_read = (pset.revents & POLLIN) != 0;
# else
fd_set fset;
struct timeval t;
t.tv_sec = 0;
t.tv_usec = usec;
if (FD_SETSIZE > 0 && (unsigned)fd >= FD_SETSIZE) {
try_read = 1;
} else {
FD_ZERO(&fset);
FD_SET(fd, &fset);
if (select(fd + 1, &fset, NULL, NULL, &t) >= 0) {
usec = t.tv_usec;
if (FD_ISSET(fd, &fset))
try_read = 1;
} else
usec = 0;
}
# endif
if (try_read) {
r = read(fd, (unsigned char *)tmpbuf + n,
ENTROPY_NEEDED - n);
if (r > 0)
n += r;
# if defined(OPENSSL_SYS_BEOS_R5)
if (r == 0)
snooze(t.tv_usec);
# endif
} else
r = -1;
if (usec == 10 * 1000)
usec = 0;
}
while ((r > 0 ||
(errno == EINTR || errno == EAGAIN)) && usec != 0
&& n < ENTROPY_NEEDED);
close(fd);
}
}
# endif
# ifdef DEVRANDOM_EGD
for (egdsocket = egdsockets; *egdsocket && n < ENTROPY_NEEDED;
egdsocket++) {
int r;
r = RAND_query_egd_bytes(*egdsocket, (unsigned char *)tmpbuf + n,
ENTROPY_NEEDED - n);
if (r > 0)
n += r;
}
# endif
# if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
if (n > 0) {
RAND_add(tmpbuf, sizeof tmpbuf, (double)n);
OPENSSL_cleanse(tmpbuf, n);
}
# endif
l = curr_pid;
RAND_add(&l, sizeof(l), 0.0);
l = getuid();
RAND_add(&l, sizeof(l), 0.0);
l = time(NULL);
RAND_add(&l, sizeof(l), 0.0);
# if defined(OPENSSL_SYS_BEOS)
{
system_info sysInfo;
get_system_info(&sysInfo);
RAND_add(&sysInfo, sizeof(sysInfo), 0);
}
# endif
# if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
return 1;
# else
return 0;
# endif
}
int RAND_poll(void)
{
return 0;
}
