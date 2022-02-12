static void vic_init2(void __iomem *base)
{
int i;
for (i = 0; i < 16; i++) {
void __iomem *reg = base + VIC_VECT_CNTL0 + (i * 4);
writel(VIC_VECT_CNTL_ENABLE | i, reg);
}
writel(32, base + VIC_PL190_DEF_VECT_ADDR);
}
static void resume_one_vic(struct vic_device *vic)
{
void __iomem *base = vic->base;
printk(KERN_DEBUG "%s: resuming vic at %p\n", __func__, base);
vic_init2(base);
writel(vic->int_select, base + VIC_INT_SELECT);
writel(vic->protect, base + VIC_PROTECT);
writel(vic->int_enable, base + VIC_INT_ENABLE);
writel(~vic->int_enable, base + VIC_INT_ENABLE_CLEAR);
writel(vic->soft_int, base + VIC_INT_SOFT);
writel(~vic->soft_int, base + VIC_INT_SOFT_CLEAR);
}
static void vic_resume(void)
{
int id;
for (id = vic_id - 1; id >= 0; id--)
resume_one_vic(vic_devices + id);
}
static void suspend_one_vic(struct vic_device *vic)
{
void __iomem *base = vic->base;
printk(KERN_DEBUG "%s: suspending vic at %p\n", __func__, base);
vic->int_select = readl(base + VIC_INT_SELECT);
vic->int_enable = readl(base + VIC_INT_ENABLE);
vic->soft_int = readl(base + VIC_INT_SOFT);
vic->protect = readl(base + VIC_PROTECT);
writel(vic->resume_irqs, base + VIC_INT_ENABLE);
writel(~vic->resume_irqs, base + VIC_INT_ENABLE_CLEAR);
}
static int vic_suspend(void)
{
int id;
for (id = 0; id < vic_id; id++)
suspend_one_vic(vic_devices + id);
return 0;
}
static int __init vic_pm_init(void)
{
if (vic_id > 0)
register_syscore_ops(&vic_syscore_ops);
return 0;
}
static void __init vic_pm_register(void __iomem *base, unsigned int irq, u32 resume_sources)
{
struct vic_device *v;
if (vic_id >= ARRAY_SIZE(vic_devices))
printk(KERN_ERR "%s: too few VICs, increase CONFIG_ARM_VIC_NR\n", __func__);
else {
v = &vic_devices[vic_id];
v->base = base;
v->resume_sources = resume_sources;
v->irq = irq;
vic_id++;
}
}
static inline void vic_pm_register(void __iomem *base, unsigned int irq, u32 arg1) { }
static void vic_ack_irq(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->irq & 31;
writel(1 << irq, base + VIC_INT_ENABLE_CLEAR);
writel(1 << irq, base + VIC_INT_SOFT_CLEAR);
}
static void vic_mask_irq(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->irq & 31;
writel(1 << irq, base + VIC_INT_ENABLE_CLEAR);
}
static void vic_unmask_irq(struct irq_data *d)
{
void __iomem *base = irq_data_get_irq_chip_data(d);
unsigned int irq = d->irq & 31;
writel(1 << irq, base + VIC_INT_ENABLE);
}
static struct vic_device *vic_from_irq(unsigned int irq)
{
struct vic_device *v = vic_devices;
unsigned int base_irq = irq & ~31;
int id;
for (id = 0; id < vic_id; id++, v++) {
if (v->irq == base_irq)
return v;
}
return NULL;
}
static int vic_set_wake(struct irq_data *d, unsigned int on)
{
struct vic_device *v = vic_from_irq(d->irq);
unsigned int off = d->irq & 31;
u32 bit = 1 << off;
if (!v)
return -EINVAL;
if (!(bit & v->resume_sources))
return -EINVAL;
if (on)
v->resume_irqs |= bit;
else
v->resume_irqs &= ~bit;
return 0;
}
static void __init vic_disable(void __iomem *base)
{
writel(0, base + VIC_INT_SELECT);
writel(0, base + VIC_INT_ENABLE);
writel(~0, base + VIC_INT_ENABLE_CLEAR);
writel(0, base + VIC_IRQ_STATUS);
writel(0, base + VIC_ITCR);
writel(~0, base + VIC_INT_SOFT_CLEAR);
}
static void __init vic_clear_interrupts(void __iomem *base)
{
unsigned int i;
writel(0, base + VIC_PL190_VECT_ADDR);
for (i = 0; i < 19; i++) {
unsigned int value;
value = readl(base + VIC_PL190_VECT_ADDR);
writel(value, base + VIC_PL190_VECT_ADDR);
}
}
static void __init vic_set_irq_sources(void __iomem *base,
unsigned int irq_start, u32 vic_sources)
{
unsigned int i;
for (i = 0; i < 32; i++) {
if (vic_sources & (1 << i)) {
unsigned int irq = irq_start + i;
irq_set_chip_and_handler(irq, &vic_chip,
handle_level_irq);
irq_set_chip_data(irq, base);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
}
}
static void __init vic_init_st(void __iomem *base, unsigned int irq_start,
u32 vic_sources)
{
unsigned int i;
int vic_2nd_block = ((unsigned long)base & ~PAGE_MASK) != 0;
vic_disable(base);
if (vic_2nd_block) {
vic_clear_interrupts(base);
for (i = 0; i < 16; i++) {
void __iomem *reg = base + VIC_VECT_CNTL0 + (i * 4);
writel(0, reg);
}
writel(32, base + VIC_PL190_DEF_VECT_ADDR);
}
vic_set_irq_sources(base, irq_start, vic_sources);
}
void __init vic_init(void __iomem *base, unsigned int irq_start,
u32 vic_sources, u32 resume_sources)
{
unsigned int i;
u32 cellid = 0;
enum amba_vendor vendor;
for (i = 0; i < 4; i++) {
u32 addr = ((u32)base & PAGE_MASK) + 0xfe0 + (i * 4);
cellid |= (readl(addr) & 0xff) << (8 * i);
}
vendor = (cellid >> 12) & 0xff;
printk(KERN_INFO "VIC @%p: id 0x%08x, vendor 0x%02x\n",
base, cellid, vendor);
switch(vendor) {
case AMBA_VENDOR_ST:
vic_init_st(base, irq_start, vic_sources);
return;
default:
printk(KERN_WARNING "VIC: unknown vendor, continuing anyways\n");
case AMBA_VENDOR_ARM:
break;
}
vic_disable(base);
vic_clear_interrupts(base);
vic_init2(base);
vic_set_irq_sources(base, irq_start, vic_sources);
vic_pm_register(base, irq_start, resume_sources);
}
