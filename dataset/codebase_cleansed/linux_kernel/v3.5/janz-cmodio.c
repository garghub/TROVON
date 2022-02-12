static int __devinit cmodio_setup_subdevice(struct cmodio_device *priv,
char *name, unsigned int devno,
unsigned int modno)
{
struct janz_platform_data *pdata;
struct mfd_cell *cell;
struct resource *res;
struct pci_dev *pci;
pci = priv->pdev;
cell = &priv->cells[devno];
res = &priv->resources[devno * 3];
pdata = &priv->pdata[devno];
cell->name = name;
cell->resources = res;
cell->num_resources = 3;
cell->id = cmodio_id++;
pdata->modno = modno;
cell->platform_data = pdata;
cell->pdata_size = sizeof(*pdata);
res->flags = IORESOURCE_MEM;
res->parent = &pci->resource[3];
res->start = pci->resource[3].start + (CMODIO_MODULBUS_SIZE * modno);
res->end = res->start + CMODIO_MODULBUS_SIZE - 1;
res++;
res->flags = IORESOURCE_MEM;
res->parent = &pci->resource[4];
res->start = pci->resource[4].start;
res->end = pci->resource[4].end;
res++;
res->flags = IORESOURCE_IRQ;
res->parent = NULL;
res->start = 0;
res->end = 0;
res++;
return 0;
}
static int __devinit cmodio_probe_submodules(struct cmodio_device *priv)
{
struct pci_dev *pdev = priv->pdev;
unsigned int num_probed = 0;
char *name;
int i;
for (i = 0; i < num_modules; i++) {
name = modules[i];
if (!strcmp(name, "") || !strcmp(name, "empty"))
continue;
dev_dbg(&priv->pdev->dev, "MODULbus %d: name %s\n", i, name);
cmodio_setup_subdevice(priv, name, num_probed, i);
num_probed++;
}
if (num_probed == 0) {
dev_err(&priv->pdev->dev, "no MODULbus modules specified, "
"please set the ``modules'' kernel "
"parameter according to your "
"hardware configuration\n");
return -ENODEV;
}
return mfd_add_devices(&pdev->dev, 0, priv->cells,
num_probed, NULL, pdev->irq);
}
static ssize_t mbus_show(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct cmodio_device *priv = dev_get_drvdata(dev);
return snprintf(buf, PAGE_SIZE, "%x\n", priv->hex);
}
static int __devinit cmodio_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
struct cmodio_device *priv;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&dev->dev, "unable to allocate private data\n");
ret = -ENOMEM;
goto out_return;
}
pci_set_drvdata(dev, priv);
priv->pdev = dev;
ret = pci_enable_device(dev);
if (ret) {
dev_err(&dev->dev, "unable to enable device\n");
goto out_free_priv;
}
pci_set_master(dev);
ret = pci_request_regions(dev, DRV_NAME);
if (ret) {
dev_err(&dev->dev, "unable to request regions\n");
goto out_pci_disable_device;
}
priv->ctrl = pci_ioremap_bar(dev, 4);
if (!priv->ctrl) {
dev_err(&dev->dev, "unable to remap onboard regs\n");
ret = -ENOMEM;
goto out_pci_release_regions;
}
priv->hex = ioread8(&priv->ctrl->int_enable);
ret = sysfs_create_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
if (ret) {
dev_err(&dev->dev, "unable to create sysfs attributes\n");
goto out_unmap_ctrl;
}
iowrite8(0xf, &priv->ctrl->int_disable);
ret = cmodio_probe_submodules(priv);
if (ret) {
dev_err(&dev->dev, "unable to probe submodules\n");
goto out_sysfs_remove_group;
}
return 0;
out_sysfs_remove_group:
sysfs_remove_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
out_unmap_ctrl:
iounmap(priv->ctrl);
out_pci_release_regions:
pci_release_regions(dev);
out_pci_disable_device:
pci_disable_device(dev);
out_free_priv:
kfree(priv);
out_return:
return ret;
}
static void __devexit cmodio_pci_remove(struct pci_dev *dev)
{
struct cmodio_device *priv = pci_get_drvdata(dev);
mfd_remove_devices(&dev->dev);
sysfs_remove_group(&dev->dev.kobj, &cmodio_sysfs_attr_group);
iounmap(priv->ctrl);
pci_release_regions(dev);
pci_disable_device(dev);
kfree(priv);
}
