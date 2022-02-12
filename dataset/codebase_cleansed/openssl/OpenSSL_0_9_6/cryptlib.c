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
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_LOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
i=sk_push(app_locks,str);
if (!i)
OPENSSL_free(str);
else
i+=CRYPTO_NUM_LOCKS;
return(i);
}
int CRYPTO_num_locks(void)
{
return CRYPTO_NUM_LOCKS;
}
int CRYPTO_get_new_dynlockid(void)
{
int i = 0;
CRYPTO_dynlock *pointer = NULL;
if (dynlock_create_callback == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_DYNLOCKID,CRYPTO_R_NO_DYNLOCK_CREATE_CALLBACK);
return(0);
}
CRYPTO_w_lock(CRYPTO_LOCK_DYNLOCK);
if ((dyn_locks == NULL)
&& ((dyn_locks=sk_CRYPTO_dynlock_new_null()) == NULL))
{
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_DYNLOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
pointer = (CRYPTO_dynlock *)OPENSSL_malloc(sizeof(CRYPTO_dynlock));
if (pointer == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_DYNLOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
pointer->references = 1;
pointer->data = dynlock_create_callback(__FILE__,__LINE__);
if (pointer->data == NULL)
{
OPENSSL_free(pointer);
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_DYNLOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
CRYPTO_w_lock(CRYPTO_LOCK_DYNLOCK);
i=sk_CRYPTO_dynlock_find(dyn_locks,NULL);
if (i == -1)
i=sk_CRYPTO_dynlock_push(dyn_locks,pointer);
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
if (!i)
{
dynlock_destroy_callback(pointer->data,__FILE__,__LINE__);
OPENSSL_free(pointer);
}
else
i += 1;
return -i;
}
void CRYPTO_destroy_dynlockid(int i)
{
CRYPTO_dynlock *pointer = NULL;
if (i)
i = -i-1;
if (dynlock_destroy_callback == NULL)
return;
CRYPTO_w_lock(CRYPTO_LOCK_DYNLOCK);
if (dyn_locks == NULL || i >= sk_CRYPTO_dynlock_num(dyn_locks))
return;
pointer = sk_CRYPTO_dynlock_value(dyn_locks, i);
if (pointer != NULL)
{
--pointer->references;
#ifdef REF_CHECK
if (pointer->references < 0)
{
fprintf(stderr,"CRYPTO_destroy_dynlockid, bad reference count\n");
abort();
}
else
#endif
if (--(pointer->references) <= 0)
{
sk_CRYPTO_dynlock_set(dyn_locks, i, NULL);
}
else
pointer = NULL;
}
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
if (pointer)
{
dynlock_destroy_callback(pointer->data,__FILE__,__LINE__);
OPENSSL_free(pointer);
}
}
struct CRYPTO_dynlock_value *CRYPTO_get_dynlock_value(int i)
{
CRYPTO_dynlock *pointer = NULL;
if (i)
i = -i-1;
CRYPTO_w_lock(CRYPTO_LOCK_DYNLOCK);
if (dyn_locks != NULL && i < sk_CRYPTO_dynlock_num(dyn_locks))
pointer = sk_CRYPTO_dynlock_value(dyn_locks, i);
if (pointer)
pointer->references++;
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
if (pointer)
return pointer->data;
return NULL;
}
void CRYPTO_set_dynlock_lock_callback(void (*func)(int mode,
struct CRYPTO_dynlock_value *l, const char *file, int line))
{
dynlock_lock_callback=func;
}
void CRYPTO_set_dynlock_destroy_callback(void (*func)
(struct CRYPTO_dynlock_value *l, const char *file, int line))
{
dynlock_destroy_callback=func;
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
#elif defined(GETPID_IS_MEANINGLESS)
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
if (type < 0)
{
int i = -type - 1;
struct CRYPTO_dynlock_value *pointer
= CRYPTO_get_dynlock_value(i);
if (pointer)
{
dynlock_lock_callback(mode, pointer, file, line);
}
CRYPTO_destroy_dynlockid(i);
}
else
if (locking_callback != NULL)
locking_callback(mode,type,file,line);
}
int CRYPTO_add_lock(int *pointer, int amount, int type, const char *file,
int line)
{
int ret = 0;
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
return("dynamic");
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
