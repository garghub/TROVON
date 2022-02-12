void __sanitize_i387_state(struct task_struct *tsk)
{
struct i387_fxsave_struct *fx = &tsk->thread.fpu.state->fxsave;
int feature_bit = 0x2;
u64 xstate_bv;
if (!fx)
return;
xstate_bv = tsk->thread.fpu.state->xsave.xsave_hdr.xstate_bv;
if ((xstate_bv & pcntxt_mask) == pcntxt_mask)
return;
if (!(xstate_bv & XSTATE_FP)) {
fx->cwd = 0x37f;
fx->swd = 0;
fx->twd = 0;
fx->fop = 0;
fx->rip = 0;
fx->rdp = 0;
memset(&fx->st_space[0], 0, 128);
}
if (!(xstate_bv & XSTATE_SSE))
memset(&fx->xmm_space[0], 0, 256);
xstate_bv = (pcntxt_mask & ~xstate_bv) >> 2;
while (xstate_bv) {
if (xstate_bv & 0x1) {
int offset = xstate_offsets[feature_bit];
int size = xstate_sizes[feature_bit];
memcpy(((void *) fx) + offset,
((void *) init_xstate_buf) + offset,
size);
}
xstate_bv >>= 1;
feature_bit++;
}
}
static inline int check_for_xstate(struct i387_fxsave_struct __user *buf,
void __user *fpstate,
struct _fpx_sw_bytes *fx_sw)
{
int min_xstate_size = sizeof(struct i387_fxsave_struct) +
sizeof(struct xsave_hdr_struct);
unsigned int magic2;
if (__copy_from_user(fx_sw, &buf->sw_reserved[0], sizeof(*fx_sw)))
return -1;
if (fx_sw->magic1 != FP_XSTATE_MAGIC1 ||
fx_sw->xstate_size < min_xstate_size ||
fx_sw->xstate_size > xstate_size ||
fx_sw->xstate_size > fx_sw->extended_size)
return -1;
if (__get_user(magic2, (__u32 __user *)(fpstate + fx_sw->xstate_size))
|| magic2 != FP_XSTATE_MAGIC2)
return -1;
return 0;
}
static inline int save_fsave_header(struct task_struct *tsk, void __user *buf)
{
if (use_fxsr()) {
struct xsave_struct *xsave = &tsk->thread.fpu.state->xsave;
struct user_i387_ia32_struct env;
struct _fpstate_ia32 __user *fp = buf;
convert_from_fxsr(&env, tsk);
if (__copy_to_user(buf, &env, sizeof(env)) ||
__put_user(xsave->i387.swd, &fp->status) ||
__put_user(X86_FXSR_MAGIC, &fp->magic))
return -1;
} else {
struct i387_fsave_struct __user *fp = buf;
u32 swd;
if (__get_user(swd, &fp->swd) || __put_user(swd, &fp->status))
return -1;
}
return 0;
}
static inline int save_xstate_epilog(void __user *buf, int ia32_frame)
{
struct xsave_struct __user *x = buf;
struct _fpx_sw_bytes *sw_bytes;
u32 xstate_bv;
int err;
sw_bytes = ia32_frame ? &fx_sw_reserved_ia32 : &fx_sw_reserved;
err = __copy_to_user(&x->i387.sw_reserved, sw_bytes, sizeof(*sw_bytes));
if (!use_xsave())
return err;
err |= __put_user(FP_XSTATE_MAGIC2, (__u32 *)(buf + xstate_size));
err |= __get_user(xstate_bv, (__u32 *)&x->xsave_hdr.xstate_bv);
xstate_bv |= XSTATE_FPSSE;
err |= __put_user(xstate_bv, (__u32 *)&x->xsave_hdr.xstate_bv);
return err;
}
static inline int save_user_xstate(struct xsave_struct __user *buf)
{
int err;
if (use_xsave())
err = xsave_user(buf);
else if (use_fxsr())
err = fxsave_user((struct i387_fxsave_struct __user *) buf);
else
err = fsave_user((struct i387_fsave_struct __user *) buf);
if (unlikely(err) && __clear_user(buf, xstate_size))
err = -EFAULT;
return err;
}
int save_xstate_sig(void __user *buf, void __user *buf_fx, int size)
{
struct xsave_struct *xsave = &current->thread.fpu.state->xsave;
struct task_struct *tsk = current;
int ia32_fxstate = (buf != buf_fx);
ia32_fxstate &= (config_enabled(CONFIG_X86_32) ||
config_enabled(CONFIG_IA32_EMULATION));
if (!access_ok(VERIFY_WRITE, buf, size))
return -EACCES;
if (!static_cpu_has(X86_FEATURE_FPU))
return fpregs_soft_get(current, NULL, 0,
sizeof(struct user_i387_ia32_struct), NULL,
(struct _fpstate_ia32 __user *) buf) ? -1 : 1;
if (user_has_fpu()) {
if (save_user_xstate(buf_fx))
return -1;
if (ia32_fxstate)
fpu_fxsave(&tsk->thread.fpu);
} else {
sanitize_i387_state(tsk);
if (__copy_to_user(buf_fx, xsave, xstate_size))
return -1;
}
if ((ia32_fxstate || !use_fxsr()) && save_fsave_header(tsk, buf))
return -1;
if (use_fxsr() && save_xstate_epilog(buf_fx, ia32_fxstate))
return -1;
drop_init_fpu(tsk);
return 0;
}
static inline void
sanitize_restored_xstate(struct task_struct *tsk,
struct user_i387_ia32_struct *ia32_env,
u64 xstate_bv, int fx_only)
{
struct xsave_struct *xsave = &tsk->thread.fpu.state->xsave;
struct xsave_hdr_struct *xsave_hdr = &xsave->xsave_hdr;
if (use_xsave()) {
memset(xsave_hdr->reserved, 0, 48);
if (fx_only)
xsave_hdr->xstate_bv = XSTATE_FPSSE;
else
xsave_hdr->xstate_bv &= (pcntxt_mask & xstate_bv);
}
if (use_fxsr()) {
xsave->i387.mxcsr &= mxcsr_feature_mask;
convert_to_fxsr(tsk, ia32_env);
}
}
static inline int restore_user_xstate(void __user *buf, u64 xbv, int fx_only)
{
if (use_xsave()) {
if ((unsigned long)buf % 64 || fx_only) {
u64 init_bv = pcntxt_mask & ~XSTATE_FPSSE;
xrstor_state(init_xstate_buf, init_bv);
return fxrstor_user(buf);
} else {
u64 init_bv = pcntxt_mask & ~xbv;
if (unlikely(init_bv))
xrstor_state(init_xstate_buf, init_bv);
return xrestore_user(buf, xbv);
}
} else if (use_fxsr()) {
return fxrstor_user(buf);
} else
return frstor_user(buf);
}
int __restore_xstate_sig(void __user *buf, void __user *buf_fx, int size)
{
int ia32_fxstate = (buf != buf_fx);
struct task_struct *tsk = current;
int state_size = xstate_size;
u64 xstate_bv = 0;
int fx_only = 0;
ia32_fxstate &= (config_enabled(CONFIG_X86_32) ||
config_enabled(CONFIG_IA32_EMULATION));
if (!buf) {
drop_init_fpu(tsk);
return 0;
}
if (!access_ok(VERIFY_READ, buf, size))
return -EACCES;
if (!used_math() && init_fpu(tsk))
return -1;
if (!static_cpu_has(X86_FEATURE_FPU))
return fpregs_soft_set(current, NULL,
0, sizeof(struct user_i387_ia32_struct),
NULL, buf) != 0;
if (use_xsave()) {
struct _fpx_sw_bytes fx_sw_user;
if (unlikely(check_for_xstate(buf_fx, buf_fx, &fx_sw_user))) {
state_size = sizeof(struct i387_fxsave_struct);
fx_only = 1;
} else {
state_size = fx_sw_user.xstate_size;
xstate_bv = fx_sw_user.xstate_bv;
}
}
if (ia32_fxstate) {
struct xsave_struct *xsave = &tsk->thread.fpu.state->xsave;
struct user_i387_ia32_struct env;
int err = 0;
drop_fpu(tsk);
if (__copy_from_user(xsave, buf_fx, state_size) ||
__copy_from_user(&env, buf, sizeof(env))) {
err = -1;
} else {
sanitize_restored_xstate(tsk, &env, xstate_bv, fx_only);
set_used_math();
}
if (use_eager_fpu())
math_state_restore();
return err;
} else {
user_fpu_begin();
if (restore_user_xstate(buf_fx, xstate_bv, fx_only)) {
drop_init_fpu(tsk);
return -1;
}
}
return 0;
}
static void prepare_fx_sw_frame(void)
{
int fsave_header_size = sizeof(struct i387_fsave_struct);
int size = xstate_size + FP_XSTATE_MAGIC2_SIZE;
if (config_enabled(CONFIG_X86_32))
size += fsave_header_size;
fx_sw_reserved.magic1 = FP_XSTATE_MAGIC1;
fx_sw_reserved.extended_size = size;
fx_sw_reserved.xstate_bv = pcntxt_mask;
fx_sw_reserved.xstate_size = xstate_size;
if (config_enabled(CONFIG_IA32_EMULATION)) {
fx_sw_reserved_ia32 = fx_sw_reserved;
fx_sw_reserved_ia32.extended_size += fsave_header_size;
}
}
static inline void xstate_enable(void)
{
set_in_cr4(X86_CR4_OSXSAVE);
xsetbv(XCR_XFEATURE_ENABLED_MASK, pcntxt_mask);
}
static void __init setup_xstate_features(void)
{
int eax, ebx, ecx, edx, leaf = 0x2;
xstate_features = fls64(pcntxt_mask);
xstate_offsets = alloc_bootmem(xstate_features * sizeof(int));
xstate_sizes = alloc_bootmem(xstate_features * sizeof(int));
do {
cpuid_count(XSTATE_CPUID, leaf, &eax, &ebx, &ecx, &edx);
if (eax == 0)
break;
xstate_offsets[leaf] = ebx;
xstate_sizes[leaf] = eax;
leaf++;
} while (1);
}
void setup_xstate_comp(void)
{
unsigned int xstate_comp_sizes[sizeof(pcntxt_mask)*8];
int i;
xstate_comp_offsets[0] = 0;
xstate_comp_offsets[1] = offsetof(struct i387_fxsave_struct, xmm_space);
if (!cpu_has_xsaves) {
for (i = 2; i < xstate_features; i++) {
if (test_bit(i, (unsigned long *)&pcntxt_mask)) {
xstate_comp_offsets[i] = xstate_offsets[i];
xstate_comp_sizes[i] = xstate_sizes[i];
}
}
return;
}
xstate_comp_offsets[2] = FXSAVE_SIZE + XSAVE_HDR_SIZE;
for (i = 2; i < xstate_features; i++) {
if (test_bit(i, (unsigned long *)&pcntxt_mask))
xstate_comp_sizes[i] = xstate_sizes[i];
else
xstate_comp_sizes[i] = 0;
if (i > 2)
xstate_comp_offsets[i] = xstate_comp_offsets[i-1]
+ xstate_comp_sizes[i-1];
}
}
static void __init setup_init_fpu_buf(void)
{
init_xstate_buf = alloc_bootmem_align(xstate_size,
__alignof__(struct xsave_struct));
fx_finit(&init_xstate_buf->i387);
if (!cpu_has_xsave)
return;
setup_xstate_features();
if (cpu_has_xsaves) {
init_xstate_buf->xsave_hdr.xcomp_bv =
(u64)1 << 63 | pcntxt_mask;
init_xstate_buf->xsave_hdr.xstate_bv = pcntxt_mask;
}
xrstor_state_booting(init_xstate_buf, -1);
xsave_state_booting(init_xstate_buf, -1);
}
static int __init eager_fpu_setup(char *s)
{
if (!strcmp(s, "on"))
eagerfpu = ENABLE;
else if (!strcmp(s, "off"))
eagerfpu = DISABLE;
else if (!strcmp(s, "auto"))
eagerfpu = AUTO;
return 1;
}
static void __init init_xstate_size(void)
{
unsigned int eax, ebx, ecx, edx;
int i;
if (!cpu_has_xsaves) {
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
xstate_size = ebx;
return;
}
xstate_size = FXSAVE_SIZE + XSAVE_HDR_SIZE;
for (i = 2; i < 64; i++) {
if (test_bit(i, (unsigned long *)&pcntxt_mask)) {
cpuid_count(XSTATE_CPUID, i, &eax, &ebx, &ecx, &edx);
xstate_size += eax;
}
}
}
static void __init xstate_enable_boot_cpu(void)
{
unsigned int eax, ebx, ecx, edx;
if (boot_cpu_data.cpuid_level < XSTATE_CPUID) {
WARN(1, KERN_ERR "XSTATE_CPUID missing\n");
return;
}
cpuid_count(XSTATE_CPUID, 0, &eax, &ebx, &ecx, &edx);
pcntxt_mask = eax + ((u64)edx << 32);
if ((pcntxt_mask & XSTATE_FPSSE) != XSTATE_FPSSE) {
pr_err("FP/SSE not shown under xsave features 0x%llx\n",
pcntxt_mask);
BUG();
}
pcntxt_mask = pcntxt_mask & XCNTXT_MASK;
xstate_enable();
init_xstate_size();
update_regset_xstate_info(xstate_size, pcntxt_mask);
prepare_fx_sw_frame();
setup_init_fpu_buf();
if (cpu_has_xsaveopt && eagerfpu != DISABLE)
eagerfpu = ENABLE;
if (pcntxt_mask & XSTATE_EAGER) {
if (eagerfpu == DISABLE) {
pr_err("eagerfpu not present, disabling some xstate features: 0x%llx\n",
pcntxt_mask & XSTATE_EAGER);
pcntxt_mask &= ~XSTATE_EAGER;
} else {
eagerfpu = ENABLE;
}
}
pr_info("enabled xstate_bv 0x%llx, cntxt size 0x%x using %s\n",
pcntxt_mask, xstate_size,
cpu_has_xsaves ? "compacted form" : "standard form");
}
void xsave_init(void)
{
static __refdata void (*next_func)(void) = xstate_enable_boot_cpu;
void (*this_func)(void);
if (!cpu_has_xsave)
return;
this_func = next_func;
next_func = xstate_enable;
this_func();
}
static inline void __init eager_fpu_init_bp(void)
{
current->thread.fpu.state =
alloc_bootmem_align(xstate_size, __alignof__(struct xsave_struct));
if (!init_xstate_buf)
setup_init_fpu_buf();
}
void eager_fpu_init(void)
{
static __refdata void (*boot_func)(void) = eager_fpu_init_bp;
clear_used_math();
current_thread_info()->status = 0;
if (eagerfpu == ENABLE)
setup_force_cpu_cap(X86_FEATURE_EAGER_FPU);
if (!cpu_has_eager_fpu) {
stts();
return;
}
if (boot_func) {
boot_func();
boot_func = NULL;
}
init_fpu(current);
__thread_fpu_begin(current);
if (cpu_has_xsave)
xrstor_state(init_xstate_buf, -1);
else
fxrstor_checking(&init_xstate_buf->i387);
}
void *get_xsave_addr(struct xsave_struct *xsave, int xstate)
{
int feature = fls64(xstate) - 1;
if (!test_bit(feature, (unsigned long *)&pcntxt_mask))
return NULL;
return (void *)xsave + xstate_comp_offsets[feature];
}
