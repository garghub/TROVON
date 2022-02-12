static unsigned long
axxia_pllclk_recalc(struct clk_hw *hw, unsigned long parent_rate)
{
struct axxia_clk *aclk = to_axxia_clk(hw);
struct axxia_pllclk *pll = to_axxia_pllclk(aclk);
unsigned long rate, fbdiv, refdiv, postdiv;
u32 control;
regmap_read(aclk->regmap, pll->reg, &control);
postdiv = ((control >> 0) & 0xf) + 1;
fbdiv = ((control >> 4) & 0xfff) + 3;
refdiv = ((control >> 16) & 0x1f) + 1;
rate = (parent_rate / (refdiv * postdiv)) * fbdiv;
return rate;
}
static unsigned long
axxia_divclk_recalc_rate(struct clk_hw *hw, unsigned long parent_rate)
{
struct axxia_clk *aclk = to_axxia_clk(hw);
struct axxia_divclk *divclk = to_axxia_divclk(aclk);
u32 ctrl, div;
regmap_read(aclk->regmap, divclk->reg, &ctrl);
div = 1 + ((ctrl >> divclk->shift) & ((1 << divclk->width)-1));
return parent_rate / div;
}
static u8 axxia_clkmux_get_parent(struct clk_hw *hw)
{
struct axxia_clk *aclk = to_axxia_clk(hw);
struct axxia_clkmux *mux = to_axxia_clkmux(aclk);
u32 ctrl, parent;
regmap_read(aclk->regmap, mux->reg, &ctrl);
parent = (ctrl >> mux->shift) & ((1 << mux->width) - 1);
return (u8) parent;
}
static int axmclk_probe(struct platform_device *pdev)
{
void __iomem *base;
struct resource *res;
int i, ret;
struct device *dev = &pdev->dev;
struct clk *clk;
struct regmap *regmap;
size_t num_clks;
struct axmclk_priv *priv;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = devm_regmap_init_mmio(dev, base, &axmclk_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
num_clks = ARRAY_SIZE(axmclk_clocks);
pr_info("axmclk: supporting %zu clocks\n", num_clks);
priv = devm_kzalloc(dev, sizeof(*priv) + sizeof(*priv->clks) * num_clks,
GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->onecell.clks = priv->clks;
priv->onecell.clk_num = num_clks;
for (i = 0; i < num_clks; i++) {
axmclk_clocks[i]->regmap = regmap;
clk = devm_clk_register(dev, &axmclk_clocks[i]->hw);
if (IS_ERR(clk))
return PTR_ERR(clk);
priv->clks[i] = clk;
}
ret = of_clk_add_provider(dev->of_node,
of_clk_src_onecell_get, &priv->onecell);
return ret;
}
static int axmclk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
return 0;
}
static int __init axmclk_init(void)
{
return platform_driver_register(&axmclk_driver);
}
static void __exit axmclk_exit(void)
{
platform_driver_unregister(&axmclk_driver);
}
