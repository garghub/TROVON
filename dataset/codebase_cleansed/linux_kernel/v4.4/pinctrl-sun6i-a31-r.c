static int sun6i_a31_r_pinctrl_probe(struct platform_device *pdev)
{
struct reset_control *rstc;
int ret;
rstc = devm_reset_control_get(&pdev->dev, NULL);
if (IS_ERR(rstc)) {
dev_err(&pdev->dev, "Reset controller missing\n");
return PTR_ERR(rstc);
}
ret = reset_control_deassert(rstc);
if (ret)
return ret;
ret = sunxi_pinctrl_init(pdev,
&sun6i_a31_r_pinctrl_data);
if (ret)
reset_control_assert(rstc);
return ret;
}
