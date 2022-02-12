static int vco_get(struct clk_icst *icst, struct icst_vco *vco)
{
u32 val;
int ret;
ret = regmap_read(icst->map, icst->vcoreg_off, &val);
if (ret)
return ret;
vco->v = val & 0x1ff;
vco->r = (val >> 9) & 0x7f;
vco->s = (val >> 16) & 03;
return 0;
}
static int vco_set(struct clk_icst *icst, struct icst_vco vco)
{
u32 val;
int ret;
ret = regmap_read(icst->map, icst->vcoreg_off, &val);
if (ret)
return ret;
val &= ~0x7ffff;
val |= vco.v | (vco.r << 9) | (vco.s << 16);
ret = regmap_write(icst->map, icst->lockreg_off, VERSATILE_LOCK_VAL);
if (ret)
return ret;
ret = regmap_write(icst->map, icst->vcoreg_off, val);
if (ret)
return ret;
ret = regmap_write(icst->map, icst->lockreg_off, 0);
if (ret)
return ret;
return 0;
}
static unsigned long icst_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
int ret;
if (parent_rate)
icst->params->ref = parent_rate;
ret = vco_get(icst, &vco);
if (ret) {
pr_err("ICST: could not get VCO setting\n");
return 0;
}
icst->rate = icst_hz(icst->params, vco);
return icst->rate;
}
static long icst_round_rate(struct clk_hw *hw, unsigned long rate,
unsigned long *prate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
vco = icst_hz_to_vco(icst->params, rate);
return icst_hz(icst->params, vco);
}
static int icst_set_rate(struct clk_hw *hw, unsigned long rate,
unsigned long parent_rate)
{
struct clk_icst *icst = to_icst(hw);
struct icst_vco vco;
if (parent_rate)
icst->params->ref = parent_rate;
vco = icst_hz_to_vco(icst->params, rate);
icst->rate = icst_hz(icst->params, vco);
return vco_set(icst, vco);
}
static struct clk *icst_clk_setup(struct device *dev,
const struct clk_icst_desc *desc,
const char *name,
const char *parent_name,
struct regmap *map)
{
struct clk *clk;
struct clk_icst *icst;
struct clk_init_data init;
struct icst_params *pclone;
icst = kzalloc(sizeof(struct clk_icst), GFP_KERNEL);
if (!icst) {
pr_err("could not allocate ICST clock!\n");
return ERR_PTR(-ENOMEM);
}
pclone = kmemdup(desc->params, sizeof(*pclone), GFP_KERNEL);
if (!pclone) {
kfree(icst);
pr_err("could not clone ICST params\n");
return ERR_PTR(-ENOMEM);
}
init.name = name;
init.ops = &icst_ops;
init.flags = CLK_IS_ROOT;
init.parent_names = (parent_name ? &parent_name : NULL);
init.num_parents = (parent_name ? 1 : 0);
icst->map = map;
icst->hw.init = &init;
icst->params = pclone;
icst->vcoreg_off = desc->vco_offset;
icst->lockreg_off = desc->lock_offset;
clk = clk_register(dev, &icst->hw);
if (IS_ERR(clk)) {
kfree(pclone);
kfree(icst);
}
return clk;
}
struct clk *icst_clk_register(struct device *dev,
const struct clk_icst_desc *desc,
const char *name,
const char *parent_name,
void __iomem *base)
{
struct regmap_config icst_regmap_conf = {
.reg_bits = 32,
.val_bits = 32,
.reg_stride = 4,
};
struct regmap *map;
map = regmap_init_mmio(dev, base, &icst_regmap_conf);
if (IS_ERR(map)) {
pr_err("could not initialize ICST regmap\n");
return ERR_CAST(map);
}
return icst_clk_setup(dev, desc, name, parent_name, map);
}
static void __init of_syscon_icst_setup(struct device_node *np)
{
struct device_node *parent;
struct regmap *map;
struct clk_icst_desc icst_desc;
const char *name = np->name;
const char *parent_name;
struct clk *regclk;
parent = of_get_parent(np);
if (!parent) {
pr_err("no parent node for syscon ICST clock\n");
return;
}
map = syscon_node_to_regmap(parent);
if (IS_ERR(map)) {
pr_err("no regmap for syscon ICST clock parent\n");
return;
}
if (of_property_read_u32(np, "vco-offset", &icst_desc.vco_offset)) {
pr_err("no VCO register offset for ICST clock\n");
return;
}
if (of_property_read_u32(np, "lock-offset", &icst_desc.lock_offset)) {
pr_err("no lock register offset for ICST clock\n");
return;
}
if (of_device_is_compatible(np, "arm,syscon-icst525"))
icst_desc.params = &icst525_params;
else if (of_device_is_compatible(np, "arm,syscon-icst307"))
icst_desc.params = &icst307_params;
else {
pr_err("unknown ICST clock %s\n", name);
return;
}
parent_name = of_clk_get_parent_name(np, 0);
regclk = icst_clk_setup(NULL, &icst_desc, name, parent_name, map);
if (IS_ERR(regclk)) {
pr_err("error setting up syscon ICST clock %s\n", name);
return;
}
of_clk_add_provider(np, of_clk_src_simple_get, regclk);
pr_debug("registered syscon ICST clock %s\n", name);
}
