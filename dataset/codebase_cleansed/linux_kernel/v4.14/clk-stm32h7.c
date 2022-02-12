static int ready_gate_clk_enable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32_ready_gate *rgate = to_ready_gate_clk(gate);
int bit_status;
unsigned int timeout = RGATE_TIMEOUT;
if (clk_gate_ops.is_enabled(hw))
return 0;
clk_gate_ops.enable(hw);
do {
bit_status = !(readl(gate->reg) & BIT(rgate->bit_rdy));
if (bit_status)
udelay(100);
} while (bit_status && --timeout);
return bit_status;
}
static void ready_gate_clk_disable(struct clk_hw *hw)
{
struct clk_gate *gate = to_clk_gate(hw);
struct stm32_ready_gate *rgate = to_ready_gate_clk(gate);
int bit_status;
unsigned int timeout = RGATE_TIMEOUT;
if (!clk_gate_ops.is_enabled(hw))
return;
clk_gate_ops.disable(hw);
do {
bit_status = !!(readl(gate->reg) & BIT(rgate->bit_rdy));
if (bit_status)
udelay(100);
} while (bit_status && --timeout);
}
static struct clk_hw *clk_register_ready_gate(struct device *dev,
const char *name, const char *parent_name,
void __iomem *reg, u8 bit_idx, u8 bit_rdy,
unsigned long flags, spinlock_t *lock)
{
struct stm32_ready_gate *rgate;
struct clk_init_data init = { NULL };
struct clk_hw *hw;
int ret;
rgate = kzalloc(sizeof(*rgate), GFP_KERNEL);
if (!rgate)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &ready_gate_clk_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
rgate->bit_rdy = bit_rdy;
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
static struct clk_mux *_get_cmux(void __iomem *reg, u8 shift, u8 width,
u32 flags, spinlock_t *lock)
{
struct clk_mux *mux;
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux)
return ERR_PTR(-ENOMEM);
mux->reg = reg;
mux->shift = shift;
mux->mask = (1 << width) - 1;
mux->flags = flags;
mux->lock = lock;
return mux;
}
static struct clk_divider *_get_cdiv(void __iomem *reg, u8 shift, u8 width,
u32 flags, spinlock_t *lock)
{
struct clk_divider *div;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return ERR_PTR(-ENOMEM);
div->reg = reg;
div->shift = shift;
div->width = width;
div->flags = flags;
div->lock = lock;
return div;
}
static struct clk_gate *_get_cgate(void __iomem *reg, u8 bit_idx, u32 flags,
spinlock_t *lock)
{
struct clk_gate *gate;
gate = kzalloc(sizeof(*gate), GFP_KERNEL);
if (!gate)
return ERR_PTR(-ENOMEM);
gate->reg = reg;
gate->bit_idx = bit_idx;
gate->flags = flags;
gate->lock = lock;
return gate;
}
static void get_cfg_composite_div(const struct composite_clk_gcfg *gcfg,
const struct composite_clk_cfg *cfg,
struct composite_cfg *composite, spinlock_t *lock)
{
struct clk_mux *mux = NULL;
struct clk_divider *div = NULL;
struct clk_gate *gate = NULL;
const struct clk_ops *mux_ops, *div_ops, *gate_ops;
struct clk_hw *mux_hw;
struct clk_hw *div_hw;
struct clk_hw *gate_hw;
mux_ops = div_ops = gate_ops = NULL;
mux_hw = div_hw = gate_hw = NULL;
if (gcfg->mux && gcfg->mux) {
mux = _get_cmux(base + cfg->mux->offset,
cfg->mux->shift,
cfg->mux->width,
gcfg->mux->flags, lock);
if (!IS_ERR(mux)) {
mux_hw = &mux->hw;
mux_ops = gcfg->mux->ops ?
gcfg->mux->ops : &clk_mux_ops;
}
}
if (gcfg->div && cfg->div) {
div = _get_cdiv(base + cfg->div->offset,
cfg->div->shift,
cfg->div->width,
gcfg->div->flags, lock);
if (!IS_ERR(div)) {
div_hw = &div->hw;
div_ops = gcfg->div->ops ?
gcfg->div->ops : &clk_divider_ops;
}
}
if (gcfg->gate && gcfg->gate) {
gate = _get_cgate(base + cfg->gate->offset,
cfg->gate->bit_idx,
gcfg->gate->flags, lock);
if (!IS_ERR(gate)) {
gate_hw = &gate->hw;
gate_ops = gcfg->gate->ops ?
gcfg->gate->ops : &clk_gate_ops;
}
}
composite->mux_hw = mux_hw;
composite->mux_ops = mux_ops;
composite->div_hw = div_hw;
composite->div_ops = div_ops;
composite->gate_hw = gate_hw;
composite->gate_ops = gate_ops;
}
static unsigned long timer_ker_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct timer_ker *clk_elem = to_timer_ker(hw);
u32 timpre;
u32 dppre_shift = clk_elem->dppre_shift;
u32 prescaler;
u32 mul;
timpre = (readl(base + RCC_CFGR) >> 15) & 0x01;
prescaler = (readl(base + RCC_D2CFGR) >> dppre_shift) & 0x03;
mul = 2;
if (prescaler < 4)
mul = 1;
else if (timpre && prescaler > 4)
mul = 4;
return parent_rate * mul;
}
static struct clk_hw *clk_register_stm32_timer_ker(struct device *dev,
const char *name, const char *parent_name,
unsigned long flags,
u8 dppre_shift,
spinlock_t *lock)
{
struct timer_ker *element;
struct clk_init_data init;
struct clk_hw *hw;
int err;
element = kzalloc(sizeof(*element), GFP_KERNEL);
if (!element)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &timer_ker_ops;
init.flags = flags;
init.parent_names = &parent_name;
init.num_parents = 1;
element->hw.init = &init;
element->lock = lock;
element->dppre_shift = dppre_shift;
hw = &element->hw;
err = clk_hw_register(dev, hw);
if (err) {
kfree(element);
return ERR_PTR(err);
}
return hw;
}
static void register_core_and_bus_clocks(void)
{
hws[SYS_D1CPRE] = clk_hw_register_divider_table(NULL, "d1cpre",
"sys_ck", CLK_IGNORE_UNUSED, base + RCC_D1CFGR, 8, 4, 0,
d1cpre_div_table, &stm32rcc_lock);
hws[HCLK] = clk_hw_register_divider_table(NULL, "hclk", "d1cpre",
CLK_IGNORE_UNUSED, base + RCC_D1CFGR, 0, 4, 0,
d1cpre_div_table, &stm32rcc_lock);
hws[CPU_SYSTICK] = clk_hw_register_fixed_factor(NULL, "systick",
"d1cpre", 0, 1, 8);
hws[PCLK3] = clk_hw_register_divider_table(NULL, "pclk3", "hclk", 0,
base + RCC_D1CFGR, 4, 3, 0,
ppre_div_table, &stm32rcc_lock);
hws[PCLK1] = clk_hw_register_divider_table(NULL, "pclk1", "hclk", 0,
base + RCC_D2CFGR, 4, 3, 0,
ppre_div_table, &stm32rcc_lock);
clk_register_stm32_timer_ker(NULL, "tim1_ker", "pclk1", 0,
4, &stm32rcc_lock);
hws[PCLK2] = clk_hw_register_divider_table(NULL, "pclk2", "hclk", 0,
base + RCC_D2CFGR, 8, 3, 0, ppre_div_table,
&stm32rcc_lock);
clk_register_stm32_timer_ker(NULL, "tim2_ker", "pclk2", 0, 8,
&stm32rcc_lock);
hws[PCLK4] = clk_hw_register_divider_table(NULL, "pclk4", "hclk", 0,
base + RCC_D3CFGR, 4, 3, 0,
ppre_div_table, &stm32rcc_lock);
}
static int pll_is_enabled(struct clk_hw *hw)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct clk_hw *_hw = &clk_elem->rgate.gate.hw;
__clk_hw_set_clk(_hw, hw);
return ready_gate_clk_ops.is_enabled(_hw);
}
static int pll_enable(struct clk_hw *hw)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct clk_hw *_hw = &clk_elem->rgate.gate.hw;
__clk_hw_set_clk(_hw, hw);
return ready_gate_clk_ops.enable(_hw);
}
static void pll_disable(struct clk_hw *hw)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct clk_hw *_hw = &clk_elem->rgate.gate.hw;
__clk_hw_set_clk(_hw, hw);
ready_gate_clk_ops.disable(_hw);
}
static int pll_frac_is_enabled(struct clk_hw *hw)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct stm32_fractional_divider *fd = &clk_elem->div;
return (readl(fd->freg_status) >> fd->freg_bit) & 0x01;
}
static unsigned long pll_read_frac(struct clk_hw *hw)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct stm32_fractional_divider *fd = &clk_elem->div;
return (readl(fd->freg_value) >> fd->fshift) &
GENMASK(fd->fwidth - 1, 0);
}
static unsigned long pll_fd_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct stm32_pll_obj *clk_elem = to_pll(hw);
struct stm32_fractional_divider *fd = &clk_elem->div;
unsigned long m, n;
u32 val, mask;
u64 rate, rate1 = 0;
val = readl(fd->mreg);
mask = GENMASK(fd->mwidth - 1, 0) << fd->mshift;
m = (val & mask) >> fd->mshift;
val = readl(fd->nreg);
mask = GENMASK(fd->nwidth - 1, 0) << fd->nshift;
n = ((val & mask) >> fd->nshift) + 1;
if (!n || !m)
return parent_rate;
rate = (u64)parent_rate * n;
do_div(rate, m);
if (pll_frac_is_enabled(hw)) {
val = pll_read_frac(hw);
rate1 = (u64)parent_rate * (u64)val;
do_div(rate1, (m * 8191));
}
return rate + rate1;
}
static struct clk_hw *clk_register_stm32_pll(struct device *dev,
const char *name,
const char *parent,
unsigned long flags,
const struct st32h7_pll_cfg *cfg,
spinlock_t *lock)
{
struct stm32_pll_obj *pll;
struct clk_init_data init = { NULL };
struct clk_hw *hw;
int ret;
struct stm32_fractional_divider *div = NULL;
struct stm32_ready_gate *rgate;
pll = kzalloc(sizeof(*pll), GFP_KERNEL);
if (!pll)
return ERR_PTR(-ENOMEM);
init.name = name;
init.ops = &pll_ops;
init.flags = flags;
init.parent_names = &parent;
init.num_parents = 1;
pll->hw.init = &init;
hw = &pll->hw;
rgate = &pll->rgate;
rgate->bit_rdy = cfg->bit_idx + 1;
rgate->gate.lock = lock;
rgate->gate.reg = base + RCC_CR;
rgate->gate.bit_idx = cfg->bit_idx;
div = &pll->div;
div->flags = 0;
div->mreg = base + RCC_PLLCKSELR;
div->mshift = cfg->divm;
div->mwidth = 6;
div->nreg = base + cfg->offset_divr;
div->nshift = 0;
div->nwidth = 9;
div->freg_status = base + RCC_PLLCFGR;
div->freg_bit = cfg->bit_frac_en;
div->freg_value = base + cfg->offset_frac;
div->fshift = 3;
div->fwidth = 13;
div->lock = lock;
ret = clk_hw_register(dev, hw);
if (ret) {
kfree(pll);
hw = ERR_PTR(ret);
}
return hw;
}
static unsigned long odf_divider_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return clk_divider_ops.recalc_rate(hw, parent_rate);
}
static long odf_divider_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
return clk_divider_ops.round_rate(hw, rate, prate);
}
static int odf_divider_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_hw *hwp;
int pll_status;
int ret;
hwp = clk_hw_get_parent(hw);
pll_status = pll_is_enabled(hwp);
if (pll_status)
pll_disable(hwp);
ret = clk_divider_ops.set_rate(hw, rate, parent_rate);
if (pll_status)
pll_enable(hwp);
return ret;
}
static int odf_gate_enable(struct clk_hw *hw)
{
struct clk_hw *hwp;
int pll_status;
int ret;
if (clk_gate_ops.is_enabled(hw))
return 0;
hwp = clk_hw_get_parent(hw);
pll_status = pll_is_enabled(hwp);
if (pll_status)
pll_disable(hwp);
ret = clk_gate_ops.enable(hw);
if (pll_status)
pll_enable(hwp);
return ret;
}
static void odf_gate_disable(struct clk_hw *hw)
{
struct clk_hw *hwp;
int pll_status;
if (!clk_gate_ops.is_enabled(hw))
return;
hwp = clk_hw_get_parent(hw);
pll_status = pll_is_enabled(hwp);
if (pll_status)
pll_disable(hwp);
clk_gate_ops.disable(hw);
if (pll_status)
pll_enable(hwp);
}
static void __init stm32h7_rcc_init(struct device_node *np)
{
struct clk_hw_onecell_data *clk_data;
struct composite_cfg c_cfg;
int n;
const char *hse_clk, *lse_clk, *i2s_clk;
struct regmap *pdrm;
clk_data = kzalloc(sizeof(*clk_data) +
sizeof(*clk_data->hws) * STM32H7_MAX_CLKS,
GFP_KERNEL);
if (!clk_data)
return;
clk_data->num = STM32H7_MAX_CLKS;
hws = clk_data->hws;
for (n = 0; n < STM32H7_MAX_CLKS; n++)
hws[n] = ERR_PTR(-ENOENT);
base = of_iomap(np, 0);
if (!base) {
pr_err("%s: unable to map resource", np->name);
goto err_free_clks;
}
pdrm = syscon_regmap_lookup_by_phandle(np, "st,syscfg");
if (IS_ERR(pdrm))
pr_warn("%s: Unable to get syscfg\n", __func__);
else
regmap_update_bits(pdrm, PWR_CR, PWR_CR_DBP, PWR_CR_DBP);
hse_clk = of_clk_get_parent_name(np, 0);
lse_clk = of_clk_get_parent_name(np, 1);
i2s_clk = of_clk_get_parent_name(np, 2);
sai_src[3] = i2s_clk;
spi_src1[3] = i2s_clk;
clk_hw_register_fixed_rate(NULL, "clk-hsi", NULL, 0, 64000000);
clk_hw_register_fixed_rate(NULL, "clk-csi", NULL, 0, 4000000);
clk_hw_register_fixed_rate(NULL, "clk-lsi", NULL, 0, 32000);
clk_hw_register_fixed_rate(NULL, "clk-rc48", NULL, 0, 48000);
hws[CK_DSI_PHY] = clk_hw_register_fixed_rate(NULL, "ck_dsi_phy", NULL,
0, 0);
hws[HSI_DIV] = clk_hw_register_divider(NULL, "hsidiv", "clk-hsi", 0,
base + RCC_CR, 3, 2, CLK_DIVIDER_POWER_OF_TWO,
&stm32rcc_lock);
hws[HSE_1M] = clk_hw_register_divider(NULL, "hse_1M", "hse_ck", 0,
base + RCC_CFGR, 8, 6, CLK_DIVIDER_ONE_BASED |
CLK_DIVIDER_ALLOW_ZERO,
&stm32rcc_lock);
for (n = 0; n < ARRAY_SIZE(stm32_mclk); n++)
hws[MCLK_BANK + n] = clk_hw_register_mux(NULL,
stm32_mclk[n].name,
stm32_mclk[n].parents,
stm32_mclk[n].num_parents,
stm32_mclk[n].flags,
stm32_mclk[n].offset + base,
stm32_mclk[n].shift,
stm32_mclk[n].width,
0,
&stm32rcc_lock);
register_core_and_bus_clocks();
for (n = 0; n < ARRAY_SIZE(stm32_oclk); n++)
hws[OSC_BANK + n] = clk_register_ready_gate(NULL,
stm32_oclk[n].name,
stm32_oclk[n].parent,
stm32_oclk[n].gate_offset + base,
stm32_oclk[n].bit_idx,
stm32_oclk[n].bit_rdy,
stm32_oclk[n].flags,
&stm32rcc_lock);
hws[HSE_CK] = clk_register_ready_gate(NULL,
"hse_ck",
hse_clk,
RCC_CR + base,
16, 17,
0,
&stm32rcc_lock);
hws[LSE_CK] = clk_register_ready_gate(NULL,
"lse_ck",
lse_clk,
RCC_BDCR + base,
0, 1,
0,
&stm32rcc_lock);
hws[CSI_KER_DIV122 + n] = clk_hw_register_fixed_factor(NULL,
"csi_ker_div122", "csi_ker", 0, 1, 122);
for (n = 0; n < ARRAY_SIZE(stm32_pll); n++) {
int odf;
clk_register_stm32_pll(NULL, stm32_pll[n].name,
stm32_pll[n].parent_name, stm32_pll[n].flags,
stm32_pll[n].cfg,
&stm32rcc_lock);
for (odf = 0; odf < 3; odf++) {
int idx = n * 3 + odf;
get_cfg_composite_div(&odf_clk_gcfg, &stm32_odf[n][odf],
&c_cfg, &stm32rcc_lock);
hws[ODF_BANK + idx] = clk_hw_register_composite(NULL,
stm32_odf[n][odf].name,
stm32_odf[n][odf].parent_name,
stm32_odf[n][odf].num_parents,
c_cfg.mux_hw, c_cfg.mux_ops,
c_cfg.div_hw, c_cfg.div_ops,
c_cfg.gate_hw, c_cfg.gate_ops,
stm32_odf[n][odf].flags);
}
}
for (n = 0; n < ARRAY_SIZE(pclk); n++)
hws[PERIF_BANK + n] = clk_hw_register_gate(NULL, pclk[n].name,
pclk[n].parent,
pclk[n].flags, base + pclk[n].gate_offset,
pclk[n].bit_idx, pclk[n].flags, &stm32rcc_lock);
for (n = 0; n < ARRAY_SIZE(kclk); n++) {
get_cfg_composite_div(&kernel_clk_cfg, &kclk[n], &c_cfg,
&stm32rcc_lock);
hws[KERN_BANK + n] = clk_hw_register_composite(NULL,
kclk[n].name,
kclk[n].parent_name,
kclk[n].num_parents,
c_cfg.mux_hw, c_cfg.mux_ops,
c_cfg.div_hw, c_cfg.div_ops,
c_cfg.gate_hw, c_cfg.gate_ops,
kclk[n].flags);
}
clk_hw_register_fixed_rate(NULL, "off", NULL, 0, 0);
get_cfg_composite_div(&rtc_clk_cfg, &rtc_clk, &c_cfg, &stm32rcc_lock);
hws[RTC_CK] = clk_hw_register_composite(NULL,
rtc_clk.name,
rtc_clk.parent_name,
rtc_clk.num_parents,
c_cfg.mux_hw, c_cfg.mux_ops,
c_cfg.div_hw, c_cfg.div_ops,
c_cfg.gate_hw, c_cfg.gate_ops,
rtc_clk.flags);
for (n = 0; n < ARRAY_SIZE(mco_clk); n++) {
get_cfg_composite_div(&mco_clk_cfg, &mco_clk[n], &c_cfg,
&stm32rcc_lock);
hws[MCO_BANK + n] = clk_hw_register_composite(NULL,
mco_clk[n].name,
mco_clk[n].parent_name,
mco_clk[n].num_parents,
c_cfg.mux_hw, c_cfg.mux_ops,
c_cfg.div_hw, c_cfg.div_ops,
c_cfg.gate_hw, c_cfg.gate_ops,
mco_clk[n].flags);
}
of_clk_add_hw_provider(np, of_clk_hw_onecell_get, clk_data);
return;
err_free_clks:
kfree(clk_data);
}
