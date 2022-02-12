static inline void __iomem *gic_dist_base(struct irq_data *d)
{
struct gic_chip_data *gic_data = irq_data_get_irq_chip_data(d);
return gic_data->dist_base;
}
static inline void __iomem *gic_cpu_base(struct irq_data *d)
{
struct gic_chip_data *gic_data = irq_data_get_irq_chip_data(d);
return gic_data->cpu_base;
}
static inline unsigned int gic_irq(struct irq_data *d)
{
struct gic_chip_data *gic_data = irq_data_get_irq_chip_data(d);
return d->irq - gic_data->irq_offset;
}
static void gic_mask_irq(struct irq_data *d)
{
u32 mask = 1 << (d->irq % 32);
spin_lock(&irq_controller_lock);
writel_relaxed(mask, gic_dist_base(d) + GIC_DIST_ENABLE_CLEAR + (gic_irq(d) / 32) * 4);
if (gic_arch_extn.irq_mask)
gic_arch_extn.irq_mask(d);
spin_unlock(&irq_controller_lock);
}
static void gic_unmask_irq(struct irq_data *d)
{
u32 mask = 1 << (d->irq % 32);
spin_lock(&irq_controller_lock);
if (gic_arch_extn.irq_unmask)
gic_arch_extn.irq_unmask(d);
writel_relaxed(mask, gic_dist_base(d) + GIC_DIST_ENABLE_SET + (gic_irq(d) / 32) * 4);
spin_unlock(&irq_controller_lock);
}
static void gic_eoi_irq(struct irq_data *d)
{
if (gic_arch_extn.irq_eoi) {
spin_lock(&irq_controller_lock);
gic_arch_extn.irq_eoi(d);
spin_unlock(&irq_controller_lock);
}
writel_relaxed(gic_irq(d), gic_cpu_base(d) + GIC_CPU_EOI);
}
static int gic_set_type(struct irq_data *d, unsigned int type)
{
void __iomem *base = gic_dist_base(d);
unsigned int gicirq = gic_irq(d);
u32 enablemask = 1 << (gicirq % 32);
u32 enableoff = (gicirq / 32) * 4;
u32 confmask = 0x2 << ((gicirq % 16) * 2);
u32 confoff = (gicirq / 16) * 4;
bool enabled = false;
u32 val;
if (gicirq < 16)
return -EINVAL;
if (type != IRQ_TYPE_LEVEL_HIGH && type != IRQ_TYPE_EDGE_RISING)
return -EINVAL;
spin_lock(&irq_controller_lock);
if (gic_arch_extn.irq_set_type)
gic_arch_extn.irq_set_type(d, type);
val = readl_relaxed(base + GIC_DIST_CONFIG + confoff);
if (type == IRQ_TYPE_LEVEL_HIGH)
val &= ~confmask;
else if (type == IRQ_TYPE_EDGE_RISING)
val |= confmask;
if (readl_relaxed(base + GIC_DIST_ENABLE_SET + enableoff) & enablemask) {
writel_relaxed(enablemask, base + GIC_DIST_ENABLE_CLEAR + enableoff);
enabled = true;
}
writel_relaxed(val, base + GIC_DIST_CONFIG + confoff);
if (enabled)
writel_relaxed(enablemask, base + GIC_DIST_ENABLE_SET + enableoff);
spin_unlock(&irq_controller_lock);
return 0;
}
static int gic_retrigger(struct irq_data *d)
{
if (gic_arch_extn.irq_retrigger)
return gic_arch_extn.irq_retrigger(d);
return -ENXIO;
}
static int gic_set_affinity(struct irq_data *d, const struct cpumask *mask_val,
bool force)
{
void __iomem *reg = gic_dist_base(d) + GIC_DIST_TARGET + (gic_irq(d) & ~3);
unsigned int shift = (d->irq % 4) * 8;
unsigned int cpu = cpumask_any_and(mask_val, cpu_online_mask);
u32 val, mask, bit;
if (cpu >= 8 || cpu >= nr_cpu_ids)
return -EINVAL;
mask = 0xff << shift;
bit = 1 << (cpu + shift);
spin_lock(&irq_controller_lock);
val = readl_relaxed(reg) & ~mask;
writel_relaxed(val | bit, reg);
spin_unlock(&irq_controller_lock);
return IRQ_SET_MASK_OK;
}
static int gic_set_wake(struct irq_data *d, unsigned int on)
{
int ret = -ENXIO;
if (gic_arch_extn.irq_set_wake)
ret = gic_arch_extn.irq_set_wake(d, on);
return ret;
}
static void gic_handle_cascade_irq(unsigned int irq, struct irq_desc *desc)
{
struct gic_chip_data *chip_data = irq_get_handler_data(irq);
struct irq_chip *chip = irq_get_chip(irq);
unsigned int cascade_irq, gic_irq;
unsigned long status;
chained_irq_enter(chip, desc);
spin_lock(&irq_controller_lock);
status = readl_relaxed(chip_data->cpu_base + GIC_CPU_INTACK);
spin_unlock(&irq_controller_lock);
gic_irq = (status & 0x3ff);
if (gic_irq == 1023)
goto out;
cascade_irq = gic_irq + chip_data->irq_offset;
if (unlikely(gic_irq < 32 || gic_irq > 1020 || cascade_irq >= NR_IRQS))
do_bad_IRQ(cascade_irq, desc);
else
generic_handle_irq(cascade_irq);
out:
chained_irq_exit(chip, desc);
}
void __init gic_cascade_irq(unsigned int gic_nr, unsigned int irq)
{
if (gic_nr >= MAX_GIC_NR)
BUG();
if (irq_set_handler_data(irq, &gic_data[gic_nr]) != 0)
BUG();
irq_set_chained_handler(irq, gic_handle_cascade_irq);
}
static void __init gic_dist_init(struct gic_chip_data *gic,
unsigned int irq_start)
{
unsigned int gic_irqs, irq_limit, i;
void __iomem *base = gic->dist_base;
u32 cpumask = 1 << smp_processor_id();
cpumask |= cpumask << 8;
cpumask |= cpumask << 16;
writel_relaxed(0, base + GIC_DIST_CTRL);
gic_irqs = readl_relaxed(base + GIC_DIST_CTR) & 0x1f;
gic_irqs = (gic_irqs + 1) * 32;
if (gic_irqs > 1020)
gic_irqs = 1020;
for (i = 32; i < gic_irqs; i += 16)
writel_relaxed(0, base + GIC_DIST_CONFIG + i * 4 / 16);
for (i = 32; i < gic_irqs; i += 4)
writel_relaxed(cpumask, base + GIC_DIST_TARGET + i * 4 / 4);
for (i = 32; i < gic_irqs; i += 4)
writel_relaxed(0xa0a0a0a0, base + GIC_DIST_PRI + i * 4 / 4);
for (i = 32; i < gic_irqs; i += 32)
writel_relaxed(0xffffffff, base + GIC_DIST_ENABLE_CLEAR + i * 4 / 32);
irq_limit = gic->irq_offset + gic_irqs;
if (WARN_ON(irq_limit > NR_IRQS))
irq_limit = NR_IRQS;
for (i = irq_start; i < irq_limit; i++) {
irq_set_chip_and_handler(i, &gic_chip, handle_fasteoi_irq);
irq_set_chip_data(i, gic);
set_irq_flags(i, IRQF_VALID | IRQF_PROBE);
}
writel_relaxed(1, base + GIC_DIST_CTRL);
}
static void __cpuinit gic_cpu_init(struct gic_chip_data *gic)
{
void __iomem *dist_base = gic->dist_base;
void __iomem *base = gic->cpu_base;
int i;
writel_relaxed(0xffff0000, dist_base + GIC_DIST_ENABLE_CLEAR);
writel_relaxed(0x0000ffff, dist_base + GIC_DIST_ENABLE_SET);
for (i = 0; i < 32; i += 4)
writel_relaxed(0xa0a0a0a0, dist_base + GIC_DIST_PRI + i * 4 / 4);
writel_relaxed(0xf0, base + GIC_CPU_PRIMASK);
writel_relaxed(1, base + GIC_CPU_CTRL);
}
void __init gic_init(unsigned int gic_nr, unsigned int irq_start,
void __iomem *dist_base, void __iomem *cpu_base)
{
struct gic_chip_data *gic;
BUG_ON(gic_nr >= MAX_GIC_NR);
gic = &gic_data[gic_nr];
gic->dist_base = dist_base;
gic->cpu_base = cpu_base;
gic->irq_offset = (irq_start - 1) & ~31;
if (gic_nr == 0)
gic_cpu_base_addr = cpu_base;
gic_dist_init(gic, irq_start);
gic_cpu_init(gic);
}
void __cpuinit gic_secondary_init(unsigned int gic_nr)
{
BUG_ON(gic_nr >= MAX_GIC_NR);
gic_cpu_init(&gic_data[gic_nr]);
}
void __cpuinit gic_enable_ppi(unsigned int irq)
{
unsigned long flags;
local_irq_save(flags);
irq_set_status_flags(irq, IRQ_NOPROBE);
gic_unmask_irq(irq_get_irq_data(irq));
local_irq_restore(flags);
}
void gic_raise_softirq(const struct cpumask *mask, unsigned int irq)
{
unsigned long map = *cpus_addr(*mask);
dsb();
writel_relaxed(map << 16 | irq, gic_data[0].dist_base + GIC_DIST_SOFTINT);
}
