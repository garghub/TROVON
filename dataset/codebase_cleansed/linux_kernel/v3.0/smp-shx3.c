static irqreturn_t ipi_interrupt_handler(int irq, void *arg)
{
unsigned int message = (unsigned int)(long)arg;
unsigned int cpu = hard_smp_processor_id();
unsigned int offs = 4 * cpu;
unsigned int x;
x = __raw_readl(0xfe410070 + offs);
x &= (1 << (message << 2));
__raw_writel(x, 0xfe410080 + offs);
smp_message_recv(message);
return IRQ_HANDLED;
}
static void shx3_smp_setup(void)
{
unsigned int cpu = 0;
int i, num;
init_cpu_possible(cpumask_of(cpu));
__raw_writel(__raw_readl(STBCR_REG(cpu)) | STBCR_LTSLP, STBCR_REG(cpu));
__cpu_number_map[0] = 0;
__cpu_logical_map[0] = 0;
for (i = 1, num = 0; i < NR_CPUS; i++) {
set_cpu_possible(i, true);
__cpu_number_map[i] = ++num;
__cpu_logical_map[num] = i;
}
printk(KERN_INFO "Detected %i available secondary CPU(s)\n", num);
}
static void shx3_prepare_cpus(unsigned int max_cpus)
{
int i;
local_timer_setup(0);
BUILD_BUG_ON(SMP_MSG_NR >= 8);
for (i = 0; i < SMP_MSG_NR; i++)
request_irq(104 + i, ipi_interrupt_handler,
IRQF_DISABLED | IRQF_PERCPU, "IPI", (void *)(long)i);
for (i = 0; i < max_cpus; i++)
set_cpu_present(i, true);
}
static void shx3_start_cpu(unsigned int cpu, unsigned long entry_point)
{
if (__in_29bit_mode())
__raw_writel(entry_point, RESET_REG(cpu));
else
__raw_writel(virt_to_phys(entry_point), RESET_REG(cpu));
if (!(__raw_readl(STBCR_REG(cpu)) & STBCR_MSTP))
__raw_writel(STBCR_MSTP, STBCR_REG(cpu));
while (!(__raw_readl(STBCR_REG(cpu)) & STBCR_MSTP))
cpu_relax();
__raw_writel(STBCR_RESET | STBCR_LTSLP, STBCR_REG(cpu));
}
static unsigned int shx3_smp_processor_id(void)
{
return __raw_readl(0xff000048);
}
static void shx3_send_ipi(unsigned int cpu, unsigned int message)
{
unsigned long addr = 0xfe410070 + (cpu * 4);
BUG_ON(cpu >= 4);
__raw_writel(1 << (message << 2), addr);
}
static void shx3_update_boot_vector(unsigned int cpu)
{
__raw_writel(STBCR_MSTP, STBCR_REG(cpu));
while (!(__raw_readl(STBCR_REG(cpu)) & STBCR_MSTP))
cpu_relax();
__raw_writel(STBCR_RESET, STBCR_REG(cpu));
}
static int __cpuinit
shx3_cpu_callback(struct notifier_block *nfb, unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned int)hcpu;
switch (action) {
case CPU_UP_PREPARE:
shx3_update_boot_vector(cpu);
break;
case CPU_ONLINE:
pr_info("CPU %u is now online\n", cpu);
break;
case CPU_DEAD:
break;
}
return NOTIFY_OK;
}
static int __cpuinit register_shx3_cpu_notifier(void)
{
register_hotcpu_notifier(&shx3_cpu_notifier);
return 0;
}
