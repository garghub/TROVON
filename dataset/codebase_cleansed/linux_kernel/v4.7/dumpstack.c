static unsigned long
__dump_trace(dump_trace_func_t func, void *data, unsigned long sp,
unsigned long low, unsigned long high)
{
struct stack_frame *sf;
struct pt_regs *regs;
while (1) {
if (sp < low || sp > high - sizeof(*sf))
return sp;
sf = (struct stack_frame *) sp;
while (1) {
if (func(data, sf->gprs[8]))
return sp;
low = sp;
sp = sf->back_chain;
if (!sp)
break;
if (sp <= low || sp > high - sizeof(*sf))
return sp;
sf = (struct stack_frame *) sp;
}
sp = (unsigned long) (sf + 1);
if (sp <= low || sp > high - sizeof(*regs))
return sp;
regs = (struct pt_regs *) sp;
if (!user_mode(regs)) {
if (func(data, regs->psw.addr))
return sp;
}
low = sp;
sp = regs->gprs[15];
}
}
void dump_trace(dump_trace_func_t func, void *data, struct task_struct *task,
unsigned long sp)
{
unsigned long frame_size;
frame_size = STACK_FRAME_OVERHEAD + sizeof(struct pt_regs);
#ifdef CONFIG_CHECK_STACK
sp = __dump_trace(func, data, sp,
S390_lowcore.panic_stack + frame_size - 4096,
S390_lowcore.panic_stack + frame_size);
#endif
sp = __dump_trace(func, data, sp,
S390_lowcore.async_stack + frame_size - ASYNC_SIZE,
S390_lowcore.async_stack + frame_size);
if (task)
__dump_trace(func, data, sp,
(unsigned long)task_stack_page(task),
(unsigned long)task_stack_page(task) + THREAD_SIZE);
else
__dump_trace(func, data, sp,
S390_lowcore.thread_info,
S390_lowcore.thread_info + THREAD_SIZE);
}
static int __return_address(void *data, unsigned long address)
{
struct return_address_data *rd = data;
if (rd->depth--)
return 0;
rd->address = address;
return 1;
}
unsigned long return_address(int depth)
{
struct return_address_data rd = { .depth = depth + 2 };
dump_trace(__return_address, &rd, NULL, current_stack_pointer());
return rd.address;
}
static int show_address(void *data, unsigned long address)
{
printk("([<%016lx>] %pSR)\n", address, (void *)address);
return 0;
}
static void show_trace(struct task_struct *task, unsigned long sp)
{
if (!sp)
sp = task ? task->thread.ksp : current_stack_pointer();
printk("Call Trace:\n");
dump_trace(show_address, NULL, task, sp);
if (!task)
task = current;
debug_show_held_locks(task);
}
void show_stack(struct task_struct *task, unsigned long *sp)
{
unsigned long *stack;
int i;
stack = sp;
if (!stack) {
if (!task)
stack = (unsigned long *)current_stack_pointer();
else
stack = (unsigned long *)task->thread.ksp;
}
for (i = 0; i < 20; i++) {
if (((addr_t) stack & (THREAD_SIZE-1)) == 0)
break;
if ((i * sizeof(long) % 32) == 0)
printk("%s ", i == 0 ? "" : "\n");
printk("%016lx ", *stack++);
}
printk("\n");
show_trace(task, (unsigned long)sp);
}
static void show_last_breaking_event(struct pt_regs *regs)
{
printk("Last Breaking-Event-Address:\n");
printk(" [<%016lx>] %pSR\n", regs->args[0], (void *)regs->args[0]);
}
void show_registers(struct pt_regs *regs)
{
struct psw_bits *psw = &psw_bits(regs->psw);
char *mode;
mode = user_mode(regs) ? "User" : "Krnl";
printk("%s PSW : %p %p", mode, (void *)regs->psw.mask, (void *)regs->psw.addr);
if (!user_mode(regs))
printk(" (%pSR)", (void *)regs->psw.addr);
printk("\n");
printk(" R:%x T:%x IO:%x EX:%x Key:%x M:%x W:%x "
"P:%x AS:%x CC:%x PM:%x", psw->r, psw->t, psw->i, psw->e,
psw->key, psw->m, psw->w, psw->p, psw->as, psw->cc, psw->pm);
printk(" RI:%x EA:%x", psw->ri, psw->eaba);
printk("\n%s GPRS: %016lx %016lx %016lx %016lx\n", mode,
regs->gprs[0], regs->gprs[1], regs->gprs[2], regs->gprs[3]);
printk(" %016lx %016lx %016lx %016lx\n",
regs->gprs[4], regs->gprs[5], regs->gprs[6], regs->gprs[7]);
printk(" %016lx %016lx %016lx %016lx\n",
regs->gprs[8], regs->gprs[9], regs->gprs[10], regs->gprs[11]);
printk(" %016lx %016lx %016lx %016lx\n",
regs->gprs[12], regs->gprs[13], regs->gprs[14], regs->gprs[15]);
show_code(regs);
}
void show_regs(struct pt_regs *regs)
{
show_regs_print_info(KERN_DEFAULT);
show_registers(regs);
if (!user_mode(regs))
show_trace(NULL, regs->gprs[15]);
show_last_breaking_event(regs);
}
void die(struct pt_regs *regs, const char *str)
{
static int die_counter;
oops_enter();
lgr_info_log();
debug_stop_all();
console_verbose();
spin_lock_irq(&die_lock);
bust_spinlocks(1);
printk("%s: %04x ilc:%d [#%d] ", str, regs->int_code & 0xffff,
regs->int_code >> 17, ++die_counter);
#ifdef CONFIG_PREEMPT
printk("PREEMPT ");
#endif
#ifdef CONFIG_SMP
printk("SMP ");
#endif
if (debug_pagealloc_enabled())
printk("DEBUG_PAGEALLOC");
printk("\n");
notify_die(DIE_OOPS, str, regs, 0, regs->int_code & 0xffff, SIGSEGV);
print_modules();
show_regs(regs);
bust_spinlocks(0);
add_taint(TAINT_DIE, LOCKDEP_NOW_UNRELIABLE);
spin_unlock_irq(&die_lock);
if (in_interrupt())
panic("Fatal exception in interrupt");
if (panic_on_oops)
panic("Fatal exception: panic_on_oops");
oops_exit();
do_exit(SIGSEGV);
}
