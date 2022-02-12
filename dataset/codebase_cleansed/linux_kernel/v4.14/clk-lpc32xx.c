static inline bool pll_is_valid(u64 val0, u64 val1, u64 min, u64 max)
{
return (val0 >= (val1 * min) && val0 <= (val1 * max));
}
static inline u32 lpc32xx_usb_clk_read(struct lpc32xx_usb_clk *clk)
{
return readl(usb_clk_vbase + LPC32XX_USB_CLK_STS);
}
static inline void lpc32xx_usb_clk_write(struct lpc32xx_usb_clk *clk, u32 val)
{
writel(val, usb_clk_vbase + LPC32XX_USB_CLK_CTRL);
}
static int clk_mask_enable(struct clk_hw *hw)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val;
regmap_read(clk_regmap, clk->reg, &val);
if (clk->busy_mask && (val & clk->busy_mask) == clk->busy)
return -EBUSY;
return regmap_update_bits(clk_regmap, clk->reg,
clk->enable_mask, clk->enable);
}
static void clk_mask_disable(struct clk_hw *hw)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
regmap_update_bits(clk_regmap, clk->reg,
clk->disable_mask, clk->disable);
}
static int clk_mask_is_enabled(struct clk_hw *hw)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val;
regmap_read(clk_regmap, clk->reg, &val);
return ((val & clk->enable_mask) == clk->enable);
}
static int clk_pll_enable(struct clk_hw *hw)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
u32 val, count;
regmap_update_bits(clk_regmap, clk->reg, clk->enable, clk->enable);
for (count = 0; count < 1000; count++) {
regmap_read(clk_regmap, clk->reg, &val);
if (val & PLL_CTRL_LOCK)
break;
}
if (val & PLL_CTRL_LOCK)
return 0;
return -ETIMEDOUT;
}
static void clk_pll_disable(struct clk_hw *hw)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
regmap_update_bits(clk_regmap, clk->reg, clk->enable, 0x0);
}
static int clk_pll_is_enabled(struct clk_hw *hw)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
u32 val;
regmap_read(clk_regmap, clk->reg, &val);
val &= clk->enable | PLL_CTRL_LOCK;
if (val == (clk->enable | PLL_CTRL_LOCK))
return 1;
return 0;
}
static unsigned long clk_pll_397x_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return parent_rate * 397;
}
static unsigned long clk_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
bool is_direct, is_bypass, is_feedback;
unsigned long rate, cco_rate, ref_rate;
u32 val;
regmap_read(clk_regmap, clk->reg, &val);
is_direct = val & PLL_CTRL_DIRECT;
is_bypass = val & PLL_CTRL_BYPASS;
is_feedback = val & PLL_CTRL_FEEDBACK;
clk->m_div = ((val & PLL_CTRL_FEEDDIV) >> 1) + 1;
clk->n_div = ((val & PLL_CTRL_PREDIV) >> 9) + 1;
clk->p_div = ((val & PLL_CTRL_POSTDIV) >> 11) + 1;
if (is_direct && is_bypass) {
clk->p_div = 0;
clk->mode = PLL_DIRECT_BYPASS;
return parent_rate;
}
if (is_bypass) {
clk->mode = PLL_BYPASS;
return parent_rate / (1 << clk->p_div);
}
if (is_direct) {
clk->p_div = 0;
clk->mode = PLL_DIRECT;
}
ref_rate = parent_rate / clk->n_div;
rate = cco_rate = ref_rate * clk->m_div;
if (!is_direct) {
if (is_feedback) {
cco_rate *= (1 << clk->p_div);
clk->mode = PLL_INTEGER;
} else {
rate /= (1 << clk->p_div);
clk->mode = PLL_NON_INTEGER;
}
}
pr_debug("%s: %lu: 0x%x: %d/%d/%d, %lu/%lu/%d => %lu\n",
clk_hw_get_name(hw),
parent_rate, val, is_direct, is_bypass, is_feedback,
clk->n_div, clk->m_div, (1 << clk->p_div), rate);
if (clk_pll_is_enabled(hw) &&
!(pll_is_valid(parent_rate, 1, 1000000, 20000000)
&& pll_is_valid(cco_rate, 1, 156000000, 320000000)
&& pll_is_valid(ref_rate, 1, 1000000, 27000000)))
pr_err("%s: PLL clocks are not in valid ranges: %lu/%lu/%lu",
clk_hw_get_name(hw),
parent_rate, cco_rate, ref_rate);
return rate;
}
static int clk_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
u32 val;
unsigned long new_rate;
switch (clk->mode) {
case PLL_DIRECT:
val = PLL_CTRL_DIRECT;
val |= (clk->m_div - 1) << 1;
val |= (clk->n_div - 1) << 9;
new_rate = (parent_rate * clk->m_div) / clk->n_div;
break;
case PLL_BYPASS:
val = PLL_CTRL_BYPASS;
val |= (clk->p_div - 1) << 11;
new_rate = parent_rate / (1 << (clk->p_div));
break;
case PLL_DIRECT_BYPASS:
val = PLL_CTRL_DIRECT | PLL_CTRL_BYPASS;
new_rate = parent_rate;
break;
case PLL_INTEGER:
val = PLL_CTRL_FEEDBACK;
val |= (clk->m_div - 1) << 1;
val |= (clk->n_div - 1) << 9;
val |= (clk->p_div - 1) << 11;
new_rate = (parent_rate * clk->m_div) / clk->n_div;
break;
case PLL_NON_INTEGER:
val = 0x0;
val |= (clk->m_div - 1) << 1;
val |= (clk->n_div - 1) << 9;
val |= (clk->p_div - 1) << 11;
new_rate = (parent_rate * clk->m_div) /
(clk->n_div * (1 << clk->p_div));
break;
default:
return -EINVAL;
}
if (new_rate != rate)
return -EINVAL;
return regmap_update_bits(clk_regmap, clk->reg, 0x1FFFF, val);
}
static long clk_hclk_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
u64 m_i, o = rate, i = *parent_rate, d = (u64)rate << 6;
u64 m = 0, n = 0, p = 0;
int p_i, n_i;
pr_debug("%s: %lu/%lu\n", clk_hw_get_name(hw), *parent_rate, rate);
if (rate > 266500000)
return -EINVAL;
for (p_i = 4; p_i >= 0; p_i--) {
for (n_i = 4; n_i > 0; n_i--) {
m_i = div64_u64(o * n_i * (1 << p_i), i);
if (!(m_i && m_i <= 256
&& pll_is_valid(i, n_i, 1000000, 27000000)
&& pll_is_valid(i * m_i * (1 << p_i), n_i,
156000000, 320000000)))
continue;
if (o * n_i * (1 << p_i) - i * m_i <= d) {
m = m_i;
n = n_i;
p = p_i;
d = o * n_i * (1 << p_i) - i * m_i;
}
}
}
if (d == (u64)rate << 6) {
pr_err("%s: %lu: no valid PLL parameters are found\n",
clk_hw_get_name(hw), rate);
return -EINVAL;
}
clk->m_div = m;
clk->n_div = n;
clk->p_div = p;
if (!p)
clk->mode = PLL_DIRECT;
else
clk->mode = PLL_NON_INTEGER;
o = div64_u64(i * m, n * (1 << p));
if (!d)
pr_debug("%s: %lu: found exact match: %llu/%llu/%llu\n",
clk_hw_get_name(hw), rate, m, n, p);
else
pr_debug("%s: %lu: found closest: %llu/%llu/%llu - %llu\n",
clk_hw_get_name(hw), rate, m, n, p, o);
return o;
}
static long clk_usb_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
struct lpc32xx_pll_clk *clk = to_lpc32xx_pll_clk(hw);
struct clk_hw *usb_div_hw, *osc_hw;
u64 d_i, n_i, m, o;
pr_debug("%s: %lu/%lu\n", clk_hw_get_name(hw), *parent_rate, rate);
if (rate != 48000000)
return -EINVAL;
usb_div_hw = clk_hw_get_parent_by_index(hw, 0);
if (!usb_div_hw)
return -EINVAL;
osc_hw = clk_hw_get_parent_by_index(usb_div_hw, 0);
if (!osc_hw)
return -EINVAL;
o = clk_hw_get_rate(osc_hw);
for (d_i = 16; d_i >= 1; d_i--) {
for (n_i = 1; n_i <= 4; n_i++) {
m = div64_u64(192000000 * d_i * n_i, o);
if (!(m && m <= 256
&& m * o == 192000000 * d_i * n_i
&& pll_is_valid(o, d_i, 1000000, 20000000)
&& pll_is_valid(o, d_i * n_i, 1000000, 27000000)))
continue;
clk->n_div = n_i;
clk->m_div = m;
clk->p_div = 2;
clk->mode = PLL_NON_INTEGER;
*parent_rate = div64_u64(o, d_i);
return rate;
}
}
return -EINVAL;
}
static int clk_ddram_is_enabled(struct clk_hw *hw)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val;
regmap_read(clk_regmap, clk->reg, &val);
val &= clk->enable_mask | clk->busy_mask;
return (val == (BIT(7) | BIT(0)) ||
val == (BIT(8) | BIT(1)));
}
static int clk_ddram_enable(struct clk_hw *hw)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val, hclk_div;
regmap_read(clk_regmap, clk->reg, &val);
hclk_div = val & clk->busy_mask;
if (hclk_div == 0x0 || hclk_div == (BIT(1) | BIT(0)))
return -EINVAL;
return regmap_update_bits(clk_regmap, clk->reg,
clk->enable_mask, hclk_div << 7);
}
static unsigned long clk_ddram_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val;
if (!clk_ddram_is_enabled(hw))
return 0;
regmap_read(clk_regmap, clk->reg, &val);
val &= clk->enable_mask;
return parent_rate / (val >> 7);
}
static unsigned long lpc32xx_clk_uart_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc32xx_clk *clk = to_lpc32xx_clk(hw);
u32 val, x, y;
regmap_read(clk_regmap, clk->reg, &val);
x = (val & 0xFF00) >> 8;
y = val & 0xFF;
if (x && y)
return (parent_rate * x) / y;
else
return 0;
}
static int clk_usb_enable(struct clk_hw *hw)
{
struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
u32 val, ctrl_val, count;
pr_debug("%s: 0x%x\n", clk_hw_get_name(hw), clk->enable);
if (clk->ctrl_mask) {
regmap_read(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, &ctrl_val);
regmap_update_bits(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
clk->ctrl_mask, clk->ctrl_enable);
}
val = lpc32xx_usb_clk_read(clk);
if (clk->busy && (val & clk->busy) == clk->busy) {
if (clk->ctrl_mask)
regmap_write(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
ctrl_val);
return -EBUSY;
}
val |= clk->enable;
lpc32xx_usb_clk_write(clk, val);
for (count = 0; count < 1000; count++) {
val = lpc32xx_usb_clk_read(clk);
if ((val & clk->enable) == clk->enable)
break;
}
if ((val & clk->enable) == clk->enable)
return 0;
if (clk->ctrl_mask)
regmap_write(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, ctrl_val);
return -ETIMEDOUT;
}
static void clk_usb_disable(struct clk_hw *hw)
{
struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
u32 val = lpc32xx_usb_clk_read(clk);
val &= ~clk->enable;
lpc32xx_usb_clk_write(clk, val);
if (clk->ctrl_mask)
regmap_update_bits(clk_regmap, LPC32XX_CLKPWR_USB_CTRL,
clk->ctrl_mask, clk->ctrl_disable);
}
static int clk_usb_is_enabled(struct clk_hw *hw)
{
struct lpc32xx_usb_clk *clk = to_lpc32xx_usb_clk(hw);
u32 ctrl_val, val;
if (clk->ctrl_mask) {
regmap_read(clk_regmap, LPC32XX_CLKPWR_USB_CTRL, &ctrl_val);
if ((ctrl_val & clk->ctrl_mask) != clk->ctrl_enable)
return 0;
}
val = lpc32xx_usb_clk_read(clk);
return ((val & clk->enable) == clk->enable);
}
static unsigned long clk_usb_i2c_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return clk_get_rate(clk[LPC32XX_CLK_PERIPH]);
}
static int lpc32xx_clk_gate_enable(struct clk_hw *hw)
{
struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
u32 mask = BIT(clk->bit_idx);
u32 val = (clk->flags & CLK_GATE_SET_TO_DISABLE ? 0x0 : mask);
return regmap_update_bits(clk_regmap, clk->reg, mask, val);
}
static void lpc32xx_clk_gate_disable(struct clk_hw *hw)
{
struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
u32 mask = BIT(clk->bit_idx);
u32 val = (clk->flags & CLK_GATE_SET_TO_DISABLE ? mask : 0x0);
regmap_update_bits(clk_regmap, clk->reg, mask, val);
}
static int lpc32xx_clk_gate_is_enabled(struct clk_hw *hw)
{
struct lpc32xx_clk_gate *clk = to_lpc32xx_gate(hw);
u32 val;
bool is_set;
regmap_read(clk_regmap, clk->reg, &val);
is_set = val & BIT(clk->bit_idx);
return (clk->flags & CLK_GATE_SET_TO_DISABLE ? !is_set : is_set);
}
static unsigned int _get_table_div(const struct clk_div_table *table,
unsigned int val)
{
const struct clk_div_table *clkt;
for (clkt = table; clkt->div; clkt++)
if (clkt->val == val)
return clkt->div;
return 0;
}
static unsigned int _get_div(const struct clk_div_table *table,
unsigned int val, unsigned long flags, u8 width)
{
if (flags & CLK_DIVIDER_ONE_BASED)
return val;
if (table)
return _get_table_div(table, val);
return val + 1;
}
static unsigned long clk_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
unsigned int val;
regmap_read(clk_regmap, divider->reg, &val);
val >>= divider->shift;
val &= div_mask(divider->width);
return divider_recalc_rate(hw, parent_rate, val, divider->table,
divider->flags);
}
static long clk_divider_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
unsigned int bestdiv;
if (divider->flags & CLK_DIVIDER_READ_ONLY) {
regmap_read(clk_regmap, divider->reg, &bestdiv);
bestdiv >>= divider->shift;
bestdiv &= div_mask(divider->width);
bestdiv = _get_div(divider->table, bestdiv, divider->flags,
divider->width);
return DIV_ROUND_UP(*prate, bestdiv);
}
return divider_round_rate(hw, rate, prate, divider->table,
divider->width, divider->flags);
}
static int clk_divider_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct lpc32xx_clk_div *divider = to_lpc32xx_div(hw);
unsigned int value;
value = divider_get_val(rate, parent_rate, divider->table,
divider->width, divider->flags);
return regmap_update_bits(clk_regmap, divider->reg,
div_mask(divider->width) << divider->shift,
value << divider->shift);
}
static u8 clk_mux_get_parent(struct clk_hw *hw)
{
struct lpc32xx_clk_mux *mux = to_lpc32xx_mux(hw);
u32 num_parents = clk_hw_get_num_parents(hw);
u32 val;
regmap_read(clk_regmap, mux->reg, &val);
val >>= mux->shift;
val &= mux->mask;
if (mux->table) {
u32 i;
for (i = 0; i < num_parents; i++)
if (mux->table[i] == val)
return i;
return -EINVAL;
}
if (val >= num_parents)
return -EINVAL;
return val;
}
static int clk_mux_set_parent(struct clk_hw *hw, u8 index)
{
struct lpc32xx_clk_mux *mux = to_lpc32xx_mux(hw);
if (mux->table)
index = mux->table[index];
return regmap_update_bits(clk_regmap, mux->reg,
mux->mask << mux->shift, index << mux->shift);
}
static struct clk * __init lpc32xx_clk_register(u32 id)
{
const struct clk_proto_t *lpc32xx_clk = &clk_proto[id];
struct clk_hw_proto *clk_hw = &clk_hw_proto[id];
const char *parents[LPC32XX_CLK_PARENTS_MAX];
struct clk *clk;
unsigned int i;
for (i = 0; i < lpc32xx_clk->num_parents; i++)
parents[i] = clk_proto[lpc32xx_clk->parents[i]].name;
pr_debug("%s: derived from '%s', clock type %d\n", lpc32xx_clk->name,
parents[0], clk_hw->type);
switch (clk_hw->type) {
case CLK_LPC32XX:
case CLK_LPC32XX_PLL:
case CLK_LPC32XX_USB:
case CLK_MUX:
case CLK_DIV:
case CLK_GATE:
{
struct clk_init_data clk_init = {
.name = lpc32xx_clk->name,
.parent_names = parents,
.num_parents = lpc32xx_clk->num_parents,
.flags = lpc32xx_clk->flags,
.ops = clk_hw->hw0.ops,
};
struct clk_hw *hw;
if (clk_hw->type == CLK_LPC32XX)
hw = &clk_hw->hw0.clk.hw;
else if (clk_hw->type == CLK_LPC32XX_PLL)
hw = &clk_hw->hw0.pll.hw;
else if (clk_hw->type == CLK_LPC32XX_USB)
hw = &clk_hw->hw0.usb_clk.hw;
else if (clk_hw->type == CLK_MUX)
hw = &clk_hw->hw0.mux.hw;
else if (clk_hw->type == CLK_DIV)
hw = &clk_hw->hw0.div.hw;
else if (clk_hw->type == CLK_GATE)
hw = &clk_hw->hw0.gate.hw;
else
return ERR_PTR(-EINVAL);
hw->init = &clk_init;
clk = clk_register(NULL, hw);
break;
}
case CLK_COMPOSITE:
{
struct clk_hw *mux_hw = NULL, *div_hw = NULL, *gate_hw = NULL;
const struct clk_ops *mops = NULL, *dops = NULL, *gops = NULL;
struct clk_hw_proto0 *mux0, *div0, *gate0;
mux0 = clk_hw->hw1.mux;
div0 = clk_hw->hw1.div;
gate0 = clk_hw->hw1.gate;
if (mux0) {
mops = mux0->ops;
mux_hw = &mux0->clk.hw;
}
if (div0) {
dops = div0->ops;
div_hw = &div0->clk.hw;
}
if (gate0) {
gops = gate0->ops;
gate_hw = &gate0->clk.hw;
}
clk = clk_register_composite(NULL, lpc32xx_clk->name,
parents, lpc32xx_clk->num_parents,
mux_hw, mops, div_hw, dops,
gate_hw, gops, lpc32xx_clk->flags);
break;
}
case CLK_FIXED:
{
struct clk_fixed_rate *fixed = &clk_hw->f;
clk = clk_register_fixed_rate(NULL, lpc32xx_clk->name,
parents[0], fixed->flags, fixed->fixed_rate);
break;
}
default:
clk = ERR_PTR(-EINVAL);
}
return clk;
}
static void __init lpc32xx_clk_div_quirk(u32 reg, u32 div_mask, u32 gate)
{
u32 val;
regmap_read(clk_regmap, reg, &val);
if (!(val & div_mask)) {
val &= ~gate;
val |= BIT(__ffs(div_mask));
}
regmap_update_bits(clk_regmap, reg, gate | div_mask, val);
}
static void __init lpc32xx_clk_init(struct device_node *np)
{
unsigned int i;
struct clk *clk_osc, *clk_32k;
void __iomem *base = NULL;
clk_32k = of_clk_get_by_name(np, clk_proto[LPC32XX_CLK_XTAL_32K].name);
if (IS_ERR(clk_32k)) {
pr_err("failed to find external 32KHz clock: %ld\n",
PTR_ERR(clk_32k));
return;
}
if (clk_get_rate(clk_32k) != 32768) {
pr_err("invalid clock rate of external 32KHz oscillator");
return;
}
clk_osc = of_clk_get_by_name(np, clk_proto[LPC32XX_CLK_XTAL].name);
if (IS_ERR(clk_osc)) {
pr_err("failed to find external main oscillator clock: %ld\n",
PTR_ERR(clk_osc));
return;
}
base = of_iomap(np, 0);
if (!base) {
pr_err("failed to map system control block registers\n");
return;
}
clk_regmap = regmap_init_mmio(NULL, base, &lpc32xx_scb_regmap_config);
if (IS_ERR(clk_regmap)) {
pr_err("failed to regmap system control block: %ld\n",
PTR_ERR(clk_regmap));
iounmap(base);
return;
}
lpc32xx_clk_div_quirk(LPC32XX_CLKPWR_PWMCLK_CTRL, 0xf0, BIT(0));
lpc32xx_clk_div_quirk(LPC32XX_CLKPWR_PWMCLK_CTRL, 0xf00, BIT(2));
lpc32xx_clk_div_quirk(LPC32XX_CLKPWR_MS_CTRL, 0xf, BIT(5) | BIT(9));
for (i = 1; i < LPC32XX_CLK_MAX; i++) {
clk[i] = lpc32xx_clk_register(i);
if (IS_ERR(clk[i])) {
pr_err("failed to register %s clock: %ld\n",
clk_proto[i].name, PTR_ERR(clk[i]));
clk[i] = NULL;
}
}
of_clk_add_provider(np, of_clk_src_onecell_get, &clk_data);
clk_set_rate(clk[LPC32XX_CLK_USB_PLL], 48000000);
clk_prepare_enable(clk[LPC32XX_CLK_ARM]);
clk_prepare_enable(clk[LPC32XX_CLK_HCLK]);
clk_prepare_enable(clk[LPC32XX_CLK_ARM_VFP]);
clk_mask_disable(&clk_hw_proto[LPC32XX_CLK_SLC].hw0.clk.hw);
clk_mask_disable(&clk_hw_proto[LPC32XX_CLK_MLC].hw0.clk.hw);
}
static void __init lpc32xx_usb_clk_init(struct device_node *np)
{
unsigned int i;
usb_clk_vbase = of_iomap(np, 0);
if (!usb_clk_vbase) {
pr_err("failed to map address range\n");
return;
}
for (i = 1; i < LPC32XX_USB_CLK_MAX; i++) {
usb_clk[i] = lpc32xx_clk_register(i + LPC32XX_CLK_USB_OFFSET);
if (IS_ERR(usb_clk[i])) {
pr_err("failed to register %s clock: %ld\n",
clk_proto[i].name, PTR_ERR(usb_clk[i]));
usb_clk[i] = NULL;
}
}
of_clk_add_provider(np, of_clk_src_onecell_get, &usb_clk_data);
}
