static int pix_rdi_set_parent(struct clk_hw *hw, u8 index)
{
int i;
int ret = 0;
u32 val;
struct clk_pix_rdi *rdi = to_clk_pix_rdi(hw);
struct clk *clk = hw->clk;
int num_parents = __clk_get_num_parents(hw->clk);
for (i = 0; i < num_parents; i++) {
ret = clk_prepare_enable(clk_get_parent_by_index(clk, i));
if (ret)
goto err;
}
if (index == 2)
val = rdi->s2_mask;
else
val = 0;
regmap_update_bits(rdi->clkr.regmap, rdi->s2_reg, rdi->s2_mask, val);
udelay(1);
if (index == 1)
val = rdi->s_mask;
else
val = 0;
regmap_update_bits(rdi->clkr.regmap, rdi->s_reg, rdi->s_mask, val);
udelay(1);
err:
for (i--; i >= 0; i--)
clk_disable_unprepare(clk_get_parent_by_index(clk, i));
return ret;
}
static u8 pix_rdi_get_parent(struct clk_hw *hw)
{
u32 val;
struct clk_pix_rdi *rdi = to_clk_pix_rdi(hw);
regmap_read(rdi->clkr.regmap, rdi->s2_reg, &val);
if (val & rdi->s2_mask)
return 2;
regmap_read(rdi->clkr.regmap, rdi->s_reg, &val);
if (val & rdi->s_mask)
return 1;
return 0;
}
static int mmcc_msm8960_probe(struct platform_device *pdev)
{
void __iomem *base;
struct resource *res;
int i, ret;
struct device *dev = &pdev->dev;
struct clk *clk;
struct clk_onecell_data *data;
struct clk **clks;
struct regmap *regmap;
size_t num_clks;
struct qcom_reset_controller *reset;
struct qcom_cc *cc;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
regmap = devm_regmap_init_mmio(dev, base, &mmcc_msm8960_regmap_config);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
num_clks = ARRAY_SIZE(mmcc_msm8960_clks);
cc = devm_kzalloc(dev, sizeof(*cc) + sizeof(*clks) * num_clks,
GFP_KERNEL);
if (!cc)
return -ENOMEM;
clks = cc->clks;
data = &cc->data;
data->clks = clks;
data->clk_num = num_clks;
for (i = 0; i < num_clks; i++) {
if (!mmcc_msm8960_clks[i])
continue;
clk = devm_clk_register_regmap(dev, mmcc_msm8960_clks[i]);
if (IS_ERR(clk))
return PTR_ERR(clk);
clks[i] = clk;
}
ret = of_clk_add_provider(dev->of_node, of_clk_src_onecell_get, data);
if (ret)
return ret;
reset = &cc->reset;
reset->rcdev.of_node = dev->of_node;
reset->rcdev.ops = &qcom_reset_ops,
reset->rcdev.owner = THIS_MODULE,
reset->rcdev.nr_resets = ARRAY_SIZE(mmcc_msm8960_resets),
reset->regmap = regmap;
reset->reset_map = mmcc_msm8960_resets,
platform_set_drvdata(pdev, &reset->rcdev);
ret = reset_controller_register(&reset->rcdev);
if (ret)
of_clk_del_provider(dev->of_node);
return ret;
}
static int mmcc_msm8960_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
reset_controller_unregister(platform_get_drvdata(pdev));
return 0;
}
