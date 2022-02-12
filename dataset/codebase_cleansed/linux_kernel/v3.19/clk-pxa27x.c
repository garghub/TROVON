unsigned int pxa27x_get_clk_frequency_khz(int info)
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
pr_info("Run Mode clock: %ld.%02ldMHz\n",
clks[1] / 1000000, (clks[1] % 1000000) / 10000);
pr_info("Turbo Mode clock: %ld.%02ldMHz\n",
clks[2] / 1000000, (clks[2] % 1000000) / 10000);
pr_info("Memory clock: %ld.%02ldMHz\n",
clks[3] / 1000000, (clks[3] % 1000000) / 10000);
pr_info("System bus clock: %ld.%02ldMHz\n",
clks[4] / 1000000, (clks[4] % 1000000) / 10000);
}
return (unsigned int)clks[0];
}
bool pxa27x_is_ppll_disabled(void)
{
unsigned long ccsr = CCSR;
return ccsr & (1 << CCCR_PPDIS_BIT);
}
static unsigned long clk_pxa27x_cpll_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long clkcfg;
unsigned int t, ht;
unsigned int l, L, n2, N;
unsigned long ccsr = CCSR;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
t = clkcfg & (1 << 0);
ht = clkcfg & (1 << 2);
l = ccsr & CCSR_L_MASK;
n2 = (ccsr & CCSR_N2_MASK) >> CCSR_N2_SHIFT;
L = l * parent_rate;
N = (L * n2) / 2;
return t ? N : L;
}
static unsigned long clk_pxa27x_lcd_base_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned int l, osc_forced;
unsigned long ccsr = CCSR;
unsigned long cccr = CCCR;
l = ccsr & CCSR_L_MASK;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
if (osc_forced) {
if (cccr & (1 << CCCR_LCD_26_BIT))
return parent_rate * 2;
else
return parent_rate;
}
if (l <= 7)
return parent_rate;
if (l <= 16)
return parent_rate / 2;
return parent_rate / 4;
}
static u8 clk_pxa27x_lcd_base_get_parent(struct clk_hw *hw)
{
unsigned int osc_forced;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
if (osc_forced)
return PXA_LCD_13Mhz;
else
return PXA_LCD_RUN;
}
static void __init pxa27x_register_plls(void)
{
clk_register_fixed_rate(NULL, "osc_13mhz", NULL,
CLK_GET_RATE_NOCACHE | CLK_IS_ROOT,
13 * MHz);
clk_register_fixed_rate(NULL, "osc_32_768khz", NULL,
CLK_GET_RATE_NOCACHE | CLK_IS_ROOT,
32768 * KHz);
clk_register_fixed_rate(NULL, "clk_dummy", NULL, CLK_IS_ROOT, 0);
clk_register_fixed_factor(NULL, "ppll_312mhz", "osc_13mhz", 0, 24, 1);
}
static unsigned long clk_pxa27x_core_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long clkcfg;
unsigned int t, ht, b, osc_forced;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
t = clkcfg & (1 << 0);
ht = clkcfg & (1 << 2);
b = clkcfg & (1 << 3);
if (osc_forced)
return parent_rate;
if (ht)
return parent_rate / 2;
else
return parent_rate;
}
static u8 clk_pxa27x_core_get_parent(struct clk_hw *hw)
{
unsigned long clkcfg;
unsigned int t, ht, b, osc_forced;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
if (osc_forced)
return PXA_CORE_13Mhz;
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
t = clkcfg & (1 << 0);
ht = clkcfg & (1 << 2);
b = clkcfg & (1 << 3);
if (ht || t)
return PXA_CORE_TURBO;
return PXA_CORE_RUN;
}
static unsigned long clk_pxa27x_run_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long ccsr = CCSR;
unsigned int n2 = (ccsr & CCSR_N2_MASK) >> CCSR_N2_SHIFT;
return (parent_rate / n2) * 2;
}
static void __init pxa27x_register_core(void)
{
clk_register_clk_pxa27x_cpll();
clk_register_clk_pxa27x_run();
clkdev_pxa_register(CLK_CORE, "core", NULL,
clk_register_clk_pxa27x_core());
}
static unsigned long clk_pxa27x_system_bus_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned long clkcfg;
unsigned int b, osc_forced;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
asm("mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg));
b = clkcfg & (1 << 3);
if (osc_forced)
return parent_rate;
if (b)
return parent_rate / 2;
else
return parent_rate;
}
static u8 clk_pxa27x_system_bus_get_parent(struct clk_hw *hw)
{
unsigned int osc_forced;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
if (osc_forced)
return PXA_BUS_13Mhz;
else
return PXA_BUS_RUN;
}
static unsigned long clk_pxa27x_memory_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
unsigned int a, l, osc_forced;
unsigned long cccr = CCCR;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
a = cccr & (1 << CCCR_A_BIT);
l = ccsr & CCSR_L_MASK;
if (osc_forced || a)
return parent_rate;
if (l <= 10)
return parent_rate;
if (l <= 20)
return parent_rate / 2;
return parent_rate / 4;
}
static u8 clk_pxa27x_memory_get_parent(struct clk_hw *hw)
{
unsigned int osc_forced, a;
unsigned long cccr = CCCR;
unsigned long ccsr = CCSR;
osc_forced = ccsr & (1 << CCCR_CPDIS_BIT);
a = cccr & (1 << CCCR_A_BIT);
if (osc_forced)
return PXA_MEM_13Mhz;
if (a)
return PXA_MEM_SYSTEM_BUS;
else
return PXA_MEM_RUN;
}
static void __init pxa27x_base_clocks_init(void)
{
pxa27x_register_plls();
pxa27x_register_core();
clk_register_clk_pxa27x_system_bus();
clk_register_clk_pxa27x_memory();
clk_register_clk_pxa27x_lcd_base();
}
static int __init pxa27x_clocks_init(void)
{
pxa27x_base_clocks_init();
return clk_pxa_cken_init(pxa27x_clocks, ARRAY_SIZE(pxa27x_clocks));
}
static void __init pxa27x_dt_clocks_init(struct device_node *np)
{
pxa27x_clocks_init();
clk_pxa_dt_common_init(np);
}
