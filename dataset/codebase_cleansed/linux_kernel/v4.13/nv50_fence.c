static int
nv50_fence_context_new(struct nouveau_channel *chan)
{
struct nv10_fence_priv *priv = chan->drm->fence;
struct nv10_fence_chan *fctx;
struct ttm_mem_reg *reg = &priv->bo->bo.mem;
u32 start = reg->start * PAGE_SIZE;
u32 limit = start + reg->size - 1;
int ret;
fctx = chan->fence = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return -ENOMEM;
nouveau_fence_context_new(chan, &fctx->base);
fctx->base.emit = nv10_fence_emit;
fctx->base.read = nv10_fence_read;
fctx->base.sync = nv17_fence_sync;
ret = nvif_object_init(&chan->user, NvSema, NV_DMA_IN_MEMORY,
&(struct nv_dma_v0) {
.target = NV_DMA_V0_TARGET_VRAM,
.access = NV_DMA_V0_ACCESS_RDWR,
.start = start,
.limit = limit,
}, sizeof(struct nv_dma_v0),
&fctx->sema);
if (ret)
nv10_fence_context_del(chan);
return ret;
}
int
nv50_fence_create(struct nouveau_drm *drm)
{
struct nv10_fence_priv *priv;
int ret = 0;
priv = drm->fence = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.dtor = nv10_fence_destroy;
priv->base.resume = nv17_fence_resume;
priv->base.context_new = nv50_fence_context_new;
priv->base.context_del = nv10_fence_context_del;
priv->base.contexts = 127;
priv->base.context_base = dma_fence_context_alloc(priv->base.contexts);
spin_lock_init(&priv->lock);
ret = nouveau_bo_new(&drm->client, 4096, 0x1000, TTM_PL_FLAG_VRAM,
0, 0x0000, NULL, NULL, &priv->bo);
if (!ret) {
ret = nouveau_bo_pin(priv->bo, TTM_PL_FLAG_VRAM, false);
if (!ret) {
ret = nouveau_bo_map(priv->bo);
if (ret)
nouveau_bo_unpin(priv->bo);
}
if (ret)
nouveau_bo_ref(NULL, &priv->bo);
}
if (ret) {
nv10_fence_destroy(drm);
return ret;
}
nouveau_bo_wr32(priv->bo, 0x000, 0x00000000);
return ret;
}
