static inline unsigned long
swap_ulong(volatile unsigned long *ptr, unsigned long val)
{
__asm__ __volatile__("swap [%1], %0\n\t" :
"=&r" (val), "=&r" (ptr) :
"0" (val), "1" (ptr));
return val;
}
void sun4m_cpu_pre_starting(void *arg)
{
}
void sun4m_cpu_pre_online(void *arg)
{
int cpuid = hard_smp_processor_id();
swap_ulong(&cpu_callin_map[cpuid], 1);
local_ops->cache_all();
local_ops->tlb_all();
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
atomic_inc(&init_mm.mm_count);
current->active_mm = &init_mm;
while (!cpumask_test_cpu(cpuid, &smp_commenced_mask))
mb();
}
void __init smp4m_boot_cpus(void)
{
sun4m_unmask_profile_irq();
local_ops->cache_all();
}
int smp4m_boot_one_cpu(int i, struct task_struct *idle)
{
unsigned long *entry = &sun4m_cpu_startup;
int timeout;
int cpu_node;
cpu_find_by_mid(i, &cpu_node);
current_set[i] = task_thread_info(idle);
entry += ((i - 1) * 3);
smp_penguin_ctable.which_io = 0;
smp_penguin_ctable.phys_addr = (unsigned int) srmmu_ctx_table_phys;
smp_penguin_ctable.reg_size = 0;
printk(KERN_INFO "Starting CPU %d at %p\n", i, entry);
local_ops->cache_all();
prom_startcpu(cpu_node, &smp_penguin_ctable, 0, (char *)entry);
for (timeout = 0; timeout < 10000; timeout++) {
if (cpu_callin_map[i])
break;
udelay(200);
}
if (!(cpu_callin_map[i])) {
printk(KERN_ERR "Processor %d is stuck.\n", i);
return -ENODEV;
}
local_ops->cache_all();
return 0;
}
void __init smp4m_smp_done(void)
{
int i, first;
int *prev;
first = 0;
prev = &first;
for_each_online_cpu(i) {
*prev = i;
prev = &cpu_data(i).next;
}
*prev = first;
local_ops->cache_all();
}
static void sun4m_send_ipi(int cpu, int level)
{
sbus_writel(SUN4M_SOFT_INT(level), &sun4m_irq_percpu[cpu]->set);
}
static void sun4m_ipi_resched(int cpu)
{
sun4m_send_ipi(cpu, IRQ_IPI_RESCHED);
}
static void sun4m_ipi_single(int cpu)
{
sun4m_send_ipi(cpu, IRQ_IPI_SINGLE);
}
static void sun4m_ipi_mask_one(int cpu)
{
sun4m_send_ipi(cpu, IRQ_IPI_MASK);
}
static void sun4m_cross_call(smpfunc_t func, cpumask_t mask, unsigned long arg1,
unsigned long arg2, unsigned long arg3,
unsigned long arg4)
{
register int ncpus = SUN4M_NCPUS;
unsigned long flags;
spin_lock_irqsave(&cross_call_lock, flags);
ccall_info.func = func;
ccall_info.arg1 = arg1;
ccall_info.arg2 = arg2;
ccall_info.arg3 = arg3;
ccall_info.arg4 = arg4;
ccall_info.arg5 = 0;
{
register int i;
cpumask_clear_cpu(smp_processor_id(), &mask);
cpumask_and(&mask, cpu_online_mask, &mask);
for (i = 0; i < ncpus; i++) {
if (cpumask_test_cpu(i, &mask)) {
ccall_info.processors_in[i] = 0;
ccall_info.processors_out[i] = 0;
sun4m_send_ipi(i, IRQ_CROSS_CALL);
} else {
ccall_info.processors_in[i] = 1;
ccall_info.processors_out[i] = 1;
}
}
}
{
register int i;
i = 0;
do {
if (!cpumask_test_cpu(i, &mask))
continue;
while (!ccall_info.processors_in[i])
barrier();
} while (++i < ncpus);
i = 0;
do {
if (!cpumask_test_cpu(i, &mask))
continue;
while (!ccall_info.processors_out[i])
barrier();
} while (++i < ncpus);
}
spin_unlock_irqrestore(&cross_call_lock, flags);
}
void smp4m_cross_call_irq(void)
{
int i = smp_processor_id();
ccall_info.processors_in[i] = 1;
ccall_info.func(ccall_info.arg1, ccall_info.arg2, ccall_info.arg3,
ccall_info.arg4, ccall_info.arg5);
ccall_info.processors_out[i] = 1;
}
void smp4m_percpu_timer_interrupt(struct pt_regs *regs)
{
struct pt_regs *old_regs;
struct clock_event_device *ce;
int cpu = smp_processor_id();
old_regs = set_irq_regs(regs);
ce = &per_cpu(sparc32_clockevent, cpu);
if (ce->mode & CLOCK_EVT_MODE_PERIODIC)
sun4m_clear_profile_irq(cpu);
else
sparc_config.load_profile_irq(cpu, 0);
irq_enter();
ce->event_handler(ce);
irq_exit();
set_irq_regs(old_regs);
}
void __init sun4m_init_smp(void)
{
sparc32_ipi_ops = &sun4m_ipi_ops;
}
