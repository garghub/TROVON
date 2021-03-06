int
nv40_fifo_create_context(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t fc = NV40_RAMFC(chan->id);
unsigned long flags;
int ret;
ret = nouveau_gpuobj_new_fake(dev, NV40_RAMFC(chan->id), ~0,
NV40_RAMFC__SIZE, NVOBJ_FLAG_ZERO_ALLOC |
NVOBJ_FLAG_ZERO_FREE, &chan->ramfc);
if (ret)
return ret;
chan->user = ioremap(pci_resource_start(dev->pdev, 0) +
NV40_USER(chan->id), PAGE_SIZE);
if (!chan->user)
return -ENOMEM;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_wi32(dev, fc + 0, chan->pushbuf_base);
nv_wi32(dev, fc + 4, chan->pushbuf_base);
nv_wi32(dev, fc + 12, chan->pushbuf->pinst >> 4);
nv_wi32(dev, fc + 24, NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8 |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
0x30000000 );
nv_wi32(dev, fc + 60, 0x0001FFFF);
nv_wr32(dev, NV04_PFIFO_MODE,
nv_rd32(dev, NV04_PFIFO_MODE) | (1 << chan->id));
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
return 0;
}
static void
nv40_fifo_do_load_context(struct drm_device *dev, int chid)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t fc = NV40_RAMFC(chid), tmp, tmp2;
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUT, nv_ri32(dev, fc + 0));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_GET, nv_ri32(dev, fc + 4));
nv_wr32(dev, NV10_PFIFO_CACHE1_REF_CNT, nv_ri32(dev, fc + 8));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_INSTANCE, nv_ri32(dev, fc + 12));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_DCOUNT, nv_ri32(dev, fc + 16));
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_STATE, nv_ri32(dev, fc + 20));
tmp = nv_ri32(dev, fc + 24);
tmp2 = nv_rd32(dev, 0x2058) & 0xFFF;
tmp2 |= (tmp & 0x30000000);
nv_wr32(dev, 0x2058, tmp2);
tmp &= ~0x30000000;
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_FETCH, tmp);
nv_wr32(dev, NV04_PFIFO_CACHE1_ENGINE, nv_ri32(dev, fc + 28));
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL1, nv_ri32(dev, fc + 32));
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_VALUE, nv_ri32(dev, fc + 36));
tmp = nv_ri32(dev, fc + 40);
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMESTAMP, tmp);
nv_wr32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMEOUT, nv_ri32(dev, fc + 44));
nv_wr32(dev, NV10_PFIFO_CACHE1_SEMAPHORE, nv_ri32(dev, fc + 48));
nv_wr32(dev, NV10_PFIFO_CACHE1_DMA_SUBROUTINE, nv_ri32(dev, fc + 52));
nv_wr32(dev, NV40_PFIFO_GRCTX_INSTANCE, nv_ri32(dev, fc + 56));
tmp = nv_rd32(dev, NV04_PFIFO_DMA_TIMESLICE) & ~0x1FFFF;
tmp |= nv_ri32(dev, fc + 60) & 0x1FFFF;
nv_wr32(dev, NV04_PFIFO_DMA_TIMESLICE, tmp);
nv_wr32(dev, 0x32e4, nv_ri32(dev, fc + 64));
nv_wr32(dev, 0x32e8, nv_ri32(dev, fc + 68));
nv_wr32(dev, 0x2088, nv_ri32(dev, fc + 76));
nv_wr32(dev, 0x3300, nv_ri32(dev, fc + 80));
nv_wr32(dev, 0x330c, nv_ri32(dev, fc + 84));
nv_wr32(dev, NV03_PFIFO_CACHE1_GET, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUT, 0);
}
int
nv40_fifo_load_context(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
uint32_t tmp;
nv40_fifo_do_load_context(dev, chan->id);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1,
NV40_PFIFO_CACHE1_PUSH1_DMA | chan->id);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUSH, 1);
tmp = nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_CTL) & ~(1 << 31);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_CTL, tmp);
return 0;
}
int
nv40_fifo_unload_context(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
uint32_t fc, tmp;
int chid;
chid = pfifo->channel_id(dev);
if (chid < 0 || chid >= dev_priv->engine.fifo.channels)
return 0;
fc = NV40_RAMFC(chid);
nv_wi32(dev, fc + 0, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_PUT));
nv_wi32(dev, fc + 4, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_GET));
nv_wi32(dev, fc + 8, nv_rd32(dev, NV10_PFIFO_CACHE1_REF_CNT));
nv_wi32(dev, fc + 12, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_INSTANCE));
nv_wi32(dev, fc + 16, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_DCOUNT));
nv_wi32(dev, fc + 20, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_STATE));
tmp = nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_FETCH);
tmp |= nv_rd32(dev, 0x2058) & 0x30000000;
nv_wi32(dev, fc + 24, tmp);
nv_wi32(dev, fc + 28, nv_rd32(dev, NV04_PFIFO_CACHE1_ENGINE));
nv_wi32(dev, fc + 32, nv_rd32(dev, NV04_PFIFO_CACHE1_PULL1));
nv_wi32(dev, fc + 36, nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_VALUE));
tmp = nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMESTAMP);
nv_wi32(dev, fc + 40, tmp);
nv_wi32(dev, fc + 44, nv_rd32(dev, NV10_PFIFO_CACHE1_ACQUIRE_TIMEOUT));
nv_wi32(dev, fc + 48, nv_rd32(dev, NV10_PFIFO_CACHE1_SEMAPHORE));
nv_wi32(dev, fc + 52, nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_GET));
nv_wi32(dev, fc + 56, nv_rd32(dev, NV40_PFIFO_GRCTX_INSTANCE));
nv_wi32(dev, fc + 60, nv_rd32(dev, NV04_PFIFO_DMA_TIMESLICE) & 0x1ffff);
nv_wi32(dev, fc + 64, nv_rd32(dev, NV40_PFIFO_UNK32E4));
nv_wi32(dev, fc + 68, nv_rd32(dev, 0x32e8));
nv_wi32(dev, fc + 76, nv_rd32(dev, 0x2088));
nv_wi32(dev, fc + 80, nv_rd32(dev, 0x3300));
#if 0
tmp = nv_rd32(dev, NV04_PFIFO_CACHE1_GET);
tmp |= (nv_rd32(dev, NV04_PFIFO_CACHE1_PUT) << 16);
nv_wi32(dev, fc + 72, tmp);
#endif
nv_wi32(dev, fc + 84, nv_rd32(dev, 0x330c));
nv40_fifo_do_load_context(dev, pfifo->channels - 1);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1,
NV40_PFIFO_CACHE1_PUSH1_DMA | (pfifo->channels - 1));
return 0;
}
static void
nv40_fifo_init_reset(struct drm_device *dev)
{
int i;
nv_wr32(dev, NV03_PMC_ENABLE,
nv_rd32(dev, NV03_PMC_ENABLE) & ~NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, NV03_PMC_ENABLE,
nv_rd32(dev, NV03_PMC_ENABLE) | NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, 0x003224, 0x000f0078);
nv_wr32(dev, 0x003210, 0x00000000);
nv_wr32(dev, 0x003270, 0x00000000);
nv_wr32(dev, 0x003240, 0x00000000);
nv_wr32(dev, 0x003244, 0x00000000);
nv_wr32(dev, 0x003258, 0x00000000);
nv_wr32(dev, 0x002504, 0x00000000);
for (i = 0; i < 16; i++)
nv_wr32(dev, 0x002510 + (i * 4), 0x00000000);
nv_wr32(dev, 0x00250c, 0x0000ffff);
nv_wr32(dev, 0x002048, 0x00000000);
nv_wr32(dev, 0x003228, 0x00000000);
nv_wr32(dev, 0x0032e8, 0x00000000);
nv_wr32(dev, 0x002410, 0x00000000);
nv_wr32(dev, 0x002420, 0x00000000);
nv_wr32(dev, 0x002058, 0x00000001);
nv_wr32(dev, 0x00221c, 0x00000000);
nv_wr32(dev, 0x002040, 0x000000ff);
nv_wr32(dev, 0x002500, 0x00000000);
nv_wr32(dev, 0x003200, 0x00000000);
nv_wr32(dev, NV04_PFIFO_DMA_TIMESLICE, 0x2101ffff);
}
static void
nv40_fifo_init_ramxx(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
nv_wr32(dev, NV03_PFIFO_RAMHT, (0x03 << 24) |
((dev_priv->ramht->bits - 9) << 16) |
(dev_priv->ramht->gpuobj->pinst >> 8));
nv_wr32(dev, NV03_PFIFO_RAMRO, dev_priv->ramro->pinst >> 8);
switch (dev_priv->chipset) {
case 0x47:
case 0x49:
case 0x4b:
nv_wr32(dev, 0x2230, 1);
break;
default:
break;
}
switch (dev_priv->chipset) {
case 0x40:
case 0x41:
case 0x42:
case 0x43:
case 0x45:
case 0x47:
case 0x48:
case 0x49:
case 0x4b:
nv_wr32(dev, NV40_PFIFO_RAMFC, 0x30002);
break;
default:
nv_wr32(dev, 0x2230, 0);
nv_wr32(dev, NV40_PFIFO_RAMFC,
((dev_priv->vram_size - 512 * 1024 +
dev_priv->ramfc->pinst) >> 16) | (3 << 16));
break;
}
}
static void
nv40_fifo_init_intr(struct drm_device *dev)
{
nouveau_irq_register(dev, 8, nv04_fifo_isr);
nv_wr32(dev, 0x002100, 0xffffffff);
nv_wr32(dev, 0x002140, 0xffffffff);
}
int
nv40_fifo_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
int i;
nv40_fifo_init_reset(dev);
nv40_fifo_init_ramxx(dev);
nv40_fifo_do_load_context(dev, pfifo->channels - 1);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1, pfifo->channels - 1);
nv40_fifo_init_intr(dev);
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
