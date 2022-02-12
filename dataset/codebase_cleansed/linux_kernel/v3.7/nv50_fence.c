static int
nv50_fence_context_new(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->drm->dev;
struct nv50_fence_priv *priv = chan->drm->fence;
struct nv50_fence_chan *fctx;
struct ttm_mem_reg *mem = &priv->bo->bo.mem;
struct nouveau_object *object;
int ret, i;
fctx = chan->fence = kzalloc(sizeof(*fctx), GFP_KERNEL);
if (!fctx)
return -ENOMEM;
nouveau_fence_context_new(&fctx->base);
ret = nouveau_object_new(nv_object(chan->cli), chan->handle,
NvSema, 0x0002,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = mem->start * PAGE_SIZE,
.limit = mem->size - 1,
}, sizeof(struct nv_dma_class),
&object);
for (i = 0; !ret && i < dev->mode_config.num_crtc; i++) {
struct nouveau_bo *bo = nv50_display_crtc_sema(dev, i);
ret = nouveau_object_new(nv_object(chan->cli), chan->handle,
NvEvoSema0 + i, 0x003d,
&(struct nv_dma_class) {
.flags = NV_DMA_TARGET_VRAM |
NV_DMA_ACCESS_RDWR,
.start = bo->bo.offset,
.limit = bo->bo.offset + 0xfff,
}, sizeof(struct nv_dma_class),
&object);
}
if (ret)
nv10_fence_context_del(chan);
return ret;
}
int
nv50_fence_create(struct nouveau_drm *drm)
{
struct nv50_fence_priv *priv;
int ret = 0;
priv = drm->fence = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->base.dtor = nv10_fence_destroy;
priv->base.context_new = nv50_fence_context_new;
priv->base.context_del = nv10_fence_context_del;
priv->base.emit = nv10_fence_emit;
priv->base.read = nv10_fence_read;
priv->base.sync = nv17_fence_sync;
spin_lock_init(&priv->lock);
ret = nouveau_bo_new(drm->dev, 4096, 0x1000, TTM_PL_FLAG_VRAM,
0, 0x0000, NULL, &priv->bo);
if (!ret) {
ret = nouveau_bo_pin(priv->bo, TTM_PL_FLAG_VRAM);
if (!ret)
ret = nouveau_bo_map(priv->bo);
if (ret)
nouveau_bo_ref(NULL, &priv->bo);
}
if (ret == 0) {
nouveau_bo_wr32(priv->bo, 0x000, 0x00000000);
priv->base.sync = nv17_fence_sync;
}
if (ret)
nv10_fence_destroy(drm);
return ret;
}
