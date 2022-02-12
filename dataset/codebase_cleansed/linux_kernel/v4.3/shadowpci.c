static u32
pcirom_read(void *data, u32 offset, u32 length, struct nvkm_bios *bios)
{
struct priv *priv = data;
if (offset + length <= priv->size) {
memcpy_fromio(bios->data + offset, priv->rom + offset, length);
return length;
}
return 0;
}
static void
pcirom_fini(void *data)
{
struct priv *priv = data;
pci_unmap_rom(priv->pdev, priv->rom);
pci_disable_rom(priv->pdev);
kfree(priv);
}
static void *
pcirom_init(struct nvkm_bios *bios, const char *name)
{
struct nvkm_device *device = bios->subdev.device;
struct priv *priv = NULL;
struct pci_dev *pdev;
int ret;
if (device->func->pci)
pdev = device->func->pci(device)->pdev;
else
return ERR_PTR(-ENODEV);
if (!(ret = pci_enable_rom(pdev))) {
if (ret = -ENOMEM,
(priv = kmalloc(sizeof(*priv), GFP_KERNEL))) {
if (ret = -EFAULT,
(priv->rom = pci_map_rom(pdev, &priv->size))) {
priv->pdev = pdev;
return priv;
}
kfree(priv);
}
pci_disable_rom(pdev);
}
return ERR_PTR(ret);
}
static void *
platform_init(struct nvkm_bios *bios, const char *name)
{
struct nvkm_device *device = bios->subdev.device;
struct pci_dev *pdev;
struct priv *priv;
int ret = -ENOMEM;
if (device->func->pci)
pdev = device->func->pci(device)->pdev;
else
return ERR_PTR(-ENODEV);
if ((priv = kmalloc(sizeof(*priv), GFP_KERNEL))) {
if (ret = -ENODEV,
(priv->rom = pci_platform_rom(pdev, &priv->size)))
return priv;
kfree(priv);
}
return ERR_PTR(ret);
}
