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
static inline struct nop_usb_xceiv *xceiv_to_nop(struct otg_transceiver *x)
{
return container_of(x, struct nop_usb_xceiv, otg);
}
static int nop_set_suspend(struct otg_transceiver *x, int suspend)
{
return 0;
}
static int nop_set_peripheral(struct otg_transceiver *x,
struct usb_gadget *gadget)
{
struct nop_usb_xceiv *nop;
if (!x)
return -ENODEV;
nop = xceiv_to_nop(x);
if (!gadget) {
nop->otg.gadget = NULL;
return -ENODEV;
}
nop->otg.gadget = gadget;
nop->otg.state = OTG_STATE_B_IDLE;
return 0;
}
static int nop_set_host(struct otg_transceiver *x, struct usb_bus *host)
{
struct nop_usb_xceiv *nop;
if (!x)
return -ENODEV;
nop = xceiv_to_nop(x);
if (!host) {
nop->otg.host = NULL;
return -ENODEV;
}
nop->otg.host = host;
return 0;
}
static int __devinit nop_usb_xceiv_probe(struct platform_device *pdev)
{
struct nop_usb_xceiv *nop;
int err;
nop = kzalloc(sizeof *nop, GFP_KERNEL);
if (!nop)
return -ENOMEM;
nop->dev = &pdev->dev;
nop->otg.dev = nop->dev;
nop->otg.label = "nop-xceiv";
nop->otg.state = OTG_STATE_UNDEFINED;
nop->otg.set_host = nop_set_host;
nop->otg.set_peripheral = nop_set_peripheral;
nop->otg.set_suspend = nop_set_suspend;
err = otg_set_transceiver(&nop->otg);
if (err) {
dev_err(&pdev->dev, "can't register transceiver, err: %d\n",
err);
goto exit;
}
platform_set_drvdata(pdev, nop);
ATOMIC_INIT_NOTIFIER_HEAD(&nop->otg.notifier);
return 0;
exit:
kfree(nop);
return err;
}
static int __devexit nop_usb_xceiv_remove(struct platform_device *pdev)
{
struct nop_usb_xceiv *nop = platform_get_drvdata(pdev);
otg_set_transceiver(NULL);
platform_set_drvdata(pdev, NULL);
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
