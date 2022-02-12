static inline void cprman_write(struct bcm2835_cprman *cprman, u32 reg, u32 val)
{
writel(CM_PASSWORD | val, cprman->regs + reg);
}
static inline u32 cprman_read(struct bcm2835_cprman *cprman, u32 reg)
{
return readl(cprman->regs + reg);
}
void __init bcm2835_init_clocks(void)
{
struct clk *clk;
int ret;
clk = clk_register_fixed_rate(NULL, "apb_pclk", NULL, 0, 126000000);
if (IS_ERR(clk))
pr_err("apb_pclk not registered\n");
clk = clk_register_fixed_rate(NULL, "uart0_pclk", NULL, 0, 3000000);
if (IS_ERR(clk))
pr_err("uart0_pclk not registered\n");
ret = clk_register_clkdev(clk, NULL, "20201000.uart");
if (ret)
pr_err("uart0_pclk alias not registered\n");
clk = clk_register_fixed_rate(NULL, "uart1_pclk", NULL, 0, 125000000);
if (IS_ERR(clk))
pr_err("uart1_pclk not registered\n");
ret = clk_register_clkdev(clk, NULL, "20215000.uart");
if (ret)
pr_err("uart1_pclk alias not registered\n");
}
static int bcm2835_pll_is_on(struct clk_hw *hw)
{
struct bcm2835_pll *pll = container_of(hw, struct bcm2835_pll, hw);
struct bcm2835_cprman *cprman = pll->cprman;
const struct bcm2835_pll_data *data = pll->data;
return cprman_read(cprman, data->a2w_ctrl_reg) &
A2W_PLL_CTRL_PRST_DISABLE;
}
static void bcm2835_pll_choose_ndiv_and_fdiv(unsigned long rate,
unsigned long parent_rate,
u32 *ndiv, u32 *fdiv)
{
u64 div;
div = (u64)rate << A2W_PLL_FRAC_BITS;
do_div(div, parent_rate);
*ndiv = div >> A2W_PLL_FRAC_BITS;
*fdiv = div & ((1 << A2W_PLL_FRAC_BITS) - 1);
}
static long bcm2835_pll_rate_from_divisors(unsigned long parent_rate,
u32 ndiv, u32 fdiv, u32 pdiv)
{
u64 rate;
if (pdiv == 0)
return 0;
rate = (u64)parent_rate * ((ndiv << A2W_PLL_FRAC_BITS) + fdiv);
do_div(rate, pdiv);
return rate >> A2W_PLL_FRAC_BITS;
}
static long bcm2835_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
u32 ndiv, fdiv;
bcm2835_pll_choose_ndiv_and_fdiv(rate, *parent_rate, &ndiv, &fdiv);
return bcm2835_pll_rate_from_divisors(*parent_rate, ndiv, fdiv, 1);
}
static unsigned long bcm2835_pll_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct bcm2835_pll *pll = container_of(hw, struct bcm2835_pll, hw);
struct bcm2835_cprman *cprman = pll->cprman;
const struct bcm2835_pll_data *data = pll->data;
u32 a2wctrl = cprman_read(cprman, data->a2w_ctrl_reg);
u32 ndiv, pdiv, fdiv;
bool using_prediv;
if (parent_rate == 0)
return 0;
fdiv = cprman_read(cprman, data->frac_reg) & A2W_PLL_FRAC_MASK;
ndiv = (a2wctrl & A2W_PLL_CTRL_NDIV_MASK) >> A2W_PLL_CTRL_NDIV_SHIFT;
pdiv = (a2wctrl & A2W_PLL_CTRL_PDIV_MASK) >> A2W_PLL_CTRL_PDIV_SHIFT;
using_prediv = cprman_read(cprman, data->ana_reg_base + 4) &
data->ana->fb_prediv_mask;
if (using_prediv)
ndiv *= 2;
return bcm2835_pll_rate_from_divisors(parent_rate, ndiv, fdiv, pdiv);
}
static void bcm2835_pll_off(struct clk_hw *hw)
{
struct bcm2835_pll *pll = container_of(hw, struct bcm2835_pll, hw);
struct bcm2835_cprman *cprman = pll->cprman;
const struct bcm2835_pll_data *data = pll->data;
cprman_write(cprman, data->cm_ctrl_reg, CM_PLL_ANARST);
cprman_write(cprman, data->a2w_ctrl_reg, A2W_PLL_CTRL_PWRDN);
}
static int bcm2835_pll_on(struct clk_hw *hw)
{
struct bcm2835_pll *pll = container_of(hw, struct bcm2835_pll, hw);
struct bcm2835_cprman *cprman = pll->cprman;
const struct bcm2835_pll_data *data = pll->data;
ktime_t timeout;
cprman_write(cprman, data->cm_ctrl_reg,
cprman_read(cprman, data->cm_ctrl_reg) & ~CM_PLL_ANARST);
timeout = ktime_add_ns(ktime_get(), LOCK_TIMEOUT_NS);
while (!(cprman_read(cprman, CM_LOCK) & data->lock_mask)) {
if (ktime_after(ktime_get(), timeout)) {
dev_err(cprman->dev, "%s: couldn't lock PLL\n",
clk_hw_get_name(hw));
return -ETIMEDOUT;
}
cpu_relax();
}
return 0;
}
static void
bcm2835_pll_write_ana(struct bcm2835_cprman *cprman, u32 ana_reg_base, u32 *ana)
{
int i;
for (i = 3; i >= 0; i--)
cprman_write(cprman, ana_reg_base + i * 4, ana[i]);
}
static int bcm2835_pll_set_rate(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate)
{
struct bcm2835_pll *pll = container_of(hw, struct bcm2835_pll, hw);
struct bcm2835_cprman *cprman = pll->cprman;
const struct bcm2835_pll_data *data = pll->data;
bool was_using_prediv, use_fb_prediv, do_ana_setup_first;
u32 ndiv, fdiv, a2w_ctl;
u32 ana[4];
int i;
if (rate < data->min_rate || rate > data->max_rate) {
dev_err(cprman->dev, "%s: rate out of spec: %lu vs (%lu, %lu)\n",
clk_hw_get_name(hw), rate,
data->min_rate, data->max_rate);
return -EINVAL;
}
if (rate > data->max_fb_rate) {
use_fb_prediv = true;
rate /= 2;
} else {
use_fb_prediv = false;
}
bcm2835_pll_choose_ndiv_and_fdiv(rate, parent_rate, &ndiv, &fdiv);
for (i = 3; i >= 0; i--)
ana[i] = cprman_read(cprman, data->ana_reg_base + i * 4);
was_using_prediv = ana[1] & data->ana->fb_prediv_mask;
ana[0] &= ~data->ana->mask0;
ana[0] |= data->ana->set0;
ana[1] &= ~data->ana->mask1;
ana[1] |= data->ana->set1;
ana[3] &= ~data->ana->mask3;
ana[3] |= data->ana->set3;
if (was_using_prediv && !use_fb_prediv) {
ana[1] &= ~data->ana->fb_prediv_mask;
do_ana_setup_first = true;
} else if (!was_using_prediv && use_fb_prediv) {
ana[1] |= data->ana->fb_prediv_mask;
do_ana_setup_first = false;
} else {
do_ana_setup_first = true;
}
cprman_write(cprman, A2W_XOSC_CTRL,
cprman_read(cprman, A2W_XOSC_CTRL) |
data->reference_enable_mask);
if (do_ana_setup_first)
bcm2835_pll_write_ana(cprman, data->ana_reg_base, ana);
cprman_write(cprman, data->frac_reg, fdiv);
a2w_ctl = cprman_read(cprman, data->a2w_ctrl_reg);
a2w_ctl &= ~A2W_PLL_CTRL_NDIV_MASK;
a2w_ctl |= ndiv << A2W_PLL_CTRL_NDIV_SHIFT;
a2w_ctl &= ~A2W_PLL_CTRL_PDIV_MASK;
a2w_ctl |= 1 << A2W_PLL_CTRL_PDIV_SHIFT;
cprman_write(cprman, data->a2w_ctrl_reg, a2w_ctl);
if (!do_ana_setup_first)
bcm2835_pll_write_ana(cprman, data->ana_reg_base, ana);
return 0;
}
static struct bcm2835_pll_divider *
bcm2835_pll_divider_from_hw(struct clk_hw *hw)
{
return container_of(hw, struct bcm2835_pll_divider, div.hw);
}
static int bcm2835_pll_divider_is_on(struct clk_hw *hw)
{
struct bcm2835_pll_divider *divider = bcm2835_pll_divider_from_hw(hw);
struct bcm2835_cprman *cprman = divider->cprman;
const struct bcm2835_pll_divider_data *data = divider->data;
return !(cprman_read(cprman, data->a2w_reg) & A2W_PLL_CHANNEL_DISABLE);
}
static long bcm2835_pll_divider_round_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long *parent_rate)
{
return clk_divider_ops.round_rate(hw, rate, parent_rate);
}
static unsigned long bcm2835_pll_divider_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return clk_divider_ops.recalc_rate(hw, parent_rate);
}
static void bcm2835_pll_divider_off(struct clk_hw *hw)
{
struct bcm2835_pll_divider *divider = bcm2835_pll_divider_from_hw(hw);
struct bcm2835_cprman *cprman = divider->cprman;
const struct bcm2835_pll_divider_data *data = divider->data;
cprman_write(cprman, data->cm_reg,
(cprman_read(cprman, data->cm_reg) &
~data->load_mask) | data->hold_mask);
cprman_write(cprman, data->a2w_reg, A2W_PLL_CHANNEL_DISABLE);
}
static int bcm2835_pll_divider_on(struct clk_hw *hw)
{
struct bcm2835_pll_divider *divider = bcm2835_pll_divider_from_hw(hw);
struct bcm2835_cprman *cprman = divider->cprman;
const struct bcm2835_pll_divider_data *data = divider->data;
cprman_write(cprman, data->a2w_reg,
cprman_read(cprman, data->a2w_reg) &
~A2W_PLL_CHANNEL_DISABLE);
cprman_write(cprman, data->cm_reg,
cprman_read(cprman, data->cm_reg) & ~data->hold_mask);
return 0;
}
static int bcm2835_pll_divider_set_rate(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate)
{
struct bcm2835_pll_divider *divider = bcm2835_pll_divider_from_hw(hw);
struct bcm2835_cprman *cprman = divider->cprman;
const struct bcm2835_pll_divider_data *data = divider->data;
u32 cm, div, max_div = 1 << A2W_PLL_DIV_BITS;
div = DIV_ROUND_UP_ULL(parent_rate, rate);
div = min(div, max_div);
if (div == max_div)
div = 0;
cprman_write(cprman, data->a2w_reg, div);
cm = cprman_read(cprman, data->cm_reg);
cprman_write(cprman, data->cm_reg, cm | data->load_mask);
cprman_write(cprman, data->cm_reg, cm & ~data->load_mask);
return 0;
}
static struct bcm2835_clock *bcm2835_clock_from_hw(struct clk_hw *hw)
{
return container_of(hw, struct bcm2835_clock, hw);
}
static int bcm2835_clock_is_on(struct clk_hw *hw)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
return (cprman_read(cprman, data->ctl_reg) & CM_ENABLE) != 0;
}
static u32 bcm2835_clock_choose_div(struct clk_hw *hw,
unsigned long rate,
unsigned long parent_rate,
bool round_up)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
const struct bcm2835_clock_data *data = clock->data;
u32 unused_frac_mask =
GENMASK(CM_DIV_FRAC_BITS - data->frac_bits, 0) >> 1;
u64 temp = (u64)parent_rate << CM_DIV_FRAC_BITS;
u64 rem;
u32 div;
rem = do_div(temp, rate);
div = temp;
if (round_up && ((div & unused_frac_mask) != 0 || rem != 0))
div += unused_frac_mask + 1;
div &= ~unused_frac_mask;
div = max(div, unused_frac_mask + 1);
div = min_t(u32, div, GENMASK(data->int_bits + CM_DIV_FRAC_BITS - 1,
CM_DIV_FRAC_BITS - data->frac_bits));
return div;
}
static long bcm2835_clock_rate_from_divisor(struct bcm2835_clock *clock,
unsigned long parent_rate,
u32 div)
{
const struct bcm2835_clock_data *data = clock->data;
u64 temp;
div >>= CM_DIV_FRAC_BITS - data->frac_bits;
div &= (1 << (data->int_bits + data->frac_bits)) - 1;
if (div == 0)
return 0;
temp = (u64)parent_rate << data->frac_bits;
do_div(temp, div);
return temp;
}
static unsigned long bcm2835_clock_get_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
u32 div = cprman_read(cprman, data->div_reg);
return bcm2835_clock_rate_from_divisor(clock, parent_rate, div);
}
static void bcm2835_clock_wait_busy(struct bcm2835_clock *clock)
{
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
ktime_t timeout = ktime_add_ns(ktime_get(), LOCK_TIMEOUT_NS);
while (cprman_read(cprman, data->ctl_reg) & CM_BUSY) {
if (ktime_after(ktime_get(), timeout)) {
dev_err(cprman->dev, "%s: couldn't lock PLL\n",
clk_hw_get_name(&clock->hw));
return;
}
cpu_relax();
}
}
static void bcm2835_clock_off(struct clk_hw *hw)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
spin_lock(&cprman->regs_lock);
cprman_write(cprman, data->ctl_reg,
cprman_read(cprman, data->ctl_reg) & ~CM_ENABLE);
spin_unlock(&cprman->regs_lock);
bcm2835_clock_wait_busy(clock);
}
static int bcm2835_clock_on(struct clk_hw *hw)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
spin_lock(&cprman->regs_lock);
cprman_write(cprman, data->ctl_reg,
cprman_read(cprman, data->ctl_reg) |
CM_ENABLE |
CM_GATE);
spin_unlock(&cprman->regs_lock);
return 0;
}
static int bcm2835_clock_set_rate(struct clk_hw *hw,
unsigned long rate, unsigned long parent_rate)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
u32 div = bcm2835_clock_choose_div(hw, rate, parent_rate, false);
cprman_write(cprman, data->div_reg, div);
return 0;
}
static int bcm2835_clock_determine_rate(struct clk_hw *hw,
struct clk_rate_request *req)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct clk_hw *parent, *best_parent = NULL;
unsigned long rate, best_rate = 0;
unsigned long prate, best_prate = 0;
size_t i;
u32 div;
for (i = 0; i < clk_hw_get_num_parents(hw); ++i) {
parent = clk_hw_get_parent_by_index(hw, i);
if (!parent)
continue;
prate = clk_hw_get_rate(parent);
div = bcm2835_clock_choose_div(hw, req->rate, prate, true);
rate = bcm2835_clock_rate_from_divisor(clock, prate, div);
if (rate > best_rate && rate <= req->rate) {
best_parent = parent;
best_prate = prate;
best_rate = rate;
}
}
if (!best_parent)
return -EINVAL;
req->best_parent_hw = best_parent;
req->best_parent_rate = best_prate;
req->rate = best_rate;
return 0;
}
static int bcm2835_clock_set_parent(struct clk_hw *hw, u8 index)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
u8 src = (index << CM_SRC_SHIFT) & CM_SRC_MASK;
cprman_write(cprman, data->ctl_reg, src);
return 0;
}
static u8 bcm2835_clock_get_parent(struct clk_hw *hw)
{
struct bcm2835_clock *clock = bcm2835_clock_from_hw(hw);
struct bcm2835_cprman *cprman = clock->cprman;
const struct bcm2835_clock_data *data = clock->data;
u32 src = cprman_read(cprman, data->ctl_reg);
return (src & CM_SRC_MASK) >> CM_SRC_SHIFT;
}
static int bcm2835_vpu_clock_is_on(struct clk_hw *hw)
{
return true;
}
static struct clk *bcm2835_register_pll(struct bcm2835_cprman *cprman,
const struct bcm2835_pll_data *data)
{
struct bcm2835_pll *pll;
struct clk_init_data init;
memset(&init, 0, sizeof(init));
init.parent_names = &cprman->osc_name;
init.num_parents = 1;
init.name = data->name;
init.ops = &bcm2835_pll_clk_ops;
init.flags = CLK_IGNORE_UNUSED;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return NULL;
pll->cprman = cprman;
pll->data = data;
pll->hw.init = &init;
return devm_clk_register(cprman->dev, &pll->hw);
}
static struct clk *
bcm2835_register_pll_divider(struct bcm2835_cprman *cprman,
const struct bcm2835_pll_divider_data *data)
{
struct bcm2835_pll_divider *divider;
struct clk_init_data init;
struct clk *clk;
const char *divider_name;
if (data->fixed_divider != 1) {
divider_name = devm_kasprintf(cprman->dev, GFP_KERNEL,
"%s_prediv", data->name);
if (!divider_name)
return NULL;
} else {
divider_name = data->name;
}
memset(&init, 0, sizeof(init));
init.parent_names = &data->source_pll->name;
init.num_parents = 1;
init.name = divider_name;
init.ops = &bcm2835_pll_divider_clk_ops;
init.flags = CLK_SET_RATE_PARENT | CLK_IGNORE_UNUSED;
divider = devm_kzalloc(cprman->dev, sizeof(*divider), GFP_KERNEL);
if (!divider)
return NULL;
divider->div.reg = cprman->regs + data->a2w_reg;
divider->div.shift = A2W_PLL_DIV_SHIFT;
divider->div.width = A2W_PLL_DIV_BITS;
divider->div.flags = CLK_DIVIDER_MAX_AT_ZERO;
divider->div.lock = &cprman->regs_lock;
divider->div.hw.init = &init;
divider->div.table = NULL;
divider->cprman = cprman;
divider->data = data;
clk = devm_clk_register(cprman->dev, &divider->div.hw);
if (IS_ERR(clk))
return clk;
if (data->fixed_divider != 1) {
return clk_register_fixed_factor(cprman->dev, data->name,
divider_name,
CLK_SET_RATE_PARENT,
1,
data->fixed_divider);
}
return clk;
}
static struct clk *bcm2835_register_clock(struct bcm2835_cprman *cprman,
const struct bcm2835_clock_data *data)
{
struct bcm2835_clock *clock;
struct clk_init_data init;
const char *parents[1 << CM_SRC_BITS];
size_t i;
for (i = 0; i < data->num_mux_parents; i++) {
if (strcmp(data->parents[i], "xosc") == 0)
parents[i] = cprman->osc_name;
else
parents[i] = data->parents[i];
}
memset(&init, 0, sizeof(init));
init.parent_names = parents;
init.num_parents = data->num_mux_parents;
init.name = data->name;
init.flags = CLK_IGNORE_UNUSED;
if (data->is_vpu_clock) {
init.ops = &bcm2835_vpu_clock_clk_ops;
} else {
init.ops = &bcm2835_clock_clk_ops;
init.flags |= CLK_SET_RATE_GATE | CLK_SET_PARENT_GATE;
}
clock = devm_kzalloc(cprman->dev, sizeof(*clock), GFP_KERNEL);
if (!clock)
return NULL;
clock->cprman = cprman;
clock->data = data;
clock->hw.init = &init;
return devm_clk_register(cprman->dev, &clock->hw);
}
static int bcm2835_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct clk **clks;
struct bcm2835_cprman *cprman;
struct resource *res;
cprman = devm_kzalloc(dev, sizeof(*cprman), GFP_KERNEL);
if (!cprman)
return -ENOMEM;
spin_lock_init(&cprman->regs_lock);
cprman->dev = dev;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
cprman->regs = devm_ioremap_resource(dev, res);
if (IS_ERR(cprman->regs))
return PTR_ERR(cprman->regs);
cprman->osc_name = of_clk_get_parent_name(dev->of_node, 0);
if (!cprman->osc_name)
return -ENODEV;
platform_set_drvdata(pdev, cprman);
cprman->onecell.clk_num = BCM2835_CLOCK_COUNT;
cprman->onecell.clks = cprman->clks;
clks = cprman->clks;
clks[BCM2835_PLLA] = bcm2835_register_pll(cprman, &bcm2835_plla_data);
clks[BCM2835_PLLB] = bcm2835_register_pll(cprman, &bcm2835_pllb_data);
clks[BCM2835_PLLC] = bcm2835_register_pll(cprman, &bcm2835_pllc_data);
clks[BCM2835_PLLD] = bcm2835_register_pll(cprman, &bcm2835_plld_data);
clks[BCM2835_PLLH] = bcm2835_register_pll(cprman, &bcm2835_pllh_data);
clks[BCM2835_PLLA_CORE] =
bcm2835_register_pll_divider(cprman, &bcm2835_plla_core_data);
clks[BCM2835_PLLA_PER] =
bcm2835_register_pll_divider(cprman, &bcm2835_plla_per_data);
clks[BCM2835_PLLC_CORE0] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllc_core0_data);
clks[BCM2835_PLLC_CORE1] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllc_core1_data);
clks[BCM2835_PLLC_CORE2] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllc_core2_data);
clks[BCM2835_PLLC_PER] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllc_per_data);
clks[BCM2835_PLLD_CORE] =
bcm2835_register_pll_divider(cprman, &bcm2835_plld_core_data);
clks[BCM2835_PLLD_PER] =
bcm2835_register_pll_divider(cprman, &bcm2835_plld_per_data);
clks[BCM2835_PLLH_RCAL] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllh_rcal_data);
clks[BCM2835_PLLH_AUX] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllh_aux_data);
clks[BCM2835_PLLH_PIX] =
bcm2835_register_pll_divider(cprman, &bcm2835_pllh_pix_data);
clks[BCM2835_CLOCK_TIMER] =
bcm2835_register_clock(cprman, &bcm2835_clock_timer_data);
clks[BCM2835_CLOCK_OTP] =
bcm2835_register_clock(cprman, &bcm2835_clock_otp_data);
clks[BCM2835_CLOCK_TSENS] =
bcm2835_register_clock(cprman, &bcm2835_clock_tsens_data);
clks[BCM2835_CLOCK_VPU] =
bcm2835_register_clock(cprman, &bcm2835_clock_vpu_data);
clks[BCM2835_CLOCK_V3D] =
bcm2835_register_clock(cprman, &bcm2835_clock_v3d_data);
clks[BCM2835_CLOCK_ISP] =
bcm2835_register_clock(cprman, &bcm2835_clock_isp_data);
clks[BCM2835_CLOCK_H264] =
bcm2835_register_clock(cprman, &bcm2835_clock_h264_data);
clks[BCM2835_CLOCK_V3D] =
bcm2835_register_clock(cprman, &bcm2835_clock_v3d_data);
clks[BCM2835_CLOCK_SDRAM] =
bcm2835_register_clock(cprman, &bcm2835_clock_sdram_data);
clks[BCM2835_CLOCK_UART] =
bcm2835_register_clock(cprman, &bcm2835_clock_uart_data);
clks[BCM2835_CLOCK_VEC] =
bcm2835_register_clock(cprman, &bcm2835_clock_vec_data);
clks[BCM2835_CLOCK_HSM] =
bcm2835_register_clock(cprman, &bcm2835_clock_hsm_data);
clks[BCM2835_CLOCK_EMMC] =
bcm2835_register_clock(cprman, &bcm2835_clock_emmc_data);
clks[BCM2835_CLOCK_PERI_IMAGE] =
clk_register_gate(dev, "peri_image", "vpu",
CLK_IGNORE_UNUSED | CLK_SET_RATE_GATE,
cprman->regs + CM_PERIICTL, CM_GATE_BIT,
0, &cprman->regs_lock);
clks[BCM2835_CLOCK_PWM] =
bcm2835_register_clock(cprman, &bcm2835_clock_pwm_data);
return of_clk_add_provider(dev->of_node, of_clk_src_onecell_get,
&cprman->onecell);
}
