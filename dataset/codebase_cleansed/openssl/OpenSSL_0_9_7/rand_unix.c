int RAND_poll(void)
{
unsigned long l;
pid_t curr_pid = getpid();
#if defined(DEVRANDOM) || defined(DEVRANDOM_EGD)
unsigned char tmpbuf[ENTROPY_NEEDED];
int n = 0;
#endif
#ifdef DEVRANDOM
static const char *randomfiles[] = { DEVRANDOM, NULL };
const char **randomfile = NULL;
int fd;
#endif
#ifdef DEVRANDOM_EGD
static const char *egdsockets[] = { DEVRANDOM_EGD, NULL };
const char **egdsocket = NULL;
#endif
#ifdef DEVRANDOM
for (randomfile = randomfiles; *randomfile && n < ENTROPY_NEEDED; randomfile++)
{
if ((fd = open(*randomfile, O_RDONLY|O_NONBLOCK
#ifdef O_NOCTTY
|O_NOCTTY
#endif
#ifdef O_NOFOLLOW
|O_NOFOLLOW
#endif
)) >= 0)
{
struct timeval t = { 0, 10*1000 };
int r;
fd_set fset;
do
{
FD_ZERO(&fset);
FD_SET(fd, &fset);
r = -1;
if (select(fd+1,&fset,NULL,NULL,&t) < 0)
t.tv_usec=0;
else if (FD_ISSET(fd, &fset))
{
r=read(fd,(unsigned char *)tmpbuf+n,
ENTROPY_NEEDED-n);
if (r > 0)
n += r;
}
if (t.tv_usec == 10*1000)
t.tv_usec=0;
}
while ((r > 0 || (errno == EINTR || errno == EAGAIN))
&& t.tv_usec != 0 && n < ENTROPY_NEEDED);
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
RAND_add(tmpbuf,sizeof tmpbuf,n);
OPENSSL_cleanse(tmpbuf,n);
}
#endif
l=curr_pid;
RAND_add(&l,sizeof(l),0);
l=getuid();
RAND_add(&l,sizeof(l),0);
l=time(NULL);
RAND_add(&l,sizeof(l),0);
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
