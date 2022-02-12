static void msm8974_pro_clock_override(void)
{
sdcc1_apps_clk_src_init.parent_names = gcc_xo_gpll0_gpll4;
sdcc1_apps_clk_src_init.num_parents = 3;
sdcc1_apps_clk_src.freq_tbl = ftbl_gcc_sdcc1_apps_clk_pro;
sdcc1_apps_clk_src.parent_map = gcc_xo_gpll0_gpll4_map;
gcc_msm8974_clocks[GPLL4] = &gpll4.clkr;
gcc_msm8974_clocks[GPLL4_VOTE] = &gpll4_vote;
gcc_msm8974_clocks[GCC_SDCC1_CDCCAL_SLEEP_CLK] =
&gcc_sdcc1_cdccal_sleep_clk.clkr;
gcc_msm8974_clocks[GCC_SDCC1_CDCCAL_FF_CLK] =
&gcc_sdcc1_cdccal_ff_clk.clkr;
}
static int gcc_msm8974_probe(struct platform_device *pdev)
{
struct clk *clk;
struct device *dev = &pdev->dev;
bool pro;
const struct of_device_id *id;
id = of_match_device(gcc_msm8974_match_table, dev);
if (!id)
return -ENODEV;
pro = !!(id->data);
if (pro)
msm8974_pro_clock_override();
clk = clk_register_fixed_rate(dev, "xo", NULL, CLK_IS_ROOT, 19200000);
if (IS_ERR(clk))
return PTR_ERR(clk);
clk = clk_register_fixed_rate(dev, "sleep_clk_src", NULL,
CLK_IS_ROOT, 32768);
if (IS_ERR(clk))
return PTR_ERR(clk);
return qcom_cc_probe(pdev, &gcc_msm8974_desc);
}
static int __init gcc_msm8974_init(void)
{
return platform_driver_register(&gcc_msm8974_driver);
}
static void __exit gcc_msm8974_exit(void)
{
platform_driver_unregister(&gcc_msm8974_driver);
}
