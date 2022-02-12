void cpu_idle(void)
{
for (;;) {
if (ARCH_SUN4C) {
static int count = HZ;
static unsigned long last_jiffies;
static unsigned long last_faults;
static unsigned long fps;
unsigned long now;
unsigned long faults;
extern unsigned long sun4c_kernel_faults;
extern void sun4c_grow_kernel_ring(void);
local_irq_disable();
now = jiffies;
count -= (now - last_jiffies);
last_jiffies = now;
if (count < 0) {
count += HZ;
faults = sun4c_kernel_faults;
fps = (fps + (faults - last_faults)) >> 1;
last_faults = faults;
#if 0
printk("kernel faults / second = %ld\n", fps);
#endif
if (fps >= SUN4C_FAULT_HIGH) {
sun4c_grow_kernel_ring();
}
}
local_irq_enable();
}
if (pm_idle) {
while (!need_resched())
(*pm_idle)();
} else {
while (!need_resched())
cpu_relax();
}
preempt_enable_no_resched();
schedule();
preempt_disable();
check_pgt_cache();
}
}
void cpu_idle(void)
{
set_thread_flag(TIF_POLLING_NRFLAG);
while(1) {
#ifdef CONFIG_SPARC_LEON
if (pm_idle) {
while (!need_resched())
(*pm_idle)();
} else
#endif
{
while (!need_resched())
cpu_relax();
}
preempt_enable_no_resched();
schedule();
preempt_disable();
check_pgt_cache();
}
}
void machine_halt(void)
{
local_irq_enable();
mdelay(8);
local_irq_disable();
prom_halt();
panic("Halt failed!");
}
void machine_restart(char * cmd)
{
char *p;
local_irq_enable();
mdelay(8);
local_irq_disable();
p = strchr (reboot_command, '\n');
if (p) *p = 0;
if (cmd)
prom_reboot(cmd);
if (*reboot_command)
prom_reboot(reboot_command);
prom_feval ("reset");
panic("Reboot failed!");
}
void machine_power_off(void)
{
if (auxio_power_register &&
(strcmp(of_console_device->type, "serial") || scons_pwroff))
*auxio_power_register |= AUXIO_POWER_OFF;
machine_halt();
}
void show_regs(struct pt_regs *r)
{
struct reg_window32 *rw = (struct reg_window32 *) r->u_regs[14];
printk("PSR: %08lx PC: %08lx NPC: %08lx Y: %08lx %s\n",
r->psr, r->pc, r->npc, r->y, print_tainted());
printk("PC: <%pS>\n", (void *) r->pc);
printk("%%G: %08lx %08lx %08lx %08lx %08lx %08lx %08lx %08lx\n",
r->u_regs[0], r->u_regs[1], r->u_regs[2], r->u_regs[3],
r->u_regs[4], r->u_regs[5], r->u_regs[6], r->u_regs[7]);
printk("%%O: %08lx %08lx %08lx %08lx %08lx %08lx %08lx %08lx\n",
r->u_regs[8], r->u_regs[9], r->u_regs[10], r->u_regs[11],
r->u_regs[12], r->u_regs[13], r->u_regs[14], r->u_regs[15]);
printk("RPC: <%pS>\n", (void *) r->u_regs[15]);
printk("%%L: %08lx %08lx %08lx %08lx %08lx %08lx %08lx %08lx\n",
rw->locals[0], rw->locals[1], rw->locals[2], rw->locals[3],
rw->locals[4], rw->locals[5], rw->locals[6], rw->locals[7]);
printk("%%I: %08lx %08lx %08lx %08lx %08lx %08lx %08lx %08lx\n",
rw->ins[0], rw->ins[1], rw->ins[2], rw->ins[3],
rw->ins[4], rw->ins[5], rw->ins[6], rw->ins[7]);
}
void show_stack(struct task_struct *tsk, unsigned long *_ksp)
{
unsigned long pc, fp;
unsigned long task_base;
struct reg_window32 *rw;
int count = 0;
if (tsk != NULL)
task_base = (unsigned long) task_stack_page(tsk);
else
task_base = (unsigned long) current_thread_info();
fp = (unsigned long) _ksp;
do {
if (fp < (task_base + sizeof(struct thread_info)) ||
fp >= (task_base + (PAGE_SIZE << 1)))
break;
rw = (struct reg_window32 *) fp;
pc = rw->ins[7];
printk("[%08lx : ", pc);
printk("%pS ] ", (void *) pc);
fp = rw->ins[6];
} while (++count < 16);
printk("\n");
}
void dump_stack(void)
{
unsigned long *ksp;
__asm__ __volatile__("mov %%fp, %0"
: "=r" (ksp));
show_stack(current, ksp);
}
unsigned long thread_saved_pc(struct task_struct *tsk)
{
return task_thread_info(tsk)->kpc;
}
static inline struct sparc_stackf __user *
clone_stackframe(struct sparc_stackf __user *dst,
struct sparc_stackf __user *src)
{
unsigned long size, fp;
struct sparc_stackf *tmp;
struct sparc_stackf __user *sp;
if (get_user(tmp, &src->fp))
return NULL;
fp = (unsigned long) tmp;
size = (fp - ((unsigned long) src));
fp = (unsigned long) dst;
sp = (struct sparc_stackf __user *)(fp - size);
if (__copy_user(sp, src, size))
sp = NULL;
else if (put_user(fp, &sp->fp))
sp = NULL;
return sp;
}
asmlinkage int sparc_do_fork(unsigned long clone_flags,
unsigned long stack_start,
struct pt_regs *regs,
unsigned long stack_size)
{
unsigned long parent_tid_ptr, child_tid_ptr;
unsigned long orig_i1 = regs->u_regs[UREG_I1];
long ret;
parent_tid_ptr = regs->u_regs[UREG_I2];
child_tid_ptr = regs->u_regs[UREG_I4];
ret = do_fork(clone_flags, stack_start,
regs, stack_size,
(int __user *) parent_tid_ptr,
(int __user *) child_tid_ptr);
if ((unsigned long)ret >= -ERESTART_RESTARTBLOCK)
regs->u_regs[UREG_I1] = orig_i1;
return ret;
}
int dump_fpu (struct pt_regs * regs, elf_fpregset_t * fpregs)
{
if (used_math()) {
memset(fpregs, 0, sizeof(*fpregs));
fpregs->pr_q_entrysize = 8;
return 1;
}
#ifdef CONFIG_SMP
if (test_thread_flag(TIF_USEDFPU)) {
put_psr(get_psr() | PSR_EF);
fpsave(&current->thread.float_regs[0], &current->thread.fsr,
&current->thread.fpqueue[0], &current->thread.fpqdepth);
if (regs != NULL) {
regs->psr &= ~(PSR_EF);
clear_thread_flag(TIF_USEDFPU);
}
}
#else
if (current == last_task_used_math) {
put_psr(get_psr() | PSR_EF);
fpsave(&current->thread.float_regs[0], &current->thread.fsr,
&current->thread.fpqueue[0], &current->thread.fpqdepth);
if (regs != NULL) {
regs->psr &= ~(PSR_EF);
last_task_used_math = NULL;
}
}
#endif
memcpy(&fpregs->pr_fr.pr_regs[0],
&current->thread.float_regs[0],
(sizeof(unsigned long) * 32));
fpregs->pr_fsr = current->thread.fsr;
fpregs->pr_qcnt = current->thread.fpqdepth;
fpregs->pr_q_entrysize = 8;
fpregs->pr_en = 1;
if(fpregs->pr_qcnt != 0) {
memcpy(&fpregs->pr_q[0],
&current->thread.fpqueue[0],
sizeof(struct fpq) * fpregs->pr_qcnt);
}
memset(&fpregs->pr_q[fpregs->pr_qcnt], 0,
sizeof(struct fpq) * (32 - fpregs->pr_qcnt));
return 1;
}
asmlinkage int sparc_execve(struct pt_regs *regs)
{
int error, base = 0;
char *filename;
if(regs->u_regs[UREG_G1] == 0)
base = 1;
filename = getname((char __user *)regs->u_regs[base + UREG_I0]);
error = PTR_ERR(filename);
if(IS_ERR(filename))
goto out;
error = do_execve(filename,
(const char __user *const __user *)
regs->u_regs[base + UREG_I1],
(const char __user *const __user *)
regs->u_regs[base + UREG_I2],
regs);
putname(filename);
out:
return error;
}
pid_t kernel_thread(int (*fn)(void *), void * arg, unsigned long flags)
{
long retval;
__asm__ __volatile__("mov %4, %%g2\n\t"
"mov %5, %%g3\n\t"
"mov %1, %%g1\n\t"
"mov %2, %%o0\n\t"
"mov 0, %%o1\n\t"
"t 0x10\n\t"
"cmp %%o1, 0\n\t"
"be 1f\n\t"
" nop\n\t"
"jmpl %%g2, %%o7\n\t"
" mov %%g3, %%o0\n\t"
"mov %3, %%g1\n\t"
"t 0x10\n\t"
"1: mov %%o0, %0\n\t" :
"=r" (retval) :
"i" (__NR_clone), "r" (flags | CLONE_VM | CLONE_UNTRACED),
"i" (__NR_exit), "r" (fn), "r" (arg) :
"g1", "g2", "g3", "o0", "o1", "memory", "cc");
return retval;
}
unsigned long get_wchan(struct task_struct *task)
{
unsigned long pc, fp, bias = 0;
unsigned long task_base = (unsigned long) task;
unsigned long ret = 0;
struct reg_window32 *rw;
int count = 0;
if (!task || task == current ||
task->state == TASK_RUNNING)
goto out;
fp = task_thread_info(task)->ksp + bias;
do {
if (fp < (task_base + sizeof(struct thread_info)) ||
fp >= (task_base + (2 * PAGE_SIZE)))
break;
rw = (struct reg_window32 *) fp;
pc = rw->ins[7];
if (!in_sched_functions(pc)) {
ret = pc;
goto out;
}
fp = rw->ins[6] + bias;
} while (++count < 16);
out:
return ret;
}
