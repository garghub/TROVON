int fsl_udc_clk_init(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata;
unsigned long freq;
int ret;
pdata = pdev->dev.platform_data;
if (!cpu_is_mx35() && !cpu_is_mx25()) {
mxc_ahb_clk = clk_get(&pdev->dev, "usb_ahb");
if (IS_ERR(mxc_ahb_clk))
return PTR_ERR(mxc_ahb_clk);
ret = clk_enable(mxc_ahb_clk);
if (ret < 0) {
dev_err(&pdev->dev, "clk_enable(\"usb_ahb\") failed\n");
goto eenahb;
}
}
mxc_usb_clk = clk_get(&pdev->dev, "usb");
if (IS_ERR(mxc_usb_clk)) {
dev_err(&pdev->dev, "clk_get(\"usb\") failed\n");
ret = PTR_ERR(mxc_usb_clk);
goto egusb;
}
if (!cpu_is_mx51()) {
freq = clk_get_rate(mxc_usb_clk);
if (pdata->phy_mode != FSL_USB2_PHY_ULPI &&
(freq < 59999000 || freq > 60001000)) {
dev_err(&pdev->dev, "USB_CLK=%lu, should be 60MHz\n", freq);
ret = -EINVAL;
goto eclkrate;
}
}
ret = clk_enable(mxc_usb_clk);
if (ret < 0) {
dev_err(&pdev->dev, "clk_enable(\"usb_clk\") failed\n");
goto eenusb;
}
return 0;
eenusb:
eclkrate:
clk_put(mxc_usb_clk);
mxc_usb_clk = NULL;
egusb:
if (!cpu_is_mx35())
clk_disable(mxc_ahb_clk);
eenahb:
if (!cpu_is_mx35())
clk_put(mxc_ahb_clk);
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
clk_disable(mxc_usb_clk);
clk_put(mxc_usb_clk);
mxc_usb_clk = NULL;
}
}
void fsl_udc_clk_release(void)
{
if (mxc_usb_clk) {
clk_disable(mxc_usb_clk);
clk_put(mxc_usb_clk);
}
if (!cpu_is_mx35()) {
clk_disable(mxc_ahb_clk);
clk_put(mxc_ahb_clk);
}
}
