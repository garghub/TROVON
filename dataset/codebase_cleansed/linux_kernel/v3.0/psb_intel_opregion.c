int psb_intel_opregion_init(struct drm_device *dev)
{
struct drm_psb_private *dev_priv = dev->dev_private;
u32 opregion_phy;
void *base;
u32 *lid_state;
dev_priv->lid_state = NULL;
pci_read_config_dword(dev->pdev, 0xfc, &opregion_phy);
if (opregion_phy == 0) {
DRM_DEBUG("Opregion not supported, won't support lid-switch\n");
return -ENOTSUPP;
}
DRM_DEBUG("OpRegion detected at 0x%8x\n", opregion_phy);
base = ioremap(opregion_phy, 8*1024);
if (!base)
return -ENOMEM;
lid_state = base + 0x01ac;
DRM_DEBUG("Lid switch state 0x%08x\n", *lid_state);
dev_priv->lid_state = lid_state;
dev_priv->lid_last_state = *lid_state;
return 0;
}
