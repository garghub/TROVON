int drm_legacy_dma_setup(struct drm_device *dev)
{
int i;
if (!drm_core_check_feature(dev, DRIVER_HAVE_DMA) ||
drm_core_check_feature(dev, DRIVER_MODESET)) {
return 0;
}
dev->buf_use = 0;
atomic_set(&dev->buf_alloc, 0);
dev->dma = kzalloc(sizeof(*dev->dma), GFP_KERNEL);
if (!dev->dma)
return -ENOMEM;
for (i = 0; i <= DRM_MAX_ORDER; i++)
memset(&dev->dma->bufs[i], 0, sizeof(dev->dma->bufs[0]));
return 0;
}
void drm_legacy_dma_takedown(struct drm_device *dev)
{
struct drm_device_dma *dma = dev->dma;
int i, j;
if (!drm_core_check_feature(dev, DRIVER_HAVE_DMA) ||
drm_core_check_feature(dev, DRIVER_MODESET)) {
return;
}
if (!dma)
return;
for (i = 0; i <= DRM_MAX_ORDER; i++) {
if (dma->bufs[i].seg_count) {
DRM_DEBUG("order %d: buf_count = %d,"
" seg_count = %d\n",
i,
dma->bufs[i].buf_count,
dma->bufs[i].seg_count);
for (j = 0; j < dma->bufs[i].seg_count; j++) {
if (dma->bufs[i].seglist[j]) {
drm_pci_free(dev, dma->bufs[i].seglist[j]);
}
}
kfree(dma->bufs[i].seglist);
}
if (dma->bufs[i].buf_count) {
for (j = 0; j < dma->bufs[i].buf_count; j++) {
kfree(dma->bufs[i].buflist[j].dev_private);
}
kfree(dma->bufs[i].buflist);
}
}
kfree(dma->buflist);
kfree(dma->pagelist);
kfree(dev->dma);
dev->dma = NULL;
}
void drm_legacy_free_buffer(struct drm_device *dev, struct drm_buf * buf)
{
if (!buf)
return;
buf->waiting = 0;
buf->pending = 0;
buf->file_priv = NULL;
buf->used = 0;
}
void drm_legacy_reclaim_buffers(struct drm_device *dev,
struct drm_file *file_priv)
{
struct drm_device_dma *dma = dev->dma;
int i;
if (!dma)
return;
for (i = 0; i < dma->buf_count; i++) {
if (dma->buflist[i]->file_priv == file_priv) {
switch (dma->buflist[i]->list) {
case DRM_LIST_NONE:
drm_legacy_free_buffer(dev, dma->buflist[i]);
break;
case DRM_LIST_WAIT:
dma->buflist[i]->list = DRM_LIST_RECLAIM;
break;
default:
break;
}
}
}
}
