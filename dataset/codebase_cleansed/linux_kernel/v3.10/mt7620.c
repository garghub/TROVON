void __init ralink_clk_init(void)
{
unsigned long cpu_rate, sys_rate;
u32 c0 = rt_sysc_r32(SYSC_REG_CPLL_CONFIG0);
u32 c1 = rt_sysc_r32(SYSC_REG_CPLL_CONFIG1);
u32 swconfig = (c0 >> CPLL_SW_CONFIG_SHIFT) & CPLL_SW_CONFIG_MASK;
u32 cpu_clk = (c1 >> CPLL_CPU_CLK_SHIFT) & CPLL_CPU_CLK_MASK;
if (cpu_clk) {
cpu_rate = 480000000;
} else if (!swconfig) {
cpu_rate = 600000000;
} else {
u32 m = (c0 >> CPLL_MULT_RATIO_SHIFT) & CPLL_MULT_RATIO;
u32 d = (c0 >> CPLL_DIV_RATIO_SHIFT) & CPLL_DIV_RATIO;
cpu_rate = ((40 * (m + 24)) / mt7620_clk_divider[d]) * 1000000;
}
if (dram_type == SYSCFG0_DRAM_TYPE_SDRAM)
sys_rate = cpu_rate / 4;
else
sys_rate = cpu_rate / 3;
ralink_clk_add("cpu", cpu_rate);
ralink_clk_add("10000100.timer", 40000000);
ralink_clk_add("10000500.uart", 40000000);
ralink_clk_add("10000c00.uartlite", 40000000);
}
void __init ralink_of_remap(void)
{
rt_sysc_membase = plat_of_remap_node("ralink,mt7620a-sysc");
rt_memc_membase = plat_of_remap_node("ralink,mt7620a-memc");
if (!rt_sysc_membase || !rt_memc_membase)
panic("Failed to remap core resources");
}
void prom_soc_init(struct ralink_soc_info *soc_info)
{
void __iomem *sysc = (void __iomem *) KSEG1ADDR(MT7620_SYSC_BASE);
unsigned char *name = NULL;
u32 n0;
u32 n1;
u32 rev;
u32 cfg0;
n0 = __raw_readl(sysc + SYSC_REG_CHIP_NAME0);
n1 = __raw_readl(sysc + SYSC_REG_CHIP_NAME1);
if (n0 == MT7620N_CHIP_NAME0 && n1 == MT7620N_CHIP_NAME1) {
name = "MT7620N";
soc_info->compatible = "ralink,mt7620n-soc";
} else if (n0 == MT7620A_CHIP_NAME0 && n1 == MT7620A_CHIP_NAME1) {
name = "MT7620A";
soc_info->compatible = "ralink,mt7620a-soc";
} else {
panic("mt7620: unknown SoC, n0:%08x n1:%08x\n", n0, n1);
}
rev = __raw_readl(sysc + SYSC_REG_CHIP_REV);
snprintf(soc_info->sys_type, RAMIPS_SYS_TYPE_LEN,
"Ralink %s ver:%u eco:%u",
name,
(rev >> CHIP_REV_VER_SHIFT) & CHIP_REV_VER_MASK,
(rev & CHIP_REV_ECO_MASK));
cfg0 = __raw_readl(sysc + SYSC_REG_SYSTEM_CONFIG0);
dram_type = (cfg0 >> SYSCFG0_DRAM_TYPE_SHIFT) & SYSCFG0_DRAM_TYPE_MASK;
switch (dram_type) {
case SYSCFG0_DRAM_TYPE_SDRAM:
soc_info->mem_size_min = MT7620_SDRAM_SIZE_MIN;
soc_info->mem_size_max = MT7620_SDRAM_SIZE_MAX;
break;
case SYSCFG0_DRAM_TYPE_DDR1:
soc_info->mem_size_min = MT7620_DDR1_SIZE_MIN;
soc_info->mem_size_max = MT7620_DDR1_SIZE_MAX;
break;
case SYSCFG0_DRAM_TYPE_DDR2:
soc_info->mem_size_min = MT7620_DDR2_SIZE_MIN;
soc_info->mem_size_max = MT7620_DDR2_SIZE_MAX;
break;
default:
BUG();
}
soc_info->mem_base = MT7620_DRAM_BASE;
}
