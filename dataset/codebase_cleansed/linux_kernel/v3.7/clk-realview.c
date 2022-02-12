static struct icst_vco realview_oscvco_get(void)
{
u32 val;
struct icst_vco vco;
val = readl(sys_vcoreg);
vco.v = val & 0x1ff;
vco.r = (val >> 9) & 0x7f;
vco.s = (val >> 16) & 03;
return vco;
}
static void realview_oscvco_set(struct icst_vco vco)
{
u32 val;
val = readl(sys_vcoreg) & ~0x7ffff;
val |= vco.v | (vco.r << 9) | (vco.s << 16);
writel(0xa05f, sys_lock);
writel(val, sys_vcoreg);
writel(0, sys_lock);
}
void __init realview_clk_init(void __iomem *sysbase, bool is_pb1176)
{
struct clk *clk;
sys_lock = sysbase + REALVIEW_SYS_LOCK_OFFSET;
if (is_pb1176)
sys_vcoreg = sysbase + REALVIEW_SYS_OSC0_OFFSET;
else
sys_vcoreg = sysbase + REALVIEW_SYS_OSC4_OFFSET;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, CLK_IS_ROOT, 0);
clk_register_clkdev(clk, "apb_pclk", NULL);
clk = clk_register_fixed_rate(NULL, "clk24mhz", NULL, CLK_IS_ROOT,
24000000);
clk_register_clkdev(clk, NULL, "dev:uart0");
clk_register_clkdev(clk, NULL, "dev:uart1");
clk_register_clkdev(clk, NULL, "dev:uart2");
clk_register_clkdev(clk, NULL, "fpga:kmi0");
clk_register_clkdev(clk, NULL, "fpga:kmi1");
clk_register_clkdev(clk, NULL, "fpga:mmc0");
clk_register_clkdev(clk, NULL, "dev:ssp0");
if (is_pb1176) {
clk_register_clkdev(clk, NULL, "dev:uart3");
clk_register_clkdev(clk, NULL, "dev:uart4");
} else
clk_register_clkdev(clk, NULL, "fpga:uart3");
clk = clk_register_fixed_rate(NULL, "clk1mhz", NULL, CLK_IS_ROOT,
1000000);
clk_register_clkdev(clk, NULL, "sp804");
clk = icst_clk_register(NULL, &realview_icst_desc);
clk_register_clkdev(clk, NULL, "dev:clcd");
clk_register_clkdev(clk, NULL, "issp:clcd");
}
