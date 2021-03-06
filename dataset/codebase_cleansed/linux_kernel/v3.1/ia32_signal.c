int copy_siginfo_to_user32(compat_siginfo_t __user *to, siginfo_t *from)
{
int err = 0;
if (!access_ok(VERIFY_WRITE, to, sizeof(compat_siginfo_t)))
return -EFAULT;
put_user_try {
put_user_ex(from->si_signo, &to->si_signo);
put_user_ex(from->si_errno, &to->si_errno);
put_user_ex((short)from->si_code, &to->si_code);
if (from->si_code < 0) {
put_user_ex(from->si_pid, &to->si_pid);
put_user_ex(from->si_uid, &to->si_uid);
put_user_ex(ptr_to_compat(from->si_ptr), &to->si_ptr);
} else {
put_user_ex(from->_sifields._pad[0],
&to->_sifields._pad[0]);
switch (from->si_code >> 16) {
case __SI_FAULT >> 16:
break;
case __SI_CHLD >> 16:
put_user_ex(from->si_utime, &to->si_utime);
put_user_ex(from->si_stime, &to->si_stime);
put_user_ex(from->si_status, &to->si_status);
default:
case __SI_KILL >> 16:
put_user_ex(from->si_uid, &to->si_uid);
break;
case __SI_POLL >> 16:
put_user_ex(from->si_fd, &to->si_fd);
break;
case __SI_TIMER >> 16:
put_user_ex(from->si_overrun, &to->si_overrun);
put_user_ex(ptr_to_compat(from->si_ptr),
&to->si_ptr);
break;
case __SI_RT >> 16:
case __SI_MESGQ >> 16:
put_user_ex(from->si_uid, &to->si_uid);
put_user_ex(from->si_int, &to->si_int);
break;
}
}
} put_user_catch(err);
return err;
}
int copy_siginfo_from_user32(siginfo_t *to, compat_siginfo_t __user *from)
{
int err = 0;
u32 ptr32;
if (!access_ok(VERIFY_READ, from, sizeof(compat_siginfo_t)))
return -EFAULT;
get_user_try {
get_user_ex(to->si_signo, &from->si_signo);
get_user_ex(to->si_errno, &from->si_errno);
get_user_ex(to->si_code, &from->si_code);
get_user_ex(to->si_pid, &from->si_pid);
get_user_ex(to->si_uid, &from->si_uid);
get_user_ex(ptr32, &from->si_ptr);
to->si_ptr = compat_ptr(ptr32);
} get_user_catch(err);
return err;
}
asmlinkage long sys32_sigsuspend(int history0, int history1, old_sigset_t mask)
{
sigset_t blocked;
current->saved_sigmask = current->blocked;
mask &= _BLOCKABLE;
siginitset(&blocked, mask);
set_current_blocked(&blocked);
current->state = TASK_INTERRUPTIBLE;
schedule();
set_restore_sigmask();
return -ERESTARTNOHAND;
}
asmlinkage long sys32_sigaltstack(const stack_ia32_t __user *uss_ptr,
stack_ia32_t __user *uoss_ptr,
struct pt_regs *regs)
{
stack_t uss, uoss;
int ret, err = 0;
mm_segment_t seg;
if (uss_ptr) {
u32 ptr;
memset(&uss, 0, sizeof(stack_t));
if (!access_ok(VERIFY_READ, uss_ptr, sizeof(stack_ia32_t)))
return -EFAULT;
get_user_try {
get_user_ex(ptr, &uss_ptr->ss_sp);
get_user_ex(uss.ss_flags, &uss_ptr->ss_flags);
get_user_ex(uss.ss_size, &uss_ptr->ss_size);
} get_user_catch(err);
if (err)
return -EFAULT;
uss.ss_sp = compat_ptr(ptr);
}
seg = get_fs();
set_fs(KERNEL_DS);
ret = do_sigaltstack(uss_ptr ? &uss : NULL, &uoss, regs->sp);
set_fs(seg);
if (ret >= 0 && uoss_ptr) {
if (!access_ok(VERIFY_WRITE, uoss_ptr, sizeof(stack_ia32_t)))
return -EFAULT;
put_user_try {
put_user_ex(ptr_to_compat(uoss.ss_sp), &uoss_ptr->ss_sp);
put_user_ex(uoss.ss_flags, &uoss_ptr->ss_flags);
put_user_ex(uoss.ss_size, &uoss_ptr->ss_size);
} put_user_catch(err);
if (err)
ret = -EFAULT;
}
return ret;
}
static int ia32_restore_sigcontext(struct pt_regs *regs,
struct sigcontext_ia32 __user *sc,
unsigned int *pax)
{
unsigned int tmpflags, err = 0;
void __user *buf;
u32 tmp;
current_thread_info()->restart_block.fn = do_no_restart_syscall;
get_user_try {
RELOAD_SEG(gs);
RELOAD_SEG(fs);
RELOAD_SEG(ds);
RELOAD_SEG(es);
COPY(di); COPY(si); COPY(bp); COPY(sp); COPY(bx);
COPY(dx); COPY(cx); COPY(ip);
COPY_SEG_CPL3(cs);
COPY_SEG_CPL3(ss);
get_user_ex(tmpflags, &sc->flags);
regs->flags = (regs->flags & ~FIX_EFLAGS) | (tmpflags & FIX_EFLAGS);
regs->orig_ax = -1;
get_user_ex(tmp, &sc->fpstate);
buf = compat_ptr(tmp);
err |= restore_i387_xstate_ia32(buf);
get_user_ex(*pax, &sc->ax);
} get_user_catch(err);
return err;
}
asmlinkage long sys32_sigreturn(struct pt_regs *regs)
{
struct sigframe_ia32 __user *frame = (struct sigframe_ia32 __user *)(regs->sp-8);
sigset_t set;
unsigned int ax;
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__get_user(set.sig[0], &frame->sc.oldmask)
|| (_COMPAT_NSIG_WORDS > 1
&& __copy_from_user((((char *) &set.sig) + 4),
&frame->extramask,
sizeof(frame->extramask))))
goto badframe;
sigdelsetmask(&set, ~_BLOCKABLE);
set_current_blocked(&set);
if (ia32_restore_sigcontext(regs, &frame->sc, &ax))
goto badframe;
return ax;
badframe:
signal_fault(regs, frame, "32bit sigreturn");
return 0;
}
asmlinkage long sys32_rt_sigreturn(struct pt_regs *regs)
{
struct rt_sigframe_ia32 __user *frame;
sigset_t set;
unsigned int ax;
struct pt_regs tregs;
frame = (struct rt_sigframe_ia32 __user *)(regs->sp - 4);
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_from_user(&set, &frame->uc.uc_sigmask, sizeof(set)))
goto badframe;
sigdelsetmask(&set, ~_BLOCKABLE);
set_current_blocked(&set);
if (ia32_restore_sigcontext(regs, &frame->uc.uc_mcontext, &ax))
goto badframe;
tregs = *regs;
if (sys32_sigaltstack(&frame->uc.uc_stack, NULL, &tregs) == -EFAULT)
goto badframe;
return ax;
badframe:
signal_fault(regs, frame, "32bit rt sigreturn");
return 0;
}
static int ia32_setup_sigcontext(struct sigcontext_ia32 __user *sc,
void __user *fpstate,
struct pt_regs *regs, unsigned int mask)
{
int err = 0;
put_user_try {
put_user_ex(get_user_seg(gs), (unsigned int __user *)&sc->gs);
put_user_ex(get_user_seg(fs), (unsigned int __user *)&sc->fs);
put_user_ex(get_user_seg(ds), (unsigned int __user *)&sc->ds);
put_user_ex(get_user_seg(es), (unsigned int __user *)&sc->es);
put_user_ex(regs->di, &sc->di);
put_user_ex(regs->si, &sc->si);
put_user_ex(regs->bp, &sc->bp);
put_user_ex(regs->sp, &sc->sp);
put_user_ex(regs->bx, &sc->bx);
put_user_ex(regs->dx, &sc->dx);
put_user_ex(regs->cx, &sc->cx);
put_user_ex(regs->ax, &sc->ax);
put_user_ex(current->thread.trap_no, &sc->trapno);
put_user_ex(current->thread.error_code, &sc->err);
put_user_ex(regs->ip, &sc->ip);
put_user_ex(regs->cs, (unsigned int __user *)&sc->cs);
put_user_ex(regs->flags, &sc->flags);
put_user_ex(regs->sp, &sc->sp_at_signal);
put_user_ex(regs->ss, (unsigned int __user *)&sc->ss);
put_user_ex(ptr_to_compat(fpstate), &sc->fpstate);
put_user_ex(mask, &sc->oldmask);
put_user_ex(current->thread.cr2, &sc->cr2);
} put_user_catch(err);
return err;
}
static void __user *get_sigframe(struct k_sigaction *ka, struct pt_regs *regs,
size_t frame_size,
void **fpstate)
{
unsigned long sp;
sp = regs->sp;
if (ka->sa.sa_flags & SA_ONSTACK) {
if (sas_ss_flags(sp) == 0)
sp = current->sas_ss_sp + current->sas_ss_size;
}
else if ((regs->ss & 0xffff) != __USER32_DS &&
!(ka->sa.sa_flags & SA_RESTORER) &&
ka->sa.sa_restorer)
sp = (unsigned long) ka->sa.sa_restorer;
if (used_math()) {
sp = sp - sig_xstate_ia32_size;
*fpstate = (struct _fpstate_ia32 *) sp;
if (save_i387_xstate_ia32(*fpstate) < 0)
return (void __user *) -1L;
}
sp -= frame_size;
sp = ((sp + 4) & -16ul) - 4;
return (void __user *) sp;
}
int ia32_setup_frame(int sig, struct k_sigaction *ka,
compat_sigset_t *set, struct pt_regs *regs)
{
struct sigframe_ia32 __user *frame;
void __user *restorer;
int err = 0;
void __user *fpstate = NULL;
static const struct {
u16 poplmovl;
u32 val;
u16 int80;
} __attribute__((packed)) code = {
0xb858,
__NR_ia32_sigreturn,
0x80cd,
};
frame = get_sigframe(ka, regs, sizeof(*frame), &fpstate);
if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
return -EFAULT;
if (__put_user(sig, &frame->sig))
return -EFAULT;
if (ia32_setup_sigcontext(&frame->sc, fpstate, regs, set->sig[0]))
return -EFAULT;
if (_COMPAT_NSIG_WORDS > 1) {
if (__copy_to_user(frame->extramask, &set->sig[1],
sizeof(frame->extramask)))
return -EFAULT;
}
if (ka->sa.sa_flags & SA_RESTORER) {
restorer = ka->sa.sa_restorer;
} else {
if (current->mm->context.vdso)
restorer = VDSO32_SYMBOL(current->mm->context.vdso,
sigreturn);
else
restorer = &frame->retcode;
}
put_user_try {
put_user_ex(ptr_to_compat(restorer), &frame->pretcode);
put_user_ex(*((u64 *)&code), (u64 *)frame->retcode);
} put_user_catch(err);
if (err)
return -EFAULT;
regs->sp = (unsigned long) frame;
regs->ip = (unsigned long) ka->sa.sa_handler;
regs->ax = sig;
regs->dx = 0;
regs->cx = 0;
loadsegment(ds, __USER32_DS);
loadsegment(es, __USER32_DS);
regs->cs = __USER32_CS;
regs->ss = __USER32_DS;
return 0;
}
int ia32_setup_rt_frame(int sig, struct k_sigaction *ka, siginfo_t *info,
compat_sigset_t *set, struct pt_regs *regs)
{
struct rt_sigframe_ia32 __user *frame;
void __user *restorer;
int err = 0;
void __user *fpstate = NULL;
static const struct {
u8 movl;
u32 val;
u16 int80;
u8 pad;
} __attribute__((packed)) code = {
0xb8,
__NR_ia32_rt_sigreturn,
0x80cd,
0,
};
frame = get_sigframe(ka, regs, sizeof(*frame), &fpstate);
if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
return -EFAULT;
put_user_try {
put_user_ex(sig, &frame->sig);
put_user_ex(ptr_to_compat(&frame->info), &frame->pinfo);
put_user_ex(ptr_to_compat(&frame->uc), &frame->puc);
err |= copy_siginfo_to_user32(&frame->info, info);
if (cpu_has_xsave)
put_user_ex(UC_FP_XSTATE, &frame->uc.uc_flags);
else
put_user_ex(0, &frame->uc.uc_flags);
put_user_ex(0, &frame->uc.uc_link);
put_user_ex(current->sas_ss_sp, &frame->uc.uc_stack.ss_sp);
put_user_ex(sas_ss_flags(regs->sp),
&frame->uc.uc_stack.ss_flags);
put_user_ex(current->sas_ss_size, &frame->uc.uc_stack.ss_size);
err |= ia32_setup_sigcontext(&frame->uc.uc_mcontext, fpstate,
regs, set->sig[0]);
err |= __copy_to_user(&frame->uc.uc_sigmask, set, sizeof(*set));
if (ka->sa.sa_flags & SA_RESTORER)
restorer = ka->sa.sa_restorer;
else
restorer = VDSO32_SYMBOL(current->mm->context.vdso,
rt_sigreturn);
put_user_ex(ptr_to_compat(restorer), &frame->pretcode);
put_user_ex(*((u64 *)&code), (u64 *)frame->retcode);
} put_user_catch(err);
if (err)
return -EFAULT;
regs->sp = (unsigned long) frame;
regs->ip = (unsigned long) ka->sa.sa_handler;
regs->ax = sig;
regs->dx = (unsigned long) &frame->info;
regs->cx = (unsigned long) &frame->uc;
loadsegment(ds, __USER32_DS);
loadsegment(es, __USER32_DS);
regs->cs = __USER32_CS;
regs->ss = __USER32_DS;
return 0;
}
