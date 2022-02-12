static inline u32 wakeupgen_readl(u8 idx, u32 cpu)
{
return readl_relaxed(wakeupgen_base + OMAP_WKG_ENB_A_0 +
(cpu * CPU_ENA_OFFSET) + (idx * 4));
}
static inline void wakeupgen_writel(u32 val, u8 idx, u32 cpu)
{
writel_relaxed(val, wakeupgen_base + OMAP_WKG_ENB_A_0 +
(cpu * CPU_ENA_OFFSET) + (idx * 4));
}
static inline void sar_writel(u32 val, u32 offset, u8 idx)
{
writel_relaxed(val, sar_base + offset + (idx * 4));
}
static inline int _wakeupgen_get_irq_info(u32 irq, u32 *bit_posn, u8 *reg_index)
{
*reg_index = irq >> 5;
*bit_posn = irq %= 32;
return 0;
}
static void _wakeupgen_clear(unsigned int irq, unsigned int cpu)
{
u32 val, bit_number;
u8 i;
if (_wakeupgen_get_irq_info(irq, &bit_number, &i))
return;
val = wakeupgen_readl(i, cpu);
val &= ~BIT(bit_number);
wakeupgen_writel(val, i, cpu);
}
static void _wakeupgen_set(unsigned int irq, unsigned int cpu)
{
u32 val, bit_number;
u8 i;
if (_wakeupgen_get_irq_info(irq, &bit_number, &i))
return;
val = wakeupgen_readl(i, cpu);
val |= BIT(bit_number);
wakeupgen_writel(val, i, cpu);
}
static void wakeupgen_mask(struct irq_data *d)
{
unsigned long flags;
raw_spin_lock_irqsave(&wakeupgen_lock, flags);
_wakeupgen_clear(d->hwirq, irq_target_cpu[d->hwirq]);
raw_spin_unlock_irqrestore(&wakeupgen_lock, flags);
irq_chip_mask_parent(d);
}
static void wakeupgen_unmask(struct irq_data *d)
{
unsigned long flags;
raw_spin_lock_irqsave(&wakeupgen_lock, flags);
_wakeupgen_set(d->hwirq, irq_target_cpu[d->hwirq]);
raw_spin_unlock_irqrestore(&wakeupgen_lock, flags);
irq_chip_unmask_parent(d);
}
static void _wakeupgen_save_masks(unsigned int cpu)
{
u8 i;
for (i = 0; i < irq_banks; i++)
per_cpu(irqmasks, cpu)[i] = wakeupgen_readl(i, cpu);
}
static void _wakeupgen_restore_masks(unsigned int cpu)
{
u8 i;
for (i = 0; i < irq_banks; i++)
wakeupgen_writel(per_cpu(irqmasks, cpu)[i], i, cpu);
}
static void _wakeupgen_set_all(unsigned int cpu, unsigned int reg)
{
u8 i;
for (i = 0; i < irq_banks; i++)
wakeupgen_writel(reg, i, cpu);
}
static void wakeupgen_irqmask_all(unsigned int cpu, unsigned int set)
{
unsigned long flags;
raw_spin_lock_irqsave(&wakeupgen_lock, flags);
if (set) {
_wakeupgen_save_masks(cpu);
_wakeupgen_set_all(cpu, WKG_MASK_ALL);
} else {
_wakeupgen_set_all(cpu, WKG_UNMASK_ALL);
_wakeupgen_restore_masks(cpu);
}
raw_spin_unlock_irqrestore(&wakeupgen_lock, flags);
}
static inline void omap4_irq_save_context(void)
{
u32 i, val;
if (omap_rev() == OMAP4430_REV_ES1_0)
return;
for (i = 0; i < irq_banks; i++) {
val = wakeupgen_readl(i, 0);
sar_writel(val, WAKEUPGENENB_OFFSET_CPU0, i);
val = wakeupgen_readl(i, 1);
sar_writel(val, WAKEUPGENENB_OFFSET_CPU1, i);
sar_writel(0x0, WAKEUPGENENB_SECURE_OFFSET_CPU0, i);
sar_writel(0x0, WAKEUPGENENB_SECURE_OFFSET_CPU1, i);
}
val = readl_relaxed(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
writel_relaxed(val, sar_base + AUXCOREBOOT0_OFFSET);
val = readl_relaxed(wakeupgen_base + OMAP_AUX_CORE_BOOT_1);
writel_relaxed(val, sar_base + AUXCOREBOOT1_OFFSET);
val = readl_relaxed(wakeupgen_base + OMAP_PTMSYNCREQ_MASK);
writel_relaxed(val, sar_base + PTMSYNCREQ_MASK_OFFSET);
val = readl_relaxed(wakeupgen_base + OMAP_PTMSYNCREQ_EN);
writel_relaxed(val, sar_base + PTMSYNCREQ_EN_OFFSET);
val = readl_relaxed(sar_base + SAR_BACKUP_STATUS_OFFSET);
val |= SAR_BACKUP_STATUS_WAKEUPGEN;
writel_relaxed(val, sar_base + SAR_BACKUP_STATUS_OFFSET);
}
static inline void omap5_irq_save_context(void)
{
u32 i, val;
for (i = 0; i < irq_banks; i++) {
val = wakeupgen_readl(i, 0);
sar_writel(val, OMAP5_WAKEUPGENENB_OFFSET_CPU0, i);
val = wakeupgen_readl(i, 1);
sar_writel(val, OMAP5_WAKEUPGENENB_OFFSET_CPU1, i);
sar_writel(0x0, OMAP5_WAKEUPGENENB_SECURE_OFFSET_CPU0, i);
sar_writel(0x0, OMAP5_WAKEUPGENENB_SECURE_OFFSET_CPU1, i);
}
val = readl_relaxed(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
writel_relaxed(val, sar_base + OMAP5_AUXCOREBOOT0_OFFSET);
val = readl_relaxed(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
writel_relaxed(val, sar_base + OMAP5_AUXCOREBOOT1_OFFSET);
val = readl_relaxed(sar_base + OMAP5_SAR_BACKUP_STATUS_OFFSET);
val |= SAR_BACKUP_STATUS_WAKEUPGEN;
writel_relaxed(val, sar_base + OMAP5_SAR_BACKUP_STATUS_OFFSET);
}
static inline void am43xx_irq_save_context(void)
{
u32 i;
for (i = 0; i < irq_banks; i++) {
wakeupgen_context[i] = wakeupgen_readl(i, 0);
wakeupgen_writel(0, i, CPU0_ID);
}
}
static void irq_save_context(void)
{
if (soc_is_dra7xx())
return;
if (!sar_base)
sar_base = omap4_get_sar_ram_base();
if (wakeupgen_ops && wakeupgen_ops->save_context)
wakeupgen_ops->save_context();
}
static void irq_sar_clear(void)
{
u32 val;
u32 offset = SAR_BACKUP_STATUS_OFFSET;
if (soc_is_dra7xx())
return;
if (soc_is_omap54xx())
offset = OMAP5_SAR_BACKUP_STATUS_OFFSET;
val = readl_relaxed(sar_base + offset);
val &= ~SAR_BACKUP_STATUS_WAKEUPGEN;
writel_relaxed(val, sar_base + offset);
}
static void am43xx_irq_restore_context(void)
{
u32 i;
for (i = 0; i < irq_banks; i++)
wakeupgen_writel(wakeupgen_context[i], i, CPU0_ID);
}
static void irq_restore_context(void)
{
if (wakeupgen_ops && wakeupgen_ops->restore_context)
wakeupgen_ops->restore_context();
}
static void irq_save_secure_context(void)
{
u32 ret;
ret = omap_secure_dispatcher(OMAP4_HAL_SAVEGIC_INDEX,
FLAG_START_CRITICAL,
0, 0, 0, 0, 0);
if (ret != API_HAL_RET_VALUE_OK)
pr_err("GIC and Wakeupgen context save failed\n");
}
static int omap_wakeupgen_cpu_online(unsigned int cpu)
{
wakeupgen_irqmask_all(cpu, 0);
return 0;
}
static int omap_wakeupgen_cpu_dead(unsigned int cpu)
{
wakeupgen_irqmask_all(cpu, 1);
return 0;
}
static void __init irq_hotplug_init(void)
{
cpuhp_setup_state_nocalls(CPUHP_AP_ONLINE_DYN, "arm/omap-wake:online",
omap_wakeupgen_cpu_online, NULL);
cpuhp_setup_state_nocalls(CPUHP_ARM_OMAP_WAKE_DEAD,
"arm/omap-wake:dead", NULL,
omap_wakeupgen_cpu_dead);
}
static void __init irq_hotplug_init(void)
{}
static int irq_notifier(struct notifier_block *self, unsigned long cmd, void *v)
{
switch (cmd) {
case CPU_CLUSTER_PM_ENTER:
if (omap_type() == OMAP2_DEVICE_TYPE_GP)
irq_save_context();
else
irq_save_secure_context();
break;
case CPU_CLUSTER_PM_EXIT:
if (omap_type() == OMAP2_DEVICE_TYPE_GP)
irq_restore_context();
break;
}
return NOTIFY_OK;
}
static void __init irq_pm_init(void)
{
if (!IS_PM44XX_ERRATUM(PM_OMAP4_CPU_OSWR_DISABLE))
cpu_pm_register_notifier(&irq_notifier_block);
}
static void __init irq_pm_init(void)
{}
void __iomem *omap_get_wakeupgen_base(void)
{
return wakeupgen_base;
}
int omap_secure_apis_support(void)
{
return omap_secure_apis;
}
static int wakeupgen_domain_translate(struct irq_domain *d,
struct irq_fwspec *fwspec,
unsigned long *hwirq,
unsigned int *type)
{
if (is_of_node(fwspec->fwnode)) {
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0] != 0)
return -EINVAL;
*hwirq = fwspec->param[1];
*type = fwspec->param[2];
return 0;
}
return -EINVAL;
}
static int wakeupgen_domain_alloc(struct irq_domain *domain,
unsigned int virq,
unsigned int nr_irqs, void *data)
{
struct irq_fwspec *fwspec = data;
struct irq_fwspec parent_fwspec;
irq_hw_number_t hwirq;
int i;
if (fwspec->param_count != 3)
return -EINVAL;
if (fwspec->param[0] != 0)
return -EINVAL;
hwirq = fwspec->param[1];
if (hwirq >= MAX_IRQS)
return -EINVAL;
for (i = 0; i < nr_irqs; i++)
irq_domain_set_hwirq_and_chip(domain, virq + i, hwirq + i,
&wakeupgen_chip, NULL);
parent_fwspec = *fwspec;
parent_fwspec.fwnode = domain->parent->fwnode;
return irq_domain_alloc_irqs_parent(domain, virq, nr_irqs,
&parent_fwspec);
}
static int __init wakeupgen_init(struct device_node *node,
struct device_node *parent)
{
struct irq_domain *parent_domain, *domain;
int i;
unsigned int boot_cpu = smp_processor_id();
u32 val;
if (!parent) {
pr_err("%pOF: no parent, giving up\n", node);
return -ENODEV;
}
parent_domain = irq_find_host(parent);
if (!parent_domain) {
pr_err("%pOF: unable to obtain parent domain\n", node);
return -ENXIO;
}
if (omap_rev() == OMAP4430_REV_ES1_0) {
WARN(1, "WakeupGen: Not supported on OMAP4430 ES1.0\n");
return -EPERM;
}
wakeupgen_base = of_iomap(node, 0);
if (WARN_ON(!wakeupgen_base))
return -ENOMEM;
if (cpu_is_omap44xx()) {
irq_banks = OMAP4_NR_BANKS;
max_irqs = OMAP4_NR_IRQS;
omap_secure_apis = 1;
wakeupgen_ops = &omap4_wakeupgen_ops;
} else if (soc_is_omap54xx()) {
wakeupgen_ops = &omap5_wakeupgen_ops;
} else if (soc_is_am43xx()) {
irq_banks = AM43XX_NR_REG_BANKS;
max_irqs = AM43XX_IRQS;
wakeupgen_ops = &am43xx_wakeupgen_ops;
}
domain = irq_domain_add_hierarchy(parent_domain, 0, max_irqs,
node, &wakeupgen_domain_ops,
NULL);
if (!domain) {
iounmap(wakeupgen_base);
return -ENOMEM;
}
for (i = 0; i < irq_banks; i++) {
wakeupgen_writel(0, i, CPU0_ID);
if (!soc_is_am43xx())
wakeupgen_writel(0, i, CPU1_ID);
}
for (i = 0; i < max_irqs; i++)
irq_target_cpu[i] = boot_cpu;
if (soc_is_omap54xx() || soc_is_dra7xx()) {
val = __raw_readl(wakeupgen_base + OMAP_AMBA_IF_MODE);
val |= BIT(5);
omap_smc1(OMAP5_MON_AMBA_IF_INDEX, val);
}
irq_hotplug_init();
irq_pm_init();
return 0;
}
