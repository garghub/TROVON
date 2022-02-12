unsigned int pxa3xx_get_clk_frequency_khz(int info)
{
struct clk *clk;
unsigned long clks[5];
int i;
for (i = 0; i < 5; i++) {
clk = clk_get(NULL, get_freq_khz[i]);
if (IS_ERR(clk)) {
clks[i] = 0;
} else {
clks[i] = clk_get_rate(clk);
clk_put(clk);
}
}
if (info) {
pr_info("RO Mode clock: %ld.%02ldMHz\n",
clks[1] / 1000000, (clks[0] % 1000000) / 10000);
pr_info("Run Mode clock: %ld.%02ldMHz\n",
clks[2] / 1000000, (clks[1] % 1000000) / 10000);
pr_info("Turbo Mode clock: %ld.%02ldMHz\n",
clks[3] / 1000000, (clks[2] % 1000000) / 10000);
pr_info("System bus clock: %ld.%02ldMHz\n",
clks[4] / 1000000, (clks[4] % 1000000) / 10000);
}
return (unsigned int)clks[0];
}
static unsigned long clk_pxa3xx_ac97_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long ac97_div, rate;
ac97_div = AC97_DIV;
rate = parent_rate / 2;
rate /= ((ac97_div >> 12) & 0x7fff);
rate *= (ac97_div & 0xfff);
return rate;
}
static unsigned long clk_pxa3xx_smemc_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long acsr = ACSR;
unsigned long memclkcfg = __raw_readl(MEMCLKCFG);
return (parent_rate / 48) * smcfs_mult[(acsr >> 23) & 0x7] /
df_clkdiv[(memclkcfg >> 16) & 0x3];
}
static bool pxa3xx_is_ring_osc_forced(void)
{
unsigned long acsr = ACSR;
return acsr & ACCR_D0CS;
}
static unsigned long clk_pxa3xx_system_bus_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long acsr = ACSR;
unsigned int hss = (acsr >> 14) & 0x3;
if (pxa3xx_is_ring_osc_forced())
return parent_rate;
return parent_rate / 48 * hss_mult[hss];
}
static u8 clk_pxa3xx_system_bus_get_parent(struct clk_hw *hw)
{
if (pxa3xx_is_ring_osc_forced())
return PXA_BUS_60Mhz;
else
return PXA_BUS_HSS;
}
static unsigned long clk_pxa3xx_core_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate;
}
static u8 clk_pxa3xx_core_get_parent(struct clk_hw *hw)
{
unsigned long xclkcfg;
unsigned int t;
if (pxa3xx_is_ring_osc_forced())
return PXA_CORE_60Mhz;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
t = xclkcfg & 0x1;
if (t)
return PXA_CORE_TURBO;
return PXA_CORE_RUN;
}
static unsigned long clk_pxa3xx_run_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long acsr = ACSR;
unsigned int xn = (acsr & ACCR_XN_MASK) >> 8;
unsigned int t, xclkcfg;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
t = xclkcfg & 0x1;
return t ? (parent_rate / xn) * 2 : parent_rate;
}
static unsigned long clk_pxa3xx_cpll_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long acsr = ACSR;
unsigned int xn = (acsr & ACCR_XN_MASK) >> 8;
unsigned int xl = acsr & ACCR_XL_MASK;
unsigned int t, xclkcfg;
__asm__ __volatile__("mrc\tp14, 0, %0, c6, c0, 0" : "=r"(xclkcfg));
t = xclkcfg & 0x1;
pr_info("RJK: parent_rate=%lu, xl=%u, xn=%u\n", parent_rate, xl, xn);
return t ? parent_rate * xl * xn : parent_rate * xl;
}
static void __init pxa3xx_register_core(void)
{
clk_register_clk_pxa3xx_cpll();
clk_register_clk_pxa3xx_run();
clkdev_pxa_register(CLK_CORE, "core", NULL,
clk_register_clk_pxa3xx_core());
}
static void __init pxa3xx_register_plls(void)
{
clk_register_fixed_rate(NULL, "osc_13mhz", NULL,
CLK_GET_RATE_NOCACHE | CLK_IS_ROOT,
13 * MHz);
clk_register_fixed_rate(NULL, "osc_32_768khz", NULL,
CLK_GET_RATE_NOCACHE | CLK_IS_ROOT,
32768);
clk_register_fixed_rate(NULL, "ring_osc_120mhz", NULL,
CLK_GET_RATE_NOCACHE | CLK_IS_ROOT,
120 * MHz);
clk_register_fixed_rate(NULL, "clk_dummy", NULL, CLK_IS_ROOT, 0);
clk_register_fixed_factor(NULL, "spll_624mhz", "osc_13mhz", 0, 48, 1);
clk_register_fixed_factor(NULL, "ring_osc_60mhz", "ring_osc_120mhz",
0, 1, 2);
}
static void __init pxa3xx_dummy_clocks_init(void)
{
struct clk *clk;
struct dummy_clk *d;
const char *name;
int i;
for (i = 0; i < ARRAY_SIZE(dummy_clks); i++) {
d = &dummy_clks[i];
name = d->dev_id ? d->dev_id : d->con_id;
clk = clk_register_fixed_factor(NULL, name, d->parent, 0, 1, 1);
clk_register_clkdev(clk, d->con_id, d->dev_id);
}
}
static void __init pxa3xx_base_clocks_init(void)
{
pxa3xx_register_plls();
pxa3xx_register_core();
clk_register_clk_pxa3xx_system_bus();
clk_register_clk_pxa3xx_ac97();
clk_register_clk_pxa3xx_smemc();
clk_register_gate(NULL, "CLK_POUT", "osc_13mhz", 0,
(void __iomem *)&OSCC, 11, 0, NULL);
}
int __init pxa3xx_clocks_init(void)
{
int ret;
pxa3xx_base_clocks_init();
pxa3xx_dummy_clocks_init();
ret = clk_pxa_cken_init(pxa3xx_clocks, ARRAY_SIZE(pxa3xx_clocks));
if (ret)
return ret;
if (cpu_is_pxa320())
return clk_pxa_cken_init(pxa320_clocks,
ARRAY_SIZE(pxa320_clocks));
if (cpu_is_pxa300() || cpu_is_pxa310())
return clk_pxa_cken_init(pxa300_310_clocks,
ARRAY_SIZE(pxa300_310_clocks));
return clk_pxa_cken_init(pxa93x_clocks, ARRAY_SIZE(pxa93x_clocks));
}
static void __init pxa3xx_dt_clocks_init(struct device_node *np)
{
pxa3xx_clocks_init();
clk_pxa_dt_common_init(np);
}
