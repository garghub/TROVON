static inline u32 wakeupgen_readl(u8 idx, u32 cpu)
{
return __raw_readl(wakeupgen_base + OMAP_WKG_ENB_A_0 +
(cpu * CPU_ENA_OFFSET) + (idx * 4));
}
static inline void wakeupgen_writel(u32 val, u8 idx, u32 cpu)
{
__raw_writel(val, wakeupgen_base + OMAP_WKG_ENB_A_0 +
(cpu * CPU_ENA_OFFSET) + (idx * 4));
}
static inline void sar_writel(u32 val, u32 offset, u8 idx)
{
__raw_writel(val, sar_base + offset + (idx * 4));
}
static inline int _wakeupgen_get_irq_info(u32 irq, u32 *bit_posn, u8 *reg_index)
{
unsigned int spi_irq;
if (irq < OMAP44XX_IRQ_GIC_START)
return -EINVAL;
spi_irq = irq - OMAP44XX_IRQ_GIC_START;
if (spi_irq > MAX_IRQS) {
pr_err("omap wakeupGen: Invalid IRQ%d\n", irq);
return -EINVAL;
}
*reg_index = spi_irq >> 5;
*bit_posn = spi_irq %= 32;
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
spin_lock_irqsave(&wakeupgen_lock, flags);
_wakeupgen_clear(d->irq, irq_target_cpu[d->irq]);
spin_unlock_irqrestore(&wakeupgen_lock, flags);
}
static void wakeupgen_unmask(struct irq_data *d)
{
unsigned long flags;
spin_lock_irqsave(&wakeupgen_lock, flags);
_wakeupgen_set(d->irq, irq_target_cpu[d->irq]);
spin_unlock_irqrestore(&wakeupgen_lock, flags);
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
spin_lock_irqsave(&wakeupgen_lock, flags);
if (set) {
_wakeupgen_save_masks(cpu);
_wakeupgen_set_all(cpu, WKG_MASK_ALL);
} else {
_wakeupgen_set_all(cpu, WKG_UNMASK_ALL);
_wakeupgen_restore_masks(cpu);
}
spin_unlock_irqrestore(&wakeupgen_lock, flags);
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
val = __raw_readl(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
__raw_writel(val, sar_base + AUXCOREBOOT0_OFFSET);
val = __raw_readl(wakeupgen_base + OMAP_AUX_CORE_BOOT_1);
__raw_writel(val, sar_base + AUXCOREBOOT1_OFFSET);
val = __raw_readl(wakeupgen_base + OMAP_PTMSYNCREQ_MASK);
__raw_writel(val, sar_base + PTMSYNCREQ_MASK_OFFSET);
val = __raw_readl(wakeupgen_base + OMAP_PTMSYNCREQ_EN);
__raw_writel(val, sar_base + PTMSYNCREQ_EN_OFFSET);
val = __raw_readl(sar_base + SAR_BACKUP_STATUS_OFFSET);
val |= SAR_BACKUP_STATUS_WAKEUPGEN;
__raw_writel(val, sar_base + SAR_BACKUP_STATUS_OFFSET);
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
val = __raw_readl(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
__raw_writel(val, sar_base + OMAP5_AUXCOREBOOT0_OFFSET);
val = __raw_readl(wakeupgen_base + OMAP_AUX_CORE_BOOT_0);
__raw_writel(val, sar_base + OMAP5_AUXCOREBOOT1_OFFSET);
val = __raw_readl(sar_base + OMAP5_SAR_BACKUP_STATUS_OFFSET);
val |= SAR_BACKUP_STATUS_WAKEUPGEN;
__raw_writel(val, sar_base + OMAP5_SAR_BACKUP_STATUS_OFFSET);
}
static void irq_save_context(void)
{
if (!sar_base)
sar_base = omap4_get_sar_ram_base();
if (soc_is_omap54xx())
omap5_irq_save_context();
else
omap4_irq_save_context();
}
static void irq_sar_clear(void)
{
u32 val;
u32 offset = SAR_BACKUP_STATUS_OFFSET;
if (soc_is_omap54xx())
offset = OMAP5_SAR_BACKUP_STATUS_OFFSET;
val = __raw_readl(sar_base + offset);
val &= ~SAR_BACKUP_STATUS_WAKEUPGEN;
__raw_writel(val, sar_base + offset);
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
static int __cpuinit irq_cpu_hotplug_notify(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (unsigned int)hcpu;
switch (action) {
case CPU_ONLINE:
wakeupgen_irqmask_all(cpu, 0);
break;
case CPU_DEAD:
wakeupgen_irqmask_all(cpu, 1);
break;
}
return NOTIFY_OK;
}
static void __init irq_hotplug_init(void)
{
register_hotcpu_notifier(&irq_hotplug_notifier);
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
irq_sar_clear();
break;
}
return NOTIFY_OK;
}
static void __init irq_pm_init(void)
{
if (!soc_is_omap54xx())
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
int __init omap_wakeupgen_init(void)
{
int i;
unsigned int boot_cpu = smp_processor_id();
if (omap_rev() == OMAP4430_REV_ES1_0) {
WARN(1, "WakeupGen: Not supported on OMAP4430 ES1.0\n");
return -EPERM;
}
wakeupgen_base = ioremap(OMAP_WKUPGEN_BASE, SZ_4K);
if (WARN_ON(!wakeupgen_base))
return -ENOMEM;
if (cpu_is_omap44xx()) {
irq_banks = OMAP4_NR_BANKS;
max_irqs = OMAP4_NR_IRQS;
omap_secure_apis = 1;
}
for (i = 0; i < irq_banks; i++) {
wakeupgen_writel(0, i, CPU0_ID);
wakeupgen_writel(0, i, CPU1_ID);
}
gic_arch_extn.irq_mask = wakeupgen_mask;
gic_arch_extn.irq_unmask = wakeupgen_unmask;
gic_arch_extn.flags = IRQCHIP_MASK_ON_SUSPEND | IRQCHIP_SKIP_SET_WAKE;
for (i = 0; i < max_irqs; i++)
irq_target_cpu[i] = boot_cpu;
irq_hotplug_init();
irq_pm_init();
return 0;
}
