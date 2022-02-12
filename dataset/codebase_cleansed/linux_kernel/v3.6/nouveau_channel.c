static int
nouveau_channel_pushbuf_init(struct nouveau_channel *chan)
{
u32 mem = nouveau_vram_pushbuf ? TTM_PL_FLAG_VRAM : TTM_PL_FLAG_TT;
struct drm_device *dev = chan->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
int ret;
ret = nouveau_bo_new(dev, 65536, 0, mem, 0, 0, NULL, &chan->pushbuf_bo);
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
struct nouveau_exec_engine *fence = nv_engine(dev, NVOBJ_ENGINE_FENCE);
struct nouveau_fifo_priv *pfifo = nv_engine(dev, NVOBJ_ENGINE_FIFO);
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nouveau_fpriv *fpriv = nouveau_fpriv(file_priv);
struct nouveau_channel *chan;
unsigned long flags;
int ret, i;
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
nouveau_dma_init(chan);
chan->user_put = 0x40;
chan->user_get = 0x44;
if (dev_priv->card_type >= NV_50)
chan->user_get_hi = 0x60;
ret = pfifo->base.context_new(chan, NVOBJ_ENGINE_FIFO);
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
ret = RING_SPACE(chan, NOUVEAU_DMA_SKIPS);
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
for (i = 0; i < NOUVEAU_DMA_SKIPS; i++)
OUT_RING (chan, 0x00000000);
ret = nouveau_gpuobj_gr_new(chan, NvSw, nouveau_software_class(dev));
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
if (dev_priv->card_type < NV_C0) {
ret = RING_SPACE(chan, 2);
if (ret) {
nouveau_channel_put(&chan);
return ret;
}
BEGIN_NV04(chan, NvSubSw, NV01_SUBCHAN_OBJECT, 1);
OUT_RING (chan, NvSw);
FIRE_RING (chan);
}
FIRE_RING(chan);
ret = fence->context_new(chan, NVOBJ_ENGINE_FENCE);
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
unsigned long flags;
int i;
if (likely(!atomic_dec_and_test(&chan->users))) {
nouveau_channel_ref(NULL, pchan);
return;
}
NV_DEBUG(dev, "freeing channel %d\n", chan->id);
nouveau_debugfs_channel_fini(chan);
nouveau_channel_idle(chan);
for (i = NVOBJ_ENGINE_NR - 1; i >= 0; i--) {
if (chan->engctx[i])
dev_priv->eng[i]->context_del(chan, i);
}
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
int
nouveau_channel_idle(struct nouveau_channel *chan)
{
struct drm_device *dev = chan->dev;
struct nouveau_fence *fence = NULL;
int ret;
ret = nouveau_fence_new(chan, &fence);
if (!ret) {
ret = nouveau_fence_wait(fence, false, false);
nouveau_fence_unref(&fence);
}
if (ret)
NV_ERROR(dev, "Failed to idle channel %d.\n", chan->id);
return ret;
}
void
nouveau_channel_cleanup(struct drm_device *dev, struct drm_file *file_priv)
{
struct nouveau_fifo_priv *pfifo = nv_engine(dev, NVOBJ_ENGINE_FIFO);
struct nouveau_channel *chan;
int i;
if (!pfifo)
return;
NV_DEBUG(dev, "clearing FIFO enables from file_priv\n");
for (i = 0; i < pfifo->channels; i++) {
chan = nouveau_channel_get(file_priv, i);
if (IS_ERR(chan))
continue;
list_del(&chan->list);
atomic_dec(&chan->users);
nouveau_channel_put(&chan);
}
}
