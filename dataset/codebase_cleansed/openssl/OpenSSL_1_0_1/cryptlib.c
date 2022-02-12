int CRYPTO_get_new_lockid(char *name)
{
char *str;
int i;
#if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_WIN16)
SSLeay_MSVC5_hack=(double)name[0]*(double)name[1];
#endif
if ((app_locks == NULL) && ((app_locks=sk_OPENSSL_STRING_new_null()) == NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_LOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
if ((str=BUF_strdup(name)) == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_GET_NEW_LOCKID,ERR_R_MALLOC_FAILURE);
return(0);
}
i=sk_OPENSSL_STRING_push(app_locks,str);
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
i=sk_CRYPTO_dynlock_push(dyn_locks,pointer) - 1;
else
(void)sk_CRYPTO_dynlock_set(dyn_locks,i,pointer);
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
if (i == -1)
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
{
CRYPTO_w_unlock(CRYPTO_LOCK_DYNLOCK);
return;
}
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
if (pointer->references <= 0)
{
(void)sk_CRYPTO_dynlock_set(dyn_locks, i, NULL);
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
OPENSSL_init();
locking_callback=func;
}
void CRYPTO_set_add_lock_callback(int (*func)(int *num,int mount,int type,
const char *file,int line))
{
add_lock_callback=func;
}
void CRYPTO_THREADID_set_numeric(CRYPTO_THREADID *id, unsigned long val)
{
memset(id, 0, sizeof(*id));
id->val = val;
}
void CRYPTO_THREADID_set_pointer(CRYPTO_THREADID *id, void *ptr)
{
unsigned char *dest = (void *)&id->val;
unsigned int accum = 0;
unsigned char dnum = sizeof(id->val);
memset(id, 0, sizeof(*id));
id->ptr = ptr;
if (sizeof(id->val) >= sizeof(id->ptr))
{
id->val = (unsigned long)id->ptr;
return;
}
while (dnum--)
{
const unsigned char *src = (void *)&id->ptr;
unsigned char snum = sizeof(id->ptr);
while (snum--)
accum += *(src++) * hash_coeffs[(snum + dnum) & 7];
accum += dnum;
*(dest++) = accum & 255;
}
}
int CRYPTO_THREADID_set_callback(void (*func)(CRYPTO_THREADID *))
{
if (threadid_callback)
return 0;
threadid_callback = func;
return 1;
}
void CRYPTO_THREADID_current(CRYPTO_THREADID *id)
{
if (threadid_callback)
{
threadid_callback(id);
return;
}
#ifndef OPENSSL_NO_DEPRECATED
if (id_callback)
{
CRYPTO_THREADID_set_numeric(id, id_callback());
return;
}
#endif
#ifdef OPENSSL_SYS_WIN16
CRYPTO_THREADID_set_numeric(id, (unsigned long)GetCurrentTask());
#elif defined(OPENSSL_SYS_WIN32)
CRYPTO_THREADID_set_numeric(id, (unsigned long)GetCurrentThreadId());
#elif defined(OPENSSL_SYS_BEOS)
CRYPTO_THREADID_set_numeric(id, (unsigned long)find_thread(NULL));
#else
CRYPTO_THREADID_set_pointer(id, &errno);
#endif
}
int CRYPTO_THREADID_cmp(const CRYPTO_THREADID *a, const CRYPTO_THREADID *b)
{
return memcmp(a, b, sizeof(*a));
}
void CRYPTO_THREADID_cpy(CRYPTO_THREADID *dest, const CRYPTO_THREADID *src)
{
memcpy(dest, src, sizeof(*src));
}
unsigned long CRYPTO_THREADID_hash(const CRYPTO_THREADID *id)
{
return id->val;
}
unsigned long CRYPTO_thread_id(void)
{
unsigned long ret=0;
if (id_callback == NULL)
{
#ifdef OPENSSL_SYS_WIN16
ret=(unsigned long)GetCurrentTask();
#elif defined(OPENSSL_SYS_WIN32)
ret=(unsigned long)GetCurrentThreadId();
#elif defined(GETPID_IS_MEANINGLESS)
ret=1L;
#elif defined(OPENSSL_SYS_BEOS)
ret=(unsigned long)find_thread(NULL);
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
CRYPTO_THREADID id;
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
CRYPTO_THREADID_current(&id);
fprintf(stderr,"lock:%08lx:(%s)%s %-18s %s:%d\n",
CRYPTO_THREADID_hash(&id), rw_text, operation_text,
CRYPTO_get_lock_name(type), file, line);
}
#endif
if (type < 0)
{
if (dynlock_lock_callback != NULL)
{
struct CRYPTO_dynlock_value *pointer
= CRYPTO_get_dynlock_value(type);
OPENSSL_assert(pointer != NULL);
dynlock_lock_callback(mode, pointer, file, line);
CRYPTO_destroy_dynlockid(type);
}
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
{
CRYPTO_THREADID id;
CRYPTO_THREADID_current(&id);
fprintf(stderr,"ladd:%08lx:%2d+%2d->%2d %-18s %s:%d\n",
CRYPTO_THREADID_hash(&id), before,amount,ret,
CRYPTO_get_lock_name(type),
file,line);
}
#endif
}
else
{
CRYPTO_lock(CRYPTO_LOCK|CRYPTO_WRITE,type,file,line);
ret= *pointer+amount;
#ifdef LOCK_DEBUG
{
CRYPTO_THREADID id;
CRYPTO_THREADID_current(&id);
fprintf(stderr,"ladd:%08lx:%2d+%2d->%2d %-18s %s:%d\n",
CRYPTO_THREADID_hash(&id),
*pointer,amount,ret,
CRYPTO_get_lock_name(type),
file,line);
}
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
else if (type-CRYPTO_NUM_LOCKS > sk_OPENSSL_STRING_num(app_locks))
return("ERROR");
else
return(sk_OPENSSL_STRING_value(app_locks,type-CRYPTO_NUM_LOCKS));
}
unsigned long *OPENSSL_ia32cap_loc(void)
{ if (sizeof(long)==4)
OPENSSL_ia32cap_P[1]=0;
return (unsigned long *)OPENSSL_ia32cap_P;
}
void OPENSSL_cpuid_setup(void)
{ static int trigger=0;
IA32CAP OPENSSL_ia32_cpuid(void);
IA32CAP vec;
char *env;
if (trigger) return;
trigger=1;
if ((env=getenv("OPENSSL_ia32cap"))) {
int off = (env[0]=='~')?1:0;
#if defined(_WIN32)
if (!sscanf(env+off,"%I64i",&vec)) vec = strtoul(env+off,NULL,0);
#else
if (!sscanf(env+off,"%lli",(long long *)&vec)) vec = strtoul(env+off,NULL,0);
#endif
if (off) vec = OPENSSL_ia32_cpuid()&~vec;
}
else
vec = OPENSSL_ia32_cpuid();
OPENSSL_ia32cap_P[0] = (unsigned int)vec|(1<<10);
OPENSSL_ia32cap_P[1] = (unsigned int)(vec>>32);
}
unsigned long *OPENSSL_ia32cap_loc(void) { return NULL; }
void OPENSSL_cpuid_setup(void) {}
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason,
LPVOID lpvReserved)
{
switch(fdwReason)
{
case DLL_PROCESS_ATTACH:
OPENSSL_cpuid_setup();
#if defined(_WIN32_WINNT)
{
IMAGE_DOS_HEADER *dos_header = (IMAGE_DOS_HEADER *)hinstDLL;
IMAGE_NT_HEADERS *nt_headers;
if (dos_header->e_magic==IMAGE_DOS_SIGNATURE)
{
nt_headers = (IMAGE_NT_HEADERS *)((char *)dos_header
+ dos_header->e_lfanew);
if (nt_headers->Signature==IMAGE_NT_SIGNATURE &&
hinstDLL!=(HINSTANCE)(nt_headers->OptionalHeader.ImageBase))
OPENSSL_NONPIC_relocated=1;
}
}
#endif
break;
case DLL_THREAD_ATTACH:
break;
case DLL_THREAD_DETACH:
break;
case DLL_PROCESS_DETACH:
break;
}
return(TRUE);
}
int OPENSSL_isservice(void)
{ HWINSTA h;
DWORD len;
WCHAR *name;
static union { void *p; int (*f)(void); } _OPENSSL_isservice = { NULL };
if (_OPENSSL_isservice.p == NULL) {
HANDLE h = GetModuleHandle(NULL);
if (h != NULL)
_OPENSSL_isservice.p = GetProcAddress(h,"_OPENSSL_isservice");
if (_OPENSSL_isservice.p == NULL)
_OPENSSL_isservice.p = (void *)-1;
}
if (_OPENSSL_isservice.p != (void *)-1)
return (*_OPENSSL_isservice.f)();
(void)GetDesktopWindow();
h = GetProcessWindowStation();
if (h==NULL) return -1;
if (GetUserObjectInformationW (h,UOI_NAME,NULL,0,&len) ||
GetLastError() != ERROR_INSUFFICIENT_BUFFER)
return -1;
if (len>512) return -1;
len++,len&=~1;
name=(WCHAR *)alloca(len+sizeof(WCHAR));
if (!GetUserObjectInformationW (h,UOI_NAME,name,len,&len))
return -1;
len++,len&=~1;
name[len/sizeof(WCHAR)]=L'\0';
#if 1
if (wcsstr(name,L"Service-0x")) return 1;
#else
if (!wcsstr(name,L"WinSta0")) return 1;
#endif
else return 0;
}
int OPENSSL_isservice(void) { return 0; }
void OPENSSL_showfatal (const char *fmta,...)
{ va_list ap;
TCHAR buf[256];
const TCHAR *fmt;
#ifdef STD_ERROR_HANDLE
HANDLE h;
if ((h=GetStdHandle(STD_ERROR_HANDLE)) != NULL &&
GetFileType(h)!=FILE_TYPE_UNKNOWN)
{
va_start (ap,fmta);
vfprintf (stderr,fmta,ap);
va_end (ap);
return;
}
#endif
if (sizeof(TCHAR)==sizeof(char))
fmt=(const TCHAR *)fmta;
else do
{ int keepgoing;
size_t len_0=strlen(fmta)+1,i;
WCHAR *fmtw;
fmtw = (WCHAR *)alloca(len_0*sizeof(WCHAR));
if (fmtw == NULL) { fmt=(const TCHAR *)L"no stack?"; break; }
#ifndef OPENSSL_NO_MULTIBYTE
if (!MultiByteToWideChar(CP_ACP,0,fmta,len_0,fmtw,len_0))
#endif
for (i=0;i<len_0;i++) fmtw[i]=(WCHAR)fmta[i];
for (i=0;i<len_0;i++)
{ if (fmtw[i]==L'%') do
{ keepgoing=0;
switch (fmtw[i+1])
{ case L'0': case L'1': case L'2': case L'3': case L'4':
case L'5': case L'6': case L'7': case L'8': case L'9':
case L'.': case L'*':
case L'-': i++; keepgoing=1; break;
case L's': fmtw[i+1]=L'S'; break;
case L'S': fmtw[i+1]=L's'; break;
case L'c': fmtw[i+1]=L'C'; break;
case L'C': fmtw[i+1]=L'c'; break;
}
} while (keepgoing);
}
fmt = (const TCHAR *)fmtw;
} while (0);
va_start (ap,fmta);
_vsntprintf (buf,sizeof(buf)/sizeof(TCHAR)-1,fmt,ap);
buf [sizeof(buf)/sizeof(TCHAR)-1] = _T('\0');
va_end (ap);
#if defined(_WIN32_WINNT) && _WIN32_WINNT>=0x0333
if (GetVersion() < 0x80000000 && OPENSSL_isservice() > 0)
{ HANDLE h = RegisterEventSource(0,_T("OPENSSL"));
const TCHAR *pmsg=buf;
ReportEvent(h,EVENTLOG_ERROR_TYPE,0,0,0,1,0,&pmsg,0);
DeregisterEventSource(h);
}
else
#endif
MessageBox (NULL,buf,_T("OpenSSL: FATAL"),MB_OK|MB_ICONSTOP);
}
void OPENSSL_showfatal (const char *fmta,...)
{ va_list ap;
va_start (ap,fmta);
vfprintf (stderr,fmta,ap);
va_end (ap);
}
int OPENSSL_isservice (void) { return 0; }
void OpenSSLDie(const char *file,int line,const char *assertion)
{
OPENSSL_showfatal(
"%s(%d): OpenSSL internal error, assertion failed: %s\n",
file,line,assertion);
#if !defined(_WIN32) || defined(__CYGWIN__)
abort();
#else
raise(SIGABRT);
_exit(3);
#endif
}
void *OPENSSL_stderr(void) { return stderr; }
