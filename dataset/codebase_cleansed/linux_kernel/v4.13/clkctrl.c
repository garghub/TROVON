static u32 _omap4_idlest(u32 val)
{
val &= OMAP4_IDLEST_MASK;
val >>= OMAP4_IDLEST_SHIFT;
return val;
}
static bool _omap4_is_idle(u32 val)
{
val = _omap4_idlest(val);
return val == CLKCTRL_IDLEST_DISABLED;
}
static bool _omap4_is_ready(u32 val)
{
val = _omap4_idlest(val);
return val == CLKCTRL_IDLEST_FUNCTIONAL ||
val == CLKCTRL_IDLEST_INTERFACE_IDLE;
}
static bool _omap4_is_timeout(union omap4_timeout *time, u32 timeout)
{
if (unlikely(_early_timeout)) {
if (time->cycles++ < timeout) {
udelay(1);
return false;
}
} else {
if (!ktime_to_ns(time->start)) {
time->start = ktime_get();
return false;
}
if (ktime_us_delta(ktime_get(), time->start) < timeout) {
cpu_relax();
return false;
}
}
return true;
}
static int __init _omap4_disable_early_timeout(void)
{
_early_timeout = false;
return 0;
}
static int _omap4_clkctrl_clk_enable(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 val;
int ret;
union omap4_timeout timeout = { 0 };
if (!clk->enable_bit)
return 0;
if (clk->clkdm) {
ret = ti_clk_ll_ops->clkdm_clk_enable(clk->clkdm, hw->clk);
if (ret) {
WARN(1,
"%s: could not enable %s's clockdomain %s: %d\n",
__func__, clk_hw_get_name(hw),
clk->clkdm_name, ret);
return ret;
}
}
val = ti_clk_ll_ops->clk_readl(&clk->enable_reg);
val &= ~OMAP4_MODULEMODE_MASK;
val |= clk->enable_bit;
ti_clk_ll_ops->clk_writel(val, &clk->enable_reg);
if (clk->flags & NO_IDLEST)
return 0;
while (!_omap4_is_ready(ti_clk_ll_ops->clk_readl(&clk->enable_reg))) {
if (_omap4_is_timeout(&timeout, OMAP4_MAX_MODULE_READY_TIME)) {
pr_err("%s: failed to enable\n", clk_hw_get_name(hw));
return -EBUSY;
}
}
return 0;
}
static void _omap4_clkctrl_clk_disable(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 val;
union omap4_timeout timeout = { 0 };
if (!clk->enable_bit)
return;
val = ti_clk_ll_ops->clk_readl(&clk->enable_reg);
val &= ~OMAP4_MODULEMODE_MASK;
ti_clk_ll_ops->clk_writel(val, &clk->enable_reg);
if (clk->flags & NO_IDLEST)
goto exit;
while (!_omap4_is_idle(ti_clk_ll_ops->clk_readl(&clk->enable_reg))) {
if (_omap4_is_timeout(&timeout,
OMAP4_MAX_MODULE_DISABLE_TIME)) {
pr_err("%s: failed to disable\n", clk_hw_get_name(hw));
break;
}
}
exit:
if (clk->clkdm)
ti_clk_ll_ops->clkdm_clk_disable(clk->clkdm, hw->clk);
}
static int _omap4_clkctrl_clk_is_enabled(struct clk_hw *hw)
{
struct clk_hw_omap *clk = to_clk_hw_omap(hw);
u32 val;
val = ti_clk_ll_ops->clk_readl(&clk->enable_reg);
if (val & clk->enable_bit)
return 1;
return 0;
}
static struct clk_hw *_ti_omap4_clkctrl_xlate(struct of_phandle_args *clkspec,
void *data)
{
struct omap_clkctrl_provider *provider = data;
struct omap_clkctrl_clk *entry;
if (clkspec->args_count != 2)
return ERR_PTR(-EINVAL);
pr_debug("%s: looking for %x:%x\n", __func__,
clkspec->args[0], clkspec->args[1]);
list_for_each_entry(entry, &provider->clocks, node) {
if (entry->reg_offset == clkspec->args[0] &&
entry->bit_offset == clkspec->args[1])
break;
}
if (!entry)
return ERR_PTR(-EINVAL);
return entry->clk;
}
static int __init
_ti_clkctrl_clk_register(struct omap_clkctrl_provider *provider,
struct device_node *node, struct clk_hw *clk_hw,
u16 offset, u8 bit, const char * const *parents,
int num_parents, const struct clk_ops *ops)
{
struct clk_init_data init = { NULL };
struct clk *clk;
struct omap_clkctrl_clk *clkctrl_clk;
int ret = 0;
init.name = kasprintf(GFP_KERNEL, "%s:%s:%04x:%d", node->parent->name,
node->name, offset, bit);
clkctrl_clk = kzalloc(sizeof(*clkctrl_clk), GFP_KERNEL);
if (!init.name || !clkctrl_clk) {
ret = -ENOMEM;
goto cleanup;
}
clk_hw->init = &init;
init.parent_names = parents;
init.num_parents = num_parents;
init.ops = ops;
init.flags = CLK_IS_BASIC;
clk = ti_clk_register(NULL, clk_hw, init.name);
if (IS_ERR_OR_NULL(clk)) {
ret = -EINVAL;
goto cleanup;
}
clkctrl_clk->reg_offset = offset;
clkctrl_clk->bit_offset = bit;
clkctrl_clk->clk = clk_hw;
list_add(&clkctrl_clk->node, &provider->clocks);
return 0;
cleanup:
kfree(init.name);
kfree(clkctrl_clk);
return ret;
}
static void __init
_ti_clkctrl_setup_gate(struct omap_clkctrl_provider *provider,
struct device_node *node, u16 offset,
const struct omap_clkctrl_bit_data *data,
void __iomem *reg)
{
struct clk_hw_omap *clk_hw;
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!clk_hw)
return;
clk_hw->enable_bit = data->bit;
clk_hw->enable_reg.ptr = reg;
if (_ti_clkctrl_clk_register(provider, node, &clk_hw->hw, offset,
data->bit, data->parents, 1,
&omap_gate_clk_ops))
kfree(clk_hw);
}
static void __init
_ti_clkctrl_setup_mux(struct omap_clkctrl_provider *provider,
struct device_node *node, u16 offset,
const struct omap_clkctrl_bit_data *data,
void __iomem *reg)
{
struct clk_omap_mux *mux;
int num_parents = 0;
const char * const *pname;
mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux)
return;
pname = data->parents;
while (*pname) {
num_parents++;
pname++;
}
mux->mask = num_parents;
mux->mask = (1 << fls(mux->mask)) - 1;
mux->shift = data->bit;
mux->reg.ptr = reg;
if (_ti_clkctrl_clk_register(provider, node, &mux->hw, offset,
data->bit, data->parents, num_parents,
&ti_clk_mux_ops))
kfree(mux);
}
static void __init
_ti_clkctrl_setup_div(struct omap_clkctrl_provider *provider,
struct device_node *node, u16 offset,
const struct omap_clkctrl_bit_data *data,
void __iomem *reg)
{
struct clk_omap_divider *div;
const struct omap_clkctrl_div_data *div_data = data->data;
div = kzalloc(sizeof(*div), GFP_KERNEL);
if (!div)
return;
div->reg.ptr = reg;
div->shift = data->bit;
if (ti_clk_parse_divider_data((int *)div_data->dividers,
div_data->max_div, 0, 0,
&div->width, &div->table)) {
pr_err("%s: Data parsing for %s:%04x:%d failed\n", __func__,
node->name, offset, data->bit);
kfree(div);
return;
}
if (_ti_clkctrl_clk_register(provider, node, &div->hw, offset,
data->bit, data->parents, 1,
&ti_clk_divider_ops))
kfree(div);
}
static void __init
_ti_clkctrl_setup_subclks(struct omap_clkctrl_provider *provider,
struct device_node *node,
const struct omap_clkctrl_reg_data *data,
void __iomem *reg)
{
const struct omap_clkctrl_bit_data *bits = data->bit_data;
if (!bits)
return;
while (bits->bit) {
switch (bits->type) {
case TI_CLK_GATE:
_ti_clkctrl_setup_gate(provider, node, data->offset,
bits, reg);
break;
case TI_CLK_DIVIDER:
_ti_clkctrl_setup_div(provider, node, data->offset,
bits, reg);
break;
case TI_CLK_MUX:
_ti_clkctrl_setup_mux(provider, node, data->offset,
bits, reg);
break;
default:
pr_err("%s: bad subclk type: %d\n", __func__,
bits->type);
return;
}
bits++;
}
}
static void __init _ti_omap4_clkctrl_setup(struct device_node *node)
{
struct omap_clkctrl_provider *provider;
const struct omap_clkctrl_data *data = default_clkctrl_data;
const struct omap_clkctrl_reg_data *reg_data;
struct clk_init_data init = { NULL };
struct clk_hw_omap *hw;
struct clk *clk;
struct omap_clkctrl_clk *clkctrl_clk;
const __be32 *addrp;
u32 addr;
addrp = of_get_address(node, 0, NULL, NULL);
addr = (u32)of_translate_address(node, addrp);
#ifdef CONFIG_ARCH_OMAP4
if (of_machine_is_compatible("ti,omap4"))
data = omap4_clkctrl_data;
#endif
while (data->addr) {
if (addr == data->addr)
break;
data++;
}
if (!data->addr) {
pr_err("%s not found from clkctrl data.\n", node->name);
return;
}
provider = kzalloc(sizeof(*provider), GFP_KERNEL);
if (!provider)
return;
provider->base = of_iomap(node, 0);
INIT_LIST_HEAD(&provider->clocks);
reg_data = data->regs;
while (reg_data->parent) {
hw = kzalloc(sizeof(*hw), GFP_KERNEL);
if (!hw)
return;
hw->enable_reg.ptr = provider->base + reg_data->offset;
_ti_clkctrl_setup_subclks(provider, node, reg_data,
hw->enable_reg.ptr);
if (reg_data->flags & CLKF_SW_SUP)
hw->enable_bit = MODULEMODE_SWCTRL;
if (reg_data->flags & CLKF_HW_SUP)
hw->enable_bit = MODULEMODE_HWCTRL;
if (reg_data->flags & CLKF_NO_IDLEST)
hw->flags |= NO_IDLEST;
init.parent_names = &reg_data->parent;
init.num_parents = 1;
init.flags = 0;
init.name = kasprintf(GFP_KERNEL, "%s:%s:%04x:%d",
node->parent->name, node->name,
reg_data->offset, 0);
clkctrl_clk = kzalloc(sizeof(*clkctrl_clk), GFP_KERNEL);
if (!init.name || !clkctrl_clk)
goto cleanup;
init.ops = &omap4_clkctrl_clk_ops;
hw->hw.init = &init;
clk = ti_clk_register(NULL, &hw->hw, init.name);
if (IS_ERR_OR_NULL(clk))
goto cleanup;
clkctrl_clk->reg_offset = reg_data->offset;
clkctrl_clk->clk = &hw->hw;
list_add(&clkctrl_clk->node, &provider->clocks);
reg_data++;
}
of_clk_add_hw_provider(node, _ti_omap4_clkctrl_xlate, provider);
return;
cleanup:
kfree(hw);
kfree(init.name);
kfree(clkctrl_clk);
}
