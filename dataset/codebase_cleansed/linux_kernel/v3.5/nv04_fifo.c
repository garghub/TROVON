bool
nv04_fifo_cache_pull(struct drm_device *dev, bool enable)
{
int pull = nv_mask(dev, NV04_PFIFO_CACHE1_PULL0, 1, enable);
if (!enable) {
if (!nv_wait(dev, NV04_PFIFO_CACHE1_PULL0,
NV04_PFIFO_CACHE1_PULL0_HASH_BUSY, 0))
NV_ERROR(dev, "Timeout idling the PFIFO puller.\n");
if (nv_rd32(dev, NV04_PFIFO_CACHE1_PULL0) &
NV04_PFIFO_CACHE1_PULL0_HASH_FAILED)
nv_wr32(dev, NV03_PFIFO_INTR_0,
NV_PFIFO_INTR_CACHE_ERROR);
nv_wr32(dev, NV04_PFIFO_CACHE1_HASH, 0);
}
return pull & 1;
}
static int
nv04_fifo_context_new(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv = nv_engine(dev, engine);
struct nv04_fifo_chan *fctx;
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
nv_wo32(fctx->ramfc, 0x08, chan->pushbuf->pinst >> 4);
nv_wo32(fctx->ramfc, 0x0c, 0x00000000);
nv_wo32(fctx->ramfc, 0x10, NV_PFIFO_CACHE1_DMA_FETCH_TRIG_128_BYTES |
NV_PFIFO_CACHE1_DMA_FETCH_SIZE_128_BYTES |
#ifdef __BIG_ENDIAN
NV_PFIFO_CACHE1_BIG_ENDIAN |
#endif
NV_PFIFO_CACHE1_DMA_FETCH_MAX_REQS_8);
nv_wo32(fctx->ramfc, 0x14, 0x00000000);
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
void
nv04_fifo_context_del(struct nouveau_channel *chan, int engine)
{
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv = nv_engine(chan->dev, engine);
struct nv04_fifo_chan *fctx = chan->engctx[engine];
struct ramfc_desc *c = priv->ramfc_desc;
unsigned long flags;
int chid;
spin_lock_irqsave(&dev_priv->context_switch_lock, flags);
nv_wr32(dev, NV03_PFIFO_CACHES, 0);
chid = nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH1) & priv->base.channels;
if (chid == chan->id) {
nv_mask(dev, NV04_PFIFO_CACHE1_DMA_PUSH, 0x00000001, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0, 0);
nv_mask(dev, NV04_PFIFO_CACHE1_PULL0, 0x00000001, 0);
do {
u32 mask = ((1ULL << c->bits) - 1) << c->regs;
nv_mask(dev, c->regp, mask, 0x00000000);
} while ((++c)->bits);
nv_wr32(dev, NV03_PFIFO_CACHE1_GET, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUT, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH1, priv->base.channels);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0, 1);
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL0, 1);
}
nv_mask(dev, NV04_PFIFO_MODE, 1 << chan->id, 0);
nv_wr32(dev, NV03_PFIFO_CACHES, 1);
spin_unlock_irqrestore(&dev_priv->context_switch_lock, flags);
nouveau_gpuobj_ref(NULL, &fctx->ramfc);
nouveau_gpuobj_ref(NULL, &chan->ramfc);
if (chan->user) {
iounmap(chan->user);
chan->user = NULL;
}
}
int
nv04_fifo_init(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv = nv_engine(dev, engine);
int i;
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, 0);
nv_mask(dev, NV03_PMC_ENABLE, NV_PMC_ENABLE_PFIFO, NV_PMC_ENABLE_PFIFO);
nv_wr32(dev, NV04_PFIFO_DELAY_0, 0x000000ff);
nv_wr32(dev, NV04_PFIFO_DMA_TIMESLICE, 0x0101ffff);
nv_wr32(dev, NV03_PFIFO_RAMHT, (0x03 << 24) |
((dev_priv->ramht->bits - 9) << 16) |
(dev_priv->ramht->gpuobj->pinst >> 8));
nv_wr32(dev, NV03_PFIFO_RAMRO, dev_priv->ramro->pinst >> 8);
nv_wr32(dev, NV03_PFIFO_RAMFC, dev_priv->ramfc->pinst >> 8);
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
nv04_fifo_fini(struct drm_device *dev, int engine, bool suspend)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv = nv_engine(dev, engine);
struct nouveau_channel *chan;
int chid;
nv_wr32(dev, NV03_PFIFO_CACHES, 0);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUSH, 0);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0, 0);
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL0, 0);
chid = nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH1) & priv->base.channels;
chan = dev_priv->channels.ptr[chid];
if (suspend && chid != priv->base.channels && chan) {
struct nv04_fifo_chan *fctx = chan->engctx[engine];
struct nouveau_gpuobj *ctx = fctx->ramfc;
struct ramfc_desc *c = priv->ramfc_desc;
do {
u32 rm = ((1ULL << c->bits) - 1) << c->regs;
u32 cm = ((1ULL << c->bits) - 1) << c->ctxs;
u32 rv = (nv_rd32(dev, c->regp) & rm) >> c->regs;
u32 cv = (nv_ro32(ctx, c->ctxp) & ~cm);
nv_wo32(ctx, c->ctxp, cv | (rv << c->ctxs));
} while ((++c)->bits);
}
nv_wr32(dev, NV03_PFIFO_INTR_EN_0, 0x00000000);
return 0;
}
static bool
nouveau_fifo_swmthd(struct drm_device *dev, u32 chid, u32 addr, u32 data)
{
struct nouveau_fifo_priv *pfifo = nv_engine(dev, NVOBJ_ENGINE_FIFO);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_channel *chan = NULL;
struct nouveau_gpuobj *obj;
unsigned long flags;
const int subc = (addr >> 13) & 0x7;
const int mthd = addr & 0x1ffc;
bool handled = false;
u32 engine;
spin_lock_irqsave(&dev_priv->channels.lock, flags);
if (likely(chid >= 0 && chid < pfifo->channels))
chan = dev_priv->channels.ptr[chid];
if (unlikely(!chan))
goto out;
switch (mthd) {
case 0x0000:
obj = nouveau_ramht_find(chan, data);
if (unlikely(!obj || obj->engine != NVOBJ_ENGINE_SW))
break;
engine = 0x0000000f << (subc * 4);
nv_mask(dev, NV04_PFIFO_CACHE1_ENGINE, engine, 0x00000000);
handled = true;
break;
default:
engine = nv_rd32(dev, NV04_PFIFO_CACHE1_ENGINE);
if (unlikely(((engine >> (subc * 4)) & 0xf) != 0))
break;
if (!nouveau_gpuobj_mthd_call(chan, nouveau_software_class(dev),
mthd, data))
handled = true;
break;
}
out:
spin_unlock_irqrestore(&dev_priv->channels.lock, flags);
return handled;
}
static const char *nv_dma_state_err(u32 state)
{
static const char * const desc[] = {
"NONE", "CALL_SUBR_ACTIVE", "INVALID_MTHD", "RET_SUBR_INACTIVE",
"INVALID_CMD", "IB_EMPTY", "MEM_FAULT", "UNK"
};
return desc[(state >> 29) & 0x7];
}
void
nv04_fifo_isr(struct drm_device *dev)
{
struct nouveau_fifo_priv *pfifo = nv_engine(dev, NVOBJ_ENGINE_FIFO);
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t status, reassign;
int cnt = 0;
reassign = nv_rd32(dev, NV03_PFIFO_CACHES) & 1;
while ((status = nv_rd32(dev, NV03_PFIFO_INTR_0)) && (cnt++ < 100)) {
uint32_t chid, get;
nv_wr32(dev, NV03_PFIFO_CACHES, 0);
chid = nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH1) & pfifo->channels;
get = nv_rd32(dev, NV03_PFIFO_CACHE1_GET);
if (status & NV_PFIFO_INTR_CACHE_ERROR) {
uint32_t mthd, data;
int ptr;
ptr = (get & 0x7ff) >> 2;
if (dev_priv->card_type < NV_40) {
mthd = nv_rd32(dev,
NV04_PFIFO_CACHE1_METHOD(ptr));
data = nv_rd32(dev,
NV04_PFIFO_CACHE1_DATA(ptr));
} else {
mthd = nv_rd32(dev,
NV40_PFIFO_CACHE1_METHOD(ptr));
data = nv_rd32(dev,
NV40_PFIFO_CACHE1_DATA(ptr));
}
if (!nouveau_fifo_swmthd(dev, chid, mthd, data)) {
NV_INFO(dev, "PFIFO_CACHE_ERROR - Ch %d/%d "
"Mthd 0x%04x Data 0x%08x\n",
chid, (mthd >> 13) & 7, mthd & 0x1ffc,
data);
}
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUSH, 0);
nv_wr32(dev, NV03_PFIFO_INTR_0,
NV_PFIFO_INTR_CACHE_ERROR);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0,
nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH0) & ~1);
nv_wr32(dev, NV03_PFIFO_CACHE1_GET, get + 4);
nv_wr32(dev, NV03_PFIFO_CACHE1_PUSH0,
nv_rd32(dev, NV03_PFIFO_CACHE1_PUSH0) | 1);
nv_wr32(dev, NV04_PFIFO_CACHE1_HASH, 0);
nv_wr32(dev, NV04_PFIFO_CACHE1_DMA_PUSH,
nv_rd32(dev, NV04_PFIFO_CACHE1_DMA_PUSH) | 1);
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL0, 1);
status &= ~NV_PFIFO_INTR_CACHE_ERROR;
}
if (status & NV_PFIFO_INTR_DMA_PUSHER) {
u32 dma_get = nv_rd32(dev, 0x003244);
u32 dma_put = nv_rd32(dev, 0x003240);
u32 push = nv_rd32(dev, 0x003220);
u32 state = nv_rd32(dev, 0x003228);
if (dev_priv->card_type == NV_50) {
u32 ho_get = nv_rd32(dev, 0x003328);
u32 ho_put = nv_rd32(dev, 0x003320);
u32 ib_get = nv_rd32(dev, 0x003334);
u32 ib_put = nv_rd32(dev, 0x003330);
if (nouveau_ratelimit())
NV_INFO(dev, "PFIFO_DMA_PUSHER - Ch %d Get 0x%02x%08x "
"Put 0x%02x%08x IbGet 0x%08x IbPut 0x%08x "
"State 0x%08x (err: %s) Push 0x%08x\n",
chid, ho_get, dma_get, ho_put,
dma_put, ib_get, ib_put, state,
nv_dma_state_err(state),
push);
nv_wr32(dev, 0x003364, 0x00000000);
if (dma_get != dma_put || ho_get != ho_put) {
nv_wr32(dev, 0x003244, dma_put);
nv_wr32(dev, 0x003328, ho_put);
} else
if (ib_get != ib_put) {
nv_wr32(dev, 0x003334, ib_put);
}
} else {
NV_INFO(dev, "PFIFO_DMA_PUSHER - Ch %d Get 0x%08x "
"Put 0x%08x State 0x%08x (err: %s) Push 0x%08x\n",
chid, dma_get, dma_put, state,
nv_dma_state_err(state), push);
if (dma_get != dma_put)
nv_wr32(dev, 0x003244, dma_put);
}
nv_wr32(dev, 0x003228, 0x00000000);
nv_wr32(dev, 0x003220, 0x00000001);
nv_wr32(dev, 0x002100, NV_PFIFO_INTR_DMA_PUSHER);
status &= ~NV_PFIFO_INTR_DMA_PUSHER;
}
if (status & NV_PFIFO_INTR_SEMAPHORE) {
uint32_t sem;
status &= ~NV_PFIFO_INTR_SEMAPHORE;
nv_wr32(dev, NV03_PFIFO_INTR_0,
NV_PFIFO_INTR_SEMAPHORE);
sem = nv_rd32(dev, NV10_PFIFO_CACHE1_SEMAPHORE);
nv_wr32(dev, NV10_PFIFO_CACHE1_SEMAPHORE, sem | 0x1);
nv_wr32(dev, NV03_PFIFO_CACHE1_GET, get + 4);
nv_wr32(dev, NV04_PFIFO_CACHE1_PULL0, 1);
}
if (dev_priv->card_type == NV_50) {
if (status & 0x00000010) {
nv50_fb_vm_trap(dev, nouveau_ratelimit());
status &= ~0x00000010;
nv_wr32(dev, 0x002100, 0x00000010);
}
}
if (status) {
if (nouveau_ratelimit())
NV_INFO(dev, "PFIFO_INTR 0x%08x - Ch %d\n",
status, chid);
nv_wr32(dev, NV03_PFIFO_INTR_0, status);
status = 0;
}
nv_wr32(dev, NV03_PFIFO_CACHES, reassign);
}
if (status) {
NV_INFO(dev, "PFIFO still angry after %d spins, halt\n", cnt);
nv_wr32(dev, 0x2140, 0);
nv_wr32(dev, 0x140, 0);
}
nv_wr32(dev, NV03_PMC_INTR_0, NV_PMC_INTR_0_PFIFO_PENDING);
}
void
nv04_fifo_destroy(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv = nv_engine(dev, engine);
nouveau_irq_unregister(dev, 8);
dev_priv->eng[engine] = NULL;
kfree(priv);
}
int
nv04_fifo_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fifo_priv *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.base.destroy = nv04_fifo_destroy;
priv->base.base.init = nv04_fifo_init;
priv->base.base.fini = nv04_fifo_fini;
priv->base.base.context_new = nv04_fifo_context_new;
priv->base.base.context_del = nv04_fifo_context_del;
priv->base.channels = 15;
priv->ramfc_desc = nv04_ramfc;
dev_priv->eng[NVOBJ_ENGINE_FIFO] = &priv->base.base;
nouveau_irq_register(dev, 8, nv04_fifo_isr);
return 0;
}
