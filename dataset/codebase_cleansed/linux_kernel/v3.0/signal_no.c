asmlinkage int
sys_sigsuspend(int unused0, int unused1, old_sigset_t mask)
{
mask &= _BLOCKABLE;
spin_lock_irq(&current->sighand->siglock);
current->saved_sigmask = current->blocked;
siginitset(&current->blocked, mask);
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
current->state = TASK_INTERRUPTIBLE;
schedule();
set_restore_sigmask();
return -ERESTARTNOHAND;
}
asmlinkage int
sys_sigaction(int sig, const struct old_sigaction __user *act,
struct old_sigaction __user *oact)
{
struct k_sigaction new_ka, old_ka;
int ret;
if (act) {
old_sigset_t mask;
if (!access_ok(VERIFY_READ, act, sizeof(*act)) ||
__get_user(new_ka.sa.sa_handler, &act->sa_handler) ||
__get_user(new_ka.sa.sa_restorer, &act->sa_restorer) ||
__get_user(new_ka.sa.sa_flags, &act->sa_flags) ||
__get_user(mask, &act->sa_mask))
return -EFAULT;
siginitset(&new_ka.sa.sa_mask, mask);
}
ret = do_sigaction(sig, act ? &new_ka : NULL, oact ? &old_ka : NULL);
if (!ret && oact) {
if (!access_ok(VERIFY_WRITE, oact, sizeof(*oact)) ||
__put_user(old_ka.sa.sa_handler, &oact->sa_handler) ||
__put_user(old_ka.sa.sa_restorer, &oact->sa_restorer) ||
__put_user(old_ka.sa.sa_flags, &oact->sa_flags) ||
__put_user(old_ka.sa.sa_mask.sig[0], &oact->sa_mask))
return -EFAULT;
}
return ret;
}
asmlinkage int
sys_sigaltstack(const stack_t __user *uss, stack_t __user *uoss)
{
return do_sigaltstack(uss, uoss, rdusp());
}
static inline int restore_fpu_state(struct sigcontext *sc)
{
int err = 1;
if (FPU_IS_EMU) {
memcpy(current->thread.fpcntl, sc->sc_fpcntl, 12);
memcpy(current->thread.fp, sc->sc_fpregs, 24);
return 0;
}
if (sc->sc_fpstate[0]) {
if (sc->sc_fpstate[0] != fpu_version)
goto out;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp1\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*sc->sc_fpregs), "m" (*sc->sc_fpcntl));
}
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k" : : "m" (*sc->sc_fpstate));
err = 0;
out:
return err;
}
static inline int rt_restore_fpu_state(struct ucontext __user *uc)
{
unsigned char fpstate[FPCONTEXT_SIZE];
int context_size = 0;
fpregset_t fpregs;
int err = 1;
if (FPU_IS_EMU) {
if (__copy_from_user(current->thread.fpcntl,
uc->uc_mcontext.fpregs.f_fpcntl, 12))
goto out;
if (__copy_from_user(current->thread.fp,
uc->uc_mcontext.fpregs.f_fpregs, 96))
goto out;
return 0;
}
if (__get_user(*(long *)fpstate, (long __user *)&uc->uc_fpstate))
goto out;
if (fpstate[0]) {
context_size = fpstate[1];
if (fpstate[0] != fpu_version)
goto out;
if (__copy_from_user(&fpregs, &uc->uc_mcontext.fpregs,
sizeof(fpregs)))
goto out;
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %0,%%fp0-%%fp7\n\t"
"fmoveml %1,%%fpcr/%%fpsr/%%fpiar\n\t"
".chip 68k"
:
: "m" (*fpregs.f_fpregs),
"m" (*fpregs.f_fpcntl));
}
if (context_size &&
__copy_from_user(fpstate + 4, (long __user *)&uc->uc_fpstate + 1,
context_size))
goto out;
__asm__ volatile (".chip 68k/68881\n\t"
"frestore %0\n\t"
".chip 68k" : : "m" (*fpstate));
err = 0;
out:
return err;
}
static inline int
restore_sigcontext(struct pt_regs *regs, struct sigcontext __user *usc, void __user *fp,
int *pd0)
{
int formatvec;
struct sigcontext context;
int err = 0;
current_thread_info()->restart_block.fn = do_no_restart_syscall;
if (copy_from_user(&context, usc, sizeof(context)))
goto badframe;
regs->d1 = context.sc_d1;
regs->a0 = context.sc_a0;
regs->a1 = context.sc_a1;
((struct switch_stack *)regs - 1)->a5 = context.sc_a5;
regs->sr = (regs->sr & 0xff00) | (context.sc_sr & 0xff);
regs->pc = context.sc_pc;
regs->orig_d0 = -1;
wrusp(context.sc_usp);
formatvec = context.sc_formatvec;
regs->format = formatvec >> 12;
regs->vector = formatvec & 0xfff;
#ifdef CONFIG_FPU
err = restore_fpu_state(&context);
#endif
*pd0 = context.sc_d0;
return err;
badframe:
return 1;
}
static inline int
rt_restore_ucontext(struct pt_regs *regs, struct switch_stack *sw,
struct ucontext __user *uc, int *pd0)
{
int temp;
greg_t __user *gregs = uc->uc_mcontext.gregs;
unsigned long usp;
int err;
current_thread_info()->restart_block.fn = do_no_restart_syscall;
err = __get_user(temp, &uc->uc_mcontext.version);
if (temp != MCONTEXT_VERSION)
goto badframe;
err |= __get_user(regs->d0, &gregs[0]);
err |= __get_user(regs->d1, &gregs[1]);
err |= __get_user(regs->d2, &gregs[2]);
err |= __get_user(regs->d3, &gregs[3]);
err |= __get_user(regs->d4, &gregs[4]);
err |= __get_user(regs->d5, &gregs[5]);
err |= __get_user(sw->d6, &gregs[6]);
err |= __get_user(sw->d7, &gregs[7]);
err |= __get_user(regs->a0, &gregs[8]);
err |= __get_user(regs->a1, &gregs[9]);
err |= __get_user(regs->a2, &gregs[10]);
err |= __get_user(sw->a3, &gregs[11]);
err |= __get_user(sw->a4, &gregs[12]);
err |= __get_user(sw->a5, &gregs[13]);
err |= __get_user(sw->a6, &gregs[14]);
err |= __get_user(usp, &gregs[15]);
wrusp(usp);
err |= __get_user(regs->pc, &gregs[16]);
err |= __get_user(temp, &gregs[17]);
regs->sr = (regs->sr & 0xff00) | (temp & 0xff);
regs->orig_d0 = -1;
regs->format = temp >> 12;
regs->vector = temp & 0xfff;
if (do_sigaltstack(&uc->uc_stack, NULL, usp) == -EFAULT)
goto badframe;
*pd0 = regs->d0;
return err;
badframe:
return 1;
}
asmlinkage int do_sigreturn(unsigned long __unused)
{
struct switch_stack *sw = (struct switch_stack *) &__unused;
struct pt_regs *regs = (struct pt_regs *) (sw + 1);
unsigned long usp = rdusp();
struct sigframe __user *frame = (struct sigframe __user *)(usp - 4);
sigset_t set;
int d0;
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__get_user(set.sig[0], &frame->sc.sc_mask) ||
(_NSIG_WORDS > 1 &&
__copy_from_user(&set.sig[1], &frame->extramask,
sizeof(frame->extramask))))
goto badframe;
sigdelsetmask(&set, ~_BLOCKABLE);
spin_lock_irq(&current->sighand->siglock);
current->blocked = set;
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
if (restore_sigcontext(regs, &frame->sc, frame + 1, &d0))
goto badframe;
return d0;
badframe:
force_sig(SIGSEGV, current);
return 0;
}
asmlinkage int do_rt_sigreturn(unsigned long __unused)
{
struct switch_stack *sw = (struct switch_stack *) &__unused;
struct pt_regs *regs = (struct pt_regs *) (sw + 1);
unsigned long usp = rdusp();
struct rt_sigframe __user *frame = (struct rt_sigframe __user *)(usp - 4);
sigset_t set;
int d0;
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_from_user(&set, &frame->uc.uc_sigmask, sizeof(set)))
goto badframe;
sigdelsetmask(&set, ~_BLOCKABLE);
spin_lock_irq(&current->sighand->siglock);
current->blocked = set;
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
if (rt_restore_ucontext(regs, sw, &frame->uc, &d0))
goto badframe;
return d0;
badframe:
force_sig(SIGSEGV, current);
return 0;
}
static inline void save_fpu_state(struct sigcontext *sc, struct pt_regs *regs)
{
if (FPU_IS_EMU) {
memcpy(sc->sc_fpcntl, current->thread.fpcntl, 12);
memcpy(sc->sc_fpregs, current->thread.fp, 24);
return;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*sc->sc_fpstate) : "memory");
if (sc->sc_fpstate[0]) {
fpu_version = sc->sc_fpstate[0];
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp1,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*sc->sc_fpregs),
"=m" (*sc->sc_fpcntl)
:
: "memory");
}
}
static inline int rt_save_fpu_state(struct ucontext __user *uc, struct pt_regs *regs)
{
unsigned char fpstate[FPCONTEXT_SIZE];
int context_size = 0;
int err = 0;
if (FPU_IS_EMU) {
err |= copy_to_user(uc->uc_mcontext.fpregs.f_pcntl,
current->thread.fpcntl, 12);
err |= copy_to_user(uc->uc_mcontext.fpregs.f_fpregs,
current->thread.fp, 96);
return err;
}
__asm__ volatile (".chip 68k/68881\n\t"
"fsave %0\n\t"
".chip 68k"
: : "m" (*fpstate) : "memory");
err |= __put_user(*(long *)fpstate, (long __user *)&uc->uc_fpstate);
if (fpstate[0]) {
fpregset_t fpregs;
context_size = fpstate[1];
fpu_version = fpstate[0];
__asm__ volatile (".chip 68k/68881\n\t"
"fmovemx %%fp0-%%fp7,%0\n\t"
"fmoveml %%fpcr/%%fpsr/%%fpiar,%1\n\t"
".chip 68k"
: "=m" (*fpregs.f_fpregs),
"=m" (*fpregs.f_fpcntl)
:
: "memory");
err |= copy_to_user(&uc->uc_mcontext.fpregs, &fpregs,
sizeof(fpregs));
}
if (context_size)
err |= copy_to_user((long __user *)&uc->uc_fpstate + 1, fpstate + 4,
context_size);
return err;
}
static void setup_sigcontext(struct sigcontext *sc, struct pt_regs *regs,
unsigned long mask)
{
sc->sc_mask = mask;
sc->sc_usp = rdusp();
sc->sc_d0 = regs->d0;
sc->sc_d1 = regs->d1;
sc->sc_a0 = regs->a0;
sc->sc_a1 = regs->a1;
sc->sc_a5 = ((struct switch_stack *)regs - 1)->a5;
sc->sc_sr = regs->sr;
sc->sc_pc = regs->pc;
sc->sc_formatvec = regs->format << 12 | regs->vector;
#ifdef CONFIG_FPU
save_fpu_state(sc, regs);
#endif
}
static inline int rt_setup_ucontext(struct ucontext __user *uc, struct pt_regs *regs)
{
struct switch_stack *sw = (struct switch_stack *)regs - 1;
greg_t __user *gregs = uc->uc_mcontext.gregs;
int err = 0;
err |= __put_user(MCONTEXT_VERSION, &uc->uc_mcontext.version);
err |= __put_user(regs->d0, &gregs[0]);
err |= __put_user(regs->d1, &gregs[1]);
err |= __put_user(regs->d2, &gregs[2]);
err |= __put_user(regs->d3, &gregs[3]);
err |= __put_user(regs->d4, &gregs[4]);
err |= __put_user(regs->d5, &gregs[5]);
err |= __put_user(sw->d6, &gregs[6]);
err |= __put_user(sw->d7, &gregs[7]);
err |= __put_user(regs->a0, &gregs[8]);
err |= __put_user(regs->a1, &gregs[9]);
err |= __put_user(regs->a2, &gregs[10]);
err |= __put_user(sw->a3, &gregs[11]);
err |= __put_user(sw->a4, &gregs[12]);
err |= __put_user(sw->a5, &gregs[13]);
err |= __put_user(sw->a6, &gregs[14]);
err |= __put_user(rdusp(), &gregs[15]);
err |= __put_user(regs->pc, &gregs[16]);
err |= __put_user(regs->sr, &gregs[17]);
#ifdef CONFIG_FPU
err |= rt_save_fpu_state(uc, regs);
#endif
return err;
}
static inline void __user *
get_sigframe(struct k_sigaction *ka, struct pt_regs *regs, size_t frame_size)
{
unsigned long usp;
usp = rdusp();
if (ka->sa.sa_flags & SA_ONSTACK) {
if (!sas_ss_flags(usp))
usp = current->sas_ss_sp + current->sas_ss_size;
}
return (void __user *)((usp - frame_size) & -8UL);
}
static int setup_frame (int sig, struct k_sigaction *ka,
sigset_t *set, struct pt_regs *regs)
{
struct sigframe __user *frame;
struct sigcontext context;
int err = 0;
frame = get_sigframe(ka, regs, sizeof(*frame));
err |= __put_user((current_thread_info()->exec_domain
&& current_thread_info()->exec_domain->signal_invmap
&& sig < 32
? current_thread_info()->exec_domain->signal_invmap[sig]
: sig),
&frame->sig);
err |= __put_user(regs->vector, &frame->code);
err |= __put_user(&frame->sc, &frame->psc);
if (_NSIG_WORDS > 1)
err |= copy_to_user(frame->extramask, &set->sig[1],
sizeof(frame->extramask));
setup_sigcontext(&context, regs, set->sig[0]);
err |= copy_to_user (&frame->sc, &context, sizeof(context));
err |= __put_user((void *) ret_from_user_signal, &frame->pretcode);
if (err)
goto give_sigsegv;
wrusp ((unsigned long) frame);
regs->pc = (unsigned long) ka->sa.sa_handler;
((struct switch_stack *)regs - 1)->a5 = current->mm->start_data;
regs->format = 0x4;
adjust_stack:
if (regs->stkadj) {
struct pt_regs *tregs =
(struct pt_regs *)((ulong)regs + regs->stkadj);
#if defined(DEBUG)
printk(KERN_DEBUG "Performing stackadjust=%04x\n", regs->stkadj);
#endif
tregs->vector = 0;
tregs->format = 0;
tregs->pc = regs->pc;
tregs->sr = regs->sr;
}
return err;
give_sigsegv:
force_sigsegv(sig, current);
goto adjust_stack;
}
static int setup_rt_frame (int sig, struct k_sigaction *ka, siginfo_t *info,
sigset_t *set, struct pt_regs *regs)
{
struct rt_sigframe __user *frame;
int err = 0;
frame = get_sigframe(ka, regs, sizeof(*frame));
err |= __put_user((current_thread_info()->exec_domain
&& current_thread_info()->exec_domain->signal_invmap
&& sig < 32
? current_thread_info()->exec_domain->signal_invmap[sig]
: sig),
&frame->sig);
err |= __put_user(&frame->info, &frame->pinfo);
err |= __put_user(&frame->uc, &frame->puc);
err |= copy_siginfo_to_user(&frame->info, info);
err |= __put_user(0, &frame->uc.uc_flags);
err |= __put_user(NULL, &frame->uc.uc_link);
err |= __put_user((void __user *)current->sas_ss_sp,
&frame->uc.uc_stack.ss_sp);
err |= __put_user(sas_ss_flags(rdusp()),
&frame->uc.uc_stack.ss_flags);
err |= __put_user(current->sas_ss_size, &frame->uc.uc_stack.ss_size);
err |= rt_setup_ucontext(&frame->uc, regs);
err |= copy_to_user (&frame->uc.uc_sigmask, set, sizeof(*set));
err |= __put_user((void *) ret_from_user_rt_signal, &frame->pretcode);
if (err)
goto give_sigsegv;
wrusp ((unsigned long) frame);
regs->pc = (unsigned long) ka->sa.sa_handler;
((struct switch_stack *)regs - 1)->a5 = current->mm->start_data;
regs->format = 0x4;
adjust_stack:
if (regs->stkadj) {
struct pt_regs *tregs =
(struct pt_regs *)((ulong)regs + regs->stkadj);
#if defined(DEBUG)
printk(KERN_DEBUG "Performing stackadjust=%04x\n", regs->stkadj);
#endif
tregs->vector = 0;
tregs->format = 0;
tregs->pc = regs->pc;
tregs->sr = regs->sr;
}
return err;
give_sigsegv:
force_sigsegv(sig, current);
goto adjust_stack;
}
static inline void
handle_restart(struct pt_regs *regs, struct k_sigaction *ka, int has_handler)
{
switch (regs->d0) {
case -ERESTARTNOHAND:
if (!has_handler)
goto do_restart;
regs->d0 = -EINTR;
break;
case -ERESTART_RESTARTBLOCK:
if (!has_handler) {
regs->d0 = __NR_restart_syscall;
regs->pc -= 2;
break;
}
regs->d0 = -EINTR;
break;
case -ERESTARTSYS:
if (has_handler && !(ka->sa.sa_flags & SA_RESTART)) {
regs->d0 = -EINTR;
break;
}
case -ERESTARTNOINTR:
do_restart:
regs->d0 = regs->orig_d0;
regs->pc -= 2;
break;
}
}
static void
handle_signal(int sig, struct k_sigaction *ka, siginfo_t *info,
sigset_t *oldset, struct pt_regs *regs)
{
int err;
if (regs->orig_d0 >= 0)
handle_restart(regs, ka, 1);
if (ka->sa.sa_flags & SA_SIGINFO)
err = setup_rt_frame(sig, ka, info, oldset, regs);
else
err = setup_frame(sig, ka, oldset, regs);
if (err)
return;
spin_lock_irq(&current->sighand->siglock);
sigorsets(&current->blocked,&current->blocked,&ka->sa.sa_mask);
if (!(ka->sa.sa_flags & SA_NODEFER))
sigaddset(&current->blocked,sig);
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
clear_thread_flag(TIF_RESTORE_SIGMASK);
}
asmlinkage void do_signal(struct pt_regs *regs)
{
struct k_sigaction ka;
siginfo_t info;
int signr;
sigset_t *oldset;
if (!user_mode(regs))
return;
if (test_thread_flag(TIF_RESTORE_SIGMASK))
oldset = &current->saved_sigmask;
else
oldset = &current->blocked;
signr = get_signal_to_deliver(&info, &ka, regs, NULL);
if (signr > 0) {
handle_signal(signr, &ka, &info, oldset, regs);
return;
}
if (regs->orig_d0 >= 0) {
handle_restart(regs, NULL, 0);
}
if (test_thread_flag(TIF_RESTORE_SIGMASK)) {
clear_thread_flag(TIF_RESTORE_SIGMASK);
sigprocmask(SIG_SETMASK, &current->saved_sigmask, NULL);
}
}
