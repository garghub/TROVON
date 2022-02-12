static struct fsl_usb2_dev_data *get_dr_mode_data(struct device_node *np)
{
const unsigned char *prop;
int i;
prop = of_get_property(np, "dr_mode", NULL);
if (prop) {
for (i = 0; i < ARRAY_SIZE(dr_mode_data); i++) {
if (!strcmp(prop, dr_mode_data[i].dr_mode))
return &dr_mode_data[i];
}
}
pr_warn("%s: Invalid 'dr_mode' property, fallback to host mode\n",
np->full_name);
return &dr_mode_data[0];
}
static enum fsl_usb2_phy_modes determine_usb_phy(const char *phy_type)
{
if (!phy_type)
return FSL_USB2_PHY_NONE;
if (!strcasecmp(phy_type, "ulpi"))
return FSL_USB2_PHY_ULPI;
if (!strcasecmp(phy_type, "utmi"))
return FSL_USB2_PHY_UTMI;
if (!strcasecmp(phy_type, "utmi_wide"))
return FSL_USB2_PHY_UTMI_WIDE;
if (!strcasecmp(phy_type, "serial"))
return FSL_USB2_PHY_SERIAL;
return FSL_USB2_PHY_NONE;
}
static struct platform_device *fsl_usb2_device_register(
struct platform_device *ofdev,
struct fsl_usb2_platform_data *pdata,
const char *name, int id)
{
struct platform_device *pdev;
const struct resource *res = ofdev->resource;
unsigned int num = ofdev->num_resources;
int retval;
pdev = platform_device_alloc(name, id);
if (!pdev) {
retval = -ENOMEM;
goto error;
}
pdev->dev.parent = &ofdev->dev;
pdev->dev.coherent_dma_mask = ofdev->dev.coherent_dma_mask;
*pdev->dev.dma_mask = *ofdev->dev.dma_mask;
retval = platform_device_add_data(pdev, pdata, sizeof(*pdata));
if (retval)
goto error;
if (num) {
retval = platform_device_add_resources(pdev, res, num);
if (retval)
goto error;
}
retval = platform_device_add(pdev);
if (retval)
goto error;
return pdev;
error:
platform_device_put(pdev);
return ERR_PTR(retval);
}
static int usb_get_ver_info(struct device_node *np)
{
int ver = -1;
if (of_device_is_compatible(np, "fsl-usb2-dr")) {
if (of_device_is_compatible(np, "fsl-usb2-dr-v1.6"))
ver = FSL_USB_VER_1_6;
else if (of_device_is_compatible(np, "fsl-usb2-dr-v2.2"))
ver = FSL_USB_VER_2_2;
else if (of_device_is_compatible(np, "fsl-usb2-dr-v2.4"))
ver = FSL_USB_VER_2_4;
else if (of_device_is_compatible(np, "fsl-usb2-dr-v2.5"))
ver = FSL_USB_VER_2_5;
else
ver = FSL_USB_VER_OLD;
if (ver > -1)
return ver;
}
if (of_device_is_compatible(np, "fsl,mpc5121-usb2-dr"))
return FSL_USB_VER_OLD;
if (of_device_is_compatible(np, "fsl-usb2-mph")) {
if (of_device_is_compatible(np, "fsl-usb2-mph-v1.6"))
ver = FSL_USB_VER_1_6;
else if (of_device_is_compatible(np, "fsl-usb2-mph-v2.2"))
ver = FSL_USB_VER_2_2;
else if (of_device_is_compatible(np, "fsl-usb2-mph-v2.4"))
ver = FSL_USB_VER_2_4;
else if (of_device_is_compatible(np, "fsl-usb2-mph-v2.5"))
ver = FSL_USB_VER_2_5;
else
ver = FSL_USB_VER_OLD;
}
return ver;
}
static int fsl_usb2_mph_dr_of_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct platform_device *usb_dev;
struct fsl_usb2_platform_data data, *pdata;
struct fsl_usb2_dev_data *dev_data;
const struct of_device_id *match;
const unsigned char *prop;
static unsigned int idx;
int i;
if (!of_device_is_available(np))
return -ENODEV;
match = of_match_device(fsl_usb2_mph_dr_of_match, &ofdev->dev);
if (!match)
return -ENODEV;
pdata = &data;
if (match->data)
memcpy(pdata, match->data, sizeof(data));
else
memset(pdata, 0, sizeof(data));
dev_data = get_dr_mode_data(np);
if (of_device_is_compatible(np, "fsl-usb2-mph")) {
if (of_get_property(np, "port0", NULL))
pdata->port_enables |= FSL_USB2_PORT0_ENABLED;
if (of_get_property(np, "port1", NULL))
pdata->port_enables |= FSL_USB2_PORT1_ENABLED;
pdata->operating_mode = FSL_USB2_MPH_HOST;
} else {
if (of_get_property(np, "fsl,invert-drvvbus", NULL))
pdata->invert_drvvbus = 1;
if (of_get_property(np, "fsl,invert-pwr-fault", NULL))
pdata->invert_pwr_fault = 1;
pdata->operating_mode = dev_data->op_mode;
}
prop = of_get_property(np, "phy_type", NULL);
pdata->phy_mode = determine_usb_phy(prop);
pdata->controller_ver = usb_get_ver_info(np);
if (pdata->have_sysif_regs) {
if (pdata->controller_ver < 0) {
dev_warn(&ofdev->dev, "Could not get controller version\n");
return -ENODEV;
}
}
for (i = 0; i < ARRAY_SIZE(dev_data->drivers); i++) {
if (!dev_data->drivers[i])
continue;
usb_dev = fsl_usb2_device_register(ofdev, pdata,
dev_data->drivers[i], idx);
if (IS_ERR(usb_dev)) {
dev_err(&ofdev->dev, "Can't register usb device\n");
return PTR_ERR(usb_dev);
}
}
idx++;
return 0;
}
static int __unregister_subdev(struct device *dev, void *d)
{
platform_device_unregister(to_platform_device(dev));
return 0;
}
static int fsl_usb2_mph_dr_of_remove(struct platform_device *ofdev)
{
device_for_each_child(&ofdev->dev, NULL, __unregister_subdev);
return 0;
}
int fsl_usb2_mpc5121_init(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct clk *clk;
int err;
clk = devm_clk_get(pdev->dev.parent, "ipg");
if (IS_ERR(clk)) {
dev_err(&pdev->dev, "failed to get clk\n");
return PTR_ERR(clk);
}
err = clk_prepare_enable(clk);
if (err) {
dev_err(&pdev->dev, "failed to enable clk\n");
return err;
}
pdata->clk = clk;
if (pdata->phy_mode == FSL_USB2_PHY_UTMI_WIDE) {
u32 reg = 0;
if (pdata->invert_drvvbus)
reg |= GC_PPP;
if (pdata->invert_pwr_fault)
reg |= GC_PFP;
out_be32(pdata->regs + ISIPHYCTRL, PHYCTRL_PHYE | PHYCTRL_PXE);
out_be32(pdata->regs + USBGENCTRL, reg);
}
return 0;
}
static void fsl_usb2_mpc5121_exit(struct platform_device *pdev)
{
struct fsl_usb2_platform_data *pdata = dev_get_platdata(&pdev->dev);
pdata->regs = NULL;
if (pdata->clk)
clk_disable_unprepare(pdata->clk);
}
