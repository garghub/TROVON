static void
titan_update_irq_hw(unsigned long mask)
{
register titan_cchip *cchip = TITAN_cchip;
unsigned long isa_enable = 1UL << 55;
register int bcpu = boot_cpuid;
#ifdef CONFIG_SMP
cpumask_t cpm;
volatile unsigned long *dim0, *dim1, *dim2, *dim3;
unsigned long mask0, mask1, mask2, mask3, dummy;
cpumask_copy(&cpm, cpu_present_mask);
mask &= ~isa_enable;
mask0 = mask & titan_cpu_irq_affinity[0];
mask1 = mask & titan_cpu_irq_affinity[1];
mask2 = mask & titan_cpu_irq_affinity[2];
mask3 = mask & titan_cpu_irq_affinity[3];
if (bcpu == 0) mask0 |= isa_enable;
else if (bcpu == 1) mask1 |= isa_enable;
else if (bcpu == 2) mask2 |= isa_enable;
else mask3 |= isa_enable;
dim0 = &cchip->dim0.csr;
dim1 = &cchip->dim1.csr;
dim2 = &cchip->dim2.csr;
dim3 = &cchip->dim3.csr;
if (!cpumask_test_cpu(0, &cpm)) dim0 = &dummy;
if (!cpumask_test_cpu(1, &cpm)) dim1 = &dummy;
if (!cpumask_test_cpu(2, &cpm)) dim2 = &dummy;
if (!cpumask_test_cpu(3, &cpm)) dim3 = &dummy;
*dim0 = mask0;
*dim1 = mask1;
*dim2 = mask2;
*dim3 = mask3;
mb();
*dim0;
*dim1;
*dim2;
*dim3;
#else
volatile unsigned long *dimB;
dimB = &cchip->dim0.csr;
if (bcpu == 1) dimB = &cchip->dim1.csr;
else if (bcpu == 2) dimB = &cchip->dim2.csr;
else if (bcpu == 3) dimB = &cchip->dim3.csr;
*dimB = mask | isa_enable;
mb();
*dimB;
#endif
}
static inline void
titan_enable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
spin_lock(&titan_irq_lock);
titan_cached_irq_mask |= 1UL << (irq - 16);
titan_update_irq_hw(titan_cached_irq_mask);
spin_unlock(&titan_irq_lock);
}
static inline void
titan_disable_irq(struct irq_data *d)
{
unsigned int irq = d->irq;
spin_lock(&titan_irq_lock);
titan_cached_irq_mask &= ~(1UL << (irq - 16));
titan_update_irq_hw(titan_cached_irq_mask);
spin_unlock(&titan_irq_lock);
}
static void
titan_cpu_set_irq_affinity(unsigned int irq, cpumask_t affinity)
{
int cpu;
for (cpu = 0; cpu < 4; cpu++) {
if (cpumask_test_cpu(cpu, &affinity))
titan_cpu_irq_affinity[cpu] |= 1UL << irq;
else
titan_cpu_irq_affinity[cpu] &= ~(1UL << irq);
}
}
static int
titan_set_irq_affinity(struct irq_data *d, const struct cpumask *affinity,
bool force)
{
unsigned int irq = d->irq;
spin_lock(&titan_irq_lock);
titan_cpu_set_irq_affinity(irq - 16, *affinity);
titan_update_irq_hw(titan_cached_irq_mask);
spin_unlock(&titan_irq_lock);
return 0;
}
static void
titan_device_interrupt(unsigned long vector)
{
printk("titan_device_interrupt: NOT IMPLEMENTED YET!!\n");
}
static void
titan_srm_device_interrupt(unsigned long vector)
{
int irq;
irq = (vector - 0x800) >> 4;
handle_irq(irq);
}
static void __init
init_titan_irqs(struct irq_chip * ops, int imin, int imax)
{
long i;
for (i = imin; i <= imax; ++i) {
irq_set_chip_and_handler(i, ops, handle_level_irq);
irq_set_status_flags(i, IRQ_LEVEL);
}
}
static irqreturn_t
titan_intr_nop(int irq, void *dev_id)
{
return IRQ_HANDLED;
}
static void __init
titan_init_irq(void)
{
if (alpha_using_srm && !alpha_mv.device_interrupt)
alpha_mv.device_interrupt = titan_srm_device_interrupt;
if (!alpha_mv.device_interrupt)
alpha_mv.device_interrupt = titan_device_interrupt;
titan_update_irq_hw(0);
init_titan_irqs(&titan_irq_type, 16, 63 + 16);
}
static void __init
titan_legacy_init_irq(void)
{
outb(0, DMA1_RESET_REG);
outb(0, DMA2_RESET_REG);
outb(DMA_MODE_CASCADE, DMA2_MODE_REG);
outb(0, DMA2_MASK_REG);
init_i8259a_irqs();
titan_init_irq();
}
void
titan_dispatch_irqs(u64 mask)
{
unsigned long vector;
mask &= titan_cpu_irq_affinity[smp_processor_id()];
while (mask) {
vector = 63 - __kernel_ctlz(mask);
mask &= ~(1UL << vector);
vector = 0x900 + (vector << 4);
alpha_mv.device_interrupt(vector);
}
}
static void __init
titan_request_irq(unsigned int irq, irq_handler_t handler,
unsigned long irqflags, const char *devname,
void *dev_id)
{
int err;
err = request_irq(irq, handler, irqflags, devname, dev_id);
if (err) {
printk("titan_request_irq for IRQ %d returned %d; ignoring\n",
irq, err);
}
}
static void __init
titan_late_init(void)
{
titan_request_irq(63+16, titan_intr_nop, IRQF_DISABLED,
"CChip Error", NULL);
titan_request_irq(62+16, titan_intr_nop, IRQF_DISABLED,
"PChip 0 H_Error", NULL);
titan_request_irq(61+16, titan_intr_nop, IRQF_DISABLED,
"PChip 1 H_Error", NULL);
titan_request_irq(60+16, titan_intr_nop, IRQF_DISABLED,
"PChip 0 C_Error", NULL);
titan_request_irq(59+16, titan_intr_nop, IRQF_DISABLED,
"PChip 1 C_Error", NULL);
titan_register_error_handlers();
cdl_check_console_data_log();
}
static int __devinit
titan_map_irq(struct pci_dev *dev, u8 slot, u8 pin)
{
u8 intline;
int irq;
pci_read_config_byte(dev, PCI_INTERRUPT_LINE, &intline);
irq = intline;
if ((irq & 0xF0) == 0xE0)
return irq;
return irq + 16;
}
static void __init
titan_init_pci(void)
{
titan_late_init();
pci_probe_only = 1;
common_init_pci();
SMC669_Init(0);
locate_and_init_vga(NULL);
}
static void __init
privateer_init_pci(void)
{
titan_request_irq(53+16, titan_intr_nop, IRQF_DISABLED,
"NMI", NULL);
titan_request_irq(50+16, titan_intr_nop, IRQF_DISABLED,
"Temperature Warning", NULL);
return titan_init_pci();
}
