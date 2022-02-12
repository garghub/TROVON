void OPENSSL_cpuid_setup(void)
{
}
unsigned long OPENSSL_rdtsc(void)
{
return 0;
}
static void ill_handler(int sig)
{
siglongjmp(ill_jmp, sig);
}
unsigned long OPENSSL_rdtsc(void)
{
if (OPENSSL_armcap_P & ARMV7_TICK)
return _armv7_tick();
else
return 0;
}
void OPENSSL_cpuid_setup(void)
{
char *e;
struct sigaction ill_oact, ill_act;
sigset_t oset;
static int trigger = 0;
if (trigger)
return;
trigger = 1;
if ((e = getenv("OPENSSL_armcap"))) {
OPENSSL_armcap_P = (unsigned int)strtoul(e, NULL, 0);
return;
}
sigfillset(&all_masked);
sigdelset(&all_masked, SIGILL);
sigdelset(&all_masked, SIGTRAP);
sigdelset(&all_masked, SIGFPE);
sigdelset(&all_masked, SIGBUS);
sigdelset(&all_masked, SIGSEGV);
OPENSSL_armcap_P = 0;
memset(&ill_act, 0, sizeof(ill_act));
ill_act.sa_handler = ill_handler;
ill_act.sa_mask = all_masked;
sigprocmask(SIG_SETMASK, &ill_act.sa_mask, &oset);
sigaction(SIGILL, &ill_act, &ill_oact);
if (getauxval != NULL) {
if (getauxval(HWCAP) & HWCAP_NEON) {
unsigned long hwcap = getauxval(HWCAP_CE);
OPENSSL_armcap_P |= ARMV7_NEON;
if (hwcap & HWCAP_CE_AES)
OPENSSL_armcap_P |= ARMV8_AES;
if (hwcap & HWCAP_CE_PMULL)
OPENSSL_armcap_P |= ARMV8_PMULL;
if (hwcap & HWCAP_CE_SHA1)
OPENSSL_armcap_P |= ARMV8_SHA1;
if (hwcap & HWCAP_CE_SHA256)
OPENSSL_armcap_P |= ARMV8_SHA256;
}
} else if (sigsetjmp(ill_jmp, 1) == 0) {
_armv7_neon_probe();
OPENSSL_armcap_P |= ARMV7_NEON;
if (sigsetjmp(ill_jmp, 1) == 0) {
_armv8_pmull_probe();
OPENSSL_armcap_P |= ARMV8_PMULL | ARMV8_AES;
} else if (sigsetjmp(ill_jmp, 1) == 0) {
_armv8_aes_probe();
OPENSSL_armcap_P |= ARMV8_AES;
}
if (sigsetjmp(ill_jmp, 1) == 0) {
_armv8_sha1_probe();
OPENSSL_armcap_P |= ARMV8_SHA1;
}
if (sigsetjmp(ill_jmp, 1) == 0) {
_armv8_sha256_probe();
OPENSSL_armcap_P |= ARMV8_SHA256;
}
}
if (sigsetjmp(ill_jmp, 1) == 0) {
_armv7_tick();
OPENSSL_armcap_P |= ARMV7_TICK;
}
sigaction(SIGILL, &ill_oact, NULL);
sigprocmask(SIG_SETMASK, &oset, NULL);
}
