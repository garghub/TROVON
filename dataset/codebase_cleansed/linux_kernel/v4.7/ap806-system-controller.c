static int ap806_syscon_clk_probe(struct platform_device *pdev)
{
unsigned int freq_mode, cpuclk_freq;
const char *name, *fixedclk_name;
struct device_node *np = pdev->dev.of_node;
struct regmap *regmap;
u32 reg;
int ret;
regmap = syscon_node_to_regmap(np);
if (IS_ERR(regmap)) {
dev_err(&pdev->dev, "cannot get regmap\n");
return PTR_ERR(regmap);
}
ret = regmap_read(regmap, AP806_SAR_REG, &reg);
if (ret) {
dev_err(&pdev->dev, "cannot read from regmap\n");
return ret;
}
freq_mode = reg & AP806_SAR_CLKFREQ_MODE_MASK;
switch (freq_mode) {
case 0x0 ... 0x5:
cpuclk_freq = 2000;
break;
case 0x6 ... 0xB:
cpuclk_freq = 1800;
break;
case 0xC ... 0x11:
cpuclk_freq = 1600;
break;
case 0x12 ... 0x16:
cpuclk_freq = 1400;
break;
case 0x17 ... 0x19:
cpuclk_freq = 1300;
break;
default:
dev_err(&pdev->dev, "invalid SAR value\n");
return -EINVAL;
}
cpuclk_freq *= 1000 * 1000;
of_property_read_string_index(np, "clock-output-names",
0, &name);
ap806_clks[0] = clk_register_fixed_rate(&pdev->dev, name, NULL,
0, cpuclk_freq);
if (IS_ERR(ap806_clks[0])) {
ret = PTR_ERR(ap806_clks[0]);
goto fail0;
}
of_property_read_string_index(np, "clock-output-names",
1, &name);
ap806_clks[1] = clk_register_fixed_rate(&pdev->dev, name, NULL, 0,
cpuclk_freq);
if (IS_ERR(ap806_clks[1])) {
ret = PTR_ERR(ap806_clks[1]);
goto fail1;
}
of_property_read_string_index(np, "clock-output-names",
2, &fixedclk_name);
ap806_clks[2] = clk_register_fixed_rate(&pdev->dev, fixedclk_name, NULL,
0, 1200 * 1000 * 1000);
if (IS_ERR(ap806_clks[2])) {
ret = PTR_ERR(ap806_clks[2]);
goto fail2;
}
of_property_read_string_index(np, "clock-output-names",
3, &name);
ap806_clks[3] = clk_register_fixed_factor(NULL, name, fixedclk_name,
0, 1, 6);
if (IS_ERR(ap806_clks[3])) {
ret = PTR_ERR(ap806_clks[3]);
goto fail3;
}
ret = of_clk_add_provider(np, of_clk_src_onecell_get, &ap806_clk_data);
if (ret)
goto fail_clk_add;
return 0;
fail_clk_add:
clk_unregister_fixed_factor(ap806_clks[3]);
fail3:
clk_unregister_fixed_rate(ap806_clks[2]);
fail2:
clk_unregister_fixed_rate(ap806_clks[1]);
fail1:
clk_unregister_fixed_rate(ap806_clks[0]);
fail0:
return ret;
}
static int ap806_syscon_clk_remove(struct platform_device *pdev)
{
of_clk_del_provider(pdev->dev.of_node);
clk_unregister_fixed_factor(ap806_clks[3]);
clk_unregister_fixed_rate(ap806_clks[2]);
clk_unregister_fixed_rate(ap806_clks[1]);
clk_unregister_fixed_rate(ap806_clks[0]);
return 0;
}
