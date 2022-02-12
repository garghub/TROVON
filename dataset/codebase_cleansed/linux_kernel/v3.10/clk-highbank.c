static int clk_pll_prepare(struct clk_hw *hwclk)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 reg;
reg = readl(hbclk->reg);
reg &= ~HB_PLL_RESET;
writel(reg, hbclk->reg);
while ((readl(hbclk->reg) & HB_PLL_LOCK) == 0)
;
while ((readl(hbclk->reg) & HB_PLL_LOCK_500) == 0)
;
return 0;
}
static void clk_pll_unprepare(struct clk_hw *hwclk)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 reg;
reg = readl(hbclk->reg);
reg |= HB_PLL_RESET;
writel(reg, hbclk->reg);
}
static int clk_pll_enable(struct clk_hw *hwclk)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 reg;
reg = readl(hbclk->reg);
reg |= HB_PLL_EXT_ENA;
writel(reg, hbclk->reg);
return 0;
}
static void clk_pll_disable(struct clk_hw *hwclk)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 reg;
reg = readl(hbclk->reg);
reg &= ~HB_PLL_EXT_ENA;
writel(reg, hbclk->reg);
}
static unsigned long clk_pll_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
unsigned long divf, divq, vco_freq, reg;
reg = readl(hbclk->reg);
if (reg & HB_PLL_EXT_BYPASS)
return parent_rate;
divf = (reg & HB_PLL_DIVF_MASK) >> HB_PLL_DIVF_SHIFT;
divq = (reg & HB_PLL_DIVQ_MASK) >> HB_PLL_DIVQ_SHIFT;
vco_freq = parent_rate * (divf + 1);
return vco_freq / (1 << divq);
}
static void clk_pll_calc(unsigned long rate, unsigned long ref_freq,
u32 *pdivq, u32 *pdivf)
{
u32 divq, divf;
unsigned long vco_freq;
if (rate < HB_PLL_MIN_FREQ)
rate = HB_PLL_MIN_FREQ;
if (rate > HB_PLL_MAX_FREQ)
rate = HB_PLL_MAX_FREQ;
for (divq = 1; divq <= 6; divq++) {
if ((rate * (1 << divq)) >= HB_PLL_VCO_MIN_FREQ)
break;
}
vco_freq = rate * (1 << divq);
divf = (vco_freq + (ref_freq / 2)) / ref_freq;
divf--;
*pdivq = divq;
*pdivf = divf;
}
static long clk_pll_round_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long *parent_rate)
{
u32 divq, divf;
unsigned long ref_freq = *parent_rate;
clk_pll_calc(rate, ref_freq, &divq, &divf);
return (ref_freq * (divf + 1)) / (1 << divq);
}
static int clk_pll_set_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 divq, divf;
u32 reg;
clk_pll_calc(rate, parent_rate, &divq, &divf);
reg = readl(hbclk->reg);
if (divf != ((reg & HB_PLL_DIVF_MASK) >> HB_PLL_DIVF_SHIFT)) {
reg |= HB_PLL_EXT_BYPASS;
writel(reg | HB_PLL_EXT_BYPASS, hbclk->reg);
writel(reg | HB_PLL_RESET, hbclk->reg);
reg &= ~(HB_PLL_DIVF_MASK | HB_PLL_DIVQ_MASK);
reg |= (divf << HB_PLL_DIVF_SHIFT) | (divq << HB_PLL_DIVQ_SHIFT);
writel(reg | HB_PLL_RESET, hbclk->reg);
writel(reg, hbclk->reg);
while ((readl(hbclk->reg) & HB_PLL_LOCK) == 0)
;
while ((readl(hbclk->reg) & HB_PLL_LOCK_500) == 0)
;
reg |= HB_PLL_EXT_ENA;
reg &= ~HB_PLL_EXT_BYPASS;
} else {
writel(reg | HB_PLL_EXT_BYPASS, hbclk->reg);
reg &= ~HB_PLL_DIVQ_MASK;
reg |= divq << HB_PLL_DIVQ_SHIFT;
writel(reg | HB_PLL_EXT_BYPASS, hbclk->reg);
}
writel(reg, hbclk->reg);
return 0;
}
static unsigned long clk_cpu_periphclk_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 div = (readl(hbclk->reg) & HB_A9_PCLK_DIV) ? 8 : 4;
return parent_rate / div;
}
static unsigned long clk_cpu_a9bclk_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 div = (readl(hbclk->reg) & HB_A9_BCLK_DIV_MASK) >> HB_A9_BCLK_DIV_SHIFT;
return parent_rate / (div + 2);
}
static unsigned long clk_periclk_recalc_rate(struct clk_hw *hwclk,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 div;
div = readl(hbclk->reg) & 0x1f;
div++;
div *= 2;
return parent_rate / div;
}
static long clk_periclk_round_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long *parent_rate)
{
u32 div;
div = *parent_rate / rate;
div++;
div &= ~0x1;
return *parent_rate / div;
}
static int clk_periclk_set_rate(struct clk_hw *hwclk, unsigned long rate,
unsigned long parent_rate)
{
struct hb_clk *hbclk = to_hb_clk(hwclk);
u32 div;
div = parent_rate / rate;
if (div & 0x1)
return -EINVAL;
writel(div >> 1, hbclk->reg);
return 0;
}
void __init hb_pll_init(struct device_node *node)
{
hb_clk_init(node, &clk_pll_ops);
}
static void __init hb_a9periph_init(struct device_node *node)
{
hb_clk_init(node, &a9periphclk_ops);
}
static void __init hb_a9bus_init(struct device_node *node)
{
struct clk *clk = hb_clk_init(node, &a9bclk_ops);
clk_prepare_enable(clk);
}
static void __init hb_emmc_init(struct device_node *node)
{
hb_clk_init(node, &periclk_ops);
}
