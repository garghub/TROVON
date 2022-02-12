static inline unsigned long sun4d_swap(volatile unsigned long *ptr, unsigned long val)
{
__asm__ __volatile__("swap [%1], %0\n\t" :
"=&r" (val), "=&r" (ptr) :
"0" (val), "1" (ptr));
return val;
}
static inline void show_leds(int cpuid)
{
cpuid &= 0x1e;
__asm__ __volatile__ ("stba %0, [%1] %2" : :
"r" ((cpu_leds[cpuid] << 4) | cpu_leds[cpuid+1]),
"r" (ECSR_BASE(cpuid) | BB_LEDS),
"i" (ASI_M_CTL));
}
void sun4d_cpu_pre_starting(void *arg)
{
int cpuid = hard_smp_processor_id();
cpu_leds[cpuid] = 0x6;
show_leds(cpuid);
cc_set_imsk((cc_get_imsk() & ~0x8000) | 0x4000);
}
void sun4d_cpu_pre_online(void *arg)
{
unsigned long flags;
int cpuid;
cpuid = hard_smp_processor_id();
sun4d_swap((unsigned long *)&cpu_callin_map[cpuid], 1);
local_ops->cache_all();
local_ops->tlb_all();
while ((unsigned long)current_set[cpuid] < PAGE_OFFSET)
barrier();
while (current_set[cpuid]->cpu != cpuid)
barrier();
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
cpu_leds[cpuid] = 0x9;
show_leds(cpuid);
mmgrab(&init_mm);
current->active_mm = &init_mm;
local_ops->cache_all();
local_ops->tlb_all();
while (!cpumask_test_cpu(cpuid, &smp_commenced_mask))
barrier();
spin_lock_irqsave(&sun4d_imsk_lock, flags);
cc_set_imsk(cc_get_imsk() & ~0x4000);
spin_unlock_irqrestore(&sun4d_imsk_lock, flags);
}
void __init smp4d_boot_cpus(void)
{
smp4d_ipi_init();
if (boot_cpu_id)
current_set[0] = NULL;
local_ops->cache_all();
}
int smp4d_boot_one_cpu(int i, struct task_struct *idle)
{
unsigned long *entry = &sun4d_cpu_startup;
int timeout;
int cpu_node;
cpu_find_by_instance(i, &cpu_node, NULL);
current_set[i] = task_thread_info(idle);
smp_penguin_ctable.which_io = 0;
smp_penguin_ctable.phys_addr = (unsigned int) srmmu_ctx_table_phys;
smp_penguin_ctable.reg_size = 0;
printk(KERN_INFO "Starting CPU %d at %p\n", i, entry);
local_ops->cache_all();
prom_startcpu(cpu_node,
&smp_penguin_ctable, 0, (char *)entry);
printk(KERN_INFO "prom_startcpu returned :)\n");
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
void __init smp4d_smp_done(void)
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
smp_processors_ready = 1;
sun4d_distribute_irqs();
}
static void __init smp4d_ipi_init(void)
{
int cpu;
struct sun4d_ipi_work *work;
printk(KERN_INFO "smp4d: setup IPI at IRQ %d\n", SUN4D_IPI_IRQ);
for_each_possible_cpu(cpu) {
work = &per_cpu(sun4d_ipi_work, cpu);
work->single = work->msk = work->resched = 0;
}
}
void sun4d_ipi_interrupt(void)
{
struct sun4d_ipi_work *work = this_cpu_ptr(&sun4d_ipi_work);
if (work->single) {
work->single = 0;
smp_call_function_single_interrupt();
}
if (work->msk) {
work->msk = 0;
smp_call_function_interrupt();
}
if (work->resched) {
work->resched = 0;
smp_resched_interrupt();
}
}
static void sun4d_send_ipi(int cpu, int level)
{
cc_set_igen(IGEN_MESSAGE(0, cpu << 3, 6 + ((level >> 1) & 7), 1 << (level - 1)));
}
static void sun4d_ipi_single(int cpu)
{
struct sun4d_ipi_work *work = &per_cpu(sun4d_ipi_work, cpu);
work->single = 1;
sun4d_send_ipi(cpu, SUN4D_IPI_IRQ);
}
static void sun4d_ipi_mask_one(int cpu)
{
struct sun4d_ipi_work *work = &per_cpu(sun4d_ipi_work, cpu);
work->msk = 1;
sun4d_send_ipi(cpu, SUN4D_IPI_IRQ);
}
static void sun4d_ipi_resched(int cpu)
{
struct sun4d_ipi_work *work = &per_cpu(sun4d_ipi_work, cpu);
work->resched = 1;
sun4d_send_ipi(cpu, SUN4D_IPI_IRQ);
}
static void sun4d_cross_call(smpfunc_t func, cpumask_t mask, unsigned long arg1,
unsigned long arg2, unsigned long arg3,
unsigned long arg4)
{
if (smp_processors_ready) {
register int high = smp_highest_cpu;
unsigned long flags;
spin_lock_irqsave(&cross_call_lock, flags);
{
register smpfunc_t f asm("i0") = func;
register unsigned long a1 asm("i1") = arg1;
register unsigned long a2 asm("i2") = arg2;
register unsigned long a3 asm("i3") = arg3;
register unsigned long a4 asm("i4") = arg4;
register unsigned long a5 asm("i5") = 0;
__asm__ __volatile__(
"std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
"r" (&ccall_info.func));
}
{
register int i;
cpumask_clear_cpu(smp_processor_id(), &mask);
cpumask_and(&mask, cpu_online_mask, &mask);
for (i = 0; i <= high; i++) {
if (cpumask_test_cpu(i, &mask)) {
ccall_info.processors_in[i] = 0;
ccall_info.processors_out[i] = 0;
sun4d_send_ipi(i, IRQ_CROSS_CALL);
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
} while (++i <= high);
i = 0;
do {
if (!cpumask_test_cpu(i, &mask))
continue;
while (!ccall_info.processors_out[i])
barrier();
} while (++i <= high);
}
spin_unlock_irqrestore(&cross_call_lock, flags);
}
}
void smp4d_cross_call_irq(void)
{
int i = hard_smp_processor_id();
ccall_info.processors_in[i] = 1;
ccall_info.func(ccall_info.arg1, ccall_info.arg2, ccall_info.arg3,
ccall_info.arg4, ccall_info.arg5);
ccall_info.processors_out[i] = 1;
}
void smp4d_percpu_timer_interrupt(struct pt_regs *regs)
{
struct pt_regs *old_regs;
int cpu = hard_smp_processor_id();
struct clock_event_device *ce;
static int cpu_tick[NR_CPUS];
static char led_mask[] = { 0xe, 0xd, 0xb, 0x7, 0xb, 0xd };
old_regs = set_irq_regs(regs);
bw_get_prof_limit(cpu);
bw_clear_intr_mask(0, 1);
cpu_tick[cpu]++;
if (!(cpu_tick[cpu] & 15)) {
if (cpu_tick[cpu] == 0x60)
cpu_tick[cpu] = 0;
cpu_leds[cpu] = led_mask[cpu_tick[cpu] >> 4];
show_leds(cpu);
}
ce = &per_cpu(sparc32_clockevent, cpu);
irq_enter();
ce->event_handler(ce);
irq_exit();
set_irq_regs(old_regs);
}
void __init sun4d_init_smp(void)
{
int i;
t_nmi[1] = t_nmi[1] + (linux_trap_ipi15_sun4d - linux_trap_ipi15_sun4m);
sparc32_ipi_ops = &sun4d_ipi_ops;
for (i = 0; i < NR_CPUS; i++) {
ccall_info.processors_in[i] = 1;
ccall_info.processors_out[i] = 1;
}
}
