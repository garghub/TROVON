static inline void align_mod(const int align, const int mod)
{
asm volatile(
".set push\n\t"
".set noreorder\n\t"
".balign %0\n\t"
".rept %1\n\t"
"nop\n\t"
".endr\n\t"
".set pop"
:
: GCC_IMM_ASM() (align), GCC_IMM_ASM() (mod));
}
static inline void mult_sh_align_mod(long *v1, long *v2, long *w,
const int align, const int mod)
{
unsigned long flags;
int m1, m2;
long p, s, lv1, lv2, lw;
local_irq_save(flags);
asm volatile(
""
: "=r" (m1), "=r" (m2), "=r" (s)
: "0" (5), "1" (8), "2" (5));
align_mod(align, mod);
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"mult %2, %3\n\t"
"dsll32 %0, %4, %5\n\t"
"mflo $0\n\t"
"dsll32 %1, %4, %5\n\t"
"nop\n\t"
".set pop"
: "=&r" (lv1), "=r" (lw)
: "r" (m1), "r" (m2), "r" (s), "I" (0)
: "hi", "lo", GCC_REG_ACCUM);
asm volatile(
""
: "=r" (m1), "=r" (m2), "=r" (s)
: "0" (m1), "1" (m2), "2" (s));
align_mod(align, mod);
p = m1 * m2;
lv2 = s << 32;
asm volatile(
""
: "=r" (lv2)
: "0" (lv2), "r" (p));
local_irq_restore(flags);
*v1 = lv1;
*v2 = lv2;
*w = lw;
}
static inline void check_mult_sh(void)
{
long v1[8], v2[8], w[8];
int bug, fix, i;
printk("Checking for the multiply/shift bug... ");
mult_sh_align_mod(&v1[0], &v2[0], &w[0], 32, 0);
mult_sh_align_mod(&v1[1], &v2[1], &w[1], 32, 1);
mult_sh_align_mod(&v1[2], &v2[2], &w[2], 32, 2);
mult_sh_align_mod(&v1[3], &v2[3], &w[3], 32, 3);
mult_sh_align_mod(&v1[4], &v2[4], &w[4], 32, 4);
mult_sh_align_mod(&v1[5], &v2[5], &w[5], 32, 5);
mult_sh_align_mod(&v1[6], &v2[6], &w[6], 32, 6);
mult_sh_align_mod(&v1[7], &v2[7], &w[7], 32, 7);
bug = 0;
for (i = 0; i < 8; i++)
if (v1[i] != w[i])
bug = 1;
if (bug == 0) {
pr_cont("no.\n");
return;
}
pr_cont("yes, workaround... ");
fix = 1;
for (i = 0; i < 8; i++)
if (v2[i] != w[i])
fix = 0;
if (fix == 1) {
pr_cont("yes.\n");
return;
}
pr_cont("no.\n");
panic(bug64hit, !R4000_WAR ? r4kwar : nowar);
}
asmlinkage void __init do_daddi_ov(struct pt_regs *regs)
{
enum ctx_state prev_state;
prev_state = exception_enter();
daddi_ov = 1;
regs->cp0_epc += 4;
exception_exit(prev_state);
}
static inline void check_daddi(void)
{
extern asmlinkage void handle_daddi_ov(void);
unsigned long flags;
void *handler;
long v, tmp;
printk("Checking for the daddi bug... ");
local_irq_save(flags);
handler = set_except_vector(EXCCODE_OV, handle_daddi_ov);
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"addiu %1, $0, %2\n\t"
"dsrl %1, %1, 1\n\t"
#ifdef HAVE_AS_SET_DADDI
".set daddi\n\t"
#endif
"daddi %0, %1, %3\n\t"
".set pop"
: "=r" (v), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
set_except_vector(EXCCODE_OV, handler);
local_irq_restore(flags);
if (daddi_ov) {
pr_cont("no.\n");
return;
}
pr_cont("yes, workaround... ");
local_irq_save(flags);
handler = set_except_vector(EXCCODE_OV, handle_daddi_ov);
asm volatile(
"addiu %1, $0, %2\n\t"
"dsrl %1, %1, 1\n\t"
"daddi %0, %1, %3"
: "=r" (v), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
set_except_vector(EXCCODE_OV, handler);
local_irq_restore(flags);
if (daddi_ov) {
pr_cont("yes.\n");
return;
}
pr_cont("no.\n");
panic(bug64hit, !DADDI_WAR ? daddiwar : nowar);
}
static inline void check_daddiu(void)
{
long v, w, tmp;
printk("Checking for the daddiu bug... ");
asm volatile(
".set push\n\t"
".set noat\n\t"
".set noreorder\n\t"
".set nomacro\n\t"
"addiu %2, $0, %3\n\t"
"dsrl %2, %2, 1\n\t"
#ifdef HAVE_AS_SET_DADDI
".set daddi\n\t"
#endif
"daddiu %0, %2, %4\n\t"
"addiu %1, $0, %4\n\t"
"daddu %1, %2\n\t"
".set pop"
: "=&r" (v), "=&r" (w), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
daddiu_bug = v != w;
if (!daddiu_bug) {
pr_cont("no.\n");
return;
}
pr_cont("yes, workaround... ");
asm volatile(
"addiu %2, $0, %3\n\t"
"dsrl %2, %2, 1\n\t"
"daddiu %0, %2, %4\n\t"
"addiu %1, $0, %4\n\t"
"daddu %1, %2"
: "=&r" (v), "=&r" (w), "=&r" (tmp)
: "I" (0xffffffffffffdb9aUL), "I" (0x1234));
if (v == w) {
pr_cont("yes.\n");
return;
}
pr_cont("no.\n");
panic(bug64hit, !DADDI_WAR ? daddiwar : nowar);
}
void __init check_bugs64_early(void)
{
if (!IS_ENABLED(CONFIG_CPU_MIPSR6)) {
check_mult_sh();
check_daddiu();
}
}
void __init check_bugs64(void)
{
if (!IS_ENABLED(CONFIG_CPU_MIPSR6))
check_daddi();
}
