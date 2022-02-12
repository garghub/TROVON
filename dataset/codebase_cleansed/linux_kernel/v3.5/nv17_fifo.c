static int
nv17_fifo_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv17_fifo_priv *priv = nv_engine(dev, engine);
struct nv17_fifo_chan *fctx;
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
chan->id * 64, ~0, 64,
NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &fctx->ramfc);
if (ret)
goto error;
nv_wo32(fctx->ramfc, 0x00, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x04, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x0c, chan->pushbuf->pinst >> 4);
nv_wo32(fctx->ramfc, 0x14, NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, NV04_PFIFO_MODE, (1 << chan->id), (1 << chan->id));
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
error:
if (ret)
priv->base.base.context_del(chan, engine);
return ret;
}
static int
nv17_fifo_init(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv17_fifo_priv *priv = nv_engine(dev, engine);
int i;
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, 0);
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, NV04_PFIFO_DELAY_0, 0x000000ff);
nv_wr32(dev, NV04_PFIFO_DMA_TIMESLICE, 0x0101ffff);
nv_wr32(dev, NV03_PFIFO_RAMHT, (0x03 << 24) |
((dev_priv->ramht->bits - 9) << 16) |
(dev_priv->ramht->gpuobj->pinst >> 8));
nv_wr32(dev, NV03_PFIFO_RAMRO, dev_priv->ramro->pinst >> 8);
nv_wr32(dev, NV03_PFIFO_RAMFC, 0x00010000 |
dev_priv->ramfc->pinst >> 8);
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
nv17_fifo_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv17_fifo_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.base.destroy = nv04_fifo_destroy;
priv->base.base.init = nv17_fifo_init;
priv->base.base.fini = nv04_fifo_fini;
priv->base.base.context_new = nv17_fifo_context_new;
priv->base.base.context_del = nv04_fifo_context_del;
priv->base.channels = 31;
priv->ramfc_desc = nv17_ramfc;
dev_priv->eng[NVOBJ_ENGINE_FIFO] = &priv->base.base;
nouveau_irq_register(dev, 8, nv04_fifo_isr);
return 0;
}
