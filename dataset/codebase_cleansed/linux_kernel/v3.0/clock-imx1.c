static int _clk_enable(struct clk *clk)
{
unsigned int reg;
reg = __raw_readl(clk->enable_reg);
reg |= 1 << clk->enable_shift;
__raw_writel(reg, clk->enable_reg);
return 0;
}
static void _clk_disable(struct clk *clk)
{
unsigned int reg;
reg = __raw_readl(clk->enable_reg);
reg &= ~(1 << clk->enable_shift);
__raw_writel(reg, clk->enable_reg);
}
static int _clk_can_use_parent(const struct clk *clk_arr[], unsigned int size,
struct clk *parent)
{
int i;
for (i = 0; i < size; i++)
if (parent == clk_arr[i])
return i;
return -EINVAL;
}
static unsigned long
_clk_simple_round_rate(struct clk *clk, unsigned long rate, unsigned int limit)
{
int div;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (parent_rate % rate)
div++;
if (div > limit)
div = limit;
return parent_rate / div;
}
static unsigned long _clk_parent_round_rate(struct clk *clk, unsigned long rate)
{
return clk->parent->round_rate(clk->parent, rate);
}
static int _clk_parent_set_rate(struct clk *clk, unsigned long rate)
{
return clk->parent->set_rate(clk->parent, rate);
}
static unsigned long clk16m_get_rate(struct clk *clk)
{
return 16000000;
}
static unsigned long clk32_get_rate(struct clk *clk)
{
return clk32_rate;
}
static unsigned long clk32_premult_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) * 512;
}
static int prem_clk_set_parent(struct clk *clk, struct clk *parent)
{
int i;
unsigned int reg = __raw_readl(CCM_CSCR);
i = _clk_can_use_parent(prem_clk_clocks, ARRAY_SIZE(prem_clk_clocks),
parent);
switch (i) {
case 0:
reg &= ~CCM_CSCR_SYSTEM_SEL;
break;
case 1:
reg |= CCM_CSCR_SYSTEM_SEL;
break;
default:
return i;
}
__raw_writel(reg, CCM_CSCR);
return 0;
}
static unsigned long system_clk_get_rate(struct clk *clk)
{
return mxc_decode_pll(__raw_readl(CCM_SPCTL0),
clk_get_rate(clk->parent));
}
static unsigned long mcu_clk_get_rate(struct clk *clk)
{
return mxc_decode_pll(__raw_readl(CCM_MPCTL0),
clk_get_rate(clk->parent));
}
static unsigned long fclk_get_rate(struct clk *clk)
{
unsigned long fclk = clk_get_rate(clk->parent);
if (__raw_readl(CCM_CSCR) & CCM_CSCR_PRESC)
fclk /= 2;
return fclk;
}
static unsigned long hclk_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / (((__raw_readl(CCM_CSCR) &
CCM_CSCR_BCLK_MASK) >> CCM_CSCR_BCLK_OFFSET) + 1);
}
static unsigned long hclk_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_simple_round_rate(clk, rate, 16);
}
static int hclk_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int div;
unsigned int reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 16 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_CSCR);
reg &= ~CCM_CSCR_BCLK_MASK;
reg |= div << CCM_CSCR_BCLK_OFFSET;
__raw_writel(reg, CCM_CSCR);
return 0;
}
static unsigned long clk48m_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / (((__raw_readl(CCM_CSCR) &
CCM_CSCR_USB_MASK) >> CCM_CSCR_USB_OFFSET) + 1);
}
static unsigned long clk48m_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_simple_round_rate(clk, rate, 8);
}
static int clk48m_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int div;
unsigned int reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 8 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_CSCR);
reg &= ~CCM_CSCR_USB_MASK;
reg |= div << CCM_CSCR_USB_OFFSET;
__raw_writel(reg, CCM_CSCR);
return 0;
}
static unsigned long perclk1_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / (((__raw_readl(CCM_PCDR) &
CCM_PCDR_PCLK1_MASK) >> CCM_PCDR_PCLK1_OFFSET) + 1);
}
static unsigned long perclk1_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_simple_round_rate(clk, rate, 16);
}
static int perclk1_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int div;
unsigned int reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 16 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_PCDR);
reg &= ~CCM_PCDR_PCLK1_MASK;
reg |= div << CCM_PCDR_PCLK1_OFFSET;
__raw_writel(reg, CCM_PCDR);
return 0;
}
static unsigned long perclk2_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / (((__raw_readl(CCM_PCDR) &
CCM_PCDR_PCLK2_MASK) >> CCM_PCDR_PCLK2_OFFSET) + 1);
}
static unsigned long perclk2_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_simple_round_rate(clk, rate, 16);
}
static int perclk2_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int div;
unsigned int reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 16 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_PCDR);
reg &= ~CCM_PCDR_PCLK2_MASK;
reg |= div << CCM_PCDR_PCLK2_OFFSET;
__raw_writel(reg, CCM_PCDR);
return 0;
}
static unsigned long perclk3_get_rate(struct clk *clk)
{
return clk_get_rate(clk->parent) / (((__raw_readl(CCM_PCDR) &
CCM_PCDR_PCLK3_MASK) >> CCM_PCDR_PCLK3_OFFSET) + 1);
}
static unsigned long perclk3_round_rate(struct clk *clk, unsigned long rate)
{
return _clk_simple_round_rate(clk, rate, 128);
}
static int perclk3_set_rate(struct clk *clk, unsigned long rate)
{
unsigned int div;
unsigned int reg;
unsigned long parent_rate;
parent_rate = clk_get_rate(clk->parent);
div = parent_rate / rate;
if (div > 128 || div < 1 || ((parent_rate / div) != rate))
return -EINVAL;
div--;
reg = __raw_readl(CCM_PCDR);
reg &= ~CCM_PCDR_PCLK3_MASK;
reg |= div << CCM_PCDR_PCLK3_OFFSET;
__raw_writel(reg, CCM_PCDR);
return 0;
}
static int clko_set_parent(struct clk *clk, struct clk *parent)
{
int i;
unsigned int reg;
i = _clk_can_use_parent(clko_clocks, ARRAY_SIZE(clko_clocks), parent);
if (i < 0)
return i;
reg = __raw_readl(CCM_CSCR) & ~CCM_CSCR_CLKO_MASK;
reg |= i << CCM_CSCR_CLKO_OFFSET;
__raw_writel(reg, CCM_CSCR);
if (clko_clocks[i]->set_rate && clko_clocks[i]->round_rate) {
clk->set_rate = _clk_parent_set_rate;
clk->round_rate = _clk_parent_round_rate;
} else {
clk->set_rate = NULL;
clk->round_rate = NULL;
}
return 0;
}
int __init mx1_clocks_init(unsigned long fref)
{
unsigned int reg;
__raw_writel(0, SCM_GCCR);
clk32_rate = fref;
reg = __raw_readl(CCM_CSCR);
if (reg & CCM_CSCR_SYSTEM_SEL) {
prem_clk.parent = &clk16m;
} else {
reg &= ~(1 << CCM_CSCR_OSC_EN_SHIFT);
__raw_writel(reg, CCM_CSCR);
prem_clk.parent = &clk32_premult;
}
reg = (reg & CCM_CSCR_CLKO_MASK) >> CCM_CSCR_CLKO_OFFSET;
clko_clk.parent = (struct clk *)clko_clocks[reg];
clkdev_add_table(lookups, ARRAY_SIZE(lookups));
clk_enable(&hclk);
clk_enable(&fclk);
mxc_timer_init(&gpt_clk, MX1_IO_ADDRESS(MX1_TIM1_BASE_ADDR),
MX1_TIM1_INT);
return 0;
}
