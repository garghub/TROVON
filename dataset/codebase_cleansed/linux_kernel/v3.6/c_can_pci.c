static u16 c_can_pci_read_reg_aligned_to_16bit(struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + priv->regs[index]);
}
static void c_can_pci_write_reg_aligned_to_16bit(struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + priv->regs[index]);
}
static u16 c_can_pci_read_reg_aligned_to_32bit(struct c_can_priv *priv,
enum reg index)
{
return readw(priv->base + 2 * priv->regs[index]);
}
static void c_can_pci_write_reg_aligned_to_32bit(struct c_can_priv *priv,
enum reg index, u16 val)
{
writew(val, priv->base + 2 * priv->regs[index]);
}
static int __devinit c_can_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
struct c_can_pci_data *c_can_pci_data = (void *)ent->driver_data;
struct c_can_priv *priv;
struct net_device *dev;
void __iomem *addr;
int ret;
ret = pci_enable_device(pdev);
if (ret) {
dev_err(&pdev->dev, "pci_enable_device FAILED\n");
goto out;
}
ret = pci_request_regions(pdev, KBUILD_MODNAME);
if (ret) {
dev_err(&pdev->dev, "pci_request_regions FAILED\n");
goto out_disable_device;
}
pci_set_master(pdev);
pci_enable_msi(pdev);
addr = pci_iomap(pdev, 0, pci_resource_len(pdev, 0));
if (!addr) {
dev_err(&pdev->dev,
"device has no PCI memory resources, "
"failing adapter\n");
ret = -ENOMEM;
goto out_release_regions;
}
dev = alloc_c_can_dev();
if (!dev) {
ret = -ENOMEM;
goto out_iounmap;
}
priv = netdev_priv(dev);
pci_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
dev->irq = pdev->irq;
priv->base = addr;
if (!c_can_pci_data->freq) {
dev_err(&pdev->dev, "no clock frequency defined\n");
ret = -ENODEV;
goto out_free_c_can;
} else {
priv->can.clock.freq = c_can_pci_data->freq;
}
switch (c_can_pci_data->type) {
case C_CAN_DEVTYPE:
priv->regs = reg_map_c_can;
break;
case D_CAN_DEVTYPE:
priv->regs = reg_map_d_can;
priv->can.ctrlmode_supported |= CAN_CTRLMODE_3_SAMPLES;
break;
default:
ret = -EINVAL;
goto out_free_c_can;
}
switch (c_can_pci_data->reg_align) {
case C_CAN_REG_ALIGN_32:
priv->read_reg = c_can_pci_read_reg_aligned_to_32bit;
priv->write_reg = c_can_pci_write_reg_aligned_to_32bit;
break;
case C_CAN_REG_ALIGN_16:
priv->read_reg = c_can_pci_read_reg_aligned_to_16bit;
priv->write_reg = c_can_pci_write_reg_aligned_to_16bit;
break;
default:
ret = -EINVAL;
goto out_free_c_can;
}
ret = register_c_can_dev(dev);
if (ret) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
KBUILD_MODNAME, ret);
goto out_free_c_can;
}
dev_dbg(&pdev->dev, "%s device registered (regs=%p, irq=%d)\n",
KBUILD_MODNAME, priv->regs, dev->irq);
return 0;
out_free_c_can:
pci_set_drvdata(pdev, NULL);
free_c_can_dev(dev);
out_iounmap:
pci_iounmap(pdev, addr);
out_release_regions:
pci_disable_msi(pdev);
pci_clear_master(pdev);
pci_release_regions(pdev);
out_disable_device:
pci_disable_device(pdev);
out:
return ret;
}
static void __devexit c_can_pci_remove(struct pci_dev *pdev)
{
struct net_device *dev = pci_get_drvdata(pdev);
struct c_can_priv *priv = netdev_priv(dev);
unregister_c_can_dev(dev);
pci_set_drvdata(pdev, NULL);
free_c_can_dev(dev);
pci_iounmap(pdev, priv->base);
pci_disable_msi(pdev);
pci_clear_master(pdev);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
