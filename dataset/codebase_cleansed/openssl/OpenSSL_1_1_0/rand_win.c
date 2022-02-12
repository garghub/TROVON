int RAND_poll(void)
{
MEMORYSTATUS mst;
# ifndef RAND_WINDOWS_USE_BCRYPT
HCRYPTPROV hProvider;
# endif
DWORD w;
BYTE buf[64];
# ifdef RAND_WINDOWS_USE_BCRYPT
if (BCryptGenRandom(NULL, buf, (ULONG)sizeof(buf), BCRYPT_USE_SYSTEM_PREFERRED_RNG) == STATUS_SUCCESS) {
RAND_add(buf, sizeof(buf), sizeof(buf));
}
# else
if (CryptAcquireContextW(&hProvider, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT | CRYPT_SILENT)) {
if (CryptGenRandom(hProvider, (DWORD)sizeof(buf), buf) != 0) {
RAND_add(buf, sizeof(buf), sizeof(buf));
}
CryptReleaseContext(hProvider, 0);
}
if (CryptAcquireContextW(&hProvider, NULL, INTEL_DEF_PROV, PROV_INTEL_SEC, CRYPT_VERIFYCONTEXT | CRYPT_SILENT)) {
if (CryptGenRandom(hProvider, (DWORD)sizeof(buf), buf) != 0) {
RAND_add(buf, sizeof(buf), sizeof(buf));
}
CryptReleaseContext(hProvider, 0);
}
# endif
readtimer();
GlobalMemoryStatus(&mst);
RAND_add(&mst, sizeof(mst), 1);
w = GetCurrentProcessId();
RAND_add(&w, sizeof(w), 1);
return (1);
}
int RAND_event(UINT iMsg, WPARAM wParam, LPARAM lParam)
{
RAND_poll();
return RAND_status();
}
void RAND_screen(void)
{
RAND_poll();
}
static void readtimer(void)
{
DWORD w;
LARGE_INTEGER l;
static int have_perfc = 1;
# if defined(_MSC_VER) && defined(_M_X86)
static int have_tsc = 1;
DWORD cyclecount;
if (have_tsc) {
__try {
__asm {
_emit 0x0f _emit 0x31 mov cyclecount, eax}
RAND_add(&cyclecount, sizeof(cyclecount), 1);
}
__except(EXCEPTION_EXECUTE_HANDLER) {
have_tsc = 0;
}
}
# else
# define have_tsc 0
# endif
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
