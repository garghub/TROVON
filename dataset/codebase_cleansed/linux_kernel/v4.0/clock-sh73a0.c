static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (__raw_readl(PLLECR) & (1 << clk->enable_bit)) {
mult = (((__raw_readl(clk->enable_reg) >> 24) & 0x3f) + 1);
switch (clk->enable_bit) {
case 1:
case 2:
if (__raw_readl(clk->enable_reg) & (1 << 20))
mult *= 2;
}
}
return clk->parent->rate * mult;
}
static int frqcr_kick(void)
{
int i;
__raw_writel(__raw_readl(FRQCRB) | (1 << 31), FRQCRB);
for (i = 1000; i; i--)
if (__raw_readl(FRQCRB) & (1 << 31))
cpu_relax();
else
return i;
return -ETIMEDOUT;
}
static void div4_kick(struct clk *clk)
{
frqcr_kick();
}
static unsigned long twd_recalc(struct clk *clk)
{
return clk_get_rate(clk->parent) / 4;
}
static int zclk_set_rate(struct clk *clk, unsigned long rate)
{
int ret;
if (!clk->parent || !__clk_get(clk->parent))
return -ENODEV;
if (readl(FRQCRB) & (1 << 31))
return -EBUSY;
if (rate == clk_get_rate(clk->parent)) {
__raw_writel(__raw_readl(FRQCRB) & ~(1 << 28), FRQCRB);
ret = div4_clk_ops->set_rate(clk, rate / 2);
if (!ret)
ret = frqcr_kick();
if (ret > 0)
ret = 0;
} else {
__raw_writel(__raw_readl(FRQCRB) | (1 << 28), FRQCRB);
ret = frqcr_kick();
if (ret >= 0)
ret = div4_clk_ops->set_rate(clk, rate);
if (ret < 0)
goto esetrate;
}
esetrate:
__clk_put(clk->parent);
return ret;
}
static long zclk_round_rate(struct clk *clk, unsigned long rate)
{
unsigned long div_freq = div4_clk_ops->round_rate(clk, rate),
parent_freq = clk_get_rate(clk->parent);
if (rate > div_freq && abs(parent_freq - rate) < rate - div_freq)
return parent_freq;
return div_freq;
}
static unsigned long zclk_recalc(struct clk *clk)
{
unsigned long div_freq = div4_clk_ops->recalc(clk);
if (__raw_readl(FRQCRB) & (1 << 28))
return div_freq;
return clk_get_rate(clk->parent);
}
static int kicker_set_rate(struct clk *clk, unsigned long rate)
{
if (__raw_readl(FRQCRB) & (1 << 31))
return -EBUSY;
return div4_clk_ops->set_rate(clk, rate);
}
static void div4_clk_extend(void)
{
int i;
div4_clk_ops = div4_clks[0].ops;
kicker_ops = *div4_clk_ops;
zclk_ops = *div4_clk_ops;
kicker_ops.set_rate = kicker_set_rate;
zclk_ops.set_rate = zclk_set_rate;
zclk_ops.round_rate = zclk_round_rate;
zclk_ops.recalc = zclk_recalc;
for (i = 0; i < DIV4_NR; i++)
div4_clks[i].ops = i == DIV4_Z ? &zclk_ops : &kicker_ops;
}
static unsigned long dsiphy_recalc(struct clk *clk)
{
u32 value;
value = __raw_readl(clk->mapping->base);
if (!(value & 0x000B8000))
return clk->parent->rate;
value &= 0x3f;
value += 1;
if ((value < 12) ||
(value > 33)) {
pr_err("DSIPHY has wrong value (%d)", value);
return 0;
}
return clk->parent->rate / value;
}
static long dsiphy_round_rate(struct clk *clk, unsigned long rate)
{
return clk_rate_mult_range_round(clk, 12, 33, rate);
}
static void dsiphy_disable(struct clk *clk)
{
u32 value;
value = __raw_readl(clk->mapping->base);
value &= ~0x000B8000;
__raw_writel(value , clk->mapping->base);
}
static int dsiphy_enable(struct clk *clk)
{
u32 value;
int multi;
value = __raw_readl(clk->mapping->base);
multi = (value & 0x3f) + 1;
if ((multi < 12) || (multi > 33))
return -EIO;
__raw_writel(value | 0x000B8000, clk->mapping->base);
return 0;
}
static int dsiphy_set_rate(struct clk *clk, unsigned long rate)
{
u32 value;
int idx;
idx = rate / clk->parent->rate;
if ((idx < 12) || (idx > 33))
return -EINVAL;
idx += -1;
value = __raw_readl(clk->mapping->base);
value = (value & ~0x3f) + idx;
__raw_writel(value, clk->mapping->base);
return 0;
}
void __init sh73a0_clock_init(void)
{
int k, ret = 0;
__raw_writel(0x108, SD0CKCR);
__raw_writel(0x108, SD1CKCR);
__raw_writel(0x108, SD2CKCR);
switch ((__raw_readl(CKSCR) >> 28) & 0x03) {
case 0:
main_clk.parent = &sh73a0_extal1_clk;
break;
case 1:
main_clk.parent = &extal1_div2_clk;
break;
case 2:
main_clk.parent = &sh73a0_extal2_clk;
break;
case 3:
main_clk.parent = &extal2_div2_clk;
break;
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret) {
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
div4_clk_extend();
}
if (!ret)
ret = sh_clk_div6_reparent_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
for (k = 0; !ret && (k < ARRAY_SIZE(late_main_clks)); k++)
ret = clk_register(late_main_clks[k]);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup sh73a0 clocks\n");
}
