static struct hisi_clock_data *hi3798cv200_clk_register(
struct platform_device *pdev)
{
struct hisi_clock_data *clk_data;
int ret;
clk_data = hisi_clk_alloc(pdev, HI3798CV200_CRG_NR_CLKS);
if (!clk_data)
return ERR_PTR(-ENOMEM);
ret = hisi_clk_register_fixed_rate(hi3798cv200_fixed_rate_clks,
ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
clk_data);
if (ret)
return ERR_PTR(ret);
ret = hisi_clk_register_mux(hi3798cv200_mux_clks,
ARRAY_SIZE(hi3798cv200_mux_clks),
clk_data);
if (ret)
goto unregister_fixed_rate;
ret = hisi_clk_register_gate(hi3798cv200_gate_clks,
ARRAY_SIZE(hi3798cv200_gate_clks),
clk_data);
if (ret)
goto unregister_mux;
ret = of_clk_add_provider(pdev->dev.of_node,
of_clk_src_onecell_get, &clk_data->clk_data);
if (ret)
goto unregister_gate;
return clk_data;
unregister_fixed_rate:
hisi_clk_unregister_fixed_rate(hi3798cv200_fixed_rate_clks,
ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
clk_data);
unregister_mux:
hisi_clk_unregister_mux(hi3798cv200_mux_clks,
ARRAY_SIZE(hi3798cv200_mux_clks),
clk_data);
unregister_gate:
hisi_clk_unregister_gate(hi3798cv200_gate_clks,
ARRAY_SIZE(hi3798cv200_gate_clks),
clk_data);
return ERR_PTR(ret);
}
static void hi3798cv200_clk_unregister(struct platform_device *pdev)
{
struct hisi_crg_dev *crg = platform_get_drvdata(pdev);
of_clk_del_provider(pdev->dev.of_node);
hisi_clk_unregister_gate(hi3798cv200_gate_clks,
ARRAY_SIZE(hi3798cv200_gate_clks),
crg->clk_data);
hisi_clk_unregister_mux(hi3798cv200_mux_clks,
ARRAY_SIZE(hi3798cv200_mux_clks),
crg->clk_data);
hisi_clk_unregister_fixed_rate(hi3798cv200_fixed_rate_clks,
ARRAY_SIZE(hi3798cv200_fixed_rate_clks),
crg->clk_data);
}
static struct hisi_clock_data *hi3798cv200_sysctrl_clk_register(
struct platform_device *pdev)
{
struct hisi_clock_data *clk_data;
int ret;
clk_data = hisi_clk_alloc(pdev, HI3798CV200_SYSCTRL_NR_CLKS);
if (!clk_data)
return ERR_PTR(-ENOMEM);
ret = hisi_clk_register_gate(hi3798cv200_sysctrl_gate_clks,
ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
clk_data);
if (ret)
return ERR_PTR(ret);
ret = of_clk_add_provider(pdev->dev.of_node,
of_clk_src_onecell_get, &clk_data->clk_data);
if (ret)
goto unregister_gate;
return clk_data;
unregister_gate:
hisi_clk_unregister_gate(hi3798cv200_sysctrl_gate_clks,
ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
clk_data);
return ERR_PTR(ret);
}
static void hi3798cv200_sysctrl_clk_unregister(struct platform_device *pdev)
{
struct hisi_crg_dev *crg = platform_get_drvdata(pdev);
of_clk_del_provider(pdev->dev.of_node);
hisi_clk_unregister_gate(hi3798cv200_sysctrl_gate_clks,
ARRAY_SIZE(hi3798cv200_sysctrl_gate_clks),
crg->clk_data);
}
static int hi3798cv200_crg_probe(struct platform_device *pdev)
{
struct hisi_crg_dev *crg;
crg = devm_kmalloc(&pdev->dev, sizeof(*crg), GFP_KERNEL);
if (!crg)
return -ENOMEM;
crg->funcs = of_device_get_match_data(&pdev->dev);
if (!crg->funcs)
return -ENOENT;
crg->rstc = hisi_reset_init(pdev);
if (!crg->rstc)
return -ENOMEM;
crg->clk_data = crg->funcs->register_clks(pdev);
if (IS_ERR(crg->clk_data)) {
hisi_reset_exit(crg->rstc);
return PTR_ERR(crg->clk_data);
}
platform_set_drvdata(pdev, crg);
return 0;
}
static int hi3798cv200_crg_remove(struct platform_device *pdev)
{
struct hisi_crg_dev *crg = platform_get_drvdata(pdev);
hisi_reset_exit(crg->rstc);
crg->funcs->unregister_clks(pdev);
return 0;
}
static int __init hi3798cv200_crg_init(void)
{
return platform_driver_register(&hi3798cv200_crg_driver);
}
static void __exit hi3798cv200_crg_exit(void)
{
platform_driver_unregister(&hi3798cv200_crg_driver);
}
