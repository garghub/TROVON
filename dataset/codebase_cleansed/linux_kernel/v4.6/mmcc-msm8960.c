static int pix_rdi_set_parent(struct clk_hw *hw, u8 index)
{
int i;
int ret = 0;
u32 val;
struct clk_pix_rdi *rdi = to_clk_pix_rdi(hw);
int num_parents = clk_hw_get_num_parents(hw);
for (i = 0; i < num_parents; i++) {
struct clk_hw *p = clk_hw_get_parent_by_index(hw, i);
ret = clk_prepare_enable(p->clk);
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
for (i--; i >= 0; i--) {
struct clk_hw *p = clk_hw_get_parent_by_index(hw, i);
clk_disable_unprepare(p->clk);
}
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
const struct of_device_id *match;
struct regmap *regmap;
bool is_8064;
struct device *dev = &pdev->dev;
match = of_match_device(mmcc_msm8960_match_table, dev);
if (!match)
return -EINVAL;
is_8064 = of_device_is_compatible(dev->of_node, "qcom,mmcc-apq8064");
if (is_8064) {
gfx3d_src.freq_tbl = clk_tbl_gfx3d_8064;
gfx3d_src.clkr.hw.init = &gfx3d_8064_init;
gfx3d_src.s[0].parent_map = mmcc_pxo_pll8_pll2_pll15_map;
gfx3d_src.s[1].parent_map = mmcc_pxo_pll8_pll2_pll15_map;
}
regmap = qcom_cc_map(pdev, match->data);
if (IS_ERR(regmap))
return PTR_ERR(regmap);
clk_pll_configure_sr(&pll15, regmap, &pll15_config, false);
return qcom_cc_really_probe(pdev, match->data, regmap);
}
