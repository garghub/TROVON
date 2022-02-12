asmlinkage void sysn32_rt_sigreturn(nabi_no_regargs struct pt_regs regs)
{
struct rt_sigframe_n32 __user *frame;
sigset_t set;
int sig;
frame = (struct rt_sigframe_n32 __user *) regs.regs[29];
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_conv_sigset_from_user(&set, &frame->rs_uc.uc_sigmask))
goto badframe;
set_current_blocked(&set);
sig = restore_sigcontext(&regs, &frame->rs_uc.uc_mcontext);
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
static int setup_rt_frame_n32(void *sig_return, struct ksignal *ksig,
struct pt_regs *regs, sigset_t *set)
{
struct rt_sigframe_n32 __user *frame;
int err = 0;
frame = get_sigframe(ksig, regs, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof (*frame)))
return -EFAULT;
err |= copy_siginfo_to_user32(&frame->rs_info, &ksig->info);
err |= __put_user(0, &frame->rs_uc.uc_flags);
err |= __put_user(0, &frame->rs_uc.uc_link);
err |= __compat_save_altstack(&frame->rs_uc.uc_stack, regs->regs[29]);
err |= setup_sigcontext(regs, &frame->rs_uc.uc_mcontext);
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
