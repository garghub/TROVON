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
int
nv04_fence_mthd(struct nouveau_channel *chan, u32 class, u32 mthd, u32 data)
{
struct nv04_fence_chan *fctx = chan->engctx[NVOBJ_ENGINE_FENCE];
atomic_set(&fctx->sequence, data);
return 0;
}
static u32
nv04_fence_read(struct nouveau_channel *chan)
{
struct nv04_fence_chan *fctx = chan->engctx[NVOBJ_ENGINE_FENCE];
return atomic_read(&fctx->sequence);
}
static void
nv04_fence_context_del(struct nouveau_channel *chan, int engine)
{
struct nv04_fence_chan *fctx = chan->engctx[engine];
nouveau_fence_context_del(&fctx->base);
chan->engctx[engine] = NULL;
kfree(fctx);
}
static int
nv04_fence_context_new(struct nouveau_channel *chan, int engine)
{
struct nv04_fence_chan *fctx = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (fctx) {
nouveau_fence_context_new(&fctx->base);
atomic_set(&fctx->sequence, 0);
chan->engctx[engine] = fctx;
return 0;
}
return -ENOMEM;
}
static int
nv04_fence_fini(struct drm_device *dev, int engine, bool suspend)
{
return 0;
}
static int
nv04_fence_init(struct drm_device *dev, int engine)
{
return 0;
}
static void
nv04_fence_destroy(struct drm_device *dev, int engine)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fence_priv *priv = nv_engine(dev, engine);
dev_priv->eng[engine] = NULL;
kfree(priv);
}
int
nv04_fence_create(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nv04_fence_priv *priv;
int ret;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.engine.destroy = nv04_fence_destroy;
priv->base.engine.init = nv04_fence_init;
priv->base.engine.fini = nv04_fence_fini;
priv->base.engine.context_new = nv04_fence_context_new;
priv->base.engine.context_del = nv04_fence_context_del;
priv->base.emit = nv04_fence_emit;
priv->base.sync = nv04_fence_sync;
priv->base.read = nv04_fence_read;
dev_priv->eng[NVOBJ_ENGINE_FENCE] = &priv->base.engine;
return ret;
}
