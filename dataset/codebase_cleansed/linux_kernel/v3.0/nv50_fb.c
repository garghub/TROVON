static void
nv50_fb_destroy(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
struct nv50_fb_priv *priv = pfb->priv;
if (drm_mm_initialized(&pfb->tag_heap))
drm_mm_takedown(&pfb->tag_heap);
if (priv->r100c08_page) {
pci_unmap_page(dev->pdev, priv->r100c08, PAGE_SIZE,
PCI_DMA_BIDIRECTIONAL);
__free_page(priv->r100c08_page);
}
kfree(priv);
pfb->priv = NULL;
}
static int
nv50_fb_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fb_engine *pfb = &dev_priv->engine.fb;
struct nv50_fb_priv *priv;
u32 tagmem;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
pfb->priv = priv;
priv->r100c08_page = alloc_page(GFP_KERNEL | __GFP_ZERO);
if (!priv->r100c08_page) {
nv50_fb_destroy(dev);
return -ENOMEM;
}
priv->r100c08 = pci_map_page(dev->pdev, priv->r100c08_page, 0,
PAGE_SIZE, PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(dev->pdev, priv->r100c08)) {
nv50_fb_destroy(dev);
return -EFAULT;
}
tagmem = nv_rd32(dev, 0x100320);
NV_DEBUG(dev, "%d tags available\n", tagmem);
ret = drm_mm_init(&pfb->tag_heap, 0, tagmem);
if (ret) {
nv50_fb_destroy(dev);
return ret;
}
return 0;
}
int
nv50_fb_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv50_fb_priv *priv;
int ret;
if (!dev_priv->engine.fb.priv) {
ret = nv50_fb_create(dev);
if (ret)
return ret;
}
priv = dev_priv->engine.fb.priv;
nv_wr32(dev, 0x100c08, priv->r100c08 >> 8);
switch (dev_priv->chipset) {
case 0x50:
nv_wr32(dev, 0x100c90, 0x000707ff);
break;
case 0xa3:
case 0xa5:
case 0xa8:
nv_wr32(dev, 0x100c90, 0x000d0fff);
break;
case 0xaf:
nv_wr32(dev, 0x100c90, 0x089d1fff);
break;
default:
nv_wr32(dev, 0x100c90, 0x001d07ff);
break;
}
return 0;
}
void
nv50_fb_takedown(struct drm_device *dev)
{
nv50_fb_destroy(dev);
}
void
nv50_fb_vm_trap(struct drm_device *dev, int display)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
const struct nouveau_enum *en, *cl;
unsigned long flags;
u32 trap[6], idx, chinst;
u8 st0, st1, st2, st3;
int i, ch;
idx = nv_rd32(dev, 0x100c90);
if (!(idx & 0x80000000))
return;
idx &= 0x00ffffff;
for (i = 0; i < 6; i++) {
nv_wr32(dev, 0x100c90, idx | i << 24);
trap[i] = nv_rd32(dev, 0x100c94);
}
nv_wr32(dev, 0x100c90, idx | 0x80000000);
if (!display)
return;
chinst = (trap[2] << 16) | trap[1];
spin_lock_irqsave(&dev_priv->channels.lock, flags);
for (ch = 0; ch < dev_priv->engine.fifo.channels; ch++) {
struct nouveau_channel *chan = dev_priv->channels.ptr[ch];
if (!chan || !chan->ramin)
continue;
if (chinst == chan->ramin->vinst >> 12)
break;
}
spin_unlock_irqrestore(&dev_priv->channels.lock, flags);
if (dev_priv->chipset < 0xa3 ||
dev_priv->chipset == 0xaa || dev_priv->chipset == 0xac) {
st0 = (trap[0] & 0x0000000f) >> 0;
st1 = (trap[0] & 0x000000f0) >> 4;
st2 = (trap[0] & 0x00000f00) >> 8;
st3 = (trap[0] & 0x0000f000) >> 12;
} else {
st0 = (trap[0] & 0x000000ff) >> 0;
st1 = (trap[0] & 0x0000ff00) >> 8;
st2 = (trap[0] & 0x00ff0000) >> 16;
st3 = (trap[0] & 0xff000000) >> 24;
}
NV_INFO(dev, "VM: trapped %s at 0x%02x%04x%04x on ch %d [0x%08x] ",
(trap[5] & 0x00000100) ? "read" : "write",
trap[5] & 0xff, trap[4] & 0xffff, trap[3] & 0xffff, ch, chinst);
en = nouveau_enum_find(vm_engine, st0);
if (en)
printk("%s/", en->name);
else
printk("%02x/", st0);
cl = nouveau_enum_find(vm_client, st2);
if (cl)
printk("%s/", cl->name);
else
printk("%02x/", st2);
if (cl && cl->data) cl = nouveau_enum_find(cl->data, st3);
else if (en && en->data) cl = nouveau_enum_find(en->data, st3);
else cl = NULL;
if (cl)
printk("%s", cl->name);
else
printk("%02x", st3);
printk(" reason: ");
en = nouveau_enum_find(vm_fault, st1);
if (en)
printk("%s\n", en->name);
else
printk("0x%08x\n", st1);
}
