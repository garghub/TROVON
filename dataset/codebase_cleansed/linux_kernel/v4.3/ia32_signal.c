static int ia32_restore_sigcontext(struct pt_regs *regs,
struct sigcontext_ia32 __user *sc)
{
unsigned int tmpflags, err = 0;
void __user *buf;
u32 tmp;
current->restart_block.fn = do_no_restart_syscall;
get_user_try {
RELOAD_SEG(gs);
RELOAD_SEG(fs);
RELOAD_SEG(ds);
RELOAD_SEG(es);
COPY(di); COPY(si); COPY(bp); COPY(sp); COPY(bx);
COPY(dx); COPY(cx); COPY(ip); COPY(ax);
COPY_SEG_CPL3(cs);
COPY_SEG_CPL3(ss);
get_user_ex(tmpflags, &sc->flags);
regs->flags = (regs->flags & ~FIX_EFLAGS) | (tmpflags & FIX_EFLAGS);
regs->orig_ax = -1;
get_user_ex(tmp, &sc->fpstate);
buf = compat_ptr(tmp);
} get_user_catch(err);
err |= fpu__restore_sig(buf, 1);
force_iret();
return err;
}
asmlinkage long sys32_sigreturn(void)
{
struct pt_regs *regs = current_pt_regs();
struct sigframe_ia32 __user *frame = (struct sigframe_ia32 __user *)(regs->sp-8);
sigset_t set;
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__get_user(set.sig[0], &frame->sc.oldmask)
|| (_COMPAT_NSIG_WORDS > 1
&& __copy_from_user((((char *) &set.sig) + 4),
&frame->extramask,
sizeof(frame->extramask))))
goto badframe;
set_current_blocked(&set);
if (ia32_restore_sigcontext(regs, &frame->sc))
goto badframe;
return regs->ax;
badframe:
signal_fault(regs, frame, "32bit sigreturn");
return 0;
}
asmlinkage long sys32_rt_sigreturn(void)
{
struct pt_regs *regs = current_pt_regs();
struct rt_sigframe_ia32 __user *frame;
sigset_t set;
frame = (struct rt_sigframe_ia32 __user *)(regs->sp - 4);
if (!access_ok(VERIFY_READ, frame, sizeof(*frame)))
goto badframe;
if (__copy_from_user(&set, &frame->uc.uc_sigmask, sizeof(set)))
goto badframe;
set_current_blocked(&set);
if (ia32_restore_sigcontext(regs, &frame->uc.uc_mcontext))
goto badframe;
if (compat_restore_altstack(&frame->uc.uc_stack))
goto badframe;
return regs->ax;
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
put_user_ex(current->thread.trap_nr, &sc->trapno);
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
static void __user *get_sigframe(struct ksignal *ksig, struct pt_regs *regs,
size_t frame_size,
void __user **fpstate)
{
struct fpu *fpu = &current->thread.fpu;
unsigned long sp;
sp = regs->sp;
if (ksig->ka.sa.sa_flags & SA_ONSTACK)
sp = sigsp(sp, ksig);
else if ((regs->ss & 0xffff) != __USER32_DS &&
!(ksig->ka.sa.sa_flags & SA_RESTORER) &&
ksig->ka.sa.sa_restorer)
sp = (unsigned long) ksig->ka.sa.sa_restorer;
if (fpu->fpstate_active) {
unsigned long fx_aligned, math_size;
sp = fpu__alloc_mathframe(sp, 1, &fx_aligned, &math_size);
*fpstate = (struct _fpstate_ia32 __user *) sp;
if (copy_fpstate_to_sigframe(*fpstate, (void __user *)fx_aligned,
math_size) < 0)
return (void __user *) -1L;
}
sp -= frame_size;
sp = ((sp + 4) & -16ul) - 4;
return (void __user *) sp;
}
int ia32_setup_frame(int sig, struct ksignal *ksig,
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
frame = get_sigframe(ksig, regs, sizeof(*frame), &fpstate);
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
if (ksig->ka.sa.sa_flags & SA_RESTORER) {
restorer = ksig->ka.sa.sa_restorer;
} else {
if (current->mm->context.vdso)
restorer = current->mm->context.vdso +
selected_vdso32->sym___kernel_sigreturn;
else
restorer = &frame->retcode;
}
put_user_try {
put_user_ex(ptr_to_compat(restorer), &frame->pretcode);
put_user_ex(*((u64 *)&code), (u64 __user *)frame->retcode);
} put_user_catch(err);
if (err)
return -EFAULT;
regs->sp = (unsigned long) frame;
regs->ip = (unsigned long) ksig->ka.sa.sa_handler;
regs->ax = sig;
regs->dx = 0;
regs->cx = 0;
loadsegment(ds, __USER32_DS);
loadsegment(es, __USER32_DS);
regs->cs = __USER32_CS;
regs->ss = __USER32_DS;
return 0;
}
int ia32_setup_rt_frame(int sig, struct ksignal *ksig,
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
frame = get_sigframe(ksig, regs, sizeof(*frame), &fpstate);
if (!access_ok(VERIFY_WRITE, frame, sizeof(*frame)))
return -EFAULT;
put_user_try {
put_user_ex(sig, &frame->sig);
put_user_ex(ptr_to_compat(&frame->info), &frame->pinfo);
put_user_ex(ptr_to_compat(&frame->uc), &frame->puc);
if (cpu_has_xsave)
put_user_ex(UC_FP_XSTATE, &frame->uc.uc_flags);
else
put_user_ex(0, &frame->uc.uc_flags);
put_user_ex(0, &frame->uc.uc_link);
compat_save_altstack_ex(&frame->uc.uc_stack, regs->sp);
if (ksig->ka.sa.sa_flags & SA_RESTORER)
restorer = ksig->ka.sa.sa_restorer;
else
restorer = current->mm->context.vdso +
selected_vdso32->sym___kernel_rt_sigreturn;
put_user_ex(ptr_to_compat(restorer), &frame->pretcode);
put_user_ex(*((u64 *)&code), (u64 __user *)frame->retcode);
} put_user_catch(err);
err |= copy_siginfo_to_user32(&frame->info, &ksig->info);
err |= ia32_setup_sigcontext(&frame->uc.uc_mcontext, fpstate,
regs, set->sig[0]);
err |= __copy_to_user(&frame->uc.uc_sigmask, set, sizeof(*set));
if (err)
return -EFAULT;
regs->sp = (unsigned long) frame;
regs->ip = (unsigned long) ksig->ka.sa.sa_handler;
regs->ax = sig;
regs->dx = (unsigned long) &frame->info;
regs->cx = (unsigned long) &frame->uc;
loadsegment(ds, __USER32_DS);
loadsegment(es, __USER32_DS);
regs->cs = __USER32_CS;
regs->ss = __USER32_DS;
return 0;
}
