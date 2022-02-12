const struct gic_kvm_info *gic_get_kvm_info(void)
{
return gic_kvm_info;
}
void gic_set_kvm_info(const struct gic_kvm_info *info)
{
BUG_ON(gic_kvm_info != NULL);
gic_kvm_info = info;
}
void gic_enable_quirks(u32 iidr, const struct gic_quirk *quirks,
void *data)
{
for (; quirks->desc; quirks++) {
if (quirks->iidr != (quirks->mask & iidr))
continue;
quirks->init(data);
pr_info("GIC: enabling workaround for %s\n", quirks->desc);
}
}
int gic_configure_irq(unsigned int irq, unsigned int type,
void __iomem *base, void (*sync_access)(void))
{
u32 confmask = 0x2 << ((irq % 16) * 2);
u32 confoff = (irq / 16) * 4;
u32 val, oldval;
int ret = 0;
val = oldval = readl_relaxed(base + GIC_DIST_CONFIG + confoff);
if (type & IRQ_TYPE_LEVEL_MASK)
val &= ~confmask;
else if (type & IRQ_TYPE_EDGE_BOTH)
val |= confmask;
if (val == oldval)
return 0;
writel_relaxed(val, base + GIC_DIST_CONFIG + confoff);
if (readl_relaxed(base + GIC_DIST_CONFIG + confoff) != val) {
if (WARN_ON(irq >= 32))
ret = -EINVAL;
else
pr_warn("GIC: PPI%d is secure or misconfigured\n",
irq - 16);
}
if (sync_access)
sync_access();
return ret;
}
void __init gic_dist_config(void __iomem *base, int gic_irqs,
void (*sync_access)(void))
{
unsigned int i;
for (i = 32; i < gic_irqs; i += 16)
writel_relaxed(GICD_INT_ACTLOW_LVLTRIG,
base + GIC_DIST_CONFIG + i / 4);
for (i = 32; i < gic_irqs; i += 4)
writel_relaxed(GICD_INT_DEF_PRI_X4, base + GIC_DIST_PRI + i);
for (i = 32; i < gic_irqs; i += 32) {
writel_relaxed(GICD_INT_EN_CLR_X32,
base + GIC_DIST_ACTIVE_CLEAR + i / 8);
writel_relaxed(GICD_INT_EN_CLR_X32,
base + GIC_DIST_ENABLE_CLEAR + i / 8);
}
if (sync_access)
sync_access();
}
void gic_cpu_config(void __iomem *base, void (*sync_access)(void))
{
int i;
writel_relaxed(GICD_INT_EN_CLR_X32, base + GIC_DIST_ACTIVE_CLEAR);
writel_relaxed(GICD_INT_EN_CLR_PPI, base + GIC_DIST_ENABLE_CLEAR);
writel_relaxed(GICD_INT_EN_SET_SGI, base + GIC_DIST_ENABLE_SET);
for (i = 0; i < 32; i += 4)
writel_relaxed(GICD_INT_DEF_PRI_X4,
base + GIC_DIST_PRI + i * 4 / 4);
if (sync_access)
sync_access();
}
