void CRYPTO_thread_setup(void)
{
int i;
lock_cs=Malloc(CRYPTO_num_locks() * sizeof(HANDLE));
for (i=0; i<CRYPTO_num_locks(); i++)
{
lock_cs[i]=CreateMutex(NULL,FALSE,NULL);
}
CRYPTO_set_locking_callback((void (*)(int,int,char *,int))win32_locking_callback);
return(1);
}
static void CRYPTO_thread_cleanup(void)
{
int i;
CRYPTO_set_locking_callback(NULL);
for (i=0; i<CRYPTO_num_locks(); i++)
CloseHandle(lock_cs[i]);
Free(lock_cs);
}
void win32_locking_callback(int mode, int type, char *file, int line)
{
if (mode & CRYPTO_LOCK)
{
WaitForSingleObject(lock_cs[type],INFINITE);
}
else
{
ReleaseMutex(lock_cs[type]);
}
}
void CRYPTO_thread_setup(void)
{
int i;
#ifdef USE_MUTEX
lock_cs=Malloc(CRYPTO_num_locks() * sizeof(mutex_t));
#else
lock_cs=Malloc(CRYPTO_num_locks() * sizeof(rwlock_t));
#endif
lock_count=Malloc(CRYPTO_num_locks() * sizeof(long));
for (i=0; i<CRYPTO_num_locks(); i++)
{
lock_count[i]=0;
#ifdef USE_MUTEX
mutex_init(&(lock_cs[i]),USYNC_THREAD,NULL);
#else
rwlock_init(&(lock_cs[i]),USYNC_THREAD,NULL);
#endif
}
CRYPTO_set_id_callback((unsigned long (*)())solaris_thread_id);
CRYPTO_set_locking_callback((void (*)())solaris_locking_callback);
}
void CRYPTO_thread_cleanup(void)
{
int i;
CRYPTO_set_locking_callback(NULL);
for (i=0; i<CRYPTO_num_locks(); i++)
{
#ifdef USE_MUTEX
mutex_destroy(&(lock_cs[i]));
#else
rwlock_destroy(&(lock_cs[i]));
#endif
}
Free(lock_cs);
Free(lock_count);
}
void solaris_locking_callback(int mode, int type, char *file, int line)
{
#if 0
fprintf(stderr,"thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode&CRYPTO_LOCK)?"l":"u",
(type&CRYPTO_READ)?"r":"w",file,line);
#endif
#if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr,"(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(),
mode,file,line);
#endif
if (mode & CRYPTO_LOCK)
{
#ifdef USE_MUTEX
mutex_lock(&(lock_cs[type]));
#else
if (mode & CRYPTO_READ)
rw_rdlock(&(lock_cs[type]));
else
rw_wrlock(&(lock_cs[type]));
#endif
lock_count[type]++;
}
else
{
#ifdef USE_MUTEX
mutex_unlock(&(lock_cs[type]));
#else
rw_unlock(&(lock_cs[type]));
#endif
}
}
unsigned long solaris_thread_id(void)
{
unsigned long ret;
ret=(unsigned long)thr_self();
return(ret);
}
void CRYPTO_thread_setup(void)
{
int i;
char filename[20];
strcpy(filename,"/tmp/mttest.XXXXXX");
mktemp(filename);
usconfig(CONF_STHREADIOOFF);
usconfig(CONF_STHREADMALLOCOFF);
usconfig(CONF_INITUSERS,100);
usconfig(CONF_LOCKTYPE,US_DEBUGPLUS);
arena=usinit(filename);
unlink(filename);
lock_cs=Malloc(CRYPTO_num_locks() * sizeof(usema_t *));
for (i=0; i<CRYPTO_num_locks(); i++)
{
lock_cs[i]=usnewsema(arena,1);
}
CRYPTO_set_id_callback((unsigned long (*)())irix_thread_id);
CRYPTO_set_locking_callback((void (*)())irix_locking_callback);
}
void CRYPTO_thread_cleanup(void)
{
int i;
CRYPTO_set_locking_callback(NULL);
for (i=0; i<CRYPTO_num_locks(); i++)
{
char buf[10];
sprintf(buf,"%2d:",i);
usdumpsema(lock_cs[i],stdout,buf);
usfreesema(lock_cs[i],arena);
}
Free(lock_cs);
}
void irix_locking_callback(int mode, int type, char *file, int line)
{
if (mode & CRYPTO_LOCK)
{
uspsema(lock_cs[type]);
}
else
{
usvsema(lock_cs[type]);
}
}
unsigned long irix_thread_id(void)
{
unsigned long ret;
ret=(unsigned long)getpid();
return(ret);
}
void CRYPTO_thread_setup(void)
{
int i;
lock_cs=Malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t));
lock_count=Malloc(CRYPTO_num_locks() * sizeof(long));
for (i=0; i<CRYPTO_num_locks(); i++)
{
lock_count[i]=0;
pthread_mutex_init(&(lock_cs[i]),NULL);
}
CRYPTO_set_id_callback((unsigned long (*)())pthreads_thread_id);
CRYPTO_set_locking_callback((void (*)())pthreads_locking_callback);
}
void thread_cleanup(void)
{
int i;
CRYPTO_set_locking_callback(NULL);
for (i=0; i<CRYPTO_num_locks(); i++)
{
pthread_mutex_destroy(&(lock_cs[i]));
}
Free(lock_cs);
Free(lock_count);
}
void pthreads_locking_callback(int mode, int type, char *file,
int line)
{
#if 0
fprintf(stderr,"thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode&CRYPTO_LOCK)?"l":"u",
(type&CRYPTO_READ)?"r":"w",file,line);
#endif
#if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr,"(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(),
mode,file,line);
#endif
if (mode & CRYPTO_LOCK)
{
pthread_mutex_lock(&(lock_cs[type]));
lock_count[type]++;
}
else
{
pthread_mutex_unlock(&(lock_cs[type]));
}
}
unsigned long pthreads_thread_id(void)
{
unsigned long ret;
ret=(unsigned long)pthread_self();
return(ret);
}
