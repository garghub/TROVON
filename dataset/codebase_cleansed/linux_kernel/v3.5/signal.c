asmlinkage int
sys_sigaltstack(const stack_t __user *uss, stack_t __user *uoss)
{
return do_sigaltstack(uss, uoss, rdusp());
}
static long
restore_sigcontext(struct sigcontext __user *sc, struct pt_regs *regs,
struct switch_stack *sw)
{
unsigned long usp;
long i, err = __get_user(regs->pc, &sc->sc_pc);
current_thread_info()->restart_block.fn = do_no_restart_syscall;
sw->r26 = (unsigned long) ret_from_sys_call;
err |= __get_user(regs->r0, sc->sc_regs+0);
err |= __get_user(regs->r1, sc->sc_regs+1);
err |= __get_user(regs->r2, sc->sc_regs+2);
err |= __get_user(regs->r3, sc->sc_regs+3);
err |= __get_user(regs->r4, sc->sc_regs+4);
err |= __get_user(regs->r5, sc->sc_regs+5);
err |= __get_user(regs->r6, sc->sc_regs+6);
err |= __get_user(regs->r7, sc->sc_regs+7);
err |= __get_user(regs->r8, sc->sc_regs+8);
err |= __get_user(sw->r9, sc->sc_regs+9);
err |= __get_user(sw->r10, sc->sc_regs+10);
err |= __get_user(sw->r11, sc->sc_regs+11);
err |= __get_user(sw->r12, sc->sc_regs+12);
err |= __get_user(sw->r13, sc->sc_regs+13);
err |= __get_user(sw->r14, sc->sc_regs+14);
err |= __get_user(sw->r15, sc->sc_regs+15);
err |= __get_user(regs->r16, sc->sc_regs+16);
err |= __get_user(regs->r17, sc->sc_regs+17);
err |= __get_user(regs->r18, sc->sc_regs+18);
err |= __get_user(regs->r19, sc->sc_regs+19);
err |= __get_user(regs->r20, sc->sc_regs+20);
err |= __get_user(regs->r21, sc->sc_regs+21);
err |= __get_user(regs->r22, sc->sc_regs+22);
err |= __get_user(regs->r23, sc->sc_regs+23);
err |= __get_user(regs->r24, sc->sc_regs+24);
err |= __get_user(regs->r25, sc->sc_regs+25);
err |= __get_user(regs->r26, sc->sc_regs+26);
err |= __get_user(regs->r27, sc->sc_regs+27);
err |= __get_user(regs->r28, sc->sc_regs+28);
err |= __get_user(regs->gp, sc->sc_regs+29);
err |= __get_user(usp, sc->sc_regs+30);
wrusp(usp);
for (i = 0; i < 31; i++)
err |= __get_user(sw->fp[i], sc->sc_fpregs+i);
err |= __get_user(sw->fp[31], &sc->sc_fpcr);
return err;
}
asmlinkage void
do_sigreturn(struct sigcontext __user *sc, struct pt_regs *regs,
struct switch_stack *sw)
{
sigset_t set;
if (!access_ok(VERIFY_READ, sc, sizeof(*sc)))
goto give_sigsegv;
if (__get_user(set.sig[0], &sc->sc_mask))
goto give_sigsegv;
set_current_blocked(&set);
if (restore_sigcontext(sc, regs, sw))
goto give_sigsegv;
if (ptrace_cancel_bpt (current)) {
siginfo_t info;
info.si_signo = SIGTRAP;
info.si_errno = 0;
info.si_code = TRAP_BRKPT;
info.si_addr = (void __user *) regs->pc;
info.si_trapno = 0;
send_sig_info(SIGTRAP, &info, current);
}
return;
give_sigsegv:
force_sig(SIGSEGV, current);
}
asmlinkage void
do_rt_sigreturn(struct rt_sigframe __user *frame, struct pt_regs *regs,
struct switch_stack *sw)
{
sigset_t set;
if (!access_ok(VERIFY_READ, &frame->uc, sizeof(frame->uc)))
goto give_sigsegv;
if (__copy_from_user(&set, &frame->uc.uc_sigmask, sizeof(set)))
goto give_sigsegv;
set_current_blocked(&set);
if (restore_sigcontext(&frame->uc.uc_mcontext, regs, sw))
goto give_sigsegv;
if (ptrace_cancel_bpt (current)) {
siginfo_t info;
info.si_signo = SIGTRAP;
info.si_errno = 0;
info.si_code = TRAP_BRKPT;
info.si_addr = (void __user *) regs->pc;
info.si_trapno = 0;
send_sig_info(SIGTRAP, &info, current);
}
return;
give_sigsegv:
force_sig(SIGSEGV, current);
}
static inline void __user *
get_sigframe(struct k_sigaction *ka, unsigned long sp, size_t frame_size)
{
if ((ka->sa.sa_flags & SA_ONSTACK) != 0 && ! sas_ss_flags(sp))
sp = current->sas_ss_sp + current->sas_ss_size;
return (void __user *)((sp - frame_size) & -32ul);
}
static long
setup_sigcontext(struct sigcontext __user *sc, struct pt_regs *regs,
struct switch_stack *sw, unsigned long mask, unsigned long sp)
{
long i, err = 0;
err |= __put_user(on_sig_stack((unsigned long)sc), &sc->sc_onstack);
err |= __put_user(mask, &sc->sc_mask);
err |= __put_user(regs->pc, &sc->sc_pc);
err |= __put_user(8, &sc->sc_ps);
err |= __put_user(regs->r0 , sc->sc_regs+0);
err |= __put_user(regs->r1 , sc->sc_regs+1);
err |= __put_user(regs->r2 , sc->sc_regs+2);
err |= __put_user(regs->r3 , sc->sc_regs+3);
err |= __put_user(regs->r4 , sc->sc_regs+4);
err |= __put_user(regs->r5 , sc->sc_regs+5);
err |= __put_user(regs->r6 , sc->sc_regs+6);
err |= __put_user(regs->r7 , sc->sc_regs+7);
err |= __put_user(regs->r8 , sc->sc_regs+8);
err |= __put_user(sw->r9 , sc->sc_regs+9);
err |= __put_user(sw->r10 , sc->sc_regs+10);
err |= __put_user(sw->r11 , sc->sc_regs+11);
err |= __put_user(sw->r12 , sc->sc_regs+12);
err |= __put_user(sw->r13 , sc->sc_regs+13);
err |= __put_user(sw->r14 , sc->sc_regs+14);
err |= __put_user(sw->r15 , sc->sc_regs+15);
err |= __put_user(regs->r16, sc->sc_regs+16);
err |= __put_user(regs->r17, sc->sc_regs+17);
err |= __put_user(regs->r18, sc->sc_regs+18);
err |= __put_user(regs->r19, sc->sc_regs+19);
err |= __put_user(regs->r20, sc->sc_regs+20);
err |= __put_user(regs->r21, sc->sc_regs+21);
err |= __put_user(regs->r22, sc->sc_regs+22);
err |= __put_user(regs->r23, sc->sc_regs+23);
err |= __put_user(regs->r24, sc->sc_regs+24);
err |= __put_user(regs->r25, sc->sc_regs+25);
err |= __put_user(regs->r26, sc->sc_regs+26);
err |= __put_user(regs->r27, sc->sc_regs+27);
err |= __put_user(regs->r28, sc->sc_regs+28);
err |= __put_user(regs->gp , sc->sc_regs+29);
err |= __put_user(sp, sc->sc_regs+30);
err |= __put_user(0, sc->sc_regs+31);
for (i = 0; i < 31; i++)
err |= __put_user(sw->fp[i], sc->sc_fpregs+i);
err |= __put_user(0, sc->sc_fpregs+31);
err |= __put_user(sw->fp[31], &sc->sc_fpcr);
err |= __put_user(regs->trap_a0, &sc->sc_traparg_a0);
err |= __put_user(regs->trap_a1, &sc->sc_traparg_a1);
err |= __put_user(regs->trap_a2, &sc->sc_traparg_a2);
return err;
}
static int
setup_frame(int sig, struct k_sigaction *ka, sigset_t *set,
struct pt_regs *regs, struct switch_stack * sw)
{
unsigned long oldsp, r26, err = 0;
struct sigframe __user *frame;
oldsp = rdusp();
frame = get_sigframe(ka, oldsp, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
return -EFAULT;
err |= setup_sigcontext(&frame->sc, regs, sw, set->sig[0], oldsp);
if (err)
return -EFAULT;
if (ka->ka_restorer) {
r26 = (unsigned long) ka->ka_restorer;
} else {
err |= __put_user(INSN_MOV_R30_R16, frame->retcode+0);
err |= __put_user(INSN_LDI_R0+__NR_sigreturn, frame->retcode+1);
err |= __put_user(INSN_CALLSYS, frame->retcode+2);
imb();
r26 = (unsigned long) frame->retcode;
}
if (err)
return err;
regs->r26 = r26;
regs->r27 = regs->pc = (unsigned long) ka->sa.sa_handler;
regs->r16 = sig;
regs->r17 = 0;
regs->r18 = (unsigned long) &frame->sc;
wrusp((unsigned long) frame);
#if DEBUG_SIG
printk("SIG deliver (%s:%d): sp=%p pc=%p ra=%p\n",
current->comm, current->pid, frame, regs->pc, regs->r26);
#endif
return 0;
}
static int
setup_rt_frame(int sig, struct k_sigaction *ka, siginfo_t *info,
sigset_t *set, struct pt_regs *regs, struct switch_stack * sw)
{
unsigned long oldsp, r26, err = 0;
struct rt_sigframe __user *frame;
oldsp = rdusp();
frame = get_sigframe(ka, oldsp, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
return -EFAULT;
err |= copy_siginfo_to_user(&frame->info, info);
err |= __put_user(0, &frame->uc.uc_flags);
err |= __put_user(0, &frame->uc.uc_link);
err |= __put_user(set->sig[0], &frame->uc.uc_osf_sigmask);
err |= __put_user(current->sas_ss_sp, &frame->uc.uc_stack.ss_sp);
err |= __put_user(sas_ss_flags(oldsp), &frame->uc.uc_stack.ss_flags);
err |= __put_user(current->sas_ss_size, &frame->uc.uc_stack.ss_size);
err |= setup_sigcontext(&frame->uc.uc_mcontext, regs, sw,
set->sig[0], oldsp);
err |= __copy_to_user(&frame->uc.uc_sigmask, set, sizeof(*set));
if (err)
return -EFAULT;
if (ka->ka_restorer) {
r26 = (unsigned long) ka->ka_restorer;
} else {
err |= __put_user(INSN_MOV_R30_R16, frame->retcode+0);
err |= __put_user(INSN_LDI_R0+__NR_rt_sigreturn,
frame->retcode+1);
err |= __put_user(INSN_CALLSYS, frame->retcode+2);
imb();
r26 = (unsigned long) frame->retcode;
}
if (err)
return -EFAULT;
regs->r26 = r26;
regs->r27 = regs->pc = (unsigned long) ka->sa.sa_handler;
regs->r16 = sig;
regs->r17 = (unsigned long) &frame->info;
regs->r18 = (unsigned long) &frame->uc;
wrusp((unsigned long) frame);
#if DEBUG_SIG
printk("SIG deliver (%s:%d): sp=%p pc=%p ra=%p\n",
current->comm, current->pid, frame, regs->pc, regs->r26);
#endif
return 0;
}
static inline void
handle_signal(int sig, struct k_sigaction *ka, siginfo_t *info,
struct pt_regs * regs, struct switch_stack *sw)
{
sigset_t *oldset = sigmask_to_save();
int ret;
if (ka->sa.sa_flags & SA_SIGINFO)
ret = setup_rt_frame(sig, ka, info, oldset, regs, sw);
else
ret = setup_frame(sig, ka, oldset, regs, sw);
if (ret) {
force_sigsegv(sig, current);
return;
}
signal_delivered(sig, info, ka, regs, 0);
}
static inline void
syscall_restart(unsigned long r0, unsigned long r19,
struct pt_regs *regs, struct k_sigaction *ka)
{
switch (regs->r0) {
case ERESTARTSYS:
if (!(ka->sa.sa_flags & SA_RESTART)) {
case ERESTARTNOHAND:
regs->r0 = EINTR;
break;
}
case ERESTARTNOINTR:
regs->r0 = r0;
regs->r19 = r19;
regs->pc -= 4;
break;
case ERESTART_RESTARTBLOCK:
regs->r0 = EINTR;
break;
}
}
static void
do_signal(struct pt_regs * regs, struct switch_stack * sw,
unsigned long r0, unsigned long r19)
{
siginfo_t info;
int signr;
unsigned long single_stepping = ptrace_cancel_bpt(current);
struct k_sigaction ka;
signr = get_signal_to_deliver(&info, &ka, regs, NULL);
single_stepping |= ptrace_cancel_bpt(current);
if (signr > 0) {
if (r0)
syscall_restart(r0, r19, regs, &ka);
handle_signal(signr, &ka, &info, regs, sw);
if (single_stepping)
ptrace_set_bpt(current);
return;
}
if (r0) {
switch (regs->r0) {
case ERESTARTNOHAND:
case ERESTARTSYS:
case ERESTARTNOINTR:
regs->r0 = r0;
regs->r19 = r19;
regs->pc -= 4;
break;
case ERESTART_RESTARTBLOCK:
regs->r0 = __NR_restart_syscall;
regs->pc -= 4;
break;
}
}
restore_saved_sigmask();
if (single_stepping)
ptrace_set_bpt(current);
}
void
do_notify_resume(struct pt_regs *regs, struct switch_stack *sw,
unsigned long thread_info_flags,
unsigned long r0, unsigned long r19)
{
if (thread_info_flags & _TIF_SIGPENDING)
do_signal(regs, sw, r0, r19);
if (thread_info_flags & _TIF_NOTIFY_RESUME) {
clear_thread_flag(TIF_NOTIFY_RESUME);
tracehook_notify_resume(regs);
}
}
