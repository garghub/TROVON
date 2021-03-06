int
nv10_fifo_channel_id(struct drm_device *dev)
{
return nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH1) &
NV10_PFIFO_CACHE1_PUSH1_CHID_MASK;
}
int
nv10_fifo_create_context(struct nouveau_channel *chan)
{
struct drm_nouveau_private *dev_priv = chan->dev->dev_private;
struct drm_device *dev = chan->dev;
uint32_t fc = NV10_RAMFC(chan->id);
int ret;
ret = nouveau_gpuobj_new_fake(dev, NV10_RAMFC(chan->id), ~0,
NV10_RAMFC__SIZE, NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &chan->ramfc);
if (ret)
return ret;
chan->user = ioremap(pci_resource_start(dev->pdev, 0) +
NV03_USER(chan->id), PAGE_SIZE);
if (!chan->user)
return -ENOMEM;
nv_wi32(dev, fc + 0, chan->pushbuf_base);
nv_wi32(dev, fc + 4, chan->pushbuf_base);
nv_wi32(dev, fc + 12, chan->pushbuf->pinst >> 4);
nv_wi32(dev, fc + 20, NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8 |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
0);
nv_wr32(dev, NV04_PFIFO_MODE,
nv_rd32(dev, NV04_PFIFO_MODE) | (1 << chan->id));
return 0;
}
static void
nv10_fifo_do_load_context(struct drm_device *dev, int chid)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t fc = NV10_RAMFC(chid), tmp;
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUT, nv_ri32(dev, fc + 0));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_GET, nv_ri32(dev, fc + 4));
nv_wr32(dev, NV10_PFIFO_CACHE1_REF_CNT, nv_ri32(dev, fc + 8));
tmp = nv_ri32(dev, fc + 12);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_INSTANCE, tmp & 0xFFFF);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_DCOUNT, tmp >> 16);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_STATE, nv_ri32(dev, fc + 16));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_FETCH, nv_ri32(dev, fc + 20));
nv_wr32(dev, NV04_PFIFO_CACHE1_ENGINE, nv_ri32(dev, fc + 24));
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL1, nv_ri32(dev, fc + 28));
if (dev_priv->chipset < 0x17)
goto out;
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_VALUE, nv_ri32(dev, fc + 32));
tmp = nv_ri32(dev, fc + 36);
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMESTAMP, tmp);
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMEOUT, nv_ri32(dev, fc + 40));
nv_wr32(dev, NV10_PFIFO_CACHE1_SEMAPHORE, nv_ri32(dev, fc + 44));
nv_wr32(dev, NV10_PFIFO_CACHE1_DMA_SUBROUTINE, nv_ri32(dev, fc + 48));
out:
nv_wr32(dev, NV03_PFIFO_CACHE1_GET, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUT, 0);
}
int
nv10_fifo_load_context(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
uint32_t tmp;
nv10_fifo_do_load_context(dev, chan->id);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1,
NV03_PFIFO_CACHE1_PUSH1_DMA | chan->id);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUSH, 1);
tmp = nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_CTL) & ~(1 << 31);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_CTL, tmp);
return 0;
}
int
nv10_fifo_unload_context(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
uint32_t fc, tmp;
int chid;
chid = pfifo->channel_id(dev);
if (chid < 0 || chid >= dev_priv->engine.fifo.channels)
return 0;
fc = NV10_RAMFC(chid);
nv_wi32(dev, fc + 0, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_PUT));
nv_wi32(dev, fc + 4, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_GET));
nv_wi32(dev, fc + 8, nv_rd32(dev, NV10_PFIFO_CACHE1_REF_CNT));
tmp = nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_INSTANCE) & 0xFFFF;
tmp |= (nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_DCOUNT) << 16);
nv_wi32(dev, fc + 12, tmp);
nv_wi32(dev, fc + 16, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_STATE));
nv_wi32(dev, fc + 20, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_FETCH));
nv_wi32(dev, fc + 24, nv_rd32(dev, NV04_PFIFO_CACHE1_ENGINE));
nv_wi32(dev, fc + 28, nv_rd32(dev, NV04_PFIFO_CACHE1_PULL1));
if (dev_priv->chipset < 0x17)
goto out;
nv_wi32(dev, fc + 32, nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_VALUE));
tmp = nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMESTAMP);
nv_wi32(dev, fc + 36, tmp);
nv_wi32(dev, fc + 40, nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMEOUT));
nv_wi32(dev, fc + 44, nv_rd32(dev, NV10_PFIFO_CACHE1_SEMAPHORE));
nv_wi32(dev, fc + 48, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_GET));
out:
nv10_fifo_do_load_context(dev, pfifo->channels - 1);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1, pfifo->channels - 1);
return 0;
}
static void
nv10_fifo_init_reset(struct drm_device *dev)
{
nv_wr32(dev, NV03_PMC_ENABLE,
nv_rd32(dev, NV03_PMC_ENABLE) & ~NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, NV03_PMC_ENABLE,
nv_rd32(dev, NV03_PMC_ENABLE) | NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, 0x003224, 0x000f0078);
nv_wr32(dev, 0x002044, 0x0101ffff);
nv_wr32(dev, 0x002040, 0x000000ff);
nv_wr32(dev, 0x002500, 0x00000000);
nv_wr32(dev, 0x003000, 0x00000000);
nv_wr32(dev, 0x003050, 0x00000000);
nv_wr32(dev, 0x003258, 0x00000000);
nv_wr32(dev, 0x003210, 0x00000000);
nv_wr32(dev, 0x003270, 0x00000000);
}
static void
nv10_fifo_init_ramxx(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, NV03_PFIFO_RAMHT, (0x03 << 24) |
((dev_priv->ramht->bits - 9) << 16) |
(dev_priv->ramht->gpuobj->pinst >> 8));
nv_wr32(dev, NV03_PFIFO_RAMRO, dev_priv->ramro->pinst >> 8);
if (dev_priv->chipset < 0x17) {
nv_wr32(dev, NV03_PFIFO_RAMFC, dev_priv->ramfc->pinst >> 8);
} else {
nv_wr32(dev, NV03_PFIFO_RAMFC, (dev_priv->ramfc->pinst >> 8) |
(1 << 16) );
}
}
static void
nv10_fifo_init_intr(struct drm_device *dev)
{
nouveau_irq_register(dev, 8, nv04_fifo_isr);
nv_wr32(dev, 0x002100, 0xffffffff);
nv_wr32(dev, 0x002140, 0xffffffff);
}
int
nv10_fifo_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
int i;
nv10_fifo_init_reset(dev);
nv10_fifo_init_ramxx(dev);
nv10_fifo_do_load_context(dev, pfifo->channels - 1);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1, pfifo->channels - 1);
nv10_fifo_init_intr(dev);
pfifo->enable(dev);
pfifo->reassign(dev, true);
for (i = 0; i < dev_priv->engine.fifo.channels; i++) {
if (dev_priv->channels.ptr[i]) {
uint32_t mode = nv_rd32(dev, NV04_PFIFO_MODE);
nv_wr32(dev, NV04_PFIFO_MODE, mode | (1 << i));
}
}
return 0;
}
