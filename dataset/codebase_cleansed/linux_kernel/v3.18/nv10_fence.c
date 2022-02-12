int
nv10_fence_emit(struct nouveau_fence *fence)
{
struct nouveau_channel *chan = fence->channel;
int ret = RING_SPACE(chan, 2);
if (ret == 0) {
BEGIN_NV04(chan, 0, NV10_SUBCHAN_REF_CNT, 1);
OUT_RING (chan, fence->base.seqno);
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
u32
nv10_fence_read(struct nouveau_channel *chan)
{
return nvif_rd32(chan, 0x0048);
}
void
nv10_fence_context_del(struct nouveau_channel *chan)
{
struct nv10_fence_chan *fctx = chan->fence;
int i;
nouveau_fence_context_del(&fctx->base);
for (i = 0; i < ARRAY_SIZE(fctx->head); i++)
nvif_object_fini(&fctx->head[i]);
nvif_object_fini(&fctx->sema);
chan->fence = NULL;
nouveau_fence_context_free(&fctx->base);
}
int
nv10_fence_context_new(struct nouveau_channel *chan)
{
struct nv10_fence_chan *fctx;
fctx = chan->fence = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return -ENOMEM;
nouveau_fence_context_new(chan, &fctx->base);
fctx->base.emit = nv10_fence_emit;
fctx->base.read = nv10_fence_read;
fctx->base.sync = nv10_fence_sync;
return 0;
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
int
nv10_fence_create(struct nouveau_drm *drm)
{
struct nv10_fence_priv *priv;
priv = drm->fence = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.dtor = nv10_fence_destroy;
priv->base.context_new = nv10_fence_context_new;
priv->base.context_del = nv10_fence_context_del;
priv->base.contexts = 31;
priv->base.context_base = fence_context_alloc(priv->base.contexts);
spin_lock_init(&priv->lock);
return 0;
}
