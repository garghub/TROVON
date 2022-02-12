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
void ChaCha20_ctr32(unsigned char *out, const unsigned char *inp,
size_t len, const unsigned int key[8],
const unsigned int counter[4])
{
OPENSSL_ppccap_P & PPC_ALTIVEC
? ChaCha20_ctr32_vmx(out, inp, len, key, counter)
: ChaCha20_ctr32_int(out, inp, len, key, counter);
}
int poly1305_init(void *ctx, const unsigned char key[16], void *func[2])
{
if (sizeof(size_t) == 4 && (OPENSSL_ppccap_P & PPC_FPU)) {
poly1305_init_fpu(ctx, key);
func[0] = poly1305_blocks_fpu;
func[1] = poly1305_emit_fpu;
} else {
poly1305_init_int(ctx, key);
func[0] = poly1305_blocks;
func[1] = poly1305_emit;
}
return 1;
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
if ((e = getenv("OPENSSL_ppccap"))) {
OPENSSL_ppccap_P = strtoul(e, NULL, 0);
return;
}
OPENSSL_ppccap_P = 0;
#if defined(_AIX)
OPENSSL_ppccap_P |= PPC_FPU;
if (sizeof(size_t) == 4) {
struct utsname uts;
# if defined(_SC_AIX_KERNEL_BITMODE)
if (sysconf(_SC_AIX_KERNEL_BITMODE) != 64)
return;
# endif
if (uname(&uts) != 0 || atoi(uts.version) < 6)
return;
}
# if defined(__power_set)
if (sizeof(size_t) == 4) {
if (__power_set(0xffffffffU<<13))
OPENSSL_ppccap_P |= PPC_FPU64;
} else {
if (__power_set(0x1U<<14))
OPENSSL_ppccap_P |= PPC_FPU64;
}
if (__power_set(0xffffffffU<<14))
OPENSSL_ppccap_P |= PPC_ALTIVEC;
if (__power_set(0xffffffffU<<16))
OPENSSL_ppccap_P |= PPC_CRYPTO207;
if (__power_set(0xffffffffU<<17))
OPENSSL_ppccap_P |= PPC_MADD300;
return;
# endif
#endif
if (getauxval != NULL) {
unsigned long hwcap = getauxval(HWCAP);
if (hwcap & HWCAP_FPU) {
OPENSSL_ppccap_P |= PPC_FPU;
if (sizeof(size_t) == 4) {
if (hwcap & HWCAP_PPC64)
OPENSSL_ppccap_P |= PPC_FPU64;
} else {
if (hwcap & HWCAP_POWER6_EXT)
OPENSSL_ppccap_P |= PPC_FPU64;
}
}
if (hwcap & HWCAP_ALTIVEC) {
OPENSSL_ppccap_P |= PPC_ALTIVEC;
if ((hwcap & HWCAP_VSX) && (getauxval(HWCAP2) & HWCAP_VEC_CRYPTO))
OPENSSL_ppccap_P |= PPC_CRYPTO207;
}
if (hwcap & HWCAP_ARCH_3_00) {
OPENSSL_ppccap_P |= PPC_MADD300;
}
return;
}
sigfillset(&all_masked);
sigdelset(&all_masked, SIGILL);
sigdelset(&all_masked, SIGTRAP);
#ifdef SIGEMT
sigdelset(&all_masked, SIGEMT);
#endif
sigdelset(&all_masked, SIGFPE);
sigdelset(&all_masked, SIGBUS);
sigdelset(&all_masked, SIGSEGV);
memset(&ill_act, 0, sizeof(ill_act));
ill_act.sa_handler = ill_handler;
ill_act.sa_mask = all_masked;
sigprocmask(SIG_SETMASK, &ill_act.sa_mask, &oset);
sigaction(SIGILL, &ill_act, &ill_oact);
if (sigsetjmp(ill_jmp,1) == 0) {
OPENSSL_fpu_probe();
OPENSSL_ppccap_P |= PPC_FPU;
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
}
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_altivec_probe();
OPENSSL_ppccap_P |= PPC_ALTIVEC;
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_crypto207_probe();
OPENSSL_ppccap_P |= PPC_CRYPTO207;
}
}
if (sigsetjmp(ill_jmp, 1) == 0) {
OPENSSL_madd300_probe();
OPENSSL_ppccap_P |= PPC_MADD300;
}
sigaction(SIGILL, &ill_oact, NULL);
sigprocmask(SIG_SETMASK, &oset, NULL);
}
