int tah_attach(struct platform_device *ofdev, int channel)
{
struct tah_instance *dev = platform_get_drvdata(ofdev);
mutex_lock(&dev->lock);
++dev->users;
mutex_unlock(&dev->lock);
return 0;
}
void tah_detach(struct platform_device *ofdev, int channel)
{
struct tah_instance *dev = platform_get_drvdata(ofdev);
mutex_lock(&dev->lock);
--dev->users;
mutex_unlock(&dev->lock);
}
void tah_reset(struct platform_device *ofdev)
{
struct tah_instance *dev = platform_get_drvdata(ofdev);
struct tah_regs __iomem *p = dev->base;
int n;
out_be32(&p->mr, TAH_MR_SR);
n = 100;
while ((in_be32(&p->mr) & TAH_MR_SR) && n)
--n;
if (unlikely(!n))
printk(KERN_ERR "%s: reset timeout\n",
ofdev->dev.of_node->full_name);
out_be32(&p->mr,
TAH_MR_CVR | TAH_MR_ST_768 | TAH_MR_TFS_10KB | TAH_MR_DTFP |
TAH_MR_DIG);
}
int tah_get_regs_len(struct platform_device *ofdev)
{
return sizeof(struct emac_ethtool_regs_subhdr) +
sizeof(struct tah_regs);
}
void *tah_dump_regs(struct platform_device *ofdev, void *buf)
{
struct tah_instance *dev = platform_get_drvdata(ofdev);
struct emac_ethtool_regs_subhdr *hdr = buf;
struct tah_regs *regs = (struct tah_regs *)(hdr + 1);
hdr->version = 0;
hdr->index = 0;
memcpy_fromio(regs, dev->base, sizeof(struct tah_regs));
return regs + 1;
}
static int tah_probe(struct platform_device *ofdev)
{
struct device_node *np = ofdev->dev.of_node;
struct tah_instance *dev;
struct resource regs;
int rc;
rc = -ENOMEM;
dev = kzalloc(sizeof(struct tah_instance), GFP_KERNEL);
if (dev == NULL)
goto err_gone;
mutex_init(&dev->lock);
dev->ofdev = ofdev;
rc = -ENXIO;
if (of_address_to_resource(np, 0, &regs)) {
printk(KERN_ERR "%s: Can't get registers address\n",
np->full_name);
goto err_free;
}
rc = -ENOMEM;
dev->base = (struct tah_regs __iomem *)ioremap(regs.start,
sizeof(struct tah_regs));
if (dev->base == NULL) {
printk(KERN_ERR "%s: Can't map device registers!\n",
np->full_name);
goto err_free;
}
platform_set_drvdata(ofdev, dev);
tah_reset(ofdev);
printk(KERN_INFO
"TAH %s initialized\n", ofdev->dev.of_node->full_name);
wmb();
return 0;
err_free:
kfree(dev);
err_gone:
return rc;
}
static int tah_remove(struct platform_device *ofdev)
{
struct tah_instance *dev = platform_get_drvdata(ofdev);
WARN_ON(dev->users != 0);
iounmap(dev->base);
kfree(dev);
return 0;
}
int __init tah_init(void)
{
return platform_driver_register(&tah_driver);
}
void tah_exit(void)
{
platform_driver_unregister(&tah_driver);
}
