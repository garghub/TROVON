static inline bool interrupted_kernel_fpu_idle(void)
{
return !__thread_has_fpu(current) &&
(read_cr0() & X86_CR0_TS);
}
static inline bool interrupted_user_mode(void)
{
struct pt_regs *regs = get_irq_regs();
return regs && user_mode_vm(regs);
}
bool irq_fpu_usable(void)
{
return !in_interrupt() ||
interrupted_user_mode() ||
interrupted_kernel_fpu_idle();
}
void kernel_fpu_begin(void)
{
struct task_struct *me = current;
WARN_ON_ONCE(!irq_fpu_usable());
preempt_disable();
if (__thread_has_fpu(me)) {
__save_init_fpu(me);
__thread_clear_has_fpu(me);
} else {
this_cpu_write(fpu_owner_task, NULL);
clts();
}
}
void kernel_fpu_end(void)
{
stts();
preempt_enable();
}
void unlazy_fpu(struct task_struct *tsk)
{
preempt_disable();
if (__thread_has_fpu(tsk)) {
__save_init_fpu(tsk);
__thread_fpu_end(tsk);
} else
tsk->fpu_counter = 0;
preempt_enable();
}
static void __cpuinit mxcsr_feature_mask_init(void)
{
unsigned long mask = 0;
clts();
if (cpu_has_fxsr) {
memset(&fx_scratch, 0, sizeof(struct i387_fxsave_struct));
asm volatile("fxsave %0" : : "m" (fx_scratch));
mask = fx_scratch.mxcsr_mask;
if (mask == 0)
mask = 0x0000ffbf;
}
mxcsr_feature_mask &= mask;
stts();
}
static void __cpuinit init_thread_xstate(void)
{
if (!HAVE_HWFP) {
setup_clear_cpu_cap(X86_FEATURE_XSAVE);
setup_clear_cpu_cap(X86_FEATURE_XSAVEOPT);
xstate_size = sizeof(struct i387_soft_struct);
return;
}
if (cpu_has_fxsr)
xstate_size = sizeof(struct i387_fxsave_struct);
else
xstate_size = sizeof(struct i387_fsave_struct);
}
void __cpuinit fpu_init(void)
{
unsigned long cr0;
unsigned long cr4_mask = 0;
if (cpu_has_fxsr)
cr4_mask |= X86_CR4_OSFXSR;
if (cpu_has_xmm)
cr4_mask |= X86_CR4_OSXMMEXCPT;
if (cr4_mask)
set_in_cr4(cr4_mask);
cr0 = read_cr0();
cr0 &= ~(X86_CR0_TS|X86_CR0_EM);
if (!HAVE_HWFP)
cr0 |= X86_CR0_EM;
write_cr0(cr0);
if (!smp_processor_id())
init_thread_xstate();
mxcsr_feature_mask_init();
current_thread_info()->status = 0;
clear_used_math();
}
void fpu_finit(struct fpu *fpu)
{
if (!HAVE_HWFP) {
finit_soft_fpu(&fpu->state->soft);
return;
}
if (cpu_has_fxsr) {
struct i387_fxsave_struct *fx = &fpu->state->fxsave;
memset(fx, 0, xstate_size);
fx->cwd = 0x37f;
if (cpu_has_xmm)
fx->mxcsr = MXCSR_DEFAULT;
} else {
struct i387_fsave_struct *fp = &fpu->state->fsave;
memset(fp, 0, xstate_size);
fp->cwd = 0xffff037fu;
fp->swd = 0xffff0000u;
fp->twd = 0xffffffffu;
fp->fos = 0xffff0000u;
}
}
int init_fpu(struct task_struct *tsk)
{
int ret;
if (tsk_used_math(tsk)) {
if (HAVE_HWFP && tsk == current)
unlazy_fpu(tsk);
tsk->thread.fpu.last_cpu = ~0;
return 0;
}
ret = fpu_alloc(&tsk->thread.fpu);
if (ret)
return ret;
fpu_finit(&tsk->thread.fpu);
set_stopped_child_used_math(tsk);
return 0;
}
int fpregs_active(struct task_struct *target, const struct user_regset *regset)
{
return tsk_used_math(target) ? regset->n : 0;
}
int xfpregs_active(struct task_struct *target, const struct user_regset *regset)
{
return (cpu_has_fxsr && tsk_used_math(target)) ? regset->n : 0;
}
int xfpregs_get(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
int ret;
if (!cpu_has_fxsr)
return -ENODEV;
ret = init_fpu(target);
if (ret)
return ret;
sanitize_i387_state(target);
return user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->fxsave, 0, -1);
}
int xfpregs_set(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
int ret;
if (!cpu_has_fxsr)
return -ENODEV;
ret = init_fpu(target);
if (ret)
return ret;
sanitize_i387_state(target);
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->fxsave, 0, -1);
target->thread.fpu.state->fxsave.mxcsr &= mxcsr_feature_mask;
if (cpu_has_xsave)
target->thread.fpu.state->xsave.xsave_hdr.xstate_bv |= XSTATE_FPSSE;
return ret;
}
int xstateregs_get(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
int ret;
if (!cpu_has_xsave)
return -ENODEV;
ret = init_fpu(target);
if (ret)
return ret;
memcpy(&target->thread.fpu.state->fxsave.sw_reserved,
xstate_fx_sw_bytes, sizeof(xstate_fx_sw_bytes));
ret = user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->xsave, 0, -1);
return ret;
}
int xstateregs_set(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
int ret;
struct xsave_hdr_struct *xsave_hdr;
if (!cpu_has_xsave)
return -ENODEV;
ret = init_fpu(target);
if (ret)
return ret;
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->xsave, 0, -1);
target->thread.fpu.state->fxsave.mxcsr &= mxcsr_feature_mask;
xsave_hdr = &target->thread.fpu.state->xsave.xsave_hdr;
xsave_hdr->xstate_bv &= pcntxt_mask;
xsave_hdr->reserved1[0] = xsave_hdr->reserved1[1] = 0;
return ret;
}
static inline unsigned short twd_i387_to_fxsr(unsigned short twd)
{
unsigned int tmp;
tmp = ~twd;
tmp = (tmp | (tmp>>1)) & 0x5555;
tmp = (tmp | (tmp >> 1)) & 0x3333;
tmp = (tmp | (tmp >> 2)) & 0x0f0f;
tmp = (tmp | (tmp >> 4)) & 0x00ff;
return tmp;
}
static inline u32 twd_fxsr_to_i387(struct i387_fxsave_struct *fxsave)
{
struct _fpxreg *st;
u32 tos = (fxsave->swd >> 11) & 7;
u32 twd = (unsigned long) fxsave->twd;
u32 tag;
u32 ret = 0xffff0000u;
int i;
for (i = 0; i < 8; i++, twd >>= 1) {
if (twd & 0x1) {
st = FPREG_ADDR(fxsave, (i - tos) & 7);
switch (st->exponent & 0x7fff) {
case 0x7fff:
tag = FP_EXP_TAG_SPECIAL;
break;
case 0x0000:
if (!st->significand[0] &&
!st->significand[1] &&
!st->significand[2] &&
!st->significand[3])
tag = FP_EXP_TAG_ZERO;
else
tag = FP_EXP_TAG_SPECIAL;
break;
default:
if (st->significand[3] & 0x8000)
tag = FP_EXP_TAG_VALID;
else
tag = FP_EXP_TAG_SPECIAL;
break;
}
} else {
tag = FP_EXP_TAG_EMPTY;
}
ret |= tag << (2 * i);
}
return ret;
}
static void
convert_from_fxsr(struct user_i387_ia32_struct *env, struct task_struct *tsk)
{
struct i387_fxsave_struct *fxsave = &tsk->thread.fpu.state->fxsave;
struct _fpreg *to = (struct _fpreg *) &env->st_space[0];
struct _fpxreg *from = (struct _fpxreg *) &fxsave->st_space[0];
int i;
env->cwd = fxsave->cwd | 0xffff0000u;
env->swd = fxsave->swd | 0xffff0000u;
env->twd = twd_fxsr_to_i387(fxsave);
#ifdef CONFIG_X86_64
env->fip = fxsave->rip;
env->foo = fxsave->rdp;
env->fcs = task_pt_regs(tsk)->cs;
if (tsk == current) {
savesegment(ds, env->fos);
} else {
env->fos = tsk->thread.ds;
}
env->fos |= 0xffff0000;
#else
env->fip = fxsave->fip;
env->fcs = (u16) fxsave->fcs | ((u32) fxsave->fop << 16);
env->foo = fxsave->foo;
env->fos = fxsave->fos;
#endif
for (i = 0; i < 8; ++i)
memcpy(&to[i], &from[i], sizeof(to[0]));
}
static void convert_to_fxsr(struct task_struct *tsk,
const struct user_i387_ia32_struct *env)
{
struct i387_fxsave_struct *fxsave = &tsk->thread.fpu.state->fxsave;
struct _fpreg *from = (struct _fpreg *) &env->st_space[0];
struct _fpxreg *to = (struct _fpxreg *) &fxsave->st_space[0];
int i;
fxsave->cwd = env->cwd;
fxsave->swd = env->swd;
fxsave->twd = twd_i387_to_fxsr(env->twd);
fxsave->fop = (u16) ((u32) env->fcs >> 16);
#ifdef CONFIG_X86_64
fxsave->rip = env->fip;
fxsave->rdp = env->foo;
#else
fxsave->fip = env->fip;
fxsave->fcs = (env->fcs & 0xffff);
fxsave->foo = env->foo;
fxsave->fos = env->fos;
#endif
for (i = 0; i < 8; ++i)
memcpy(&to[i], &from[i], sizeof(from[0]));
}
int fpregs_get(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
void *kbuf, void __user *ubuf)
{
struct user_i387_ia32_struct env;
int ret;
ret = init_fpu(target);
if (ret)
return ret;
if (!HAVE_HWFP)
return fpregs_soft_get(target, regset, pos, count, kbuf, ubuf);
if (!cpu_has_fxsr) {
return user_regset_copyout(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->fsave, 0,
-1);
}
sanitize_i387_state(target);
if (kbuf && pos == 0 && count == sizeof(env)) {
convert_from_fxsr(kbuf, target);
return 0;
}
convert_from_fxsr(&env, target);
return user_regset_copyout(&pos, &count, &kbuf, &ubuf, &env, 0, -1);
}
int fpregs_set(struct task_struct *target, const struct user_regset *regset,
unsigned int pos, unsigned int count,
const void *kbuf, const void __user *ubuf)
{
struct user_i387_ia32_struct env;
int ret;
ret = init_fpu(target);
if (ret)
return ret;
sanitize_i387_state(target);
if (!HAVE_HWFP)
return fpregs_soft_set(target, regset, pos, count, kbuf, ubuf);
if (!cpu_has_fxsr) {
return user_regset_copyin(&pos, &count, &kbuf, &ubuf,
&target->thread.fpu.state->fsave, 0, -1);
}
if (pos > 0 || count < sizeof(env))
convert_from_fxsr(&env, target);
ret = user_regset_copyin(&pos, &count, &kbuf, &ubuf, &env, 0, -1);
if (!ret)
convert_to_fxsr(target, &env);
if (cpu_has_xsave)
target->thread.fpu.state->xsave.xsave_hdr.xstate_bv |= XSTATE_FP;
return ret;
}
static inline int save_i387_fsave(struct _fpstate_ia32 __user *buf)
{
struct task_struct *tsk = current;
struct i387_fsave_struct *fp = &tsk->thread.fpu.state->fsave;
fp->status = fp->swd;
if (__copy_to_user(buf, fp, sizeof(struct i387_fsave_struct)))
return -1;
return 1;
}
static int save_i387_fxsave(struct _fpstate_ia32 __user *buf)
{
struct task_struct *tsk = current;
struct i387_fxsave_struct *fx = &tsk->thread.fpu.state->fxsave;
struct user_i387_ia32_struct env;
int err = 0;
convert_from_fxsr(&env, tsk);
if (__copy_to_user(buf, &env, sizeof(env)))
return -1;
err |= __put_user(fx->swd, &buf->status);
err |= __put_user(X86_FXSR_MAGIC, &buf->magic);
if (err)
return -1;
if (__copy_to_user(&buf->_fxsr_env[0], fx, xstate_size))
return -1;
return 1;
}
static int save_i387_xsave(void __user *buf)
{
struct task_struct *tsk = current;
struct _fpstate_ia32 __user *fx = buf;
int err = 0;
sanitize_i387_state(tsk);
tsk->thread.fpu.state->xsave.xsave_hdr.xstate_bv |= XSTATE_FPSSE;
if (save_i387_fxsave(fx) < 0)
return -1;
err = __copy_to_user(&fx->sw_reserved, &fx_sw_reserved_ia32,
sizeof(struct _fpx_sw_bytes));
err |= __put_user(FP_XSTATE_MAGIC2,
(__u32 __user *) (buf + sig_xstate_ia32_size
- FP_XSTATE_MAGIC2_SIZE));
if (err)
return -1;
return 1;
}
int save_i387_xstate_ia32(void __user *buf)
{
struct _fpstate_ia32 __user *fp = (struct _fpstate_ia32 __user *) buf;
struct task_struct *tsk = current;
if (!used_math())
return 0;
if (!access_ok(VERIFY_WRITE, buf, sig_xstate_ia32_size))
return -EACCES;
clear_used_math();
if (!HAVE_HWFP) {
return fpregs_soft_get(current, NULL,
0, sizeof(struct user_i387_ia32_struct),
NULL, fp) ? -1 : 1;
}
unlazy_fpu(tsk);
if (cpu_has_xsave)
return save_i387_xsave(fp);
if (cpu_has_fxsr)
return save_i387_fxsave(fp);
else
return save_i387_fsave(fp);
}
static inline int restore_i387_fsave(struct _fpstate_ia32 __user *buf)
{
struct task_struct *tsk = current;
return __copy_from_user(&tsk->thread.fpu.state->fsave, buf,
sizeof(struct i387_fsave_struct));
}
static int restore_i387_fxsave(struct _fpstate_ia32 __user *buf,
unsigned int size)
{
struct task_struct *tsk = current;
struct user_i387_ia32_struct env;
int err;
err = __copy_from_user(&tsk->thread.fpu.state->fxsave, &buf->_fxsr_env[0],
size);
tsk->thread.fpu.state->fxsave.mxcsr &= mxcsr_feature_mask;
if (err || __copy_from_user(&env, buf, sizeof(env)))
return 1;
convert_to_fxsr(tsk, &env);
return 0;
}
static int restore_i387_xsave(void __user *buf)
{
struct _fpx_sw_bytes fx_sw_user;
struct _fpstate_ia32 __user *fx_user =
((struct _fpstate_ia32 __user *) buf);
struct i387_fxsave_struct __user *fx =
(struct i387_fxsave_struct __user *) &fx_user->_fxsr_env[0];
struct xsave_hdr_struct *xsave_hdr =
&current->thread.fpu.state->xsave.xsave_hdr;
u64 mask;
int err;
if (check_for_xstate(fx, buf, &fx_sw_user))
goto fx_only;
mask = fx_sw_user.xstate_bv;
err = restore_i387_fxsave(buf, fx_sw_user.xstate_size);
xsave_hdr->xstate_bv &= pcntxt_mask;
xsave_hdr->reserved1[0] = xsave_hdr->reserved1[1] = 0;
mask = ~(pcntxt_mask & ~mask);
xsave_hdr->xstate_bv &= mask;
return err;
fx_only:
xsave_hdr->xstate_bv = XSTATE_FPSSE;
return restore_i387_fxsave(buf, sizeof(struct i387_fxsave_struct));
}
int restore_i387_xstate_ia32(void __user *buf)
{
int err;
struct task_struct *tsk = current;
struct _fpstate_ia32 __user *fp = (struct _fpstate_ia32 __user *) buf;
if (HAVE_HWFP)
clear_fpu(tsk);
if (!buf) {
if (used_math()) {
clear_fpu(tsk);
clear_used_math();
}
return 0;
} else
if (!access_ok(VERIFY_READ, buf, sig_xstate_ia32_size))
return -EACCES;
if (!used_math()) {
err = init_fpu(tsk);
if (err)
return err;
}
if (HAVE_HWFP) {
if (cpu_has_xsave)
err = restore_i387_xsave(buf);
else if (cpu_has_fxsr)
err = restore_i387_fxsave(fp, sizeof(struct
i387_fxsave_struct));
else
err = restore_i387_fsave(fp);
} else {
err = fpregs_soft_set(current, NULL,
0, sizeof(struct user_i387_ia32_struct),
NULL, fp) != 0;
}
set_used_math();
return err;
}
int dump_fpu(struct pt_regs *regs, struct user_i387_struct *fpu)
{
struct task_struct *tsk = current;
int fpvalid;
fpvalid = !!used_math();
if (fpvalid)
fpvalid = !fpregs_get(tsk, NULL,
0, sizeof(struct user_i387_ia32_struct),
fpu, NULL);
return fpvalid;
}
