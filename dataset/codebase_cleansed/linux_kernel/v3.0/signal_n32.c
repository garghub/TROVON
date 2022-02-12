asmlinkage int sysn32_rt_sigsuspend(nabi_no_regargs struct pt_regs regs)
{
compat_sigset_t __user *unewset;
compat_sigset_t uset;
size_t sigsetsize;
sigset_t newset;
sigsetsize = regs.regs[5];
if (sigsetsize != sizeof(sigset_t))
return -EINVAL;
unewset = (compat_sigset_t __user *) regs.regs[4];
if (copy_from_user(&uset, unewset, sizeof(uset)))
return -EFAULT;
sigset_from_compat(&newset, &uset);
sigdelsetmask(&newset, ~_BLOCKABLE);
spin_lock_irq(&current->sighand->siglock);
current->saved_sigmask = current->blocked;
current->blocked = newset;
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
current->state = TASK_INTERRUPTIBLE;
schedule();
set_thread_flag(TIF_RESTORE_SIGMASK);
return -ERESTARTNOHAND;
}
asmlinkage void sysn32_rt_sigreturn(nabi_no_regargs struct pt_regs regs)
{
struct rt_sigframe_n32 __user *frame;
mm_segment_t old_fs;
sigset_t set;
stack_t st;
s32 sp;
int sig;
frame = (struct rt_sigframe_n32 __user *) regs.regs[29];
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_conv_sigset_from_user(&set, &frame->rs_uc.uc_sigmask))
goto badframe;
sigdelsetmask(&set, ~_BLOCKABLE);
spin_lock_irq(&current->sighand->siglock);
current->blocked = set;
recalc_sigpending();
spin_unlock_irq(&current->sighand->siglock);
sig = restore_sigcontext(&regs, &frame->rs_uc.uc_mcontext);
if (sig < 0)
goto badframe;
else if (sig)
force_sig(sig, current);
if (__get_user(sp, &frame->rs_uc.uc_stack.ss_sp))
goto badframe;
st.ss_sp = (void __user *)(long) sp;
if (__get_user(st.ss_size, &frame->rs_uc.uc_stack.ss_size))
goto badframe;
if (__get_user(st.ss_flags, &frame->rs_uc.uc_stack.ss_flags))
goto badframe;
old_fs = get_fs();
set_fs(KERNEL_DS);
do_sigaltstack((stack_t __user *)&st, NULL, regs.regs[29]);
set_fs(old_fs);
__asm__ __volatile__(
"move\t$29, %0\n\t"
"j\tsyscall_exit"
:
:"r" (&regs));
badframe:
force_sig(SIGSEGV, current);
}
static int setup_rt_frame_n32(void *sig_return, struct k_sigaction *ka,
struct pt_regs *regs, int signr, sigset_t *set, siginfo_t *info)
{
struct rt_sigframe_n32 __user *frame;
int err = 0;
s32 sp;
frame = get_sigframe(ka, regs, sizeof(*frame));
if (!access_ok(VERIFY_WRITE, frame, sizeof (*frame)))
goto give_sigsegv;
err |= copy_siginfo_to_user32(&frame->rs_info, info);
err |= __put_user(0, &frame->rs_uc.uc_flags);
err |= __put_user(0, &frame->rs_uc.uc_link);
sp = (int) (long) current->sas_ss_sp;
err |= __put_user(sp,
&frame->rs_uc.uc_stack.ss_sp);
err |= __put_user(sas_ss_flags(regs->regs[29]),
&frame->rs_uc.uc_stack.ss_flags);
err |= __put_user(current->sas_ss_size,
&frame->rs_uc.uc_stack.ss_size);
err |= setup_sigcontext(regs, &frame->rs_uc.uc_mcontext);
err |= __copy_conv_sigset_to_user(&frame->rs_uc.uc_sigmask, set);
if (err)
goto give_sigsegv;
regs->regs[ 4] = signr;
regs->regs[ 5] = (unsigned long) &frame->rs_info;
regs->regs[ 6] = (unsigned long) &frame->rs_uc;
regs->regs[29] = (unsigned long) frame;
regs->regs[31] = (unsigned long) sig_return;
regs->cp0_epc = regs->regs[25] = (unsigned long) ka->sa.sa_handler;
DEBUGP("SIG deliver (%s:%d): sp=0x%p pc=0x%lx ra=0x%lx\n",
current->comm, current->pid,
frame, regs->cp0_epc, regs->regs[31]);
return 0;
give_sigsegv:
force_sigsegv(signr, current);
return -EFAULT;
}
