static int
nv40_fifo_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv40_fifo_priv *priv = nv_engine(dev, engine);
struct nv40_fifo_chan *fctx;
unsigned long flags;
int ret;
fctx = chan->engctx[engine] = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return -ENOMEM;
chan->user = ioremap(pci_resource_start(dev->pdev, 0) +
NV03_USER(chan->id), PAGE_SIZE);
if (!chan->user) {
ret = -ENOMEM;
goto error;
}
ret = nouveau_gpuobj_new_fake(dev, dev_priv->ramfc->pinst +
chan->id * 128, ~0, 128,
NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &fctx->ramfc);
if (ret)
goto error;
nv_wo32(fctx->ramfc, 0x00, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x04, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x0c, chan->pushbuf->pinst >> 4);
nv_wo32(fctx->ramfc, 0x18, 0x30000000 |
NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
nv_wo32(fctx->ramfc, 0x3c, 0x0001ffff);
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, NV04_PFIFO_MODE, (1 << chan->id), (1 << chan->id));
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
nouveau_gpuobj_ref(fctx->ramfc, &chan->ramfc);
error:
if (ret)
priv->base.base.context_del(chan, engine);
return ret;
}
static int
nv40_fifo_init(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv40_fifo_priv *priv = nv_engine(dev, engine);
int i;
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, 0);
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, 0x002040, 0x000000ff);
nv_wr32(dev, 0x002044, 0x2101ffff);
nv_wr32(dev, 0x002058, 0x00000001);
nv_wr32(dev, NV03_PFIFO_RAMHT, (0x03 << 24) |
((dev_priv->ramht->bits - 9) << 16) |
(dev_priv->ramht->gpuobj->pinst >> 8));
nv_wr32(dev, NV03_PFIFO_RAMRO, dev_priv->ramro->pinst >> 8);
switch (dev_priv->chipset) {
case 0x47:
case 0x49:
case 0x4b:
nv_wr32(dev, 0x002230, 0x00000001);
case 0x40:
case 0x41:
case 0x42:
case 0x43:
case 0x45:
case 0x48:
nv_wr32(dev, 0x002220, 0x00030002);
break;
default:
nv_wr32(dev, 0x002230, 0x00000000);
nv_wr32(dev, 0x002220, ((dev_priv->vram_size - 512 * 1024 +
dev_priv->ramfc->pinst) >> 16) |
0x00030000);
break;
}
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1, priv->base.channels);
nv_wr32(dev, NV03_PFIFO_INTR_0, 0xffffffff);
nv_wr32(dev, NV03_PFIFO_INTR_EN_0, 0xffffffff);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0, 1);
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL0, 1);
nv_wr32(dev, NV03_PFIFO_CACHES, 1);
for (i = 0; i < priv->base.channels; i++) {
if (dev_priv->channels.ptr[i])
nv_mask(dev, NV04_PFIFO_MODE, (1 << i), (1 << i));
}
return 0;
}
int
nv40_fifo_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv40_fifo_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.base.destroy = nv04_fifo_destroy;
priv->base.base.init = nv40_fifo_init;
priv->base.base.fini = nv04_fifo_fini;
priv->base.base.context_new = nv40_fifo_context_new;
priv->base.base.context_del = nv04_fifo_context_del;
priv->base.channels = 31;
priv->ramfc_desc = nv40_ramfc;
dev_priv->eng[NVOBJ_ENGINE_FIFO] = &priv->base.base;
nouveau_irq_register(dev, 8, nv04_fifo_isr);
return 0;
}
