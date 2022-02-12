int gma_intel_opregion_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 opregion_phy;
void *base;
u32 *lid_state;
dev_priv->lid_state = NULL;
pci_read_config_dword(dev->pdev, 0xfc, &opregion_phy);
if (opregion_phy == 0)
return -ENOTSUPP;
base = ioremap(opregion_phy, 8*1024);
if (!base)
return -ENOMEM;
lid_state = base + 0x01ac;
dev_priv->lid_state = lid_state;
dev_priv->lid_last_state = readl(lid_state);
return 0;
}
int gma_intel_opregion_exit(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
if (dev_priv->lid_state)
iounmap(dev_priv->lid_state);
return 0;
}
