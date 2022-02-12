static void rt3883_wdt_reset(void)
{
u32 t;
t = rt_sysc_r32(RT3883_SYSC_REG_SYSCFG1);
t |= RT3883_SYSCFG1_GPIO2_AS_WDT_OUT;
rt_sysc_w32(t, RT3883_SYSC_REG_SYSCFG1);
}
void __init ralink_clk_init(void)
{
unsigned long cpu_rate, sys_rate;
u32 syscfg0;
u32 clksel;
u32 ddr2;
syscfg0 = rt_sysc_r32(RT3883_SYSC_REG_SYSCFG0);
clksel = ((syscfg0 >> RT3883_SYSCFG0_CPUCLK_SHIFT) &
RT3883_SYSCFG0_CPUCLK_MASK);
ddr2 = syscfg0 & RT3883_SYSCFG0_DRAM_TYPE_DDR2;
switch (clksel) {
case RT3883_SYSCFG0_CPUCLK_250:
cpu_rate = 250000000;
sys_rate = (ddr2) ? 125000000 : 83000000;
break;
case RT3883_SYSCFG0_CPUCLK_384:
cpu_rate = 384000000;
sys_rate = (ddr2) ? 128000000 : 96000000;
break;
case RT3883_SYSCFG0_CPUCLK_480:
cpu_rate = 480000000;
sys_rate = (ddr2) ? 160000000 : 120000000;
break;
case RT3883_SYSCFG0_CPUCLK_500:
cpu_rate = 500000000;
sys_rate = (ddr2) ? 166000000 : 125000000;
break;
}
ralink_clk_add("cpu", cpu_rate);
ralink_clk_add("10000100.timer", sys_rate);
ralink_clk_add("10000120.watchdog", sys_rate);
ralink_clk_add("10000500.uart", 40000000);
ralink_clk_add("10000b00.spi", sys_rate);
ralink_clk_add("10000c00.uartlite", 40000000);
ralink_clk_add("10100000.ethernet", sys_rate);
}
void __init ralink_of_remap(void)
{
rt_sysc_membase = plat_of_remap_node("ralink,rt3883-sysc");
rt_memc_membase = plat_of_remap_node("ralink,rt3883-memc");
if (!rt_sysc_membase || !rt_memc_membase)
panic("Failed to remap core resources");
}
void prom_soc_init(struct ralink_soc_info *soc_info)
{
void __iomem *sysc = (void __iomem *) KSEG1ADDR(RT3883_SYSC_BASE);
const char *name;
u32 n0;
u32 n1;
u32 id;
n0 = __raw_readl(sysc + RT3883_SYSC_REG_CHIPID0_3);
n1 = __raw_readl(sysc + RT3883_SYSC_REG_CHIPID4_7);
id = __raw_readl(sysc + RT3883_SYSC_REG_REVID);
if (n0 == RT3883_CHIP_NAME0 && n1 == RT3883_CHIP_NAME1) {
soc_info->compatible = "ralink,rt3883-soc";
name = "RT3883";
} else {
panic("rt3883: unknown SoC, n0:%08x n1:%08x", n0, n1);
}
snprintf(soc_info->sys_type, RAMIPS_SYS_TYPE_LEN,
"Ralink %s ver:%u eco:%u",
name,
(id >> RT3883_REVID_VER_ID_SHIFT) & RT3883_REVID_VER_ID_MASK,
(id & RT3883_REVID_ECO_ID_MASK));
soc_info->mem_base = RT3883_SDRAM_BASE;
soc_info->mem_size_min = RT3883_MEM_SIZE_MIN;
soc_info->mem_size_max = RT3883_MEM_SIZE_MAX;
}
