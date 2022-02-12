static int
nouveau_channel_pushbuf_init(struct nouveau_channel *chan)
{
u32 mem = nouveau_vram_pushbuf ? TTM_PL_FLAG_VRAM : TTM_PL_FLAG_TT;
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
int ret;
ret = nouveau_bo_new(dev, 65536, 0, mem, 0, 0, &chan->pushbuf_bo);
if (ret)
goto out;
ret = nouveau_bo_pin(chan->pushbuf_bo, mem);
if (ret)
goto out;
ret = nouveau_bo_map(chan->pushbuf_bo);
if (ret)
goto out;
chan->pushbuf_base = chan->pushbuf_bo->bo.offset;
if (dev_priv->card_type >= NV_50) {
ret = nouveau_bo_vma_add(chan->pushbuf_bo, chan->vm,
&chan->pushbuf_vma);
if (ret)
goto out;
if (dev_priv->card_type < NV_C0) {
ret = nouveau_gpuobj_dma_new(chan,
NV_CLASS_DMA_IN_MEMORY, 0,
(1ULL << 40),
NV_MEM_ACCESS_RO,
NV_MEM_TARGET_VM,
&chan->pushbuf);
}
chan->pushbuf_base = chan->pushbuf_vma.offset;
} else
if (chan->pushbuf_bo->bo.mem.mem_type == TTM_PL_TT) {
ret = nouveau_gpuobj_dma_new(chan, NV_CLASS_DMA_IN_MEMORY, 0,
dev_priv->gart_info.aper_size,
NV_MEM_ACCESS_RO,
NV_MEM_TARGET_GART,
&chan->pushbuf);
} else
if (dev_priv->card_type != NV_04) {
ret = nouveau_gpuobj_dma_new(chan, NV_CLASS_DMA_IN_MEMORY, 0,
dev_priv->fb_available_size,
NV_MEM_ACCESS_RO,
NV_MEM_TARGET_VRAM,
&chan->pushbuf);
} else {
ret = nouveau_gpuobj_dma_new(chan, NV_CLASS_DMA_IN_MEMORY,
pci_resource_start(dev->pdev, 1),
dev_priv->fb_available_size,
NV_MEM_ACCESS_RO,
NV_MEM_TARGET_PCI,
&chan->pushbuf);
}
out:
if (ret) {
NV_ERROR(dev, "error initialising pushbuf: %d\n", ret);
nouveau_bo_vma_del(chan->pushbuf_bo, &chan->pushbuf_vma);
nouveau_gpuobj_ref(NULL, &chan->pushbuf);
if (chan->pushbuf_bo) {
nouveau_bo_unmap(chan->pushbuf_bo);
nouveau_bo_ref(NULL, &chan->pushbuf_bo);
}
}
return 0;
}
int
nouveau_channel_alloc(struct drm_device *dev, struct nouveau_channel **chan_ret,
struct drm_file *file_priv,
uint32_t vram_handle, uint32_t gart_handle)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
struct nouveau_fpriv *fpriv = nouveau_fpriv(file_priv);
struct nouveau_channel *chan;
unsigned long flags;
int ret;
chan = kzalloc(sizeof(*chan), GFP_KERNEL);
if (!chan)
return -ENOMEM;
chan->dev = dev;
chan->file_priv = file_priv;
chan->vram_handle = vram_handle;
chan->gart_handle = gart_handle;
kref_init(&chan->ref);
atomic_set(&chan->users, 1);
mutex_init(&chan->mutex);
mutex_lock(&chan->mutex);
spin_lock_irqsave(&dev_priv->channels.lock, flags);
for (chan->id = 0; chan->id < pfifo->channels; chan->id++) {
if (!dev_priv->channels.ptr[chan->id]) {
nouveau_channel_ref(chan, &dev_priv->channels.ptr[chan->id]);
break;
}
}
spin_unlock_irqrestore(&dev_priv->channels.lock, flags);
if (chan->id == pfifo->channels) {
mutex_unlock(&chan->mutex);
kfree(chan);
return -ENODEV;
}
NV_DEBUG(dev, "initialising channel %d\n", chan->id);
INIT_LIST_HEAD(&chan->nvsw.vbl_wait);
INIT_LIST_HEAD(&chan->nvsw.flip);
INIT_LIST_HEAD(&chan->fence.pending);
ret = nouveau_gpuobj_channel_init(chan, vram_handle, gart_handle);
if (ret) {
NV_ERROR(dev, "gpuobj %d\n", ret);
nouveau_channel_put(&chan);
return ret;
}
ret = nouveau_notifier_init_channel(chan);
if (ret) {
NV_ERROR(dev, "ntfy %d\n", ret);
nouveau_channel_put(&chan);
return ret;
}
ret = nouveau_channel_pushbuf_init(chan);
if (ret) {
NV_ERROR(dev, "pushbuf %d\n", ret);
nouveau_channel_put(&chan);
return ret;
}
nouveau_dma_pre_init(chan);
chan->user_put = 0x40;
chan->user_get = 0x44;
pfifo->reassign(dev, false);
ret = pfifo->create_context(chan);
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
pfifo->reassign(dev, true);
ret = nouveau_dma_init(chan);
if (!ret)
ret = nouveau_fence_channel_init(chan);
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
nouveau_debugfs_channel_init(chan);
NV_DEBUG(dev, "channel %d initialised\n", chan->id);
if (fpriv) {
spin_lock(&fpriv->lock);
list_add(&chan->list, &fpriv->channels);
spin_unlock(&fpriv->lock);
}
*chan_ret = chan;
return 0;
}
struct nouveau_channel *
nouveau_channel_get_unlocked(struct nouveau_channel *ref)
{
struct nouveau_channel *chan = NULL;
if (likely(ref && atomic_inc_not_zero(&ref->users)))
nouveau_channel_ref(ref, &chan);
return chan;
}
struct nouveau_channel *
nouveau_channel_get(struct drm_file *file_priv, int id)
{
struct nouveau_fpriv *fpriv = nouveau_fpriv(file_priv);
struct nouveau_channel *chan;
spin_lock(&fpriv->lock);
list_for_each_entry(chan, &fpriv->channels, list) {
if (chan->id == id) {
chan = nouveau_channel_get_unlocked(chan);
spin_unlock(&fpriv->lock);
mutex_lock(&chan->mutex);
return chan;
}
}
spin_unlock(&fpriv->lock);
return ERR_PTR(-EINVAL);
}
void
nouveau_channel_put_unlocked(struct nouveau_channel **pchan)
{
struct nouveau_channel *chan = *pchan;
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fifo_engine *pfifo = &dev_priv->engine.fifo;
unsigned long flags;
int i;
if (likely(!atomic_dec_and_test(&chan->users))) {
nouveau_channel_ref(NULL, pchan);
return;
}
NV_DEBUG(dev, "freeing channel %d\n", chan->id);
nouveau_debugfs_channel_fini(chan);
nouveau_channel_idle(chan);
nouveau_fence_channel_fini(chan);
pfifo->reassign(dev, false);
pfifo->destroy_context(chan);
for (i = 0; i < NVOBJ_ENGINE_NR; i++) {
if (chan->engctx[i])
dev_priv->eng[i]->context_del(chan, i);
}
pfifo->reassign(dev, true);
spin_lock_irqsave(&dev_priv->channels.lock, flags);
nouveau_channel_ref(NULL, &dev_priv->channels.ptr[chan->id]);
spin_unlock_irqrestore(&dev_priv->channels.lock, flags);
nouveau_gpuobj_ref(NULL, &chan->pushbuf);
if (chan->pushbuf_bo) {
nouveau_bo_vma_del(chan->pushbuf_bo, &chan->pushbuf_vma);
nouveau_bo_unmap(chan->pushbuf_bo);
nouveau_bo_unpin(chan->pushbuf_bo);
nouveau_bo_ref(NULL, &chan->pushbuf_bo);
}
nouveau_ramht_ref(NULL, &chan->ramht, chan);
nouveau_notifier_takedown_channel(chan);
nouveau_gpuobj_channel_takedown(chan);
nouveau_channel_ref(NULL, pchan);
}
void
nouveau_channel_put(struct nouveau_channel **pchan)
{
mutex_unlock(&(*pchan)->mutex);
nouveau_channel_put_unlocked(pchan);
}
static void
nouveau_channel_del(struct kref *ref)
{
struct nouveau_channel *chan =
container_of(ref, struct nouveau_channel, ref);
kfree(chan);
}
void
nouveau_channel_ref(struct nouveau_channel *chan,
struct nouveau_channel **pchan)
{
if (chan)
kref_get(&chan->ref);
if (*pchan)
kref_put(&(*pchan)->ref, nouveau_channel_del);
*pchan = chan;
}
void
nouveau_channel_idle(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
struct nouveau_fence *fence = NULL;
int ret;
nouveau_fence_update(chan);
if (chan->fence.sequence != chan->fence.sequence_ack) {
ret = nouveau_fence_new(chan, &fence, true);
if (!ret) {
ret = nouveau_fence_wait(fence, false, false);
nouveau_fence_unref(&fence);
}
if (ret)
NV_ERROR(dev, "Failed to idle channel %d.\n", chan->id);
}
}
void
nouveau_channel_cleanup(struct drm_device *dev, struct drm_file *file_priv)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_engine *engine = &dev_priv->engine;
struct nouveau_channel *chan;
int i;
NV_DEBUG(dev, "clearing FIFO enables from file_priv\n");
for (i = 0; i < engine->fifo.channels; i++) {
chan = nouveau_channel_get(file_priv, i);
if (IS_ERR(chan))
continue;
list_del(&chan->list);
atomic_dec(&chan->users);
nouveau_channel_put(&chan);
}
}
static int
nouveau_ioctl_fifo_alloc(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct drm_nouveau_channel_alloc *init = data;
struct nouveau_channel *chan;
int ret;
if (!dev_priv->eng[NVOBJ_ENGINE_GR])
return -ENODEV;
if (init->fb_ctxdma_handle == ~0 || init->tt_ctxdma_handle == ~0)
return -EINVAL;
ret = nouveau_channel_alloc(dev, &chan, file_priv,
init->fb_ctxdma_handle,
init->tt_ctxdma_handle);
if (ret)
return ret;
init->channel = chan->id;
if (chan->dma.ib_max)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM |
NOUVEAU_GEM_DOMAIN_GART;
else if (chan->pushbuf_bo->bo.mem.mem_type == TTM_PL_VRAM)
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_VRAM;
else
init->pushbuf_domains = NOUVEAU_GEM_DOMAIN_GART;
if (dev_priv->card_type < NV_C0) {
init->subchan[0].handle = NvM2MF;
if (dev_priv->card_type < NV_50)
init->subchan[0].grclass = 0x0039;
else
init->subchan[0].grclass = 0x5039;
init->subchan[1].handle = NvSw;
init->subchan[1].grclass = NV_SW;
init->nr_subchan = 2;
} else {
init->subchan[0].handle = 0x9039;
init->subchan[0].grclass = 0x9039;
init->nr_subchan = 1;
}
ret = drm_gem_handle_create(file_priv, chan->notifier_bo->gem,
&init->notifier_handle);
if (ret == 0)
atomic_inc(&chan->users);
nouveau_channel_put(&chan);
return ret;
}
static int
nouveau_ioctl_fifo_free(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_nouveau_channel_free *req = data;
struct nouveau_channel *chan;
chan = nouveau_channel_get(file_priv, req->channel);
if (IS_ERR(chan))
return PTR_ERR(chan);
list_del(&chan->list);
atomic_dec(&chan->users);
nouveau_channel_put(&chan);
return 0;
}
