int CRYPTO_get_new_lockid(char *name)
{
char *str;
int i;
#if defined(WIN32) || defined(WIN16)
SSLeay_MSVC5_hack=(double)name[0]*(double)name[1];
#endif
if ((app_locks == NULL) && ((app_locks=sk_new_null()) == NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_LOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
if ((str=BUF_strdup(name)) == NULL)
return(0);
i=sk_push(app_locks,str);
if (!i)
Free(str);
else
i+=CRYPTO_NUM_LOCKS;
return(i);
}
void CRYPTO_set_locking_callback(void (*func)(int mode,int type,
const char *file,int line))
{
locking_callback=func;
}
void CRYPTO_set_add_lock_callback(int (*func)(int *num,int mount,int type,
const char *file,int line))
{
add_lock_callback=func;
}
unsigned long CRYPTO_thread_id(void)
{
unsigned long ret=0;
if (id_callback == NULL)
{
#ifdef WIN16
ret=(unsigned long)GetCurrentTask();
#elif defined(WIN32)
ret=(unsigned long)GetCurrentThreadId();
#elif defined(MSDOS)
ret=1L;
#else
ret=(unsigned long)getpid();
#endif
}
else
ret=id_callback();
return(ret);
}
void CRYPTO_lock(int mode, int type, const char *file, int line)
{
#ifdef LOCK_DEBUG
{
char *rw_text,*operation_text;
if (mode & CRYPTO_LOCK)
operation_text="lock ";
else if (mode & CRYPTO_UNLOCK)
operation_text="unlock";
else
operation_text="ERROR ";
if (mode & CRYPTO_READ)
rw_text="r";
else if (mode & CRYPTO_WRITE)
rw_text="w";
else
rw_text="ERROR";
fprintf(stderr,"lock:%08lx:(%s)%s %-18s %s:%d\n",
CRYPTO_thread_id(), rw_text, operation_text,
CRYPTO_get_lock_name(type), file, line);
}
#endif
if (locking_callback != NULL)
locking_callback(mode,type,file,line);
}
int CRYPTO_add_lock(int *pointer, int amount, int type, const char *file,
int line)
{
int ret;
if (add_lock_callback != NULL)
{
#ifdef LOCK_DEBUG
int before= *pointer;
#endif
ret=add_lock_callback(pointer,amount,type,file,line);
#ifdef LOCK_DEBUG
fprintf(stderr,"ladd:%08lx:%2d+%2d->%2d %-18s %s:%d\n",
CRYPTO_thread_id(),
before,amount,ret,
CRYPTO_get_lock_name(type),
file,line);
#endif
*pointer=ret;
}
else
{
CRYPTO_lock(CRYPTO_LOCK|CRYPTO_WRITE,type,file,line);
ret= *pointer+amount;
#ifdef LOCK_DEBUG
fprintf(stderr,"ladd:%08lx:%2d+%2d->%2d %-18s %s:%d\n",
CRYPTO_thread_id(),
*pointer,amount,ret,
CRYPTO_get_lock_name(type),
file,line);
#endif
*pointer=ret;
CRYPTO_lock(CRYPTO_UNLOCK|CRYPTO_WRITE,type,file,line);
}
return(ret);
}
const char *CRYPTO_get_lock_name(int type)
{
if (type < 0)
return("ERROR");
else if (type < CRYPTO_NUM_LOCKS)
return(lock_names[type]);
else if (type-CRYPTO_NUM_LOCKS >= sk_num(app_locks))
return("ERROR");
else
return(sk_value(app_locks,type-CRYPTO_NUM_LOCKS));
}
BOOL WINAPI DLLEntryPoint(HINSTANCE hinstDLL, DWORD fdwReason,
LPVOID lpvReserved)
{
switch(fdwReason)
{
case DLL_PROCESS_ATTACH:
break;
case DLL_THREAD_ATTACH:
break;
case DLL_THREAD_DETACH:
ERR_remove_state(0);
break;
case DLL_PROCESS_DETACH:
break;
}
return(TRUE);
}
