void __init r8a73a4_clock_init(void)
{
void __iomem *cpg_base, *reg;
int k, ret = 0;
cpg_base = ioremap_nocache(CPG_BASE, CPG_LEN);
BUG_ON(!cpg_base);
reg = cpg_base + (MPCKCR - CPG_BASE);
iowrite32(ioread32(reg) | 1 << 7 | 0x0c, reg);
iounmap(cpg_base);
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a73a4 clocks\n");
}
