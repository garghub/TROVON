void OPENSSL_cpuid_setup(void)
{
static int trigger = 0;
IA32CAP OPENSSL_ia32_cpuid(unsigned int *);
IA32CAP vec;
char *env;
if (trigger)
return;
trigger = 1;
if ((env = getenv("OPENSSL_ia32cap"))) {
int off = (env[0] == '~') ? 1 : 0;
# if defined(_WIN32)
if (!sscanf(env + off, "%I64i", &vec))
vec = strtoul(env + off, NULL, 0);
# else
if (!sscanf(env + off, "%lli", (long long *)&vec))
vec = strtoul(env + off, NULL, 0);
# endif
if (off)
vec = OPENSSL_ia32_cpuid(OPENSSL_ia32cap_P) & ~vec;
else if (env[0] == ':')
vec = OPENSSL_ia32_cpuid(OPENSSL_ia32cap_P);
OPENSSL_ia32cap_P[2] = 0;
if ((env = strchr(env, ':'))) {
unsigned int vecx;
env++;
off = (env[0] == '~') ? 1 : 0;
vecx = strtoul(env + off, NULL, 0);
if (off)
OPENSSL_ia32cap_P[2] &= ~vecx;
else
OPENSSL_ia32cap_P[2] = vecx;
}
} else
vec = OPENSSL_ia32_cpuid(OPENSSL_ia32cap_P);
OPENSSL_ia32cap_P[0] = (unsigned int)vec | (1 << 10);
OPENSSL_ia32cap_P[1] = (unsigned int)(vec >> 32);
}
void OPENSSL_cpuid_setup(void)
{
}
int OPENSSL_isservice(void)
{
HWINSTA h;
DWORD len;
WCHAR *name;
static union {
void *p;
FARPROC f;
} _OPENSSL_isservice = {
NULL
};
if (_OPENSSL_isservice.p == NULL) {
HANDLE mod = GetModuleHandle(NULL);
if (mod != NULL)
_OPENSSL_isservice.f = GetProcAddress(mod, "_OPENSSL_isservice");
if (_OPENSSL_isservice.p == NULL)
_OPENSSL_isservice.p = (void *)-1;
}
if (_OPENSSL_isservice.p != (void *)-1)
return (*_OPENSSL_isservice.f) ();
h = GetProcessWindowStation();
if (h == NULL)
return -1;
if (GetUserObjectInformationW(h, UOI_NAME, NULL, 0, &len) ||
GetLastError() != ERROR_INSUFFICIENT_BUFFER)
return -1;
if (len > 512)
return -1;
len++, len &= ~1;
name = (WCHAR *)alloca(len + sizeof(WCHAR));
if (!GetUserObjectInformationW(h, UOI_NAME, name, len, &len))
return -1;
len++, len &= ~1;
name[len / sizeof(WCHAR)] = L'\0';
# if 1
if (wcsstr(name, L"Service-0x"))
return 1;
# else
if (!wcsstr(name, L"WinSta0"))
return 1;
# endif
else
return 0;
}
int OPENSSL_isservice(void)
{
return 0;
}
void OPENSSL_showfatal(const char *fmta, ...)
{
va_list ap;
TCHAR buf[256];
const TCHAR *fmt;
# ifdef STD_ERROR_HANDLE
HANDLE h;
if ((h = GetStdHandle(STD_ERROR_HANDLE)) != NULL &&
GetFileType(h) != FILE_TYPE_UNKNOWN) {
int len;
DWORD out;
va_start(ap, fmta);
len = _vsnprintf((char *)buf, sizeof(buf), fmta, ap);
WriteFile(h, buf, len < 0 ? sizeof(buf) : (DWORD) len, &out, NULL);
va_end(ap);
return;
}
# endif
if (sizeof(TCHAR) == sizeof(char))
fmt = (const TCHAR *)fmta;
else
do {
int keepgoing;
size_t len_0 = strlen(fmta) + 1, i;
WCHAR *fmtw;
fmtw = (WCHAR *)alloca(len_0 * sizeof(WCHAR));
if (fmtw == NULL) {
fmt = (const TCHAR *)L"no stack?";
break;
}
if (!MultiByteToWideChar(CP_ACP, 0, fmta, len_0, fmtw, len_0))
for (i = 0; i < len_0; i++)
fmtw[i] = (WCHAR)fmta[i];
for (i = 0; i < len_0; i++) {
if (fmtw[i] == L'%')
do {
keepgoing = 0;
switch (fmtw[i + 1]) {
case L'0':
case L'1':
case L'2':
case L'3':
case L'4':
case L'5':
case L'6':
case L'7':
case L'8':
case L'9':
case L'.':
case L'*':
case L'-':
i++;
keepgoing = 1;
break;
case L's':
fmtw[i + 1] = L'S';
break;
case L'S':
fmtw[i + 1] = L's';
break;
case L'c':
fmtw[i + 1] = L'C';
break;
case L'C':
fmtw[i + 1] = L'c';
break;
}
} while (keepgoing);
}
fmt = (const TCHAR *)fmtw;
} while (0);
va_start(ap, fmta);
_vsntprintf(buf, OSSL_NELEM(buf) - 1, fmt, ap);
buf[OSSL_NELEM(buf) - 1] = _T('\0');
va_end(ap);
# if defined(_WIN32_WINNT) && _WIN32_WINNT>=0x0333
if (check_winnt() && OPENSSL_isservice() > 0) {
HANDLE hEventLog = RegisterEventSource(NULL, _T("OpenSSL"));
if (hEventLog != NULL) {
const TCHAR *pmsg = buf;
if (!ReportEvent(hEventLog, EVENTLOG_ERROR_TYPE, 0, 0, NULL,
1, 0, &pmsg, NULL)) {
#if defined(DEBUG)
OutputDebugString(pmsg);
#endif
}
(void)DeregisterEventSource(hEventLog);
}
} else
# endif
MessageBox(NULL, buf, _T("OpenSSL: FATAL"), MB_OK | MB_ICONERROR);
}
void OPENSSL_showfatal(const char *fmta, ...)
{
#ifndef OPENSSL_NO_STDIO
va_list ap;
va_start(ap, fmta);
vfprintf(stderr, fmta, ap);
va_end(ap);
#endif
}
int OPENSSL_isservice(void)
{
return 0;
}
void OPENSSL_die(const char *message, const char *file, int line)
{
OPENSSL_showfatal("%s:%d: OpenSSL internal error: %s\n",
file, line, message);
#if !defined(_WIN32) || defined(__CYGWIN__)
abort();
#else
# if !defined(_WIN32_WCE)
raise(SIGABRT);
# endif
_exit(3);
#endif
}
int CRYPTO_memcmp(const volatile void * volatile in_a,
const volatile void * volatile in_b,
size_t len)
{
size_t i;
const volatile unsigned char *a = in_a;
const volatile unsigned char *b = in_b;
unsigned char x = 0;
for (i = 0; i < len; i++)
x |= a[i] ^ b[i];
return x;
}
