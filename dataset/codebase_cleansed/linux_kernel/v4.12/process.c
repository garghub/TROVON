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
rcu_sysrq_start();
for (;;);
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
copy_thread(unsigned long clone_flags, unsigned long usp,
unsigned long kthread_arg, struct task_struct *p)
{
struct pt_regs *cregs = &(p->thread.regs);
void *stack = task_stack_page(p);
extern void * const ret_from_kernel_thread;
extern void * const child_return;
if (unlikely(p->flags & PF_KTHREAD)) {
memset(cregs, 0, sizeof(struct pt_regs));
if (!usp)
return 0;
cregs->ksp = (unsigned long)stack + THREAD_SZ_ALGN + FRAME_SIZE;
cregs->kpc = (unsigned long) &ret_from_kernel_thread;
#ifdef CONFIG_64BIT
cregs->gr[27] = ((unsigned long *)usp)[3];
cregs->gr[26] = ((unsigned long *)usp)[2];
#else
cregs->gr[26] = usp;
#endif
cregs->gr[25] = kthread_arg;
} else {
if (usp) {
usp = ALIGN(usp, 4);
if (likely(usp))
cregs->gr[30] = usp;
}
cregs->ksp = (unsigned long)stack + THREAD_SZ_ALGN + FRAME_SIZE;
cregs->kpc = (unsigned long) &child_return;
if (clone_flags & CLONE_SETTLS)
cregs->cr27 = cregs->gr[23];
}
return 0;
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
static inline unsigned long brk_rnd(void)
{
return (get_random_int() & BRK_RND_MASK) << PAGE_SHIFT;
}
unsigned long arch_randomize_brk(struct mm_struct *mm)
{
unsigned long ret = PAGE_ALIGN(mm->brk + brk_rnd());
if (ret < mm->brk)
return mm->brk;
return ret;
}
