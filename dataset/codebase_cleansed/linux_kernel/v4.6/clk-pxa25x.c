unsigned int pxa25x_get_clk_frequency_khz(int info)
{
struct clk *clk;
unsigned long clks[5];
int i;
for (i = 0; i < ARRAY_SIZE(get_freq_khz); i++) {
clk = clk_get(NULL, get_freq_khz[i]);
if (IS_ERR(clk)) {
clks[i] = 0;
} else {
clks[i] = clk_get_rate(clk);
clk_put(clk);
}
}
if (info) {
pr_info("Run Mode clock: %ld.%02ldMHz\n",
clks[1] / 1000000, (clks[1] % 1000000) / 10000);
pr_info("Turbo Mode clock: %ld.%02ldMHz\n",
clks[2] / 1000000, (clks[2] % 1000000) / 10000);
pr_info("Memory clock: %ld.%02ldMHz\n",
clks[3] / 1000000, (clks[3] % 1000000) / 10000);
}
return (unsigned int)clks[0] / KHz;
}
static unsigned long clk_pxa25x_memory_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long cccr = readl(CCCR);
unsigned int m = M_clk_mult[(cccr >> 5) & 0x03];
return parent_rate / m;
}
static u8 clk_pxa25x_core_get_parent(struct clk_hw *hw)
{
unsigned long clkcfg;
unsigned int t;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
t = clkcfg & (1 << 0);
if (t)
return PXA_CORE_TURBO;
return PXA_CORE_RUN;
}
static unsigned long clk_pxa25x_core_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate;
}
static unsigned long clk_pxa25x_run_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long cccr = readl(CCCR);
unsigned int n2 = N2_clk_mult[(cccr >> 7) & 0x07];
return (parent_rate / n2) * 2;
}
static unsigned long clk_pxa25x_cpll_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long clkcfg, cccr = readl(CCCR);
unsigned int l, m, n2, t;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
t = clkcfg & (1 << 0);
l = L_clk_mult[(cccr >> 0) & 0x1f];
m = M_clk_mult[(cccr >> 5) & 0x03];
n2 = N2_clk_mult[(cccr >> 7) & 0x07];
if (t)
return m * l * n2 * parent_rate / 2;
return m * l * parent_rate;
}
static void __init pxa25x_register_core(void)
{
clk_register_clk_pxa25x_cpll();
clk_register_clk_pxa25x_run();
clkdev_pxa_register(CLK_CORE, "core", NULL,
clk_register_clk_pxa25x_core());
}
static void __init pxa25x_register_plls(void)
{
clk_register_fixed_rate(NULL, "osc_3_6864mhz", NULL,
CLK_GET_RATE_NOCACHE, 3686400);
clk_register_fixed_rate(NULL, "osc_32_768khz", NULL,
CLK_GET_RATE_NOCACHE, 32768);
clk_register_fixed_rate(NULL, "clk_dummy", NULL, 0, 0);
clk_register_fixed_factor(NULL, "ppll_95_85mhz", "osc_3_6864mhz",
0, 26, 1);
clk_register_fixed_factor(NULL, "ppll_147_46mhz", "osc_3_6864mhz",
0, 40, 1);
}
static void __init pxa25x_base_clocks_init(void)
{
pxa25x_register_plls();
pxa25x_register_core();
clk_register_clk_pxa25x_memory();
}
static void __init pxa25x_dummy_clocks_init(void)
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
int __init pxa25x_clocks_init(void)
{
pxa25x_base_clocks_init();
pxa25x_dummy_clocks_init();
return clk_pxa_cken_init(pxa25x_clocks, ARRAY_SIZE(pxa25x_clocks));
}
static void __init pxa25x_dt_clocks_init(struct device_node *np)
{
pxa25x_clocks_init();
clk_pxa_dt_common_init(np);
}
