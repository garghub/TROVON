static void instruction_dump(unsigned long *pc)
{
int i;
if((((unsigned long) pc) & 3))
return;
for(i = -3; i < 6; i++)
printk("%c%08lx%c",i?' ':'<',pc[i],i?' ':'>');
printk("\n");
}
void die_if_kernel(char *str, struct pt_regs *regs)
{
static int die_counter;
int count = 0;
printk(
" \\|/ ____ \\|/\n"
" \"@'/ ,. \\`@\"\n"
" /_| \\__/ |_\\\n"
" \\__U_/\n");
printk("%s(%d): %s [#%d]\n", current->comm, task_pid_nr(current), str, ++die_counter);
show_regs(regs);
add_taint(TAINT_DIE);
__SAVE; __SAVE; __SAVE; __SAVE;
__SAVE; __SAVE; __SAVE; __SAVE;
__RESTORE; __RESTORE; __RESTORE; __RESTORE;
__RESTORE; __RESTORE; __RESTORE; __RESTORE;
{
struct reg_window32 *rw = (struct reg_window32 *)regs->u_regs[UREG_FP];
while(rw &&
count++ < 30 &&
(((unsigned long) rw) >= PAGE_OFFSET) &&
!(((unsigned long) rw) & 0x7)) {
printk("Caller[%08lx]: %pS\n", rw->ins[7],
(void *) rw->ins[7]);
rw = (struct reg_window32 *)rw->ins[6];
}
}
printk("Instruction DUMP:");
instruction_dump ((unsigned long *) regs->pc);
if(regs->psr & PSR_PS)
do_exit(SIGKILL);
do_exit(SIGSEGV);
}
void do_hw_interrupt(struct pt_regs *regs, unsigned long type)
{
siginfo_t info;
if(type < 0x80) {
printk("Unimplemented Sparc TRAP, type = %02lx\n", type);
die_if_kernel("Whee... Hello Mr. Penguin", regs);
}
if(regs->psr & PSR_PS)
die_if_kernel("Kernel bad trap", regs);
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_ILLTRP;
info.si_addr = (void __user *)regs->pc;
info.si_trapno = type - 0x80;
force_sig_info(SIGILL, &info, current);
}
void do_illegal_instruction(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
if(psr & PSR_PS)
die_if_kernel("Kernel illegal instruction", regs);
#ifdef TRAP_DEBUG
printk("Ill instr. at pc=%08lx instruction is %08lx\n",
regs->pc, *(unsigned long *)regs->pc);
#endif
if (!do_user_muldiv (regs, pc))
return;
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_ILLOPC;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGILL, &info, current);
}
void do_priv_instruction(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
if(psr & PSR_PS)
die_if_kernel("Penguin instruction from Penguin mode??!?!", regs);
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_PRVOPC;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGILL, &info, current);
}
void do_memaccess_unaligned(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
if(regs->psr & PSR_PS) {
printk("KERNEL MNA at pc %08lx npc %08lx called by %08lx\n", pc, npc,
regs->u_regs[UREG_RETPC]);
die_if_kernel("BOGUS", regs);
}
#if 0
show_regs (regs);
instruction_dump ((unsigned long *) regs->pc);
printk ("do_MNA!\n");
#endif
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_ADRALN;
info.si_addr = (void *)0;
info.si_trapno = 0;
send_sig_info(SIGBUS, &info, current);
}
void do_fpd_trap(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
if(psr & PSR_PS)
die_if_kernel("Kernel gets FloatingPenguinUnit disabled trap", regs);
put_psr(get_psr() | PSR_EF);
regs->psr |= PSR_EF;
#ifndef CONFIG_SMP
if(last_task_used_math == current)
return;
if(last_task_used_math) {
struct task_struct *fptask = last_task_used_math;
fpsave(&fptask->thread.float_regs[0], &fptask->thread.fsr,
&fptask->thread.fpqueue[0], &fptask->thread.fpqdepth);
}
last_task_used_math = current;
if(used_math()) {
fpload(&current->thread.float_regs[0], &current->thread.fsr);
} else {
fpload(&init_fregs[0], &init_fsr);
set_used_math();
}
#else
if(!used_math()) {
fpload(&init_fregs[0], &init_fsr);
set_used_math();
} else {
fpload(&current->thread.float_regs[0], &current->thread.fsr);
}
set_thread_flag(TIF_USEDFPU);
#endif
}
void handle_tag_overflow(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
if(psr & PSR_PS)
die_if_kernel("Penguin overflow trap from kernel mode", regs);
info.si_signo = SIGEMT;
info.si_errno = 0;
info.si_code = EMT_TAGOVF;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGEMT, &info, current);
}
void handle_watchpoint(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
#ifdef TRAP_DEBUG
printk("Watchpoint detected at PC %08lx NPC %08lx PSR %08lx\n",
pc, npc, psr);
#endif
if(psr & PSR_PS)
panic("Tell me what a watchpoint trap is, and I'll then deal "
"with such a beast...");
}
void handle_reg_access(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
#ifdef TRAP_DEBUG
printk("Register Access Exception at PC %08lx NPC %08lx PSR %08lx\n",
pc, npc, psr);
#endif
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = BUS_OBJERR;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
force_sig_info(SIGBUS, &info, current);
}
void handle_cp_disabled(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_COPROC;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGILL, &info, current);
}
void handle_cp_exception(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
#ifdef TRAP_DEBUG
printk("Co-Processor Exception at PC %08lx NPC %08lx PSR %08lx\n",
pc, npc, psr);
#endif
info.si_signo = SIGILL;
info.si_errno = 0;
info.si_code = ILL_COPROC;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGILL, &info, current);
}
void handle_hw_divzero(struct pt_regs *regs, unsigned long pc, unsigned long npc,
unsigned long psr)
{
siginfo_t info;
info.si_signo = SIGFPE;
info.si_errno = 0;
info.si_code = FPE_INTDIV;
info.si_addr = (void __user *)pc;
info.si_trapno = 0;
send_sig_info(SIGFPE, &info, current);
}
void do_BUG(const char *file, int line)
{
printk("kernel BUG at %s:%d!\n", file, line);
}
void trap_init(void)
{
extern void thread_info_offsets_are_bolixed_pete(void);
if (TI_UWINMASK != offsetof(struct thread_info, uwinmask) ||
TI_TASK != offsetof(struct thread_info, task) ||
TI_EXECDOMAIN != offsetof(struct thread_info, exec_domain) ||
TI_FLAGS != offsetof(struct thread_info, flags) ||
TI_CPU != offsetof(struct thread_info, cpu) ||
TI_PREEMPT != offsetof(struct thread_info, preempt_count) ||
TI_SOFTIRQ != offsetof(struct thread_info, softirq_count) ||
TI_HARDIRQ != offsetof(struct thread_info, hardirq_count) ||
TI_KSP != offsetof(struct thread_info, ksp) ||
TI_KPC != offsetof(struct thread_info, kpc) ||
TI_KPSR != offsetof(struct thread_info, kpsr) ||
TI_KWIM != offsetof(struct thread_info, kwim) ||
TI_REG_WINDOW != offsetof(struct thread_info, reg_window) ||
TI_RWIN_SPTRS != offsetof(struct thread_info, rwbuf_stkptrs) ||
TI_W_SAVED != offsetof(struct thread_info, w_saved))
thread_info_offsets_are_bolixed_pete();
atomic_inc(&init_mm.mm_count);
current->active_mm = &init_mm;
}
