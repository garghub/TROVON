static irqreturn_t j2_ipi_interrupt_handler(int irq, void *arg)
{
unsigned cpu = hard_smp_processor_id();
volatile unsigned *pmsg = &per_cpu(j2_ipi_messages, cpu);
unsigned messages, i;
do messages = *pmsg;
while (cmpxchg(pmsg, messages, 0) != messages);
if (!messages) return IRQ_NONE;
for (i=0; i<SMP_MSG_NR; i++)
if (messages & (1U<<i))
smp_message_recv(i);
return IRQ_HANDLED;
}
static void j2_smp_setup(void)
{
}
static void j2_prepare_cpus(unsigned int max_cpus)
{
struct device_node *np;
unsigned i, max = 1;
np = of_find_compatible_node(NULL, NULL, "jcore,ipi-controller");
if (!np)
goto out;
j2_ipi_irq = irq_of_parse_and_map(np, 0);
j2_ipi_trigger = of_iomap(np, 0);
if (!j2_ipi_irq || !j2_ipi_trigger)
goto out;
np = of_find_compatible_node(NULL, NULL, "jcore,cpuid-mmio");
if (!np)
goto out;
sh2_cpuid_addr = of_iomap(np, 0);
if (!sh2_cpuid_addr)
goto out;
if (request_irq(j2_ipi_irq, j2_ipi_interrupt_handler, IRQF_PERCPU,
"ipi", (void *)j2_ipi_interrupt_handler) != 0)
goto out;
max = max_cpus;
out:
for (i=max; i<NR_CPUS; i++) {
set_cpu_possible(i, false);
set_cpu_present(i, false);
}
}
static void j2_start_cpu(unsigned int cpu, unsigned long entry_point)
{
struct device_node *np;
u32 regs[2];
void __iomem *release, *initpc;
if (!cpu) return;
np = of_get_cpu_node(cpu, NULL);
if (!np) return;
if (of_property_read_u32_array(np, "cpu-release-addr", regs, 2)) return;
release = ioremap_nocache(regs[0], sizeof(u32));
initpc = ioremap_nocache(regs[1], sizeof(u32));
__raw_writel(entry_point, initpc);
__raw_writel(1, release);
iounmap(initpc);
iounmap(release);
pr_info("J2 SMP: requested start of cpu %u\n", cpu);
}
static unsigned int j2_smp_processor_id(void)
{
return __raw_readl(sh2_cpuid_addr);
}
static void j2_send_ipi(unsigned int cpu, unsigned int message)
{
volatile unsigned *pmsg;
unsigned old;
unsigned long val;
pmsg = &per_cpu(j2_ipi_messages, cpu);
do old = *pmsg;
while (cmpxchg(pmsg, old, old|(1U<<message)) != old);
val = __raw_readl(j2_ipi_trigger + cpu);
__raw_writel(val | (1U<<28), j2_ipi_trigger + cpu);
}
