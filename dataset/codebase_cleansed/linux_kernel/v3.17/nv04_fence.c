static int
nv04_fence_emit(struct nouveau_fence *fence)
{
struct nouveau_channel *chan = fence->channel;
int ret = RING_SPACE(chan, 2);
if (ret == 0) {
BEGIN_NV04(chan, NvSubSw, 0x0150, 1);
OUT_RING (chan, fence->sequence);
FIRE_RING (chan);
}
return ret;
}
static int
nv04_fence_sync(struct nouveau_fence *fence,
struct nouveau_channel *prev, struct nouveau_channel *chan)
{
return -ENODEV;
}
static u32
nv04_fence_read(struct nouveau_channel *chan)
{
struct nouveau_fifo_chan *fifo = nvkm_fifo_chan(chan);;
return atomic_read(&fifo->refcnt);
}
static void
nv04_fence_context_del(struct nouveau_channel *chan)
{
struct nv04_fence_chan *fctx = chan->fence;
nouveau_fence_context_del(&fctx->base);
chan->fence = NULL;
kfree(fctx);
}
static int
nv04_fence_context_new(struct nouveau_channel *chan)
{
struct nv04_fence_chan *fctx = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (fctx) {
nouveau_fence_context_new(&fctx->base);
fctx->base.emit = nv04_fence_emit;
fctx->base.sync = nv04_fence_sync;
fctx->base.read = nv04_fence_read;
chan->fence = fctx;
return 0;
}
return -ENOMEM;
}
static void
nv04_fence_destroy(struct nouveau_drm *drm)
{
struct nv04_fence_priv *priv = drm->fence;
drm->fence = NULL;
kfree(priv);
}
int
nv04_fence_create(struct nouveau_drm *drm)
{
struct nv04_fence_priv *priv;
priv = drm->fence = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.dtor = nv04_fence_destroy;
priv->base.context_new = nv04_fence_context_new;
priv->base.context_del = nv04_fence_context_del;
return 0;
}
