static void
nvc0_fb_destroy(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
struct nvc0_fb_priv *priv = pfb->priv;
if (priv->r100c10_page) {
pci_unmap_page(dev->pdev, priv->r100c10, PAGE_SIZE,
PCI_DMA_BIDIRECTIONAL);
__free_page(priv->r100c10_page);
}
kfree(priv);
pfb->priv = NULL;
}
static int
nvc0_fb_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
struct nvc0_fb_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
pfb->priv = priv;
priv->r100c10_page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!priv->r100c10_page) {
nvc0_fb_destroy(dev);
return -ENOMEM;
}
priv->r100c10 = pci_map_page(dev->pdev, priv->r100c10_page, 0,
PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(dev->pdev, priv->r100c10)) {
nvc0_fb_destroy(dev);
return -EFAULT;
}
return 0;
}
int
nvc0_fb_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvc0_fb_priv *priv;
int ret;
if (!dev_priv->engine.fb.priv) {
ret = nvc0_fb_create(dev);
if (ret)
return ret;
}
priv = dev_priv->engine.fb.priv;
nv_wr32(dev, 0x100c10, priv->r100c10 >> 8);
return 0;
}
void
nvc0_fb_takedown(struct drm_device *dev)
{
nvc0_fb_destroy(dev);
}
