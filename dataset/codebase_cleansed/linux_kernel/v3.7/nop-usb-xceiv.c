void usb_nop_xceiv_register(void)
{
if (pd)
return;
pd = platform_device_register_simple("nop_usb_xceiv", -1, NULL, 0);
if (!pd) {
printk(KERN_ERR "Unable to register usb nop transceiver\n");
return;
}
}
void usb_nop_xceiv_unregister(void)
{
platform_device_unregister(pd);
pd = NULL;
}
static int nop_set_suspend(struct usb_phy *x, int suspend)
{
return 0;
}
static int nop_set_peripheral(struct usb_otg *otg, struct usb_gadget *gadget)
{
if (!otg)
return -ENODEV;
if (!gadget) {
otg->gadget = NULL;
return -ENODEV;
}
otg->gadget = gadget;
otg->phy->state = OTG_STATE_B_IDLE;
return 0;
}
static int nop_set_host(struct usb_otg *otg, struct usb_bus *host)
{
if (!otg)
return -ENODEV;
if (!host) {
otg->host = NULL;
return -ENODEV;
}
otg->host = host;
return 0;
}
static int __devinit nop_usb_xceiv_probe(struct platform_device *pdev)
{
struct nop_usb_xceiv_platform_data *pdata = pdev->dev.platform_data;
struct nop_usb_xceiv *nop;
enum usb_phy_type type = USB_PHY_TYPE_USB2;
int err;
nop = kzalloc(sizeof *nop, GFP_KERNEL);
if (!nop)
return -ENOMEM;
nop->phy.otg = kzalloc(sizeof *nop->phy.otg, GFP_KERNEL);
if (!nop->phy.otg) {
kfree(nop);
return -ENOMEM;
}
if (pdata)
type = pdata->type;
nop->dev = &pdev->dev;
nop->phy.dev = nop->dev;
nop->phy.label = "nop-xceiv";
nop->phy.set_suspend = nop_set_suspend;
nop->phy.state = OTG_STATE_UNDEFINED;
nop->phy.otg->phy = &nop->phy;
nop->phy.otg->set_host = nop_set_host;
nop->phy.otg->set_peripheral = nop_set_peripheral;
err = usb_add_phy(&nop->phy, type);
if (err) {
dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
err);
goto exit;
}
platform_set_drvdata(pdev, nop);
ATOMIC_INIT_NOTIFIER_HEAD(&nop->phy.notifier);
return 0;
exit:
kfree(nop->phy.otg);
kfree(nop);
return err;
}
static int __devexit nop_usb_xceiv_remove(struct platform_device *pdev)
{
struct nop_usb_xceiv *nop = platform_get_drvdata(pdev);
usb_remove_phy(&nop->phy);
platform_set_drvdata(pdev, NULL);
kfree(nop->phy.otg);
kfree(nop);
return 0;
}
static int __init nop_usb_xceiv_init(void)
{
return platform_driver_register(&nop_usb_xceiv_driver);
}
static void __exit nop_usb_xceiv_exit(void)
{
platform_driver_unregister(&nop_usb_xceiv_driver);
}
