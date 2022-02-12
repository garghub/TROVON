static struct hisi_clock_data *hi3519_clk_register(struct platform_device *pdev)
{
struct hisi_clock_data *clk_data;
int ret;
clk_data = hisi_clk_alloc(pdev, HI3519_NR_CLKS);
if (!clk_data)
return ERR_PTR(-ENOMEM);
ret = hisi_clk_register_fixed_rate(hi3519_fixed_rate_clks,
ARRAY_SIZE(hi3519_fixed_rate_clks),
clk_data);
if (ret)
return ERR_PTR(ret);
ret = hisi_clk_register_mux(hi3519_mux_clks,
ARRAY_SIZE(hi3519_mux_clks),
clk_data);
if (ret)
goto unregister_fixed_rate;
ret = hisi_clk_register_gate(hi3519_gate_clks,
ARRAY_SIZE(hi3519_gate_clks),
clk_data);
if (ret)
goto unregister_mux;
ret = of_clk_add_provider(pdev->dev.of_node,
of_clk_src_onecell_get, &clk_data->clk_data);
if (ret)
goto unregister_gate;
return clk_data;
unregister_fixed_rate:
hisi_clk_unregister_fixed_rate(hi3519_fixed_rate_clks,
ARRAY_SIZE(hi3519_fixed_rate_clks),
clk_data);
unregister_mux:
hisi_clk_unregister_mux(hi3519_mux_clks,
ARRAY_SIZE(hi3519_mux_clks),
clk_data);
unregister_gate:
hisi_clk_unregister_gate(hi3519_gate_clks,
ARRAY_SIZE(hi3519_gate_clks),
clk_data);
return ERR_PTR(ret);
}
static void hi3519_clk_unregister(struct platform_device *pdev)
{
struct hi3519_crg_data *crg = platform_get_drvdata(pdev);
of_clk_del_provider(pdev->dev.of_node);
hisi_clk_unregister_gate(hi3519_gate_clks,
ARRAY_SIZE(hi3519_mux_clks),
crg->clk_data);
hisi_clk_unregister_mux(hi3519_mux_clks,
ARRAY_SIZE(hi3519_mux_clks),
crg->clk_data);
hisi_clk_unregister_fixed_rate(hi3519_fixed_rate_clks,
ARRAY_SIZE(hi3519_fixed_rate_clks),
crg->clk_data);
}
static int hi3519_clk_probe(struct platform_device *pdev)
{
struct hi3519_crg_data *crg;
crg = devm_kmalloc(&pdev->dev, sizeof(*crg), GFP_KERNEL);
if (!crg)
return -ENOMEM;
crg->rstc = hisi_reset_init(pdev);
if (!crg->rstc)
return -ENOMEM;
crg->clk_data = hi3519_clk_register(pdev);
if (IS_ERR(crg->clk_data)) {
hisi_reset_exit(crg->rstc);
return PTR_ERR(crg->clk_data);
}
platform_set_drvdata(pdev, crg);
return 0;
}
static int hi3519_clk_remove(struct platform_device *pdev)
{
struct hi3519_crg_data *crg = platform_get_drvdata(pdev);
hisi_reset_exit(crg->rstc);
hi3519_clk_unregister(pdev);
return 0;
}
static int __init hi3519_clk_init(void)
{
return platform_driver_register(&hi3519_clk_driver);
}
static void __exit hi3519_clk_exit(void)
{
platform_driver_unregister(&hi3519_clk_driver);
}
