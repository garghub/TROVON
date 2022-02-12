int RAND_poll(void)
{
MEMORYSTATUS m;
HCRYPTPROV hProvider = 0;
DWORD w;
int good = 0;
OSVERSIONINFO osverinfo ;
osverinfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFO) ;
GetVersionEx( &osverinfo ) ;
#if defined(OPENSSL_SYS_WINCE)
# if defined(_WIN32_WCE) && _WIN32_WCE>=300
{
BYTE buf[64];
if (CryptAcquireContextW(&hProvider, NULL, NULL, PROV_RSA_FULL,
CRYPT_VERIFYCONTEXT))
{
if (CryptGenRandom(hProvider, sizeof(buf), buf))
RAND_add(buf, sizeof(buf), sizeof(buf));
CryptReleaseContext(hProvider, 0);
}
}
# endif
#else
{
HMODULE advapi = LoadLibrary(TEXT("ADVAPI32.DLL"));
HMODULE kernel = LoadLibrary(TEXT("KERNEL32.DLL"));
HMODULE user = NULL;
HMODULE netapi = LoadLibrary(TEXT("NETAPI32.DLL"));
CRYPTACQUIRECONTEXTW acquire = NULL;
CRYPTGENRANDOM gen = NULL;
CRYPTRELEASECONTEXT release = NULL;
NETSTATGET netstatget = NULL;
NETFREE netfree = NULL;
BYTE buf[64];
if (netapi)
{
netstatget = (NETSTATGET) GetProcAddress(netapi,"NetStatisticsGet");
netfree = (NETFREE) GetProcAddress(netapi,"NetApiBufferFree");
}
if (netstatget && netfree)
{
LPBYTE outbuf;
if (netstatget(NULL, L"LanmanWorkstation", 0, 0, &outbuf) == 0)
{
RAND_add(outbuf, sizeof(STAT_WORKSTATION_0), 45);
netfree(outbuf);
}
if (netstatget(NULL, L"LanmanServer", 0, 0, &outbuf) == 0)
{
RAND_add(outbuf, sizeof(STAT_SERVER_0), 17);
netfree(outbuf);
}
}
if (netapi)
FreeLibrary(netapi);
#if 0
if ( osverinfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
osverinfo.dwMajorVersion < 5)
{
LONG rc=ERROR_MORE_DATA;
char * buf=NULL;
DWORD bufsz=0;
DWORD length;
while (rc == ERROR_MORE_DATA)
{
buf = realloc(buf,bufsz+8192);
if (!buf)
break;
bufsz += 8192;
length = bufsz;
rc = RegQueryValueEx(HKEY_PERFORMANCE_DATA, TEXT("Global"),
NULL, NULL, buf, &length);
}
if (rc == ERROR_SUCCESS)
{
RAND_add(&length, sizeof(length), 0);
RAND_add(buf, length, length / 4.0);
RegCloseKey(HKEY_PERFORMANCE_DATA);
}
if (buf)
free(buf);
}
#endif
if (advapi)
{
acquire = (CRYPTACQUIRECONTEXTW) GetProcAddress(advapi,
"CryptAcquireContextW");
gen = (CRYPTGENRANDOM) GetProcAddress(advapi,
"CryptGenRandom");
release = (CRYPTRELEASECONTEXT) GetProcAddress(advapi,
"CryptReleaseContext");
}
if (acquire && gen && release)
{
if (acquire(&hProvider, NULL, NULL, PROV_RSA_FULL,
CRYPT_VERIFYCONTEXT))
{
if (gen(hProvider, sizeof(buf), buf) != 0)
{
RAND_add(buf, sizeof(buf), 0);
good = 1;
#if 0
printf("randomness from PROV_RSA_FULL\n");
#endif
}
release(hProvider, 0);
}
if (acquire(&hProvider, 0, INTEL_DEF_PROV, PROV_INTEL_SEC, 0))
{
if (gen(hProvider, sizeof(buf), buf) != 0)
{
RAND_add(buf, sizeof(buf), sizeof(buf));
good = 1;
#if 0
printf("randomness from PROV_INTEL_SEC\n");
#endif
}
release(hProvider, 0);
}
}
if (advapi)
FreeLibrary(advapi);
if ((osverinfo.dwPlatformId != VER_PLATFORM_WIN32_NT ||
!OPENSSL_isservice()) &&
(user = LoadLibrary(TEXT("USER32.DLL"))))
{
GETCURSORINFO cursor;
GETFOREGROUNDWINDOW win;
GETQUEUESTATUS queue;
win = (GETFOREGROUNDWINDOW) GetProcAddress(user, "GetForegroundWindow");
cursor = (GETCURSORINFO) GetProcAddress(user, "GetCursorInfo");
queue = (GETQUEUESTATUS) GetProcAddress(user, "GetQueueStatus");
if (win)
{
HWND h = win();
RAND_add(&h, sizeof(h), 0);
}
if (cursor)
{
if ( osverinfo.dwPlatformId == VER_PLATFORM_WIN32_NT &&
osverinfo.dwMajorVersion < 5)
cursor = 0;
}
if (cursor)
{
CURSORINFO ci;
ci.cbSize = sizeof(CURSORINFO);
if (cursor(&ci))
RAND_add(&ci, ci.cbSize, 2);
}
if (queue)
{
w = queue(QS_ALLEVENTS);
RAND_add(&w, sizeof(w), 1);
}
FreeLibrary(user);
}
if (kernel)
{
CREATETOOLHELP32SNAPSHOT snap;
CLOSETOOLHELP32SNAPSHOT close_snap;
HANDLE handle;
HEAP32FIRST heap_first;
HEAP32NEXT heap_next;
HEAP32LIST heaplist_first, heaplist_next;
PROCESS32 process_first, process_next;
THREAD32 thread_first, thread_next;
MODULE32 module_first, module_next;
HEAPLIST32 hlist;
HEAPENTRY32 hentry;
PROCESSENTRY32 p;
THREADENTRY32 t;
MODULEENTRY32 m;
DWORD starttime = 0;
snap = (CREATETOOLHELP32SNAPSHOT)
GetProcAddress(kernel, "CreateToolhelp32Snapshot");
close_snap = (CLOSETOOLHELP32SNAPSHOT)
GetProcAddress(kernel, "CloseToolhelp32Snapshot");
heap_first = (HEAP32FIRST) GetProcAddress(kernel, "Heap32First");
heap_next = (HEAP32NEXT) GetProcAddress(kernel, "Heap32Next");
heaplist_first = (HEAP32LIST) GetProcAddress(kernel, "Heap32ListFirst");
heaplist_next = (HEAP32LIST) GetProcAddress(kernel, "Heap32ListNext");
process_first = (PROCESS32) GetProcAddress(kernel, "Process32First");
process_next = (PROCESS32) GetProcAddress(kernel, "Process32Next");
thread_first = (THREAD32) GetProcAddress(kernel, "Thread32First");
thread_next = (THREAD32) GetProcAddress(kernel, "Thread32Next");
module_first = (MODULE32) GetProcAddress(kernel, "Module32First");
module_next = (MODULE32) GetProcAddress(kernel, "Module32Next");
if (snap && heap_first && heap_next && heaplist_first &&
heaplist_next && process_first && process_next &&
thread_first && thread_next && module_first &&
module_next && (handle = snap(TH32CS_SNAPALL,0))
!= INVALID_HANDLE_VALUE)
{
ZeroMemory(&hlist, sizeof(HEAPLIST32));
hlist.dwSize = sizeof(HEAPLIST32);
if (good) starttime = GetTickCount();
#ifdef _MSC_VER
if (heaplist_first(handle, &hlist))
{
int ex_cnt_limit = 42;
do
{
RAND_add(&hlist, hlist.dwSize, 3);
__try
{
ZeroMemory(&hentry, sizeof(HEAPENTRY32));
hentry.dwSize = sizeof(HEAPENTRY32);
if (heap_first(&hentry,
hlist.th32ProcessID,
hlist.th32HeapID))
{
int entrycnt = 80;
do
RAND_add(&hentry,
hentry.dwSize, 5);
while (heap_next(&hentry)
&& (!good || (GetTickCount()-starttime)<MAXDELAY)
&& --entrycnt > 0);
}
}
__except (EXCEPTION_EXECUTE_HANDLER)
{
ex_cnt_limit--;
}
} while (heaplist_next(handle, &hlist)
&& (!good || (GetTickCount()-starttime)<MAXDELAY)
&& ex_cnt_limit > 0);
}
#else
if (heaplist_first(handle, &hlist))
{
do
{
RAND_add(&hlist, hlist.dwSize, 3);
hentry.dwSize = sizeof(HEAPENTRY32);
if (heap_first(&hentry,
hlist.th32ProcessID,
hlist.th32HeapID))
{
int entrycnt = 80;
do
RAND_add(&hentry,
hentry.dwSize, 5);
while (heap_next(&hentry)
&& --entrycnt > 0);
}
} while (heaplist_next(handle, &hlist)
&& (!good || (GetTickCount()-starttime)<MAXDELAY));
}
#endif
p.dwSize = sizeof(PROCESSENTRY32);
if (good) starttime = GetTickCount();
if (process_first(handle, &p))
do
RAND_add(&p, p.dwSize, 9);
while (process_next(handle, &p) && (!good || (GetTickCount()-starttime)<MAXDELAY));
t.dwSize = sizeof(THREADENTRY32);
if (good) starttime = GetTickCount();
if (thread_first(handle, &t))
do
RAND_add(&t, t.dwSize, 6);
while (thread_next(handle, &t) && (!good || (GetTickCount()-starttime)<MAXDELAY));
m.dwSize = sizeof(MODULEENTRY32);
if (good) starttime = GetTickCount();
if (module_first(handle, &m))
do
RAND_add(&m, m.dwSize, 9);
while (module_next(handle, &m)
&& (!good || (GetTickCount()-starttime)<MAXDELAY));
if (close_snap)
close_snap(handle);
else
CloseHandle(handle);
}
FreeLibrary(kernel);
}
}
#endif
readtimer();
GlobalMemoryStatus(&m);
RAND_add(&m, sizeof(m), 1);
w = GetCurrentProcessId();
RAND_add(&w, sizeof(w), 1);
#if 0
printf("Exiting RAND_poll\n");
#endif
return(1);
}
int RAND_event(UINT iMsg, WPARAM wParam, LPARAM lParam)
{
double add_entropy=0;
switch (iMsg)
{
case WM_KEYDOWN:
{
static WPARAM key;
if (key != wParam)
add_entropy = 0.05;
key = wParam;
}
break;
case WM_MOUSEMOVE:
{
static int lastx,lasty,lastdx,lastdy;
int x,y,dx,dy;
x=LOWORD(lParam);
y=HIWORD(lParam);
dx=lastx-x;
dy=lasty-y;
if (dx != 0 && dy != 0 && dx-lastdx != 0 && dy-lastdy != 0)
add_entropy=.2;
lastx=x, lasty=y;
lastdx=dx, lastdy=dy;
}
break;
}
readtimer();
RAND_add(&iMsg, sizeof(iMsg), add_entropy);
RAND_add(&wParam, sizeof(wParam), 0);
RAND_add(&lParam, sizeof(lParam), 0);
return (RAND_status());
}
void RAND_screen(void)
{
RAND_poll();
readscreen();
}
static void readtimer(void)
{
DWORD w;
LARGE_INTEGER l;
static int have_perfc = 1;
#if defined(_MSC_VER) && defined(_M_X86)
static int have_tsc = 1;
DWORD cyclecount;
if (have_tsc) {
__try {
__asm {
_emit 0x0f
_emit 0x31
mov cyclecount, eax
}
RAND_add(&cyclecount, sizeof(cyclecount), 1);
} __except(EXCEPTION_EXECUTE_HANDLER) {
have_tsc = 0;
}
}
#else
# define have_tsc 0
#endif
if (have_perfc) {
if (QueryPerformanceCounter(&l) == 0)
have_perfc = 0;
else
RAND_add(&l, sizeof(l), 0);
}
if (!have_tsc && !have_perfc) {
w = GetTickCount();
RAND_add(&w, sizeof(w), 0);
}
}
static void readscreen(void)
{
#if !defined(OPENSSL_SYS_WINCE) && !defined(OPENSSL_SYS_WIN32_CYGWIN)
HDC hScrDC;
HDC hMemDC;
HBITMAP hBitmap;
HBITMAP hOldBitmap;
BITMAP bm;
unsigned int size;
char *bmbits;
int w;
int h;
int y;
int n = 16;
if (GetVersion() < 0x80000000 && OPENSSL_isservice()>0)
return;
hScrDC = CreateDC(TEXT("DISPLAY"), NULL, NULL, NULL);
hMemDC = CreateCompatibleDC(hScrDC);
w = GetDeviceCaps(hScrDC, HORZRES);
h = GetDeviceCaps(hScrDC, VERTRES);
hBitmap = CreateCompatibleBitmap(hScrDC, w, n);
hOldBitmap = SelectObject(hMemDC, hBitmap);
GetObject(hBitmap, sizeof(BITMAP), (LPSTR)&bm);
size = (unsigned int)bm.bmWidthBytes * bm.bmHeight * bm.bmPlanes;
bmbits = OPENSSL_malloc(size);
if (bmbits) {
for (y = 0; y < h-n; y += n)
{
unsigned char md[MD_DIGEST_LENGTH];
BitBlt(hMemDC, 0, 0, w, n, hScrDC, 0, y, SRCCOPY);
GetBitmapBits(hBitmap, size, bmbits);
MD(bmbits,size,md);
RAND_add(md, MD_DIGEST_LENGTH, 0);
}
OPENSSL_free(bmbits);
}
hBitmap = SelectObject(hMemDC, hOldBitmap);
DeleteObject(hBitmap);
DeleteDC(hMemDC);
DeleteDC(hScrDC);
#endif
}
