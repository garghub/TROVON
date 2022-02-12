static int setup_sigcontext32(struct pt_regs *regs,
struct sigcontext32 __user *sc)
{
int err = 0;
int i;
err |= __put_user(regs->cp0_epc, &sc->sc_pc);
err |= __put_user(0, &sc->sc_regs[0]);
for (i = 1; i < 32; i++)
err |= __put_user(regs->regs[i], &sc->sc_regs[i]);
err |= __put_user(regs->hi, &sc->sc_mdhi);
err |= __put_user(regs->lo, &sc->sc_mdlo);
if (cpu_has_dsp) {
err |= __put_user(rddsp(DSP_MASK), &sc->sc_dsp);
err |= __put_user(mfhi1(), &sc->sc_hi1);
err |= __put_user(mflo1(), &sc->sc_lo1);
err |= __put_user(mfhi2(), &sc->sc_hi2);
err |= __put_user(mflo2(), &sc->sc_lo2);
err |= __put_user(mfhi3(), &sc->sc_hi3);
err |= __put_user(mflo3(), &sc->sc_lo3);
}
err |= protected_save_fp_context(sc);
return err;
}
static int restore_sigcontext32(struct pt_regs *regs,
struct sigcontext32 __user *sc)
{
int err = 0;
s32 treg;
int i;
current->restart_block.fn = do_no_restart_syscall;
err |= __get_user(regs->cp0_epc, &sc->sc_pc);
err |= __get_user(regs->hi, &sc->sc_mdhi);
err |= __get_user(regs->lo, &sc->sc_mdlo);
if (cpu_has_dsp) {
err |= __get_user(treg, &sc->sc_hi1); mthi1(treg);
err |= __get_user(treg, &sc->sc_lo1); mtlo1(treg);
err |= __get_user(treg, &sc->sc_hi2); mthi2(treg);
err |= __get_user(treg, &sc->sc_lo2); mtlo2(treg);
err |= __get_user(treg, &sc->sc_hi3); mthi3(treg);
err |= __get_user(treg, &sc->sc_lo3); mtlo3(treg);
err |= __get_user(treg, &sc->sc_dsp); wrdsp(treg, DSP_MASK);
}
for (i = 1; i < 32; i++)
err |= __get_user(regs->regs[i], &sc->sc_regs[i]);
return err ?: protected_restore_fp_context(sc);
}
static int setup_frame_32(void *sig_return, struct ksignal *ksig,
struct pt_regs *regs, sigset_t *set)
{
struct sigframe32 __user *frame;
int err = 0;
frame = get_sigframe(ksig, regs, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof (*frame)))
return -EFAULT;
err |= setup_sigcontext32(regs, &frame->sf_sc);
err |= __copy_conv_sigset_to_user(&frame->sf_mask, set);
if (err)
return -EFAULT;
regs->regs[ 4] = ksig->sig;
regs->regs[ 5] = 0;
regs->regs[ 6] = (unsigned long) &frame->sf_sc;
regs->regs[29] = (unsigned long) frame;
regs->regs[31] = (unsigned long) sig_return;
regs->cp0_epc = regs->regs[25] = (unsigned long) ksig->ka.sa.sa_handler;
DEBUGP("SIG deliver (%s:%d): sp=0x%p pc=0x%lx ra=0x%lx\n",
current->comm, current->pid,
frame, regs->cp0_epc, regs->regs[31]);
return 0;
}
asmlinkage void sys32_rt_sigreturn(nabi_no_regargs struct pt_regs regs)
{
struct rt_sigframe32 __user *frame;
sigset_t set;
int sig;
frame = (struct rt_sigframe32 __user *) regs.regs[29];
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_conv_sigset_from_user(&set, &frame->rs_uc.uc_sigmask))
goto badframe;
set_current_blocked(&set);
sig = restore_sigcontext32(&regs, &frame->rs_uc.uc_mcontext);
if (sig < 0)
goto badframe;
else if (sig)
force_sig(sig, current);
if (compat_restore_altstack(&frame->rs_uc.uc_stack))
goto badframe;
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
badframe:
force_sig(SIGSEGV, current);
}
static int setup_rt_frame_32(void *sig_return, struct ksignal *ksig,
struct pt_regs *regs, sigset_t *set)
{
struct rt_sigframe32 __user *frame;
int err = 0;
frame = get_sigframe(ksig, regs, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof (*frame)))
return -EFAULT;
err |= copy_siginfo_to_user32(&frame->rs_info, &ksig->info);
err |= __put_user(0, &frame->rs_uc.uc_flags);
err |= __put_user(0, &frame->rs_uc.uc_link);
err |= __compat_save_altstack(&frame->rs_uc.uc_stack, regs->regs[29]);
err |= setup_sigcontext32(regs, &frame->rs_uc.uc_mcontext);
err |= __copy_conv_sigset_to_user(&frame->rs_uc.uc_sigmask, set);
if (err)
return -EFAULT;
regs->regs[ 4] = ksig->sig;
regs->regs[ 5] = (unsigned long) &frame->rs_info;
regs->regs[ 6] = (unsigned long) &frame->rs_uc;
regs->regs[29] = (unsigned long) frame;
regs->regs[31] = (unsigned long) sig_return;
regs->cp0_epc = regs->regs[25] = (unsigned long) ksig->ka.sa.sa_handler;
DEBUGP("SIG deliver (%s:%d): sp=0x%p pc=0x%lx ra=0x%lx\n",
current->comm, current->pid,
frame, regs->cp0_epc, regs->regs[31]);
return 0;
}
asmlinkage void sys32_sigreturn(nabi_no_regargs struct pt_regs regs)
{
struct sigframe32 __user *frame;
sigset_t blocked;
int sig;
frame = (struct sigframe32 __user *) regs.regs[29];
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_conv_sigset_from_user(&blocked, &frame->sf_mask))
goto badframe;
set_current_blocked(&blocked);
sig = restore_sigcontext32(&regs, &frame->sf_sc);
if (sig < 0)
goto badframe;
else if (sig)
force_sig(sig, current);
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
badframe:
force_sig(SIGSEGV, current);
}
