static void vt8500_pmc_wait_busy(void)
{
while (readl(pmc_base) & VT8500_PMC_BUSY_MASK)
cpu_relax();
}
static int vt8500_dclk_enable(struct clk_hw *hw)
{
struct clk_device *cdev = to_clk_device(hw);
u32 en_val;
unsigned long flags = 0;
spin_lock_irqsave(cdev->lock, flags);
en_val = readl(cdev->en_reg);
en_val |= BIT(cdev->en_bit);
writel(en_val, cdev->en_reg);
spin_unlock_irqrestore(cdev->lock, flags);
return 0;
}
static void vt8500_dclk_disable(struct clk_hw *hw)
{
struct clk_device *cdev = to_clk_device(hw);
u32 en_val;
unsigned long flags = 0;
spin_lock_irqsave(cdev->lock, flags);
en_val = readl(cdev->en_reg);
en_val &= ~BIT(cdev->en_bit);
writel(en_val, cdev->en_reg);
spin_unlock_irqrestore(cdev->lock, flags);
}
static int vt8500_dclk_is_enabled(struct clk_hw *hw)
{
struct clk_device *cdev = to_clk_device(hw);
u32 en_val = (readl(cdev->en_reg) & BIT(cdev->en_bit));
return en_val ? 1 : 0;
}
static unsigned long vt8500_dclk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_device *cdev = to_clk_device(hw);
u32 div = readl(cdev->div_reg) & cdev->div_mask;
if ((cdev->div_mask == 0x3F) && (div & BIT(5)))
div = 64 * (div & 0x1f);
if (div == 0)
div = (cdev->div_mask + 1);
return parent_rate / div;
}
static long vt8500_dclk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_device *cdev = to_clk_device(hw);
u32 divisor = *prate / rate;
if ((cdev->div_mask == 0x3F) && (divisor > 31)) {
divisor = 64 * ((divisor / 64) + 1);
}
return *prate / divisor;
}
static int vt8500_dclk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_device *cdev = to_clk_device(hw);
u32 divisor = parent_rate / rate;
unsigned long flags = 0;
if (divisor == cdev->div_mask + 1)
divisor = 0;
if ((cdev->div_mask == 0x3F) && (divisor > 31)) {
divisor = 0x20 + (divisor / 64);
}
if (divisor > cdev->div_mask) {
pr_err("%s: invalid divisor for clock\n", __func__);
return -EINVAL;
}
spin_lock_irqsave(cdev->lock, flags);
vt8500_pmc_wait_busy();
writel(divisor, cdev->div_reg);
vt8500_pmc_wait_busy();
spin_lock_irqsave(cdev->lock, flags);
return 0;
}
static __init void vtwm_device_clk_init(struct device_node *node)
{
u32 en_reg, div_reg;
struct clk *clk;
struct clk_device *dev_clk;
const char *clk_name = node->name;
const char *parent_name;
struct clk_init_data init;
int rc;
int clk_init_flags = 0;
dev_clk = kzalloc(sizeof(*dev_clk), GFP_KERNEL);
if (WARN_ON(!dev_clk))
return;
dev_clk->lock = &_lock;
rc = of_property_read_u32(node, "enable-reg", &en_reg);
if (!rc) {
dev_clk->en_reg = pmc_base + en_reg;
rc = of_property_read_u32(node, "enable-bit", &dev_clk->en_bit);
if (rc) {
pr_err("%s: enable-bit property required for gated clock\n",
__func__);
return;
}
clk_init_flags |= CLK_INIT_GATED;
}
rc = of_property_read_u32(node, "divisor-reg", &div_reg);
if (!rc) {
dev_clk->div_reg = pmc_base + div_reg;
dev_clk->div_mask = 0x1f;
of_property_read_u32(node, "divisor-mask", &dev_clk->div_mask);
clk_init_flags |= CLK_INIT_DIVISOR;
}
of_property_read_string(node, "clock-output-names", &clk_name);
switch (clk_init_flags) {
case CLK_INIT_GATED:
init.ops = &vt8500_gated_clk_ops;
break;
case CLK_INIT_DIVISOR:
init.ops = &vt8500_divisor_clk_ops;
break;
case CLK_INIT_GATED_DIVISOR:
init.ops = &vt8500_gated_divisor_clk_ops;
break;
default:
pr_err("%s: Invalid clock description in device tree\n",
__func__);
kfree(dev_clk);
return;
}
init.name = clk_name;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = &parent_name;
init.num_parents = 1;
dev_clk->hw.init = &init;
clk = clk_register(NULL, &dev_clk->hw);
if (WARN_ON(IS_ERR(clk))) {
kfree(dev_clk);
return;
}
rc = of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
static void vt8500_find_pll_bits(unsigned long rate, unsigned long parent_rate,
u32 *multiplier, u32 *prediv)
{
unsigned long tclk;
if ((rate < parent_rate * 4) || (rate > parent_rate * 62)) {
pr_err("%s: requested rate out of range\n", __func__);
*multiplier = 0;
*prediv = 1;
return;
}
if (rate <= parent_rate * 31)
*prediv = 2;
else
*prediv = 1;
*multiplier = rate / (parent_rate / *prediv);
tclk = (parent_rate / *prediv) * *multiplier;
if (tclk != rate)
pr_warn("%s: requested rate %lu, found rate %lu\n", __func__,
rate, tclk);
}
static void wm8650_find_pll_bits(unsigned long rate, unsigned long parent_rate,
u32 *multiplier, u32 *divisor1, u32 *divisor2)
{
u32 mul, div1, div2;
u32 best_mul, best_div1, best_div2;
unsigned long tclk, rate_err, best_err;
best_err = (unsigned long)-1;
for (div1 = 5; div1 >= 3; div1--)
for (div2 = 3; div2 >= 0; div2--)
for (mul = 3; mul <= 1023; mul++) {
tclk = parent_rate * mul / (div1 * (1 << div2));
if (tclk > rate)
continue;
rate_err = rate - tclk;
if (rate_err == 0) {
*multiplier = mul;
*divisor1 = div1;
*divisor2 = div2;
return;
}
if (rate_err < best_err) {
best_err = rate_err;
best_mul = mul;
best_div1 = div1;
best_div2 = div2;
}
}
pr_warn("%s: requested rate %lu, found rate %lu\n", __func__, rate,
rate - best_err);
*multiplier = mul;
*divisor1 = div1;
*divisor2 = div2;
}
static int vtwm_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_pll *pll = to_clk_pll(hw);
u32 mul, div1, div2;
u32 pll_val;
unsigned long flags = 0;
switch (pll->type) {
case PLL_TYPE_VT8500:
vt8500_find_pll_bits(rate, parent_rate, &mul, &div1);
pll_val = VT8500_BITS_TO_VAL(mul, div1);
break;
case PLL_TYPE_WM8650:
wm8650_find_pll_bits(rate, parent_rate, &mul, &div1, &div2);
pll_val = WM8650_BITS_TO_VAL(mul, div1, div2);
break;
default:
pr_err("%s: invalid pll type\n", __func__);
return 0;
}
spin_lock_irqsave(pll->lock, flags);
vt8500_pmc_wait_busy();
writel(pll_val, pll->reg);
vt8500_pmc_wait_busy();
spin_unlock_irqrestore(pll->lock, flags);
return 0;
}
static long vtwm_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_pll *pll = to_clk_pll(hw);
u32 mul, div1, div2;
long round_rate;
switch (pll->type) {
case PLL_TYPE_VT8500:
vt8500_find_pll_bits(rate, *prate, &mul, &div1);
round_rate = VT8500_BITS_TO_FREQ(*prate, mul, div1);
break;
case PLL_TYPE_WM8650:
wm8650_find_pll_bits(rate, *prate, &mul, &div1, &div2);
round_rate = WM8650_BITS_TO_FREQ(*prate, mul, div1, div2);
break;
default:
round_rate = 0;
}
return round_rate;
}
static unsigned long vtwm_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_pll *pll = to_clk_pll(hw);
u32 pll_val = readl(pll->reg);
unsigned long pll_freq;
switch (pll->type) {
case PLL_TYPE_VT8500:
pll_freq = parent_rate * VT8500_PLL_MUL(pll_val);
pll_freq /= VT8500_PLL_DIV(pll_val);
break;
case PLL_TYPE_WM8650:
pll_freq = parent_rate * WM8650_PLL_MUL(pll_val);
pll_freq /= WM8650_PLL_DIV(pll_val);
break;
default:
pll_freq = 0;
}
return pll_freq;
}
static __init void vtwm_pll_clk_init(struct device_node *node, int pll_type)
{
u32 reg;
struct clk *clk;
struct clk_pll *pll_clk;
const char *clk_name = node->name;
const char *parent_name;
struct clk_init_data init;
int rc;
rc = of_property_read_u32(node, "reg", &reg);
if (WARN_ON(rc))
return;
pll_clk = kzalloc(sizeof(*pll_clk), GFP_KERNEL);
if (WARN_ON(!pll_clk))
return;
pll_clk->reg = pmc_base + reg;
pll_clk->lock = &_lock;
pll_clk->type = pll_type;
of_property_read_string(node, "clock-output-names", &clk_name);
init.name = clk_name;
init.ops = &vtwm_pll_ops;
init.flags = 0;
parent_name = of_clk_get_parent_name(node, 0);
init.parent_names = &parent_name;
init.num_parents = 1;
pll_clk->hw.init = &init;
clk = clk_register(NULL, &pll_clk->hw);
if (WARN_ON(IS_ERR(clk))) {
kfree(pll_clk);
return;
}
rc = of_clk_add_provider(node, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
}
static void __init vt8500_pll_init(struct device_node *node)
{
vtwm_pll_clk_init(node, PLL_TYPE_VT8500);
}
static void __init wm8650_pll_init(struct device_node *node)
{
vtwm_pll_clk_init(node, PLL_TYPE_WM8650);
}
void __init vtwm_clk_init(void __iomem *base)
{
if (!base)
return;
pmc_base = base;
of_clk_init(clk_match);
}
