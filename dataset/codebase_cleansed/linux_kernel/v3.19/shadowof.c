static u32
of_read(void *data, u32 offset, u32 length, struct nouveau_bios *bios)
{
struct priv *priv = data;
if (offset + length <= priv->size) {
memcpy_fromio(bios->data + offset, priv->data + offset, length);
return length;
}
return 0;
}
static void *
of_init(struct nouveau_bios *bios, const char *name)
{
struct pci_dev *pdev = nv_device(bios)->pdev;
struct device_node *dn;
struct priv *priv;
if (!(dn = pci_device_to_OF_node(pdev)))
return ERR_PTR(-ENODEV);
if (!(priv = kzalloc(sizeof(*priv), GFP_KERNEL)))
return ERR_PTR(-ENOMEM);
if ((priv->data = of_get_property(dn, "NVDA,BMP", &priv->size)))
return priv;
kfree(priv);
return ERR_PTR(-EINVAL);
}
