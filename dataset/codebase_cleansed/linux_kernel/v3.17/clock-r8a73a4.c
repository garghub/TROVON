static unsigned long pll_recalc(struct clk *clk)
{
unsigned long mult = 1;
if (ioread32(CPG_MAP(PLLECR)) & (1 << clk->enable_bit))
mult = (((ioread32(clk->mapped_reg) >> 24) & 0x7f) + 1);
return clk->parent->rate * mult;
}
static int pll_set_parent(struct clk *clk, struct clk *parent)
{
u32 val;
int i, ret;
if (!clk->parent_table || !clk->parent_num)
return -EINVAL;
for (i = 0; i < clk->parent_num; i++)
if (clk->parent_table[i] == parent)
break;
if (i == clk->parent_num)
return -ENODEV;
ret = clk_reparent(clk, parent);
if (ret < 0)
return ret;
val = ioread32(clk->mapped_reg) &
~(((1 << clk->src_width) - 1) << clk->src_shift);
iowrite32(val | i << clk->src_shift, clk->mapped_reg);
return 0;
}
static bool frqcr_kick_check(struct clk *clk)
{
return !(ioread32(CPG_MAP(FRQCRB)) & BIT(31));
}
static int frqcr_kick_do(struct clk *clk)
{
int i;
iowrite32(ioread32(CPG_MAP(FRQCRB)) | BIT(31), CPG_MAP(FRQCRB));
for (i = 1000; i; i--)
if (ioread32(CPG_MAP(FRQCRB)) & BIT(31))
cpu_relax();
else
return 0;
return -ETIMEDOUT;
}
static int zclk_set_rate(struct clk *clk, unsigned long rate)
{
void __iomem *frqcrc;
int ret;
unsigned long step, p_rate;
u32 val;
if (!clk->parent || !__clk_get(clk->parent))
return -ENODEV;
if (!atomic_inc_and_test(&frqcr_lock) || !frqcr_kick_check(clk)) {
ret = -EBUSY;
goto done;
}
p_rate = clk_get_rate(clk->parent);
if (rate == p_rate) {
val = 0;
} else {
step = DIV_ROUND_CLOSEST(p_rate, 32);
if (rate > p_rate || rate < step) {
ret = -EINVAL;
goto done;
}
val = 32 - rate / step;
}
frqcrc = clk->mapped_reg + (FRQCRC - (u32)clk->enable_reg);
iowrite32((ioread32(frqcrc) & ~(clk->div_mask << clk->enable_bit)) |
(val << clk->enable_bit), frqcrc);
ret = frqcr_kick_do(clk);
done:
atomic_dec(&frqcr_lock);
__clk_put(clk->parent);
return ret;
}
static long zclk_round_rate(struct clk *clk, unsigned long rate)
{
unsigned long step, mul_min, mul_max, rate_min, rate_max;
rate_max = clk_get_rate(clk->parent);
if (rate >= rate_max)
return rate_max;
step = DIV_ROUND_CLOSEST(rate_max, 32);
if (step >= rate)
return step;
mul_min = rate / step;
mul_max = DIV_ROUND_UP(rate, step);
rate_min = step * mul_min;
if (mul_max == mul_min)
return rate_min;
rate_max = step * mul_max;
if (rate_max - rate < rate - rate_min)
return rate_max;
return rate_min;
}
static unsigned long zclk_recalc(struct clk *clk)
{
void __iomem *frqcrc = FRQCRC - (u32)clk->enable_reg + clk->mapped_reg;
unsigned int max = clk->div_mask + 1;
unsigned long val = ((ioread32(frqcrc) >> clk->enable_bit) &
clk->div_mask);
return DIV_ROUND_CLOSEST(clk_get_rate(clk->parent), max) *
(max - val);
}
static void div4_kick(struct clk *clk)
{
if (!WARN(!atomic_inc_and_test(&frqcr_lock), "FRQCR* lock broken!\n"))
frqcr_kick_do(clk);
atomic_dec(&frqcr_lock);
}
void __init r8a73a4_clock_init(void)
{
void __iomem *reg;
int k, ret = 0;
u32 ckscr;
atomic_set(&frqcr_lock, -1);
reg = ioremap_nocache(CKSCR, PAGE_SIZE);
BUG_ON(!reg);
ckscr = ioread32(reg);
iounmap(reg);
switch ((ckscr >> 28) & 0x3) {
case 0:
main_clk.parent = &extal1_clk;
break;
case 1:
main_clk.parent = &extal1_div2_clk;
break;
case 2:
main_clk.parent = &extal2_clk;
break;
case 3:
main_clk.parent = &extal2_div2_clk;
break;
}
for (k = 0; !ret && (k < ARRAY_SIZE(main_clks)); k++)
ret = clk_register(main_clks[k]);
if (!ret)
ret = sh_clk_div4_register(div4_clks, DIV4_NR, &div4_table);
if (!ret)
ret = sh_clk_div6_reparent_register(div6_clks, DIV6_NR);
if (!ret)
ret = sh_clk_mstp_register(mstp_clks, MSTP_NR);
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
if (!ret)
shmobile_clk_init();
else
panic("failed to setup r8a73a4 clocks\n");
}
