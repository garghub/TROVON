int
nv10_fence_emit(struct nouveau_fence *fence)
{
struct nouveau_channel *chan = fence->channel;
int ret = RING_SPACE(chan, 2);
if (ret == 0) {
BEGIN_NV04(chan, 0, NV10_SUBCHAN_REF_CNT, 1);
OUT_RING (chan, fence->sequence);
FIRE_RING (chan);
}
return ret;
}
static int
nv10_fence_sync(struct nouveau_fence *fence,
struct nouveau_channel *prev, struct nouveau_channel *chan)
{
return -ENODEV;
}
int
nv17_fence_sync(struct nouveau_fence *fence,
struct nouveau_channel *prev, struct nouveau_channel *chan)
{
struct nv10_fence_priv *priv = chan->drm->fence;
u32 value;
int ret;
if (!mutex_trylock(&prev->cli->mutex))
return -EBUSY;
spin_lock(&priv->lock);
value = priv->sequence;
priv->sequence += 2;
spin_unlock(&priv->lock);
ret = RING_SPACE(prev, 5);
if (!ret) {
BEGIN_NV04(prev, 0, NV11_SUBCHAN_DMA_SEMAPHORE, 4);
OUT_RING (prev, NvSema);
OUT_RING (prev, 0);
OUT_RING (prev, value + 0);
OUT_RING (prev, value + 1);
FIRE_RING (prev);
}
if (!ret && !(ret = RING_SPACE(chan, 5))) {
BEGIN_NV04(chan, 0, NV11_SUBCHAN_DMA_SEMAPHORE, 4);
OUT_RING (chan, NvSema);
OUT_RING (chan, 0);
OUT_RING (chan, value + 1);
OUT_RING (chan, value + 2);
FIRE_RING (chan);
}
mutex_unlock(&prev->cli->mutex);
return 0;
}
u32
nv10_fence_read(struct nouveau_channel *chan)
{
return nv_ro32(chan->object, 0x0048);
}
void
nv10_fence_context_del(struct nouveau_channel *chan)
{
struct nv10_fence_chan *fctx = chan->fence;
nouveau_fence_context_del(&fctx->base);
chan->fence = NULL;
kfree(fctx);
}
static int
nv10_fence_context_new(struct nouveau_channel *chan)
{
struct nv10_fence_priv *priv = chan->drm->fence;
struct nv10_fence_chan *fctx;
int ret = 0;
fctx = chan->fence = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return -ENOMEM;
nouveau_fence_context_new(&fctx->base);
if (priv->bo) {
struct ttm_mem_reg *mem = &priv->bo->bo.mem;
struct nouveau_object *object;
u32 start = mem->start * PAGE_SIZE;
u32 limit = mem->start + mem->size - 1;
ret = nouveau_object_new(nv_object(chan->cli), chan->handle,
NvSema, 0x0002,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_class),
&object);
}
if (ret)
nv10_fence_context_del(chan);
return ret;
}
void
nv10_fence_destroy(struct nouveau_drm *drm)
{
struct nv10_fence_priv *priv = drm->fence;
nouveau_bo_unmap(priv->bo);
if (priv->bo)
nouveau_bo_unpin(priv->bo);
nouveau_bo_ref(NULL, &priv->bo);
drm->fence = NULL;
kfree(priv);
}
void nv17_fence_resume(struct nouveau_drm *drm)
{
struct nv10_fence_priv *priv = drm->fence;
nouveau_bo_wr32(priv->bo, 0, priv->sequence);
}
int
nv10_fence_create(struct nouveau_drm *drm)
{
struct nv10_fence_priv *priv;
int ret = 0;
priv = drm->fence = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.dtor = nv10_fence_destroy;
priv->base.context_new = nv10_fence_context_new;
priv->base.context_del = nv10_fence_context_del;
priv->base.emit = nv10_fence_emit;
priv->base.read = nv10_fence_read;
priv->base.sync = nv10_fence_sync;
spin_lock_init(&priv->lock);
if (nv_device(drm->device)->chipset >= 0x17) {
ret = nouveau_bo_new(drm->dev, 4096, 0x1000, TTM_PL_FLAG_VRAM,
0, 0x0000, NULL, &priv->bo);
if (!ret) {
ret = nouveau_bo_pin(priv->bo, TTM_PL_FLAG_VRAM);
if (!ret) {
ret = nouveau_bo_map(priv->bo);
if (ret)
nouveau_bo_unpin(priv->bo);
}
if (ret)
nouveau_bo_ref(NULL, &priv->bo);
}
if (ret == 0) {
nouveau_bo_wr32(priv->bo, 0x000, 0x00000000);
priv->base.sync = nv17_fence_sync;
priv->base.resume = nv17_fence_resume;
}
}
if (ret)
nv10_fence_destroy(drm);
return ret;
}
