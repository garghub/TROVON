static void rt288x_wdt_reset(void)
{
u32 t;
t = rt_sysc_r32(SYSC_REG_CLKCFG);
t |= CLKCFG_SRAM_CS_N_WDT;
rt_sysc_w32(t, SYSC_REG_CLKCFG);
}
void __init ralink_clk_init(void)
{
unsigned long cpu_rate, wmac_rate = 40000000;
u32 t = rt_sysc_r32(SYSC_REG_SYSTEM_CONFIG);
t = ((t >> SYSTEM_CONFIG_CPUCLK_SHIFT) & SYSTEM_CONFIG_CPUCLK_MASK);
switch (t) {
case SYSTEM_CONFIG_CPUCLK_250:
cpu_rate = 250000000;
break;
case SYSTEM_CONFIG_CPUCLK_266:
cpu_rate = 266666667;
break;
case SYSTEM_CONFIG_CPUCLK_280:
cpu_rate = 280000000;
break;
case SYSTEM_CONFIG_CPUCLK_300:
cpu_rate = 300000000;
break;
}
ralink_clk_add("cpu", cpu_rate);
ralink_clk_add("300100.timer", cpu_rate / 2);
ralink_clk_add("300120.watchdog", cpu_rate / 2);
ralink_clk_add("300500.uart", cpu_rate / 2);
ralink_clk_add("300c00.uartlite", cpu_rate / 2);
ralink_clk_add("400000.ethernet", cpu_rate / 2);
ralink_clk_add("480000.wmac", wmac_rate);
}
void __init ralink_of_remap(void)
{
rt_sysc_membase = plat_of_remap_node("ralink,rt2880-sysc");
rt_memc_membase = plat_of_remap_node("ralink,rt2880-memc");
if (!rt_sysc_membase || !rt_memc_membase)
panic("Failed to remap core resources");
}
void prom_soc_init(struct ralink_soc_info *soc_info)
{
void __iomem *sysc = (void __iomem *) KSEG1ADDR(RT2880_SYSC_BASE);
const char *name;
u32 n0;
u32 n1;
u32 id;
n0 = __raw_readl(sysc + SYSC_REG_CHIP_NAME0);
n1 = __raw_readl(sysc + SYSC_REG_CHIP_NAME1);
id = __raw_readl(sysc + SYSC_REG_CHIP_ID);
if (n0 == RT2880_CHIP_NAME0 && n1 == RT2880_CHIP_NAME1) {
soc_info->compatible = "ralink,r2880-soc";
name = "RT2880";
} else {
panic("rt288x: unknown SoC, n0:%08x n1:%08x", n0, n1);
}
snprintf(soc_info->sys_type, RAMIPS_SYS_TYPE_LEN,
"Ralink %s id:%u rev:%u",
name,
(id >> CHIP_ID_ID_SHIFT) & CHIP_ID_ID_MASK,
(id & CHIP_ID_REV_MASK));
soc_info->mem_base = RT2880_SDRAM_BASE;
soc_info->mem_size_min = RT2880_MEM_SIZE_MIN;
soc_info->mem_size_max = RT2880_MEM_SIZE_MAX;
rt2880_pinmux_data = rt2880_pinmux_data_act;
ralink_soc == RT2880_SOC;
}
