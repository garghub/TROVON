int CRYPTO_get_new_lockid(char *name)
{
char *str;
int i;
#if defined(OPENSSL_SYS_WIN32) || defined(OPENSSL_SYS_WIN16)
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
i=sk_CRYPTO_dynlock_push(dyn_locks,pointer) - 1;
else
sk_CRYPTO_dynlock_set(dyn_locks,i,pointer);
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
#ifdef OPENSSL_SYS_WIN16
ret=(unsigned long)GetCurrentTask();
#elif defined(OPENSSL_SYS_WIN32)
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
fprintf(stderr,"ladd:%08lx:%2d+%2d->%2d %-18s %s:%d\n",
CRYPTO_thread_id(),
before,amount,ret,
CRYPTO_get_lock_name(type),
file,line);
#endif
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
else if (type-CRYPTO_NUM_LOCKS > sk_num(app_locks))
return("ERROR");
else
return(sk_value(app_locks,type-CRYPTO_NUM_LOCKS));
}
unsigned long *OPENSSL_ia32cap_loc(void) { return &OPENSSL_ia32cap_P; }
void OPENSSL_cpuid_setup(void)
{ static int trigger=0;
unsigned long OPENSSL_ia32_cpuid(void);
char *env;
if (trigger) return;
trigger=1;
if ((env=getenv("OPENSSL_ia32cap")))
OPENSSL_ia32cap_P = strtoul(env,NULL,0)|(1<<10);
else
OPENSSL_ia32cap_P = OPENSSL_ia32_cpuid()|(1<<10);
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
ERR_remove_state(0);
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
(void)GetDesktopWindow();
h = GetProcessWindowStation();
if (h==NULL) return -1;
if (GetUserObjectInformationW (h,UOI_NAME,NULL,0,&len) ||
GetLastError() != ERROR_INSUFFICIENT_BUFFER)
return -1;
if (len>512) return -1;
len++,len&=~1;
#ifdef _MSC_VER
name=(WCHAR *)_alloca(len+sizeof(WCHAR));
#else
name=(WCHAR *)alloca(len+sizeof(WCHAR));
#endif
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
void OPENSSL_showfatal (const char *fmta,...)
{ va_list ap;
TCHAR buf[256];
const TCHAR *fmt;
HANDLE h;
if ((h=GetStdHandle(STD_ERROR_HANDLE)) != NULL &&
GetFileType(h)!=FILE_TYPE_UNKNOWN)
{
va_start (ap,fmta);
vfprintf (stderr,fmta,ap);
va_end (ap);
return;
}
if (sizeof(TCHAR)==sizeof(char))
fmt=fmta;
else do
{ int keepgoing;
size_t len_0=strlen(fmta)+1,i;
WCHAR *fmtw;
#ifdef _MSC_VER
fmtw = (WCHAR *)_alloca (len_0*sizeof(WCHAR));
#else
fmtw = (WCHAR *)alloca (len_0*sizeof(WCHAR));
#endif
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
if (GetVersion() < 0x80000000 && OPENSSL_isservice())
{ HANDLE h = RegisterEventSource(0,_T("OPENSSL"));
const TCHAR *pmsg=buf;
ReportEvent(h,EVENTLOG_ERROR_TYPE,0,0,0,1,0,&pmsg,0);
DeregisterEventSource(h);
}
else
#endif
{ MSGBOXPARAMS m;
m.cbSize = sizeof(m);
m.hwndOwner = NULL;
m.lpszCaption = _T("OpenSSL: FATAL");
m.dwStyle = MB_OK;
m.hInstance = NULL;
m.lpszIcon = IDI_ERROR;
m.dwContextHelpId = 0;
m.lpfnMsgBoxCallback = NULL;
m.dwLanguageId = MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US);
m.lpszText = buf;
MessageBoxIndirect (&m);
}
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
abort();
}
void *OPENSSL_stderr(void) { return stderr; }
