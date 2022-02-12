static inline void atl_write(struct dra7_atl_clock_info *cinfo, u32 reg,
u32 val)
{
__raw_writel(val, cinfo->iobase + reg);
}
static inline int atl_read(struct dra7_atl_clock_info *cinfo, u32 reg)
{
return __raw_readl(cinfo->iobase + reg);
}
static int atl_clk_enable(struct clk_hw *hw)
{
struct dra7_atl_desc *cdesc = to_atl_desc(hw);
if (!cdesc->probed)
goto out;
if (unlikely(!cdesc->valid))
dev_warn(cdesc->cinfo->dev, "atl%d has not been configured\n",
cdesc->id);
pm_runtime_get_sync(cdesc->cinfo->dev);
atl_write(cdesc->cinfo, DRA7_ATL_ATLCR_REG(cdesc->id),
cdesc->divider - 1);
atl_write(cdesc->cinfo, DRA7_ATL_SWEN_REG(cdesc->id), DRA7_ATL_SWEN);
out:
cdesc->enabled = true;
return 0;
}
static void atl_clk_disable(struct clk_hw *hw)
{
struct dra7_atl_desc *cdesc = to_atl_desc(hw);
if (!cdesc->probed)
goto out;
atl_write(cdesc->cinfo, DRA7_ATL_SWEN_REG(cdesc->id), 0);
pm_runtime_put_sync(cdesc->cinfo->dev);
out:
cdesc->enabled = false;
}
static int atl_clk_is_enabled(struct clk_hw *hw)
{
struct dra7_atl_desc *cdesc = to_atl_desc(hw);
return cdesc->enabled;
}
static unsigned long atl_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct dra7_atl_desc *cdesc = to_atl_desc(hw);
return parent_rate / cdesc->divider;
}
static long atl_clk_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *parent_rate)
{
unsigned divider;
divider = (*parent_rate + rate / 2) / rate;
if (divider > DRA7_ATL_DIVIDER_MASK + 1)
divider = DRA7_ATL_DIVIDER_MASK + 1;
return *parent_rate / divider;
}
static int atl_clk_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct dra7_atl_desc *cdesc = to_atl_desc(hw);
u32 divider;
divider = ((parent_rate + rate / 2) / rate) - 1;
if (divider > DRA7_ATL_DIVIDER_MASK)
divider = DRA7_ATL_DIVIDER_MASK;
cdesc->divider = divider + 1;
return 0;
}
static void __init of_dra7_atl_clock_setup(struct device_node *node)
{
struct dra7_atl_desc *clk_hw = NULL;
struct clk_init_data init = { 0 };
const char **parent_names = NULL;
struct clk *clk;
clk_hw = kzalloc(sizeof(*clk_hw), GFP_KERNEL);
if (!clk_hw) {
pr_err("%s: could not allocate dra7_atl_desc\n", __func__);
return;
}
clk_hw->hw.init = &init;
clk_hw->divider = 1;
init.name = node->name;
init.ops = &atl_clk_ops;
init.flags = CLK_IGNORE_UNUSED;
init.num_parents = of_clk_get_parent_count(node);
if (init.num_parents != 1) {
pr_err("%s: atl clock %s must have 1 parent\n", __func__,
node->name);
goto cleanup;
}
parent_names = kzalloc(sizeof(char *), GFP_KERNEL);
if (!parent_names)
goto cleanup;
parent_names[0] = of_clk_get_parent_name(node, 0);
init.parent_names = parent_names;
clk = clk_register(NULL, &clk_hw->hw);
if (!IS_ERR(clk)) {
of_clk_add_provider(node, of_clk_src_simple_get, clk);
return;
}
cleanup:
kfree(parent_names);
kfree(clk_hw);
}
static int of_dra7_atl_clk_probe(struct platform_device *pdev)
{
struct device_node *node = pdev->dev.of_node;
struct dra7_atl_clock_info *cinfo;
int i;
int ret = 0;
if (!node)
return -ENODEV;
cinfo = devm_kzalloc(&pdev->dev, sizeof(*cinfo), GFP_KERNEL);
if (!cinfo)
return -ENOMEM;
cinfo->iobase = of_iomap(node, 0);
cinfo->dev = &pdev->dev;
pm_runtime_enable(cinfo->dev);
pm_runtime_get_sync(cinfo->dev);
atl_write(cinfo, DRA7_ATL_PCLKMUX_REG(0), DRA7_ATL_PCLKMUX);
for (i = 0; i < DRA7_ATL_INSTANCES; i++) {
struct device_node *cfg_node;
char prop[5];
struct dra7_atl_desc *cdesc;
struct of_phandle_args clkspec;
struct clk *clk;
int rc;
rc = of_parse_phandle_with_args(node, "ti,provided-clocks",
NULL, i, &clkspec);
if (rc) {
pr_err("%s: failed to lookup atl clock %d\n", __func__,
i);
return -EINVAL;
}
clk = of_clk_get_from_provider(&clkspec);
cdesc = to_atl_desc(__clk_get_hw(clk));
cdesc->cinfo = cinfo;
cdesc->id = i;
snprintf(prop, sizeof(prop), "atl%u", i);
cfg_node = of_find_node_by_name(node, prop);
if (cfg_node) {
ret = of_property_read_u32(cfg_node, "bws",
&cdesc->bws);
ret |= of_property_read_u32(cfg_node, "aws",
&cdesc->aws);
if (!ret) {
cdesc->valid = true;
atl_write(cinfo, DRA7_ATL_BWSMUX_REG(i),
cdesc->bws);
atl_write(cinfo, DRA7_ATL_AWSMUX_REG(i),
cdesc->aws);
}
}
cdesc->probed = true;
if (cdesc->enabled)
atl_clk_enable(__clk_get_hw(clk));
}
pm_runtime_put_sync(cinfo->dev);
return ret;
}
static int of_dra7_atl_clk_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
