void __cpuinit smp_store_cpu_info(int id)
{
int cpu_node;
int mid;
cpu_data(id).udelay_val = loops_per_jiffy;
cpu_find_by_mid(id, &cpu_node);
cpu_data(id).clock_tick = prom_getintdefault(cpu_node,
"clock-frequency", 0);
cpu_data(id).prom_node = cpu_node;
mid = cpu_get_hwmid(cpu_node);
if (mid < 0) {
printk(KERN_NOTICE "No MID found for CPU%d at node 0x%08d", id, cpu_node);
mid = 0;
}
cpu_data(id).mid = mid;
}
void __init smp_cpus_done(unsigned int max_cpus)
{
extern void smp4m_smp_done(void);
extern void smp4d_smp_done(void);
unsigned long bogosum = 0;
int cpu, num = 0;
for_each_online_cpu(cpu) {
num++;
bogosum += cpu_data(cpu).udelay_val;
}
printk("Total of %d processors activated (%lu.%02lu BogoMIPS).\n",
num, bogosum/(500000/HZ),
(bogosum/(5000/HZ))%100);
switch(sparc_cpu_model) {
case sun4m:
smp4m_smp_done();
break;
case sun4d:
smp4d_smp_done();
break;
case sparc_leon:
leon_smp_done();
break;
case sun4e:
printk("SUN4E\n");
BUG();
break;
case sun4u:
printk("SUN4U\n");
BUG();
break;
default:
printk("UNKNOWN!\n");
BUG();
break;
}
}
void cpu_panic(void)
{
printk("CPU[%d]: Returns from cpu_idle!\n", smp_processor_id());
panic("SMP bolixed\n");
}
void smp_send_reschedule(int cpu)
{
sparc32_ipi_ops->resched(cpu);
}
void smp_send_stop(void)
{
}
void arch_send_call_function_single_ipi(int cpu)
{
sparc32_ipi_ops->single(cpu);
}
void arch_send_call_function_ipi_mask(const struct cpumask *mask)
{
int cpu;
for_each_cpu(cpu, mask)
sparc32_ipi_ops->mask_one(cpu);
}
void smp_resched_interrupt(void)
{
irq_enter();
scheduler_ipi();
local_cpu_data().irq_resched_count++;
irq_exit();
}
void smp_call_function_single_interrupt(void)
{
irq_enter();
generic_smp_call_function_single_interrupt();
local_cpu_data().irq_call_count++;
irq_exit();
}
void smp_call_function_interrupt(void)
{
irq_enter();
generic_smp_call_function_interrupt();
local_cpu_data().irq_call_count++;
irq_exit();
}
int setup_profiling_timer(unsigned int multiplier)
{
return -EINVAL;
}
void __init smp_prepare_cpus(unsigned int max_cpus)
{
extern void __init smp4m_boot_cpus(void);
extern void __init smp4d_boot_cpus(void);
int i, cpuid, extra;
printk("Entering SMP Mode...\n");
extra = 0;
for (i = 0; !cpu_find_by_instance(i, NULL, &cpuid); i++) {
if (cpuid >= NR_CPUS)
extra++;
}
if (extra && max_cpus > i - extra)
printk("Warning: NR_CPUS is too low to start all cpus\n");
smp_store_cpu_info(boot_cpu_id);
switch(sparc_cpu_model) {
case sun4m:
smp4m_boot_cpus();
break;
case sun4d:
smp4d_boot_cpus();
break;
case sparc_leon:
leon_boot_cpus();
break;
case sun4e:
printk("SUN4E\n");
BUG();
break;
case sun4u:
printk("SUN4U\n");
BUG();
break;
default:
printk("UNKNOWN!\n");
BUG();
break;
}
}
void __init smp_setup_cpu_possible_map(void)
{
int instance, mid;
instance = 0;
while (!cpu_find_by_instance(instance, NULL, &mid)) {
if (mid < NR_CPUS) {
set_cpu_possible(mid, true);
set_cpu_present(mid, true);
}
instance++;
}
}
void __init smp_prepare_boot_cpu(void)
{
int cpuid = hard_smp_processor_id();
if (cpuid >= NR_CPUS) {
prom_printf("Serious problem, boot cpu id >= NR_CPUS\n");
prom_halt();
}
if (cpuid != 0)
printk("boot cpu id != 0, this could work but is untested\n");
current_thread_info()->cpu = cpuid;
set_cpu_online(cpuid, true);
set_cpu_possible(cpuid, true);
}
int __cpuinit __cpu_up(unsigned int cpu, struct task_struct *tidle)
{
extern int __cpuinit smp4m_boot_one_cpu(int, struct task_struct *);
extern int __cpuinit smp4d_boot_one_cpu(int, struct task_struct *);
int ret=0;
switch(sparc_cpu_model) {
case sun4m:
ret = smp4m_boot_one_cpu(cpu, tidle);
break;
case sun4d:
ret = smp4d_boot_one_cpu(cpu, tidle);
break;
case sparc_leon:
ret = leon_boot_one_cpu(cpu, tidle);
break;
case sun4e:
printk("SUN4E\n");
BUG();
break;
case sun4u:
printk("SUN4U\n");
BUG();
break;
default:
printk("UNKNOWN!\n");
BUG();
break;
}
if (!ret) {
cpumask_set_cpu(cpu, &smp_commenced_mask);
while (!cpu_online(cpu))
mb();
}
return ret;
}
void __cpuinit arch_cpu_pre_starting(void *arg)
{
local_ops->cache_all();
local_ops->tlb_all();
switch(sparc_cpu_model) {
case sun4m:
sun4m_cpu_pre_starting(arg);
break;
case sun4d:
sun4d_cpu_pre_starting(arg);
break;
case sparc_leon:
leon_cpu_pre_starting(arg);
break;
default:
BUG();
}
}
void __cpuinit arch_cpu_pre_online(void *arg)
{
unsigned int cpuid = hard_smp_processor_id();
register_percpu_ce(cpuid);
calibrate_delay();
smp_store_cpu_info(cpuid);
local_ops->cache_all();
local_ops->tlb_all();
switch(sparc_cpu_model) {
case sun4m:
sun4m_cpu_pre_online(arg);
break;
case sun4d:
sun4d_cpu_pre_online(arg);
break;
case sparc_leon:
leon_cpu_pre_online(arg);
break;
default:
BUG();
}
}
void __cpuinit sparc_start_secondary(void *arg)
{
unsigned int cpu;
arch_cpu_pre_starting(arg);
preempt_disable();
cpu = smp_processor_id();
notify_cpu_starting(cpu);
arch_cpu_pre_online(arg);
set_cpu_online(cpu, true);
local_irq_enable();
wmb();
cpu_idle();
BUG();
}
void __cpuinit smp_callin(void)
{
sparc_start_secondary(NULL);
}
void smp_bogo(struct seq_file *m)
{
int i;
for_each_online_cpu(i) {
seq_printf(m,
"Cpu%dBogo\t: %lu.%02lu\n",
i,
cpu_data(i).udelay_val/(500000/HZ),
(cpu_data(i).udelay_val/(5000/HZ))%100);
}
}
void smp_info(struct seq_file *m)
{
int i;
seq_printf(m, "State:\n");
for_each_online_cpu(i)
seq_printf(m, "CPU%d\t\t: online\n", i);
}
