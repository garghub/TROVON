static inline int put_sigset_t(compat_sigset_t __user *uset, sigset_t *set)
{
compat_sigset_t cset;
switch (_NSIG_WORDS) {
case 4: cset.sig[6] = set->sig[3] & 0xffffffffull;
cset.sig[7] = set->sig[3] >> 32;
case 3: cset.sig[4] = set->sig[2] & 0xffffffffull;
cset.sig[5] = set->sig[2] >> 32;
case 2: cset.sig[2] = set->sig[1] & 0xffffffffull;
cset.sig[3] = set->sig[1] >> 32;
case 1: cset.sig[0] = set->sig[0] & 0xffffffffull;
cset.sig[1] = set->sig[0] >> 32;
}
return copy_to_user(uset, &cset, sizeof(*uset));
}
static inline int get_sigset_t(sigset_t *set,
const compat_sigset_t __user *uset)
{
compat_sigset_t s32;
if (copy_from_user(&s32, uset, sizeof(*uset)))
return -EFAULT;
switch (_NSIG_WORDS) {
case 4: set->sig[3] = s32.sig[6] | (((long)s32.sig[7]) << 32);
case 3: set->sig[2] = s32.sig[4] | (((long)s32.sig[5]) << 32);
case 2: set->sig[1] = s32.sig[2] | (((long)s32.sig[3]) << 32);
case 1: set->sig[0] = s32.sig[0] | (((long)s32.sig[1]) << 32);
}
return 0;
}
static inline int save_general_regs(struct pt_regs *regs,
struct mcontext __user *frame)
{
elf_greg_t64 *gregs = (elf_greg_t64 *)regs;
int i;
WARN_ON(!FULL_REGS(regs));
for (i = 0; i <= PT_RESULT; i ++) {
if (i == 14 && !FULL_REGS(regs))
i = 32;
if (__put_user((unsigned int)gregs[i], &frame->mc_gregs[i]))
return -EFAULT;
}
return 0;
}
static inline int restore_general_regs(struct pt_regs *regs,
struct mcontext __user *sr)
{
elf_greg_t64 *gregs = (elf_greg_t64 *)regs;
int i;
for (i = 0; i <= PT_RESULT; i++) {
if ((i == PT_MSR) || (i == PT_SOFTE))
continue;
if (__get_user(gregs[i], &sr->mc_gregs[i]))
return -EFAULT;
}
return 0;
}
static inline int put_sigset_t(sigset_t __user *uset, sigset_t *set)
{
return copy_to_user(uset, set, sizeof(*uset));
}
static inline int get_sigset_t(sigset_t *set, const sigset_t __user *uset)
{
return copy_from_user(set, uset, sizeof(*uset));
}
static inline int save_general_regs(struct pt_regs *regs,
struct mcontext __user *frame)
{
WARN_ON(!FULL_REGS(regs));
return __copy_to_user(&frame->mc_gregs, regs, GP_REGS_SIZE);
}
static inline int restore_general_regs(struct pt_regs *regs,
struct mcontext __user *sr)
{
if (__copy_from_user(regs, &sr->mc_gregs,
PT_MSR * sizeof(elf_greg_t)))
return -EFAULT;
if (__copy_from_user(&regs->orig_gpr3, &sr->mc_gregs[PT_ORIG_R3],
GP_REGS_SIZE - PT_ORIG_R3 * sizeof(elf_greg_t)))
return -EFAULT;
return 0;
}
unsigned long copy_fpr_to_user(void __user *to,
struct task_struct *task)
{
u64 buf[ELF_NFPREG];
int i;
for (i = 0; i < (ELF_NFPREG - 1) ; i++)
buf[i] = task->thread.TS_FPR(i);
buf[i] = task->thread.fp_state.fpscr;
return __copy_to_user(to, buf, ELF_NFPREG * sizeof(double));
}
unsigned long copy_fpr_from_user(struct task_struct *task,
void __user *from)
{
u64 buf[ELF_NFPREG];
int i;
if (__copy_from_user(buf, from, ELF_NFPREG * sizeof(double)))
return 1;
for (i = 0; i < (ELF_NFPREG - 1) ; i++)
task->thread.TS_FPR(i) = buf[i];
task->thread.fp_state.fpscr = buf[i];
return 0;
}
unsigned long copy_vsx_to_user(void __user *to,
struct task_struct *task)
{
u64 buf[ELF_NVSRHALFREG];
int i;
for (i = 0; i < ELF_NVSRHALFREG; i++)
buf[i] = task->thread.fp_state.fpr[i][TS_VSRLOWOFFSET];
return __copy_to_user(to, buf, ELF_NVSRHALFREG * sizeof(double));
}
unsigned long copy_vsx_from_user(struct task_struct *task,
void __user *from)
{
u64 buf[ELF_NVSRHALFREG];
int i;
if (__copy_from_user(buf, from, ELF_NVSRHALFREG * sizeof(double)))
return 1;
for (i = 0; i < ELF_NVSRHALFREG ; i++)
task->thread.fp_state.fpr[i][TS_VSRLOWOFFSET] = buf[i];
return 0;
}
unsigned long copy_ckfpr_to_user(void __user *to,
struct task_struct *task)
{
u64 buf[ELF_NFPREG];
int i;
for (i = 0; i < (ELF_NFPREG - 1) ; i++)
buf[i] = task->thread.TS_CKFPR(i);
buf[i] = task->thread.ckfp_state.fpscr;
return __copy_to_user(to, buf, ELF_NFPREG * sizeof(double));
}
unsigned long copy_ckfpr_from_user(struct task_struct *task,
void __user *from)
{
u64 buf[ELF_NFPREG];
int i;
if (__copy_from_user(buf, from, ELF_NFPREG * sizeof(double)))
return 1;
for (i = 0; i < (ELF_NFPREG - 1) ; i++)
task->thread.TS_CKFPR(i) = buf[i];
task->thread.ckfp_state.fpscr = buf[i];
return 0;
}
unsigned long copy_ckvsx_to_user(void __user *to,
struct task_struct *task)
{
u64 buf[ELF_NVSRHALFREG];
int i;
for (i = 0; i < ELF_NVSRHALFREG; i++)
buf[i] = task->thread.ckfp_state.fpr[i][TS_VSRLOWOFFSET];
return __copy_to_user(to, buf, ELF_NVSRHALFREG * sizeof(double));
}
unsigned long copy_ckvsx_from_user(struct task_struct *task,
void __user *from)
{
u64 buf[ELF_NVSRHALFREG];
int i;
if (__copy_from_user(buf, from, ELF_NVSRHALFREG * sizeof(double)))
return 1;
for (i = 0; i < ELF_NVSRHALFREG ; i++)
task->thread.ckfp_state.fpr[i][TS_VSRLOWOFFSET] = buf[i];
return 0;
}
inline unsigned long copy_fpr_to_user(void __user *to,
struct task_struct *task)
{
return __copy_to_user(to, task->thread.fp_state.fpr,
ELF_NFPREG * sizeof(double));
}
inline unsigned long copy_fpr_from_user(struct task_struct *task,
void __user *from)
{
return __copy_from_user(task->thread.fp_state.fpr, from,
ELF_NFPREG * sizeof(double));
}
inline unsigned long copy_ckfpr_to_user(void __user *to,
struct task_struct *task)
{
return __copy_to_user(to, task->thread.ckfp_state.fpr,
ELF_NFPREG * sizeof(double));
}
inline unsigned long copy_ckfpr_from_user(struct task_struct *task,
void __user *from)
{
return __copy_from_user(task->thread.ckfp_state.fpr, from,
ELF_NFPREG * sizeof(double));
}
static int save_user_regs(struct pt_regs *regs, struct mcontext __user *frame,
struct mcontext __user *tm_frame, int sigret,
int ctx_has_vsx_region)
{
unsigned long msr = regs->msr;
flush_fp_to_thread(current);
if (save_general_regs(regs, frame))
return 1;
#ifdef CONFIG_ALTIVEC
if (current->thread.used_vr) {
flush_altivec_to_thread(current);
if (__copy_to_user(&frame->mc_vregs, &current->thread.vr_state,
ELF_NVRREG * sizeof(vector128)))
return 1;
msr |= MSR_VEC;
}
if (cpu_has_feature(CPU_FTR_ALTIVEC))
current->thread.vrsave = mfspr(SPRN_VRSAVE);
if (__put_user(current->thread.vrsave, (u32 __user *)&frame->mc_vregs[32]))
return 1;
#endif
if (copy_fpr_to_user(&frame->mc_fregs, current))
return 1;
msr &= ~MSR_VSX;
#ifdef CONFIG_VSX
if (current->thread.used_vsr && ctx_has_vsx_region) {
flush_vsx_to_thread(current);
if (copy_vsx_to_user(&frame->mc_vsregs, current))
return 1;
msr |= MSR_VSX;
}
#endif
#ifdef CONFIG_SPE
if (current->thread.used_spe) {
flush_spe_to_thread(current);
if (__copy_to_user(&frame->mc_vregs, current->thread.evr,
ELF_NEVRREG * sizeof(u32)))
return 1;
msr |= MSR_SPE;
}
if (__put_user(current->thread.spefscr, (u32 __user *)&frame->mc_vregs + ELF_NEVRREG))
return 1;
#endif
if (__put_user(msr, &frame->mc_gregs[PT_MSR]))
return 1;
if (tm_frame && __put_user(0, &tm_frame->mc_gregs[PT_MSR]))
return 1;
if (sigret) {
if (__put_user(0x38000000UL + sigret, &frame->tramp[0])
|| __put_user(0x44000002UL, &frame->tramp[1]))
return 1;
flush_icache_range((unsigned long) &frame->tramp[0],
(unsigned long) &frame->tramp[2]);
}
return 0;
}
static int save_tm_user_regs(struct pt_regs *regs,
struct mcontext __user *frame,
struct mcontext __user *tm_frame, int sigret)
{
unsigned long msr = regs->msr;
regs->msr &= ~MSR_TS_MASK;
if (save_general_regs(&current->thread.ckpt_regs, frame)
|| save_general_regs(regs, tm_frame))
return 1;
if (__put_user((msr >> 32), &tm_frame->mc_gregs[PT_MSR]))
return 1;
#ifdef CONFIG_ALTIVEC
if (current->thread.used_vr) {
if (__copy_to_user(&frame->mc_vregs, &current->thread.ckvr_state,
ELF_NVRREG * sizeof(vector128)))
return 1;
if (msr & MSR_VEC) {
if (__copy_to_user(&tm_frame->mc_vregs,
&current->thread.vr_state,
ELF_NVRREG * sizeof(vector128)))
return 1;
} else {
if (__copy_to_user(&tm_frame->mc_vregs,
&current->thread.ckvr_state,
ELF_NVRREG * sizeof(vector128)))
return 1;
}
msr |= MSR_VEC;
}
if (cpu_has_feature(CPU_FTR_ALTIVEC))
current->thread.ckvrsave = mfspr(SPRN_VRSAVE);
if (__put_user(current->thread.ckvrsave,
(u32 __user *)&frame->mc_vregs[32]))
return 1;
if (msr & MSR_VEC) {
if (__put_user(current->thread.vrsave,
(u32 __user *)&tm_frame->mc_vregs[32]))
return 1;
} else {
if (__put_user(current->thread.ckvrsave,
(u32 __user *)&tm_frame->mc_vregs[32]))
return 1;
}
#endif
if (copy_ckfpr_to_user(&frame->mc_fregs, current))
return 1;
if (msr & MSR_FP) {
if (copy_fpr_to_user(&tm_frame->mc_fregs, current))
return 1;
} else {
if (copy_ckfpr_to_user(&tm_frame->mc_fregs, current))
return 1;
}
#ifdef CONFIG_VSX
if (current->thread.used_vsr) {
if (copy_ckvsx_to_user(&frame->mc_vsregs, current))
return 1;
if (msr & MSR_VSX) {
if (copy_vsx_to_user(&tm_frame->mc_vsregs,
current))
return 1;
} else {
if (copy_ckvsx_to_user(&tm_frame->mc_vsregs, current))
return 1;
}
msr |= MSR_VSX;
}
#endif
#ifdef CONFIG_SPE
if (current->thread.used_spe) {
flush_spe_to_thread(current);
if (__copy_to_user(&frame->mc_vregs, current->thread.evr,
ELF_NEVRREG * sizeof(u32)))
return 1;
msr |= MSR_SPE;
}
if (__put_user(current->thread.spefscr, (u32 __user *)&frame->mc_vregs + ELF_NEVRREG))
return 1;
#endif
if (__put_user(msr, &frame->mc_gregs[PT_MSR]))
return 1;
if (sigret) {
if (__put_user(0x38000000UL + sigret, &frame->tramp[0])
|| __put_user(0x44000002UL, &frame->tramp[1]))
return 1;
flush_icache_range((unsigned long) &frame->tramp[0],
(unsigned long) &frame->tramp[2]);
}
return 0;
}
static long restore_user_regs(struct pt_regs *regs,
struct mcontext __user *sr, int sig)
{
long err;
unsigned int save_r2 = 0;
unsigned long msr;
#ifdef CONFIG_VSX
int i;
#endif
if (!sig)
save_r2 = (unsigned int)regs->gpr[2];
err = restore_general_regs(regs, sr);
regs->trap = 0;
err |= __get_user(msr, &sr->mc_gregs[PT_MSR]);
if (!sig)
regs->gpr[2] = (unsigned long) save_r2;
if (err)
return 1;
if (sig)
regs->msr = (regs->msr & ~MSR_LE) | (msr & MSR_LE);
#ifdef CONFIG_ALTIVEC
regs->msr &= ~MSR_VEC;
if (msr & MSR_VEC) {
if (__copy_from_user(&current->thread.vr_state, &sr->mc_vregs,
sizeof(sr->mc_vregs)))
return 1;
current->thread.used_vr = true;
} else if (current->thread.used_vr)
memset(&current->thread.vr_state, 0,
ELF_NVRREG * sizeof(vector128));
if (__get_user(current->thread.vrsave, (u32 __user *)&sr->mc_vregs[32]))
return 1;
if (cpu_has_feature(CPU_FTR_ALTIVEC))
mtspr(SPRN_VRSAVE, current->thread.vrsave);
#endif
if (copy_fpr_from_user(current, &sr->mc_fregs))
return 1;
#ifdef CONFIG_VSX
regs->msr &= ~MSR_VSX;
if (msr & MSR_VSX) {
if (copy_vsx_from_user(current, &sr->mc_vsregs))
return 1;
current->thread.used_vsr = true;
} else if (current->thread.used_vsr)
for (i = 0; i < 32 ; i++)
current->thread.fp_state.fpr[i][TS_VSRLOWOFFSET] = 0;
#endif
regs->msr &= ~(MSR_FP | MSR_FE0 | MSR_FE1);
#ifdef CONFIG_SPE
regs->msr &= ~MSR_SPE;
if (msr & MSR_SPE) {
if (__copy_from_user(current->thread.evr, &sr->mc_vregs,
ELF_NEVRREG * sizeof(u32)))
return 1;
current->thread.used_spe = true;
} else if (current->thread.used_spe)
memset(current->thread.evr, 0, ELF_NEVRREG * sizeof(u32));
if (__get_user(current->thread.spefscr, (u32 __user *)&sr->mc_vregs + ELF_NEVRREG))
return 1;
#endif
return 0;
}
static long restore_tm_user_regs(struct pt_regs *regs,
struct mcontext __user *sr,
struct mcontext __user *tm_sr)
{
long err;
unsigned long msr, msr_hi;
#ifdef CONFIG_VSX
int i;
#endif
err = restore_general_regs(regs, tm_sr);
err |= restore_general_regs(&current->thread.ckpt_regs, sr);
err |= __get_user(current->thread.tm_tfhar, &sr->mc_gregs[PT_NIP]);
err |= __get_user(msr, &sr->mc_gregs[PT_MSR]);
if (err)
return 1;
regs->msr = (regs->msr & ~MSR_LE) | (msr & MSR_LE);
#ifdef CONFIG_ALTIVEC
regs->msr &= ~MSR_VEC;
if (msr & MSR_VEC) {
if (__copy_from_user(&current->thread.ckvr_state, &sr->mc_vregs,
sizeof(sr->mc_vregs)) ||
__copy_from_user(&current->thread.vr_state,
&tm_sr->mc_vregs,
sizeof(sr->mc_vregs)))
return 1;
current->thread.used_vr = true;
} else if (current->thread.used_vr) {
memset(&current->thread.vr_state, 0,
ELF_NVRREG * sizeof(vector128));
memset(&current->thread.ckvr_state, 0,
ELF_NVRREG * sizeof(vector128));
}
if (__get_user(current->thread.ckvrsave,
(u32 __user *)&sr->mc_vregs[32]) ||
__get_user(current->thread.vrsave,
(u32 __user *)&tm_sr->mc_vregs[32]))
return 1;
if (cpu_has_feature(CPU_FTR_ALTIVEC))
mtspr(SPRN_VRSAVE, current->thread.ckvrsave);
#endif
regs->msr &= ~(MSR_FP | MSR_FE0 | MSR_FE1);
if (copy_fpr_from_user(current, &sr->mc_fregs) ||
copy_ckfpr_from_user(current, &tm_sr->mc_fregs))
return 1;
#ifdef CONFIG_VSX
regs->msr &= ~MSR_VSX;
if (msr & MSR_VSX) {
if (copy_vsx_from_user(current, &tm_sr->mc_vsregs) ||
copy_ckvsx_from_user(current, &sr->mc_vsregs))
return 1;
current->thread.used_vsr = true;
} else if (current->thread.used_vsr)
for (i = 0; i < 32 ; i++) {
current->thread.fp_state.fpr[i][TS_VSRLOWOFFSET] = 0;
current->thread.ckfp_state.fpr[i][TS_VSRLOWOFFSET] = 0;
}
#endif
#ifdef CONFIG_SPE
regs->msr &= ~MSR_SPE;
if (msr & MSR_SPE) {
if (__copy_from_user(current->thread.evr, &sr->mc_vregs,
ELF_NEVRREG * sizeof(u32)))
return 1;
current->thread.used_spe = true;
} else if (current->thread.used_spe)
memset(current->thread.evr, 0, ELF_NEVRREG * sizeof(u32));
if (__get_user(current->thread.spefscr, (u32 __user *)&sr->mc_vregs
+ ELF_NEVRREG))
return 1;
#endif
if (__get_user(msr_hi, &tm_sr->mc_gregs[PT_MSR]))
return 1;
msr_hi <<= 32;
if (MSR_TM_RESV(msr_hi))
return 1;
regs->msr = (regs->msr & ~MSR_TS_MASK) | (msr_hi & MSR_TS_MASK);
tm_enable();
current->thread.tm_texasr |= TEXASR_FS;
tm_recheckpoint(&current->thread, msr);
msr_check_and_set(msr & (MSR_FP | MSR_VEC));
if (msr & MSR_FP) {
load_fp_state(&current->thread.fp_state);
regs->msr |= (MSR_FP | current->thread.fpexc_mode);
}
#ifdef CONFIG_ALTIVEC
if (msr & MSR_VEC) {
load_vr_state(&current->thread.vr_state);
regs->msr |= MSR_VEC;
}
#endif
return 0;
}
int copy_siginfo_to_user32(struct compat_siginfo __user *d, const siginfo_t *s)
{
int err;
if (!access_ok (VERIFY_WRITE, d, sizeof(*d)))
return -EFAULT;
err = __put_user(s->si_signo, &d->si_signo);
err |= __put_user(s->si_errno, &d->si_errno);
err |= __put_user(s->si_code, &d->si_code);
if (s->si_code < 0)
err |= __copy_to_user(&d->_sifields._pad, &s->_sifields._pad,
SI_PAD_SIZE32);
else switch(siginfo_layout(s->si_signo, s->si_code)) {
case SIL_CHLD:
err |= __put_user(s->si_pid, &d->si_pid);
err |= __put_user(s->si_uid, &d->si_uid);
err |= __put_user(s->si_utime, &d->si_utime);
err |= __put_user(s->si_stime, &d->si_stime);
err |= __put_user(s->si_status, &d->si_status);
break;
case SIL_FAULT:
err |= __put_user((unsigned int)(unsigned long)s->si_addr,
&d->si_addr);
break;
case SIL_POLL:
err |= __put_user(s->si_band, &d->si_band);
err |= __put_user(s->si_fd, &d->si_fd);
break;
case SIL_TIMER:
err |= __put_user(s->si_tid, &d->si_tid);
err |= __put_user(s->si_overrun, &d->si_overrun);
err |= __put_user(s->si_int, &d->si_int);
break;
case SIL_SYS:
err |= __put_user(ptr_to_compat(s->si_call_addr), &d->si_call_addr);
err |= __put_user(s->si_syscall, &d->si_syscall);
err |= __put_user(s->si_arch, &d->si_arch);
break;
case SIL_RT:
err |= __put_user(s->si_int, &d->si_int);
case SIL_KILL:
err |= __put_user(s->si_pid, &d->si_pid);
err |= __put_user(s->si_uid, &d->si_uid);
break;
}
return err;
}
int copy_siginfo_from_user32(siginfo_t *to, struct compat_siginfo __user *from)
{
if (copy_from_user(to, from, 3*sizeof(int)) ||
copy_from_user(to->_sifields._pad,
from->_sifields._pad, SI_PAD_SIZE32))
return -EFAULT;
return 0;
}
int handle_rt_signal32(struct ksignal *ksig, sigset_t *oldset,
struct task_struct *tsk)
{
struct rt_sigframe __user *rt_sf;
struct mcontext __user *frame;
struct mcontext __user *tm_frame = NULL;
void __user *addr;
unsigned long newsp = 0;
int sigret;
unsigned long tramp;
struct pt_regs *regs = tsk->thread.regs;
BUG_ON(tsk != current);
rt_sf = get_sigframe(ksig, get_tm_stackpointer(tsk), sizeof(*rt_sf), 1);
addr = rt_sf;
if (unlikely(rt_sf == NULL))
goto badframe;
if (copy_siginfo_to_user(&rt_sf->info, &ksig->info)
|| __put_user(0, &rt_sf->uc.uc_flags)
|| __save_altstack(&rt_sf->uc.uc_stack, regs->gpr[1])
|| __put_user(to_user_ptr(&rt_sf->uc.uc_mcontext),
&rt_sf->uc.uc_regs)
|| put_sigset_t(&rt_sf->uc.uc_sigmask, oldset))
goto badframe;
frame = &rt_sf->uc.uc_mcontext;
addr = frame;
if (vdso32_rt_sigtramp && tsk->mm->context.vdso_base) {
sigret = 0;
tramp = tsk->mm->context.vdso_base + vdso32_rt_sigtramp;
} else {
sigret = __NR_rt_sigreturn;
tramp = (unsigned long) frame->tramp;
}
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
tm_frame = &rt_sf->uc_transact.uc_mcontext;
if (MSR_TM_ACTIVE(regs->msr)) {
if (__put_user((unsigned long)&rt_sf->uc_transact,
&rt_sf->uc.uc_link) ||
__put_user((unsigned long)tm_frame,
&rt_sf->uc_transact.uc_regs))
goto badframe;
if (save_tm_user_regs(regs, frame, tm_frame, sigret))
goto badframe;
}
else
#endif
{
if (__put_user(0, &rt_sf->uc.uc_link))
goto badframe;
if (save_user_regs(regs, frame, tm_frame, sigret, 1))
goto badframe;
}
regs->link = tramp;
tsk->thread.fp_state.fpscr = 0;
newsp = ((unsigned long)rt_sf) - (__SIGNAL_FRAMESIZE + 16);
addr = (void __user *)regs->gpr[1];
if (put_user(regs->gpr[1], (u32 __user *)newsp))
goto badframe;
regs->gpr[1] = newsp;
regs->gpr[3] = ksig->sig;
regs->gpr[4] = (unsigned long) &rt_sf->info;
regs->gpr[5] = (unsigned long) &rt_sf->uc;
regs->gpr[6] = (unsigned long) rt_sf;
regs->nip = (unsigned long) ksig->ka.sa.sa_handler;
regs->msr &= ~MSR_LE;
regs->msr |= (MSR_KERNEL & MSR_LE);
return 0;
badframe:
if (show_unhandled_signals)
printk_ratelimited(KERN_INFO
"%s[%d]: bad frame in handle_rt_signal32: "
"%p nip %08lx lr %08lx\n",
tsk->comm, tsk->pid,
addr, regs->nip, regs->link);
return 1;
}
static int do_setcontext(struct ucontext __user *ucp, struct pt_regs *regs, int sig)
{
sigset_t set;
struct mcontext __user *mcp;
if (get_sigset_t(&set, &ucp->uc_sigmask))
return -EFAULT;
#ifdef CONFIG_PPC64
{
u32 cmcp;
if (__get_user(cmcp, &ucp->uc_regs))
return -EFAULT;
mcp = (struct mcontext __user *)(u64)cmcp;
}
#else
if (__get_user(mcp, &ucp->uc_regs))
return -EFAULT;
if (!access_ok(VERIFY_READ, mcp, sizeof(*mcp)))
return -EFAULT;
#endif
set_current_blocked(&set);
if (restore_user_regs(regs, mcp, sig))
return -EFAULT;
return 0;
}
static int do_setcontext_tm(struct ucontext __user *ucp,
struct ucontext __user *tm_ucp,
struct pt_regs *regs)
{
sigset_t set;
struct mcontext __user *mcp;
struct mcontext __user *tm_mcp;
u32 cmcp;
u32 tm_cmcp;
if (get_sigset_t(&set, &ucp->uc_sigmask))
return -EFAULT;
if (__get_user(cmcp, &ucp->uc_regs) ||
__get_user(tm_cmcp, &tm_ucp->uc_regs))
return -EFAULT;
mcp = (struct mcontext __user *)(u64)cmcp;
tm_mcp = (struct mcontext __user *)(u64)tm_cmcp;
set_current_blocked(&set);
if (restore_tm_user_regs(regs, mcp, tm_mcp))
return -EFAULT;
return 0;
}
long sys_swapcontext(struct ucontext __user *old_ctx,
struct ucontext __user *new_ctx,
int ctx_size, int r6, int r7, int r8, struct pt_regs *regs)
{
unsigned char tmp;
int ctx_has_vsx_region = 0;
#ifdef CONFIG_PPC64
unsigned long new_msr = 0;
if (new_ctx) {
struct mcontext __user *mcp;
u32 cmcp;
if (__get_user(cmcp, &new_ctx->uc_regs))
return -EFAULT;
mcp = (struct mcontext __user *)(u64)cmcp;
if (__get_user(new_msr, &mcp->mc_gregs[PT_MSR]))
return -EFAULT;
}
if (ctx_size < UCONTEXTSIZEWITHOUTVSX)
return -EINVAL;
if ((ctx_size < sizeof(struct ucontext)) &&
(new_msr & MSR_VSX))
return -EINVAL;
if (ctx_size >= sizeof(struct ucontext))
ctx_has_vsx_region = 1;
#else
if (ctx_size < sizeof(struct ucontext))
return -EINVAL;
#endif
if (old_ctx != NULL) {
struct mcontext __user *mctx;
mctx = (struct mcontext __user *)
((unsigned long) &old_ctx->uc_mcontext & ~0xfUL);
if (!access_ok(VERIFY_WRITE, old_ctx, ctx_size)
|| save_user_regs(regs, mctx, NULL, 0, ctx_has_vsx_region)
|| put_sigset_t(&old_ctx->uc_sigmask, &current->blocked)
|| __put_user(to_user_ptr(mctx), &old_ctx->uc_regs))
return -EFAULT;
}
if (new_ctx == NULL)
return 0;
if (!access_ok(VERIFY_READ, new_ctx, ctx_size)
|| __get_user(tmp, (u8 __user *) new_ctx)
|| __get_user(tmp, (u8 __user *) new_ctx + ctx_size - 1))
return -EFAULT;
if (do_setcontext(new_ctx, regs, 0))
do_exit(SIGSEGV);
set_thread_flag(TIF_RESTOREALL);
return 0;
}
long sys_rt_sigreturn(int r3, int r4, int r5, int r6, int r7, int r8,
struct pt_regs *regs)
{
struct rt_sigframe __user *rt_sf;
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
struct ucontext __user *uc_transact;
unsigned long msr_hi;
unsigned long tmp;
int tm_restore = 0;
#endif
current->restart_block.fn = do_no_restart_syscall;
rt_sf = (struct rt_sigframe __user *)
(regs->gpr[1] + __SIGNAL_FRAMESIZE + 16);
if (!access_ok(VERIFY_READ, rt_sf, sizeof(*rt_sf)))
goto bad;
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
if (MSR_TM_SUSPENDED(mfmsr()))
tm_reclaim_current(0);
if (__get_user(tmp, &rt_sf->uc.uc_link))
goto bad;
uc_transact = (struct ucontext __user *)(uintptr_t)tmp;
if (uc_transact) {
u32 cmcp;
struct mcontext __user *mcp;
if (__get_user(cmcp, &uc_transact->uc_regs))
return -EFAULT;
mcp = (struct mcontext __user *)(u64)cmcp;
if (__get_user(msr_hi, &mcp->mc_gregs[PT_MSR]))
goto bad;
if (MSR_TM_ACTIVE(msr_hi<<32)) {
tm_restore = 1;
if (do_setcontext_tm(&rt_sf->uc, uc_transact, regs))
goto bad;
}
}
if (!tm_restore)
#endif
if (do_setcontext(&rt_sf->uc, regs, 1))
goto bad;
#ifdef CONFIG_PPC64
if (compat_restore_altstack(&rt_sf->uc.uc_stack))
goto bad;
#else
if (restore_altstack(&rt_sf->uc.uc_stack))
goto bad;
#endif
set_thread_flag(TIF_RESTOREALL);
return 0;
bad:
if (show_unhandled_signals)
printk_ratelimited(KERN_INFO
"%s[%d]: bad frame in sys_rt_sigreturn: "
"%p nip %08lx lr %08lx\n",
current->comm, current->pid,
rt_sf, regs->nip, regs->link);
force_sig(SIGSEGV, current);
return 0;
}
int sys_debug_setcontext(struct ucontext __user *ctx,
int ndbg, struct sig_dbg_op __user *dbg,
int r6, int r7, int r8,
struct pt_regs *regs)
{
struct sig_dbg_op op;
int i;
unsigned char tmp;
unsigned long new_msr = regs->msr;
#ifdef CONFIG_PPC_ADV_DEBUG_REGS
unsigned long new_dbcr0 = current->thread.debug.dbcr0;
#endif
for (i=0; i<ndbg; i++) {
if (copy_from_user(&op, dbg + i, sizeof(op)))
return -EFAULT;
switch (op.dbg_type) {
case SIG_DBG_SINGLE_STEPPING:
#ifdef CONFIG_PPC_ADV_DEBUG_REGS
if (op.dbg_value) {
new_msr |= MSR_DE;
new_dbcr0 |= (DBCR0_IDM | DBCR0_IC);
} else {
new_dbcr0 &= ~DBCR0_IC;
if (!DBCR_ACTIVE_EVENTS(new_dbcr0,
current->thread.debug.dbcr1)) {
new_msr &= ~MSR_DE;
new_dbcr0 &= ~DBCR0_IDM;
}
}
#else
if (op.dbg_value)
new_msr |= MSR_SE;
else
new_msr &= ~MSR_SE;
#endif
break;
case SIG_DBG_BRANCH_TRACING:
#ifdef CONFIG_PPC_ADV_DEBUG_REGS
return -EINVAL;
#else
if (op.dbg_value)
new_msr |= MSR_BE;
else
new_msr &= ~MSR_BE;
#endif
break;
default:
return -EINVAL;
}
}
regs->msr = new_msr;
#ifdef CONFIG_PPC_ADV_DEBUG_REGS
current->thread.debug.dbcr0 = new_dbcr0;
#endif
if (!access_ok(VERIFY_READ, ctx, sizeof(*ctx))
|| __get_user(tmp, (u8 __user *) ctx)
|| __get_user(tmp, (u8 __user *) (ctx + 1) - 1))
return -EFAULT;
if (do_setcontext(ctx, regs, 1)) {
if (show_unhandled_signals)
printk_ratelimited(KERN_INFO "%s[%d]: bad frame in "
"sys_debug_setcontext: %p nip %08lx "
"lr %08lx\n",
current->comm, current->pid,
ctx, regs->nip, regs->link);
force_sig(SIGSEGV, current);
goto out;
}
restore_altstack(&ctx->uc_stack);
set_thread_flag(TIF_RESTOREALL);
out:
return 0;
}
int handle_signal32(struct ksignal *ksig, sigset_t *oldset,
struct task_struct *tsk)
{
struct sigcontext __user *sc;
struct sigframe __user *frame;
struct mcontext __user *tm_mctx = NULL;
unsigned long newsp = 0;
int sigret;
unsigned long tramp;
struct pt_regs *regs = tsk->thread.regs;
BUG_ON(tsk != current);
frame = get_sigframe(ksig, get_tm_stackpointer(tsk), sizeof(*frame), 1);
if (unlikely(frame == NULL))
goto badframe;
sc = (struct sigcontext __user *) &frame->sctx;
#if _NSIG != 64
#error "Please adjust handle_signal()"
#endif
if (__put_user(to_user_ptr(ksig->ka.sa.sa_handler), &sc->handler)
|| __put_user(oldset->sig[0], &sc->oldmask)
#ifdef CONFIG_PPC64
|| __put_user((oldset->sig[0] >> 32), &sc->_unused[3])
#else
|| __put_user(oldset->sig[1], &sc->_unused[3])
#endif
|| __put_user(to_user_ptr(&frame->mctx), &sc->regs)
|| __put_user(ksig->sig, &sc->signal))
goto badframe;
if (vdso32_sigtramp && tsk->mm->context.vdso_base) {
sigret = 0;
tramp = tsk->mm->context.vdso_base + vdso32_sigtramp;
} else {
sigret = __NR_sigreturn;
tramp = (unsigned long) frame->mctx.tramp;
}
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
tm_mctx = &frame->mctx_transact;
if (MSR_TM_ACTIVE(regs->msr)) {
if (save_tm_user_regs(regs, &frame->mctx, &frame->mctx_transact,
sigret))
goto badframe;
}
else
#endif
{
if (save_user_regs(regs, &frame->mctx, tm_mctx, sigret, 1))
goto badframe;
}
regs->link = tramp;
tsk->thread.fp_state.fpscr = 0;
newsp = ((unsigned long)frame) - __SIGNAL_FRAMESIZE;
if (put_user(regs->gpr[1], (u32 __user *)newsp))
goto badframe;
regs->gpr[1] = newsp;
regs->gpr[3] = ksig->sig;
regs->gpr[4] = (unsigned long) sc;
regs->nip = (unsigned long) (unsigned long)ksig->ka.sa.sa_handler;
regs->msr &= ~MSR_LE;
return 0;
badframe:
if (show_unhandled_signals)
printk_ratelimited(KERN_INFO
"%s[%d]: bad frame in handle_signal32: "
"%p nip %08lx lr %08lx\n",
tsk->comm, tsk->pid,
frame, regs->nip, regs->link);
return 1;
}
long sys_sigreturn(int r3, int r4, int r5, int r6, int r7, int r8,
struct pt_regs *regs)
{
struct sigframe __user *sf;
struct sigcontext __user *sc;
struct sigcontext sigctx;
struct mcontext __user *sr;
void __user *addr;
sigset_t set;
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
struct mcontext __user *mcp, *tm_mcp;
unsigned long msr_hi;
#endif
current->restart_block.fn = do_no_restart_syscall;
sf = (struct sigframe __user *)(regs->gpr[1] + __SIGNAL_FRAMESIZE);
sc = &sf->sctx;
addr = sc;
if (copy_from_user(&sigctx, sc, sizeof(sigctx)))
goto badframe;
#ifdef CONFIG_PPC64
set.sig[0] = sigctx.oldmask + ((long)(sigctx._unused[3]) << 32);
#else
set.sig[0] = sigctx.oldmask;
set.sig[1] = sigctx._unused[3];
#endif
set_current_blocked(&set);
#ifdef CONFIG_PPC_TRANSACTIONAL_MEM
mcp = (struct mcontext __user *)&sf->mctx;
tm_mcp = (struct mcontext __user *)&sf->mctx_transact;
if (__get_user(msr_hi, &tm_mcp->mc_gregs[PT_MSR]))
goto badframe;
if (MSR_TM_ACTIVE(msr_hi<<32)) {
if (!cpu_has_feature(CPU_FTR_TM))
goto badframe;
if (restore_tm_user_regs(regs, mcp, tm_mcp))
goto badframe;
} else
#endif
{
sr = (struct mcontext __user *)from_user_ptr(sigctx.regs);
addr = sr;
if (!access_ok(VERIFY_READ, sr, sizeof(*sr))
|| restore_user_regs(regs, sr, 1))
goto badframe;
}
set_thread_flag(TIF_RESTOREALL);
return 0;
badframe:
if (show_unhandled_signals)
printk_ratelimited(KERN_INFO
"%s[%d]: bad frame in sys_sigreturn: "
"%p nip %08lx lr %08lx\n",
current->comm, current->pid,
addr, regs->nip, regs->link);
force_sig(SIGSEGV, current);
return 0;
}
