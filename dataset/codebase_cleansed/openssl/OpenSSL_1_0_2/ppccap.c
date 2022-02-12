int bn_mul_mont(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,
const BN_ULONG *np, const BN_ULONG *n0, int num)
{
int bn_mul_mont_fpu64(BN_ULONG *rp, const BN_ULONG *ap,
const BN_ULONG *bp, const BN_ULONG *np,
const BN_ULONG *n0, int num);
int bn_mul_mont_int(BN_ULONG *rp, const BN_ULONG *ap, const BN_ULONG *bp,
const BN_ULONG *np, const BN_ULONG *n0, int num);
if (sizeof(size_t) == 4) {
# if 1 || (defined(__APPLE__) && defined(__MACH__))
if (num >= 8 && (num & 3) == 0 && (OPENSSL_ppccap_P & PPC_FPU64))
return bn_mul_mont_fpu64(rp, ap, bp, np, n0, num);
# else
if (num >= 32 && (num & 3) == 0 && (OPENSSL_ppccap_P & PPC_FPU64)) {
sigset_t oset;
int ret;
sigprocmask(SIG_SETMASK, &all_masked, &oset);
ret = bn_mul_mont_fpu64(rp, ap, bp, np, n0, num);
sigprocmask(SIG_SETMASK, &oset, NULL);
return ret;
}
# endif
} else if ((OPENSSL_ppccap_P & PPC_FPU64))
return bn_mul_mont_fpu64(rp, ap, bp, np, n0, num);
return bn_mul_mont_int(rp, ap, bp, np, n0, num);
}
void sha256_block_data_order(void *ctx, const void *inp, size_t len)
{
OPENSSL_ppccap_P & PPC_CRYPTO207 ? sha256_block_p8(ctx, inp, len) :
sha256_block_ppc(ctx, inp, len);
}
void sha512_block_data_order(void *ctx, const void *inp, size_t len)
{
OPENSSL_ppccap_P & PPC_CRYPTO207 ? sha512_block_p8(ctx, inp, len) :
sha512_block_ppc(ctx, inp, len);
}
static void ill_handler(int sig)
{
siglongjmp(ill_jmp, sig);
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
sigfillset(&all_masked);
sigdelset(&all_masked, SIGILL);
sigdelset(&all_masked, SIGTRAP);
#ifdef SIGEMT
sigdelset(&all_masked, SIGEMT);
#endif
sigdelset(&all_masked, SIGFPE);
sigdelset(&all_masked, SIGBUS);
sigdelset(&all_masked, SIGSEGV);
if ((e = getenv("OPENSSL_ppccap"))) {
OPENSSL_ppccap_P = strtoul(e, NULL, 0);
return;
}
OPENSSL_ppccap_P = 0;
#if defined(_AIX)
if (sizeof(size_t) == 4) {
struct utsname uts;
# if defined(_SC_AIX_KERNEL_BITMODE)
if (sysconf(_SC_AIX_KERNEL_BITMODE) != 64)
return;
# endif
if (uname(&uts) != 0 || atoi(uts.version) < 6)
return;
}
#endif
memset(&ill_act, 0, sizeof(ill_act));
ill_act.sa_handler = ill_handler;
ill_act.sa_mask = all_masked;
sigprocmask(SIG_SETMASK, &ill_act.sa_mask, &oset);
sigaction(SIGILL, &ill_act, &ill_oact);
if (sizeof(size_t) == 4) {
#ifdef __linux
struct utsname uts;
if (uname(&uts) == 0 && strcmp(uts.machine, "ppc64") == 0)
#endif
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_ppc64_probe();
OPENSSL_ppccap_P |= PPC_FPU64;
}
} else {
}
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_altivec_probe();
OPENSSL_ppccap_P |= PPC_ALTIVEC;
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_crypto207_probe();
OPENSSL_ppccap_P |= PPC_CRYPTO207;
}
}
sigaction(SIGILL, &ill_oact, NULL);
sigprocmask(SIG_SETMASK, &oset, NULL);
}
