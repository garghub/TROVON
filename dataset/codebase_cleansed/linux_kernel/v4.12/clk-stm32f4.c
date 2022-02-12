static unsigned long clk_apb_mul_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_apb_mul *am = to_clk_apb_mul(hw);
if (readl(base + STM32F4_RCC_CFGR) & BIT(am->bit_idx))
return parent_rate * 2;
return parent_rate;
}
static long clk_apb_mul_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_apb_mul *am = to_clk_apb_mul(hw);
unsigned long mult = 1;
if (readl(base + STM32F4_RCC_CFGR) & BIT(am->bit_idx))
mult = 2;
if (clk_hw_get_flags(hw) & CLK_SET_RATE_PARENT) {
unsigned long best_parent = rate / mult;
*prate = clk_hw_round_rate(clk_hw_get_parent(hw), best_parent);
}
return *prate * mult;
}
static int clk_apb_mul_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
return 0;
}
static struct clk *clk_register_apb_mul(struct device *dev, const char *name,
const char *parent_name,
unsigned long flags, u8 bit_idx)
{
struct clk_apb_mul *am;
struct clk_init_data init;
struct clk *clk;
am = kzalloc(sizeof(*am), GFP_KERNEL);
if (!am)
return ERR_PTR(-ENOMEM);
am->bit_idx = bit_idx;
am->hw.init = &init;
init.name = name;
init.ops = &clk_apb_mul_factor_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
clk = clk_register(dev, &am->hw);
if (IS_ERR(clk))
kfree(am);
return clk;
}
static int stm32f4_pll_is_enabled(struct clk_hw *hw)
{
return clk_gate_ops.is_enabled(hw);
}
static int stm32f4_pll_enable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32f4_pll *pll = to_stm32f4_pll(gate);
int bit_status;
unsigned int timeout = PLL_TIMEOUT;
if (clk_gate_ops.is_enabled(hw))
return 0;
clk_gate_ops.enable(hw);
do {
bit_status = !(readl(gate->reg) & BIT(pll->bit_rdy_idx));
} while (bit_status && --timeout);
return bit_status;
}
static void stm32f4_pll_disable(struct clk_hw *hw)
{
clk_gate_ops.disable(hw);
}
static unsigned long stm32f4_pll_recalc(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32f4_pll *pll = to_stm32f4_pll(gate);
unsigned long n;
n = (readl(base + pll->offset) >> 6) & 0x1ff;
return parent_rate * n;
}
static long stm32f4_pll_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32f4_pll *pll = to_stm32f4_pll(gate);
unsigned long n;
n = rate / *prate;
if (n < pll->n_start)
n = pll->n_start;
else if (n > 432)
n = 432;
return *prate * n;
}
static int stm32f4_pll_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32f4_pll *pll = to_stm32f4_pll(gate);
unsigned long n;
unsigned long val;
int pll_state;
pll_state = stm32f4_pll_is_enabled(hw);
if (pll_state)
stm32f4_pll_disable(hw);
n = rate / parent_rate;
val = readl(base + pll->offset) & ~(0x1ff << 6);
writel(val | ((n & 0x1ff) << 6), base + pll->offset);
if (pll_state)
stm32f4_pll_enable(hw);
return 0;
}
static unsigned long stm32f4_pll_div_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return clk_divider_ops.recalc_rate(hw, parent_rate);
}
static long stm32f4_pll_div_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
return clk_divider_ops.round_rate(hw, rate, prate);
}
static int stm32f4_pll_div_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
int pll_state, ret;
struct clk_divider *div = to_clk_divider(hw);
struct stm32f4_pll_div *pll_div = to_pll_div_clk(div);
pll_state = stm32f4_pll_is_enabled(pll_div->hw_pll);
if (pll_state)
stm32f4_pll_disable(pll_div->hw_pll);
ret = clk_divider_ops.set_rate(hw, rate, parent_rate);
if (pll_state)
stm32f4_pll_enable(pll_div->hw_pll);
return ret;
}
static struct clk_hw *clk_register_pll_div(const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 shift, u8 width,
u8 clk_divider_flags, const struct clk_div_table *table,
struct clk_hw *pll_hw, spinlock_t *lock)
{
struct stm32f4_pll_div *pll_div;
struct clk_hw *hw;
struct clk_init_data init;
int ret;
pll_div = kzalloc(sizeof(*pll_div), GFP_KERNEL);
if (!pll_div)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &stm32f4_pll_div_ops;
init.flags = flags;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
pll_div->div.reg = reg;
pll_div->div.shift = shift;
pll_div->div.width = width;
pll_div->div.flags = clk_divider_flags;
pll_div->div.lock = lock;
pll_div->div.table = table;
pll_div->div.hw.init = &init;
pll_div->hw_pll = pll_hw;
hw = &pll_div->div.hw;
ret = clk_hw_register(NULL, hw);
if (ret) {
kfree(pll_div);
hw = ERR_PTR(ret);
}
return hw;
}
static struct clk_hw *stm32f4_rcc_register_pll(const char *pllsrc,
const struct stm32f4_pll_data *data, spinlock_t *lock)
{
struct stm32f4_pll *pll;
struct clk_init_data init = { NULL };
void __iomem *reg;
struct clk_hw *pll_hw;
int ret;
int i;
const struct stm32f4_vco_data *vco;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
vco = &vco_data[data->pll_num];
init.name = vco->vco_name;
init.ops = &stm32f4_pll_gate_ops;
init.flags = CLK_SET_RATE_GATE;
init.parent_names = &pllsrc;
init.num_parents = 1;
pll->gate.lock = lock;
pll->gate.reg = base + STM32F4_RCC_CR;
pll->gate.bit_idx = vco->bit_idx;
pll->gate.hw.init = &init;
pll->offset = vco->offset;
pll->n_start = data->n_start;
pll->bit_rdy_idx = vco->bit_rdy_idx;
pll->status = (readl(base + STM32F4_RCC_CR) >> vco->bit_idx) & 0x1;
reg = base + pll->offset;
pll_hw = &pll->gate.hw;
ret = clk_hw_register(NULL, pll_hw);
if (ret) {
kfree(pll);
return ERR_PTR(ret);
}
for (i = 0; i < MAX_PLL_DIV; i++)
if (data->div_name[i])
clk_register_pll_div(data->div_name[i],
vco->vco_name,
0,
reg,
div_data[i].shift,
div_data[i].width,
div_data[i].flag_div,
div_data[i].div_table,
pll_hw,
lock);
return pll_hw;
}
static int stm32f4_rcc_lookup_clk_idx(u8 primary, u8 secondary)
{
u64 table[MAX_GATE_MAP];
if (primary == 1) {
if (WARN_ON(secondary >= stm32fx_end_primary_clk))
return -EINVAL;
return secondary;
}
memcpy(table, stm32f4_gate_map, sizeof(table));
if (WARN_ON(secondary >= BITS_PER_BYTE * sizeof(table) ||
0 == (table[BIT_ULL_WORD(secondary)] &
BIT_ULL_MASK(secondary))))
return -EINVAL;
table[BIT_ULL_WORD(secondary)] &=
GENMASK_ULL(secondary % BITS_PER_LONG_LONG, 0);
return stm32fx_end_primary_clk - 1 + hweight64(table[0]) +
(BIT_ULL_WORD(secondary) >= 1 ? hweight64(table[1]) : 0) +
(BIT_ULL_WORD(secondary) >= 2 ? hweight64(table[2]) : 0);
}
static struct clk_hw *
stm32f4_rcc_lookup_clk(struct of_phandle_args *clkspec, void *data)
{
int i = stm32f4_rcc_lookup_clk_idx(clkspec->args[0], clkspec->args[1]);
if (i < 0)
return ERR_PTR(-EINVAL);
return clks[i];
}
static inline void disable_power_domain_write_protection(void)
{
if (pdrm)
regmap_update_bits(pdrm, 0x00, (1 << 8), (1 << 8));
}
static inline void enable_power_domain_write_protection(void)
{
if (pdrm)
regmap_update_bits(pdrm, 0x00, (1 << 8), (0 << 8));
}
static inline void sofware_reset_backup_domain(void)
{
unsigned long val;
val = readl(base + STM32F4_RCC_BDCR);
writel(val | BIT(16), base + STM32F4_RCC_BDCR);
writel(val & ~BIT(16), base + STM32F4_RCC_BDCR);
}
static int rgclk_enable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32_rgate *rgate = to_rgclk(gate);
int bit_status;
unsigned int timeout = RGATE_TIMEOUT;
if (clk_gate_ops.is_enabled(hw))
return 0;
disable_power_domain_write_protection();
clk_gate_ops.enable(hw);
do {
bit_status = !(readl(gate->reg) & BIT(rgate->bit_rdy_idx));
if (bit_status)
udelay(100);
} while (bit_status && --timeout);
enable_power_domain_write_protection();
return bit_status;
}
static void rgclk_disable(struct clk_hw *hw)
{
clk_gate_ops.disable(hw);
}
static int rgclk_is_enabled(struct clk_hw *hw)
{
return clk_gate_ops.is_enabled(hw);
}
static struct clk_hw *clk_register_rgate(struct device *dev, const char *name,
const char *parent_name, unsigned long flags,
void __iomem *reg, u8 bit_idx, u8 bit_rdy_idx,
u8 clk_gate_flags, spinlock_t *lock)
{
struct stm32_rgate *rgate;
struct clk_init_data init = { NULL };
struct clk_hw *hw;
int ret;
rgate = kzalloc(sizeof(*rgate), GFP_KERNEL);
if (!rgate)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &rgclk_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
rgate->bit_rdy_idx = bit_rdy_idx;
rgate->gate.lock = lock;
rgate->gate.reg = reg;
rgate->gate.bit_idx = bit_idx;
rgate->gate.hw.init = &init;
hw = &rgate->gate.hw;
ret = clk_hw_register(dev, hw);
if (ret) {
kfree(rgate);
hw = ERR_PTR(ret);
}
return hw;
}
static int cclk_gate_enable(struct clk_hw *hw)
{
int ret;
disable_power_domain_write_protection();
ret = clk_gate_ops.enable(hw);
enable_power_domain_write_protection();
return ret;
}
static void cclk_gate_disable(struct clk_hw *hw)
{
disable_power_domain_write_protection();
clk_gate_ops.disable(hw);
enable_power_domain_write_protection();
}
static int cclk_gate_is_enabled(struct clk_hw *hw)
{
return clk_gate_ops.is_enabled(hw);
}
static u8 cclk_mux_get_parent(struct clk_hw *hw)
{
return clk_mux_ops.get_parent(hw);
}
static int cclk_mux_set_parent(struct clk_hw *hw, u8 index)
{
int ret;
disable_power_domain_write_protection();
sofware_reset_backup_domain();
ret = clk_mux_ops.set_parent(hw, index);
enable_power_domain_write_protection();
return ret;
}
static struct clk_hw *stm32_register_cclk(struct device *dev, const char *name,
const char * const *parent_names, int num_parents,
void __iomem *reg, u8 bit_idx, u8 shift, unsigned long flags,
spinlock_t *lock)
{
struct clk_hw *hw;
struct clk_gate *gate;
struct clk_mux *mux;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
hw = ERR_PTR(-EINVAL);
goto fail;
}
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux) {
kfree(gate);
hw = ERR_PTR(-EINVAL);
goto fail;
}
gate->reg = reg;
gate->bit_idx = bit_idx;
gate->flags = 0;
gate->lock = lock;
mux->reg = reg;
mux->shift = shift;
mux->mask = 3;
mux->flags = 0;
hw = clk_hw_register_composite(dev, name, parent_names, num_parents,
&mux->hw, &cclk_mux_ops,
NULL, NULL,
&gate->hw, &cclk_gate_ops,
flags);
if (IS_ERR(hw)) {
kfree(gate);
kfree(mux);
}
fail:
return hw;
}
static struct clk_hw *stm32_register_aux_clk(const char *name,
const char * const *parent_names, int num_parents,
int offset_mux, u8 shift, u8 mask,
int offset_gate, u8 bit_idx,
unsigned long flags, spinlock_t *lock)
{
struct clk_hw *hw;
struct clk_gate *gate = NULL;
struct clk_mux *mux = NULL;
struct clk_hw *mux_hw = NULL, *gate_hw = NULL;
const struct clk_ops *mux_ops = NULL, *gate_ops = NULL;
if (offset_gate != NO_GATE) {
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate) {
hw = ERR_PTR(-EINVAL);
goto fail;
}
gate->reg = base + offset_gate;
gate->bit_idx = bit_idx;
gate->flags = 0;
gate->lock = lock;
gate_hw = &gate->hw;
gate_ops = &clk_gate_ops;
}
if (offset_mux != NO_MUX) {
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux) {
hw = ERR_PTR(-EINVAL);
goto fail;
}
mux->reg = base + offset_mux;
mux->shift = shift;
mux->mask = mask;
mux->flags = 0;
mux_hw = &mux->hw;
mux_ops = &clk_mux_ops;
}
if (mux_hw == NULL && gate_hw == NULL) {
hw = ERR_PTR(-EINVAL);
goto fail;
}
hw = clk_hw_register_composite(NULL, name, parent_names, num_parents,
mux_hw, mux_ops,
NULL, NULL,
gate_hw, gate_ops,
flags);
fail:
if (IS_ERR(hw)) {
kfree(gate);
kfree(mux);
}
return hw;
}
static void __init stm32f4_rcc_init(struct device_node *np)
{
const char *hse_clk, *i2s_in_clk;
int n;
const struct of_device_id *match;
const struct stm32f4_clk_data *data;
unsigned long pllcfgr;
const char *pllsrc;
unsigned long pllm;
base = of_iomap(np, 0);
if (!base) {
pr_err("%s: unable to map resource", np->name);
return;
}
pdrm = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(pdrm)) {
pdrm = NULL;
pr_warn("%s: Unable to get syscfg\n", __func__);
}
match = of_match_node(stm32f4_of_match, np);
if (WARN_ON(!match))
return;
data = match->data;
stm32fx_end_primary_clk = data->end_primary;
clks = kmalloc_array(data->gates_num + stm32fx_end_primary_clk,
sizeof(*clks), GFP_KERNEL);
if (!clks)
goto fail;
stm32f4_gate_map = data->gates_map;
hse_clk = of_clk_get_parent_name(np, 0);
i2s_in_clk = of_clk_get_parent_name(np, 1);
i2s_parents[1] = i2s_in_clk;
sai_parents[2] = i2s_in_clk;
clks[CLK_HSI] = clk_hw_register_fixed_rate_with_accuracy(NULL, "hsi",
NULL, 0, 16000000, 160000);
pllcfgr = readl(base + STM32F4_RCC_PLLCFGR);
pllsrc = pllcfgr & BIT(22) ? hse_clk : "hsi";
pllm = pllcfgr & 0x3f;
clk_hw_register_fixed_factor(NULL, "vco_in", pllsrc,
0, 1, pllm);
stm32f4_rcc_register_pll("vco_in", &data->pll_data[0],
&stm32f4_clk_lock);
clks[PLL_VCO_I2S] = stm32f4_rcc_register_pll("vco_in",
&data->pll_data[1], &stm32f4_clk_lock);
clks[PLL_VCO_SAI] = stm32f4_rcc_register_pll("vco_in",
&data->pll_data[2], &stm32f4_clk_lock);
for (n = 0; n < MAX_POST_DIV; n++) {
const struct stm32f4_pll_post_div_data *post_div;
struct clk_hw *hw;
post_div = &post_div_data[n];
hw = clk_register_pll_div(post_div->name,
post_div->parent,
post_div->flag,
base + post_div->offset,
post_div->shift,
post_div->width,
post_div->flag_div,
post_div->div_table,
clks[post_div->pll_num],
&stm32f4_clk_lock);
if (post_div->idx != NO_IDX)
clks[post_div->idx] = hw;
}
sys_parents[1] = hse_clk;
clks[CLK_SYSCLK] = clk_hw_register_mux_table(
NULL, "sys", sys_parents, ARRAY_SIZE(sys_parents), 0,
base + STM32F4_RCC_CFGR, 0, 3, 0, NULL, &stm32f4_clk_lock);
clk_register_divider_table(NULL, "ahb_div", "sys",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
4, 4, 0, ahb_div_table, &stm32f4_clk_lock);
clk_register_divider_table(NULL, "apb1_div", "ahb_div",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
10, 3, 0, apb_div_table, &stm32f4_clk_lock);
clk_register_apb_mul(NULL, "apb1_mul", "apb1_div",
CLK_SET_RATE_PARENT, 12);
clk_register_divider_table(NULL, "apb2_div", "ahb_div",
CLK_SET_RATE_PARENT, base + STM32F4_RCC_CFGR,
13, 3, 0, apb_div_table, &stm32f4_clk_lock);
clk_register_apb_mul(NULL, "apb2_mul", "apb2_div",
CLK_SET_RATE_PARENT, 15);
clks[SYSTICK] = clk_hw_register_fixed_factor(NULL, "systick", "ahb_div",
0, 1, 8);
clks[FCLK] = clk_hw_register_fixed_factor(NULL, "fclk", "ahb_div",
0, 1, 1);
for (n = 0; n < data->gates_num; n++) {
const struct stm32f4_gate_data *gd;
unsigned int secondary;
int idx;
gd = &data->gates_data[n];
secondary = 8 * (gd->offset - STM32F4_RCC_AHB1ENR) +
gd->bit_idx;
idx = stm32f4_rcc_lookup_clk_idx(0, secondary);
if (idx < 0)
goto fail;
clks[idx] = clk_hw_register_gate(
NULL, gd->name, gd->parent_name, gd->flags,
base + gd->offset, gd->bit_idx, 0, &stm32f4_clk_lock);
if (IS_ERR(clks[idx])) {
pr_err("%s: Unable to register leaf clock %s\n",
np->full_name, gd->name);
goto fail;
}
}
clks[CLK_LSI] = clk_register_rgate(NULL, "lsi", "clk-lsi", 0,
base + STM32F4_RCC_CSR, 0, 1, 0, &stm32f4_clk_lock);
if (IS_ERR(clks[CLK_LSI])) {
pr_err("Unable to register lsi clock\n");
goto fail;
}
clks[CLK_LSE] = clk_register_rgate(NULL, "lse", "clk-lse", 0,
base + STM32F4_RCC_BDCR, 0, 1, 0, &stm32f4_clk_lock);
if (IS_ERR(clks[CLK_LSE])) {
pr_err("Unable to register lse clock\n");
goto fail;
}
clks[CLK_HSE_RTC] = clk_hw_register_divider(NULL, "hse-rtc", "clk-hse",
0, base + STM32F4_RCC_CFGR, 16, 5, 0,
&stm32f4_clk_lock);
if (IS_ERR(clks[CLK_HSE_RTC])) {
pr_err("Unable to register hse-rtc clock\n");
goto fail;
}
clks[CLK_RTC] = stm32_register_cclk(NULL, "rtc", rtc_parents, 4,
base + STM32F4_RCC_BDCR, 15, 8, 0, &stm32f4_clk_lock);
if (IS_ERR(clks[CLK_RTC])) {
pr_err("Unable to register rtc clock\n");
goto fail;
}
for (n = 0; n < data->aux_clk_num; n++) {
const struct stm32_aux_clk *aux_clk;
struct clk_hw *hw;
aux_clk = &data->aux_clk[n];
hw = stm32_register_aux_clk(aux_clk->name,
aux_clk->parent_names, aux_clk->num_parents,
aux_clk->offset_mux, aux_clk->shift,
aux_clk->mask, aux_clk->offset_gate,
aux_clk->bit_idx, aux_clk->flags,
&stm32f4_clk_lock);
if (IS_ERR(hw)) {
pr_warn("Unable to register %s clk\n", aux_clk->name);
continue;
}
if (aux_clk->idx != NO_IDX)
clks[aux_clk->idx] = hw;
}
if (of_device_is_compatible(np, "st,stm32f746-rcc"))
clk_hw_register_fixed_factor(NULL, "hsi_div488", "hsi", 0,
1, 488);
of_clk_add_hw_provider(np, stm32f4_rcc_lookup_clk, NULL);
return;
fail:
kfree(clks);
iounmap(base);
}
