static inline unsigned int gic_irq(struct irq_data *d)
{
return d->hwirq;
}
static inline int gic_irq_in_rdist(struct irq_data *d)
{
return gic_irq(d) < 32;
}
static inline void __iomem *gic_dist_base(struct irq_data *d)
{
if (gic_irq_in_rdist(d))
return gic_data_rdist_sgi_base();
if (d->hwirq <= 1023)
return gic_data.dist_base;
return NULL;
}
static void gic_do_wait_for_rwp(void __iomem *base)
{
u32 count = 1000000;
while (readl_relaxed(base + GICD_CTLR) & GICD_CTLR_RWP) {
count--;
if (!count) {
pr_err_ratelimited("RWP timeout, gone fishing\n");
return;
}
cpu_relax();
udelay(1);
};
}
static void gic_dist_wait_for_rwp(void)
{
gic_do_wait_for_rwp(gic_data.dist_base);
}
static void gic_redist_wait_for_rwp(void)
{
gic_do_wait_for_rwp(gic_data_rdist_rd_base());
}
static u64 __maybe_unused gic_read_iar(void)
{
u64 irqstat;
asm volatile("mrs_s %0, " __stringify(ICC_IAR1_EL1) : "=r" (irqstat));
return irqstat;
}
static void __maybe_unused gic_write_pmr(u64 val)
{
asm volatile("msr_s " __stringify(ICC_PMR_EL1) ", %0" : : "r" (val));
}
static void __maybe_unused gic_write_ctlr(u64 val)
{
asm volatile("msr_s " __stringify(ICC_CTLR_EL1) ", %0" : : "r" (val));
isb();
}
static void __maybe_unused gic_write_grpen1(u64 val)
{
asm volatile("msr_s " __stringify(ICC_GRPEN1_EL1) ", %0" : : "r" (val));
isb();
}
static void __maybe_unused gic_write_sgi1r(u64 val)
{
asm volatile("msr_s " __stringify(ICC_SGI1R_EL1) ", %0" : : "r" (val));
}
static void gic_enable_sre(void)
{
u64 val;
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
val |= ICC_SRE_EL1_SRE;
asm volatile("msr_s " __stringify(ICC_SRE_EL1) ", %0" : : "r" (val));
isb();
asm volatile("mrs_s %0, " __stringify(ICC_SRE_EL1) : "=r" (val));
if (!(val & ICC_SRE_EL1_SRE))
pr_err("GIC: unable to set SRE (disabled at EL2), panic ahead\n");
}
static void gic_enable_redist(bool enable)
{
void __iomem *rbase;
u32 count = 1000000;
u32 val;
rbase = gic_data_rdist_rd_base();
val = readl_relaxed(rbase + GICR_WAKER);
if (enable)
val &= ~GICR_WAKER_ProcessorSleep;
else
val |= GICR_WAKER_ProcessorSleep;
writel_relaxed(val, rbase + GICR_WAKER);
if (!enable) {
val = readl_relaxed(rbase + GICR_WAKER);
if (!(val & GICR_WAKER_ProcessorSleep))
return;
}
while (count--) {
val = readl_relaxed(rbase + GICR_WAKER);
if (enable ^ (val & GICR_WAKER_ChildrenAsleep))
break;
cpu_relax();
udelay(1);
};
if (!count)
pr_err_ratelimited("redistributor failed to %s...\n",
enable ? "wakeup" : "sleep");
}
static void gic_poke_irq(struct irq_data *d, u32 offset)
{
u32 mask = 1 << (gic_irq(d) % 32);
void (*rwp_wait)(void);
void __iomem *base;
if (gic_irq_in_rdist(d)) {
base = gic_data_rdist_sgi_base();
rwp_wait = gic_redist_wait_for_rwp;
} else {
base = gic_data.dist_base;
rwp_wait = gic_dist_wait_for_rwp;
}
writel_relaxed(mask, base + offset + (gic_irq(d) / 32) * 4);
rwp_wait();
}
static void gic_mask_irq(struct irq_data *d)
{
gic_poke_irq(d, GICD_ICENABLER);
}
static void gic_unmask_irq(struct irq_data *d)
{
gic_poke_irq(d, GICD_ISENABLER);
}
static void gic_eoi_irq(struct irq_data *d)
{
gic_write_eoir(gic_irq(d));
}
static int gic_set_type(struct irq_data *d, unsigned int type)
{
unsigned int irq = gic_irq(d);
void (*rwp_wait)(void);
void __iomem *base;
if (irq < 16)
return -EINVAL;
if (irq >= 32 && type != IRQ_TYPE_LEVEL_HIGH &&
type != IRQ_TYPE_EDGE_RISING)
return -EINVAL;
if (gic_irq_in_rdist(d)) {
base = gic_data_rdist_sgi_base();
rwp_wait = gic_redist_wait_for_rwp;
} else {
base = gic_data.dist_base;
rwp_wait = gic_dist_wait_for_rwp;
}
return gic_configure_irq(irq, type, base, rwp_wait);
}
static u64 gic_mpidr_to_affinity(u64 mpidr)
{
u64 aff;
aff = (MPIDR_AFFINITY_LEVEL(mpidr, 3) << 32 |
MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16 |
MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8 |
MPIDR_AFFINITY_LEVEL(mpidr, 0));
return aff;
}
static asmlinkage void __exception_irq_entry gic_handle_irq(struct pt_regs *regs)
{
u64 irqnr;
do {
irqnr = gic_read_iar();
if (likely(irqnr > 15 && irqnr < 1020) || irqnr >= 8192) {
int err;
err = handle_domain_irq(gic_data.domain, irqnr, regs);
if (err) {
WARN_ONCE(true, "Unexpected interrupt received!\n");
gic_write_eoir(irqnr);
}
continue;
}
if (irqnr < 16) {
gic_write_eoir(irqnr);
#ifdef CONFIG_SMP
handle_IPI(irqnr, regs);
#else
WARN_ONCE(true, "Unexpected SGI received!\n");
#endif
continue;
}
} while (irqnr != ICC_IAR1_EL1_SPURIOUS);
}
static void __init gic_dist_init(void)
{
unsigned int i;
u64 affinity;
void __iomem *base = gic_data.dist_base;
writel_relaxed(0, base + GICD_CTLR);
gic_dist_wait_for_rwp();
gic_dist_config(base, gic_data.irq_nr, gic_dist_wait_for_rwp);
writel_relaxed(GICD_CTLR_ARE_NS | GICD_CTLR_ENABLE_G1A | GICD_CTLR_ENABLE_G1,
base + GICD_CTLR);
affinity = gic_mpidr_to_affinity(cpu_logical_map(smp_processor_id()));
for (i = 32; i < gic_data.irq_nr; i++)
writeq_relaxed(affinity, base + GICD_IROUTER + i * 8);
}
static int gic_populate_rdist(void)
{
u64 mpidr = cpu_logical_map(smp_processor_id());
u64 typer;
u32 aff;
int i;
aff = (MPIDR_AFFINITY_LEVEL(mpidr, 3) << 24 |
MPIDR_AFFINITY_LEVEL(mpidr, 2) << 16 |
MPIDR_AFFINITY_LEVEL(mpidr, 1) << 8 |
MPIDR_AFFINITY_LEVEL(mpidr, 0));
for (i = 0; i < gic_data.nr_redist_regions; i++) {
void __iomem *ptr = gic_data.redist_regions[i].redist_base;
u32 reg;
reg = readl_relaxed(ptr + GICR_PIDR2) & GIC_PIDR2_ARCH_MASK;
if (reg != GIC_PIDR2_ARCH_GICv3 &&
reg != GIC_PIDR2_ARCH_GICv4) {
pr_warn("No redistributor present @%p\n", ptr);
break;
}
do {
typer = readq_relaxed(ptr + GICR_TYPER);
if ((typer >> 32) == aff) {
u64 offset = ptr - gic_data.redist_regions[i].redist_base;
gic_data_rdist_rd_base() = ptr;
gic_data_rdist()->phys_base = gic_data.redist_regions[i].phys_base + offset;
pr_info("CPU%d: found redistributor %llx region %d:%pa\n",
smp_processor_id(),
(unsigned long long)mpidr,
i, &gic_data_rdist()->phys_base);
return 0;
}
if (gic_data.redist_stride) {
ptr += gic_data.redist_stride;
} else {
ptr += SZ_64K * 2;
if (typer & GICR_TYPER_VLPIS)
ptr += SZ_64K * 2;
}
} while (!(typer & GICR_TYPER_LAST));
}
WARN(true, "CPU%d: mpidr %llx has no re-distributor!\n",
smp_processor_id(), (unsigned long long)mpidr);
return -ENODEV;
}
static void gic_cpu_sys_reg_init(void)
{
gic_enable_sre();
gic_write_pmr(DEFAULT_PMR_VALUE);
gic_write_ctlr(ICC_CTLR_EL1_EOImode_drop_dir);
gic_write_grpen1(1);
}
static int gic_dist_supports_lpis(void)
{
return !!(readl_relaxed(gic_data.dist_base + GICD_TYPER) & GICD_TYPER_LPIS);
}
static void gic_cpu_init(void)
{
void __iomem *rbase;
if (gic_populate_rdist())
return;
gic_enable_redist(true);
rbase = gic_data_rdist_sgi_base();
gic_cpu_config(rbase, gic_redist_wait_for_rwp);
if (IS_ENABLED(CONFIG_ARM_GIC_V3_ITS) && gic_dist_supports_lpis())
its_cpu_init();
gic_cpu_sys_reg_init();
}
static int gic_peek_irq(struct irq_data *d, u32 offset)
{
u32 mask = 1 << (gic_irq(d) % 32);
void __iomem *base;
if (gic_irq_in_rdist(d))
base = gic_data_rdist_sgi_base();
else
base = gic_data.dist_base;
return !!(readl_relaxed(base + offset + (gic_irq(d) / 32) * 4) & mask);
}
static int gic_secondary_init(struct notifier_block *nfb,
unsigned long action, void *hcpu)
{
if (action == CPU_STARTING || action == CPU_STARTING_FROZEN)
gic_cpu_init();
return NOTIFY_OK;
}
static u16 gic_compute_target_list(int *base_cpu, const struct cpumask *mask,
u64 cluster_id)
{
int cpu = *base_cpu;
u64 mpidr = cpu_logical_map(cpu);
u16 tlist = 0;
while (cpu < nr_cpu_ids) {
if (WARN_ON((mpidr & 0xff) >= 16))
goto out;
tlist |= 1 << (mpidr & 0xf);
cpu = cpumask_next(cpu, mask);
if (cpu >= nr_cpu_ids)
goto out;
mpidr = cpu_logical_map(cpu);
if (cluster_id != (mpidr & ~0xffUL)) {
cpu--;
goto out;
}
}
out:
*base_cpu = cpu;
return tlist;
}
static void gic_send_sgi(u64 cluster_id, u16 tlist, unsigned int irq)
{
u64 val;
val = (MPIDR_TO_SGI_AFFINITY(cluster_id, 3) |
MPIDR_TO_SGI_AFFINITY(cluster_id, 2) |
irq << ICC_SGI1R_SGI_ID_SHIFT |
MPIDR_TO_SGI_AFFINITY(cluster_id, 1) |
tlist << ICC_SGI1R_TARGET_LIST_SHIFT);
pr_debug("CPU%d: ICC_SGI1R_EL1 %llx\n", smp_processor_id(), val);
gic_write_sgi1r(val);
}
static void gic_raise_softirq(const struct cpumask *mask, unsigned int irq)
{
int cpu;
if (WARN_ON(irq >= 16))
return;
smp_wmb();
for_each_cpu_mask(cpu, *mask) {
u64 cluster_id = cpu_logical_map(cpu) & ~0xffUL;
u16 tlist;
tlist = gic_compute_target_list(&cpu, mask, cluster_id);
gic_send_sgi(cluster_id, tlist, irq);
}
isb();
}
static void gic_smp_init(void)
{
set_smp_cross_call(gic_raise_softirq);
register_cpu_notifier(&gic_cpu_notifier);
}
static int gic_set_affinity(struct irq_data *d, const struct cpumask *mask_val,
bool force)
{
unsigned int cpu = cpumask_any_and(mask_val, cpu_online_mask);
void __iomem *reg;
int enabled;
u64 val;
if (gic_irq_in_rdist(d))
return -EINVAL;
enabled = gic_peek_irq(d, GICD_ISENABLER);
if (enabled)
gic_mask_irq(d);
reg = gic_dist_base(d) + GICD_IROUTER + (gic_irq(d) * 8);
val = gic_mpidr_to_affinity(cpu_logical_map(cpu));
writeq_relaxed(val, reg);
if (enabled)
gic_unmask_irq(d);
else
gic_dist_wait_for_rwp();
return IRQ_SET_MASK_OK;
}
static int gic_cpu_pm_notifier(struct notifier_block *self,
unsigned long cmd, void *v)
{
if (cmd == CPU_PM_EXIT) {
gic_enable_redist(true);
gic_cpu_sys_reg_init();
} else if (cmd == CPU_PM_ENTER) {
gic_write_grpen1(0);
gic_enable_redist(false);
}
return NOTIFY_OK;
}
static void gic_cpu_pm_init(void)
{
cpu_pm_register_notifier(&gic_cpu_pm_notifier_block);
}
static inline void gic_cpu_pm_init(void) { }
static int gic_irq_domain_map(struct irq_domain *d, unsigned int irq,
irq_hw_number_t hw)
{
if (hw < 16)
return -EPERM;
if (hw >= gic_data.irq_nr && hw < 8192)
return -EPERM;
if (hw >= GIC_ID_NR)
return -EPERM;
if (hw < 32) {
irq_set_percpu_devid(irq);
irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
handle_percpu_devid_irq, NULL, NULL);
set_irq_flags(irq, IRQF_VALID | IRQF_NOAUTOEN);
}
if (hw >= 32 && hw < gic_data.irq_nr) {
irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
handle_fasteoi_irq, NULL, NULL);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
if (hw >= 8192 && hw < GIC_ID_NR) {
if (!gic_dist_supports_lpis())
return -EPERM;
irq_domain_set_info(d, irq, hw, &gic_chip, d->host_data,
handle_fasteoi_irq, NULL, NULL);
set_irq_flags(irq, IRQF_VALID);
}
return 0;
}
static int gic_irq_domain_xlate(struct irq_domain *d,
struct device_node *controller,
const u32 *intspec, unsigned int intsize,
unsigned long *out_hwirq, unsigned int *out_type)
{
if (d->of_node != controller)
return -EINVAL;
if (intsize < 3)
return -EINVAL;
switch(intspec[0]) {
case 0:
*out_hwirq = intspec[1] + 32;
break;
case 1:
*out_hwirq = intspec[1] + 16;
break;
case GIC_IRQ_TYPE_LPI:
*out_hwirq = intspec[1];
break;
default:
return -EINVAL;
}
*out_type = intspec[2] & IRQ_TYPE_SENSE_MASK;
return 0;
}
static int gic_irq_domain_alloc(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs, void *arg)
{
int i, ret;
irq_hw_number_t hwirq;
unsigned int type = IRQ_TYPE_NONE;
struct of_phandle_args *irq_data = arg;
ret = gic_irq_domain_xlate(domain, irq_data->np, irq_data->args,
irq_data->args_count, &hwirq, &type);
if (ret)
return ret;
for (i = 0; i < nr_irqs; i++)
gic_irq_domain_map(domain, virq + i, hwirq + i);
return 0;
}
static void gic_irq_domain_free(struct irq_domain *domain, unsigned int virq,
unsigned int nr_irqs)
{
int i;
for (i = 0; i < nr_irqs; i++) {
struct irq_data *d = irq_domain_get_irq_data(domain, virq + i);
irq_set_handler(virq + i, NULL);
irq_domain_reset_irq_data(d);
}
}
static int __init gic_of_init(struct device_node *node, struct device_node *parent)
{
void __iomem *dist_base;
struct redist_region *rdist_regs;
u64 redist_stride;
u32 nr_redist_regions;
u32 typer;
u32 reg;
int gic_irqs;
int err;
int i;
dist_base = of_iomap(node, 0);
if (!dist_base) {
pr_err("%s: unable to map gic dist registers\n",
node->full_name);
return -ENXIO;
}
reg = readl_relaxed(dist_base + GICD_PIDR2) & GIC_PIDR2_ARCH_MASK;
if (reg != GIC_PIDR2_ARCH_GICv3 && reg != GIC_PIDR2_ARCH_GICv4) {
pr_err("%s: no distributor detected, giving up\n",
node->full_name);
err = -ENODEV;
goto out_unmap_dist;
}
if (of_property_read_u32(node, "#redistributor-regions", &nr_redist_regions))
nr_redist_regions = 1;
rdist_regs = kzalloc(sizeof(*rdist_regs) * nr_redist_regions, GFP_KERNEL);
if (!rdist_regs) {
err = -ENOMEM;
goto out_unmap_dist;
}
for (i = 0; i < nr_redist_regions; i++) {
struct resource res;
int ret;
ret = of_address_to_resource(node, 1 + i, &res);
rdist_regs[i].redist_base = of_iomap(node, 1 + i);
if (ret || !rdist_regs[i].redist_base) {
pr_err("%s: couldn't map region %d\n",
node->full_name, i);
err = -ENODEV;
goto out_unmap_rdist;
}
rdist_regs[i].phys_base = res.start;
}
if (of_property_read_u64(node, "redistributor-stride", &redist_stride))
redist_stride = 0;
gic_data.dist_base = dist_base;
gic_data.redist_regions = rdist_regs;
gic_data.nr_redist_regions = nr_redist_regions;
gic_data.redist_stride = redist_stride;
typer = readl_relaxed(gic_data.dist_base + GICD_TYPER);
gic_data.rdists.id_bits = GICD_TYPER_ID_BITS(typer);
gic_irqs = GICD_TYPER_IRQS(typer);
if (gic_irqs > 1020)
gic_irqs = 1020;
gic_data.irq_nr = gic_irqs;
gic_data.domain = irq_domain_add_tree(node, &gic_irq_domain_ops,
&gic_data);
gic_data.rdists.rdist = alloc_percpu(typeof(*gic_data.rdists.rdist));
if (WARN_ON(!gic_data.domain) || WARN_ON(!gic_data.rdists.rdist)) {
err = -ENOMEM;
goto out_free;
}
set_handle_irq(gic_handle_irq);
if (IS_ENABLED(CONFIG_ARM_GIC_V3_ITS) && gic_dist_supports_lpis())
its_init(node, &gic_data.rdists, gic_data.domain);
gic_smp_init();
gic_dist_init();
gic_cpu_init();
gic_cpu_pm_init();
return 0;
out_free:
if (gic_data.domain)
irq_domain_remove(gic_data.domain);
free_percpu(gic_data.rdists.rdist);
out_unmap_rdist:
for (i = 0; i < nr_redist_regions; i++)
if (rdist_regs[i].redist_base)
iounmap(rdist_regs[i].redist_base);
kfree(rdist_regs);
out_unmap_dist:
iounmap(dist_base);
return err;
}
