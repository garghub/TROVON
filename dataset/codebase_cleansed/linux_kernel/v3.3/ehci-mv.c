static void ehci_clock_enable(struct ehci_hcd_mv *ehci_mv)
{
unsigned int i;
for (i = 0; i < ehci_mv->clknum; i++)
clk_enable(ehci_mv->clk[i]);
}
static void ehci_clock_disable(struct ehci_hcd_mv *ehci_mv)
{
unsigned int i;
for (i = 0; i < ehci_mv->clknum; i++)
clk_disable(ehci_mv->clk[i]);
}
static int mv_ehci_enable(struct ehci_hcd_mv *ehci_mv)
{
int retval;
ehci_clock_enable(ehci_mv);
if (ehci_mv->pdata->phy_init) {
retval = ehci_mv->pdata->phy_init(ehci_mv->phy_regs);
if (retval)
return retval;
}
return 0;
}
static void mv_ehci_disable(struct ehci_hcd_mv *ehci_mv)
{
if (ehci_mv->pdata->phy_deinit)
ehci_mv->pdata->phy_deinit(ehci_mv->phy_regs);
ehci_clock_disable(ehci_mv);
}
static int mv_ehci_reset(struct usb_hcd *hcd)
{
struct ehci_hcd *ehci = hcd_to_ehci(hcd);
struct device *dev = hcd->self.controller;
struct ehci_hcd_mv *ehci_mv = dev_get_drvdata(dev);
int retval;
if (ehci_mv == NULL) {
dev_err(dev, "Can not find private ehci data\n");
return -ENODEV;
}
retval = ehci_init(hcd);
if (retval) {
dev_err(dev, "ehci_init failed %d\n", retval);
return retval;
}
hcd->has_tt = 1;
ehci->sbrn = 0x20;
retval = ehci_reset(ehci);
if (retval) {
dev_err(dev, "ehci_reset failed %d\n", retval);
return retval;
}
return 0;
}
static int mv_ehci_probe(struct platform_device *pdev)
{
struct mv_usb_platform_data *pdata = pdev->dev.platform_data;
struct usb_hcd *hcd;
struct ehci_hcd *ehci;
struct ehci_hcd_mv *ehci_mv;
struct resource *r;
int clk_i, retval = -ENODEV;
u32 offset;
size_t size;
if (!pdata) {
dev_err(&pdev->dev, "missing platform_data\n");
return -ENODEV;
}
if (usb_disabled())
return -ENODEV;
hcd = usb_create_hcd(&mv_ehci_hc_driver, &pdev->dev, "mv ehci");
if (!hcd)
return -ENOMEM;
size = sizeof(*ehci_mv) + sizeof(struct clk *) * pdata->clknum;
ehci_mv = kzalloc(size, GFP_KERNEL);
if (ehci_mv == NULL) {
dev_err(&pdev->dev, "cannot allocate ehci_hcd_mv\n");
retval = -ENOMEM;
goto err_put_hcd;
}
platform_set_drvdata(pdev, ehci_mv);
ehci_mv->pdata = pdata;
ehci_mv->hcd = hcd;
ehci_mv->clknum = pdata->clknum;
for (clk_i = 0; clk_i < ehci_mv->clknum; clk_i++) {
ehci_mv->clk[clk_i] =
clk_get(&pdev->dev, pdata->clkname[clk_i]);
if (IS_ERR(ehci_mv->clk[clk_i])) {
dev_err(&pdev->dev, "error get clck \"%s\"\n",
pdata->clkname[clk_i]);
retval = PTR_ERR(ehci_mv->clk[clk_i]);
goto err_put_clk;
}
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "phyregs");
if (r == NULL) {
dev_err(&pdev->dev, "no phy I/O memory resource defined\n");
retval = -ENODEV;
goto err_put_clk;
}
ehci_mv->phy_regs = ioremap(r->start, resource_size(r));
if (ehci_mv->phy_regs == 0) {
dev_err(&pdev->dev, "failed to map phy I/O memory\n");
retval = -EFAULT;
goto err_put_clk;
}
r = platform_get_resource_byname(pdev, IORESOURCE_MEM, "capregs");
if (!r) {
dev_err(&pdev->dev, "no I/O memory resource defined\n");
retval = -ENODEV;
goto err_iounmap_phyreg;
}
ehci_mv->cap_regs = ioremap(r->start, resource_size(r));
if (ehci_mv->cap_regs == NULL) {
dev_err(&pdev->dev, "failed to map I/O memory\n");
retval = -EFAULT;
goto err_iounmap_phyreg;
}
retval = mv_ehci_enable(ehci_mv);
if (retval) {
dev_err(&pdev->dev, "init phy error %d\n", retval);
goto err_iounmap_capreg;
}
offset = readl(ehci_mv->cap_regs) & CAPLENGTH_MASK;
ehci_mv->op_regs =
(void __iomem *) ((unsigned long) ehci_mv->cap_regs + offset);
hcd->rsrc_start = r->start;
hcd->rsrc_len = r->end - r->start + 1;
hcd->regs = ehci_mv->op_regs;
hcd->irq = platform_get_irq(pdev, 0);
if (!hcd->irq) {
dev_err(&pdev->dev, "Cannot get irq.");
retval = -ENODEV;
goto err_disable_clk;
}
ehci = hcd_to_ehci(hcd);
ehci->caps = (struct ehci_caps *) ehci_mv->cap_regs;
ehci->regs = (struct ehci_regs *) ehci_mv->op_regs;
ehci->hcs_params = ehci_readl(ehci, &ehci->caps->hcs_params);
ehci_mv->mode = pdata->mode;
if (ehci_mv->mode == MV_USB_MODE_OTG) {
#ifdef CONFIG_USB_OTG_UTILS
ehci_mv->otg = otg_get_transceiver();
if (!ehci_mv->otg) {
dev_err(&pdev->dev,
"unable to find transceiver\n");
retval = -ENODEV;
goto err_disable_clk;
}
retval = otg_set_host(ehci_mv->otg, &hcd->self);
if (retval < 0) {
dev_err(&pdev->dev,
"unable to register with transceiver\n");
retval = -ENODEV;
goto err_put_transceiver;
}
mv_ehci_disable(ehci_mv);
#else
dev_info(&pdev->dev, "MV_USB_MODE_OTG "
"must have CONFIG_USB_OTG_UTILS enabled\n");
goto err_disable_clk;
#endif
} else {
if (pdata->set_vbus)
pdata->set_vbus(1);
retval = usb_add_hcd(hcd, hcd->irq, IRQF_SHARED);
if (retval) {
dev_err(&pdev->dev,
"failed to add hcd with err %d\n", retval);
goto err_set_vbus;
}
}
if (pdata->private_init)
pdata->private_init(ehci_mv->op_regs, ehci_mv->phy_regs);
dev_info(&pdev->dev,
"successful find EHCI device with regs 0x%p irq %d"
" working in %s mode\n", hcd->regs, hcd->irq,
ehci_mv->mode == MV_USB_MODE_OTG ? "OTG" : "Host");
return 0;
err_set_vbus:
if (pdata->set_vbus)
pdata->set_vbus(0);
#ifdef CONFIG_USB_OTG_UTILS
err_put_transceiver:
if (ehci_mv->otg)
otg_put_transceiver(ehci_mv->otg);
#endif
err_disable_clk:
mv_ehci_disable(ehci_mv);
err_iounmap_capreg:
iounmap(ehci_mv->cap_regs);
err_iounmap_phyreg:
iounmap(ehci_mv->phy_regs);
err_put_clk:
for (clk_i--; clk_i >= 0; clk_i--)
clk_put(ehci_mv->clk[clk_i]);
platform_set_drvdata(pdev, NULL);
kfree(ehci_mv);
err_put_hcd:
usb_put_hcd(hcd);
return retval;
}
static int mv_ehci_remove(struct platform_device *pdev)
{
struct ehci_hcd_mv *ehci_mv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_mv->hcd;
int clk_i;
if (hcd->rh_registered)
usb_remove_hcd(hcd);
if (ehci_mv->otg) {
otg_set_host(ehci_mv->otg, NULL);
otg_put_transceiver(ehci_mv->otg);
}
if (ehci_mv->mode == MV_USB_MODE_HOST) {
if (ehci_mv->pdata->set_vbus)
ehci_mv->pdata->set_vbus(0);
mv_ehci_disable(ehci_mv);
}
iounmap(ehci_mv->cap_regs);
iounmap(ehci_mv->phy_regs);
for (clk_i = 0; clk_i < ehci_mv->clknum; clk_i++)
clk_put(ehci_mv->clk[clk_i]);
platform_set_drvdata(pdev, NULL);
kfree(ehci_mv);
usb_put_hcd(hcd);
return 0;
}
static void mv_ehci_shutdown(struct platform_device *pdev)
{
struct ehci_hcd_mv *ehci_mv = platform_get_drvdata(pdev);
struct usb_hcd *hcd = ehci_mv->hcd;
if (!hcd->rh_registered)
return;
if (hcd->driver->shutdown)
hcd->driver->shutdown(hcd);
}
