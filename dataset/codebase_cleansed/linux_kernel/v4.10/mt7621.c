phys_addr_t mips_cpc_default_phys_base(void)
{
panic("Cannot detect cpc address");
}
void __init ralink_clk_init(void)
{
int cpu_fdiv = 0;
int cpu_ffrac = 0;
int fbdiv = 0;
u32 clk_sts, syscfg;
u8 clk_sel = 0, xtal_mode;
u32 cpu_clk;
if ((rt_sysc_r32(SYSC_REG_CPLL_CLKCFG0) & CPU_CLK_SEL) != 0)
clk_sel = 1;
switch (clk_sel) {
case 0:
clk_sts = rt_sysc_r32(SYSC_REG_CUR_CLK_STS);
cpu_fdiv = ((clk_sts >> 8) & 0x1F);
cpu_ffrac = (clk_sts & 0x1F);
cpu_clk = (500 * cpu_ffrac / cpu_fdiv) * 1000 * 1000;
break;
case 1:
fbdiv = ((rt_sysc_r32(0x648) >> 4) & 0x7F) + 1;
syscfg = rt_sysc_r32(SYSC_REG_SYSCFG);
xtal_mode = (syscfg >> 6) & 0x7;
if (xtal_mode >= 6) {
cpu_clk = 25 * fbdiv * 1000 * 1000;
} else if (xtal_mode >= 3) {
cpu_clk = 40 * fbdiv * 1000 * 1000;
} else {
cpu_clk = 20 * fbdiv * 1000 * 1000;
}
break;
}
}
void __init ralink_of_remap(void)
{
rt_sysc_membase = plat_of_remap_node("mtk,mt7621-sysc");
rt_memc_membase = plat_of_remap_node("mtk,mt7621-memc");
if (!rt_sysc_membase || !rt_memc_membase)
panic("Failed to remap core resources");
}
void prom_soc_init(struct ralink_soc_info *soc_info)
{
void __iomem *sysc = (void __iomem *) KSEG1ADDR(MT7621_SYSC_BASE);
unsigned char *name = NULL;
u32 n0;
u32 n1;
u32 rev;
n0 = __raw_readl(sysc + SYSC_REG_CHIP_NAME0);
n1 = __raw_readl(sysc + SYSC_REG_CHIP_NAME1);
if (n0 == MT7621_CHIP_NAME0 && n1 == MT7621_CHIP_NAME1) {
name = "MT7621";
soc_info->compatible = "mtk,mt7621-soc";
} else {
panic("mt7621: unknown SoC, n0:%08x n1:%08x\n", n0, n1);
}
rev = __raw_readl(sysc + SYSC_REG_CHIP_REV);
snprintf(soc_info->sys_type, RAMIPS_SYS_TYPE_LEN,
"MediaTek %s ver:%u eco:%u",
name,
(rev >> CHIP_REV_VER_SHIFT) & CHIP_REV_VER_MASK,
(rev & CHIP_REV_ECO_MASK));
soc_info->mem_size_min = MT7621_DDR2_SIZE_MIN;
soc_info->mem_size_max = MT7621_DDR2_SIZE_MAX;
soc_info->mem_base = MT7621_DRAM_BASE;
rt2880_pinmux_data = mt7621_pinmux_data;
mips_cm_probe();
mips_cpc_probe();
if (mips_cm_numiocu()) {
write_gcr_reg0_base(MT7621_PALMBUS_BASE);
write_gcr_reg0_mask(~MT7621_PALMBUS_SIZE |
CM_GCR_REGn_MASK_CMTGT_IOCU0);
}
if (!register_cps_smp_ops())
return;
if (!register_cmp_smp_ops())
return;
if (!register_vsmp_smp_ops())
return;
}
