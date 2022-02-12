int fsl_udc_clk_init(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata;
unsigned long freq;
int ret;
pdata = pdev->dev.platform_data;
mxc_ipg_clk = devm_clk_get(&pdev->dev, "ipg");
if (IS_ERR(mxc_ipg_clk)) {
dev_err(&pdev->dev, "clk_get(\"ipg\") failed\n");
return PTR_ERR(mxc_ipg_clk);
}
mxc_ahb_clk = devm_clk_get(&pdev->dev, "ahb");
if (IS_ERR(mxc_ahb_clk)) {
dev_err(&pdev->dev, "clk_get(\"ahb\") failed\n");
return PTR_ERR(mxc_ahb_clk);
}
mxc_per_clk = devm_clk_get(&pdev->dev, "per");
if (IS_ERR(mxc_per_clk)) {
dev_err(&pdev->dev, "clk_get(\"per\") failed\n");
return PTR_ERR(mxc_per_clk);
}
clk_prepare_enable(mxc_ipg_clk);
clk_prepare_enable(mxc_ahb_clk);
clk_prepare_enable(mxc_per_clk);
if (!cpu_is_mx51()) {
freq = clk_get_rate(mxc_per_clk);
if (pdata->phy_mode != FSL_USB2_PHY_ULPI &&
(freq < 59999000 || freq > 60001000)) {
dev_err(&pdev->dev, "USB_CLK=%lu, should be 60MHz\n", freq);
ret = -EINVAL;
goto eclkrate;
}
}
return 0;
eclkrate:
clk_disable_unprepare(mxc_ipg_clk);
clk_disable_unprepare(mxc_ahb_clk);
clk_disable_unprepare(mxc_per_clk);
mxc_per_clk = NULL;
return ret;
}
void fsl_udc_clk_finalize(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata = pdev->dev.platform_data;
if (cpu_is_mx35()) {
unsigned int v;
if (pdata->workaround & FLS_USB2_WORKAROUND_ENGCM09152) {
v = readl(MX35_IO_ADDRESS(MX35_USB_BASE_ADDR +
USBPHYCTRL_OTGBASE_OFFSET));
writel(v | USBPHYCTRL_EVDO,
MX35_IO_ADDRESS(MX35_USB_BASE_ADDR +
USBPHYCTRL_OTGBASE_OFFSET));
}
}
if (pdata->phy_mode == FSL_USB2_PHY_ULPI) {
clk_disable_unprepare(mxc_per_clk);
mxc_per_clk = NULL;
}
}
void fsl_udc_clk_release(void)
{
if (mxc_per_clk)
clk_disable_unprepare(mxc_per_clk);
clk_disable_unprepare(mxc_ahb_clk);
clk_disable_unprepare(mxc_ipg_clk);
}
