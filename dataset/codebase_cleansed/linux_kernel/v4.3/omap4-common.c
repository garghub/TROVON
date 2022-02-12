static void omap4_mb(void)
{
if (dram_sync)
writel_relaxed(0, dram_sync);
}
void omap_interconnect_sync(void)
{
if (dram_sync && sram_sync) {
writel_relaxed(readl_relaxed(dram_sync), dram_sync);
writel_relaxed(readl_relaxed(sram_sync), sram_sync);
isb();
}
}
static int __init omap4_sram_init(void)
{
struct device_node *np;
struct gen_pool *sram_pool;
np = of_find_compatible_node(NULL, NULL, "ti,omap4-mpu");
if (!np)
pr_warn("%s:Unable to allocate sram needed to handle errata I688\n",
__func__);
sram_pool = of_gen_pool_get(np, "sram", 0);
if (!sram_pool)
pr_warn("%s:Unable to get sram pool needed to handle errata I688\n",
__func__);
else
sram_sync = (void *)gen_pool_alloc(sram_pool, PAGE_SIZE);
return 0;
}
void __init omap_barrier_reserve_memblock(void)
{
dram_sync_size = ALIGN(PAGE_SIZE, SZ_1M);
dram_sync_paddr = arm_memblock_steal(dram_sync_size, SZ_1M);
}
void __init omap_barriers_init(void)
{
struct map_desc dram_io_desc[1];
dram_io_desc[0].virtual = OMAP4_DRAM_BARRIER_VA;
dram_io_desc[0].pfn = __phys_to_pfn(dram_sync_paddr);
dram_io_desc[0].length = dram_sync_size;
dram_io_desc[0].type = MT_MEMORY_RW_SO;
iotable_init(dram_io_desc, ARRAY_SIZE(dram_io_desc));
dram_sync = (void __iomem *) dram_io_desc[0].virtual;
pr_info("OMAP4: Map %pa to %p for dram barrier\n",
&dram_sync_paddr, dram_sync);
soc_mb = omap4_mb;
}
void gic_dist_disable(void)
{
if (gic_dist_base_addr)
writel_relaxed(0x0, gic_dist_base_addr + GIC_DIST_CTRL);
}
void gic_dist_enable(void)
{
if (gic_dist_base_addr)
writel_relaxed(0x1, gic_dist_base_addr + GIC_DIST_CTRL);
}
bool gic_dist_disabled(void)
{
return !(readl_relaxed(gic_dist_base_addr + GIC_DIST_CTRL) & 0x1);
}
void gic_timer_retrigger(void)
{
u32 twd_int = readl_relaxed(twd_base + TWD_TIMER_INTSTAT);
u32 gic_int = readl_relaxed(gic_dist_base_addr + GIC_DIST_PENDING_SET);
u32 twd_ctrl = readl_relaxed(twd_base + TWD_TIMER_CONTROL);
if (twd_int && !(gic_int & BIT(IRQ_LOCALTIMER))) {
pr_warn("%s: lost localtimer interrupt\n", __func__);
writel_relaxed(1, twd_base + TWD_TIMER_INTSTAT);
if (!(twd_ctrl & TWD_TIMER_CONTROL_PERIODIC)) {
writel_relaxed(1, twd_base + TWD_TIMER_COUNTER);
twd_ctrl |= TWD_TIMER_CONTROL_ENABLE;
writel_relaxed(twd_ctrl, twd_base + TWD_TIMER_CONTROL);
}
}
}
void __iomem *omap4_get_l2cache_base(void)
{
return l2cache_base;
}
void omap4_l2c310_write_sec(unsigned long val, unsigned reg)
{
unsigned smc_op;
switch (reg) {
case L2X0_CTRL:
smc_op = OMAP4_MON_L2X0_CTRL_INDEX;
break;
case L2X0_AUX_CTRL:
smc_op = OMAP4_MON_L2X0_AUXCTRL_INDEX;
break;
case L2X0_DEBUG_CTRL:
smc_op = OMAP4_MON_L2X0_DBG_CTRL_INDEX;
break;
case L310_PREFETCH_CTRL:
smc_op = OMAP4_MON_L2X0_PREFETCH_INDEX;
break;
case L310_POWER_CTRL:
pr_info_once("OMAP L2C310: ROM does not support power control setting\n");
return;
default:
WARN_ONCE(1, "OMAP L2C310: ignoring write to reg 0x%x\n", reg);
return;
}
omap_smc1(smc_op, val);
}
int __init omap_l2_cache_init(void)
{
l2cache_base = ioremap(OMAP44XX_L2CACHE_BASE, SZ_4K);
if (WARN_ON(!l2cache_base))
return -ENOMEM;
return 0;
}
void __iomem *omap4_get_sar_ram_base(void)
{
return sar_ram_base;
}
static int __init omap4_sar_ram_init(void)
{
unsigned long sar_base;
if (cpu_is_omap44xx())
sar_base = OMAP44XX_SAR_RAM_BASE;
else if (soc_is_omap54xx())
sar_base = OMAP54XX_SAR_RAM_BASE;
else
return -ENOMEM;
sar_ram_base = ioremap(sar_base, SZ_16K);
if (WARN_ON(!sar_ram_base))
return -ENOMEM;
return 0;
}
unsigned int omap4_xlate_irq(unsigned int hwirq)
{
struct of_phandle_args irq_data;
unsigned int irq;
if (!intc_node)
intc_node = of_find_matching_node(NULL, intc_match);
if (WARN_ON(!intc_node))
return hwirq;
irq_data.np = intc_node;
irq_data.args_count = 3;
irq_data.args[0] = 0;
irq_data.args[1] = hwirq - OMAP44XX_IRQ_GIC_START;
irq_data.args[2] = IRQ_TYPE_LEVEL_HIGH;
irq = irq_create_of_mapping(&irq_data);
if (WARN_ON(!irq))
irq = hwirq;
return irq;
}
void __init omap_gic_of_init(void)
{
struct device_node *np;
intc_node = of_find_matching_node(NULL, intc_match);
if (WARN_ON(!intc_node)) {
pr_err("No WUGEN found in DT, system will misbehave.\n");
pr_err("UPDATE YOUR DEVICE TREE!\n");
}
if (!cpu_is_omap446x())
goto skip_errata_init;
np = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-gic");
gic_dist_base_addr = of_iomap(np, 0);
WARN_ON(!gic_dist_base_addr);
np = of_find_compatible_node(NULL, NULL, "arm,cortex-a9-twd-timer");
twd_base = of_iomap(np, 0);
WARN_ON(!twd_base);
skip_errata_init:
irqchip_init();
}
