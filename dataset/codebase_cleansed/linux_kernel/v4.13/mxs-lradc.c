static int mxs_lradc_probe(struct platform_device *pdev)
{
const struct of_device_id *of_id;
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct mxs_lradc *lradc;
struct mfd_cell *cells = NULL;
struct resource *res;
int ret = 0;
u32 ts_wires = 0;
lradc = devm_kzalloc(&pdev->dev, sizeof(*lradc), GFP_KERNEL);
if (!lradc)
return -ENOMEM;
of_id = of_match_device(mxs_lradc_dt_ids, &pdev->dev);
if (!of_id)
return -EINVAL;
lradc->soc = (enum mxs_lradc_id)of_id->data;
lradc->clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(lradc->clk)) {
dev_err(dev, "Failed to get the delay unit clock\n");
return PTR_ERR(lradc->clk);
}
ret = clk_prepare_enable(lradc->clk);
if (ret) {
dev_err(dev, "Failed to enable the delay unit clock\n");
return ret;
}
ret = of_property_read_u32(node, "fsl,lradc-touchscreen-wires",
&ts_wires);
if (!ret) {
lradc->buffer_vchans = BUFFER_VCHANS_LIMITED;
switch (ts_wires) {
case 4:
lradc->touchscreen_wire = MXS_LRADC_TOUCHSCREEN_4WIRE;
break;
case 5:
if (lradc->soc == IMX28_LRADC) {
lradc->touchscreen_wire =
MXS_LRADC_TOUCHSCREEN_5WIRE;
break;
}
default:
dev_err(&pdev->dev,
"Unsupported number of touchscreen wires (%d)\n"
, ts_wires);
ret = -EINVAL;
goto err_clk;
}
} else {
lradc->buffer_vchans = BUFFER_VCHANS_ALL;
}
platform_set_drvdata(pdev, lradc);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -ENOMEM;
switch (lradc->soc) {
case IMX23_LRADC:
mx23_adc_resources[RES_MEM] = *res;
mx23_touchscreen_resources[RES_MEM] = *res;
cells = mx23_cells;
break;
case IMX28_LRADC:
mx28_adc_resources[RES_MEM] = *res;
mx28_touchscreen_resources[RES_MEM] = *res;
cells = mx28_cells;
break;
default:
dev_err(dev, "Unsupported SoC\n");
ret = -ENODEV;
goto err_clk;
}
ret = devm_mfd_add_devices(&pdev->dev, PLATFORM_DEVID_NONE,
&cells[ADC_CELL], 1, NULL, 0, NULL);
if (ret) {
dev_err(&pdev->dev, "Failed to add the ADC subdevice\n");
goto err_clk;
}
if (!lradc->touchscreen_wire)
return 0;
ret = devm_mfd_add_devices(&pdev->dev, PLATFORM_DEVID_NONE,
&cells[TSC_CELL], 1, NULL, 0, NULL);
if (ret) {
dev_err(&pdev->dev,
"Failed to add the touchscreen subdevice\n");
goto err_clk;
}
return 0;
err_clk:
clk_disable_unprepare(lradc->clk);
return ret;
}
static int mxs_lradc_remove(struct platform_device *pdev)
{
struct mxs_lradc *lradc = platform_get_drvdata(pdev);
clk_disable_unprepare(lradc->clk);
return 0;
}
