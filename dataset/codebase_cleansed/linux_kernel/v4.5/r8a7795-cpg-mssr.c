static
struct clk * __init r8a7795_cpg_clk_register(struct device *dev,
const struct cpg_core_clk *core,
const struct cpg_mssr_info *info,
struct clk **clks,
void __iomem *base)
{
const struct clk *parent;
unsigned int mult = 1;
unsigned int div = 1;
u32 value;
parent = clks[core->parent];
if (IS_ERR(parent))
return ERR_CAST(parent);
switch (core->type) {
case CLK_TYPE_GEN3_MAIN:
div = cpg_pll_config->extal_div;
break;
case CLK_TYPE_GEN3_PLL0:
value = readl(base + CPG_PLL0CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
break;
case CLK_TYPE_GEN3_PLL1:
mult = cpg_pll_config->pll1_mult;
break;
case CLK_TYPE_GEN3_PLL2:
value = readl(base + CPG_PLL2CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
break;
case CLK_TYPE_GEN3_PLL3:
mult = cpg_pll_config->pll3_mult;
break;
case CLK_TYPE_GEN3_PLL4:
value = readl(base + CPG_PLL4CR);
mult = (((value >> 24) & 0x7f) + 1) * 2;
break;
default:
return ERR_PTR(-EINVAL);
}
return clk_register_fixed_factor(NULL, core->name,
__clk_get_name(parent), 0, mult, div);
}
static u32 rcar_gen3_read_mode_pins(void)
{
void __iomem *modemr = ioremap_nocache(MODEMR, 4);
u32 mode;
BUG_ON(!modemr);
mode = ioread32(modemr);
iounmap(modemr);
return mode;
}
static int __init r8a7795_cpg_mssr_init(struct device *dev)
{
u32 cpg_mode = rcar_gen3_read_mode_pins();
cpg_pll_config = &cpg_pll_configs[CPG_PLL_CONFIG_INDEX(cpg_mode)];
if (!cpg_pll_config->extal_div) {
dev_err(dev, "Prohibited setting (cpg_mode=0x%x)\n", cpg_mode);
return -EINVAL;
}
return 0;
}
