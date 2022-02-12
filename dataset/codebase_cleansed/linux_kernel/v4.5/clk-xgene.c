static inline u32 xgene_clk_read(void __iomem *csr)
{
return readl_relaxed(csr);
}
static inline void xgene_clk_write(u32 data, void __iomem *csr)
{
return writel_relaxed(data, csr);
}
static int xgene_clk_pll_is_enabled(struct clk_hw *hw)
{
struct xgene_clk_pll *pllclk = to_xgene_clk_pll(hw);
u32 data;
data = xgene_clk_read(pllclk->reg + pllclk->pll_offset);
pr_debug("%s pll %s\n", clk_hw_get_name(hw),
data & REGSPEC_RESET_F1_MASK ? "disabled" : "enabled");
return data & REGSPEC_RESET_F1_MASK ? 0 : 1;
}
static unsigned long xgene_clk_pll_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct xgene_clk_pll *pllclk = to_xgene_clk_pll(hw);
unsigned long fref;
unsigned long fvco;
u32 pll;
u32 nref;
u32 nout;
u32 nfb;
pll = xgene_clk_read(pllclk->reg + pllclk->pll_offset);
if (pllclk->type == PLL_TYPE_PCP) {
nout = 2;
fvco = parent_rate * (N_DIV_RD(pll) + 4);
} else {
nref = CLKR_RD(pll) + 1;
nout = CLKOD_RD(pll) + 1;
nfb = CLKF_RD(pll);
fref = parent_rate / nref;
fvco = fref * nfb;
}
pr_debug("%s pll recalc rate %ld parent %ld\n", clk_hw_get_name(hw),
fvco / nout, parent_rate);
return fvco / nout;
}
static struct clk *xgene_register_clk_pll(struct device *dev,
const char *name, const char *parent_name,
unsigned long flags, void __iomem *reg, u32 pll_offset,
u32 type, spinlock_t *lock)
{
struct xgene_clk_pll *apmclk;
struct clk *clk;
struct clk_init_data init;
apmclk = kzalloc(sizeof(*apmclk), GFP_KERNEL);
if (!apmclk) {
pr_err("%s: could not allocate APM clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &xgene_clk_pll_ops;
init.flags = flags;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
apmclk->reg = reg;
apmclk->lock = lock;
apmclk->pll_offset = pll_offset;
apmclk->type = type;
apmclk->hw.init = &init;
clk = clk_register(dev, &apmclk->hw);
if (IS_ERR(clk)) {
pr_err("%s: could not register clk %s\n", __func__, name);
kfree(apmclk);
return NULL;
}
return clk;
}
static void xgene_pllclk_init(struct device_node *np, enum xgene_pll_type pll_type)
{
const char *clk_name = np->full_name;
struct clk *clk;
void __iomem *reg;
reg = of_iomap(np, 0);
if (reg == NULL) {
pr_err("Unable to map CSR register for %s\n", np->full_name);
return;
}
of_property_read_string(np, "clock-output-names", &clk_name);
clk = xgene_register_clk_pll(NULL,
clk_name, of_clk_get_parent_name(np, 0),
CLK_IS_ROOT, reg, 0, pll_type, &clk_lock);
if (!IS_ERR(clk)) {
of_clk_add_provider(np, of_clk_src_simple_get, clk);
clk_register_clkdev(clk, clk_name, NULL);
pr_debug("Add %s clock PLL\n", clk_name);
}
}
static void xgene_socpllclk_init(struct device_node *np)
{
xgene_pllclk_init(np, PLL_TYPE_SOC);
}
static void xgene_pcppllclk_init(struct device_node *np)
{
xgene_pllclk_init(np, PLL_TYPE_PCP);
}
static int xgene_clk_enable(struct clk_hw *hw)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
unsigned long flags = 0;
u32 data;
phys_addr_t reg;
if (pclk->lock)
spin_lock_irqsave(pclk->lock, flags);
if (pclk->param.csr_reg != NULL) {
pr_debug("%s clock enabled\n", clk_hw_get_name(hw));
reg = __pa(pclk->param.csr_reg);
data = xgene_clk_read(pclk->param.csr_reg +
pclk->param.reg_clk_offset);
data |= pclk->param.reg_clk_mask;
xgene_clk_write(data, pclk->param.csr_reg +
pclk->param.reg_clk_offset);
pr_debug("%s clock PADDR base %pa clk offset 0x%08X mask 0x%08X value 0x%08X\n",
clk_hw_get_name(hw), &reg,
pclk->param.reg_clk_offset, pclk->param.reg_clk_mask,
data);
data = xgene_clk_read(pclk->param.csr_reg +
pclk->param.reg_csr_offset);
data &= ~pclk->param.reg_csr_mask;
xgene_clk_write(data, pclk->param.csr_reg +
pclk->param.reg_csr_offset);
pr_debug("%s CSR RESET PADDR base %pa csr offset 0x%08X mask 0x%08X value 0x%08X\n",
clk_hw_get_name(hw), &reg,
pclk->param.reg_csr_offset, pclk->param.reg_csr_mask,
data);
}
if (pclk->lock)
spin_unlock_irqrestore(pclk->lock, flags);
return 0;
}
static void xgene_clk_disable(struct clk_hw *hw)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
unsigned long flags = 0;
u32 data;
if (pclk->lock)
spin_lock_irqsave(pclk->lock, flags);
if (pclk->param.csr_reg != NULL) {
pr_debug("%s clock disabled\n", clk_hw_get_name(hw));
data = xgene_clk_read(pclk->param.csr_reg +
pclk->param.reg_csr_offset);
data |= pclk->param.reg_csr_mask;
xgene_clk_write(data, pclk->param.csr_reg +
pclk->param.reg_csr_offset);
data = xgene_clk_read(pclk->param.csr_reg +
pclk->param.reg_clk_offset);
data &= ~pclk->param.reg_clk_mask;
xgene_clk_write(data, pclk->param.csr_reg +
pclk->param.reg_clk_offset);
}
if (pclk->lock)
spin_unlock_irqrestore(pclk->lock, flags);
}
static int xgene_clk_is_enabled(struct clk_hw *hw)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
u32 data = 0;
if (pclk->param.csr_reg != NULL) {
pr_debug("%s clock checking\n", clk_hw_get_name(hw));
data = xgene_clk_read(pclk->param.csr_reg +
pclk->param.reg_clk_offset);
pr_debug("%s clock is %s\n", clk_hw_get_name(hw),
data & pclk->param.reg_clk_mask ? "enabled" :
"disabled");
}
if (pclk->param.csr_reg == NULL)
return 1;
return data & pclk->param.reg_clk_mask ? 1 : 0;
}
static unsigned long xgene_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
u32 data;
if (pclk->param.divider_reg) {
data = xgene_clk_read(pclk->param.divider_reg +
pclk->param.reg_divider_offset);
data >>= pclk->param.reg_divider_shift;
data &= (1 << pclk->param.reg_divider_width) - 1;
pr_debug("%s clock recalc rate %ld parent %ld\n",
clk_hw_get_name(hw),
parent_rate / data, parent_rate);
return parent_rate / data;
} else {
pr_debug("%s clock recalc rate %ld parent %ld\n",
clk_hw_get_name(hw), parent_rate, parent_rate);
return parent_rate;
}
}
static int xgene_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
unsigned long flags = 0;
u32 data;
u32 divider;
u32 divider_save;
if (pclk->lock)
spin_lock_irqsave(pclk->lock, flags);
if (pclk->param.divider_reg) {
if (rate > parent_rate)
rate = parent_rate;
divider_save = divider = parent_rate / rate;
divider &= (1 << pclk->param.reg_divider_width) - 1;
divider <<= pclk->param.reg_divider_shift;
data = xgene_clk_read(pclk->param.divider_reg +
pclk->param.reg_divider_offset);
data &= ~((1 << pclk->param.reg_divider_width) - 1)
<< pclk->param.reg_divider_shift;
data |= divider;
xgene_clk_write(data, pclk->param.divider_reg +
pclk->param.reg_divider_offset);
pr_debug("%s clock set rate %ld\n", clk_hw_get_name(hw),
parent_rate / divider_save);
} else {
divider_save = 1;
}
if (pclk->lock)
spin_unlock_irqrestore(pclk->lock, flags);
return parent_rate / divider_save;
}
static long xgene_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct xgene_clk *pclk = to_xgene_clk(hw);
unsigned long parent_rate = *prate;
u32 divider;
if (pclk->param.divider_reg) {
if (rate > parent_rate)
rate = parent_rate;
divider = parent_rate / rate;
} else {
divider = 1;
}
return parent_rate / divider;
}
static struct clk *xgene_register_clk(struct device *dev,
const char *name, const char *parent_name,
struct xgene_dev_parameters *parameters, spinlock_t *lock)
{
struct xgene_clk *apmclk;
struct clk *clk;
struct clk_init_data init;
int rc;
apmclk = kzalloc(sizeof(*apmclk), GFP_KERNEL);
if (!apmclk) {
pr_err("%s: could not allocate APM clk\n", __func__);
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &xgene_clk_ops;
init.flags = 0;
init.parent_names = parent_name ? &parent_name : NULL;
init.num_parents = parent_name ? 1 : 0;
apmclk->lock = lock;
apmclk->hw.init = &init;
apmclk->param = *parameters;
clk = clk_register(dev, &apmclk->hw);
if (IS_ERR(clk)) {
pr_err("%s: could not register clk %s\n", __func__, name);
kfree(apmclk);
return clk;
}
rc = clk_register_clkdev(clk, name, NULL);
if (rc != 0) {
pr_err("%s: could not register lookup clk %s\n",
__func__, name);
}
return clk;
}
static void __init xgene_devclk_init(struct device_node *np)
{
const char *clk_name = np->full_name;
struct clk *clk;
struct resource res;
int rc;
struct xgene_dev_parameters parameters;
int i;
if (!of_device_is_available(np))
return;
parameters.csr_reg = NULL;
parameters.divider_reg = NULL;
for (i = 0; i < 2; i++) {
void __iomem *map_res;
rc = of_address_to_resource(np, i, &res);
if (rc != 0) {
if (i == 0) {
pr_err("no DTS register for %s\n",
np->full_name);
return;
}
break;
}
map_res = of_iomap(np, i);
if (map_res == NULL) {
pr_err("Unable to map resource %d for %s\n",
i, np->full_name);
goto err;
}
if (strcmp(res.name, "div-reg") == 0)
parameters.divider_reg = map_res;
else
parameters.csr_reg = map_res;
}
if (of_property_read_u32(np, "csr-offset", &parameters.reg_csr_offset))
parameters.reg_csr_offset = 0;
if (of_property_read_u32(np, "csr-mask", &parameters.reg_csr_mask))
parameters.reg_csr_mask = 0xF;
if (of_property_read_u32(np, "enable-offset",
&parameters.reg_clk_offset))
parameters.reg_clk_offset = 0x8;
if (of_property_read_u32(np, "enable-mask", &parameters.reg_clk_mask))
parameters.reg_clk_mask = 0xF;
if (of_property_read_u32(np, "divider-offset",
&parameters.reg_divider_offset))
parameters.reg_divider_offset = 0;
if (of_property_read_u32(np, "divider-width",
&parameters.reg_divider_width))
parameters.reg_divider_width = 0;
if (of_property_read_u32(np, "divider-shift",
&parameters.reg_divider_shift))
parameters.reg_divider_shift = 0;
of_property_read_string(np, "clock-output-names", &clk_name);
clk = xgene_register_clk(NULL, clk_name,
of_clk_get_parent_name(np, 0), &parameters, &clk_lock);
if (IS_ERR(clk))
goto err;
pr_debug("Add %s clock\n", clk_name);
rc = of_clk_add_provider(np, of_clk_src_simple_get, clk);
if (rc != 0)
pr_err("%s: could register provider clk %s\n", __func__,
np->full_name);
return;
err:
if (parameters.csr_reg)
iounmap(parameters.csr_reg);
if (parameters.divider_reg)
iounmap(parameters.divider_reg);
}
