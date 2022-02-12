void gic_configure_irq(unsigned int irq, unsigned int type,
void __iomem *base, void (*sync_access)(void))
{
u32 enablemask = 1 << (irq % 32);
u32 enableoff = (irq / 32) * 4;
u32 confmask = 0x2 << ((irq % 16) * 2);
u32 confoff = (irq / 16) * 4;
bool enabled = false;
u32 val;
val = readl_relaxed(base + GIC_DIST_CONFIG + confoff);
if (type == IRQ_TYPE_LEVEL_HIGH)
val &= ~confmask;
else if (type == IRQ_TYPE_EDGE_RISING)
val |= confmask;
if (readl_relaxed(base + GIC_DIST_ENABLE_SET + enableoff) & enablemask) {
writel_relaxed(enablemask, base + GIC_DIST_ENABLE_CLEAR + enableoff);
if (sync_access)
sync_access();
enabled = true;
}
writel_relaxed(val, base + GIC_DIST_CONFIG + confoff);
if (enabled)
writel_relaxed(enablemask, base + GIC_DIST_ENABLE_SET + enableoff);
if (sync_access)
sync_access();
}
void __init gic_dist_config(void __iomem *base, int gic_irqs,
void (*sync_access)(void))
{
unsigned int i;
for (i = 32; i < gic_irqs; i += 16)
writel_relaxed(0, base + GIC_DIST_CONFIG + i / 4);
for (i = 32; i < gic_irqs; i += 4)
writel_relaxed(0xa0a0a0a0, base + GIC_DIST_PRI + i);
for (i = 32; i < gic_irqs; i += 32)
writel_relaxed(0xffffffff, base + GIC_DIST_ENABLE_CLEAR + i / 8);
if (sync_access)
sync_access();
}
void gic_cpu_config(void __iomem *base, void (*sync_access)(void))
{
int i;
writel_relaxed(0xffff0000, base + GIC_DIST_ENABLE_CLEAR);
writel_relaxed(0x0000ffff, base + GIC_DIST_ENABLE_SET);
for (i = 0; i < 32; i += 4)
writel_relaxed(0xa0a0a0a0, base + GIC_DIST_PRI + i * 4 / 4);
if (sync_access)
sync_access();
}
