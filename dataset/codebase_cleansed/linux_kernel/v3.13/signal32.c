int copy_siginfo_to_user32(compat_siginfo_t __user *to, const siginfo_t *from)
{
int err;
if (!access_ok(VERIFY_WRITE, to, sizeof(compat_siginfo_t)))
return -EFAULT;
err = __put_user(from->si_signo, &to->si_signo);
err |= __put_user(from->si_errno, &to->si_errno);
err |= __put_user((short)from->si_code, &to->si_code);
if (from->si_code < 0)
err |= __copy_to_user(&to->_sifields._pad, &from->_sifields._pad, SI_PAD_SIZE);
else {
switch (from->si_code >> 16) {
case __SI_TIMER >> 16:
err |= __put_user(from->si_tid, &to->si_tid);
err |= __put_user(from->si_overrun, &to->si_overrun);
err |= __put_user(from->si_int, &to->si_int);
break;
case __SI_CHLD >> 16:
err |= __put_user(from->si_utime, &to->si_utime);
err |= __put_user(from->si_stime, &to->si_stime);
err |= __put_user(from->si_status, &to->si_status);
default:
err |= __put_user(from->si_pid, &to->si_pid);
err |= __put_user(from->si_uid, &to->si_uid);
break;
case __SI_FAULT >> 16:
err |= __put_user(from->si_trapno, &to->si_trapno);
err |= __put_user((unsigned long)from->si_addr, &to->si_addr);
break;
case __SI_POLL >> 16:
err |= __put_user(from->si_band, &to->si_band);
err |= __put_user(from->si_fd, &to->si_fd);
break;
case __SI_RT >> 16:
case __SI_MESGQ >> 16:
err |= __put_user(from->si_pid, &to->si_pid);
err |= __put_user(from->si_uid, &to->si_uid);
err |= __put_user(from->si_int, &to->si_int);
break;
}
}
return err;
}
int copy_siginfo_from_user32(siginfo_t *to, compat_siginfo_t __user *from)
{
if (!access_ok(VERIFY_WRITE, from, sizeof(compat_siginfo_t)))
return -EFAULT;
if (copy_from_user(to, from, 3*sizeof(int)) ||
copy_from_user(to->_sifields._pad, from->_sifields._pad,
SI_PAD_SIZE))
return -EFAULT;
return 0;
}
void do_sigreturn32(struct pt_regs *regs)
{
struct signal_frame32 __user *sf;
compat_uptr_t fpu_save;
compat_uptr_t rwin_save;
unsigned int psr;
unsigned pc, npc;
sigset_t set;
unsigned seta[_COMPAT_NSIG_WORDS];
int err, i;
current_thread_info()->restart_block.fn = do_no_restart_syscall;
synchronize_user_stack();
regs->u_regs[UREG_FP] &= 0x00000000ffffffffUL;
sf = (struct signal_frame32 __user *) regs->u_regs[UREG_FP];
if (!access_ok(VERIFY_READ, sf, sizeof(*sf)) ||
(((unsigned long) sf) & 3))
goto segv;
if (get_user(pc, &sf->info.si_regs.pc) ||
__get_user(npc, &sf->info.si_regs.npc))
goto segv;
if ((pc | npc) & 3)
goto segv;
if (test_thread_flag(TIF_32BIT)) {
pc &= 0xffffffff;
npc &= 0xffffffff;
}
regs->tpc = pc;
regs->tnpc = npc;
err = __get_user(regs->y, &sf->info.si_regs.y);
err |= __get_user(psr, &sf->info.si_regs.psr);
for (i = UREG_G1; i <= UREG_I7; i++)
err |= __get_user(regs->u_regs[i], &sf->info.si_regs.u_regs[i]);
if ((psr & (PSR_VERS|PSR_IMPL)) == PSR_V8PLUS) {
err |= __get_user(i, &sf->v8plus.g_upper[0]);
if (i == SIGINFO_EXTRA_V8PLUS_MAGIC) {
unsigned long asi;
for (i = UREG_G1; i <= UREG_I7; i++)
err |= __get_user(((u32 *)regs->u_regs)[2*i], &sf->v8plus.g_upper[i]);
err |= __get_user(asi, &sf->v8plus.asi);
regs->tstate &= ~TSTATE_ASI;
regs->tstate |= ((asi & 0xffUL) << 24UL);
}
}
regs->tstate &= ~(TSTATE_ICC|TSTATE_XCC);
regs->tstate |= psr_to_tstate_icc(psr);
pt_regs_clear_syscall(regs);
err |= __get_user(fpu_save, &sf->fpu_save);
if (!err && fpu_save)
err |= restore_fpu_state(regs, compat_ptr(fpu_save));
err |= __get_user(rwin_save, &sf->rwin_save);
if (!err && rwin_save) {
if (restore_rwin_state(compat_ptr(rwin_save)))
goto segv;
}
err |= __get_user(seta[0], &sf->info.si_mask);
err |= copy_from_user(seta+1, &sf->extramask,
(_COMPAT_NSIG_WORDS - 1) * sizeof(unsigned int));
if (err)
goto segv;
switch (_NSIG_WORDS) {
case 4: set.sig[3] = seta[6] + (((long)seta[7]) << 32);
case 3: set.sig[2] = seta[4] + (((long)seta[5]) << 32);
case 2: set.sig[1] = seta[2] + (((long)seta[3]) << 32);
case 1: set.sig[0] = seta[0] + (((long)seta[1]) << 32);
}
set_current_blocked(&set);
return;
segv:
force_sig(SIGSEGV, current);
}
asmlinkage void do_rt_sigreturn32(struct pt_regs *regs)
{
struct rt_signal_frame32 __user *sf;
unsigned int psr, pc, npc;
compat_uptr_t fpu_save;
compat_uptr_t rwin_save;
sigset_t set;
compat_sigset_t seta;
int err, i;
current_thread_info()->restart_block.fn = do_no_restart_syscall;
synchronize_user_stack();
regs->u_regs[UREG_FP] &= 0x00000000ffffffffUL;
sf = (struct rt_signal_frame32 __user *) regs->u_regs[UREG_FP];
if (!access_ok(VERIFY_READ, sf, sizeof(*sf)) ||
(((unsigned long) sf) & 3))
goto segv;
if (get_user(pc, &sf->regs.pc) ||
__get_user(npc, &sf->regs.npc))
goto segv;
if ((pc | npc) & 3)
goto segv;
if (test_thread_flag(TIF_32BIT)) {
pc &= 0xffffffff;
npc &= 0xffffffff;
}
regs->tpc = pc;
regs->tnpc = npc;
err = __get_user(regs->y, &sf->regs.y);
err |= __get_user(psr, &sf->regs.psr);
for (i = UREG_G1; i <= UREG_I7; i++)
err |= __get_user(regs->u_regs[i], &sf->regs.u_regs[i]);
if ((psr & (PSR_VERS|PSR_IMPL)) == PSR_V8PLUS) {
err |= __get_user(i, &sf->v8plus.g_upper[0]);
if (i == SIGINFO_EXTRA_V8PLUS_MAGIC) {
unsigned long asi;
for (i = UREG_G1; i <= UREG_I7; i++)
err |= __get_user(((u32 *)regs->u_regs)[2*i], &sf->v8plus.g_upper[i]);
err |= __get_user(asi, &sf->v8plus.asi);
regs->tstate &= ~TSTATE_ASI;
regs->tstate |= ((asi & 0xffUL) << 24UL);
}
}
regs->tstate &= ~(TSTATE_ICC|TSTATE_XCC);
regs->tstate |= psr_to_tstate_icc(psr);
pt_regs_clear_syscall(regs);
err |= __get_user(fpu_save, &sf->fpu_save);
if (!err && fpu_save)
err |= restore_fpu_state(regs, compat_ptr(fpu_save));
err |= copy_from_user(&seta, &sf->mask, sizeof(compat_sigset_t));
err |= compat_restore_altstack(&sf->stack);
if (err)
goto segv;
err |= __get_user(rwin_save, &sf->rwin_save);
if (!err && rwin_save) {
if (restore_rwin_state(compat_ptr(rwin_save)))
goto segv;
}
switch (_NSIG_WORDS) {
case 4: set.sig[3] = seta.sig[6] + (((long)seta.sig[7]) << 32);
case 3: set.sig[2] = seta.sig[4] + (((long)seta.sig[5]) << 32);
case 2: set.sig[1] = seta.sig[2] + (((long)seta.sig[3]) << 32);
case 1: set.sig[0] = seta.sig[0] + (((long)seta.sig[1]) << 32);
}
set_current_blocked(&set);
return;
segv:
force_sig(SIGSEGV, current);
}
static int invalid_frame_pointer(void __user *fp, int fplen)
{
if ((((unsigned long) fp) & 7) || ((unsigned long)fp) > 0x100000000ULL - fplen)
return 1;
return 0;
}
static void __user *get_sigframe(struct ksignal *ksig, struct pt_regs *regs, unsigned long framesize)
{
unsigned long sp;
regs->u_regs[UREG_FP] &= 0x00000000ffffffffUL;
sp = regs->u_regs[UREG_FP];
if (on_sig_stack(sp) && !likely(on_sig_stack(sp - framesize)))
return (void __user *) -1L;
sp = sigsp(sp, ksig) - framesize;
sp &= ~15UL;
return (void __user *) sp;
}
static void flush_signal_insns(unsigned long address)
{
unsigned long pstate, paddr;
pte_t *ptep, pte;
pgd_t *pgdp;
pud_t *pudp;
pmd_t *pmdp;
wmb();
__asm__ __volatile__("rdpr %%pstate, %0" : "=r" (pstate));
__asm__ __volatile__("wrpr %0, %1, %%pstate"
: : "r" (pstate), "i" (PSTATE_IE));
pgdp = pgd_offset(current->mm, address);
if (pgd_none(*pgdp))
goto out_irqs_on;
pudp = pud_offset(pgdp, address);
if (pud_none(*pudp))
goto out_irqs_on;
pmdp = pmd_offset(pudp, address);
if (pmd_none(*pmdp))
goto out_irqs_on;
ptep = pte_offset_map(pmdp, address);
pte = *ptep;
if (!pte_present(pte))
goto out_unmap;
paddr = (unsigned long) page_address(pte_page(pte));
__asm__ __volatile__("flush %0 + %1"
:
: "r" (paddr),
"r" (address & (PAGE_SIZE - 1))
: "memory");
out_unmap:
pte_unmap(ptep);
out_irqs_on:
__asm__ __volatile__("wrpr %0, 0x0, %%pstate" : : "r" (pstate));
}
static int setup_frame32(struct ksignal *ksig, struct pt_regs *regs,
sigset_t *oldset)
{
struct signal_frame32 __user *sf;
int i, err, wsaved;
void __user *tail;
int sigframe_size;
u32 psr;
unsigned int seta[_COMPAT_NSIG_WORDS];
synchronize_user_stack();
save_and_clear_fpu();
wsaved = get_thread_wsaved();
sigframe_size = sizeof(*sf);
if (current_thread_info()->fpsaved[0] & FPRS_FEF)
sigframe_size += sizeof(__siginfo_fpu_t);
if (wsaved)
sigframe_size += sizeof(__siginfo_rwin_t);
sf = (struct signal_frame32 __user *)
get_sigframe(ksig, regs, sigframe_size);
if (invalid_frame_pointer(sf, sigframe_size)) {
do_exit(SIGILL);
return -EINVAL;
}
tail = (sf + 1);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
err = put_user(regs->tpc, &sf->info.si_regs.pc);
err |= __put_user(regs->tnpc, &sf->info.si_regs.npc);
err |= __put_user(regs->y, &sf->info.si_regs.y);
psr = tstate_to_psr(regs->tstate);
if (current_thread_info()->fpsaved[0] & FPRS_FEF)
psr |= PSR_EF;
err |= __put_user(psr, &sf->info.si_regs.psr);
for (i = 0; i < 16; i++)
err |= __put_user(regs->u_regs[i], &sf->info.si_regs.u_regs[i]);
err |= __put_user(sizeof(siginfo_extra_v8plus_t), &sf->extra_size);
err |= __put_user(SIGINFO_EXTRA_V8PLUS_MAGIC, &sf->v8plus.g_upper[0]);
for (i = 1; i < 16; i++)
err |= __put_user(((u32 *)regs->u_regs)[2*i],
&sf->v8plus.g_upper[i]);
err |= __put_user((regs->tstate & TSTATE_ASI) >> 24UL,
&sf->v8plus.asi);
if (psr & PSR_EF) {
__siginfo_fpu_t __user *fp = tail;
tail += sizeof(*fp);
err |= save_fpu_state(regs, fp);
err |= __put_user((u64)fp, &sf->fpu_save);
} else {
err |= __put_user(0, &sf->fpu_save);
}
if (wsaved) {
__siginfo_rwin_t __user *rwp = tail;
tail += sizeof(*rwp);
err |= save_rwin_state(wsaved, rwp);
err |= __put_user((u64)rwp, &sf->rwin_save);
set_thread_wsaved(0);
} else {
err |= __put_user(0, &sf->rwin_save);
}
switch (_NSIG_WORDS) {
case 4: seta[7] = (oldset->sig[3] >> 32);
seta[6] = oldset->sig[3];
case 3: seta[5] = (oldset->sig[2] >> 32);
seta[4] = oldset->sig[2];
case 2: seta[3] = (oldset->sig[1] >> 32);
seta[2] = oldset->sig[1];
case 1: seta[1] = (oldset->sig[0] >> 32);
seta[0] = oldset->sig[0];
}
err |= __put_user(seta[0], &sf->info.si_mask);
err |= __copy_to_user(sf->extramask, seta + 1,
(_COMPAT_NSIG_WORDS - 1) * sizeof(unsigned int));
if (!wsaved) {
err |= copy_in_user((u32 __user *)sf,
(u32 __user *)(regs->u_regs[UREG_FP]),
sizeof(struct reg_window32));
} else {
struct reg_window *rp;
rp = &current_thread_info()->reg_window[wsaved - 1];
for (i = 0; i < 8; i++)
err |= __put_user(rp->locals[i], &sf->ss.locals[i]);
for (i = 0; i < 6; i++)
err |= __put_user(rp->ins[i], &sf->ss.ins[i]);
err |= __put_user(rp->ins[6], &sf->ss.fp);
err |= __put_user(rp->ins[7], &sf->ss.callers_pc);
}
if (err)
return err;
regs->u_regs[UREG_FP] = (unsigned long) sf;
regs->u_regs[UREG_I0] = ksig->sig;
regs->u_regs[UREG_I1] = (unsigned long) &sf->info;
regs->u_regs[UREG_I2] = (unsigned long) &sf->info;
regs->tpc = (unsigned long) ksig->ka.sa.sa_handler;
regs->tnpc = (regs->tpc + 4);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
if (ksig->ka.ka_restorer) {
regs->u_regs[UREG_I7] = (unsigned long)ksig->ka.ka_restorer;
} else {
unsigned long address = ((unsigned long)&(sf->insns[0]));
regs->u_regs[UREG_I7] = (unsigned long) (&(sf->insns[0]) - 2);
err = __put_user(0x821020d8, &sf->insns[0]);
err |= __put_user(0x91d02010, &sf->insns[1]);
if (err)
return err;
flush_signal_insns(address);
}
return 0;
}
static int setup_rt_frame32(struct ksignal *ksig, struct pt_regs *regs,
sigset_t *oldset)
{
struct rt_signal_frame32 __user *sf;
int i, err, wsaved;
void __user *tail;
int sigframe_size;
u32 psr;
compat_sigset_t seta;
synchronize_user_stack();
save_and_clear_fpu();
wsaved = get_thread_wsaved();
sigframe_size = sizeof(*sf);
if (current_thread_info()->fpsaved[0] & FPRS_FEF)
sigframe_size += sizeof(__siginfo_fpu_t);
if (wsaved)
sigframe_size += sizeof(__siginfo_rwin_t);
sf = (struct rt_signal_frame32 __user *)
get_sigframe(ksig, regs, sigframe_size);
if (invalid_frame_pointer(sf, sigframe_size)) {
do_exit(SIGILL);
return -EINVAL;
}
tail = (sf + 1);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
err = put_user(regs->tpc, &sf->regs.pc);
err |= __put_user(regs->tnpc, &sf->regs.npc);
err |= __put_user(regs->y, &sf->regs.y);
psr = tstate_to_psr(regs->tstate);
if (current_thread_info()->fpsaved[0] & FPRS_FEF)
psr |= PSR_EF;
err |= __put_user(psr, &sf->regs.psr);
for (i = 0; i < 16; i++)
err |= __put_user(regs->u_regs[i], &sf->regs.u_regs[i]);
err |= __put_user(sizeof(siginfo_extra_v8plus_t), &sf->extra_size);
err |= __put_user(SIGINFO_EXTRA_V8PLUS_MAGIC, &sf->v8plus.g_upper[0]);
for (i = 1; i < 16; i++)
err |= __put_user(((u32 *)regs->u_regs)[2*i],
&sf->v8plus.g_upper[i]);
err |= __put_user((regs->tstate & TSTATE_ASI) >> 24UL,
&sf->v8plus.asi);
if (psr & PSR_EF) {
__siginfo_fpu_t __user *fp = tail;
tail += sizeof(*fp);
err |= save_fpu_state(regs, fp);
err |= __put_user((u64)fp, &sf->fpu_save);
} else {
err |= __put_user(0, &sf->fpu_save);
}
if (wsaved) {
__siginfo_rwin_t __user *rwp = tail;
tail += sizeof(*rwp);
err |= save_rwin_state(wsaved, rwp);
err |= __put_user((u64)rwp, &sf->rwin_save);
set_thread_wsaved(0);
} else {
err |= __put_user(0, &sf->rwin_save);
}
err |= copy_siginfo_to_user32(&sf->info, &ksig->info);
err |= __compat_save_altstack(&sf->stack, regs->u_regs[UREG_FP]);
switch (_NSIG_WORDS) {
case 4: seta.sig[7] = (oldset->sig[3] >> 32);
seta.sig[6] = oldset->sig[3];
case 3: seta.sig[5] = (oldset->sig[2] >> 32);
seta.sig[4] = oldset->sig[2];
case 2: seta.sig[3] = (oldset->sig[1] >> 32);
seta.sig[2] = oldset->sig[1];
case 1: seta.sig[1] = (oldset->sig[0] >> 32);
seta.sig[0] = oldset->sig[0];
}
err |= __copy_to_user(&sf->mask, &seta, sizeof(compat_sigset_t));
if (!wsaved) {
err |= copy_in_user((u32 __user *)sf,
(u32 __user *)(regs->u_regs[UREG_FP]),
sizeof(struct reg_window32));
} else {
struct reg_window *rp;
rp = &current_thread_info()->reg_window[wsaved - 1];
for (i = 0; i < 8; i++)
err |= __put_user(rp->locals[i], &sf->ss.locals[i]);
for (i = 0; i < 6; i++)
err |= __put_user(rp->ins[i], &sf->ss.ins[i]);
err |= __put_user(rp->ins[6], &sf->ss.fp);
err |= __put_user(rp->ins[7], &sf->ss.callers_pc);
}
if (err)
return err;
regs->u_regs[UREG_FP] = (unsigned long) sf;
regs->u_regs[UREG_I0] = ksig->sig;
regs->u_regs[UREG_I1] = (unsigned long) &sf->info;
regs->u_regs[UREG_I2] = (unsigned long) &sf->regs;
regs->tpc = (unsigned long) ksig->ka.sa.sa_handler;
regs->tnpc = (regs->tpc + 4);
if (test_thread_flag(TIF_32BIT)) {
regs->tpc &= 0xffffffff;
regs->tnpc &= 0xffffffff;
}
if (ksig->ka.ka_restorer)
regs->u_regs[UREG_I7] = (unsigned long)ksig->ka.ka_restorer;
else {
unsigned long address = ((unsigned long)&(sf->insns[0]));
regs->u_regs[UREG_I7] = (unsigned long) (&(sf->insns[0]) - 2);
err |= __put_user(0x82102065, &sf->insns[0]);
err |= __put_user(0x91d02010, &sf->insns[1]);
if (err)
return err;
flush_signal_insns(address);
}
return 0;
}
static inline void handle_signal32(struct ksignal *ksig,
struct pt_regs *regs)
{
sigset_t *oldset = sigmask_to_save();
int err;
if (ksig->ka.sa.sa_flags & SA_SIGINFO)
err = setup_rt_frame32(ksig, regs, oldset);
else
err = setup_frame32(ksig, regs, oldset);
signal_setup_done(err, ksig, 0);
}
static inline void syscall_restart32(unsigned long orig_i0, struct pt_regs *regs,
struct sigaction *sa)
{
switch (regs->u_regs[UREG_I0]) {
case ERESTART_RESTARTBLOCK:
case ERESTARTNOHAND:
no_system_call_restart:
regs->u_regs[UREG_I0] = EINTR;
regs->tstate |= TSTATE_ICARRY;
break;
case ERESTARTSYS:
if (!(sa->sa_flags & SA_RESTART))
goto no_system_call_restart;
case ERESTARTNOINTR:
regs->u_regs[UREG_I0] = orig_i0;
regs->tpc -= 4;
regs->tnpc -= 4;
}
}
void do_signal32(struct pt_regs * regs)
{
struct ksignal ksig;
unsigned long orig_i0 = 0;
int restart_syscall = 0;
bool has_handler = get_signal(&ksig);
if (pt_regs_is_syscall(regs) &&
(regs->tstate & (TSTATE_XCARRY | TSTATE_ICARRY))) {
restart_syscall = 1;
orig_i0 = regs->u_regs[UREG_G6];
}
if (has_handler) {
if (restart_syscall)
syscall_restart32(orig_i0, regs, &ksig.ka.sa);
handle_signal32(&ksig, regs);
} else {
if (restart_syscall) {
switch (regs->u_regs[UREG_I0]) {
case ERESTARTNOHAND:
case ERESTARTSYS:
case ERESTARTNOINTR:
regs->u_regs[UREG_I0] = orig_i0;
regs->tpc -= 4;
regs->tnpc -= 4;
pt_regs_clear_syscall(regs);
case ERESTART_RESTARTBLOCK:
regs->u_regs[UREG_G1] = __NR_restart_syscall;
regs->tpc -= 4;
regs->tnpc -= 4;
pt_regs_clear_syscall(regs);
}
}
restore_saved_sigmask();
}
}
asmlinkage int do_sys32_sigstack(u32 u_ssptr, u32 u_ossptr, unsigned long sp)
{
struct sigstack32 __user *ssptr =
(struct sigstack32 __user *)((unsigned long)(u_ssptr));
struct sigstack32 __user *ossptr =
(struct sigstack32 __user *)((unsigned long)(u_ossptr));
int ret = -EFAULT;
if (ossptr) {
if (put_user(current->sas_ss_sp + current->sas_ss_size,
&ossptr->the_stack) ||
__put_user(on_sig_stack(sp), &ossptr->cur_status))
goto out;
}
if (ssptr) {
u32 ss_sp;
if (get_user(ss_sp, &ssptr->the_stack))
goto out;
ret = -EPERM;
if (current->sas_ss_sp && on_sig_stack(sp))
goto out;
current->sas_ss_sp = (unsigned long)ss_sp - SIGSTKSZ;
current->sas_ss_size = SIGSTKSZ;
}
ret = 0;
out:
return ret;
}
