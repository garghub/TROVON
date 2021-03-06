static int cpg_mstp_clock_endisable(struct clk_hw *hw, bool enable)
{
struct mstp_clock *clock = to_mstp_clock(hw);
struct cpg_mssr_priv *priv = clock->priv;
unsigned int reg = clock->index / 32;
unsigned int bit = clock->index % 32;
struct device *dev = priv->dev;
u32 bitmask = BIT(bit);
unsigned long flags;
unsigned int i;
u32 value;
dev_dbg(dev, "MSTP %u%02u/%pC %s\n", reg, bit, hw->clk,
enable ? "ON" : "OFF");
spin_lock_irqsave(&priv->mstp_lock, flags);
value = clk_readl(priv->base + SMSTPCR(reg));
if (enable)
value &= ~bitmask;
else
value |= bitmask;
clk_writel(value, priv->base + SMSTPCR(reg));
spin_unlock_irqrestore(&priv->mstp_lock, flags);
if (!enable)
return 0;
for (i = 1000; i > 0; --i) {
if (!(clk_readl(priv->base + MSTPSR(reg)) &
bitmask))
break;
cpu_relax();
}
if (!i) {
dev_err(dev, "Failed to enable SMSTP %p[%d]\n",
priv->base + SMSTPCR(reg), bit);
return -ETIMEDOUT;
}
return 0;
}
static int cpg_mstp_clock_enable(struct clk_hw *hw)
{
return cpg_mstp_clock_endisable(hw, true);
}
static void cpg_mstp_clock_disable(struct clk_hw *hw)
{
cpg_mstp_clock_endisable(hw, false);
}
static int cpg_mstp_clock_is_enabled(struct clk_hw *hw)
{
struct mstp_clock *clock = to_mstp_clock(hw);
struct cpg_mssr_priv *priv = clock->priv;
u32 value;
value = clk_readl(priv->base + MSTPSR(clock->index / 32));
return !(value & BIT(clock->index % 32));
}
static
struct clk *cpg_mssr_clk_src_twocell_get(struct of_phandle_args *clkspec,
void *data)
{
unsigned int clkidx = clkspec->args[1];
struct cpg_mssr_priv *priv = data;
struct device *dev = priv->dev;
unsigned int idx;
const char *type;
struct clk *clk;
switch (clkspec->args[0]) {
case CPG_CORE:
type = "core";
if (clkidx > priv->last_dt_core_clk) {
dev_err(dev, "Invalid %s clock index %u\n", type,
clkidx);
return ERR_PTR(-EINVAL);
}
clk = priv->clks[clkidx];
break;
case CPG_MOD:
type = "module";
idx = MOD_CLK_PACK(clkidx);
if (clkidx % 100 > 31 || idx >= priv->num_mod_clks) {
dev_err(dev, "Invalid %s clock index %u\n", type,
clkidx);
return ERR_PTR(-EINVAL);
}
clk = priv->clks[priv->num_core_clks + idx];
break;
default:
dev_err(dev, "Invalid CPG clock type %u\n", clkspec->args[0]);
return ERR_PTR(-EINVAL);
}
if (IS_ERR(clk))
dev_err(dev, "Cannot get %s clock %u: %ld", type, clkidx,
PTR_ERR(clk));
else
dev_dbg(dev, "clock (%u, %u) is %pC at %pCr Hz\n",
clkspec->args[0], clkspec->args[1], clk, clk);
return clk;
}
static void __init cpg_mssr_register_core_clk(const struct cpg_core_clk *core,
const struct cpg_mssr_info *info,
struct cpg_mssr_priv *priv)
{
struct clk *clk = NULL, *parent;
struct device *dev = priv->dev;
unsigned int id = core->id, div = core->div;
const char *parent_name;
WARN_DEBUG(id >= priv->num_core_clks);
WARN_DEBUG(PTR_ERR(priv->clks[id]) != -ENOENT);
switch (core->type) {
case CLK_TYPE_IN:
clk = of_clk_get_by_name(priv->dev->of_node, core->name);
break;
case CLK_TYPE_FF:
case CLK_TYPE_DIV6P1:
case CLK_TYPE_DIV6_RO:
WARN_DEBUG(core->parent >= priv->num_core_clks);
parent = priv->clks[core->parent];
if (IS_ERR(parent)) {
clk = parent;
goto fail;
}
parent_name = __clk_get_name(parent);
if (core->type == CLK_TYPE_DIV6_RO)
div *= (readl(priv->base + core->offset) & 0x3f) + 1;
if (core->type == CLK_TYPE_DIV6P1) {
clk = cpg_div6_register(core->name, 1, &parent_name,
priv->base + core->offset);
} else {
clk = clk_register_fixed_factor(NULL, core->name,
parent_name, 0,
core->mult, div);
}
break;
default:
if (info->cpg_clk_register)
clk = info->cpg_clk_register(dev, core, info,
priv->clks, priv->base);
else
dev_err(dev, "%s has unsupported core clock type %u\n",
core->name, core->type);
break;
}
if (IS_ERR_OR_NULL(clk))
goto fail;
dev_dbg(dev, "Core clock %pC at %pCr Hz\n", clk, clk);
priv->clks[id] = clk;
return;
fail:
dev_err(dev, "Failed to register %s clock %s: %ld\n", "core,",
core->name, PTR_ERR(clk));
}
static void __init cpg_mssr_register_mod_clk(const struct mssr_mod_clk *mod,
const struct cpg_mssr_info *info,
struct cpg_mssr_priv *priv)
{
struct mstp_clock *clock = NULL;
struct device *dev = priv->dev;
unsigned int id = mod->id;
struct clk_init_data init;
struct clk *parent, *clk;
const char *parent_name;
unsigned int i;
WARN_DEBUG(id < priv->num_core_clks);
WARN_DEBUG(id >= priv->num_core_clks + priv->num_mod_clks);
WARN_DEBUG(mod->parent >= priv->num_core_clks + priv->num_mod_clks);
WARN_DEBUG(PTR_ERR(priv->clks[id]) != -ENOENT);
parent = priv->clks[mod->parent];
if (IS_ERR(parent)) {
clk = parent;
goto fail;
}
clock = kzalloc(sizeof(*clock), GFP_KERNEL);
if (!clock) {
clk = ERR_PTR(-ENOMEM);
goto fail;
}
init.name = mod->name;
init.ops = &cpg_mstp_clock_ops;
init.flags = CLK_IS_BASIC | CLK_SET_RATE_PARENT;
for (i = 0; i < info->num_crit_mod_clks; i++)
if (id == info->crit_mod_clks[i]) {
#ifdef CLK_ENABLE_HAND_OFF
dev_dbg(dev, "MSTP %s setting CLK_ENABLE_HAND_OFF\n",
mod->name);
init.flags |= CLK_ENABLE_HAND_OFF;
break;
#else
dev_dbg(dev, "Ignoring MSTP %s to prevent disabling\n",
mod->name);
kfree(clock);
return;
#endif
}
parent_name = __clk_get_name(parent);
init.parent_names = &parent_name;
init.num_parents = 1;
clock->index = id - priv->num_core_clks;
clock->priv = priv;
clock->hw.init = &init;
clk = clk_register(NULL, &clock->hw);
if (IS_ERR(clk))
goto fail;
dev_dbg(dev, "Module clock %pC at %pCr Hz\n", clk, clk);
priv->clks[id] = clk;
return;
fail:
dev_err(dev, "Failed to register %s clock %s: %ld\n", "module,",
mod->name, PTR_ERR(clk));
kfree(clock);
}
static bool cpg_mssr_is_pm_clk(const struct of_phandle_args *clkspec,
struct cpg_mssr_clk_domain *pd)
{
unsigned int i;
if (clkspec->np != pd->np || clkspec->args_count != 2)
return false;
switch (clkspec->args[0]) {
case CPG_CORE:
for (i = 0; i < pd->num_core_pm_clks; i++)
if (clkspec->args[1] == pd->core_pm_clks[i])
return true;
return false;
case CPG_MOD:
return true;
default:
return false;
}
}
int cpg_mssr_attach_dev(struct generic_pm_domain *unused, struct device *dev)
{
struct cpg_mssr_clk_domain *pd = cpg_mssr_clk_domain;
struct device_node *np = dev->of_node;
struct of_phandle_args clkspec;
struct clk *clk;
int i = 0;
int error;
if (!pd) {
dev_dbg(dev, "CPG/MSSR clock domain not yet available\n");
return -EPROBE_DEFER;
}
while (!of_parse_phandle_with_args(np, "clocks", "#clock-cells", i,
&clkspec)) {
if (cpg_mssr_is_pm_clk(&clkspec, pd))
goto found;
of_node_put(clkspec.np);
i++;
}
return 0;
found:
clk = of_clk_get_from_provider(&clkspec);
of_node_put(clkspec.np);
if (IS_ERR(clk))
return PTR_ERR(clk);
error = pm_clk_create(dev);
if (error) {
dev_err(dev, "pm_clk_create failed %d\n", error);
goto fail_put;
}
error = pm_clk_add_clk(dev, clk);
if (error) {
dev_err(dev, "pm_clk_add_clk %pC failed %d\n", clk, error);
goto fail_destroy;
}
return 0;
fail_destroy:
pm_clk_destroy(dev);
fail_put:
clk_put(clk);
return error;
}
void cpg_mssr_detach_dev(struct generic_pm_domain *unused, struct device *dev)
{
if (!list_empty(&dev->power.subsys_data->clock_list))
pm_clk_destroy(dev);
}
static int __init cpg_mssr_add_clk_domain(struct device *dev,
const unsigned int *core_pm_clks,
unsigned int num_core_pm_clks)
{
struct device_node *np = dev->of_node;
struct generic_pm_domain *genpd;
struct cpg_mssr_clk_domain *pd;
size_t pm_size = num_core_pm_clks * sizeof(core_pm_clks[0]);
pd = devm_kzalloc(dev, sizeof(*pd) + pm_size, GFP_KERNEL);
if (!pd)
return -ENOMEM;
pd->np = np;
pd->num_core_pm_clks = num_core_pm_clks;
memcpy(pd->core_pm_clks, core_pm_clks, pm_size);
genpd = &pd->genpd;
genpd->name = np->name;
genpd->flags = GENPD_FLAG_PM_CLK;
genpd->attach_dev = cpg_mssr_attach_dev;
genpd->detach_dev = cpg_mssr_detach_dev;
pm_genpd_init(genpd, &pm_domain_always_on_gov, false);
cpg_mssr_clk_domain = pd;
of_genpd_add_provider_simple(np, genpd);
return 0;
}
static void cpg_mssr_del_clk_provider(void *data)
{
of_clk_del_provider(data);
}
static int __init cpg_mssr_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
const struct cpg_mssr_info *info;
struct cpg_mssr_priv *priv;
unsigned int nclks, i;
struct resource *res;
struct clk **clks;
int error;
info = of_match_node(cpg_mssr_match, np)->data;
if (info->init) {
error = info->init(dev);
if (error)
return error;
}
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->dev = dev;
spin_lock_init(&priv->mstp_lock);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(dev, res);
if (IS_ERR(priv->base))
return PTR_ERR(priv->base);
nclks = info->num_total_core_clks + info->num_hw_mod_clks;
clks = devm_kmalloc_array(dev, nclks, sizeof(*clks), GFP_KERNEL);
if (!clks)
return -ENOMEM;
priv->clks = clks;
priv->num_core_clks = info->num_total_core_clks;
priv->num_mod_clks = info->num_hw_mod_clks;
priv->last_dt_core_clk = info->last_dt_core_clk;
for (i = 0; i < nclks; i++)
clks[i] = ERR_PTR(-ENOENT);
for (i = 0; i < info->num_core_clks; i++)
cpg_mssr_register_core_clk(&info->core_clks[i], info, priv);
for (i = 0; i < info->num_mod_clks; i++)
cpg_mssr_register_mod_clk(&info->mod_clks[i], info, priv);
error = of_clk_add_provider(np, cpg_mssr_clk_src_twocell_get, priv);
if (error)
return error;
error = devm_add_action_or_reset(dev,
cpg_mssr_del_clk_provider,
np);
if (error)
return error;
error = cpg_mssr_add_clk_domain(dev, info->core_pm_clks,
info->num_core_pm_clks);
if (error)
return error;
return 0;
}
static int __init cpg_mssr_init(void)
{
return platform_driver_probe(&cpg_mssr_driver, cpg_mssr_probe);
}
