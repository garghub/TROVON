void
nouveau_irq_preinstall(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, NV03_PMC_INTR_EN_0, 0);
INIT_LIST_HEAD(&dev_priv->vbl_waiting);
}
int
nouveau_irq_postinstall(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, NV03_PMC_INTR_EN_0, NV_PMC_INTR_EN_0_MASTER_ENABLE);
if (dev_priv->msi_enabled)
nv_wr08(dev, 0x00088068, 0xff);
return 0;
}
void
nouveau_irq_uninstall(struct drm_device *dev)
{
nv_wr32(dev, NV03_PMC_INTR_EN_0, 0);
}
irqreturn_t
nouveau_irq_handler(DRM_IRQ_ARGS)
{
struct drm_device *dev = (struct drm_device *)arg;
struct drm_nouveau_private *dev_priv = dev->dev_private;
unsigned long flags;
u32 stat;
int i;
stat = nv_rd32(dev, NV03_PMC_INTR_0);
if (!stat)
return IRQ_NONE;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
for (i = 0; i < 32 && stat; i++) {
if (!(stat & (1 << i)) || !dev_priv->irq_handler[i])
continue;
dev_priv->irq_handler[i](dev);
stat &= ~(1 << i);
}
if (dev_priv->msi_enabled)
nv_wr08(dev, 0x00088068, 0xff);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
if (stat && nouveau_ratelimit())
NV_ERROR(dev, "PMC - unhandled INTR 0x%08x\n", stat);
return IRQ_HANDLED;
}
int
nouveau_irq_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
int ret;
if (nouveau_msi != 0 && dev_priv->card_type >= NV_50) {
ret = pci_enable_msi(dev->pdev);
if (ret == 0) {
NV_INFO(dev, "enabled MSI\n");
dev_priv->msi_enabled = true;
}
}
return drm_irq_install(dev);
}
void
nouveau_irq_fini(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
drm_irq_uninstall(dev);
if (dev_priv->msi_enabled)
pci_disable_msi(dev->pdev);
}
void
nouveau_irq_register(struct drm_device *dev, int status_bit,
void (*handler)(struct drm_device *))
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
dev_priv->irq_handler[status_bit] = handler;
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
}
void
nouveau_irq_unregister(struct drm_device *dev, int status_bit)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
unsigned long flags;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
dev_priv->irq_handler[status_bit] = NULL;
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
}
