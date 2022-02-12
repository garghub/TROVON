void cpu_idle(void)
{
set_thread_flag(TIF_POLLING_NRFLAG);
while (1) {
while (!need_resched())
barrier();
preempt_enable_no_resched();
schedule();
preempt_disable();
check_pgt_cache();
}
}
void machine_restart(char *cmd)
{
#ifdef FASTBOOT_SELFTEST_SUPPORT
if (ftc_bitmap) {
pdc_do_firm_test_reset(ftc_bitmap);
}
#endif
pdc_chassis_send_status(PDC_CHASSIS_DIRECT_SHUTDOWN);
pdc_do_reset();
gsc_writel(CMD_RESET, COMMAND_GLOBAL);
while (1) ;
}
void machine_halt(void)
{
}
void machine_power_off(void)
{
if (chassis_power_off)
chassis_power_off();
pdc_soft_power_button(0);
pdc_chassis_send_status(PDC_CHASSIS_DIRECT_SHUTDOWN);
printk(KERN_EMERG "System shut down completed.\n"
"Please power this system off now.");
}
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
{
return __kernel_thread(fn, arg, flags);
}
void exit_thread(void)
{
}
void flush_thread(void)
{
}
void release_thread(struct task_struct *dead_task)
{
}
int dump_fpu (struct pt_regs * regs, elf_fpregset_t *r)
{
if (regs == NULL)
return 0;
memcpy(r, regs->fr, sizeof *r);
return 1;
}
int dump_task_fpu (struct task_struct *tsk, elf_fpregset_t *r)
{
memcpy(r, tsk->thread.regs.fr, sizeof(*r));
return 1;
}
int
sys_clone(unsigned long clone_flags, unsigned long usp,
struct pt_regs *regs)
{
int __user *parent_tidptr = (int __user *)regs->gr[24];
int __user *child_tidptr = (int __user *)regs->gr[22];
usp = ALIGN(usp, 4);
if (usp == 0)
usp = regs->gr[30];
return do_fork(clone_flags, usp, regs, 0, parent_tidptr, child_tidptr);
}
int
sys_vfork(struct pt_regs *regs)
{
return do_fork(CLONE_VFORK | CLONE_VM | SIGCHLD, regs->gr[30], regs, 0, NULL, NULL);
}
int
copy_thread(unsigned long clone_flags, unsigned long usp,
unsigned long unused,
struct task_struct * p, struct pt_regs * pregs)
{
struct pt_regs * cregs = &(p->thread.regs);
void *stack = task_stack_page(p);
extern void * const ret_from_kernel_thread;
extern void * const child_return;
#ifdef CONFIG_HPUX
extern void * const hpux_child_return;
#endif
*cregs = *pregs;
cregs->gr[28] = 0;
if (usp == 1) {
cregs->ksp = (unsigned long)stack + THREAD_SZ_ALGN;
cregs->kpc = (unsigned long) &ret_from_kernel_thread;
#ifdef CONFIG_64BIT
cregs->gr[27] = pregs->gr[27];
#endif
cregs->gr[26] = pregs->gr[26];
cregs->gr[25] = pregs->gr[25];
} else {
cregs->ksp = (unsigned long)stack
+ (pregs->gr[21] & (THREAD_SIZE - 1));
cregs->gr[30] = usp;
if (p->personality == PER_HPUX) {
#ifdef CONFIG_HPUX
cregs->kpc = (unsigned long) &hpux_child_return;
#else
BUG();
#endif
} else {
cregs->kpc = (unsigned long) &child_return;
}
if (clone_flags & CLONE_SETTLS)
cregs->cr27 = pregs->gr[23];
}
return 0;
}
unsigned long thread_saved_pc(struct task_struct *t)
{
return t->thread.regs.kpc;
}
asmlinkage int sys_execve(struct pt_regs *regs)
{
int error;
char *filename;
filename = getname((const char __user *) regs->gr[26]);
error = PTR_ERR(filename);
if (IS_ERR(filename))
goto out;
error = do_execve(filename,
(const char __user *const __user *) regs->gr[25],
(const char __user *const __user *) regs->gr[24],
regs);
putname(filename);
out:
return error;
}
int kernel_execve(const char *filename,
const char *const argv[],
const char *const envp[])
{
return __execve(filename, argv, envp, current);
}
unsigned long
get_wchan(struct task_struct *p)
{
struct unwind_frame_info info;
unsigned long ip;
int count = 0;
if (!p || p == current || p->state == TASK_RUNNING)
return 0;
unwind_frame_init_from_blocked_task(&info, p);
do {
if (unwind_once(&info) < 0)
return 0;
ip = info.ip;
if (!in_sched_functions(ip))
return ip;
} while (count++ < 16);
return 0;
}
void *dereference_function_descriptor(void *ptr)
{
Elf64_Fdesc *desc = ptr;
void *p;
if (!probe_kernel_address(&desc->addr, p))
ptr = p;
return ptr;
}
