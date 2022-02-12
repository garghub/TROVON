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
return qcom_cc_probe(pdev, &mmcc_msm8960_desc);
}
static int mmcc_msm8960_remove(struct platform_device *pdev)
{
qcom_cc_remove(pdev);
return 0;
}
