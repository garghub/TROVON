static void sercos3_disable_interrupts(struct uio_info *info,
struct sercos3_priv *priv)
{
void __iomem *ier0 = info->mem[3].internal_addr + IER0_OFFSET;
priv->ier0_cache |= ioread32(ier0);
iowrite32(0, ier0);
}
static void sercos3_enable_interrupts(struct uio_info *info,
struct sercos3_priv *priv)
{
void __iomem *ier0 = info->mem[3].internal_addr + IER0_OFFSET;
iowrite32(ioread32(ier0) | priv->ier0_cache, ier0);
priv->ier0_cache = 0;
}
static irqreturn_t sercos3_handler(int irq, struct uio_info *info)
{
struct sercos3_priv *priv = info->priv;
void __iomem *isr0 = info->mem[3].internal_addr + ISR0_OFFSET;
void __iomem *ier0 = info->mem[3].internal_addr + IER0_OFFSET;
if (!(ioread32(isr0) & ioread32(ier0)))
return IRQ_NONE;
spin_lock(&priv->ier0_cache_lock);
sercos3_disable_interrupts(info, priv);
spin_unlock(&priv->ier0_cache_lock);
return IRQ_HANDLED;
}
static int sercos3_irqcontrol(struct uio_info *info, s32 irq_on)
{
struct sercos3_priv *priv = info->priv;
spin_lock_irq(&priv->ier0_cache_lock);
if (irq_on)
sercos3_enable_interrupts(info, priv);
else
sercos3_disable_interrupts(info, priv);
spin_unlock_irq(&priv->ier0_cache_lock);
return 0;
}
static int sercos3_setup_iomem(struct pci_dev *dev, struct uio_info *info,
int n, int pci_bar)
{
info->mem[n].addr = pci_resource_start(dev, pci_bar);
if (!info->mem[n].addr)
return -1;
info->mem[n].internal_addr = ioremap(pci_resource_start(dev, pci_bar),
pci_resource_len(dev, pci_bar));
if (!info->mem[n].internal_addr)
return -1;
info->mem[n].size = pci_resource_len(dev, pci_bar);
info->mem[n].memtype = UIO_MEM_PHYS;
return 0;
}
static int sercos3_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct uio_info *info;
struct sercos3_priv *priv;
int i;
info = kzalloc(sizeof(struct uio_info), GFP_KERNEL);
if (!info)
return -ENOMEM;
priv = kzalloc(sizeof(struct sercos3_priv), GFP_KERNEL);
if (!priv)
goto out_free;
if (pci_enable_device(dev))
goto out_free_priv;
if (pci_request_regions(dev, "sercos3"))
goto out_disable;
if (sercos3_setup_iomem(dev, info, 0, 0))
goto out_unmap;
if (sercos3_setup_iomem(dev, info, 1, 2))
goto out_unmap;
if (sercos3_setup_iomem(dev, info, 2, 3))
goto out_unmap;
if (sercos3_setup_iomem(dev, info, 3, 4))
goto out_unmap;
if (sercos3_setup_iomem(dev, info, 4, 5))
goto out_unmap;
spin_lock_init(&priv->ier0_cache_lock);
info->priv = priv;
info->name = "Sercos_III_PCI";
info->version = "0.0.1";
info->irq = dev->irq;
info->irq_flags = IRQF_SHARED;
info->handler = sercos3_handler;
info->irqcontrol = sercos3_irqcontrol;
pci_set_drvdata(dev, info);
if (uio_register_device(&dev->dev, info))
goto out_unmap;
return 0;
out_unmap:
for (i = 0; i < 5; i++) {
if (info->mem[i].internal_addr)
iounmap(info->mem[i].internal_addr);
}
pci_release_regions(dev);
out_disable:
pci_disable_device(dev);
out_free_priv:
kfree(priv);
out_free:
kfree(info);
return -ENODEV;
}
static void sercos3_pci_remove(struct pci_dev *dev)
{
struct uio_info *info = pci_get_drvdata(dev);
int i;
uio_unregister_device(info);
pci_release_regions(dev);
pci_disable_device(dev);
pci_set_drvdata(dev, NULL);
for (i = 0; i < 5; i++) {
if (info->mem[i].internal_addr)
iounmap(info->mem[i].internal_addr);
}
kfree(info->priv);
kfree(info);
}
