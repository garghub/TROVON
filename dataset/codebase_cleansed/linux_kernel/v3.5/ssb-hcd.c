static void __devinit ssb_hcd_5354wa(struct ssb_device *dev)
{
#ifdef CONFIG_SSB_DRIVER_MIPS
if (dev->id.revision == 2 && dev->bus->chip_id == 0x5354) {
ssb_write32(dev, 0x894, 0x00fe00fe);
ssb_write32(dev, 0x89c, ssb_read32(dev, 0x89c) | 0x1);
}
#endif
}
static void __devinit ssb_hcd_usb20wa(struct ssb_device *dev)
{
if (dev->id.coreid == SSB_DEV_USB20_HOST) {
ssb_write32(dev, 0x200, 0x7ff);
ssb_write32(dev, 0x400, ssb_read32(dev, 0x400) & ~8);
ssb_read32(dev, 0x400);
ssb_write32(dev, 0x304, ssb_read32(dev, 0x304) & ~0x100);
ssb_read32(dev, 0x304);
udelay(1);
ssb_hcd_5354wa(dev);
}
}
static u32 __devinit ssb_hcd_init_chip(struct ssb_device *dev)
{
u32 flags = 0;
if (dev->id.coreid == SSB_DEV_USB11_HOSTDEV)
flags |= SSB_HCD_TMSLOW_HOSTMODE;
ssb_device_enable(dev, flags);
ssb_hcd_usb20wa(dev);
return flags;
}
static struct platform_device * __devinit
ssb_hcd_create_pdev(struct ssb_device *dev, bool ohci, u32 addr, u32 len)
{
struct platform_device *hci_dev;
struct resource hci_res[2];
int ret = -ENOMEM;
memset(hci_res, 0, sizeof(hci_res));
hci_res[0].start = addr;
hci_res[0].end = hci_res[0].start + len - 1;
hci_res[0].flags = IORESOURCE_MEM;
hci_res[1].start = dev->irq;
hci_res[1].flags = IORESOURCE_IRQ;
hci_dev = platform_device_alloc(ohci ? "ohci-platform" :
"ehci-platform" , 0);
if (!hci_dev)
return NULL;
hci_dev->dev.parent = dev->dev;
hci_dev->dev.dma_mask = &hci_dev->dev.coherent_dma_mask;
ret = platform_device_add_resources(hci_dev, hci_res,
ARRAY_SIZE(hci_res));
if (ret)
goto err_alloc;
if (ohci)
ret = platform_device_add_data(hci_dev, &ohci_pdata,
sizeof(ohci_pdata));
else
ret = platform_device_add_data(hci_dev, &ehci_pdata,
sizeof(ehci_pdata));
if (ret)
goto err_alloc;
ret = platform_device_add(hci_dev);
if (ret)
goto err_alloc;
return hci_dev;
err_alloc:
platform_device_put(hci_dev);
return ERR_PTR(ret);
}
static int __devinit ssb_hcd_probe(struct ssb_device *dev,
const struct ssb_device_id *id)
{
int err, tmp;
int start, len;
u16 chipid_top;
u16 coreid = dev->id.coreid;
struct ssb_hcd_device *usb_dev;
chipid_top = (dev->bus->chip_id & 0xFF00);
if (chipid_top != 0x4700 && chipid_top != 0x5300)
return -ENODEV;
if (dma_set_mask(dev->dma_dev, DMA_BIT_MASK(32)) ||
dma_set_coherent_mask(dev->dma_dev, DMA_BIT_MASK(32)))
return -EOPNOTSUPP;
usb_dev = kzalloc(sizeof(struct ssb_hcd_device), GFP_KERNEL);
if (!usb_dev)
return -ENOMEM;
usb_dev->enable_flags = ssb_hcd_init_chip(dev);
tmp = ssb_read32(dev, SSB_ADMATCH0);
start = ssb_admatch_base(tmp);
len = (coreid == SSB_DEV_USB20_HOST) ? 0x800 : ssb_admatch_size(tmp);
usb_dev->ohci_dev = ssb_hcd_create_pdev(dev, true, start, len);
if (IS_ERR(usb_dev->ohci_dev)) {
err = PTR_ERR(usb_dev->ohci_dev);
goto err_free_usb_dev;
}
if (coreid == SSB_DEV_USB20_HOST) {
start = ssb_admatch_base(tmp) + 0x800;
usb_dev->ehci_dev = ssb_hcd_create_pdev(dev, false, start, len);
if (IS_ERR(usb_dev->ehci_dev)) {
err = PTR_ERR(usb_dev->ehci_dev);
goto err_unregister_ohci_dev;
}
}
ssb_set_drvdata(dev, usb_dev);
return 0;
err_unregister_ohci_dev:
platform_device_unregister(usb_dev->ohci_dev);
err_free_usb_dev:
kfree(usb_dev);
return err;
}
static void __devexit ssb_hcd_remove(struct ssb_device *dev)
{
struct ssb_hcd_device *usb_dev = ssb_get_drvdata(dev);
struct platform_device *ohci_dev = usb_dev->ohci_dev;
struct platform_device *ehci_dev = usb_dev->ehci_dev;
if (ohci_dev)
platform_device_unregister(ohci_dev);
if (ehci_dev)
platform_device_unregister(ehci_dev);
ssb_device_disable(dev, 0);
}
static void __devexit ssb_hcd_shutdown(struct ssb_device *dev)
{
ssb_device_disable(dev, 0);
}
static int ssb_hcd_suspend(struct ssb_device *dev, pm_message_t state)
{
ssb_device_disable(dev, 0);
return 0;
}
static int ssb_hcd_resume(struct ssb_device *dev)
{
struct ssb_hcd_device *usb_dev = ssb_get_drvdata(dev);
ssb_device_enable(dev, usb_dev->enable_flags);
return 0;
}
static int __init ssb_hcd_init(void)
{
return ssb_driver_register(&ssb_hcd_driver);
}
static void __exit ssb_hcd_exit(void)
{
ssb_driver_unregister(&ssb_hcd_driver);
}
