static int bcma_wait_bits(struct bcma_device *dev, u16 reg, u32 bitmask,
int timeout)
{
int i;
u32 val;
for (i = 0; i < timeout; i++) {
val = bcma_read32(dev, reg);
if ((val & bitmask) == bitmask)
return 0;
udelay(10);
}
return -ETIMEDOUT;
}
static void bcma_hcd_4716wa(struct bcma_device *dev)
{
#ifdef CONFIG_BCMA_DRIVER_MIPS
if (dev->bus->chipinfo.id == 0x4716) {
u32 tmp;
tmp = bcma_cpu_clock(&dev->bus->drv_mips);
if (tmp >= 480000000)
tmp = 0x1846b;
else if (tmp == 453000000)
tmp = 0x1046b;
else
tmp = 0;
if (tmp) {
bcma_write32(dev, 0x524, 0x1);
udelay(500);
bcma_write32(dev, 0x524, tmp);
udelay(500);
bcma_write32(dev, 0x524, 0x4ab);
udelay(500);
bcma_read32(dev, 0x528);
bcma_write32(dev, 0x528, 0x80000000);
}
}
#endif
}
static void bcma_hcd_init_chip_mips(struct bcma_device *dev)
{
u32 tmp;
if (!bcma_core_is_enabled(dev)) {
bcma_core_enable(dev, 0);
mdelay(10);
if (dev->id.rev >= 5) {
tmp = bcma_read32(dev, 0x1e0);
tmp |= 0x100;
bcma_write32(dev, 0x1e0, tmp);
if (bcma_wait_bits(dev, 0x1e0, 1 << 24, 100))
printk(KERN_EMERG "Failed to enable misc PPL!\n");
bcma_write32(dev, 0x200, 0x4ff);
udelay(25);
bcma_write32(dev, 0x200, 0x6ff);
udelay(25);
bcma_write32(dev, 0x524, 0x6b);
udelay(50);
tmp = bcma_read32(dev, 0x524);
udelay(50);
bcma_write32(dev, 0x524, 0xab);
udelay(50);
tmp = bcma_read32(dev, 0x524);
udelay(50);
bcma_write32(dev, 0x524, 0x2b);
udelay(50);
tmp = bcma_read32(dev, 0x524);
udelay(50);
bcma_write32(dev, 0x524, 0x10ab);
udelay(50);
tmp = bcma_read32(dev, 0x524);
if (bcma_wait_bits(dev, 0x528, 0xc000, 10000)) {
tmp = bcma_read32(dev, 0x528);
printk(KERN_EMERG
"USB20H mdio_rddata 0x%08x\n", tmp);
}
bcma_write32(dev, 0x528, 0x80000000);
tmp = bcma_read32(dev, 0x314);
udelay(265);
bcma_write32(dev, 0x200, 0x7ff);
udelay(10);
bcma_write32(dev, 0x510, 0);
} else {
bcma_write32(dev, 0x200, 0x7ff);
udelay(1);
}
bcma_hcd_4716wa(dev);
}
}
static void bcma_hcd_init_chip_arm_phy(struct bcma_device *dev)
{
struct bcma_device *arm_core;
void __iomem *dmu;
arm_core = bcma_find_core(dev->bus, BCMA_CORE_ARMCA9);
if (!arm_core) {
dev_err(&dev->dev, "can not find ARM Cortex A9 ihost core\n");
return;
}
dmu = ioremap_nocache(arm_core->addr_s[0], 0x1000);
if (!dmu) {
dev_err(&dev->dev, "can not map ARM Cortex A9 ihost core\n");
return;
}
iowrite32(0x0000ea68, dmu + 0x180);
iowrite32(0x00dd10c3, dmu + 0x164);
iowrite32(0x00000000, dmu + 0x180);
iounmap(dmu);
}
static void bcma_hcd_init_chip_arm_hc(struct bcma_device *dev)
{
u32 val;
usleep_range(1000, 2000);
val = bcma_read32(dev, 0x94);
val &= 0xffff;
val |= 0x80 << 16;
bcma_write32(dev, 0x94, val);
val = bcma_read32(dev, 0x9c);
val |= 1;
bcma_write32(dev, 0x9c, val);
}
static void bcma_hcd_init_chip_arm(struct bcma_device *dev)
{
bcma_core_enable(dev, 0);
if (dev->bus->chipinfo.id == BCMA_CHIP_ID_BCM4707 ||
dev->bus->chipinfo.id == BCMA_CHIP_ID_BCM53018) {
if (dev->bus->chipinfo.pkg == BCMA_PKG_ID_BCM4707 ||
dev->bus->chipinfo.pkg == BCMA_PKG_ID_BCM4708)
bcma_hcd_init_chip_arm_phy(dev);
bcma_hcd_init_chip_arm_hc(dev);
}
}
static void bcma_hci_platform_power_gpio(struct bcma_device *dev, bool val)
{
int gpio;
gpio = of_get_named_gpio(dev->dev.of_node, "vcc-gpio", 0);
if (!gpio_is_valid(gpio))
return;
if (val) {
gpio_request(gpio, "bcma-hcd-gpio");
gpio_set_value(gpio, 1);
} else {
gpio_set_value(gpio, 0);
gpio_free(gpio);
}
}
static struct platform_device *bcma_hcd_create_pdev(struct bcma_device *dev, bool ohci, u32 addr)
{
struct platform_device *hci_dev;
struct resource hci_res[2];
int ret;
memset(hci_res, 0, sizeof(hci_res));
hci_res[0].start = addr;
hci_res[0].end = hci_res[0].start + 0x1000 - 1;
hci_res[0].flags = IORESOURCE_MEM;
hci_res[1].start = dev->irq;
hci_res[1].flags = IORESOURCE_IRQ;
hci_dev = platform_device_alloc(ohci ? "ohci-platform" :
"ehci-platform" , 0);
if (!hci_dev)
return ERR_PTR(-ENOMEM);
hci_dev->dev.parent = &dev->dev;
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
static int bcma_hcd_probe(struct bcma_device *dev)
{
int err;
u32 ohci_addr;
struct bcma_hcd_device *usb_dev;
struct bcma_chipinfo *chipinfo;
chipinfo = &dev->bus->chipinfo;
if (dma_set_mask_and_coherent(dev->dma_dev, DMA_BIT_MASK(32)))
return -EOPNOTSUPP;
usb_dev = devm_kzalloc(&dev->dev, sizeof(struct bcma_hcd_device),
GFP_KERNEL);
if (!usb_dev)
return -ENOMEM;
bcma_hci_platform_power_gpio(dev, true);
switch (dev->id.id) {
case BCMA_CORE_NS_USB20:
bcma_hcd_init_chip_arm(dev);
break;
case BCMA_CORE_USB20_HOST:
bcma_hcd_init_chip_mips(dev);
break;
default:
return -ENODEV;
}
ohci_addr = dev->addr_s[0];
if ((chipinfo->id == BCMA_CHIP_ID_BCM5357 ||
chipinfo->id == BCMA_CHIP_ID_BCM4749)
&& chipinfo->rev == 0)
ohci_addr = 0x18009000;
usb_dev->ohci_dev = bcma_hcd_create_pdev(dev, true, ohci_addr);
if (IS_ERR(usb_dev->ohci_dev))
return PTR_ERR(usb_dev->ohci_dev);
usb_dev->ehci_dev = bcma_hcd_create_pdev(dev, false, dev->addr);
if (IS_ERR(usb_dev->ehci_dev)) {
err = PTR_ERR(usb_dev->ehci_dev);
goto err_unregister_ohci_dev;
}
bcma_set_drvdata(dev, usb_dev);
return 0;
err_unregister_ohci_dev:
platform_device_unregister(usb_dev->ohci_dev);
return err;
}
static void bcma_hcd_remove(struct bcma_device *dev)
{
struct bcma_hcd_device *usb_dev = bcma_get_drvdata(dev);
struct platform_device *ohci_dev = usb_dev->ohci_dev;
struct platform_device *ehci_dev = usb_dev->ehci_dev;
if (ohci_dev)
platform_device_unregister(ohci_dev);
if (ehci_dev)
platform_device_unregister(ehci_dev);
bcma_core_disable(dev, 0);
}
static void bcma_hcd_shutdown(struct bcma_device *dev)
{
bcma_hci_platform_power_gpio(dev, false);
bcma_core_disable(dev, 0);
}
static int bcma_hcd_suspend(struct bcma_device *dev)
{
bcma_hci_platform_power_gpio(dev, false);
bcma_core_disable(dev, 0);
return 0;
}
static int bcma_hcd_resume(struct bcma_device *dev)
{
bcma_hci_platform_power_gpio(dev, true);
bcma_core_enable(dev, 0);
return 0;
}
static int __init bcma_hcd_init(void)
{
return bcma_driver_register(&bcma_hcd_driver);
}
static void __exit bcma_hcd_exit(void)
{
bcma_driver_unregister(&bcma_hcd_driver);
}
