static int sun6i_drc_bind(struct device *dev, struct device *master,
void *data)
{
struct sun6i_drc *drc;
int ret;
drc = devm_kzalloc(dev, sizeof(*drc), GFP_KERNEL);
if (!drc)
return -ENOMEM;
dev_set_drvdata(dev, drc);
drc->reset = devm_reset_control_get(dev, NULL);
if (IS_ERR(drc->reset)) {
dev_err(dev, "Couldn't get our reset line\n");
return PTR_ERR(drc->reset);
}
ret = reset_control_deassert(drc->reset);
if (ret) {
dev_err(dev, "Couldn't deassert our reset line\n");
return ret;
}
drc->bus_clk = devm_clk_get(dev, "ahb");
if (IS_ERR(drc->bus_clk)) {
dev_err(dev, "Couldn't get our bus clock\n");
ret = PTR_ERR(drc->bus_clk);
goto err_assert_reset;
}
clk_prepare_enable(drc->bus_clk);
drc->mod_clk = devm_clk_get(dev, "mod");
if (IS_ERR(drc->mod_clk)) {
dev_err(dev, "Couldn't get our mod clock\n");
ret = PTR_ERR(drc->mod_clk);
goto err_disable_bus_clk;
}
clk_prepare_enable(drc->mod_clk);
return 0;
err_disable_bus_clk:
clk_disable_unprepare(drc->bus_clk);
err_assert_reset:
reset_control_assert(drc->reset);
return ret;
}
static void sun6i_drc_unbind(struct device *dev, struct device *master,
void *data)
{
struct sun6i_drc *drc = dev_get_drvdata(dev);
clk_disable_unprepare(drc->mod_clk);
clk_disable_unprepare(drc->bus_clk);
reset_control_assert(drc->reset);
}
static int sun6i_drc_probe(struct platform_device *pdev)
{
return component_add(&pdev->dev, &sun6i_drc_ops);
}
static int sun6i_drc_remove(struct platform_device *pdev)
{
component_del(&pdev->dev, &sun6i_drc_ops);
return 0;
}
