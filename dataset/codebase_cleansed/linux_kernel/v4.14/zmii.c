static inline int zmii_valid_mode(int mode)
{
return mode == PHY_MODE_MII ||
mode == PHY_MODE_RMII ||
mode == PHY_MODE_SMII ||
mode == PHY_MODE_NA;
}
static inline const char *zmii_mode_name(int mode)
{
switch (mode) {
case PHY_MODE_MII:
return "MII";
case PHY_MODE_RMII:
return "RMII";
case PHY_MODE_SMII:
return "SMII";
default:
BUG();
}
}
static inline u32 zmii_mode_mask(int mode, int input)
{
switch (mode) {
case PHY_MODE_MII:
return ZMII_FER_MII(input);
case PHY_MODE_RMII:
return ZMII_FER_RMII(input);
case PHY_MODE_SMII:
return ZMII_FER_SMII(input);
default:
return 0;
}
}
int zmii_attach(struct platform_device *ofdev, int input, int *mode)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
struct zmii_regs __iomem *p = dev->base;
ZMII_DBG(dev, "init(%d, %d)" NL, input, *mode);
if (!zmii_valid_mode(*mode)) {
dev->users++;
return 0;
}
mutex_lock(&dev->lock);
if (dev->mode == PHY_MODE_NA) {
if (*mode == PHY_MODE_NA) {
u32 r = dev->fer_save;
ZMII_DBG(dev, "autodetecting mode, FER = 0x%08x" NL, r);
if (r & (ZMII_FER_MII(0) | ZMII_FER_MII(1)))
dev->mode = PHY_MODE_MII;
else if (r & (ZMII_FER_RMII(0) | ZMII_FER_RMII(1)))
dev->mode = PHY_MODE_RMII;
else
dev->mode = PHY_MODE_SMII;
} else
dev->mode = *mode;
printk(KERN_NOTICE "%pOF: bridge in %s mode\n",
ofdev->dev.of_node,
zmii_mode_name(dev->mode));
} else {
if (*mode != PHY_MODE_NA && *mode != dev->mode) {
printk(KERN_ERR
"%pOF: invalid mode %d specified for input %d\n",
ofdev->dev.of_node, *mode, input);
mutex_unlock(&dev->lock);
return -EINVAL;
}
}
*mode = dev->mode;
out_be32(&p->fer, in_be32(&p->fer) | zmii_mode_mask(dev->mode, input));
++dev->users;
mutex_unlock(&dev->lock);
return 0;
}
void zmii_get_mdio(struct platform_device *ofdev, int input)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
u32 fer;
ZMII_DBG2(dev, "get_mdio(%d)" NL, input);
mutex_lock(&dev->lock);
fer = in_be32(&dev->base->fer) & ~ZMII_FER_MDI_ALL;
out_be32(&dev->base->fer, fer | ZMII_FER_MDI(input));
}
void zmii_put_mdio(struct platform_device *ofdev, int input)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
ZMII_DBG2(dev, "put_mdio(%d)" NL, input);
mutex_unlock(&dev->lock);
}
void zmii_set_speed(struct platform_device *ofdev, int input, int speed)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
u32 ssr;
mutex_lock(&dev->lock);
ssr = in_be32(&dev->base->ssr);
ZMII_DBG(dev, "speed(%d, %d)" NL, input, speed);
if (speed == SPEED_100)
ssr |= ZMII_SSR_SP(input);
else
ssr &= ~ZMII_SSR_SP(input);
out_be32(&dev->base->ssr, ssr);
mutex_unlock(&dev->lock);
}
void zmii_detach(struct platform_device *ofdev, int input)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
BUG_ON(!dev || dev->users == 0);
mutex_lock(&dev->lock);
ZMII_DBG(dev, "detach(%d)" NL, input);
out_be32(&dev->base->fer,
in_be32(&dev->base->fer) & ~zmii_mode_mask(dev->mode, input));
--dev->users;
mutex_unlock(&dev->lock);
}
int zmii_get_regs_len(struct platform_device *ofdev)
{
return sizeof(struct emac_ethtool_regs_subhdr) +
sizeof(struct zmii_regs);
}
void *zmii_dump_regs(struct platform_device *ofdev, void *buf)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
struct emac_ethtool_regs_subhdr *hdr = buf;
struct zmii_regs *regs = (struct zmii_regs *)(hdr + 1);
hdr->version = 0;
hdr->index = 0;
memcpy_fromio(regs, dev->base, sizeof(struct zmii_regs));
return regs + 1;
}
static int zmii_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct zmii_instance *dev;
struct resource regs;
int rc;
rc = -ENOMEM;
dev = kzalloc(sizeof(struct zmii_instance), GFP_KERNEL);
if (dev == NULL)
goto err_gone;
mutex_init(&dev->lock);
dev->ofdev = ofdev;
dev->mode = PHY_MODE_NA;
rc = -ENXIO;
if (of_address_to_resource(np, 0, &regs)) {
printk(KERN_ERR "%pOF: Can't get registers address\n", np);
goto err_free;
}
rc = -ENOMEM;
dev->base = (struct zmii_regs __iomem *)ioremap(regs.start,
sizeof(struct zmii_regs));
if (dev->base == NULL) {
printk(KERN_ERR "%pOF: Can't map device registers!\n", np);
goto err_free;
}
dev->fer_save = in_be32(&dev->base->fer);
out_be32(&dev->base->fer, 0);
printk(KERN_INFO "ZMII %pOF initialized\n", ofdev->dev.of_node);
wmb();
platform_set_drvdata(ofdev, dev);
return 0;
err_free:
kfree(dev);
err_gone:
return rc;
}
static int zmii_remove(struct platform_device *ofdev)
{
struct zmii_instance *dev = platform_get_drvdata(ofdev);
WARN_ON(dev->users != 0);
iounmap(dev->base);
kfree(dev);
return 0;
}
int __init zmii_init(void)
{
return platform_driver_register(&zmii_driver);
}
void zmii_exit(void)
{
platform_driver_unregister(&zmii_driver);
}
