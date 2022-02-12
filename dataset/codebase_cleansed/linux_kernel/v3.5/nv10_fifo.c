static int
nv10_fifo_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv10_fifo_priv *priv = nv_engine(dev, engine);
struct nv10_fifo_chan *fctx;
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
chan->id * 32, ~0, 32,
NVOBJ_FLAG_ZERO_FREE, &fctx->ramfc);
if (ret)
goto error;
nv_wo32(fctx->ramfc, 0x00, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x04, chan->pushbuf_base);
nv_wo32(fctx->ramfc, 0x08, 0x00000000);
nv_wo32(fctx->ramfc, 0x0c, chan->pushbuf->pinst >> 4);
nv_wo32(fctx->ramfc, 0x10, 0x00000000);
nv_wo32(fctx->ramfc, 0x14, NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
nv_wo32(fctx->ramfc, 0x18, 0x00000000);
nv_wo32(fctx->ramfc, 0x1c, 0x00000000);
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_mask(dev, NV04_PFIFO_MODE, (1 << chan->id), (1 << chan->id));
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
error:
if (ret)
priv->base.base.context_del(chan, engine);
return ret;
}
int
nv10_fifo_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv10_fifo_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.base.destroy = nv04_fifo_destroy;
priv->base.base.init = nv04_fifo_init;
priv->base.base.fini = nv04_fifo_fini;
priv->base.base.context_new = nv10_fifo_context_new;
priv->base.base.context_del = nv04_fifo_context_del;
priv->base.channels = 31;
priv->ramfc_desc = nv10_ramfc;
dev_priv->eng[NVOBJ_ENGINE_FIFO] = &priv->base.base;
nouveau_irq_register(dev, 8, nv04_fifo_isr);
return 0;
}
